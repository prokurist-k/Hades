#pragma once

#include "HadesMath.h"
#include <string>

namespace Hades
{

class CVector2
{
public:
    float x;
    float y;
    float z;

    static const CVector2 zero_vector;

    static bool IsNearlyEqual(const CVector2& a, const CVector2& b, const float tolerance = CMath::EPSILON_FLOAT);
    static bool IsNearlyZero(const CVector2& a, const float tolerance = CMath::EPSILON_FLOAT);

    static float DistanceSquared(const CVector2& vec1, const CVector2& vec2);
    static float Distance(const CVector2& vec1, const CVector2& vec2);

    CVector2();
    CVector2(float in_x, float in_y);
    CVector2(float in_value);

    std::string ToString() const;

    CVector2 operator+(const CVector2& vec) const;
    CVector2 operator-(const CVector2& vec) const;
    CVector2 operator*(const float scale) const;
    CVector2 operator/(const float divider) const;
    CVector2 operator+(const float addend) const;
    CVector2 operator-(const float subtrahend) const;

    bool operator==(const CVector2& vec) const;
    bool operator!=(const CVector2& vec) const;

    CVector2 operator-() const;

    CVector2& operator+=(const CVector2& vec);
    CVector2& operator-=(const CVector2& vec);
    CVector2& operator*=(const float factor);
    CVector2& operator/=(const float divider);

    float LengthSquared() const;
    float Length() const;

    float ScalarProduct(const CVector2& vec) const;

    bool Normalize();
    bool IsNormalized() const;

    bool IsCollinearTo(const CVector2& vec) const;
    bool IsOrthogonalTo(const CVector2& vec) const;

    CVector2 Reflect(const CVector2& normal) const;
    CVector2 Project(const CVector2& target) const;
};
}
