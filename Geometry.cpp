#include "Geometry.h"

Point Point::operator-(Point p)
{
    try
    {
        if (dim != p.dim) {           
            throw -1;
        }
    }
    catch(int a)
    {
        std::cerr << "error";
        exit;
    }
    Point result(p.dim);

    for (size_t i = 0; i < dim; i++)
    {
        result[i] = this->arr[i] - p[i];
    }  

    return result;
}

Vector::Vector(Point p)
{
    dim = p.dim;
    for (size_t i = 0; i < dim; i++)
    {
        arr[i] = p[i];
    }
}

double Vector::length()
{
    double sum = 0;
    for (size_t i = 0; i < dim; i++)
    {
        sum += arr[i] * arr[i];
    }
    return sqrt(sum);
}

Vector Vector::normalize()
{

    Vector tmp(dim);
    
    double lngth = length();
    for (size_t i = 0; i < dim; i++)
    {
        tmp[i] = arr[i] / lngth;
    }
   
    return tmp;
}

Vector Vector::plusXCoord()
{
    if (arr[0] < 0)
        return -(*this);
    else
        return *this;
}

Vector Vector::operator-()
{
    Vector tmp(dim);
    for (size_t i = 0; i < dim; i++)
    {
        tmp[i] = -arr[i];
    } 
    return tmp;
}

Vector Vector::operator*(double n)
{
    Vector tmp(dim);
    for (size_t i = 0; i < dim; i++)
    {
        tmp[i] = arr[i] * n;
    }
  
    return tmp;
}

void Vector::operator=(Point p)
{
    this->dim = p.dim;
    arr.resize(dim);
    for (size_t i = 0; i < dim; i++)
    {
        this->arr[i] = p[i];
    }  
}

bool Vector::operator==(Vector v)
{
    Vector v1, v2;

    v1 = this->normalize();
    v1 = v1.plusXCoord();

    v2 = v.normalize();
    v2 = v2.plusXCoord();


    if (dim != v.dim)
        return false;

    for (size_t i = 0; i < dim; i++)
    {
        if (v1[i] != v2[i])
            return false;
    }

    return true;
}

bool Vector::operator!=(Vector v)
{
    Vector v1, v2;

    v1 = this->normalize();
    v1 = v1.plusXCoord();

    v2 = v.normalize();
    v2 = v2.plusXCoord();

    if (dim != v.dim)
        return true;

    for (size_t i = 0; i < dim; i++)
    {
        if (v1[i] != v2[i])
            return true;
    }
    return false;   
}

Matrix& operator*(Matrix a, Matrix b)
{
    try 
    {
        if (a.n != b.m)
            throw -1;    
    }

    catch (int a)
    {
        std::cerr << "error";
        exit;
    }

    Matrix result(a.m, b.n);

    for (size_t i = 0; i < result.m; i++)
    {
        for (size_t j = 0; j < result.n; j++)
        {            
            for (size_t k = 0; k < a.n; k++)
            {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return result;
}

Matrix& Matrix::operator=(Matrix a)
{
    arr.clear();
    arr.resize(a.m);
    for (size_t i = 0; i < a.m; i++)
    {
        arr[i].resize(a.n);
        for (size_t j = 0; j < a.n; j++)
        {
            arr[i][j] = a[i][j];
        }
    }
    return *this;
}

std::ifstream& operator >> (std::ifstream& in, Matrix& a)
{    
    for (size_t i = 0; i < a.m; i++)
    {
        for (size_t j = 0; j < a.n; j++)
        {            
            in >> a[i][j];
        }
    }
    return in;
}

std::ofstream& operator<< (std::ofstream& out, Matrix& a)
{
    for (size_t i = 0; i < a.m; i++)
    {
        for (size_t j = 0; j < a.n; j++)
        {
            out << a[i][j];
        }
    }    
    return out;
}

//
//Plane::Plane(Vector nV, double d)
//{   
//    this->_d = d;
//    this->nV = nV;   
//}
//
//Plane::Plane(double a, double b, double c, double d)
//{
//    this->_d = d;
//    nV.x = a;
//    nV.y = b;
//    nV.z = c;
//}
//
//Line::Line(Point p1, Point p2)
//{
//    this->p = p1;
//    this->v = (p2 - p1);
//
//    this->plane1.a = v.y;
//    this->plane1.b = -v.x;
//    this->plane1.c = 0;
//    this->plane1.d = -v.y * p.x + v.x * p.y;
//
//    this->plane2.a = v.z;
//    this->plane2.b = 0;
//    this->plane2.c = -v.x;
//    this->plane2.d = -v.z * p.x + v.x * p.z;
//}
//
//double Line::distance(Point a)
//{    
//    Vector r = (a - p);
//    double det =
//        (r.y * v.z - r.z * v.y)
//      - (r.x * v.z - r.z * v.x)
//      + (r.x * v.y - r.y * v.x);
//    det = (det < 0) ? -det : det;
//
//    if (det == 0)
//    {
//        double scal = r.x * v.x + r.y * v.y + r.z * v.z;
//        double cosAlpha = scal / (r.length() * v.length());
//        
//        return sqrt(1 - cosAlpha * cosAlpha) * r.length();
//    }
//
//    return (det / v.length());    
//}
//
//Vector Line::distanceV(Point a)
//{
//    return v;
//}