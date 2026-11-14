#include "Matrix3x3.h"
#include "Source/Core/Math/Vector3.h"
#include <cmath>
#include <format>

namespace Hades
{

/*static*/ CMatrix3x3 CMatrix3x3::CreateIdentity()
{
    CMatrix3x3 result;
    for (int row = 0; row < 3; ++row)
    {
        for (int column = 0; column < 3; ++column)
        {
            result.elements[row][column] = (row == column) ? 1.0f : 0.0f;
        }
    }
    return result;
}

/*static*/ CMatrix3x3 CMatrix3x3::CreateTranslation(const CVector2& translation)
{
    CMatrix3x3 result;
    result.elements[0][2] = translation.x;
    result.elements[1][2] = translation.y;
    return result;
}

/*static*/ CMatrix3x3 CMatrix3x3::CreateRotation(float angle)
{
    CMatrix3x3 result;
    const float cos = std::cos(angle);
    const float sin = std::sin(angle);
    result.elements[0][0] = cos;
    result.elements[0][1] = -sin;
    result.elements[1][0] = sin;
    result.elements[1][1] = cos;
    return result;
}

/*static*/ CMatrix3x3 CMatrix3x3::CreateScale(const CVector2& scale)
{
    CMatrix3x3 result;
    result.elements[0][0] = scale.x;
    result.elements[1][1] = scale.y;
    return result;
}

CMatrix3x3::CMatrix3x3()
{
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            elements[i][j] = (i == j) ? 1.0f : 0.0f;
        }
    }
}

std::string CMatrix3x3::ToString() const
{
    return std::format("[{:.2f} {:.2f} {:.2f}]\n[{:.2f} {:.2f} {:.2f}]\n[{:.2f} {:.2f} {:.2f}]",
        elements[0][0], elements[0][1], elements[0][2],
        elements[1][0], elements[1][1], elements[1][2],
        elements[2][0], elements[2][1], elements[2][2]);
}

CMatrix3x3::CMatrix3x3(const CVector2& column0, const CVector2& column1, const CVector2& translation)
{
    elements[0][0] = column0.x;
    elements[0][1] = column1.x;
    elements[0][2] = translation.x;

    elements[1][0] = column0.y;
    elements[1][1] = column1.y;
    elements[1][2] = translation.y;

    elements[2][0] = 0.0f;
    elements[2][1] = 0.0f;
    elements[2][2] = 1.0f;
}

bool CMatrix3x3::operator==(const CMatrix3x3& matrix) const
{
    for (int row = 0; row != 3; ++row)
    {
        for (int column = 0; column != 3; ++column)
        {
            if (elements[row][column] != matrix.elements[row][column])
            {
                return false;
            }
        }
    }
    return true;
}

bool CMatrix3x3::operator!=(const CMatrix3x3& matrix) const
{
    return !(*this == matrix);
}

CMatrix3x3 CMatrix3x3::operator+(const CMatrix3x3& matrix) const
{
    CMatrix3x3 result;
    for (int row = 0; row != 3; ++row)
    {
        for (int column = 0; column != 3; ++column)
        {
            result.elements[row][column] = elements[row][column] + matrix.elements[row][column];
        }
    }
    return result;
}

CMatrix3x3 CMatrix3x3::operator-(const CMatrix3x3& matrix) const
{
    CMatrix3x3 result;
    for (int row = 0; row != 3; ++row)
    {
        for (int column = 0; column != 3; ++column)
        {
            result.elements[row][column] = elements[row][column] - matrix.elements[row][column];
        }
    }
    return result;
}
CMatrix3x3 CMatrix3x3::operator*(const CMatrix3x3& matrix) const
{
    CMatrix3x3 result;
    for (int row = 0; row != 3; ++row)
    {
        for (int column = 0; column != 3; ++column)
        {
            result.elements[row][column] = 0.0f;

            for (int k = 0; k != 3; ++k)
            {
                result.elements[row][column] += elements[row][k] * matrix.elements[k][column];
            }
        }
    }
    return result;
}

CVector3 CMatrix3x3::operator*(const CVector3& vec) const
{
    return CVector3(
        elements[0][0] * vec.x + elements[0][1] * vec.y + elements[0][2] * vec.z,
        elements[1][0] * vec.x + elements[1][1] * vec.y + elements[1][2] * vec.z,
        elements[2][0] * vec.x + elements[2][1] * vec.y + elements[2][2] * vec.z);
}

float CMatrix3x3::Determinant() const
{
    return elements[0][0] * elements[1][1] * elements[2][2] + elements[1][0] * elements[2][1] * elements[0][2] + elements[2][0] * elements[0][1] * elements[1][2] - elements[0][2] * elements[1][1] * elements[2][0] - elements[1][2] * elements[2][1] * elements[0][0] - elements[2][2] * elements[0][1] * elements[1][0];
}

CMatrix3x3 CMatrix3x3::Transpose() const
{
    CMatrix3x3 result = *this;
    for (int row = 0; row != 3; ++row)
    {
        for (int column = 0; column != 3; ++column)
        {
            result.elements[row][column] = elements[column][row];
        }
    }
    return result;
}

std::optional<CMatrix3x3> CMatrix3x3::Inverse() const
{
    const float det = Determinant();
    if (det != 0.0f)
    {
        CMatrix3x3 result;
        const float inverse_det = 1.0f / det;
        result.elements[0][0] = (elements[1][1] * elements[2][2] - elements[1][2] * elements[2][1]) * inverse_det;
        result.elements[0][1] = (elements[0][2] * elements[2][1] - elements[0][1] * elements[2][2]) * inverse_det;
        result.elements[0][2] = (elements[0][1] * elements[1][2] - elements[0][2] * elements[1][1]) * inverse_det;

        result.elements[1][0] = (elements[1][2] * elements[2][0] - elements[1][0] * elements[2][2]) * inverse_det;
        result.elements[1][1] = (elements[0][0] * elements[2][2] - elements[0][2] * elements[2][0]) * inverse_det;
        result.elements[1][2] = (elements[0][2] * elements[1][0] - elements[0][0] * elements[1][2]) * inverse_det;

        result.elements[2][0] = (elements[1][0] * elements[2][1] - elements[1][1] * elements[2][0]) * inverse_det;
        result.elements[2][1] = (elements[0][1] * elements[2][0] - elements[0][0] * elements[2][1]) * inverse_det;
        result.elements[2][2] = (elements[0][0] * elements[1][1] - elements[0][1] * elements[1][0]) * inverse_det;

        return result;
    }

    HADES_LOG(Log, "Matrix is not invertible");
    return std::nullopt;
}

float CMatrix3x3::Trace() const
{
    return elements[0][0] + elements[1][1] + elements[2][2];
}

bool CMatrix3x3::IsIdentity() const
{
    for (int row = 0; row < 3; ++row)
    {
        for (int column = 0; column < 3; ++column)
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
