#pragma once

#include "../Logging/Log.h"
#include <cmath>

namespace Hades
{
class CMath
{
public:
    static const float PI;
    static const float TWO_PI;
    static const float HALF_PI;
    static const float INV_PI;
    static const float SQRT_TWO;
    static const float SQRT_THREE;

    static const float RAD2DEG;
    static const float DEG2RAD;

    static const float EPSILON_FLOAT;
    static const double EPSILON_DOUBLE;

    static bool IsNearlyEqual(const float a, const float b, const float tolerance = EPSILON_FLOAT)
    {
        return std::abs(a - b) <= tolerance;
    }

    static bool IsNearlyEqual(const double a, const double b, const double tolerance = EPSILON_DOUBLE)
    {
        return std::abs(a - b) <= tolerance;
    }

    static bool IsNearlyZero(const float a, const float tolerance = EPSILON_FLOAT)
    {
        return IsNearlyEqual(a, 0.0f, tolerance);
    }

    static bool IsNearlyZero(const double a, const double tolerance = EPSILON_DOUBLE)
    {
        return IsNearlyEqual(a, 0.0, tolerance);
    }

    static float Sqrt(const float radicand)
    {
        if (radicand < 0.f)
        {
            HADES_LOG(Warning, "Sqrt called with negative value: %f", radicand)
            return NAN;
        }
        return std::sqrt(radicand);
    }

    static double Sqrt(const double radicand)
    {
        if (radicand < 0.)
        {
            HADES_LOG(Warning, "Sqrt called with negative value: %f", radicand)
            return NAN;
        }
        return std::sqrt(radicand);
    }

    static float InvSqrt(const float radicand)
    {
        if (radicand < 0.f)
        {
            HADES_LOG(Warning, "Sqrt called with negative value: %f", radicand)
            return NAN;
        }

        const float root = std::sqrt(radicand);
        if (IsNearlyZero(root))
        {
            HADES_LOG(Warning, "InvSqrt called with value resulting in near-zero root: %f", radicand)
            return NAN;
        }
        return 1. / root;
    }
    static double InvSqrt(const double radicand)
    {
        if (radicand < 0.)
        {
            HADES_LOG(Warning, "Sqrt called with negative value: %f", radicand)
            return NAN;
        }

        const double root = std::sqrt(radicand);
        if (IsNearlyZero(root))
        {
            HADES_LOG(Warning, "InvSqrt called with value resulting in near-zero root: %f", radicand)
            return NAN;
        }
        return 1.f / root;
    }
};
}
