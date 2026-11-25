/*
 * main.c - automated tests for the linked list library
 *
 */
#include "linked_list.h"

static int checks_run = 0;
static int checks_failed = 0;

/* ---------- tiny test framework ---------- */

#define CHECK(cond)                                                     \
    do {                                                                \
        checks_run++;                                                   \
        if (!(cond)) {                                                  \
            checks_failed++;                                            \
            printf("    FAIL (line %d): %s\n", __LINE__, #cond);        \
        }                                                               \
    } while (0)

/* Compares a list against an exact sequence of values. */
static void CheckList(int line, const char* name, Node* head,
                      const int* expected, int n)
{
    Node* cur = head;
    int ok = TRUE;
    int i;

    checks_run++;

    for (i = 0; i < n && ok; i++)
    {
        if (cur == NULL || cur->data != expected[i])
            ok = FALSE;
        else
            cur = cur->next;
    }

    if (ok && cur != NULL)      /* list is longer than expected */
        ok = FALSE;

    if (!ok)
    {
        checks_failed++;
        printf("    FAIL (line %d): list '%s'\n      expected:", line, name);
        for (i = 0; i < n; i++)
            printf(" %d", expected[i]);
        printf("\n      actual:   ");
        PrintList(head);
    }
}

#define CHECK_LIST(head, ...)                                           \
    do {                                                                \
        int exp_[] = { __VA_ARGS__ };                                   \
        CheckList(__LINE__, #head, (head), exp_,                        \
                  (int)(sizeof(exp_) / sizeof(exp_[0])));               \
    } while (0)

#define RUN(test)                                                       \
    do {                                                                \
        int failed_before_ = checks_failed;                             \
        printf("%s\n", #test);                                          \
        test();                                                         \
        printf("  -> %s\n",                                             \
               checks_failed == failed_before_ ? "ok" : "FAILED");      \
    } while (0)

/* ---------- helpers ---------- */

static Node* BuildList(const int* values, int n)
{
    Node* head = NULL;
    int i;

    for (i = 0; i < n; i++)
        head = InsertNodeTail(head, values[i]);

    return head;
}

#define BUILD(...)                                                      \
    BuildList((int[]){ __VA_ARGS__ },                                   \
              (int)(sizeof((int[]){ __VA_ARGS__ }) / sizeof(int)))

/* ---------- tests ---------- */

static void test_create_node(void)
{
    Node* n = CreateNode(42);

    CHECK(n != NULL);
    if (n == NULL)
        return;

    CHECK(n->data == 42);
    CHECK(n->next == NULL);
    free(n);
}

static void test_insert_front(void)
{
    Node* head = NULL;

    head = InsertNodeFront(head, 1);
    CHECK_LIST(head, 1);

    head = InsertNodeFront(head, 2);
    CHECK_LIST(head, 2, 1);

    head = InsertNodeFront(head, 3);
    CHECK_LIST(head, 3, 2, 1);

    FreeList(head);
}

static void test_insert_tail(void)
{
    Node* head = NULL;

    head = InsertNodeTail(head, 1);
    CHECK_LIST(head, 1);

    head = InsertNodeTail(head, 2);
    CHECK_LIST(head, 1, 2);

    head = InsertNodeTail(head, 3);
    CHECK_LIST(head, 1, 2, 3);

    FreeList(head);
}

static void test_insert_at_position(void)
{
    Node* head = BUILD(1, 2, 3);

    head = InsertNode(head, 10, 1);             /* front */
    CHECK_LIST(head, 10, 1, 2, 3);

    head = InsertNode(head, 20, 3);             /* middle */
    CHECK_LIST(head, 10, 1, 20, 2, 3);

    head = InsertNode(head, 30, 6);             /* one past the end = append */
    CHECK_LIST(head, 10, 1, 20, 2, 3, 30);

    /* out of range: list must be unchanged */
    head = InsertNode(head, 99, 0);
    CHECK_LIST(head, 10, 1, 20, 2, 3, 30);

    head = InsertNode(head, 99, -1);
    CHECK_LIST(head, 10, 1, 20, 2, 3, 30);

    head = InsertNode(head, 99, 8);
    CHECK_LIST(head, 10, 1, 20, 2, 3, 30);

    FreeList(head);

    /* empty list */
    head = InsertNode(NULL, 5, 2);
    CHECK(head == NULL);

    head = InsertNode(NULL, 5, 1);
    CHECK_LIST(head, 5);

    FreeList(head);
}

static void test_delete_front(void)
{
    Node* head = DeleteNodeFront(NULL);         /* empty list */
    CHECK(head == NULL);

    head = BUILD(1, 2, 3);

    head = DeleteNodeFront(head);
    CHECK_LIST(head, 2, 3);

    head = DeleteNodeFront(head);
    CHECK_LIST(head, 3);

    head = DeleteNodeFront(head);               /* only node */
    CHECK(head == NULL);
}

static void test_delete_end(void)
{
    Node* head = DeleteNodeEnd(NULL);           /* empty list */
    CHECK(head == NULL);

    head = BUILD(1, 2, 3);

    head = DeleteNodeEnd(head);
    CHECK_LIST(head, 1, 2);

    head = DeleteNodeEnd(head);
    CHECK_LIST(head, 1);

    head = DeleteNodeEnd(head);                 /* only node */
    CHECK(head == NULL);
}

static void test_delete_at_position(void)
{
    Node* head = BUILD(1, 2, 3, 4, 5);

    /* out of range: list must be unchanged */
    head = DeleteNode(head, 0);
    CHECK_LIST(head, 1, 2, 3, 4, 5);

    head = DeleteNode(head, 6);
    CHECK_LIST(head, 1, 2, 3, 4, 5);

    head = DeleteNode(head, -3);
    CHECK_LIST(head, 1, 2, 3, 4, 5);

    head = DeleteNode(head, 1);                 /* front */
    CHECK_LIST(head, 2, 3, 4, 5);

    head = DeleteNode(head, 4);                 /* last */
    CHECK_LIST(head, 2, 3, 4);

    head = DeleteNode(head, 2);                 /* middle */
    CHECK_LIST(head, 2, 4);

    head = DeleteNode(head, 2);
    CHECK_LIST(head, 2);

    head = DeleteNode(head, 1);                 /* only node */
    CHECK(head == NULL);

    head = DeleteNode(head, 1);                 /* empty list */
    CHECK(head == NULL);
}

static void test_length(void)
{
    Node* head = NULL;
    int i;

    CHECK(GetLength(NULL) == 0);

    for (i = 1; i <= 5; i++)
    {
        head = InsertNodeFront(head, i);
        CHECK(GetLength(head) == i);
    }

    for (i = 4; i >= 0; i--)
    {
        head = DeleteNodeFront(head);
        CHECK(GetLength(head) == i);
    }
}

static void test_search(void)
{
    Node* head;

    CHECK(Search(NULL, 1) == FALSE);

    head = BUILD(4, 5, 6);
    CHECK(Search(head, 4) == TRUE);             /* first */
    CHECK(Search(head, 5) == TRUE);             /* middle */
    CHECK(Search(head, 6) == TRUE);             /* last */
    CHECK(Search(head, 7) == FALSE);
    CHECK(Search(head, 0) == FALSE);

    head = DeleteNode(head, 2);                 /* remove the 5 */
    CHECK(Search(head, 5) == FALSE);
    CHECK(Search(head, 6) == TRUE);

    FreeList(head);
}

static void test_free_list(void)
{
    Node* head;

    CHECK(FreeList(NULL) == NULL);

    head = BUILD(1, 2, 3);
    head = FreeList(head);
    CHECK(head == NULL);
}

#define STRESS_N 1000

static void test_stress(void)
{
    Node* head = NULL;
    Node* cur;
    int i;
    int in_order = TRUE;

    for (i = 0; i < STRESS_N; i++)
        head = InsertNodeTail(head, i);

    CHECK(GetLength(head) == STRESS_N);

    cur = head;
    for (i = 0; i < STRESS_N; i++)
    {
        if (cur == NULL || cur->data != i)
        {
            in_order = FALSE;
            break;
        }
        cur = cur->next;
    }
    CHECK(in_order);

    /* remove from both ends until nothing is left */
    for (i = 0; i < STRESS_N / 2; i++)
    {
        head = DeleteNodeFront(head);
        head = DeleteNodeEnd(head);
    }
    CHECK(head == NULL);
}

/* ---------- entry point ---------- */

int main(void)
{
    RUN(test_create_node);
    RUN(test_insert_front);
    RUN(test_insert_tail);
    RUN(test_insert_at_position);
    RUN(test_delete_front);
    RUN(test_delete_end);
    RUN(test_delete_at_position);
    RUN(test_length);
    RUN(test_search);
    RUN(test_free_list);
    RUN(test_stress);

    printf("\n%d checks run, %d failed\n", checks_run, checks_failed);

    return checks_failed == 0 ? 0 : 1;
}
