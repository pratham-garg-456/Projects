/* Citation and Sources...
Final Project Milestone 5 part 1
Module: Menu


Name : Pratham Garg
Email : pgarg13@myseneca.ca
Student ID : 117900217
Date : 06 - 03 - 2022

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
		/*	m_menuContent = new char[strlen(menuContent) + 1];
			strcpy(m_menuContent, menuContent);*/
		}
	}

	//destructor

	Menu::~Menu() {
		delete[]m_menuContent;
		m_menuContent = nullptr;
	}

	//This method receives nothing and returns an unsigned integer and will not change the state of the Menu object.

	unsigned int Menu::run(bool isFile)const {
		unsigned int temp;		
		cout << m_menuContent;
		cout << "0- Exit\n";
			temp=ut.getint(0, m_noOfOptions, "> ", NULL);
			if (!isFile)
			{
				temp = 7;
			}
			switch (temp)
			{
			case 1:cout << "\n****List Items****\n";
				break;
			case 2:cout << "\n****Add Item****\n\n";
				break;
			case 3:cout << "\n****Remove Item****\n\n";
				break;
			case 4:cout << "\n****Update Quantity****\n\n";
				break;
			case 5:cout << "\n****Sort****\n\n";
				break;
			case 6:cout << "\n****Ship Items****\n\n";
				break;
			case 7:
				cout << "\n****New/Open Aid Database****\n"; 
				cout << "Enter file name: ";
				break;
			case 0:
				cout << "Exiting Program!\n"; 			
				break;			
					default:
				break;
			}		
		return temp;
	}
}