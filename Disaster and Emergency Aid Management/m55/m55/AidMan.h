/* Citation and Sources...
Final Project Milestone 5 part 5
Module: AidMan

Name : Pratham Garg
Email: pgarg13@myseneca.ca
Student ID : 117900217
Date : 10 - 04 - 2022

I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
---------------------------------------------------------- -
---------------------------------------------------------- - */

#ifndef SDDS_AIDMAN_H
#define SDDS_AIDMAN_H
#include"Status.h"
#include"Utils.h"
#include "Menu.h"
#include"iProduct.h"
#include "Perishable.h"
#include"Item.h"

namespace sdds {
	const int sdds_max_num_items = 100;
	class AidMan{
		iProduct* m_ptr[sdds_max_num_items];  //an array of sdds_max_num_items iProduct Pointers
		int m_noOfiProducts=0;  //an integer to keep track of the number of iProduct Items pointed by the iProduct pointers.
		char* m_fileName{}; //Dynamically holding the name of a data file holding the aid and product information.
		Menu m_menu; //A Menu object.
		unsigned int menu();
	public:
		AidMan();
		AidMan(const AidMan& A) = delete;
		AidMan& operator=(const AidMan& A) = delete;
		~AidMan();
		int list(const char* sub_desc = nullptr);
		int addItem();
		void run();
		void save()const;
		void load();
		int search(int sku) const;
		void remove(int index);
		void removeItem(); 
		void updateQuantity();
		void sort();
		int qtyDiffQtyneeded(int index);
	};

}
#endif