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
    EXPECT_EQ(vector_.size(), 3);
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
    EXPECT_EQ(list_.size(), 3);
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
