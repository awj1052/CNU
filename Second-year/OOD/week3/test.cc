#include "gtest/gtest.h"
#include "int_accumulator.h"
#include "float_accumulator.h"

class IntAccTest : public ::testing::Test {
 public:
    IntAccTest() : accumulator_(3) {}
 protected:
    void SetUp() override { }
    void TearDown() override { }
    int_accumulator::Accumulator accumulator_;
};

TEST_F(IntAccTest, IntAccAddTest1) {
    accumulator_.Add(3);
    EXPECT_EQ(accumulator_.acc(), 6);
}

TEST_F(IntAccTest, IntAccAddTest2) {
    accumulator_.Add(-3);
    EXPECT_EQ(accumulator_.acc(), 0);
}

TEST_F(IntAccTest, IntAccAddTest3) {
    accumulator_.Add(9);
    EXPECT_EQ(accumulator_.acc(), 12);
}

TEST_F(IntAccTest, IntAccSubTest1) {
    accumulator_.Sub(3);
    EXPECT_EQ(accumulator_.acc(), 0);
}

TEST_F(IntAccTest, IntAccSubTest2) {
    accumulator_.Sub(-3);
    EXPECT_EQ(accumulator_.acc(), 6);
}

TEST_F(IntAccTest, IntAccSubTest3) {
    accumulator_.Sub(9);
    EXPECT_EQ(accumulator_.acc(), -6);
}

TEST_F(IntAccTest, IntAccMulTest1) {
    accumulator_.Mul(3);
    EXPECT_EQ(accumulator_.acc(), 9);
}

TEST_F(IntAccTest, IntAccMulTest2) {
    accumulator_.Mul(-3);
    EXPECT_EQ(accumulator_.acc(), -9);
}

TEST_F(IntAccTest, IntAccMulTest3) {
    accumulator_.Mul(0);
    EXPECT_EQ(accumulator_.acc(), 0);
}

TEST_F(IntAccTest, IntAccDivTest1) {
    accumulator_.Div(2);
    EXPECT_EQ(accumulator_.acc(), 1);
}

TEST_F(IntAccTest, IntAccDivTest2) {
    accumulator_.Div(-2);
    EXPECT_EQ(accumulator_.acc(), -1);
}

TEST_F(IntAccTest, IntAccDivTest3) {
    ASSERT_DEATH(accumulator_.Div(0), "Divide-by-zero");
}

class FloatAccTest : public ::testing::Test {
 public:
    FloatAccTest() : accumulator_(3.5) {}
 protected:
    void SetUp() override { }
    void TearDown() override { }
    float_accumulator::Accumulator accumulator_;
};

TEST_F(FloatAccTest, FloatAccAddTest1) {
    accumulator_.Add(3.3);
    EXPECT_FLOAT_EQ(accumulator_.acc(), 6.8);
}

TEST_F(FloatAccTest, FloatAccAddTest2) {
    accumulator_.Add(-3.8);
    EXPECT_FLOAT_EQ(accumulator_.acc(), -0.3);
}

TEST_F(FloatAccTest, FloatAccAddTest3) {
    accumulator_.Add(-3.5);
    EXPECT_FLOAT_EQ(accumulator_.acc(), 0);
}

TEST_F(FloatAccTest, FloatAccSubTest1) {
    accumulator_.Sub(-3.3);
    EXPECT_FLOAT_EQ(accumulator_.acc(), 6.8);
}

TEST_F(FloatAccTest, FloatAccSubTest2) {
    accumulator_.Sub(3.8);
    EXPECT_FLOAT_EQ(accumulator_.acc(), -0.3);
}

TEST_F(FloatAccTest, FloatAccSubTest3) {
    accumulator_.Sub(3.5);
    EXPECT_FLOAT_EQ(accumulator_.acc(), 0);
}

TEST_F(FloatAccTest, FloatAccMulTest1) {
    accumulator_.Mul(2.5);
    EXPECT_FLOAT_EQ(accumulator_.acc(), 8.75);
}

TEST_F(FloatAccTest, FloatAccMulTest2) {
    accumulator_.Mul(-2.5);
    EXPECT_FLOAT_EQ(accumulator_.acc(), -8.75);
}

TEST_F(FloatAccTest, FloatAccMulTest3) {
    accumulator_.Mul(0);
    EXPECT_FLOAT_EQ(accumulator_.acc(), 0);
}

TEST_F(FloatAccTest, FloatAccDivTest1) {
    accumulator_.Div(2.5);
    EXPECT_FLOAT_EQ(accumulator_.acc(), 1.4);
}

TEST_F(FloatAccTest, FloatAccDivTest2) {
    accumulator_.Div(-2.5);
    EXPECT_FLOAT_EQ(accumulator_.acc(), -1.4);
}

TEST_F(FloatAccTest, FloatAccDivTest3) {
    ASSERT_DEATH(accumulator_.Div(0), "Divide-by-zero");
}
