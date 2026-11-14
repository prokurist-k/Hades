#pragma once

#include "Vector2.h"
#include "Vector3.h"
#include <optional>

namespace Hades
{
class CMatrix3x3
{
public:
    static CMatrix3x3 CreateIdentity();
    static CMatrix3x3 CreateTranslation(const CVector2& translation);
    static CMatrix3x3 CreateRotation(float angle);
    static CMatrix3x3 CreateScale(const CVector2& scale);

    CMatrix3x3();
    CMatrix3x3(const CVector2& x, const CVector2& y, const CVector2& w);

    float elements[3][3];

    std::string ToString() const;

    bool operator==(const CMatrix3x3& matrix) const;
    bool operator!=(const CMatrix3x3& matrix) const;

    CMatrix3x3 operator+(const CMatrix3x3& matrix) const;
    CMatrix3x3 operator-(const CMatrix3x3& matrix) const;
    CMatrix3x3 operator*(const CMatrix3x3& matrix) const;

    CVector3 operator*(const CVector3& vec) const;

    float Determinant() const;
    CMatrix3x3 Transpose() const;
    std::optional<CMatrix3x3> Inverse() const;
    float Trace() const;
    bool IsIdentity() const;
};
}
