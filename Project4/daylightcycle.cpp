#include "daylightcycle.h"

Daylightcycle::Daylightcycle() : Jdate{ Date() }, Jrise{ getRiseD()}, Jset{ getSetD() } {
	
}


double Daylightcycle::getRiseD() {
	double Jtransit = getJtransit();

	double w = getW();

	return Jtransit - (w / 360.0);
}

double Daylightcycle::getSetD() {
	double Jtransit = getJtransit();

	double w = getW();

	return Jtransit + (w / 360.0);
}

double Daylightcycle::getJtransit() {
	double Jmean = getJmean();
	double M = getM();
	double lambda = getLambda();

	return 2451545.0 + Jmean + 0.0053*sin(M * PI / 180) - 0.0069*sin(2 * lambda * PI / 180);
}

double Daylightcycle::getW() {
	double phi = getPhi();
	double delta = getDelta();

	double ef = 0; // elevation in metres

	double extra = -2.076*sqrt(ef)/60.0;

	double a = sin((-0.833 + extra) * PI / 180);
	double b = sin(phi * PI / 180);
	double c = sin(delta * PI / 180);
	double d = cos(phi * PI / 180);
	double e = cos(delta * PI / 180);

	return acos((a - b*c)/(d*e) * PI / 180);
}

double Daylightcycle::getPhi() {
	double lw = 58.40; //latitude for linkoping

	return lw * PI / 180;
}

double Daylightcycle::getDelta() {
	double lambda = getLambda();

	double a = sin(lambda * PI / 180);
	double b = sin(23.4397 * PI / 180);

	return asin(a * b * PI / 180);
}

double Daylightcycle::getLambda() {
	double M = getM();
	double C = getC(M);

	return fmod(M + C + 180 + 102.9372, 360.0);
}

double Daylightcycle::getM() {
	double Jmean = getJmean();

	return fmod(357.5291 + 0.98560028 * Jmean, 360.0);
}

double Daylightcycle::getC(double M) {
	return 1.9148*sin(M * PI / 180) + 0.0200*sin(2*M * PI / 180) + 0.0003*sin(3*M * PI / 180);
}

double Daylightcycle::getJmean() {
	int n = getN();
	double lw = 15.61; //longitude for linkoping

	return n - (lw/360.0);
}

int Daylightcycle::getN() {
	double Jdate = getJdate();

	std::cout << "Jdate: " << std::setprecision(13) << Jdate << std::endl;

	return int(ceil(Jdate - (2451545.0 + 0.0008)));
}

double Daylightcycle::getJdate() {
	int hour = Jdate.hour;
	int minute = Jdate.minute;
	int second = Jdate.second;

	double JDN = getJDN();

	return JDN + ((hour - 12)/24.0) + ((minute)/1440.0) + ((second)/86400.0);
}

double Daylightcycle::getJDN(){ //from gregorian
	int Y = Jdate.year;
	int M = Jdate.month;
	int D = Jdate.day;

	double a = ((1461 * (Y + 4800 + (M - 14) / 12.0)) / 4.0);
	double b = ((367 * (M - 2 - 12 * ((M - 14) / 12.0))) / 12.0);
	double c = ((3 * ((Y + 4900 + ((M - 14) / 12.0)) / 100.0)) / 4.0);
	double d = (D - 32075);

	return a + b - c + d;
}