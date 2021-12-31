#pragma once
#include <iostream>
#define ERROR_NULL_DIVISION 0
#define ERROR_FAILED_TO_INITIALIZE_PLANE 1

class Point
{
public:
    double x, y, z;
    Point() { x = 0; y = 0; z = 0; }
    Point(double a, double b, double c) { x = a; y = b; z = c; }
    Point operator-(Point p);
};

class Vector : public Point
{
public:
    Vector() :Point() {}
    Vector(double a, double b, double c) : Point(a, b, c) {}
    Vector(Point p);

    double length();
    Vector normalize();
    Vector plusXCoord();
    Vector operator-();
    Vector operator*(double n);
    void operator=(Point p);
    bool operator==(Vector v);
    bool operator!=(Vector v);
private:
};

class Plane
{
    double _d;
    Vector nV;
public:
    double& a = nV.x;
    double& b = nV.y;
    double& c = nV.z;
    double& d = _d;
    Plane() {};
    Plane(Vector nV, double d);
    Plane(double a, double b, double c, double d);
};

class Line
{
private:
    Point p;
    Vector v;
    Plane plane1;
    Plane plane2;
public:
    const double& x0 = p.x;
    const double& y0 = p.y;
    const double& z0 = p.z;
    Line(Point p1, Point p2);
    double distance(Point a);
    Vector distanceV(Point a);
};


