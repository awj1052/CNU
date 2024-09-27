#include "gtest/gtest.h"
#include "int_set.h"

class IntSetTest : public ::testing::Test {
 public:
    IntSetTest() : int_set_(5) {}

 protected:
    void SetUp() override {}
    void TearDown() override {}
    IntSet int_set_;
};

TEST_F(IntSetTest, IntSetAddTest1) {
    int_set_.Add(1);
    int_set_.Add(2);
    int_set_.Add(2);
    int_set_.Add(3);
    int_set_.Add(4);
    int_set_.Add(5);
    ASSERT_DEATH(int_set_.Add(6), "Exceeded capacity");
}

TEST_F(IntSetTest, IntSetAddTest2) {
    int_set_.Add(-1);
    int_set_.Add(-2);
    int_set_.Add(-2);
    int_set_.Add(2);
    int_set_.Add(3);
    EXPECT_EQ(int_set_.size(), 4);
}

TEST_F(IntSetTest, IntSetAddTest3) {
    int_set_.Add(0);
    EXPECT_EQ(int_set_.size(), 1);
}

TEST_F(IntSetTest, IntSetAddRefTest1) {
    int_set_.Add(-2);
    int_set_.Add(-1);
    int_set_.Add(0);
    IntSet other = IntSet(10);
    other.Add(1);
    other.Add(2);
    other.Add(3);
    ASSERT_DEATH(int_set_.Add(other), "Exceeded capacity");
}

TEST_F(IntSetTest, IntSetAddRefTest2) {
    IntSet other = IntSet(10);
    other.Add(1);
    other.Add(2);
    other.Add(3);
    int_set_.Add(0);
    int_set_.Add(1);
    int_set_.Add(other);
    EXPECT_EQ(int_set_.size(), 4);
}

TEST_F(IntSetTest, IntSetAddRefTest3) {
    IntSet other = IntSet(10);
    other.Add(1);
    int_set_.Add(1);
    int_set_.Add(other);
    EXPECT_EQ(int_set_.size(), 1);
}

TEST_F(IntSetTest, IntSetMapTest1) {
    int_set_.Add(0);
    int_set_.Add(1);
    int_set_.Add(2);
    int_set_.Map([](int i)
                 { return i * 2; });
    int* elements = int_set_.elements();
    int ans[] = {0, 2, 4};
    for (int i = 0; i < int_set_.size(); i++) {
        EXPECT_EQ(elements[i], ans[i]);
    }
}

TEST_F(IntSetTest, IntSetMapTest2) {
    int_set_.Add(0);
    int_set_.Add(1);
    int_set_.Add(2);
    int_set_.Map([](int i)
                 { return i * -1; });
    int* elements = int_set_.elements();
    int ans[] = {0, -1, -2};
    for (int i = 0; i < int_set_.size(); i++) {
        EXPECT_EQ(elements[i], ans[i]);
    }
}

TEST_F(IntSetTest, IntSetMapTest3) {
    int_set_.Add(0);
    int_set_.Add(1);
    int_set_.Add(2);
    int_set_.Add(3);
    int_set_.Add(4);
    int_set_.Map([](int i)
                 { return i*i; });
    int* elements = int_set_.elements();
    int ans[] = {0, 1, 4, 9, 16};
    for (int i = 0; i < int_set_.size(); i++) {
        EXPECT_EQ(elements[i], ans[i]);
    }
}

TEST_F(IntSetTest, IntSetForAllTest1) {
    int_set_.Add(0);
    int_set_.Add(1);
    int_set_.Add(2);
    bool result = int_set_.ForAll([](int i) {
                   if (i < 10) { return true; } else { return false; } });
    EXPECT_EQ(result, true);
}

TEST_F(IntSetTest, IntSetForAllTest2) {
    int_set_.Add(100);
    int_set_.Add(1);
    int_set_.Add(2);
    bool result = int_set_.ForAll([](int i) {
                   if (i < 10) { return true; } else { return false; } });
    EXPECT_EQ(result, false);
}

TEST_F(IntSetTest, IntSetForAllTest3) {
    int_set_.Add(1);
    int_set_.Add(2);
    int_set_.Add(3);
    IntSet other = IntSet(int_set_);
    other.Add(4);
    other.Add(5);
    bool result = int_set_.ForAll([](int i) {
                   if (i % 2) { return true; } else { return false; } });
    EXPECT_EQ(result, false);
}

