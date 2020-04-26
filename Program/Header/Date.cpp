#include "Date.h"
#include <iostream>
#include <ctime>
#include <sstream>
#include <iomanip>

using namespace std;

Date::Date()
{
	this->day = 1;
	this->month = 1;
	this->year = 1;
}

Date::Date(int month, int day, int year)
{
	if (!setDate(month, day, year))		//check valid date
		this->month = this->day = this->year = 1;
}

void Date::setDate()
{
	struct tm *ptr;
	time_t times;
	time(&times);

	ptr = localtime(&times);
	
	this->month = ptr->tm_mon+1;
	this->day = ptr->tm_mday;
	this->year = ptr->tm_year+1900;
}

bool Date::setDate(int month, int day, int year)
{
	if (month < 1 || month > 12)
		return false;
	if (day < 1 || day > 31)
		return false;
	switch (month)
	{
		case 2:
			if (isLeapYear(year)) {
				if (day > 29)
					return false;
			}
			else if (day > 28)
				return false;
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			if (day > 30)
				return false;
	}
	this->month = month;
	this->day = day;
	this->year = year;
	return true;
}

void Date::userInput()
{
	int day, month, year;
	do {
        cin >> day >> month >> year;
        if (!setDate(month, day, year))
            cout << ConstString::nhapsai;
	} while (!setDate(month, day, year));
}

void Date::print() const 
{
	cout << asString();
}

int Date::getMonth() const
{
	return this->month;
}
int Date::getDay() const
{
	return this->day;
}
int Date::getYear() const
{
	return this->year;
}

const string& Date::asString() const
{
	static string str;
	stringstream iostream;
	
	iostream << day << "/" << month << "/" << year;
	iostream >> str;
	return str;
}

void Date::importData(fstream &dataInput, Date &temp)
{
    dataInput >> day;
    dataInput >> month;
    dataInput >> year;
}



















