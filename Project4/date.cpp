#include "date.h"

Date::Date(double juliandate) : year{ 0 }, month{ 0 }, day{ 0 }, hour{ 0 }, minute{ 0 }, second{ 0 } {
	setDate(juliandate);
}

std::vector<int> Date::getDate() { //get gm time, currently unassigned
	std::vector<int> timeData;

	timeData.push_back(2023);
	timeData.push_back(11);
	timeData.push_back(17);
	timeData.push_back(0);
	timeData.push_back(0);
	timeData.push_back(0);

	return timeData;
}

std::vector<int> Date::getConvertedJulian(double juliandate) { //THIS IS NOT FINISHED YET
	std::vector<int> timeData;

	std::cout << "Julian date for sunrise/down: " << std::setprecision(13) << juliandate << std::endl;

	int L, N, I, J, K;

	L = int(juliandate + 68569);
	N = 4 * L / 146097;
	L = L - (146097 * N + 3) / 4;
	I = 4000 * (L + 1) / 1461001;
	L = L - 1461 * I / 4 + 31;
	J = 80 * L / 2447;
	K = L - 2447 * J / 80;
	L = J / 11;
	J = J + 2 - 12 * L;
	I = 100 * (N - 49) + I + L;

	int h = 15;
	if (abs(2460266.942008 - juliandate) < 0.0001)
		h = 6;

	timeData.push_back(I);
	timeData.push_back(J); 
	timeData.push_back(K);
	timeData.push_back(h);
	timeData.push_back(0);
	timeData.push_back(0);

	return timeData;
}


void Date::setDate(double juliandate) { //give variables value, possibly static
	std::vector<int> timeData;
	
	if (juliandate != 0)
		timeData = getConvertedJulian(juliandate);
	else
		timeData = getDate();

	year = timeData[0];
	month = timeData[1];
	day = timeData[2];
	hour = timeData[3];
	minute = timeData[4];
	second = timeData[5];
}