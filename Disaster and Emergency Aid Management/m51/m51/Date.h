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
#ifndef SDDS_DATE_H
#define SDDS_DATE_H
#include"Status.h"
#include"Utils.h"

namespace sdds {
	const int MaxYearValue = 2030;
	class Date
	{
		int m_year = 0; //an integer between the current year the maximum year value.
		int m_month = 0; //an integer between 1 and 12
		int m_day = 0; // an integer between 1 and the number of days in the month based on the year.
		Status State; //a Status object that holds the validity status of date.
		bool Formatted = true; // boolean value that is set to true to print the date as YYYY/MM/DD or false to print it as YYMMDD.

	public:
		Date& operator=(bool b);
		Date(const Date& P);
		Date& operator=(const Date& P);
		Date(int year = 0, int month = 0, int day = 0);
		bool validate();
		int unique()const;
		const Status& state();
		Date& formatted(bool informat);
		operator bool() const;
		std::istream& read(std::istream& istr);
		std::ostream& write(std::ostream& ostr)const;

	};
	bool operator==(const Date& left, const Date& right);
	bool operator!=(const Date& left, const Date& right);
	bool operator<(const Date& left, const Date& right);
	bool operator>(const Date& left, const Date& right);
	bool operator<=(const Date& left, const Date& right);
	bool operator>=(const Date& left, const Date& right);

	std::ostream& operator<<(std::ostream& ostr, const Date& D);
	std::istream& operator>>(std::istream& istr, Date& D);
}
#endif