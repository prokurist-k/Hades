#pragma once

#include "HadesMath.h"
#include <string>

namespace Hades
{
class CVector3
{
public:
    union
    {
        struct
        {
            float x;
            float y;
            float z;
        };

        float xyz[3];
    };

    static const CVector3 zero_vector;

    static bool IsNearlyEqual(const CVector3& a, const CVector3& b, const float tolerance = CMath::EPSILON_FLOAT);
    static bool IsNearlyZero(const CVector3& a, const float tolerance = CMath::EPSILON_FLOAT);

    static float DistanceSquared(const CVector3& vec1, const CVector3& vec2);
    static float Distance(const CVector3& vec1, const CVector3& vec2);

    CVector3() = default;
    CVector3(float in_x, float in_y, float in_z);
    CVector3(float in_value);

    std::string ToString() const;

    CVector3 operator+(const CVector3& vec) const;
    CVector3 operator-(const CVector3& vec) const;
    CVector3 operator*(const float scale) const;
    CVector3 operator/(const float divider) const;
    CVector3 operator+(const float addend) const;
    CVector3 operator-(const float subtrahend) const;

    bool operator==(const CVector3& vec) const;
    bool operator!=(const CVector3& vec) const;

    CVector3 operator-() const;

    CVector3& operator+=(const CVector3& vec);
    CVector3& operator-=(const CVector3& vec);
    CVector3& operator*=(const float factor);
    CVector3& operator/=(const float divider);

    float LengthSquared() const;
    float Length() const;

    float ScalarProduct(const CVector3& vec) const;
    CVector3 CrossProduct(const CVector3& other) const;

    bool Normalize();

    bool IsCollinearTo(const CVector3& vec) const;
    bool IsOrthogonalTo(const CVector3& vec) const;
};
}
