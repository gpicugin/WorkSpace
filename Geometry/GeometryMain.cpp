//#include "Geometry.h"
#include <iostream>
#include <fstream>


struct Point
{
    int x, y;
    Point operator-(Point p)
    {
        Point result;
        result.x = x - p.x;
        result.y = y - p.y;
        return result;
    }
};




double multipleAbs(Point v1, Point v2)
{
    return abs(v1.x * v2.y - v1.y* v2.x);
}


double sqrTriangle(Point p1, Point p2, Point p3)
{
    Point v1, v2;
    v1.x = p2.x - p1.x;
    v1.y = p2.y - p1.y;

    v2.x = p3.x - p1.x;
    v2.y = p3.y - p1.y;

    double sqr = multipleAbs(v1, v2) / 2;
    return sqr;
}



int main()
{

    std::ifstream in;
    std::ofstream out;

    in.open("..\\INPUT.txt");
    out.open("..\\OUTPUT.txt");

    int n, result = 0;
    in >> n;

    Point p;
    Point p1;
    Point p2;
    Point p3;
    Point p4;

    for (int i = 0; i < n; i++)
    {
        in >> p.x >> p.y;
        in >> p1.x >> p1.y;
        in >> p2.x >> p2.y;
        in >> p3.x >> p3.y;
        in >> p4.x >> p4.y;

        double sqr = multipleAbs(p2 - p1, p4 - p1);

        double sqrT1 = sqrTriangle(p, p1, p2);
        double sqrT2 = sqrTriangle(p, p2, p3);
        double sqrT3 = sqrTriangle(p, p3, p4);
        double sqrT4 = sqrTriangle(p, p4, p1);

        double sum = sqrT1 + sqrT2 + sqrT3 + sqrT4;

        if (abs(sum - sqr) == 0)
            result++;

    }  
    out << result;
    return 0;
}
