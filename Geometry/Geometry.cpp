#include "Geometry.h"

Point Point::operator-(Point p)
{
    Point result;
    result.x = this->x - p.x;
    result.y = this->y - p.y;
    result.z = this->z - p.z; 
    return result;
}

Vector::Vector(Point p)
{
    this->x = p.x;
    this->y = p.y;
    this->z = p.z;

}

double Vector::length()
{
    return sqrt(x*x + y * y + z * z);
}

Vector Vector::normalize()
{
    Vector tmp;
    double lngth = length();
    x = x / lngth;
    y = y / lngth;
    z = z / lngth;
    return tmp;
}

Vector Vector::plusXCoord()
{
    if (x < 0)
        return -(*this);
    else
        return *this;
}

Vector Vector::operator-()
{
    Vector tmp;
    tmp.x = -x;
    tmp.y = -y;
    tmp.z = -z;
    return tmp;
}

Vector Vector::operator*(double n)
{
    Vector tmp;
    tmp.x *= n;
    tmp.y *= n;
    tmp.z *= n;
    return tmp;
}

void Vector::operator=(Point p)
{
    this->x = p.x;
    this->y = p.y;
    this->z = p.z;
}

bool Vector::operator==(Vector v)
{
    Vector v1, v2;

    v1 = this->normalize();
    v1 = v1.plusXCoord();

    v2 = v.normalize();
    v2 = v2.plusXCoord();

    if (v1.x == v2.x && v1.y == v2.y && v1.z == v2.z)
        return true;
    else
        return false;
}

bool Vector::operator!=(Vector v)
{
    Vector v1, v2;

    v1 = this->normalize();
    v1 = v1.plusXCoord();

    v2 = v.normalize();
    v2 = v2.plusXCoord();

    if (v1.x != v2.x || v1.y != v2.y || v1.z != v2.z)
        return true;
    else
        return false;
}


Plane::Plane(Vector nV, double d)
{   
    this->_d = d;
    this->nV = nV;   
}

Plane::Plane(double a, double b, double c, double d)
{
    this->_d = d;
    nV.x = a;
    nV.y = b;
    nV.z = c;
}

Line::Line(Point p1, Point p2)
{
    this->p = p1;
    this->v = (p2 - p1);

    this->plane1.a = v.y;
    this->plane1.b = -v.x;
    this->plane1.c = 0;
    this->plane1.d = -v.y * p.x + v.x * p.y;

    this->plane2.a = v.z;
    this->plane2.b = 0;
    this->plane2.c = -v.x;
    this->plane2.d = -v.z * p.x + v.x * p.z;
}

double Line::distance(Point a)
{    
    Vector r = (a - p);
    double det =
        (r.y * v.z - r.z * v.y)
      - (r.x * v.z - r.z * v.x)
      + (r.x * v.y - r.y * v.x);
    det = (det < 0) ? -det : det;

    if (det == 0)
    {
        double scal = r.x * v.x + r.y * v.y + r.z * v.z;
        double cosAlpha = scal / (r.length() * v.length());
        
        return sqrt(1 - cosAlpha * cosAlpha) * r.length();
    }

    return (det / v.length());    
}

Vector Line::distanceV(Point a)
{
    return v;
}