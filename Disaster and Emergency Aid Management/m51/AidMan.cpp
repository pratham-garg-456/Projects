/* Citation and Sources...
Final Project Milestone 5 part 1
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
#include <fstream>
using namespace std;

namespace sdds {

	//constructor

	AidMan::AidMan() :m_menu{ 7, "1- List Items\n2- Add Item\n3- Remove Item\n4- Update Quantity\n5- Sort\n6- Ship Items\n7- New/Open Aid Database\n---------------------------------\n" }{
	}

	//destructor

	AidMan::~AidMan() {
		for (int i = 0; i <m_noOfiProducts; i++)
		{
			delete m_ptr[i];
			m_ptr[i] = nullptr;
		}
		m_noOfiProducts = 0;
		delete [] m_fileName;
		m_fileName = NULL;
	}

	//runs the whole application. The run function exits when the user selects 0

	void AidMan::run() {
		unsigned int temp;
		do
		{
			temp = menu();
		} while (temp!=0);
		
	}

	//This function receives nothing and returns an unsigned integer that is the user's selection of an option in the main menu of the system. 

	unsigned int AidMan::menu(){
		int t_year = 0;
		int t_month = 0;
		int t_day = 0;
		unsigned int temp=0;
	
		ut.getSystemDate(&t_year, &t_month, &t_day);
		cout << "Aid Management System" << endl;
		cout << "Date: " << t_year << "/"<< std::setfill('0') << std::setw(2) << t_month << "/" << t_day << endl;
		if (m_fileName==NULL)
		{
			cout << "Data file: No file" << endl;
			cout << "---------------------------------" << endl;
			 temp= m_menu.run(false);			
			 load();
		}
		else
		{
			cout << "Data file: "<<m_fileName<< endl;
			cout << "---------------------------------" << endl;
		temp = m_menu.run(true);
			switch (temp)
			{
			case 1: list();
				break;
			case 7:
				load();
				break;
			default:
				break;
			}		
		}
		return temp;
	}

	//the save method

	void AidMan::save()const {
			if (m_fileName!=NULL)  //if the filename attribute is not null
			{
				ofstream File(m_fileName);  //Creates an ofstream object using the filename (to write into)
				for (int i = 0; i < m_noOfiProducts; i++)  // goes through the iProduct Pointers up to the number of number of iProduct Items and calls the save() of each iProduct to write them in the file.
				{
					m_ptr[i]->save(File);
					File << endl;
				}
				File.close();
			}
	}

// the load method

	void AidMan::load() {
		char filename[20];
		save(); //Saves all the already existing iProducts
		for (int i = 0; i < m_noOfiProducts; i++)  //Deallocates all the resources of the AidMan class making it ready to load new information.
		{
			delete m_ptr[i];
			m_ptr[i] = nullptr;
		}
		m_noOfiProducts = 0;
	/*	delete m_fileName;
		m_fileName = NULL;*/
		cin >> filename;
		std::ifstream File(filename);  //opens m_filename for reading in an ifstream
		if (File.is_open()) {  //if the file opening the file was successful
			ut.alocpy(m_fileName, filename);
			int i = 0;
			while (File.good()) {  //, in a loop:
				int c = File.peek();   //peeks the first character of the record to determine if the record is a Perishable item or not.
				if (c == 49)  // checks if first character is 1
				{
					m_ptr[i] = new Perishable;  //it will create a new Perishable item in the next available iProduct Pointers element.
					m_ptr[i]->load(File);
				}
				else if(c>1)
				{
					m_ptr[i] = new Item;  // it will create an Item in the next available iProduct Pointers.
					m_ptr[i]->load(File);
				}
				else
				{
					File.setstate(std::ios::failbit);
				}
				if (File.fail())
				{
				
				}
				else
				{
					i++;
					m_noOfiProducts = i;
				}			
			}
			cout << m_noOfiProducts << " records loaded!\n\n";
		}
		else {   //if opening the file was not successful
			unsigned temp;
			// show message:
			cout << "Failed to open "<<filename<<" for reading!\n";
			cout << "Would you like to create a new data file?\n";
			cout << "1- Yes!\n0- Exit\n>";
			temp = ut.getint(0, 1, "> ", NULL);
			if (temp)
			{
				ut.alocpy(m_fileName, filename);
			}
		}
	}
	
	int AidMan::list(const char* sub_desc ) {
		if (sub_desc==NULL)
		{
				cout <<" ROW |  SKU " << " | " << std::left<< setfill(' ') <<setw(35)<<"Description" << " | " << std::right << setfill(' ') << setw(4) << "Have" << " | " << std::right << setfill(' ') << setw(4) << "Need"<< " | " << " Price  | " << std::left << "Expiry" << endl;
				cout << "-----+-------+-------------------------------------+------+------+---------+-----------\n";
			for (int i = 0; i < m_noOfiProducts; i++)
			{
				m_ptr[i]->linear(true);
				cout << "   " << (i+1) << " | ";
				m_ptr[i]->display(cout) << endl;
			}
			cout << "-----+-------+-------------------------------------+------+------+---------+-----------" << endl;
			cout << "Enter row number to display details or <ENTER> to continue:" << endl;
			cout << "> ";
			cin.ignore(1000,'\n');
			int temp;
			if (cin.peek()==10)
			{
				temp = cin.get();				
			}
			else
			{
				cin >> temp;
				cin.ignore();
			}		
			if (temp==10)  //If the user presses , go back to the main menu otherwise display the selected item in a non-linear format.
			{
				cout << endl;
			}
			else
			{			
				m_ptr[temp-1]->linear(false);
				m_ptr[temp-1]->display(cout) << endl;
			}
		}
		return m_noOfiProducts;
	}
}