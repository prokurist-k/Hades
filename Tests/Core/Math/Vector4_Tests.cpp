#include "../Engine/Source/Core/Math/Vector4.h"
#include "Source/Core/Math/HadesMath.h"
#include "gtest/gtest.h"
#include <gtest/gtest.h>

TEST(Vector4, ConstructFromXYZW)
{
    const float x = 1.0f;
    const float y = 2.0f;
    const float z = 3.0f;
    const float w = 4.0f;

    Hades::CVector4 a(x, y, z, w);
    EXPECT_FLOAT_EQ(a.x, x);
    EXPECT_FLOAT_EQ(a.y, y);
    EXPECT_FLOAT_EQ(a.z, z);
    EXPECT_FLOAT_EQ(a.w, w);
}

TEST(Vector4, ConstructFromValue)
{
    const float value = 1729.0f;

    Hades::CVector4 a(value);
    EXPECT_FLOAT_EQ(a.x, value);
    EXPECT_FLOAT_EQ(a.y, value);
    EXPECT_FLOAT_EQ(a.z, value);
    EXPECT_FLOAT_EQ(a.w, value);
}

TEST(Vector4, CopyConstruct)
{
    Hades::CVector4 original(1.0f, 2.0f, 3.0f, 4.0f);
    Hades::CVector4 copy(original);

    EXPECT_FLOAT_EQ(copy.x, original.x);
    EXPECT_FLOAT_EQ(copy.y, original.y);
    EXPECT_FLOAT_EQ(copy.z, original.z);
    EXPECT_FLOAT_EQ(copy.w, original.w);
}

TEST(Vector4, Equal)
{
    const float x = 54.0f;
    const float y = 83.5f;
    const float z = 27.3f;
    const float w = 98.32f;

    Hades::CVector4 a(x, y, z, w);
    Hades::CVector4 b(x, y, z, w);

    EXPECT_TRUE(a == b);
}

TEST(Vector4, NotEqualBeyondTolerance)
{
    Hades::CVector4 a(1.0f, 2.0f, 3.0f, 4.0f);
    Hades::CVector4 b(1.1f, 2.0f, 3.0f, 4.0f);

    EXPECT_FALSE(a == b);
}

TEST(Vector4, NotEqualJustBeyondTolerance)
{
    Hades::CVector4 a(1.0f, 2.0f, 3.0f, 4.0f);
    Hades::CVector4 b(1.0f + Hades::CMath::EPSILON_FLOAT * 2.0f, 2.0f, 3.0f, 4.0f);

    EXPECT_FALSE(a == b);
}

TEST(Vector4, NotEqualWithinTolerance)
{
    Hades::CVector4 a(1.0f, 2.0f, 3.0f, 4.0f);
    Hades::CVector4 b(
        1.0f + Hades::CMath::EPSILON_FLOAT * 0.5f,
        2.0f,
        3.0f,
        4.0f);

    EXPECT_FALSE(a == b);
}

TEST(Vector4, OperatorPlus)
{
    Hades::CVector4 a(1.0f, 2.0f, 3.0f, 4.0f);
    Hades::CVector4 b(5.0f, 8.0f, 13.0f, 1.0f);

    Hades::CVector4 c = a + b;

    EXPECT_FLOAT_EQ(c.x, 6.0f);
    EXPECT_FLOAT_EQ(c.y, 10.0f);
    EXPECT_FLOAT_EQ(c.z, 16.0f);
    EXPECT_FLOAT_EQ(c.w, 5.0f);
}

TEST(Vector4, OperatorPlusEquals)
{
    Hades::CVector4 a(1.0f, 2.0f, 3.0f, 4.0f);
    Hades::CVector4 b(5.0f, 8.0f, 13.0f, 1.0f);

    a += b;

    EXPECT_FLOAT_EQ(a.x, 6.0f);
    EXPECT_FLOAT_EQ(a.y, 10.0f);
    EXPECT_FLOAT_EQ(a.z, 16.0f);
    EXPECT_FLOAT_EQ(a.w, 5.0f);
}

TEST(Vector4, OperatorMinus)
{
    Hades::CVector4 a(1.0f, 2.0f, 3.0f, 4.0f);
    Hades::CVector4 b(5.0f, 8.0f, 13.0f, 1.0f);

    Hades::CVector4 c = a - b;

    EXPECT_FLOAT_EQ(c.x, -4.0f);
    EXPECT_FLOAT_EQ(c.y, -6.0f);
    EXPECT_FLOAT_EQ(c.z, -10.0f);
    EXPECT_FLOAT_EQ(c.w, 3.0f);
}

TEST(Vector4, OperatorMinusEquals)
{
    Hades::CVector4 a(1.0f, 2.0f, 3.0f, 4.0f);
    Hades::CVector4 b(5.0f, 8.0f, 13.0f, 1.0f);

    a -= b;

    EXPECT_FLOAT_EQ(a.x, -4.0f);
    EXPECT_FLOAT_EQ(a.y, -6.0f);
    EXPECT_FLOAT_EQ(a.z, -10.0f);
    EXPECT_FLOAT_EQ(a.w, 3.0f);
}

TEST(Vector4, OperatorProduct)
{
    Hades::CVector4 a(1.0f, 2.0f, 3.0f, 4.0f);
    const float factor = 3.0f;

    Hades::CVector4 c = a * factor;

    EXPECT_FLOAT_EQ(c.x, 3.0f);
    EXPECT_FLOAT_EQ(c.y, 6.0f);
    EXPECT_FLOAT_EQ(c.z, 9.0f);
    EXPECT_FLOAT_EQ(c.w, 12.0f);
}

TEST(Vector4, OperatorProductEquals)
{
    Hades::CVector4 a(1.0f, 2.0f, 3.0f, 4.0f);
    const float factor = 3.0f;

    a *= factor;

    EXPECT_FLOAT_EQ(a.x, 3.0f);
    EXPECT_FLOAT_EQ(a.y, 6.0f);
    EXPECT_FLOAT_EQ(a.z, 9.0f);
    EXPECT_FLOAT_EQ(a.w, 12.0f);
}

TEST(Vector4, OperatorDivision)
{
    Hades::CVector4 a(3.0f, 6.0f, 9.0f, 12.0f);
    const float divider = 3.0f;

    Hades::CVector4 c = a / divider;

    EXPECT_FLOAT_EQ(c.x, 1.0f);
    EXPECT_FLOAT_EQ(c.y, 2.0f);
    EXPECT_FLOAT_EQ(c.z, 3.0f);
    EXPECT_FLOAT_EQ(c.w, 4.0f);
}

TEST(Vector4, OperatorDivisionZero)
{
    Hades::CVector4 a(3.0f, 6.0f, 9.0f, 12.0f);
    const float divider = 0.f;

    EXPECT_DEATH(a / divider, ".*");
}

TEST(Vector4, LengthSquared)
{
    Hades::CVector4 a(2.0f, 3.0f, 4.0f, 5.0f);

    // 4 + 9 + 16 + 25 = 29
    const float result = 54.0f;

    EXPECT_FLOAT_EQ(a.LengthSquared(), result);
}

TEST(Vector4, Length)
{
    Hades::CVector4 a(2.0f, 4.0f, 5.0f, 2.0f);

    // 4 + 16 + 25 + 4 = 49 = 7^2
    const float result = 7.0f;

    EXPECT_FLOAT_EQ(a.Length(), result);
}

TEST(Vector4, ScalarProduct)
{
    Hades::CVector4 a(1.0f, 2.0f, 3.0f, 4.0f);
    Hades::CVector4 b(2.0f, 3.0f, 4.0f, 5.0f);

    // 1*2 + 2*3 + 3*4 + 4*5= 2 + 6 + 12 + 20 = 40
    const float result = 40.0f;

    EXPECT_FLOAT_EQ(a.ScalarProduct(b), result);
}

TEST(Vector4, NormalizeRegularVector)
{
    Hades::CVector4 a(3.0f, 4.0f, 0.0f, 1.0f);
    const bool result = a.Normalize();

    const float len = std::sqrt(26.0f);

    EXPECT_TRUE(result);
    EXPECT_FLOAT_EQ(a.Length(), 1.0f);
    EXPECT_FLOAT_EQ(a.x, 3.0f / len);
    EXPECT_FLOAT_EQ(a.y, 4.0f / len);
    EXPECT_FLOAT_EQ(a.z, 0.0f);
    EXPECT_FLOAT_EQ(a.w, 1.0f / len);
}

TEST(Vector4, NormalizeSmallNumber)
{
    Hades::CVector4 a(1e-30f, 0.0f, 0.0f, 0.0f);
    const bool result = a.Normalize();

    EXPECT_TRUE(result);
    EXPECT_FLOAT_EQ(a.Length(), 1.0f);
    EXPECT_FLOAT_EQ(a.x, 1.0f);
    EXPECT_FLOAT_EQ(a.y, 0.0f);
    EXPECT_FLOAT_EQ(a.z, 0.0f);
    EXPECT_FLOAT_EQ(a.w, 0.0f);
}

TEST(Vector4, NormalizeNegativeSmallNumber)
{
    Hades::CVector4 a(-1e-30f, 0.0f, 0.0f, 0.0f);
    const bool result = a.Normalize();

    EXPECT_TRUE(result);
    EXPECT_FLOAT_EQ(a.Length(), 1.0f);
    EXPECT_FLOAT_EQ(a.x, -1.0f);
    EXPECT_FLOAT_EQ(a.y, 0.0f);
    EXPECT_FLOAT_EQ(a.z, 0.0f);
    EXPECT_FLOAT_EQ(a.w, 0.0f);
}

TEST(Vector4, NormalizeSmallDiagonalVector)
{
    Hades::CVector4 a(1e-30f, 1e-30f, 0.0f, 0.0f);
    const bool result = a.Normalize();

    EXPECT_TRUE(result);
    EXPECT_FLOAT_EQ(a.Length(), 1.0f);
    EXPECT_NEAR(a.x, 0.70710678f, 1e-5f);
    EXPECT_NEAR(a.y, 0.70710678f, 1e-5f);
    EXPECT_NEAR(a.z, 0.0f, 1e-6f);
    EXPECT_NEAR(a.w, 0.0f, 1e-6f);
}

TEST(Vector4, NormalizeBigNumber)
{
    Hades::CVector4 a(1e30f, 0.0f, 0.0f, 0.0f);
    const bool result = a.Normalize();

    EXPECT_TRUE(result);
    EXPECT_FLOAT_EQ(a.Length(), 1.0f);
    EXPECT_FLOAT_EQ(a.x, 1.0f);
    EXPECT_FLOAT_EQ(a.y, 0.0f);
    EXPECT_FLOAT_EQ(a.z, 0.0f);
    EXPECT_FLOAT_EQ(a.w, 0.0f);
}

TEST(Vector4, NormalizeNegativeBigNumber)
{
    Hades::CVector4 a(-1e30f, 0.0f, 0.0f, 0.0f);
    const bool result = a.Normalize();

    EXPECT_TRUE(result);
    EXPECT_FLOAT_EQ(a.Length(), 1.0f);
    EXPECT_FLOAT_EQ(a.x, -1.0f);
    EXPECT_FLOAT_EQ(a.y, 0.0f);
    EXPECT_FLOAT_EQ(a.z, 0.0f);
    EXPECT_FLOAT_EQ(a.w, 0.0f);
}

TEST(Vector4, NormalizeBigDiagonalVector)
{
    Hades::CVector4 a(1e30f, 1e30f, 0.0f, 0.0f);
    const bool result = a.Normalize();

    EXPECT_TRUE(result);
    EXPECT_FLOAT_EQ(a.Length(), 1.0f);
    EXPECT_NEAR(a.x, 0.70710678f, 1e-5f);
    EXPECT_NEAR(a.y, 0.70710678f, 1e-5f);
    EXPECT_NEAR(a.z, 0.0f, 1e-6f);
    EXPECT_NEAR(a.w, 0.0f, 1e-6f);
}

TEST(Vector4, NormalizeMixedDiagonalVector)
{
    Hades::CVector4 a(-1e30f, 1e30f, 0.0f, 0.0f);
    const bool result = a.Normalize();

    EXPECT_TRUE(result);
    EXPECT_FLOAT_EQ(a.Length(), 1.0f);
    EXPECT_NEAR(a.x, -0.70710678f, 1e-5f);
    EXPECT_NEAR(a.y, 0.70710678f, 1e-5f);
    EXPECT_NEAR(a.z, 0.0f, 1e-6f);
    EXPECT_NEAR(a.w, 0.0f, 1e-6f);
}

TEST(Vector4, NormalizeZeroVector)
{
    Hades::CVector4 a = Hades::CVector4::zero_vector;
    const bool result = a.Normalize();

    EXPECT_FALSE(result);
    EXPECT_FLOAT_EQ(a.x, 0.0f);
    EXPECT_FLOAT_EQ(a.y, 0.0f);
    EXPECT_FLOAT_EQ(a.z, 0.0f);
    EXPECT_FLOAT_EQ(a.w, 0.0f);
}

TEST(Vector4, NormalizeNaN)
{
    Hades::CVector4 a(3.0f, 4.0f, std::numeric_limits<float>::quiet_NaN(), 1.0f);
    const bool result = a.Normalize();

    EXPECT_FALSE(result);
    EXPECT_FLOAT_EQ(a.x, 3.0f);
    EXPECT_FLOAT_EQ(a.y, 4.0f);
    EXPECT_TRUE(std::isnan(a.z));
    EXPECT_FLOAT_EQ(a.w, 1.0f);
}

TEST(Vector4, NormalizeInfinity)
{
    Hades::CVector4 a(3.0f, 4.0f, std::numeric_limits<float>::infinity(), 1.0f);
    const bool result = a.Normalize();

    EXPECT_FALSE(result);
    EXPECT_FLOAT_EQ(a.x, 3.0f);
    EXPECT_FLOAT_EQ(a.y, 4.0f);
    EXPECT_FLOAT_EQ(a.z, std::numeric_limits<float>::infinity());
    EXPECT_FLOAT_EQ(a.w, 1.0f);
}

TEST(Vector4, IsCollinearToMultiple)
{
    Hades::CVector4 a(3.0f, 15.0f, 24.0f, 1.0f);
    Hades::CVector4 b = a * 3.0f;

    EXPECT_TRUE(a.IsCollinearTo(b));
}

TEST(Vector4, IsCollinearToOppositeDirection)
{
    Hades::CVector4 a(3.0f, 15.0f, 24.0f, 1.0f);
    Hades::CVector4 b = a * -1.0f;

    EXPECT_TRUE(a.IsCollinearTo(b));
}

TEST(Vector4, IsCollinearToZeroVector)
{
    Hades::CVector4 a(3.0f, 15.0f, 24.0f, 1.0f);
    Hades::CVector4 b = Hades::CVector4::zero_vector;

    EXPECT_FALSE(a.IsCollinearTo(b));
}

TEST(Vector4, IsCollinearToOrthogonal)
{
    Hades::CVector4 a(1.0f, 0.0f, 0.0f, 1.0f);
    Hades::CVector4 b(0.0f, 1.0f, 0.0f, 24.0f);

    EXPECT_FALSE(a.IsCollinearTo(b));
}

TEST(Vector4, IsOrthogonalTo)
{
    Hades::CVector4 a(1.0f, 0.0f, 0.0f, 0.0f);
    Hades::CVector4 b(0.0f, 1.0f, 0.0f, 0.0f);

    EXPECT_TRUE(a.IsOrthogonalTo(b));
}

TEST(Vector4, IsOrthogonalToCollinear)
{
    Hades::CVector4 a(3.0f, 15.0f, 24.0f, 1.0f);
    Hades::CVector4 b = a * 3.0f;

    EXPECT_FALSE(a.IsOrthogonalTo(b));
}

TEST(Vector4, ToStringWithWholeNumbers)
{
    Hades::CVector4 a(3.0f, 15.0f, 24.0f, 10.0f);
    EXPECT_EQ(a.ToString(), "(3, 15, 24, 10)");
}

TEST(Vector4, ToStringWithDecimals)
{
    Hades::CVector4 a(3.10f, 15.2f, 24.14f, 2.2f);
    EXPECT_EQ(a.ToString(), "(3.1, 15.2, 24.14, 2.2)");
}
