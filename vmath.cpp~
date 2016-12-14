#include "vmath.h"

// Constructor
 Vector::Vector(void)
{
x = 0;
y = 0;
z = 0;
}
// Constructor
Vector::Vector(float xi, float yi, float zi)
{
x = xi;
y = yi;
z = zi;
}


void Vector::Normalize(void)
{
    float const tol = 0.0001f;
float m = (float) sqrt(x*x + y*y + z*z);
if(m <= tol) m = 1;
x /= m;
y /= m;
z /= m;

if (fabs(x) < tol) x = 0.0f;
if (fabs(y) < tol) y = 0.0f;
if (fabs(z) < tol) z = 0.0f;
}


float Vector::Magnitude(void)
{
return (float) sqrt(x*x + y*y + z*z);
}

void Vector::Reverse(void)
{
x = -x;
y = -y;
z = -z;
}

 Vector& Vector::operator+=(Vector u)
{

x += u.x;
y += u.y;
z += u.z;
return *this;
}


Vector& Vector::operator-=(Vector u)
{
x -= u.x;
y -= u.y;
z -= u.z;
return *this;
}


Vector& Vector::operator*=(float s)
{
x *= s;
y *= s;
z *= s;
return *this;
}


Vector& Vector::operator/=(float s)
{
x /= s;
y /= s;
z /= s;
return *this;
}




Vector operator+(Vector u, Vector v)
{
return Vector(u.x + v.x, u.y + v.y, u.z + v.z);
}


Vector operator-(Vector u, Vector v)
{

return Vector(u.x - v.x, u.y - v.y, u.z - v.z);
}


Vector operator^(Vector u, Vector v)
{
return Vector(
u.y*v.z - u.z*v.y,
-u.x*v.z + u.z*v.x,
u.x*v.y - u.y*v.x );
}

// Vector dot product

float operator*(Vector u, Vector v)
{
return (u.x*v.x + u.y*v.y + u.z*v.z);
}


Vector operator*(float s, Vector u)
{
return Vector(u.x*s, u.y*s, u.z*s);
}

Vector operator*(Vector u, float s)
{
return Vector(u.x*s, u.y*s, u.z*s);
}


Vector operator/(Vector u, float s)
{
return Vector(u.x/s, u.y/s, u.z/s);
}


float TripleScalarProduct(Vector u, Vector v, Vector w)
{
return float(
(u.x * (v.y*w.z - v.z*w.y)) +
(u.y * (-v.x*w.z + v.z*w.x)) +
(u.z * (v.x*w.y - v.y*w.x)) );
}

float Vector::Approach(float goal, float current, float dt)
{
    float difference;
    difference = goal - current;

    if (difference > dt)
    {
        return current + dt;
    }

    if (difference < -dt )
    {
        return current -dt;
    }

    return goal;



}








