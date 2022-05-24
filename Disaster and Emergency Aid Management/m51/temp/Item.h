/* Citation and Sources...
Final Project Milestone 4
Module: Item


Name : Pratham Garg
Email : pgarg13@myseneca.ca
Student ID : 117900217
Date : 04 - 04 - 2022

I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
---------------------------------------------------------- -
---------------------------------------------------------- - */
#ifndef SDDS_Item_H
#define SDDS_Item_H
#include"Status.h"
#include"iProduct.h"
namespace sdds {
	class Item :public iProduct {
		char* m_description{};
		bool m_linear;
		double m_price;
		int m_qty;
		int m_qtyNeeded;
	protected:
		int m_sku;
		Status m_state;
		bool linear()const;
	

	public:
		void linear(bool isLinear);
		Item();
		Item(const Item& N);
		Item& operator=(const Item& N);
		~Item();
		void clear();
		std::ostream& display(std::ostream& ostr)const;
		std::ifstream& load(std::ifstream& ifstr);
		operator bool()const;
		operator double()const;
		int operator=(int qty);
		int operator+=(int qty);
		int operator-=(int qty);
		bool operator==(int sku)const;
		bool operator==(const char* description)const;
		int qty()const;
		int qtyNeeded()const;

		int readSku(std::istream& istr);
		std::ofstream& save(std::ofstream& ostr)const;
		std::istream& read(std::istream& istr);
	};

}
#endif