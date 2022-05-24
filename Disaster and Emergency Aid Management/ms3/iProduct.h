/* Citation and Sources...
Final Project Milestone 3
Module: iProduct


Name : Pratham Garg
Email : pgarg13@myseneca.ca
Student ID : 117900217
Date : 30 - 03 - 2022

I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
---------------------------------------------------------- -
---------------------------------------------------------- - */

#ifndef SDDS_iProduct_H
#define SDDS_iProduct_H
#include "Status.h"
namespace sdds {

	class iProduct {
		
	public:
		virtual ~iProduct()=0;
		virtual std::ostream& display(std::ostream& ostr)const=0;
		virtual void linear(bool isLinear)=0;
		virtual operator bool()const=0;
		virtual operator double()const=0;
		virtual int operator+=(int qty)=0;
		virtual int operator-=(int qty)=0;
		virtual bool operator==(int sku)const=0;
		virtual bool operator==(const char* description)const=0;
		virtual int qty()const=0;
		virtual int qtyNeeded()const=0;
		
		virtual int readSku(std::istream& istr)=0;
		virtual std::ofstream& save(std::ofstream& ofstr)const=0;
		virtual std::istream& read(std::istream& istr)=0;
		virtual std::ifstream& load(std::ifstream& ifstr)=0;
	};
	std::ostream& operator<<(std::ostream& ostr, const iProduct& D);
	std::istream& operator>>(std::istream& istr, iProduct& D);

}
#endif