/* Citation and Sources...
Final Project Milestone 4
Module: Status


Name : Pratham Garg
Email : pgarg13@myseneca.ca
Student ID : 117900217
Date : 04 - 04 - 2022

I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
---------------------------------------------------------- -
---------------------------------------------------------- - */
#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <string>
#include <iomanip>
#include <cstring>
#include "Status.h"
using namespace std;
namespace sdds {
	Status::Status(const char* desc)
	{
		set(desc, 0);
	}

	Status::~Status()
	{
		delete[] m_desc;
		m_desc = nullptr;
	}

	void Status::reallocateandcopy(const char* des, int code) {
		delete[] m_desc;
		m_desc = nullptr;
		m_desc = new char[strlen(des) + 1];
		strcpy(m_desc, des);
	}

	void Status::set(const char* desc, int code) {
		if (desc != nullptr)
		{
			reallocateandcopy(desc, code);
			m_code = code;
		}
		else
		{
			delete[] m_desc;
			m_desc = nullptr;
		}

	}
	Status::Status(const Status& S) {
		if (!S)
		{
			*this = S;
		}
	}
	Status& Status:: operator=(const char* desc) {
		if (m_desc != desc)
		{
			if (validName(desc)) {
				if (m_desc != nullptr)
				{
					delete[] m_desc;
					m_desc = nullptr;
				}

				m_desc = new char[strlen(desc) + 1];
				strcpy(m_desc, desc);
			}
			else
			{
				delete[] m_desc;
				m_desc = nullptr;
			}
		}
		return *this;
	}
	Status& Status:: operator=(int code) {
		if (m_code != 0)
		{
			m_code = 0;
		}
		m_code = code;
		return *this;
	}
	Status::operator bool() const {
		return (m_desc == NULL);
	}
	Status::operator int() const {
		return m_code;
	}
	Status::operator const char* ()const {
		return m_desc;
	}
	bool Status::validName(const char* desc) {
		return desc != nullptr;
	}
	Status& Status::clear() {
		if (m_desc != nullptr)
		{
			m_desc = nullptr;
		}
		delete[] m_desc;
		m_desc = nullptr;
		m_code = 0;
		return *this;
	}
	ostream& operator<<(ostream& ostr, const Status& S) {
		if (!S)
		{
			if (int(S) != 0)
			{
				ostr << "ERR#" << int(S) << ": ";
				S.print(ostr);
			}
			else
			{
				S.print(ostr);
			}
		}
		return ostr;
	}

	std::ostream& Status::print(std::ostream& ostr) const {
		ostr << m_desc;
		return ostr;
	}

}