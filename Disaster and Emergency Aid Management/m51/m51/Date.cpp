/* Citation and Sources...
Final Project Milestone 5 part 1
Module: Date

Name : Pratham Garg
Email : pgarg13@myseneca.ca
Student ID : 117900217
Date : 06 - 04 - 2022

I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
---------------------------------------------------------- -
---------------------------------------------------------- - */
#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <iomanip>
#include <cstring>
#include "Date.h"

using namespace std;
namespace sdds {

	//constructor

	Date::Date(int year, int month, int day) {
		if (year != 0 && month != 0 && year != 0)
		{
			m_day = day;
			m_month = month;
			m_year = year;
		}
		else
		{
			ut.getSystemDate(&year, &month, &day);
			m_day = day;
			m_month = month;
			m_year = year;
		}
	}

	// copy constructor

	Date::Date(const Date& P) {
		*this = P;
	}

	// assignment operator overload to set the Formatted flag (attribute) of the Date.

	Date& Date::operator=(bool b) {
		Formatted = b;
		return *this;
	}

	//copy assignment operator

	Date& Date::operator=(const Date& P) {
		if (this != &P)
		{
			m_day = P.m_day;
			m_month = P.m_month;
			m_year = P.m_year;
			Formatted = P.Formatted;
		}
		return*this;
	}

	//This function validates the year, month and day, if the date is valid the function returns true or false if any of the validations have failed.

	bool Date::validate() {
		bool flag = false;
		time_t t = std::time(NULL);
		tm lt = *localtime(&t);
		int t_year = lt.tm_year + 1900;
		if (m_year == 0 && m_day == 0 && m_month == 0) {
			State = "Invalid date value";
			State = 0;
		}
		else if (m_year > MaxYearValue || m_year < t_year)
		{
			State = "Invalid year in date";
			State = 1;
		}
		else if (m_month < 1 || m_month>12)
		{
			State = "Invalid month in date";
			State = 2;
		}
		else if (m_day<1 || m_day>ut.daysOfMon(m_month, m_year))
		{
			State = "Invalid day in date";
			State = 3;
		}
		else {
			State.clear();
			flag = true;
		}
		return flag;
	}

	// a method to return a unique integer value tied to the date. Use this value to compare two dates

	int Date::unique()const {
		int uniqueNum = (m_year * 372) + (m_month * 31) + m_day;
		return uniqueNum;
	}

	//an accessor method called state that returns a constant reference to the State of the Date.

	const Status& Date::state() {
		return State;
	}

	// a modifier method called formatted to set the Formatted flag (attribute) of the Date.
	//This method return the reference of the current object.

	Date& Date::formatted(bool informat) {
		Formatted = informat;
		return *this;
	}

	// the Date object is casted to a boolean, the state of the date object is returned.

	Date::operator bool() const {
		return State;
	}

	// a method that receives and returns a reference of the istream object from which it extracts the date value 

	istream& Date::read(istream& istr) {
		int temp = 0;
		istr >> temp;
		int t_year = 0;
		int t_month = 0;
		int t_day = 0;
		ut.getSystemDate(&t_year, &t_month, &t_day); // get the system date
	
		if (temp <= 9999 && temp >= 1000)
		{
			m_year = t_year;
			m_month = temp / 100;
			m_day = temp % 100;
		}
		else if (temp <= 999999 && temp >= 100000) {
			m_year = int(temp / 10000) + 2000;
			m_month = (temp % 10000) / 100;
			m_day = (temp % 10000) % 100;
		}
		else if (temp < 99 && temp>10)
		{
			m_day = temp;
			m_year = t_year;
			m_month = 0;
		}
		else
		{
			m_year = 0;
			m_month = 0;
			m_day = 0;
		}
		if (validate())
		{
		}
		else {
			istr.setstate(ios::badbit); // if not valid set to bad state
		}
		return istr;
	}

	//a method that receives and returns a reference of the ostream object in which it inserts the date value

	std::ostream& Date::write(std::ostream& ostr)const {
		int t_year;
		int t_month;
		int t_day;
		ut.getSystemDate(&t_year, &t_month, &t_day);
		if (Formatted)// if true print the date as YYYY/MM/DD 
		{
			if (m_year <= MaxYearValue && m_year >= t_year && m_month >= 1 && m_month <= 12 && m_day >= 1 && m_day <= 31) {
				ostr << m_year << "/" << std::setfill('0') << std::setw(2) << m_month << "/" << m_day;
			}
		}
		else // false to print it as YYMMDD.
		{
			ostr << (m_year - 2000) << std::setfill('0') << std::setw(2) << m_month << m_day;
		}
		return ostr;
	}

	// Operator overload for comaprison 

	bool operator==(const Date& left, const Date& right) {
		return left.unique() == right.unique();
	}

	// Operator overload for comaprison 

	bool operator!=(const Date& left, const Date& right) {
		return left.unique() != right.unique();
	}

	// Operator overload for comaprison 

	bool operator<(const Date& left, const Date& right) {
		return left.unique() < right.unique();
	}

	// Operator overload for comaprison 

	bool operator>(const Date& left, const Date& right) {
		return left.unique() > right.unique();
	}

	// Operator overload for comaprison 

	bool operator<=(const Date& left, const Date& right) {
		return left.unique() <= right.unique();
	}

	// Operator overload for comaprison 

	bool operator>=(const Date& left, const Date& right) {
		return left.unique() >= right.unique();
	}

	//insertion operator overload to write date object to ostream

	std::ostream& operator<<(std::ostream& ostr, const Date& D) {
		if (D)
		{
			D.write(ostr);
		}
		else
		{
			ostr << "Bad Date";
		}
		return ostr;
	}

	// extraction operator overload to read date object from istream

	std::istream& operator>>(std::istream& istr, Date& D) {
		D.read(istr);
		return istr;
	}
}