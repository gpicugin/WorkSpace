#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Tasks.h"
#include <math.h>
#include "../Geometry/Geometry.h"

const double E = 0.7;
const double A = 0.3;
const double Ideal = 1;

double errorFunc(double a)
{
	
	return pow((Ideal - a), 2) / 1;
}

double fDerSigm(double a)
{
	return (1 - a) * a;
}

double Round(double a, double dec)
{
	return round(a * dec) / dec;
}

double deltaO(double actual)
{
	return (Ideal - actual) * fDerSigm(actual);
}

double deltaH(double ho, double deltaPrev, double w)
{
	return fDerSigm(ho) * deltaPrev * w;
}

double gradient(double delta, double out)
{
	return delta * out;
}

double deltaW(double grad, double& dWPast)
{	
	double result =  E * grad + A * dWPast;
	dWPast = result;
	return result;
}


void forwardMove(std::ofstream& out, Matrix& i, Matrix& w1, Matrix& w2, Matrix& h1i, Matrix& h1o, Matrix& oi, Matrix& o)
{
	h1i = i * w1;

	//out << "H1I is : \n";
	//out << h1i;

	//out << "h1O is : \n";
	h1o = h1i.fSigm().Round(100);
	//out << h1o;

	//out << "Oi is : \n";
	oi = h1o * w2;
	//out << oi;

	//out << "O is : \n";
	o = oi.fSigm().Round(1000);
	out << o;

	out << "error is " << Round(errorFunc(o[0][0]), 100);
}


void backMove(std::ofstream& out, Matrix& i, Matrix& w1, Matrix& w2, Matrix& h1o, Matrix& w1d, Matrix& w2d, Matrix& o)
{
	//out << "\ndelta O is - ";

	double deltO = Round(deltaO(o[0][0]), 1000);

	//out << deltO << "\n";

	double deltaH1 = Round(deltaH(h1o[0][0], deltO, w2[0][0]), 1000);
	double deltaH2 = Round(deltaH(h1o[0][1], deltO, w2[1][0]), 1000);

	//out << "delta H1 is - " << deltaH1 << "\n";
	//out << "delta H2 is - " << deltaH2 << "\n";

	double GRADw5 = Round(gradient(deltO, h1o[0][0]), 1000);
	double GRADw6 = Round(gradient(deltO, h1o[0][1]), 1000);

	//out << "GRADw5 is - " << GRADw5 << "\n";
	//out << "GRADw6 is - " << GRADw6 << "\n";

	//out << "DeltaW5 is - " << Round(deltaW(GRADw5, w2d[0][0]), 1000) << "\n";
	//out << "DeltaW6 is - " << Round(deltaW(GRADw6, w2d[1][0]), 1000) << "\n";

	for (size_t i = 0; i < w2.m; i++)
	{
		double grad = gradient(deltO, h1o[0][i]);
		w2[i][0] += deltaW(grad, w2d[i][0]);
	}

	//out << "New W5 is - " << Round(w2[0][0], 1000) << "\n";
	//out << "New W6 is - " << Round(w2[1][0], 1000) << "\n";

	double GRADw[4];

	GRADw[0] = Round(gradient(deltaH1, i[0][0]), 1000);
	GRADw[1] = Round(gradient(deltaH2, i[0][0]), 1000);
	GRADw[2] = Round(gradient(deltaH1, i[0][1]), 1000);
	GRADw[3] = Round(gradient(deltaH2, i[0][1]), 1000);

	for (size_t i = 0; i < 4; i++)
	{		//out << "GRADw" << i << " is - " << GRADw[i] << "\n";
	}
	

	double deltW[4];

	deltW[0] = Round(deltaW(GRADw[0], w1d[0][0]), 100);
	deltW[1] = Round(deltaW(GRADw[1], w1d[0][1]), 100);
	deltW[2] = Round(deltaW(GRADw[2], w1d[1][0]), 100);
	deltW[3] = Round(deltaW(GRADw[3], w1d[1][1]), 100);

	/*out << "DeltaW1 is - " << deltW[0] << "\n";
	out << "DeltaW2 is - " << deltW[1] << "\n";
	out << "DeltaW3 is - " << deltW[2] << "\n";
	out << "DeltaW4 is - " << deltW[3] << "\n";*/

	for (size_t i = 0; i < w1.m; i++)
		for (size_t j = 0; j < w1.n; j++)
		{
			w1[i][j] += deltW[i * 2 + j];
			//out << "New W" << i * 2 + j << " is - " << w1[i][j] << "\n";
		}
}


int main() {
	std::ifstream in("../INPUT.txt");
	std::ofstream  io("../IOPUT.txt");
	std::ofstream out("../OUTPUT.txt");
	Matrix i(1, 2), w1(2,2), w2(2,1), o(1,1);
	Matrix w1d(2, 2), w2d(2, 1), h1i(1,2), h1o(1, 2), oi(1,1);
	in >> i >> w1 >> w2;

	int n = 1000;
	for (size_t j = 0; j < n; j++)
	{
		out << j + 1 << "ST PROGON\n";
		forwardMove(out, i, w1, w2, h1i, h1o, oi, o);

		out << "\n______________________________________\n";

		backMove(out, i, w1, w2, h1o, w1d, w2d, o);	

		out << "\n___________________________________END\n\n";
	}

	io << i << w1 << w2;
}