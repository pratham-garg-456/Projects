/* Citation and Sources...
Final Project Milestone 5 part 4
Module: iProduct

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
#include <fstream>

#include"iProduct.h"
using namespace std;
namespace sdds {

	iProduct::~iProduct() {
	}
	std::ostream& operator<<(std::ostream& ostr, const iProduct& D) {
		D.display(ostr);
		return ostr;
	}
	std::istream& operator>>(std::istream& istr, iProduct& D) {
		D.read(istr);
		return istr;
	}

}