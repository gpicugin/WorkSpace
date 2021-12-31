#include "Numeric.h"
#include <fstream>


// ----------Public----------

Numeric::Numeric(int i)
{
    char* arr = new char[100];
    _itoa(i, arr, 10);
    std::string str(arr);
    container = str;
}

Numeric Numeric::operator+(Numeric& v)
{
    Numeric tmp;
    int max_size = std::max(container.size(), v.container.size()) + 1;


    tmp.container.insert(0, max_size, '0');
    this->fillToSize(max_size);
    v.fillToSize(max_size);
    int plus = 0;
    for (int i = max_size - 1; i >= 0; i--)
    {
        if (i == 0 && plus == 1)
        {

        }
        int a, b, c;
        a = (*this)[i]; b = v[i];
        c = a + b + plus;
        if (c > 9)
        {
            plus = 1;
            c -= 10;
        }
        else
            plus = 0;
        tmp.container[i] = (c + zeroCode);
    }
    this->cutFirstZeros();
    v.cutFirstZeros();
    tmp.cutFirstZeros();
    return tmp;
}

void Numeric::operator+=(Numeric& v)
{
    *this = *this + v;
}

std::ofstream& operator<< (std::ofstream& out, const Numeric& v)
{

    out << v.container;
    return out;
}

// ----------Private----------

void Numeric::fillToSize(int size)
{
    if (size > container.size())
        container.insert(0, size - container.size(), '0');
}

int Numeric::findFirtNonZeroPos()
{
    int result = -1;
    for (int i = 0; i < container.size(); i++)
    {
        if (container[i] != '0')
        {
            result = i;
            break;
        }
    }
    return result;
}

void Numeric::cutFirstZeros()
{
    int pos = this->findFirtNonZeroPos();
    if (pos > 0)
        container.erase(0, pos);
}

int Numeric::operator [](int i)

{
    if (i < container.size() && i >= 0)
    {
        char ch = container[i];
        return atoi(&ch);
    }
    else
        return -1;
}