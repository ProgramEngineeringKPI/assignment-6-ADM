//
// Created by sasha on 08.06.2018.
//

#include "Vector.h"

Vector::Vector()
{
    this->x = 0;
    this->y = 0;
    this->z = 0;
}

Vector::Vector(const Vector & v)
{
    this->x = v.x;
    this->y = v.y;
    this->z = v.z;
}

Vector::Vector(float x, float y, float z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

Vector::Vector(float f)
{
    this->x = f;
    this->y = f;
    this->z = f;
}

Vector::~Vector() {}

float Vector::lengthSquared()
{
    return x*x + y*y + z*z;
}

float Vector::length()
{
    return sqrt(lengthSquared());
}

Vector Vector::normalized()
{
    float l = length();
    float inversionLength = 1 / l;
    x *= inversionLength;
    y *= inversionLength;
    z *= inversionLength;
    return *this;
}

Vector & Vector::operator=(const Vector & v)
{
    this->x = v.x;
    this->y = v.y;
    this->z = v.z;
    return *this;
}

Vector & Vector::operator+=(const Vector & v)
{
    this->x += v.x;
    this->y += v.y;
    this->z += v.z;
    return *this;
}

Vector & Vector::operator-=(const Vector & v)
{
    this->x -= v.x;
    this->y -= v.y;
    this->z -= v.z;
    return *this;
}

Vector & Vector::operator*=(float f)
{
    this->x *= f;
    this->y *= f;
    this->z *= f;
    return *this;
}

Vector & Vector::operator/=(float f)
{
    this->x /= f;
    this->y /= f;
    this->z /= f;
    return *this;
}

Vector Vector::operator-() const
{
    return Vector(-x, -y, -z);
}

float & Vector::operator [](int coordinate)
{
    if(coordinate == 0) return this->x;
    if(coordinate == 1) return this->y;
    if(coordinate == 2) return this->z;
    return this->x;
}

float & Vector::coordinate(int coordinate)
{
    if(coordinate == 0) return this->x;
    if(coordinate == 1) return this->y;
    if(coordinate == 2) return this->z;
    return this->x;
}

float Vector::dot(Vector v1, Vector v2)
{
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

Vector Vector::cross(Vector v1, Vector v2)
{
    return Vector(v1.y*v2.z - v1.z*v2.y, v1.z*v2.x - v1.x*v2.z, v1.x*v2.y - v1.y*v2.x);
}

Vector operator -(const Vector & v1, const Vector & v2)
{
    return Vector(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z);
}

Vector operator *(const Vector & v1, const Vector & v2)
{
    return Vector(v1.x * v2.x, v1.y * v2.y, v1.z * v2.z);
}

Vector operator *(const Vector & v, float f)
{
    return Vector(v.x  * f, v.y * f, v.z * f);
}

Vector operator *(float f, const Vector & v)
{
    return Vector(v.x  * f, v.y * f, v.z * f);
}

Vector operator /(const Vector & v1, const Vector & v2)
{
    return Vector(v1.x / v2.x, v1.y / v2.y, v1.z / v2.z);
}

Vector operator /(const Vector & v, float f)
{
    return Vector(v.x  / f, v.y / f, v.z / f);
}

Vector operator /(float f, const Vector & v)
{
    return Vector(f / v.x, f / v.y, f / v.z);
}

Vector operator +(const Vector & v1, const Vector & v2)
{
    return Vector(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
}



Vector2::Vector2()
{
    this->u = 0;
    this->v = 0;
}

Vector2::Vector2(const Vector2 & v)
{
    this->u = v.u;
    this->v = v.v;
}

Vector2::Vector2(float u, float v)
{
    this->u = u;
    this->v = v;
}

Vector2::Vector2(float f)
{
    this->u = f;
    this->v = f;
}

Vector2::~Vector2()
{
}

Vector2 & Vector2::operator=(const Vector2 & v)
{
    this->u = v.u;
    this->v = v.v;
    return *this;
}
