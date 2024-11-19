#include <gtest/gtest.h>

#include "Mat2.h"
#include "Vec2.h"

struct Mat2OperationFixture : public ::testing::TestWithParam<std::tuple<core::Mat2<core::Vec2<float>>, core::Mat2<core::Vec2<float>>>>
{

};

TEST_P(Mat2OperationFixture, Addition)
{
    core::Mat2<float> Matrice1{1.0f, 2.0f, 3.0f, 4.0f};
    core::Mat2<float> Matrice2{5.0f, 6.0f, 7.0f, 8.0f};

    const auto result = Matrice1 + Matrice2;

    EXPECT_FLOAT_EQ(result.matrix_[0][0], 6.0f);
    EXPECT_FLOAT_EQ(result.matrix_[0][1], 8.0f);
    EXPECT_FLOAT_EQ(result.matrix_[1][0], 10.0f);
    EXPECT_FLOAT_EQ(result.matrix_[1][1], 12.0f);
}

TEST_P(Mat2OperationFixture, Multiplication)
{
    core::Mat2<float> Matrice1{ 1.0f, 2.0f, 3.0f, 4.0f };
    core::Mat2<float> Matrice2{ 5.0f, 6.0f, 7.0f, 8.0f };

    const auto result = Matrice1 * Matrice2;

    EXPECT_FLOAT_EQ(result.matrix_[0][0], 6.0f);
    EXPECT_FLOAT_EQ(result.matrix_[0][1], 8.0f);
    EXPECT_FLOAT_EQ(result.matrix_[1][0], 10.0f);
    EXPECT_FLOAT_EQ(result.matrix_[1][1], 12.0f);
}

INSTANTIATE_TEST_SUITE_P
(
    Default,
    Mat2OperationFixture,
    ::testing::Values()  // Add parameter values if needed
);