/* Citation and Sources...
Final Project Milestone 5 part 4
Module: Item

Name : Pratham Garg
Email : pgarg13@myseneca.ca
Student ID : 117900217
Date : 10 - 04 - 2022

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
		char* m_description{};  //a dynamic Cstring for the description of the item.
		bool m_linear;  //a boolean flag to dictate to the display function if the next output is going to be linear to descriptive.
		double m_price;  //a double for the price of item
		int m_qty;   //an integer for quantity on hand
		int m_qtyNeeded; // target amount for the item to be acquired.
	protected:
		int m_sku;  //an integer value to hold the Stock-Keeping Unit number.
		Status m_state;    //a Status object to hold the state of the Item object
		bool linear()const;
	public:
		bool search(const char* substr)const;
		void linear(bool isLinear);
		Item();
		Item(const Item& N);
		Item& operator=(const Item& N);
		~Item();
		void clear();		
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
		std::ostream& display(std::ostream& ostr)const;
		std::ifstream& load(std::ifstream& ifstr);
		std::ofstream& save(std::ofstream& ostr)const;
		std::istream& read(std::istream& istr);
	};

}
#endif