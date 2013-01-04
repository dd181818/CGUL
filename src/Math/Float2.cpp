/* Jatta - General Utility Library
 * Copyright (c) 2012-2013, Joshua Brookover
 * All rights reserved.
 */

#include "Float2.h"
#include "Math.h"

_JATTA_EXPORT const Jatta::Float2 zero(0, 0);
_JATTA_EXPORT const Jatta::Float2 one(1, 1);
_JATTA_EXPORT const Jatta::Float2 unitX(1, 0);
_JATTA_EXPORT const Jatta::Float2 unitY(0, 1);

_JATTA_EXPORT Jatta::Float2::Float2()
{
    this->x = 0;
    this->y = 0;
}

_JATTA_EXPORT Jatta::Float2::Float2(const Float2& copy)
{
    this->x = copy.x;
    this->y = copy.y;
}

_JATTA_EXPORT Jatta::Float2::Float2(float value)
{
    this->x = value;
    this->y = value;
}

_JATTA_EXPORT Jatta::Float2::Float2(float x, float y)
{
    this->x = x;
    this->y = y;
}

_JATTA_EXPORT Jatta::Float2& Jatta::Float2::operator=(const Float2& operand)
{
    this->x = operand.x;
    this->y = operand.y;
    return *this;
}

_JATTA_EXPORT Jatta::Float32& Jatta::Float2::operator[](UInt32 index)
{
    return m[index];
}

_JATTA_EXPORT Jatta::Float32 Jatta::Float2::operator[](UInt32 index) const
{
    return m[index];
}

_JATTA_EXPORT Jatta::Float2 Jatta::Float2::operator-() const
{
    return Float2(-this->x, -this->y);
}

_JATTA_EXPORT bool Jatta::Float2::operator==(const Float2& operand) const
{
    return (this->x == operand.x && this->y == operand.y);
}

_JATTA_EXPORT bool Jatta::Float2::operator!=(const Float2& operand) const
{
    return (this->x != operand.x || this->y != operand.y);
}

_JATTA_EXPORT Jatta::Float2 Jatta::Float2::operator+(const Float2& operand) const
{
    return Float2(this->x + operand.x, this->y + operand.y);
}

_JATTA_EXPORT Jatta::Float2& Jatta::Float2::operator+=(const Float2& operand)
{
    this->x += operand.x;
    this->y += operand.y;
    return *this;
}

_JATTA_EXPORT Jatta::Float2 Jatta::Float2::operator-(const Float2& operand) const
{
    return Float2(this->x - operand.x, this->y - operand.y);
}

_JATTA_EXPORT Jatta::Float2& Jatta::Float2::operator-=(const Float2& operand)
{
    this->x -= operand.x;
    this->y -= operand.y;
    return *this;
}

_JATTA_EXPORT Jatta::Float2 Jatta::Float2::operator*(float operand) const
{
    return Float2(this->x * operand, this->y * operand);
}

_JATTA_EXPORT Jatta::Float2& Jatta::Float2::operator*=(float operand)
{
    this->x *= operand;
    this->y *= operand;
    return *this;
}

_JATTA_EXPORT Jatta::Float2 Jatta::Float2::operator/(Float32 operand) const
{
    return Float2(this->x / operand, this->y / operand);
}

_JATTA_EXPORT Jatta::Float2& Jatta::Float2::operator/=(Float32 operand)
{
    this->x /= operand;
    this->y /= operand;
    return *this;
}

_JATTA_EXPORT void Jatta::Float2::Set(Float32 value)
{
    this->x = value;
    this->y = value;
}

_JATTA_EXPORT void Jatta::Float2::Set(Float32 x, Float32 y)
{
    this->x = x;
    this->y = y;
}

_JATTA_EXPORT void Jatta::Float2::Normalize()
{
    Float32 inverseMagnitude = 1.0f / GetMagnitude();
    x *= inverseMagnitude;
    y *= inverseMagnitude;
}

_JATTA_EXPORT Jatta::Boolean Jatta::Float2::IsNormalized(Float32 epsilon) const
{
    return Math::InEpsilon(GetMagnitude(), 1, epsilon);
}

_JATTA_EXPORT Jatta::Float32 Jatta::Float2::GetMagnitude() const
{
    return Math::Sqrt(x * x + y * y);
}

_JATTA_EXPORT Jatta::Float32 Jatta::Float2::GetDistance(const Float2& other) const
{
    // TODO: this
    return 0;
}