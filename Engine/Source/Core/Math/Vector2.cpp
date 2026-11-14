#include "../../Core.h"
#include "Source/Core/Math/HadesMath.h"
#include "Vector2.h"
#include <algorithm>
#include <cstdlib>
#include <format>

namespace Hades
{
/*static*/ const CVector2 CVector2::zero_vector = CVector2(0.0f, 0.0f);

/*static*/ bool CVector2::IsNearlyEqual(const CVector2& a, const CVector2& b, const float tolerance /*= CMath::EPSILON_FLOAT*/)
{
    return std::abs(a.x - b.x) <= tolerance && std::abs(a.y - b.y) <= tolerance && std::abs(a.z - b.z) <= tolerance;
}

/*static*/ bool CVector2::IsNearlyZero(const CVector2& a, const float tolerance /*= CMath::EPSILON_FLOAT*/)
{
    return IsNearlyEqual(a, CVector2::zero_vector, tolerance);
}

/*static*/ float CVector2::DistanceSquared(const CVector2& vec1, const CVector2& vec2)
{
    const float dx = vec2.x - vec1.x;
    const float dy = vec2.y - vec1.y;
    const float dz = vec2.z - vec1.z;
    return dx * dx + dy * dy + dz * dz;
}

/*static*/ float CVector2::Distance(const CVector2& vec1, const CVector2& vec2)
{
    return CMath::Sqrt(DistanceSquared(vec1, vec2));
}

CVector2::CVector2()
    : x(0.0f)
    , y(0.0f)
{
}

CVector2::CVector2(float in_x, float in_y)
    : x(in_x)
    , y(in_y)
{
}

CVector2::CVector2(float in_value)
    : x(in_value)
    , y(in_value)
{
}

CVector2 CVector2::operator+(const CVector2& vec) const
{
    return CVector2(x + vec.x, y + vec.y);
}

CVector2 CVector2::operator-(const CVector2& vec) const
{
    return CVector2(x - vec.x, y - vec.y);
}

CVector2 CVector2::operator*(const float scale) const
{
    return CVector2(x * scale, y * scale);
}

CVector2 CVector2::operator/(const float divider) const
{
    HADES_ASSERT(divider != 0, "division by 0")
    const float inverse = 1.0f / divider;
    return CVector2(x * inverse, y * inverse);
}

CVector2 CVector2::operator+(const float addend) const
{
    return CVector2(x + addend, y + addend);
}

CVector2 CVector2::operator-(const float subtrahend) const
{
    return CVector2(x - subtrahend, y - subtrahend);
}

bool CVector2::operator==(const CVector2& vec) const
{
    return x == vec.x && y == vec.y;
}

bool CVector2::operator!=(const CVector2& vec) const
{
    return !(*this == vec);
}

CVector2 CVector2::operator-() const
{
    return CVector2(-x, -y);
}

CVector2& CVector2::operator+=(const CVector2& vec)
{
    x += vec.x;
    y += vec.y;
    return *this;
}

CVector2& CVector2::operator-=(const CVector2& vec)
{
    x -= vec.x;
    y -= vec.y;
    return *this;
}

CVector2& CVector2::operator*=(const float factor)
{
    x *= factor;
    y *= factor;
    return *this;
}

CVector2& CVector2::operator/=(const float divider)
{
    HADES_ASSERT(divider != 0, "division by 0")
    const float inverse = 1.0f / divider;
    x *= inverse;
    y *= inverse;

    return *this;
}

float CVector2::LengthSquared() const
{
    return x * x + y * y;
}

float CVector2::Length() const
{
    return static_cast<float>(std::hypot(x, y));
}

float CVector2::ScalarProduct(const CVector2& vec) const
{
    return x * vec.x + y * vec.y;
}

bool CVector2::Normalize()
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

    CVector2 v = *this / max_abs_component;
    const float length = v.Length();
    CVector2 normalized = v / length;
    *this = normalized;
    return true;
}

bool CVector2::IsNormalized() const
{
    return (std::abs(1.f - LengthSquared()) < CMath::NORMALIZED_TOLERANCE);
}

bool CVector2::IsCollinearTo(const CVector2& vec) const
{
    if (IsNearlyZero(vec) || IsNearlyZero(*this))
    {
        return false;
    }

    return std::abs(x * vec.y - y * vec.x) < CMath::EPSILON_FLOAT;
}

bool CVector2::IsOrthogonalTo(const CVector2& vec) const
{
    const float scalar_product = ScalarProduct(vec);
    return CMath::IsNearlyZero(scalar_product);
}

std::string CVector2::ToString() const
{
    return std::format("({}, {})", x, y);
}

CVector2 CVector2::Reflect(const CVector2& normal) const
{
    if (!normal.IsNormalized())
    {
        HADES_LOG(Warning, "Reflect called with a non-normalized normal vector.")
    }

    const float d = 2 * ScalarProduct(normal);
    return *this - (normal * d);
}

CVector2 CVector2::Project(const CVector2& target) const
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
