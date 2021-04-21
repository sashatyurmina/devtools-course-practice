// Copyright 2021 Tyurmina Alexandra

#include <gtest/gtest.h>
#include "include/calculate_price.h"

TEST(CalculatePrice,
  Do_Throw_When_Create_Basket_With_Negative_Value) {

  ASSERT_ANY_THROW(CalculatePrice(1, -2, 3, 4, 5));
}

TEST(CalculatePrice, Can_Create_Basket_With_Zero_Value) {

  ASSERT_NO_THROW(CalculatePrice(0, 0, 0, 0, 0));
}

TEST(CalculatePrice,
  Calculate_Price_Same_Parts_Of_Books_Without_Discount) {
  CalculatePrice b(7, 0, 0, 0, 0);
  double price = 56.0;

  EXPECT_EQ(price, b.TotalSum());
}

TEST(CalculatePrice,
  Calculate_Price_With_Discount_Only_For_Different_Books) {
  CalculatePrice b(7, 1, 0, 0, 0);
  double price = 63.2;

  EXPECT_EQ(price, b.TotalSum());
}

TEST(CalculatePrice, Calculate_Price_With_Maximum_Discount) {
  CalculatePrice b(5, 4, 3, 2, 1);
  double price = 100.4;

  EXPECT_EQ(price, b.TotalSum());
}

TEST(CalculatePrice,
  Correct_Calculate_Price_Of_Shopping_Basket_With_Zero_Value) {
  CalculatePrice b(0, 0, 0, 0, 0);
  double price = 0.0;

  EXPECT_EQ(price, b.TotalSum());
}

TEST(CalculatePrice, Correct_Calculate_Irrespective_Of_Parts_Of_Book) {
  CalculatePrice b(0, 0, 2, 1, 0);
  double price = 23.2;

  EXPECT_EQ(price, b.TotalSum());
}

TEST(CalculatePrice, No_Discount_On_One_Book) {
  CalculatePrice b(1, 0, 0, 0, 0);
  double price = 8.0;

  EXPECT_EQ(price, b.TotalSum());
}

TEST(CalculatePrice, Correct_Discount_On_Two_Different_Books) {
  CalculatePrice b(1, 1, 0, 0, 0);
  double price = 15.2;

  EXPECT_EQ(price, b.TotalSum());
}

TEST(CalculatePrice, Correct_Discount_On_Three_Different_Books) {
  CalculatePrice b(1, 1, 1, 0, 0);
  double price = 21.6;

  EXPECT_EQ(price, b.TotalSum());
}

TEST(CalculatePrice, Correct_Discount_On_Four_Different_Books) {
  CalculatePrice b(1, 1, 1, 1, 0);
  double price = 25.6;

  EXPECT_EQ(price, b.TotalSum());
}

TEST(CalculatePrice, Correct_Discount_On_All_Books) {
  CalculatePrice b(1, 1, 1, 1, 1);
  double price = 30.0;

  EXPECT_EQ(price, b.TotalSum());
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
