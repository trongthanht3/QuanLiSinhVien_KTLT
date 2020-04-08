#ifndef DATE_H
#define DATE_H
#include <iostream>
#include <ctime>
#include <String>
#include "ConstString.h"
#include <fstream>

using namespace std;

class Date
{
	private:
		int month;
		int day;
		int year;
	public:
		Date();
		Date(int month, int day, int year);
		bool setDate(int month, int day, int year);
		void setDate(void);
		void userInput();
		void print(void) const;
		
		int getMonth() const;
		int getDay() const;
		int getYear() const;
		bool isEqual(const Date&) const;
		bool isLess(const Date&) const;
		bool isLeapYear(int year);
		const string& asString() const;
		void importData(fstream& dataInput, Date &temp);
//        void input(string data);
	protected:
};


inline bool Date::isEqual(const Date& tempD) const
{
	return month == tempD.month && day == tempD.day && year == tempD.year;
}

inline bool Date::isLess(const Date& tempD) const
{
	if (year != tempD.year)
		return year < tempD.year;
	else if (month != tempD.month)
		return month < tempD.month;
	else 
		return day < tempD.day;
}

inline bool Date::isLeapYear(int year)
{
	return (year%4 == 0 && year%100 == 0) || year%400 == 0;
}
#endif
