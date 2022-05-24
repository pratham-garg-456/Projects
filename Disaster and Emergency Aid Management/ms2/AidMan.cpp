/* Citation and Sources...
Final Project Milestone 2
Module: AidMan


Name : Pratham GargEmail: pgarg13@myseneca.ca
Student ID : 117900217
Date : 22 - 03 - 2022

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
#include "AidMan.h"
using namespace std;

namespace sdds {

	AidMan::AidMan() :m_menu{ 7, "1- List Items\n2- Add Item\n3- Remove Item\n4- Update Quantity\n5- Sort\n6- Ship Items\n7- New/Open Aid Database\n---------------------------------\n" }{


	}
	AidMan::~AidMan() {
		delete m_fileName;
		m_fileName = NULL;
	}
	void AidMan::run()const {
		unsigned int temp;
		do
		{
			temp = menu();
		} while (temp!=0);
		
	}
	unsigned int AidMan::menu()const{
		int t_year = 0;
		int t_month = 0;
		int t_day = 0;
		ut.getSystemDate(&t_year, &t_month, &t_day);
		cout << "Aid Management System Version 0.1" << endl;
		cout << "Date: " << t_year << "/"<< std::setfill('0') << std::setw(2) << t_month << "/" << t_day << endl;
		if (m_fileName==NULL)
		{
			cout << "Data file: No file" << endl;
		}
		else
		{
			cout << "Data file : "<<m_fileName<<".csv" << endl;
		}
	
		cout << "---------------------------------"<<endl;
	unsigned int temp =m_menu.run();
		return temp;
	}
	

}