//
// Created by George Thiruvathukal on 2/17/24.
//
 
#include <gtest/gtest.h>

#include "int_stack.hh"

TEST(IntStackTests, Initialization)
{
    int_stack_t stack1;
    int_stack_init(&stack1, 10);
    ASSERT_EQ(int_stack_size(&stack1), 0);
    ASSERT_EQ(int_stack_capacity(&stack1), 10);
}

TEST(IntStackTests, PushToCapacityAndOverflow)
{
    // create stack that can hold 10 items
    int_stack_t stack1;
    const int capacity = 10;
    int_stack_init(&stack1, capacity);

    // fill it
    for (int i=0; i < capacity; i++) {
        int result = int_stack_push(&stack1, i);
        ASSERT_TRUE(result);
    }

    // ensure it's full
    ASSERT_EQ(int_stack_size(&stack1), capacity);

    // try to add one more
    int result = int_stack_push(&stack1, capacity+1);

    // and make sure it is an overflow (error)
    ASSERT_FALSE(result);
}


TEST(IntStackTests, PushToCapcacityPopUntilUnderflow
)
{
    // create stack that can hold 10 items [similar to previous test]
    int_stack_t stack1;
    const int capacity = 10;
    int_stack_init(&stack1, capacity);

    // fill it
    for (int i=0; i < capacity; i++) {
        int result = int_stack_push(&stack1, i);
        ASSERT_TRUE(result);
    }

    // now drain it one item at a time, ensuring each item is the value expected
    for (int i=capacity-1; i >= 0; i--) {
        int top_value;
        int result = int_stack_pop(&stack1, &top_value);
        ASSERT_EQ(i, top_value);
    }

    // try to remove from empty stack and ensure it fails
    int top_value;
    int result = int_stack_pop(&stack1, &top_value);
    ASSERT_FALSE(result);
}

TEST(IntStackTests, OverOperation)
{
    int_stack_t stack;
    int_stack_init(&stack, 3);
    int_stack_push(&stack, 10);
    int_stack_push(&stack, 20);
    ASSERT_TRUE(int_stack_over(&stack));
    int top_value;
    int_stack_pop(&stack, &top_value);
    ASSERT_EQ(top_value, 10); 
}

TEST(IntStackTests, RotOperation)
{
    int_stack_t stack;
    int_stack_init(&stack, 3);
    int_stack_push(&stack, 10);
    int_stack_push(&stack, 20);
    int_stack_push(&stack, 30);
    ASSERT_TRUE(int_stack_rot(&stack));
    int top_value;
    int_stack_pop(&stack, &top_value);
    ASSERT_EQ(top_value, 10);
}

TEST(IntStackTests, DropOperation)
{
    int_stack_t stack;
    int_stack_init(&stack, 2);
    int_stack_push(&stack, 10);
    int_stack_push(&stack, 20);
    ASSERT_TRUE(int_stack_drop(&stack));
    int top_value;
    int_stack_pop(&stack, &top_value);
    ASSERT_EQ(top_value, 10);
}

TEST(IntStackTests, TwoSwapOperation)
{
    int_stack_t stack;
    int_stack_init(&stack, 4);
    int_stack_push(&stack, 10);
    int_stack_push(&stack, 20);
    int_stack_push(&stack, 30);
    int_stack_push(&stack, 40);
    ASSERT_TRUE(int_stack_2swap(&stack));
    int top_value;
    int_stack_pop(&stack, &top_value);
    ASSERT_EQ(top_value, 20);
    int_stack_pop(&stack, &top_value);
    ASSERT_EQ(top_value, 10);
}

TEST(IntStackTests, TwoDupOperation)
{
    int_stack_t stack;
    int_stack_init(&stack, 4);
    int_stack_push(&stack, 10);
    int_stack_push(&stack, 20);
    ASSERT_TRUE(int_stack_2dup(&stack));
    int top_value;
    int_stack_pop(&stack, &top_value);
    ASSERT_EQ(top_value, 20);
    int_stack_pop(&stack, &top_value);
    ASSERT_EQ(top_value, 10);
}
TEST(IntStackTests, TwoOverOperation)
{
    int_stack_t stack;
    int_stack_init(&stack, 6);
    int_stack_push(&stack, 10);
    int_stack_push(&stack, 20);
    int_stack_push(&stack, 30);
    int_stack_push(&stack, 40);
    ASSERT_TRUE(int_stack_2over(&stack));
    int top_value;
    int_stack_pop(&stack, &top_value);
    ASSERT_EQ(top_value, 20);
    int_stack_pop(&stack, &top_value);
    ASSERT_EQ(top_value, 10);
}

TEST(IntStackTests, TwoDropOperation)
{
    int_stack_t stack;
    int_stack_init(&stack, 4);
    int_stack_push(&stack, 10);
    int_stack_push(&stack, 20);
    int_stack_push(&stack, 30);
    int_stack_push(&stack, 40);
    ASSERT_TRUE(int_stack_2drop(&stack));
    ASSERT_EQ(int_stack_size(&stack), 2);
    int top_value;
    int_stack_pop(&stack, &top_value);
    ASSERT_EQ(top_value, 20);
    int_stack_pop(&stack, &top_value);
    ASSERT_EQ(top_value, 10);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}