/* Citation and Sources...
Final Project Milestone 5 part 4
Module: Menu


Name : Pratham Garg
Email : pgarg13@myseneca.ca
Student ID : 117900217
Date : 10 - 04 - 2022

I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
---------------------------------------------------------- -
---------------------------------------------------------- - */
#ifndef SDDS_MENU_H
#define SDDS_MENU_H
#include"Status.h"
#include"Utils.h"

namespace sdds {
	class Menu {
		char* m_menuContent{}; //A dynamically allocated text that contains the list of options the user can select from.
		unsigned int m_noOfOptions=0; //An unsigned integer that holds the number of available options.
	public:
		Menu(unsigned int options=0, const char* menuContent=NULL);
		Menu(const Menu& M)=delete;
		Menu& operator=(const Menu& M) = delete;
		~Menu();
		unsigned int run()const;
	 };
}
#endif