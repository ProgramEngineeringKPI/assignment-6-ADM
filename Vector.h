#ifndef ASSIGNMENT_6_ADM_VECTOR_H
#define ASSIGNMENT_6_ADM_VECTOR_H

#include <math.h>

struct Vector
{
    float x, y, z;

    Vector();
    Vector(const Vector & v);
    Vector(float x, float y, float z);
    Vector(float f);

    ~Vector();

    float lengthSquared();
    float length();
    Vector normalized();

    Vector& operator =(const Vector& v);
    Vector& operator +=(const Vector& v);
    Vector& operator -=(const Vector& v);
    Vector& operator *=(float f);
    Vector& operator /=(float f);
    Vector operator -() const;
    float & operator [](int coordinate);
    float & coordinate(int coordinate);

    static float dot(Vector v1, Vector v2);
    static Vector cross(Vector v1, Vector v2);

    friend Vector operator +(const Vector& v1, const Vector& v2);
    friend Vector operator -(const Vector& v1, const Vector& v2);
    friend Vector operator *(const Vector& v1, const Vector& v2);
    friend Vector operator *(const Vector& v, float f);
    friend Vector operator *(float f, const Vector& v);
    friend Vector operator /(const Vector& v1, const Vector& v2);
    friend Vector operator /(const Vector& v, float f);
    friend Vector operator /(float f, const Vector& v);


};

typedef Vector Point;

struct Vector2
{
    float u, v;

    Vector2();
    Vector2(const Vector2&);
    Vector2(float u, float v);
    Vector2(float f);

    ~Vector2();

    Vector2& operator =(const Vector2& v);
};

#endif //ASSIGNMENT_6_ADM_VECTOR_H
