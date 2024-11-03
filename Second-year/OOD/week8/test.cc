#include "gtest/gtest.h"
#include "car_builder.h"
#include "hyundai_parts_factory.h"
#include "kia_parts_factory.h"

class HyundaiCarBuilderTest : public ::testing::Test {
 public:
    HyundaiCarBuilderTest() :
        car_builder_(new CarBuilder(HyundaiPartsFactory::GetInstance())) {}
 protected:
    void SetUp() override {}
    void TearDown() override {}
    CarBuilder* car_builder_;
};

class KiaCarBuilderTest : public ::testing::Test {
 public:
    KiaCarBuilderTest() :
        car_builder_(new CarBuilder(KiaPartsFactory::GetInstance())) {}
 protected:
    void SetUp() override {}
    void TearDown() override {}
    CarBuilder* car_builder_;
};

// Hyundai
TEST_F(HyundaiCarBuilderTest, HyundaiTest1) {
    auto car = car_builder_->CreateDoor()
                            .CreateWheel()
                            .CreateRoof()
                            .SetColor("red").Build();
    EXPECT_EQ(car->GetSpec(),
        "Car([hyundai] Door, [hyundai] Wheel, [hyundai] Roof, red)");

    delete car;
    delete car_builder_;
}

TEST_F(HyundaiCarBuilderTest, HyundaiTest2) {
    auto car = car_builder_->CreateWheel()
                            .SetColor("blue").Build();
    EXPECT_EQ(car->GetSpec(),
        "Car([hyundai] Wheel, blue)");

    delete car;
    delete car_builder_;
}

TEST_F(HyundaiCarBuilderTest, HyundaiTest3) {
    ASSERT_DEATH(car_builder_->CreateDoor()
                            .CreateDoor(),
                "Duplicated Parts retain : Door");

    delete car_builder_;
}

// Kia
TEST_F(KiaCarBuilderTest, KiaTest1) {
    auto car = car_builder_->CreateWheel()
                            .CreateRoof()
                            .SetColor("black").Build();
    EXPECT_EQ(car->GetSpec(),
        "Car([kia] Wheel, [kia] Roof, black)");

    delete car;
    delete car_builder_;
}

TEST_F(KiaCarBuilderTest, KiaTest2) {
    auto car1 = car_builder_->CreateDoor()
                            .CreateRoof().SetColor("white").Build();
    auto car2 = car_builder_->CreateDoor()
                            .CreateWheel().SetColor("black").Build();

    *car1 = *car2;

    EXPECT_EQ(car1->GetSpec(),
        "Car([kia] Door, [kia] Wheel, black)");

    delete car1;
    delete car2;
    delete car_builder_;
}

TEST_F(KiaCarBuilderTest, KiaTest3) {
    ASSERT_DEATH(car_builder_->SetColor("111").SetColor("222")
                            .CreateDoor().CreateRoof()
                            .CreateWheel().CreateWheel(),
                "Duplicated Parts retain : Wheel");

    delete car_builder_;
}
