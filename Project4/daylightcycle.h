#pragma once

#include "date.h"

#include <iostream>

#define PI 3.14159265

class Daylightcycle
{
public:
	Daylightcycle();

	friend std::ostream& operator<<(std::ostream& os, const Daylightcycle& dc) {
		os << "On the date " << dc.Jdate << " there is a sunrise at " << dc.Jrise << " and a sunset at " << dc.Jset;
		return os;
	}

	Date Jdate;
	Date Jrise;
	Date Jset;

private:
	double getRiseD();

	double getSetD();

	double getJtransit();

	double getW();

	double getPhi();

	double getDelta();

	double getLambda();

	double getM();

	double getC(double M);

	double getJmean();

	int getN();

	double getJdate();

	double getJDN();
};