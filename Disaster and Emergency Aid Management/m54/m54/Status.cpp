/* Citation and Sources...
Final Project Milestone 5 part 4
Module: Status


Name : Pratham Garg
Email : pgarg13@myseneca.ca
Student ID : 117900217
Date : 10 - 04 - 2022

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
#include"Utils.h"
using namespace std;
namespace sdds {

	// constructor

	Status::Status(const char* desc)
	{
		set(desc, 0);
	}

	//destructor 

	Status::~Status()
	{
		delete[] m_desc;
		m_desc = nullptr;
	}

	// function to reallocate and copy the Stauts class data members

	void Status::reallocateandcopy(const char* des, int code) {

		ut.alocpy(m_desc, des);
		m_code = code;
	}

	// to set the description an code of Status object

	void Status::set(const char* desc, int code) {
		if (desc != nullptr)
		{
			reallocateandcopy(desc, code);
			
		}
		else
		{
			delete[] m_desc;
			m_desc = nullptr;
		}
	}

	// copy constructor

	Status::Status(const Status& S) {
		if (!S)
		{
			*this = S;
		}
	}

	// copy assignment operator for casting status object to constant character pointer

	Status& Status:: operator=(const char* desc) {
		if (m_desc != desc)
		{
			if (validName(desc)) {
				ut.alocpy(m_desc, desc);
			}
			else
			{
				delete[] m_desc;
				m_desc = nullptr;
			}
		}
		return *this;
	}

	//copy assignment operator for casting a status object to an integer

	Status& Status:: operator=(int code) {
		if (m_code != 0)
		{
			m_code = 0;
		}
		m_code = code;
		return *this;
	}

	// boolean conversion overload to cast status to boolean

	Status::operator bool() const {
		return (m_desc == NULL);
	}

	// query to return the code

	Status::operator int() const {
		return m_code;
	}

	//query to return the description

	Status::operator const char* ()const {
		return m_desc;
	}

	// function to check if the description is valid or not

	bool Status::validName(const char* desc) {
		return desc != nullptr;
	}

	//safely deallocates the description and sets the code to zero. This method will return a reference to the current object at the end.

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

	// helper insertion operator overload to print a Status object using ostream.

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

	//function to print the description of status

	std::ostream& Status::print(std::ostream& ostr) const {
		ostr << m_desc;
		return ostr;
	}

}