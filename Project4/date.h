#pragma once

#include <vector>
#include <iostream>
#include <chrono>
#include <fstream>
#include <iomanip>


class Date
{
public:
	Date(double juliandate = 0);

	std::vector<int> getDate();

	std::vector<int> getConvertedJulian(double juliandate);

	void setDate(double juliandate = 0);

	friend std::ostream& operator<<(std::ostream& os, const Date& dt) {
		os << dt.year << '/' << std::setw(2) << std::setfill('0') << dt.month << 
			'/' << std::setw(2) << std::setfill('0') << dt.day << 
			", " << std::setw(2) << std::setfill('0') <<  dt.hour << 
			":" << std::setw(2) << std::setfill('0') << dt.minute << 
			"." << std::setw(2) << std::setfill('0') << dt.second;
		return os;
	}

	int year, month, day, hour, minute, second;
};