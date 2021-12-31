#pragma once
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
#include "Numeric.h"
#define numericArr std::vector<Numeric> 

int task1(int n, int x, int y)
{
    int m = 0;
    int result = -1;
    int listCount = 1;
    if (n == 1)
    {
        result = std::min(x, y);
    }
    else
    {
        do
        {
            m++;
            listCount = 0;
            listCount = (int)(m / x) + (int)(m / y) + 1;

        } while (listCount < n);
        result = m + std::min(x, y);
    }
    return result;
}

int task1_1(int n, int x, int y)
{
    double result = n * x * y / (x + y);
    return (int)(result)+ std::min(x,y);
}

int task4(int x)
{
    int result = x * 100 + 9 * 10 + (9 - x);
    return result;
}

void task5(std::vector<int> &input, std::ofstream &out)
{
    std::vector<int> even, odd;
    for (int i = 0; i < input.size(); i++)
    {
        if (input[i] % 2 == 0)
            even.push_back(input[i]);
        else
            odd.push_back(input[i]);
    }
    for (int i = 0; i < odd.size(); i++)
        out << odd[i] << " ";
    out << "\n";
    for (int i = 0; i < even.size(); i++)
        out << even[i] << " ";
    out << "\n";

    if (even.size() >= odd.size())
        out << "YES";
    else
        out << "NO";        
}

std::string task6(std::string &str)
{
    {
        if (str.size() != 5)
            return "ERROR";

        if ((int)str[0] < 65 || (int)str[0] > 72)
            return "ERROR";

        if ((int)str[1] < 49 || (int)str[1] > 56)
            return "ERROR";

        if (str[2] != '-')
            return "ERROR";

        if ((int)str[3] < 65 || (int)str[3] > 72)
            return "ERROR";

        if ((int)str[4] < 49 || (int)str[4] > 56)
            return "ERROR";
    }

    int start_x = (int)str[0] - 65;
    int start_y = (int)str[1] - 49;
    // ----
    int end_x = (int)str[3] - 65;
    int end_y = (int)str[4] - 49;

    int abs_x = abs(start_x - end_x);
    int abs_y = abs(start_y - end_y);

    if ((abs_x == 2 && abs_y == 1) || (abs_x == 1 && abs_y == 2))
        return "YES";
    else
        return "NO";

}

std::string maxString(const std::string &str1, const std::string &str2)
{
    if (str1.size() > str2.size())
        return str1;
    else if (str1.size() < str2.size())
        return str2;
    else
    {
        int cmp = str1.compare(str2);
        if (cmp >= 0)
            return str1;
        else
            return str2;
    }
}

std::string task7(std::ifstream &in)
{
    std::string str1, str2, str3, str_tmp;
    std::getline(in, str1, ' ');
    std::getline(in, str2, ' ');
    std::getline(in, str3, '\n');
    //str3.erase(str3.size() - 1);

    int max_size = std::max(str1.size(), std::max(str2.size(), str3.size()));

    str1.insert(0, max_size - str1.size(), '0');
    str2.insert(0, max_size - str2.size(), '0');
    str3.insert(0, max_size - str3.size(), '0');



    std::string result = maxString(str1, (maxString(str2, str3)));

    return result;
}

std::string task8(std::ifstream &in)
{
    int a, b, c;
    in >> a >> b >> c;

    if (a * b == c)
        return "YES";
    else
        return "NO";  
}

void task9(std::ifstream &in, std::ofstream &out)
{
    int a, b, c, d;
    in >> a >> b >> c >> d;
    for (int i = -100; i < 101; i++)
    {
        if (a*i*i*i + b * i*i + c * i + d == 0)
            out << i << " ";
    }
}

void task10(std::ifstream &in, std::ofstream &out)
{
    long long a, b, c, d;
    in >> a >> b >> c >> d;
    for (int x = -100; x <= 100; x++)
    {

        if ((a * x*x*x + b * x*x + c * x + d) == 0)
            out << x << " ";
    }
}

numericArr* fillDp(int n, int k)
{
    numericArr* dp_ptr = new numericArr;
    numericArr& dp = *dp_ptr;
    dp.resize(n + 1);
    dp[0] = dp[1] = 1;
    for (int i = 2; i < n + 1; i++)
    {
        int j = i;
        int count = k;
        while (j != 0 && count != 0)
        {
            j--;
            count--;
            dp[i] += dp[j];
        }
    }
    return dp_ptr;
}

void task11(std::ifstream &in, std::ofstream &out)
{
    int k, n;
    in >> k >> n;
    numericArr* dp_ptr = fillDp(n, k);
    out << (*dp_ptr)[n];
}

struct Point
{
    long long x, y;
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

void task12(std::ifstream &in, std::ofstream &out)
{
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
}

struct Animals
{
	int cows;
	int bulls;
};

void task13(std::ifstream &in, std::ofstream &out)
{
	Animals zoo;
	zoo.cows = 0;
	zoo.bulls = 0;	

	std::string a, b;
	in >> a >> b;

	for (int i = 0; i < a.size(); i++)
	{
		for (int j = 0; j < a.size(); j++)
		{
			if (a[i] == b[j])
			{
				if (i == j)
					zoo.bulls++;
				else
					zoo.cows++;
			}
		}
	}

	out << zoo.bulls << " " << zoo.cows;
}

int gcd(int a, int b)
{
	if (a*b == 0)return a + b;
	if (a < b) return gcd(a, b%a);
	else return gcd(a%b, b);
}

void task14(std::ifstream &in, std::ofstream &out)
{
	int a, b;
	in >> a >> b;

	out << (a * b / gcd(a, b));
}

void task15(std::ifstream &in, std::ofstream &out)
{
	int n;
	in >> n;
	int* arr = new int [n*n];
	for (int i = 0; i < n*n; i++)
		in >> arr[i];
	int counter = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (arr[i * n + j] == 1)
				counter++;
		}
	}
	out << counter;
}


struct Ladder
{
	int n; 
	std::vector <int> lvl;
	Ladder()
	{
		lvl.resize(2);
		lvl[0] = n;
		lvl[1] = 0;
	}
	void NextLvl() // надстраиваем сл уровень лестницы с +1 кубика
	{

	}
};

void task16(std::ifstream &in, std::ofstream &out)
{
	int n;
	in >> n;
	if (n < 3)
		out << 1;


}

