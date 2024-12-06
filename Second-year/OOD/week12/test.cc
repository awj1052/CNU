#include <string>

#include "gtest/gtest.h"
#include "vector.h"
#include "list.h"
#include "safe_int.h"

class VectorTest : public ::testing::Test {
 public:
    VectorTest() :
        vector_(Vector<SafeInt>(2)) {}
 protected:
    void SetUp() override {}
    void TearDown() override {}
    Vector<SafeInt> vector_;
};

class ListTest : public ::testing::Test {
 public:
    ListTest() :
        list_(List<int>()) {}
 protected:
    void SetUp() override {}
    void TearDown() override {}
    List<int> list_;
};

class SafeIntTest : public ::testing::Test {
 protected:
    void SetUp() override {}
    void TearDown() override {}
};

TEST_F(SafeIntTest, SafeIntTest1) {
    SafeInt safe_ = SafeInt(1);
    const int kMax = std::numeric_limits<int>::max();
    try {
        safe_ + SafeInt(kMax);
        FAIL();
    } catch (std::overflow_error& e) {
        EXPECT_EQ(e.what(),
            "Integer overflow occurs in 1 + " + std::to_string(kMax));
    }
}

TEST_F(SafeIntTest, SafeIntTest2) {
    SafeInt safe_ = SafeInt(1);
    const int kMin = std::numeric_limits<int>::min();
    const int kMax = std::numeric_limits<int>::max();
    try {
        SafeInt(kMin) - SafeInt(1);
        FAIL();
    } catch (std::overflow_error& e) {
        EXPECT_EQ(e.what(),
            "Integer overflow occurs in " + std::to_string(kMin) + " - 1");
    }
}

TEST_F(SafeIntTest, SafeIntTest3) {
    const int kMin = std::numeric_limits<int>::min();
    const int kMax = std::numeric_limits<int>::max();
    SafeInt safe_ = SafeInt(kMax);
    std::string msg = "Integer overflow occurs in "
            + std::to_string(kMax) + " * "
            + std::to_string(kMax);
    try {
        safe_ * safe_;
        FAIL();
    } catch (std::overflow_error& e) {
        EXPECT_EQ(e.what(), msg);
    }
}

TEST_F(SafeIntTest, SafeIntTest4) {
    const int kMax = std::numeric_limits<int>::max();
    SafeInt safe_ = SafeInt(kMax);
    try {
        safe_ / SafeInt(0);
        FAIL();
    } catch (DivideByZeroException& e) {
        EXPECT_EQ(e.what(),
            "Divide-by-zero exception occurs in " + std::to_string(kMax) +"/0");
    }
}

TEST_F(SafeIntTest, SafeIntTest5) {
    const int kMax = std::numeric_limits<int>::max();
    SafeInt safe_ = SafeInt(kMax);
    try {
        safe_ % SafeInt(0);
        FAIL();
    } catch (DivideByZeroException& e) {
        EXPECT_EQ(e.what(),
            "Divide-by-zero exception occurs in " + std::to_string(kMax) +"%0");
    }
}

TEST_F(SafeIntTest, SafeIntTest6) {
    const int kMax = std::numeric_limits<int>::max();
    SafeInt safe_ = SafeInt(kMax);
    try {
        safe_ % SafeInt(1);
    } catch (std::overflow_error& e) {
        FAIL();
    }
}

TEST_F(SafeIntTest, SafeIntTest7) {
    const int kMax = std::numeric_limits<int>::max();
    SafeInt safe_ = SafeInt(kMax);
    try {
        safe_ - SafeInt(1);
    } catch (std::overflow_error& e) {
        FAIL();
    }
}

TEST_F(SafeIntTest, SafeIntTest8) {
    const int kMin = std::numeric_limits<int>::min();
    SafeInt safe_ = SafeInt(kMin);
    try {
        safe_ + SafeInt(1);
    } catch (std::overflow_error& e) {
        FAIL();
    }
}

TEST_F(SafeIntTest, SafeIntTest9) {
    const int kMax = std::numeric_limits<int>::max();
    try {
        SafeInt(2) * SafeInt(10);
    } catch (std::overflow_error& e) {
        FAIL();
    }
}

TEST_F(VectorTest, VectorTest1) {
    vector_.PushBack(SafeInt(1));
    try {
        vector_[1];
        FAIL();
    } catch (std::out_of_range& e) {
        EXPECT_EQ(e.what(),
            std::string("The index is 1, but the size is 1"));
    }
}

TEST_F(VectorTest, VectorTest11) {
    vector_.PushBack(SafeInt(1));
    try {
        vector_[0];
    } catch (std::out_of_range& e) {
        FAIL();
    }
}

TEST_F(VectorTest, VectorTest2) {
    vector_.PushBack(SafeInt(1));
    try {
        vector_.PopBack();
        vector_.PopBack();
        FAIL();
    } catch (EmptyContainerException& e) {
        EXPECT_EQ(e.what(), std::string("This vector is empty"));
    }
}

TEST_F(VectorTest, VectorTest22) {
    vector_.PushBack(SafeInt(1));
    try {
        vector_.PopBack();
    } catch (EmptyContainerException& e) {
       FAIL();
    }
}

TEST_F(ListTest, ListTest1) {
    list_.PushBack(2);
    list_.PushFront(1);
    list_.PushBack(3);
    try {
        list_.At(list_.size());
        FAIL();
    } catch (std::out_of_range& e) {
        EXPECT_EQ(e.what(),
            std::string("The index is 3, but the size is 3"));
    }
}

TEST_F(ListTest, ListTest11) {
    list_.PushBack(2);
    list_.PushFront(1);
    list_.PushBack(3);
    try {
        list_.At(list_.size()-1);
    } catch (std::out_of_range& e) {
        FAIL();
    }
}

TEST_F(ListTest, ListTest2) {
    list_.PushBack(2);
    list_.PushFront(1);
    list_.PushBack(3);
    try {
        list_.PopBack();
        list_.PopBack();
        list_.PopBack();
        list_.PopBack();
        FAIL();
    } catch (EmptyContainerException& e) {
        EXPECT_EQ(e.what(), std::string("This list is empty"));
    }
}

TEST_F(ListTest, ListTest22) {
    list_.PushBack(2);
    list_.PushFront(1);
    list_.PushBack(3);
    try {
        list_.PopBack();
        list_.PopBack();
        list_.PopBack();
    } catch (EmptyContainerException& e) {
        FAIL();
    }
}
