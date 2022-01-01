#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Tasks.h"
#include "../Geometry/Geometry.h"


double errorFunc(double a)
{
	
	return pow((1 - a), 2) / 1;
}

int main() {
	std::ifstream in("../INPUT.txt");
	std::ofstream out("../OUTPUT.txt");
	Matrix i(1, 2), w1(2,2), w2(2,1), o(1,1);
	
	in >> i >> w1 >> w2;	

	Matrix h1i = i * w1;

	out << h1i;

	Matrix h1o = h1i.fSigm().Round();

	out << h1o;

	Matrix oi = (h1o * w2).Round();

	out << oi;

	o = oi.fSigm().Round();

	std::cout << o[0][0] << " " << errorFunc(o[0][0]);

	out << o;
}