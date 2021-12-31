#pragma once
#include <string>
#include <algorithm>
#include <fstream>
class Numeric
{
private:
    static const int zeroCode = 48;
    std::string container;

public:
    Numeric() {}
    Numeric(int i);    

    Numeric operator+(Numeric& v);

    void operator+=(Numeric& v);

    friend std::ofstream& operator<< (std::ofstream& out, const Numeric& v);

private:

    void fillToSize(int size);

    int findFirtNonZeroPos();    

    void cutFirstZeros();    

    int operator [](int i);    
};