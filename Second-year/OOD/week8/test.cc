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

TEST_F(HyundaiCarBuilderTest, HyundaiTest1) {
    Car* car = car_builder_->CreateDoor()
                            .CreateWheel()
                            .CreateRoof()
                            .SetColor("ood").Build();
    EXPECT_EQ(car->GetSpec(),
        "Car([hyundai] Door, [hyundai] Wheel, [hyundai] Roof, ood)");

    delete car;
    delete car_builder_;
}

TEST_F(HyundaiCarBuilderTest, HyundaiTest2) {
    Car* car = car_builder_->CreateRoof()
                            .SetColor("hehe").Build();
    EXPECT_EQ(car->GetSpec(),
        "Car([hyundai] Roof, hehe)");

    delete car;
    delete car_builder_;
}

TEST_F(HyundaiCarBuilderTest, HyundaiTest3) {
    ASSERT_DEATH(car_builder_->CreateDoor()
                            .CreateDoor(),
                "Duplicated Parts retain : Door");

    delete car_builder_;
}

TEST_F(KiaCarBuilderTest, KiaTest1) {
    Car* car = car_builder_->CreateWheel()
                            .CreateRoof()
                            .SetColor("IWANTTOGOHOME").Build();
    EXPECT_EQ(car->GetSpec(),
        "Car([kia] Wheel, [kia] Roof, IWANTTOGOHOME)");

    delete car;
    delete car_builder_;
}

TEST_F(KiaCarBuilderTest, KiaTest2) {
    Car* car1 = car_builder_->CreateDoor()
                            .CreateWheel()
                            .CreateRoof().Build();
    Car* car2 = car_builder_->SetColor("PINK").Build();

    *car1 = *car2;

    EXPECT_EQ(car1->GetSpec(),
        "Car(PINK)");

    delete car1;
    delete car2;
    delete car_builder_;
}

TEST_F(KiaCarBuilderTest, KiaTest3) {
    ASSERT_DEATH(car_builder_->CreateDoor().CreateRoof()
                            .CreateWheel().CreateWheel(),
                "Duplicated Parts retain : Wheel");

    delete car_builder_;
}
