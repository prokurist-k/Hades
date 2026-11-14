#include "../../Core.h"
#include "Source/Core/Math/HadesMath.h"
#include "Vector4.h"
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <format>

namespace Hades
{
/*static*/ const CVector4 CVector4::zero_vector = CVector4(0.0f, 0.0f, 0.0f, 0.0f);

/*static*/ bool CVector4::IsNearlyEqual(const CVector4& a, const CVector4& b, const float tolerance /*= CMath::EPSILON_FLOAT*/)
{
    return std::abs(a.x - b.x) <= tolerance && std::abs(a.y - b.y) <= tolerance && std::abs(a.z - b.z) <= tolerance;
}

/*static*/ bool CVector4::IsNearlyZero(const CVector4& a, const float tolerance /*= CMath::EPSILON_FLOAT*/)
{
    return IsNearlyEqual(a, CVector4::zero_vector, tolerance);
}

/*static*/ float CVector4::DistanceSquared(const CVector4& vec1, const CVector4& vec2)
{
    const float dx = vec2.x - vec1.x;
    const float dy = vec2.y - vec1.y;
    const float dz = vec2.z - vec1.z;
    const float dw = vec2.w - vec1.w;
    return dx * dx + dy * dy + dz * dz + dw * dw;
}

/*static*/ float CVector4::Distance(const CVector4& vec1, const CVector4& vec2)
{
    return CMath::Sqrt(DistanceSquared(vec1, vec2));
}

CVector4::CVector4()
    : x(0.0f)
    , y(0.0f)
    , z(0.0f)
    , w(0.0f)
{
}

CVector4::CVector4(float in_x, float in_y, float in_z, float in_w)
    : x(in_x)
    , y(in_y)
    , z(in_z)
    , w(in_w)
{
}

CVector4::CVector4(float in_value)
    : x(in_value)
    , y(in_value)
    , z(in_value)
    , w(in_value)
{
}

CVector4 CVector4::operator+(const CVector4& vec) const
{
    return CVector4(x + vec.x, y + vec.y, z + vec.z, w + vec.w);
}

CVector4 CVector4::operator-(const CVector4& vec) const
{
    return CVector4(x - vec.x, y - vec.y, z - vec.z, w - vec.w);
}

CVector4 CVector4::operator*(const float scale) const
{
    return CVector4(x * scale, y * scale, z * scale, w * scale);
}

CVector4 CVector4::operator/(const float divider) const
{
    HADES_ASSERT(divider != 0, "division by 0")
    const float inverse = 1.0f / divider;
    return CVector4(x * inverse, y * inverse, z * inverse, w * inverse);
}

CVector4 CVector4::operator+(const float addend) const
{
    return CVector4(x + addend, y + addend, z + addend, w + addend);
}

CVector4 CVector4::operator-(const float subtrahend) const
{
    return CVector4(x - subtrahend, y - subtrahend, z - subtrahend, w - subtrahend);
}

bool CVector4::operator==(const CVector4& vec) const
{
    return x == vec.x && y == vec.y && z == vec.z && w == vec.w;
}

bool CVector4::operator!=(const CVector4& vec) const
{
    return !(*this == vec);
}

CVector4 CVector4::operator-() const
{
    return CVector4(-x, -y, -z, -w);
}

CVector4& CVector4::operator+=(const CVector4& vec)
{
    x += vec.x;
    y += vec.y;
    z += vec.z;
    w += vec.w;
    return *this;
}

CVector4& CVector4::operator-=(const CVector4& vec)
{
    x -= vec.x;
    y -= vec.y;
    z -= vec.z;
    w -= vec.w;
    return *this;
}

CVector4& CVector4::operator*=(const float factor)
{
    x *= factor;
    y *= factor;
    z *= factor;
    w *= factor;
    return *this;
}

CVector4& CVector4::operator/=(const float divider)
{
    HADES_ASSERT(divider != 0, "division by 0")
    const float inverse = 1.0f / divider;
    x *= inverse;
    y *= inverse;
    z *= inverse;
    w *= inverse;

    return *this;
}

float CVector4::LengthSquared() const
{
    return x * x + y * y + z * z + w * w;
}

float CVector4::Length() const
{
    return static_cast<float>(std::hypot(std::hypot(x, y, z), w));
}

float CVector4::ScalarProduct(const CVector4& vec) const
{
    return x * vec.x + y * vec.y + z * vec.z + w * vec.w;
}

bool CVector4::Normalize()
{
    if (!std::isfinite(x) || !std::isfinite(y) || !std::isfinite(z))
    {
        HADES_LOG(Warning, "Cannot normalize vector: component is NaN or infinite.")
        return false;
    }

    const float max_abs_component = std::max(std::max(std::abs(x), std::abs(y)), std::abs(z));
    if (max_abs_component == 0.0f)
    {
        HADES_LOG(Warning, "Cannot normalize zero vector.")
        return false;
    }

    CVector4 v = *this / max_abs_component;
    const float length = v.Length();
    CVector4 normalized = v / length;
    *this = normalized;
    return true;
}

bool CVector4::IsNormalized() const
{
    return (std::abs(1.f - LengthSquared()) < CMath::NORMALIZED_TOLERANCE);
}

bool CVector4::IsCollinearTo(const CVector4& vec) const
{
    if (IsNearlyZero(vec) || IsNearlyZero(*this))
    {
        return false;
    }

    const float d1 = x * vec.y - y * vec.x;
    const float d2 = x * vec.z - z * vec.x;
    const float d3 = x * vec.w - w * vec.x;
    const float d4 = y * vec.z - z * vec.y;
    const float d5 = y * vec.w - w * vec.y;
    const float d6 = z * vec.w - w * vec.z;

    return CMath::IsNearlyZero(d1) && CMath::IsNearlyZero(d2) && CMath::IsNearlyZero(d3) && CMath::IsNearlyZero(d4) && CMath::IsNearlyZero(d5) && CMath::IsNearlyZero(d6);
}

bool CVector4::IsOrthogonalTo(const CVector4& vec) const
{
    const float scalar_product = ScalarProduct(vec);
    return CMath::IsNearlyZero(scalar_product);
}

std::string CVector4::ToString() const
{
    return std::format("({}, {}, {}, {})", x, y, z, w);
}

CVector4 CVector4::Reflect(const CVector4& normal) const
{
    if (!normal.IsNormalized())
    {
        HADES_LOG(Warning, "Reflect called with a non-normalized normal vector.")
    }

    const float d = 2 * ScalarProduct(normal);
    return *this - (normal * d);
}

CVector4 CVector4::Project(const CVector4& target) const
{
    if (IsNearlyZero(target))
    {
        HADES_LOG(Warning, "Project called with a zero target vector.")
        return zero_vector;
    }

    const float d = ScalarProduct(target);
    const float q = d / target.LengthSquared();
    return target * q;
}

}
