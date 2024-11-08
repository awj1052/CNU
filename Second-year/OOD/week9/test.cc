#include "gtest/gtest.h"
#include "vector.h"
#include "list.h"
#include "stack.h"
#include "queue.h"

class VectorTest : public ::testing::Test {
 public:
    VectorTest() :
        vector_(Vector(2)) {}
 protected:
    void SetUp() override {}
    void TearDown() override {}
    Vector vector_;
};

class ListTest : public ::testing::Test {
 public:
    ListTest() :
        list_(List()) {}
 protected:
    void SetUp() override {}
    void TearDown() override {}
    List list_;
};

class StackTest : public ::testing::Test {
 public:
    StackTest() :
        stack_(Stack(2)) {}
 protected:
    void SetUp() override {}
    void TearDown() override {}
    Stack stack_;
};

class QueueTest : public ::testing::Test {
 public:
    QueueTest() :
        queue_(Queue()) {}
 protected:
    void SetUp() override {}
    void TearDown() override {}
    Queue queue_;
};

TEST_F(VectorTest, VectorTest1) {
    vector_.PushBack(1);
    vector_.PushBack(2);
    vector_.PushBack(3);
    EXPECT_EQ(vector_.capacity(), 6);
}

TEST_F(VectorTest, VectorTest2) {
    vector_.PushBack(1);
    vector_.PushBack(2);
    vector_.PushBack(3);
    Vector vec = Vector(vector_);
    EXPECT_EQ(vec[1], 2);
}

TEST_F(VectorTest, VectorTest3) {
    vector_.PushBack(1);
    vector_.PushBack(2);
    vector_.PushBack(3);
    EXPECT_EQ(vector_[1], 2);
}

TEST_F(VectorTest, VectorTest4) {
    vector_.PushBack(1);
    vector_.PushBack(2);
    vector_.PushBack(3);
    Vector vector2 = Vector(10);
    vector2.PushBack(10);
    vector_ = vector2;
    EXPECT_EQ(vector_[0], 10);
}

TEST_F(VectorTest, VectorTest5) {
    vector_.PushBack(1);
    ASSERT_DEATH(vector_[1], "Out-of-bound");
}

TEST_F(ListTest, ListTest1) {
    list_.PushBack(2);
    list_.PushFront(1);
    list_.PushBack(3);
    List lst = List(list_);
    EXPECT_EQ(lst.At(1), 2);
}

TEST_F(ListTest, ListTest2) {
    list_.PushBack(2);
    list_.PushFront(1);
    list_.PushBack(3);
    list_.PopFront();
    EXPECT_EQ(list_.At(0), 2);
}

TEST_F(ListTest, ListTest3) {
    list_.PushBack(2);
    list_.PushFront(1);
    list_.PushBack(3);
    list_.PopBack();
    EXPECT_EQ(list_.At(list_.size() - 1), 2);
}

TEST_F(ListTest, ListTest4) {
    list_.PushBack(2);
    list_.PushFront(1);
    list_.PushBack(3);
    List lst = List();
    lst.PushBack(-1);
    lst.PushBack(-2);
    lst.PushBack(-3);
    list_ = lst;
    EXPECT_EQ(list_.At(1), -2);
}

TEST_F(ListTest, ListTest5) {
    list_.PushBack(2);
    list_.PushFront(1);
    list_.PushBack(3);
    ASSERT_DEATH(list_.At(3), "Out-of-bound");
}

TEST_F(StackTest, StackTest1) {
    stack_.Push(1);
    stack_.Push(2);
    stack_.Push(3);
    stack_.Push(4);
    stack_.Pop();
    stack_.Pop();
    EXPECT_EQ(stack_.Pop(), 2);
}

TEST_F(StackTest, StackTest2) {
    stack_.Push(1);
    stack_.Push(2);
    stack_.Push(3);
    EXPECT_EQ(stack_.size(), 3);
}

TEST_F(StackTest, StackTest3) {
    stack_.Push(1);
    Stack st = Stack(5);
    st.Push(-1);
    st.Push(-2);
    st.Push(-3);
    stack_ = st;
    EXPECT_EQ(stack_.Pop(), -3);
}

TEST_F(StackTest, StackTest4) {
    stack_.Push(1);
    stack_.Push(2);
    stack_.Push(3);
    Stack st = Stack(stack_);
    EXPECT_EQ(st.Pop(), 3);
}

TEST_F(StackTest, StackTest5) {
    stack_.Push(1);
    stack_.Push(2);
    stack_.Pop();
    stack_.Pop();
    ASSERT_DEATH(stack_.Pop(), "Out-of-bound");
}

TEST_F(QueueTest, QueueTest1) {
    queue_.Add(1);
    queue_.Add(2);
    queue_.Add(3);
    EXPECT_EQ(queue_.Poll(), 1);
}

TEST_F(QueueTest, QueueTest2) {
    queue_.Add(1);
    queue_.Add(2);
    queue_.Add(3);
    queue_.Poll();
    EXPECT_EQ(queue_.Poll(), 2);
}

TEST_F(QueueTest, QueueTest3) {
    queue_.Add(1);
    Queue q = Queue();
    q.Add(-1);
    q.Add(-2);
    queue_ = q;
    EXPECT_EQ(queue_.Poll(), -1);
}

TEST_F(QueueTest, QueueTest4) {
    queue_.Add(1);
    queue_.Add(2);
    Queue q = Queue(queue_);
    q.Add(3);
    EXPECT_EQ(q.size(), 3);
}

TEST_F(QueueTest, QueueTest5) {
    queue_.Add(1);
    queue_.Add(2);
    queue_.Poll();
    queue_.Poll();
    ASSERT_DEATH(queue_.Poll(), "Out-of-bound");
}
