#include "../Engine/Source/Core/Math/Vector3.h"
#include "Source/Core/Math/HadesMath.h"
#include "gtest/gtest.h"
#include <gtest/gtest.h>

TEST(Vector3, ConstructFromXYZ)
{
    const float x = 1.0f;
    const float y = 2.0f;
    const float z = 3.0f;

    Hades::CVector3 a(x, y, z);
    EXPECT_FLOAT_EQ(a.x, x);
    EXPECT_FLOAT_EQ(a.y, y);
    EXPECT_FLOAT_EQ(a.z, z);
}

TEST(Vector3, ConstructFromValue)
{
    const float value = 1729.0f;

    Hades::CVector3 a(value);
    EXPECT_FLOAT_EQ(a.x, value);
    EXPECT_FLOAT_EQ(a.y, value);
    EXPECT_FLOAT_EQ(a.z, value);
}

TEST(Vector3, CopyConstruct)
{
    Hades::CVector3 original(1.0f, 2.0f, 3.0f);
    Hades::CVector3 copy(original);

    EXPECT_FLOAT_EQ(copy.x, original.x);
    EXPECT_FLOAT_EQ(copy.y, original.y);
    EXPECT_FLOAT_EQ(copy.z, original.z);
}

TEST(Vector3, Equal)
{
    const float x = 54.0f;
    const float y = 83.5f;
    const float z = 27.3f;
    Hades::CVector3 a(x, y, z);
    Hades::CVector3 b(x, y, z);

    EXPECT_TRUE(a == b);
}

TEST(Vector3, NotEqualBeyondTolerance)
{
    Hades::CVector3 a(1.0f, 2.0f, 3.0f);
    Hades::CVector3 b(1.1f, 2.0f, 3.0f);

    EXPECT_FALSE(a == b);
}

TEST(Vector3, NotEqualJustBeyondTolerance)
{
    Hades::CVector3 a(1.0f, 2.0f, 3.0f);
    Hades::CVector3 b(1.0f + Hades::CMath::EPSILON_FLOAT * 2.0f, 2.0f, 3.0f);

    EXPECT_FALSE(a == b);
}

TEST(Vector3, EqualJustWithinTolerance)
{
    Hades::CVector3 a(1.0f, 2.0f, 3.0f);
    Hades::CVector3 b(1.0f + Hades::CMath::EPSILON_FLOAT * 0.5f, 2.0f, 3.0f);

    EXPECT_TRUE(a == b);
}

TEST(Vector3, OperatorPlus)
{
    Hades::CVector3 a(1.0f, 2.0f, 3.0f);
    Hades::CVector3 b(5.0f, 8.0f, 13.0f);

    Hades::CVector3 c = a + b;

    EXPECT_FLOAT_EQ(c.x, 6.0f);
    EXPECT_FLOAT_EQ(c.y, 10.0f);
    EXPECT_FLOAT_EQ(c.z, 16.0f);
}

TEST(Vector3, OperatorPlusEquals)
{
    Hades::CVector3 a(1.0f, 2.0f, 3.0f);
    Hades::CVector3 b(5.0f, 8.0f, 13.0f);

    a += b;

    EXPECT_FLOAT_EQ(a.x, 6.0f);
    EXPECT_FLOAT_EQ(a.y, 10.0f);
    EXPECT_FLOAT_EQ(a.z, 16.0f);
}

TEST(Vector3, OperatorMinus)
{
    Hades::CVector3 a(1.0f, 2.0f, 3.0f);
    Hades::CVector3 b(5.0f, 8.0f, 13.0f);

    Hades::CVector3 c = a - b;

    EXPECT_FLOAT_EQ(c.x, -4.0f);
    EXPECT_FLOAT_EQ(c.y, -6.0f);
    EXPECT_FLOAT_EQ(c.z, -10.0f);
}

TEST(Vector3, OperatorMinusEquals)
{
    Hades::CVector3 a(1.0f, 2.0f, 3.0f);
    Hades::CVector3 b(5.0f, 8.0f, 13.0f);

    a -= b;

    EXPECT_FLOAT_EQ(a.x, -4.0f);
    EXPECT_FLOAT_EQ(a.y, -6.0f);
    EXPECT_FLOAT_EQ(a.z, -10.0f);
}

TEST(Vector3, OperatorProduct)
{
    Hades::CVector3 a(1.0f, 2.0f, 3.0f);
    const float factor = 3.0f;

    Hades::CVector3 c = a * factor;

    EXPECT_FLOAT_EQ(c.x, 3.0f);
    EXPECT_FLOAT_EQ(c.y, 6.0f);
    EXPECT_FLOAT_EQ(c.z, 9.0f);
}

TEST(Vector3, OperatorProductEquals)
{
    Hades::CVector3 a(1.0f, 2.0f, 3.0f);
    const float factor = 3.0f;

    a *= factor;

    EXPECT_FLOAT_EQ(a.x, 3.0f);
    EXPECT_FLOAT_EQ(a.y, 6.0f);
    EXPECT_FLOAT_EQ(a.z, 9.0f);
}

TEST(Vector3, OperatorDivision)
{
    Hades::CVector3 a(3.0f, 6.0f, 9.0f);
    const float divider = 3.0f;

    Hades::CVector3 c = a / divider;

    EXPECT_FLOAT_EQ(c.x, 1.0f);
    EXPECT_FLOAT_EQ(c.y, 2.0f);
    EXPECT_FLOAT_EQ(c.z, 3.0f);
}

TEST(Vector3, OperatorDivisionZero)
{
    Hades::CVector3 a(3.0f, 6.0f, 9.0f);
    const float divider = 0.f;

    EXPECT_DEATH({ Hades::CVector3 c = a / divider; }, ".*");
}

TEST(Vector3, LengthSquared)
{
    Hades::CVector3 a(2.0f, 3.0f, 4.0f);

    // 4 + 9 + 16 = 29
    const float result = 29.0f;

    EXPECT_FLOAT_EQ(a.LengthSquared(), result);
}

TEST(Vector3, Length)
{
    Hades::CVector3 a(3.0f, 4.0f, 0.0f);

    // 9 + 16 + 0 = 25 = 5^2
    const float result = 5.0f;

    EXPECT_FLOAT_EQ(a.Length(), result);
}

TEST(Vector3, ScalarProduct)
{
    Hades::CVector3 a(1.0f, 2.0f, 3.0f);
    Hades::CVector3 b(2.0f, 3.0f, 4.0f);

    // 1*2 + 2*3 + 3*4 = 2 + 6 + 12 = 20
    const float result = 20.0f;

    EXPECT_FLOAT_EQ(a.ScalarProduct(b), result);
}

TEST(Vector3, CrossProduct)
{
    Hades::CVector3 a(1.0f, 2.0f, 3.0f);
    Hades::CVector3 b(3.0f, 4.0f, 5.0f);

    const Hades::CVector3 result(-2.0f, 4.0f, -2.0f);
    const Hades::CVector3 c = a.CrossProduct(b);

    EXPECT_FLOAT_EQ(c.x, result.x);
    EXPECT_FLOAT_EQ(c.y, result.y);
    EXPECT_FLOAT_EQ(c.z, result.z);
}

TEST(Vector3, Normalize)
{
    Hades::CVector3 a(1.0f, 2.0f, 3.0f);
    const bool result = a.Normalize();

    EXPECT_FLOAT_EQ(a.Length(), 1.0f);
    EXPECT_TRUE(result);
}

TEST(Vector3, NormalizeZeroVector)
{
    Hades::CVector3 a = Hades::CVector3::zero_vector;
    const bool result = a.Normalize();

    EXPECT_FALSE(result);
}

TEST(Vector3, IsCollinearToMultiple)
{
    Hades::CVector3 a(3.0f, 15.0f, 24.0f);
    Hades::CVector3 b = a * 3.0f;

    EXPECT_TRUE(a.IsCollinearTo(b));
}

TEST(Vector3, IsCollinearToOppositeDirection)
{
    Hades::CVector3 a(3.0f, 15.0f, 24.0f);
    Hades::CVector3 b = a * -1.0f;

    EXPECT_TRUE(a.IsCollinearTo(b));
}

TEST(Vector3, IsCollinearToZeroVector)
{
    Hades::CVector3 a(3.0f, 15.0f, 24.0f);
    Hades::CVector3 b = Hades::CVector3::zero_vector;

    EXPECT_FALSE(a.IsCollinearTo(b));
}

TEST(Vector3, IsCollinearToOrthogonal)
{
    Hades::CVector3 a(1.0f, 0.0f, 0.0f);
    Hades::CVector3 b(0.0f, 1.0f, 0.0f);

    EXPECT_FALSE(a.IsCollinearTo(b));
}

TEST(Vector3, IsOrthogonalTo)
{
    Hades::CVector3 a(1.0f, 0.0f, 0.0f);
    Hades::CVector3 b(0.0f, 1.0f, 0.0f);

    EXPECT_TRUE(a.IsOrthogonalTo(b));
}

TEST(Vector3, IsOrthogonalToCollinear)
{
    Hades::CVector3 a(3.0f, 15.0f, 24.0f);
    Hades::CVector3 b = a * 3.0f;

    EXPECT_FALSE(a.IsOrthogonalTo(b));
}

TEST(Vector3, ToStringWithWholeNumbers)
{
    Hades::CVector3 a(3.0f, 15.0f, 24.0f);
    EXPECT_EQ(a.ToString(), "(3, 15, 24)");
}

TEST(Vector3, ToStringWithDecimals)
{
    Hades::CVector3 a(3.10f, 15.2f, 24.14f);
    EXPECT_EQ(a.ToString(), "(3.1, 15.2, 24.14)");
}
