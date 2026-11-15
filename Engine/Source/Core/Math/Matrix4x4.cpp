#include "Matrix4x4.h"
#include "Source/Core/Math/Matrix3x3.h"
#include "Source/Core/Math/Vector3.h"
#include <cmath>
#include <format>

namespace Hades
{

/*static*/ CMatrix4x4 CMatrix4x4::CreateIdentity()
{
    CMatrix4x4 result;
    for (int row = 0; row < 4; ++row)
    {
        for (int column = 0; column < 4; ++column)
        {
            result.elements[row][column] = (row == column) ? 1.0f : 0.0f;
        }
    }
    return result;
}

/*static*/ CMatrix4x4 CMatrix4x4::CreateTranslation(const CVector3& translation)
{
    CMatrix4x4 result;
    result.elements[0][2] = translation.x;
    result.elements[1][2] = translation.y;
    result.elements[2][2] = translation.z;
    return result;
}

/*static*/ CMatrix4x4 CMatrix4x4::CreateRotation(float angle)
{
    CMatrix4x4 result;
    const float cos = std::cos(angle);
    const float sin = std::sin(angle);
    result.elements[0][0] = cos;
    result.elements[0][1] = -sin;
    result.elements[1][0] = sin;
    result.elements[1][1] = cos;
    return result;
}

/*static*/ CMatrix4x4 CMatrix4x4::CreateScale(const CVector3& scale)
{
    CMatrix4x4 result;
    result.elements[0][0] = scale.x;
    result.elements[1][1] = scale.y;
    result.elements[2][2] = scale.z;
    return result;
}

CMatrix4x4::CMatrix4x4()
{
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            elements[i][j] = (i == j) ? 1.0f : 0.0f;
        }
    }
}

std::string CMatrix4x4::ToString() const
{
    return std::format("[{:.2f} {:.2f} {:.2f} {:.2f}]\n[{:.2f} {:.2f} {:.2f} {:.2f}]\n[{:.2f} {:.2f} {:.2f} {:.2f}]\n[{:.2f} {:.2f} {:.2f} {:.2f}]",
        elements[0][0], elements[0][1], elements[0][2], elements[0][3],
        elements[1][0], elements[1][1], elements[1][2], elements[1][3],
        elements[2][0], elements[2][1], elements[2][2], elements[2][3],
        elements[3][0], elements[3][1], elements[3][2], elements[3][3]);
}

CMatrix4x4::CMatrix4x4(const CVector3& column0, const CVector3& column1, const CVector3& column2, const CVector3& translation)
{
    elements[0][0] = column0.x;
    elements[0][1] = column1.x;
    elements[0][2] = column2.x;
    elements[0][3] = translation.x;

    elements[1][0] = column0.y;
    elements[1][1] = column1.y;
    elements[1][2] = column2.y;
    elements[1][3] = translation.y;

    elements[2][0] = column0.z;
    elements[2][1] = column1.z;
    elements[2][2] = column2.z;
    elements[2][3] = translation.z;

    elements[3][0] = 0.0f;
    elements[3][1] = 0.0f;
    elements[3][2] = 0.0f;
    elements[3][3] = 1.0f;
}

bool CMatrix4x4::operator==(const CMatrix4x4& matrix) const
{
    for (int row = 0; row != 4; ++row)
    {
        for (int column = 0; column != 4; ++column)
        {
            if (elements[row][column] != matrix.elements[row][column])
            {
                return false;
            }
        }
    }
    return true;
}

bool CMatrix4x4::operator!=(const CMatrix4x4& matrix) const
{
    return !(*this == matrix);
}

CMatrix4x4 CMatrix4x4::operator+(const CMatrix4x4& matrix) const
{
    CMatrix4x4 result;
    for (int row = 0; row != 4; ++row)
    {
        for (int column = 0; column != 4; ++column)
        {
            result.elements[row][column] = elements[row][column] + matrix.elements[row][column];
        }
    }
    return result;
}

CMatrix4x4 CMatrix4x4::operator-(const CMatrix4x4& matrix) const
{
    CMatrix4x4 result;
    for (int row = 0; row != 4; ++row)
    {
        for (int column = 0; column != 4; ++column)
        {
            result.elements[row][column] = elements[row][column] - matrix.elements[row][column];
        }
    }
    return result;
}

CMatrix4x4 CMatrix4x4::operator*(const CMatrix4x4& matrix) const
{
    CMatrix4x4 result;
    for (int row = 0; row != 4; ++row)
    {
        for (int column = 0; column != 4; ++column)
        {
            result.elements[row][column] = 0.0f;

            for (int k = 0; k != 4; ++k)
            {
                result.elements[row][column] += elements[row][k] * matrix.elements[k][column];
            }
        }
    }
    return result;
}

CVector4 CMatrix4x4::operator*(const CVector4& vec) const
{
    return CVector4(
        elements[0][0] * vec.x + elements[0][1] * vec.y + elements[0][2] * vec.z + elements[0][3] * vec.w,
        elements[1][0] * vec.x + elements[1][1] * vec.y + elements[1][2] * vec.z + elements[1][3] * vec.w,
        elements[2][0] * vec.x + elements[2][1] * vec.y + elements[2][2] * vec.z + elements[2][3] * vec.w,
        elements[3][0] * vec.x + elements[3][1] * vec.y + elements[3][2] * vec.z + elements[3][3] * vec.w);
}

float CMatrix4x4::Determinant() const
{
    const auto& m = elements;

    const float s0 = m[0][0] * m[1][1] - m[1][0] * m[0][1];
    const float s1 = m[0][0] * m[1][2] - m[1][0] * m[0][2];
    const float s2 = m[0][0] * m[1][3] - m[1][0] * m[0][3];
    const float s3 = m[0][1] * m[1][2] - m[1][1] * m[0][2];
    const float s4 = m[0][1] * m[1][3] - m[1][1] * m[0][3];
    const float s5 = m[0][2] * m[1][3] - m[1][2] * m[0][3];

    const float c5 = m[2][2] * m[3][3] - m[3][2] * m[2][3];
    const float c4 = m[2][1] * m[3][3] - m[3][1] * m[2][3];
    const float c3 = m[2][1] * m[3][2] - m[3][1] * m[2][2];
    const float c2 = m[2][0] * m[3][3] - m[3][0] * m[2][3];
    const float c1 = m[2][0] * m[3][2] - m[3][0] * m[2][2];
    const float c0 = m[2][0] * m[3][1] - m[3][0] * m[2][1];

    return s0 * c5 - s1 * c4 + s2 * c3 + s3 * c2 - s4 * c1 + s5 * c0;
}

CMatrix4x4 CMatrix4x4::Transpose() const
{
    CMatrix4x4 result = *this;
    for (int row = 0; row != 3; ++row)
    {
        for (int column = 0; column != 3; ++column)
        {
            result.elements[row][column] = elements[column][row];
        }
    }
    return result;
}

std::optional<CMatrix4x4> CMatrix4x4::Inverse() const
{
    const float det = Determinant();

    if (det == 0.0f)
    {
        HADES_LOG(Log, "Matrix is not invertible");
        return std::nullopt;
    }

    CMatrix4x4 result;
    const float inverse_det = 1.0f / det;

    for (int row = 0; row < 4; ++row)
    {
        for (int column = 0; column < 4; ++column)
        {
            CMatrix3x3 minor;

            int minor_row = 0;
            for (int i = 0; i < 4; ++i)
            {
                if (i == row)
                    continue;

                int minor_column = 0;
                for (int j = 0; j < 4; ++j)
                {
                    if (j == column)
                        continue;

                    minor.elements[minor_row][minor_column] = elements[i][j];
                    ++minor_column;
                }
                ++minor_row;
            }

            const float sign = ((row + column) % 2 == 0) ? 1.0f : -1.0f;
            result.elements[column][row] = sign * minor.Determinant() * inverse_det;
        }
    }
    return result;
}

float CMatrix4x4::Trace() const
{
    return elements[0][0] + elements[1][1] + elements[2][2] + elements[3][3];
}

bool CMatrix4x4::IsIdentity() const
{
    for (int row = 0; row < 4; ++row)
    {
        for (int column = 0; column < 4; ++column)
        {
            if (row == column)
            {
                if (elements[row][column] != 1.0f)
                {
                    return false;
                }
            }
            else if (elements[row][column] != 0.0f)
            {
                return false;
            }
        }
    }
    return true;
}

}
