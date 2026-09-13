#include "../../Core.h"
#include "Vector3.h"
#include <cmath>
#include <format>

namespace Hades
{
/*static*/ const CVector3 CVector3::zero_vector = CVector3(0.0f, 0.0f, 0.0f);

/*static*/ bool CVector3::IsNearlyEqual(const CVector3& a, const CVector3& b, const float tolerance /*= CMath::EPSILON_FLOAT*/)
{
    return std::abs(a.x - b.x) <= tolerance && std::abs(a.y - b.y) <= tolerance && std::abs(a.z - b.z) <= tolerance;
}

/*static*/ bool CVector3::IsNearlyZero(const CVector3& a, const float tolerance /*= CMath::EPSILON_FLOAT*/)
{
    return IsNearlyEqual(a, CVector3::zero_vector, tolerance);
}

/*static*/ float CVector3::DistanceSquared(const CVector3& vec1, const CVector3& vec2)
{
    const float dx = vec2.x - vec1.x;
    const float dy = vec2.y - vec1.y;
    const float dz = vec2.z - vec1.z;
    return dx * dx + dy * dy + dz * dz;
}

/*static*/ float CVector3::Distance(const CVector3& vec1, const CVector3& vec2)
{
    return CMath::Sqrt(DistanceSquared(vec1, vec2));
}

CVector3::CVector3(float in_x, float in_y, float in_z)
    : x(in_x)
    , y(in_y)
    , z(in_z)
{
}

CVector3::CVector3(float in_value)
    : x(in_value)
    , y(in_value)
    , z(in_value)
{
}

CVector3 CVector3::operator+(const CVector3& vec) const
{
    return CVector3(x + vec.x, y + vec.y, z + vec.z);
}

CVector3 CVector3::operator-(const CVector3& vec) const
{
    return CVector3(x - vec.x, y - vec.y, z - vec.z);
}

CVector3 CVector3::operator*(const float scale) const
{
    return CVector3(x * scale, y * scale, z * scale);
}

CVector3 CVector3::operator/(const float divider) const
{
    HADES_ASSERT(divider != 0, "division by 0")
    const float inverse = 1.0f / divider;
    return CVector3(x * inverse, y * inverse, z * inverse);
}

CVector3 CVector3::operator+(const float addend) const
{
    return CVector3(x + addend, y + addend, z + addend);
}

CVector3 CVector3::operator-(const float subtrahend) const
{
    return CVector3(x - subtrahend, y - subtrahend, z - subtrahend);
}

bool CVector3::operator==(const CVector3& vec) const
{
    return (CMath::IsNearlyEqual(x, vec.x) && CMath::IsNearlyEqual(y, vec.y) && CMath::IsNearlyEqual(z, vec.z));
}

bool CVector3::operator!=(const CVector3& vec) const
{
    return !(*this == vec);
}

CVector3 CVector3::operator-() const
{
    return CVector3(-x, -y, -z);
}

CVector3& CVector3::operator+=(const CVector3& vec)
{
    x += vec.x;
    y += vec.y;
    z += vec.z;
    return *this;
}

CVector3& CVector3::operator-=(const CVector3& vec)
{
    x -= vec.x;
    y -= vec.y;
    z -= vec.z;
    return *this;
}

CVector3& CVector3::operator*=(const float factor)
{
    x *= factor;
    y *= factor;
    z *= factor;
    return *this;
}

CVector3& CVector3::operator/=(const float divider)
{
    HADES_ASSERT(divider != 0, "division by 0")
    const float inverse = 1.0f / divider;
    x *= inverse;
    y *= inverse;
    z *= inverse;

    return *this;
}

float CVector3::LengthSquared() const
{
    return x * x + y * y + z * z;
}

float CVector3::Length() const
{
    return CMath::Sqrt(LengthSquared());
}

float CVector3::ScalarProduct(const CVector3& vec) const
{
    return x * vec.x + y * vec.y + z * vec.z;
}

CVector3 CVector3::CrossProduct(const CVector3& other) const
{
    return CVector3(y * other.z - z * other.y, z * other.x - x * other.z, x * other.y - y * other.x);
}

bool CVector3::Normalize()
{
    const float length = Length();
    if (length > 0.f)
    {
        *this /= length;
        return true;
    }
    return false;
}

bool CVector3::IsCollinearTo(const CVector3& vec) const
{
    if (IsNearlyZero(vec) || IsNearlyZero(*this))
    {
        return false;
    }

    return CrossProduct(vec).LengthSquared() < (CMath::EPSILON_FLOAT * CMath::EPSILON_FLOAT);
}

bool CVector3::IsOrthogonalTo(const CVector3& vec) const
{
    const float scalar_product = ScalarProduct(vec);
    return CMath::IsNearlyZero(scalar_product);
}

std::string CVector3::ToString() const
{
    return std::format("({}, {}, {})", x, y, z);
}
}
