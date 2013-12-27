// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file Angle.cpp
 */

#include "Angle.hpp"
#include "Math.hpp"

CGUL::Angle CGUL::Angle::Inverse(const Angle& angle)
{
    return Angle(angle.GetRadians() + Math::Tau< CGUL::Float32 >());
}

CGUL::Angle CGUL::Angle::Difference(const Angle& a, const Angle& b)
{
    return Angle(b.GetRadians() - a.GetRadians());
}

CGUL::Angle CGUL::Angle::Center(const Angle& a, const Angle& b)
{
    if (Difference(a, b).GetDegreesPositive() <= 180)
    {
        return Angle(a.GetRadians() + (Difference(a, b).GetRadians() * .5f));
    }
    else
    {
        return Inverse(Angle(a.GetRadians() + (Difference(a, b).GetRadians() * .5f)));
    }
}

CGUL::Angle CGUL::Angle::InverseCenter(const Angle& a, const Angle& b)
{
    return Inverse(Center(a, b));
}

CGUL::Angle::Angle()
{
    radians = 0.0f;
}

CGUL::Angle::Angle(CGUL::Float32 radians)
{
    SetRadians(radians);
}

CGUL::Angle::Angle(const Vector2& direction)
{
    SetDirection(direction);
}

void CGUL::Angle::SetRadians(Float32 radians)
{
    this->radians = radians - Math::Floor(radians / Math::Tau< Float32 >()) * (Math::Tau< Float32 >());
}

CGUL::Float32 CGUL::Angle::GetRadians() const
{
    if (this->radians > Math::Pi< Float32 >())
    {
        return -(Math::Tau< Float32 >() - radians);
    }
    else
    {
        return radians;
    }
}

CGUL::Float32 CGUL::Angle::GetRadiansPositive() const
{
    return radians;
}

void CGUL::Angle::SetDegrees(CGUL::Float32 degrees)
{
    SetRadians(Math::DegToRad(degrees));
}

CGUL::Float32 CGUL::Angle::GetDegrees() const
{
    return Math::RadToDeg(GetRadians());
}

CGUL::Float32 CGUL::Angle::GetDegreesPositive() const
{
    return Math::RadToDeg(GetRadiansPositive());
}

void CGUL::Angle::SetDirection(const Vector2& direction)
{
    if (direction.GetSquaredMagnitude() == 1)
    {
        radians = Math::ATan2(direction.y, direction.x);
    }
    else
    {
        Vector2 dir = Vector2::Normalized(direction);
        radians = Math::ATan2(dir.y, dir.x);
    }
}

CGUL::Vector2 CGUL::Angle::GetDirection() const
{
    return Vector2(Math::Cos(radians), Math::Sin(radians));
}

void CGUL::Angle::Constrain(Angle from, Angle to)
{
    Angle mid = Center(from, to);

    if (Difference(from, *this).GetDegreesPositive() > Difference(from, to).GetDegreesPositive())
    {
        if (Difference(mid, *this).GetDegrees() < 0)
        {
            *this = from;
        }
        else
        {
            *this = to;
        }
    }
}