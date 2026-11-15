#pragma once

#include "Source/Core/Math/Vector4.h"
#pragma once

#include "Vector3.h"
#include <optional>

namespace Hades
{
class CMatrix4x4
{
public:
    static CMatrix4x4 CreateIdentity();
    static CMatrix4x4 CreateTranslation(const CVector3& translation);
    static CMatrix4x4 CreateRotation(float angle);
    static CMatrix4x4 CreateScale(const CVector3& scale);

    CMatrix4x4();
    CMatrix4x4(const CVector3& column0, const CVector3& column1, const CVector3& column2, const CVector3& w);

    float elements[4][4];

    std::string ToString() const;

    bool operator==(const CMatrix4x4& matrix) const;
    bool operator!=(const CMatrix4x4& matrix) const;

    CMatrix4x4 operator+(const CMatrix4x4& matrix) const;
    CMatrix4x4 operator-(const CMatrix4x4& matrix) const;
    CMatrix4x4 operator*(const CMatrix4x4& matrix) const;

    CVector4 operator*(const CVector4& vec) const;

    float Determinant() const;
    CMatrix4x4 Transpose() const;
    std::optional<CMatrix4x4> Inverse() const;
    float Trace() const;
    bool IsIdentity() const;
};
}
