#pragma once
#include <iostream>
#include <stdarg.h>
#include <vector>
#include <fstream>
#include <math.h>
#define ERROR_NULL_DIVISION 0
#define ERROR_FAILED_TO_INITIALIZE_PLANE 1

class Point
{
public:
    int dim;
    std::vector<double> arr;
    Point() 
    { 
        dim = 0;        
    }
  /*  Point(int d)
    {
        dim = d;
        arr = new double[dim];
        for (size_t i = 0; i < dim; i++)
            arr[i] = 0;
    }*/
    Point(int d, ...) 
    {
        dim = d;
        arr.resize(dim);
        va_list ap;
        va_start(ap, dim);
       
        for (size_t i = 0; i <= dim; i++) 
        {
            arr[i] = va_arg(ap, double);
        }
        va_end(ap);        
    }
    
    Point operator-(Point p);
    double& operator[](int i) { return arr[i]; }
};



class Vector : public Point
{
public:
    Vector() :Point() {};
    Vector(int d, ...) :Point(d) {}
    //Vector(double a, double b, double c) : Point(a, b, c) {}
    Vector(Point p);

    double length();
    Vector normalize();
    Vector plusXCoord();
    Vector operator-();
    Vector operator*(double n);
    void operator=(Point p);
    bool operator==(Vector v);
    bool operator!=(Vector v);
    //double* operator[](int i) { return &arr[i]; }
private:
};

//class Plane
//{
//    double _d;
//    Vector nV;
//public:
//    double& a = nV.x;
//    double& b = nV.y;
//    double& c = nV.z;
//    double& d = _d;
//    Plane() {};
//    Plane(Vector nV, double d);
//    Plane(double a, double b, double c, double d);
//};
//
//class Line
//{
//private:
//    Point p;
//    Vector v;
//    Plane plane1;
//    Plane plane2;
//public:
//    const double& x0 = p.x;
//    const double& y0 = p.y;
//    const double& z0 = p.z;
//    Line(Point p1, Point p2);
//    double distance(Point a);
//    Vector distanceV(Point a);
//};


class Matrix
{
private:
    std::vector<std::vector<double>> arr;
public:
    int m, n;
    Matrix(int a, int b)
    {
        m = a;
        n = b;
        arr.resize(m);
        for (size_t i = 0; i < m; i++)
        {
            arr[i].resize(n);
        }
    }
    Matrix fSigm();
    Matrix Round(double dec);
    std::vector<double>& operator[](int i) { return arr[i]; }
    Matrix& operator=(Matrix a);
    friend Matrix operator*(const Matrix a, const Matrix b);
    friend std::ifstream& operator>>(std::ifstream& in, Matrix& a);
    friend std::ofstream& operator<<(std::ofstream& out, Matrix a);
};