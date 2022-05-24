/* Citation and Sources...
Final Project Milestone 5 part 2
Module: Menu

Name : Pratham Garg
Email : pgarg13@myseneca.ca
Student ID : 117900217
Date : 08 - 04 - 2022

I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
---------------------------------------------------------- -
---------------------------------------------------------- - */

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <iomanip>
#include <cstring>
#include <ctime>
#include "Menu.h"
using namespace std;
namespace sdds {

	//constructor

	Menu::Menu (unsigned int options,const char* menuContent) {		
		if (options>15||menuContent==NULL)
		{
			//setInvalid();
		}
		else
		{		
			m_noOfOptions = options;
			ut.alocpy(m_menuContent, menuContent);
		}
	}

	//destructor

	Menu::~Menu() {
		delete[]m_menuContent;
		m_menuContent = nullptr;
	}

	//This method receives nothing and returns an unsigned integer and will not change the state of the Menu object.

	unsigned int Menu::run()const {
		unsigned int temp;		
		cout << m_menuContent;
		cout << "0- Exit\n";
		temp=ut.getint(0, m_noOfOptions, "> ", NULL);
		return temp;
	}
}