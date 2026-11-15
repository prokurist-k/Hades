#include "../Engine/Source/Core/Math/Vector2.h"
#include "Source/Core/Math/HadesMath.h"
#include "gtest/gtest.h"
#include <gtest/gtest.h>

TEST(Vector2, ConstructFromXYZ)
{
    const float x = 1.0f;
    const float y = 2.0f;

    Hades::CVector2 a(x, y);
    EXPECT_FLOAT_EQ(a.x, x);
    EXPECT_FLOAT_EQ(a.y, y);
}

TEST(Vector2, ConstructFromValue)
{
    const float value = 1729.0f;

    Hades::CVector2 a(value);
    EXPECT_FLOAT_EQ(a.x, value);
    EXPECT_FLOAT_EQ(a.y, value);
}

TEST(Vector2, CopyConstruct)
{
    Hades::CVector2 original(1.0f, 2.0f);
    Hades::CVector2 copy(original);

    EXPECT_FLOAT_EQ(copy.x, original.x);
    EXPECT_FLOAT_EQ(copy.y, original.y);
}

TEST(Vector2, Equal)
{
    const float x = 54.0f;
    const float y = 83.5f;
    Hades::CVector2 a(x, y);
    Hades::CVector2 b(x, y);

    EXPECT_TRUE(a == b);
}

TEST(Vector2, NotEqualBeyondTolerance)
{
    Hades::CVector2 a(1.0f, 2.0f);
    Hades::CVector2 b(1.1f, 2.0f);

    EXPECT_FALSE(a == b);
}

TEST(Vector2, NotEqualJustBeyondTolerance)
{
    Hades::CVector2 a(1.0f, 2.0f);
    Hades::CVector2 b(1.0f + Hades::CMath::EPSILON_FLOAT * 2.0f, 2.0f);

    EXPECT_FALSE(a == b);
}

TEST(Vector2, NotEqualWithinTolerance)
{
    Hades::CVector2 a(1.0f, 2.0f);
    Hades::CVector2 b(1.0f + Hades::CMath::EPSILON_FLOAT * 0.5f, 2.0f);

    EXPECT_FALSE(a == b);
}

TEST(Vector2, OperatorPlus)
{
    Hades::CVector2 a(1.0f, 2.0f);
    Hades::CVector2 b(5.0f, 8.0f);

    Hades::CVector2 c = a + b;

    EXPECT_FLOAT_EQ(c.x, 6.0f);
    EXPECT_FLOAT_EQ(c.y, 10.0f);
}

TEST(Vector2, OperatorPlusEquals)
{
    Hades::CVector2 a(1.0f, 2.0f);
    Hades::CVector2 b(5.0f, 8.0f);

    a += b;

    EXPECT_FLOAT_EQ(a.x, 6.0f);
    EXPECT_FLOAT_EQ(a.y, 10.0f);
}

TEST(Vector2, OperatorMinus)
{
    Hades::CVector2 a(1.0f, 2.0f);
    Hades::CVector2 b(5.0f, 8.0f);

    Hades::CVector2 c = a - b;

    EXPECT_FLOAT_EQ(c.x, -4.0f);
    EXPECT_FLOAT_EQ(c.y, -6.0f);
}

TEST(Vector2, OperatorMinusEquals)
{
    Hades::CVector2 a(1.0f, 2.0f);
    Hades::CVector2 b(5.0f, 8.0f);

    a -= b;

    EXPECT_FLOAT_EQ(a.x, -4.0f);
    EXPECT_FLOAT_EQ(a.y, -6.0f);
}

TEST(Vector2, OperatorProduct)
{
    Hades::CVector2 a(1.0f, 2.0f);
    const float factor = 3.0f;

    Hades::CVector2 c = a * factor;

    EXPECT_FLOAT_EQ(c.x, 3.0f);
    EXPECT_FLOAT_EQ(c.y, 6.0f);
}

TEST(Vector2, OperatorProductEquals)
{
    Hades::CVector2 a(1.0f, 2.0f);
    const float factor = 3.0f;

    a *= factor;

    EXPECT_FLOAT_EQ(a.x, 3.0f);
    EXPECT_FLOAT_EQ(a.y, 6.0f);
}

TEST(Vector2, OperatorDivision)
{
    Hades::CVector2 a(3.0f, 6.0f);
    const float divider = 3.0f;

    Hades::CVector2 c = a / divider;

    EXPECT_FLOAT_EQ(c.x, 1.0f);
    EXPECT_FLOAT_EQ(c.y, 2.0f);
}

TEST(Vector2, OperatorDivisionZero)
{
    Hades::CVector2 a(3.0f, 6.0f);
    const float divider = 0.f;

    EXPECT_DEATH(a / divider, ".*");
}

TEST(Vector2, LengthSquared)
{
    Hades::CVector2 a(2.0f, 3.0f);

    // 4 + 9 = 13
    const float result = 13.0f;

    EXPECT_FLOAT_EQ(a.LengthSquared(), result);
}

TEST(Vector2, Length)
{
    Hades::CVector2 a(3.0f, 4.0f);

    // 9 + 16 = 25 = 5^2
    const float result = 5.0f;

    EXPECT_FLOAT_EQ(a.Length(), result);
}

TEST(Vector2, ScalarProduct)
{
    Hades::CVector2 a(1.0f, 2.0f);
    Hades::CVector2 b(2.0f, 3.0f);

    // 1*2 + 2*3  = 2 + 6 = 8
    const float result = 8.0f;

    EXPECT_FLOAT_EQ(a.ScalarProduct(b), result);
}

TEST(Vector2, NormalizeRegularVector)
{
    Hades::CVector2 a(3.0f, 4.0f);
    const bool result = a.Normalize();

    EXPECT_TRUE(result);
    EXPECT_FLOAT_EQ(a.Length(), 1.0f);
    EXPECT_FLOAT_EQ(a.x, 0.6f);
    EXPECT_FLOAT_EQ(a.y, 0.8f);
}

TEST(Vector2, NormalizeSmallNumber)
{
    Hades::CVector2 a(1e-30f, 0);
    const bool result = a.Normalize();

    EXPECT_TRUE(result);
    EXPECT_FLOAT_EQ(a.Length(), 1.0f);
    EXPECT_FLOAT_EQ(a.x, 1.0f);
    EXPECT_FLOAT_EQ(a.y, 0.0f);
}

TEST(Vector2, NormalizeNegativeSmallNumber)
{
    Hades::CVector2 a(-1e-30f, 0);
    const bool result = a.Normalize();

    EXPECT_TRUE(result);
    EXPECT_FLOAT_EQ(a.Length(), 1.0f);
    EXPECT_FLOAT_EQ(a.x, -1.0f);
    EXPECT_FLOAT_EQ(a.y, 0.0f);
}

TEST(Vector2, NormalizeSmallDiagonalVector)
{
    Hades::CVector2 a(1e-30f, 1e-30f);
    const bool result = a.Normalize();

    EXPECT_TRUE(result);
    EXPECT_FLOAT_EQ(a.Length(), 1.0f);
    EXPECT_NEAR(a.x, 0.70710678f, 1e-5f);
    EXPECT_NEAR(a.y, 0.70710678f, 1e-5f);
}

TEST(Vector2, NormalizeBigNumber)
{
    Hades::CVector2 a(1e30f, 0);
    const bool result = a.Normalize();

    EXPECT_TRUE(result);
    EXPECT_FLOAT_EQ(a.Length(), 1.0f);
    EXPECT_FLOAT_EQ(a.x, 1.0f);
    EXPECT_FLOAT_EQ(a.y, 0.0f);
}

TEST(Vector2, NormalizeNegativeBigNumber)
{
    Hades::CVector2 a(-1e30f, 0);
    const bool result = a.Normalize();

    EXPECT_TRUE(result);
    EXPECT_FLOAT_EQ(a.Length(), 1.0f);
    EXPECT_FLOAT_EQ(a.x, -1.0f);
    EXPECT_FLOAT_EQ(a.y, 0.0f);
}

TEST(Vector2, NormalizeBigDiagonalVector)
{
    Hades::CVector2 a(1e30f, 1e30f);
    const bool result = a.Normalize();

    EXPECT_TRUE(result);
    EXPECT_FLOAT_EQ(a.Length(), 1.0f);
    EXPECT_NEAR(a.x, 0.70710678f, 1e-5f);
    EXPECT_NEAR(a.y, 0.70710678f, 1e-5f);
}

TEST(Vector2, NormalizeMixedDiagonalVector)
{
    Hades::CVector2 a(-1e30f, 1e30f);
    const bool result = a.Normalize();

    EXPECT_TRUE(result);
    EXPECT_FLOAT_EQ(a.Length(), 1.0f);
    EXPECT_NEAR(a.x, -0.70710678f, 1e-5f);
    EXPECT_NEAR(a.y, 0.70710678f, 1e-5f);
}

TEST(Vector2, NormalizeZeroVector)
{
    Hades::CVector2 a = Hades::CVector2::zero_vector;
    const bool result = a.Normalize();

    EXPECT_FALSE(result);
    EXPECT_FLOAT_EQ(a.x, 0.0f);
    EXPECT_FLOAT_EQ(a.y, 0.0f);
}

TEST(Vector2, NormalizeNaN)
{
    Hades::CVector2 a(3.0f, std::numeric_limits<float>::quiet_NaN());
    const bool result = a.Normalize();

    EXPECT_FALSE(result);
    EXPECT_FLOAT_EQ(a.x, 3.0f);
    EXPECT_TRUE(std::isnan(a.y));
}

TEST(Vector2, NormalizeInfinity)
{
    Hades::CVector2 a(3.0f, std::numeric_limits<float>::infinity());
    const bool result = a.Normalize();

    EXPECT_FALSE(result);
    EXPECT_FLOAT_EQ(a.x, 3.0f);
    EXPECT_FLOAT_EQ(a.y, std::numeric_limits<float>::infinity());
}

TEST(Vector2, IsCollinearToMultiple)
{
    Hades::CVector2 a(3.0f, 15.0f);
    Hades::CVector2 b = a * 3.0f;

    EXPECT_TRUE(a.IsCollinearTo(b));
}

TEST(Vector2, IsCollinearToOppositeDirection)
{
    Hades::CVector2 a(3.0f, 15.0f);
    Hades::CVector2 b = a * -1.0f;

    EXPECT_TRUE(a.IsCollinearTo(b));
}

TEST(Vector2, IsCollinearToZeroVector)
{
    Hades::CVector2 a(3.0f, 15.0f);
    Hades::CVector2 b = Hades::CVector2::zero_vector;

    EXPECT_FALSE(a.IsCollinearTo(b));
}

TEST(Vector2, IsCollinearToOrthogonal)
{
    Hades::CVector2 a(1.0f, 0.0f);
    Hades::CVector2 b(0.0f, 1.0f);

    EXPECT_FALSE(a.IsCollinearTo(b));
}

TEST(Vector2, IsOrthogonalTo)
{
    Hades::CVector2 a(1.0f, 0.0f);
    Hades::CVector2 b(0.0f, 1.0f);

    EXPECT_TRUE(a.IsOrthogonalTo(b));
}

TEST(Vector2, IsOrthogonalToCollinear)
{
    Hades::CVector2 a(3.0f, 15.0f);
    Hades::CVector2 b = a * 3.0f;

    EXPECT_FALSE(a.IsOrthogonalTo(b));
}

TEST(Vector2, ToStringWithWholeNumbers)
{
    Hades::CVector2 a(3.0f, 15.0f);
    EXPECT_EQ(a.ToString(), "(3, 15)");
}

TEST(Vector2, ToStringWithDecimals)
{
    Hades::CVector2 a(3.10f, 15.23f);
    EXPECT_EQ(a.ToString(), "(3.1, 15.23)");
}
