#include <gtest/gtest.h>

#include "vec2.h"

struct Vec2iOperationFixture : public ::testing::TestWithParam<std::pair<core::Vec2<int>, core::Vec2<int>>>
{
	
};

TEST_P(Vec2iOperationFixture, Add)
{
	core::Vec2<float> v1{1, 2};
	core::Vec2<float> v2{3, 4};
	core::Vec2<float> result = v1 + v2;

	EXPECT_FLOAT_EQ(result.x, 4);
	EXPECT_FLOAT_EQ(result.y, 6);
}

TEST_P(Vec2iOperationFixture, Sub)
{
	core::Vec2<float> v1{ 1, 2 };
	core::Vec2<float> v2{ 3, 4 };
	core::Vec2<float> result = v1 - v2;

	EXPECT_FLOAT_EQ(result.x, -2);
	EXPECT_FLOAT_EQ(result.y, -2);

	const auto neg1 = -v1;
	const auto neg2 = -v2;
	EXPECT_FLOAT_EQ(neg1.x, -1);
	EXPECT_FLOAT_EQ(neg1.y, -2);
	EXPECT_FLOAT_EQ(neg2.x, -3);
	EXPECT_FLOAT_EQ(neg2.y, -4);
}

TEST_P(Vec2iOperationFixture, Perpendicular)
{
	core::Vec2<float> v1{ 1.0f, 2.0f };
	core::Vec2<float> result1 = v1.Perpendicular();

	EXPECT_FLOAT_EQ(result1.x, -2.0f);
	EXPECT_FLOAT_EQ(result1.y, 1.0f);

	core::Vec2<float> v2{ 1.0f, 2.0f };
	core::Vec2<float> result2 = v2.Perpendicular2();

	EXPECT_FLOAT_EQ(result2.x, 2.0f);
	EXPECT_FLOAT_EQ(result2.y, -1.0f);
}

INSTANTIATE_TEST_SUITE_P(PositiveNumbers,
    Vec2iOperationFixture,
    testing::Values(
        std::pair{ core::Vec2{1,3}, core::Vec2{2,4} },
        std::pair{ core::Vec2{10, 15}, core::Vec2{25, 35} }
    )
);