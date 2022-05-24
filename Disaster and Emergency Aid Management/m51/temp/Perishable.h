/* Citation and Sources...
Final Project Milestone 4
Module: Perishable


Name : Pratham Garg
Email : pgarg13@myseneca.ca
Student ID : 117900217
Date : 04 - 04 - 2022

I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
---------------------------------------------------------- -
---------------------------------------------------------- - */

#ifndef SDDS_PERISHABLE_H
#define SDDS_PERISHABLE_H
#include "Date.h"
#include"iProduct.h"
#include"Item.h"
namespace sdds {
	class Perishable :public Item {
		Date m_expiry;
		char* m_handling{};
	public:
		Perishable();
		~Perishable();
		Perishable(const Perishable& P);
		Perishable& operator=(const Perishable& P);
		operator bool()const;
		const Date& expiry()const;
		virtual int readSku(std::istream& istr);
		virtual std::ofstream& save(std::ofstream& ostr)const;
		virtual std::ifstream& load(std::ifstream& ifstr);
		virtual std::ostream& display(std::ostream& ostr)const;
		virtual std::istream& read(std::istream& istr);
	};

}
#endif