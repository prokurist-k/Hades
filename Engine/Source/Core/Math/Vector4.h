#pragma once

#include "HadesMath.h"
#include <string>

namespace Hades
{
class CVector4
{
public:
    float x;
    float y;
    float z;
    float w;

    static const CVector4 zero_vector;

    static bool IsNearlyEqual(const CVector4& a, const CVector4& b, const float tolerance = CMath::EPSILON_FLOAT);
    static bool IsNearlyZero(const CVector4& a, const float tolerance = CMath::EPSILON_FLOAT);

    static float DistanceSquared(const CVector4& vec1, const CVector4& vec2);
    static float Distance(const CVector4& vec1, const CVector4& vec2);

    CVector4();
    CVector4(float in_x, float in_y, float in_z, float in_w);
    CVector4(float in_value);

    std::string ToString() const;

    CVector4 operator+(const CVector4& vec) const;
    CVector4 operator-(const CVector4& vec) const;
    CVector4 operator*(const float scale) const;
    CVector4 operator/(const float divider) const;
    CVector4 operator+(const float addend) const;
    CVector4 operator-(const float subtrahend) const;

    bool operator==(const CVector4& vec) const;
    bool operator!=(const CVector4& vec) const;

    CVector4 operator-() const;

    CVector4& operator+=(const CVector4& vec);
    CVector4& operator-=(const CVector4& vec);
    CVector4& operator*=(const float factor);
    CVector4& operator/=(const float divider);

    float LengthSquared() const;
    float Length() const;

    float ScalarProduct(const CVector4& vec) const;

    bool Normalize();
    bool IsNormalized() const;

    bool IsCollinearTo(const CVector4& vec) const;
    bool IsOrthogonalTo(const CVector4& vec) const;

    CVector4 Reflect(const CVector4& normal) const;
    CVector4 Project(const CVector4& target) const;
};
}
