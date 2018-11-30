#include "aiv_unit_test.h"
#include "lists.h"

TEST(list_creation)
{
    list_item *head = list_append(NULL, "test");
    ASSERT_THAT(head);
    ASSERT_THAT(!head->next);
}

TEST(list_append)
{
    list_item *head = list_append(NULL, "head");
    list_item *tail = list_append(head, "tail");
    ASSERT_THAT(head->next == tail);
}

TEST(list_get)
{
    list_item *first = list_append(NULL, "first");
    list_item *second = list_append(first, "second");
    list_item *third = list_append(second, "third");
    ASSERT_THAT(list_get(first, 0) == first);
    ASSERT_THAT(list_get(first, 1) == second);
    ASSERT_THAT(list_get(first, 2) == third);
    ASSERT_THAT(list_get(first, 3) == NULL);
}

TEST(list_size)
{
    list_item *head = list_append(NULL, "test");
    ASSERT_THAT(list_size(head) == 1);
    list_append(head, "second");
    ASSERT_THAT(list_size(head) == 2);
}

TEST(list_remove)
{
    list_item *first = list_append(NULL, "first");
    list_item *second = list_append(first, "second");
    list_item *third = list_append(second, "third");
    list_item *head = list_remove(first, second);
    ASSERT_THAT(list_size(first) == 2);
    ASSERT_THAT(first->next == third);
    ASSERT_THAT(head == first);
}

TEST(list_remove_index)
{
    list_item *first = list_append(NULL, "first");
    list_item *second = list_append(first, "second");
    list_item *third = list_append(second, "third");
    list_item *head = list_remove_by_index(first, 0);
    ASSERT_THAT(list_size(head) == 2);
    ASSERT_THAT(head == second);
}

int main(int argc, char **argv)
{
    RUN_TEST(list_creation);
    RUN_TEST(list_append);
    RUN_TEST(list_get);
    RUN_TEST(list_size);
    RUN_TEST(list_remove);
    RUN_TEST(list_remove_index);
    PRINT_TEST_RESULTS();
}
