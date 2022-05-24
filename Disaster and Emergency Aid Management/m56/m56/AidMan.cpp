/* Citation and Sources...
Final Project Milestone 5 part 6
Module: AidMan

Name : Pratham Garg
Email: pgarg13@myseneca.ca
Student ID : 117900217
Date : 10 - 04 - 2022

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
#include <cstdlib>
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

	unsigned int AidMan::menu() {
		int t_year = 0;
		int t_month = 0;
		int t_day = 0;
		unsigned int temp = 0;
		ut.getSystemDate(&t_year, &t_month, &t_day);
		cout << "Aid Management System" << endl;
		cout << "Date: " << t_year << "/" << std::setfill('0') << std::setw(2) << t_month << "/" << t_day << endl;
		if (m_fileName == NULL)
		{
			cout << "Data file: No file" << endl;
			cout << "---------------------------------" << endl;
			temp = m_menu.run();
			temp = 7;			
		}
		else
		{
			cout << "Data file: " << m_fileName << endl;
			cout << "---------------------------------" << endl;
			temp = m_menu.run();
		}
		switch (temp)
			{
			case 1:
				cout << "\n****List Items****\n";
				list();
				break;
			case 2:cout << "\n****Add Item****\n";
				addItem();
				cout << endl;
				save();
				break;
			case 3:cout << "\n****Remove Item****\n";
				removeItem();
				break;
			case 4:cout << "\n****Update Quantity****\n";
				updateQuantity();
				break;
			case 5:cout << "\n****Sort****\n";
				sort();
				break;
			case 6:cout << "\n****Ship Items****\n";
				ship();
				break;
			case 7:
				cout << "\n****New/Open Aid Database****\n";
				cout << "Enter file name: ";
				load();
				break;
			case 0:
				cout << "Exiting Program!\n";
				save();
				break;
			default:
				break;			
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

		cin >> filename;
		std::ifstream File(filename);  //opens m_filename for reading in an ifstream

		if (File.is_open()) {  //if the file opening the file was successful

			ut.alocpy(m_fileName, filename);
			int i = 0;
			while (File.good()) {  //, in a loop:
				int c = File.peek();   //peeks the first character of the record to determine if the record is a Perishable item or not.
				if (c >= 49&&c<=51)  // checks if first character is 1, 2 and 3  for perishable
				{
					m_ptr[i] = new Perishable;  //it will create a new Perishable item in the next available iProduct Pointers element.
					m_ptr[i]->load(File);
				}
				else if(c>51&&c<=57)
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
			File.clear();
		}
		else {   //if opening the file was not successful
			unsigned temp;
			// show message:
			cout << "Failed to open "<<filename<<" for reading!\n";
			cout << "Would you like to create a new data file?\n";

			Menu menu = { 1, "1- Yes!\n" };			
			temp = menu.run();
			if (temp)
			{
				ut.alocpy(m_fileName, filename);
			}
		}
	}
	
	// list all the items

	int AidMan::list(const char* sub_desc ) {
		int count = 0;
		cout << " ROW |  SKU " << " | " << std::left << setfill(' ') << setw(35) << "Description" << " | " << std::right << setfill(' ') << setw(4) << "Have" << " | " << std::right << setfill(' ') << setw(4) << "Need" << " | " << " Price  | " << std::left << "Expiry" << endl;
		cout << "-----+-------+-------------------------------------+------+------+---------+-----------\n";
		if (sub_desc==NULL)
		{

			for (int i = 0; i < m_noOfiProducts; i++)
			{
				m_ptr[i]->linear(true);
				cout << "   " << (i+1) << " | ";
				m_ptr[i]->display(cout) << endl;
				count++;
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
			if (temp==10)  //If the user presses enter , go back to the main menu otherwise display the selected item in a non-linear format.
			{
				cout << endl;
			}
			else
			{			
				m_ptr[temp-1]->linear(false);
				m_ptr[temp-1]->display(cout) << endl;
			}
		}
		else
		{
			for (int i = 0; i < m_noOfiProducts; i++)
			{
				if (m_ptr[i]->search(sub_desc))
				{
					m_ptr[i]->linear(true);
					cout << "   " << (i + 1) << " | ";
					m_ptr[i]->display(cout) << endl;
					count++;
				}
			
			}
			cout << "-----+-------+-------------------------------------+------+------+---------+-----------" << endl;

		}
		return count;
	}

	//Loops through all the iProduct Pointers elements and if the SKU is a match it will return the index, otherwise it will return -1

	int AidMan::search(int sku) const {
		int index = -1;
		bool flag = true;
		for (int i = 0; i < m_noOfiProducts&&flag; i++)
		{
			if (*m_ptr[i] == sku)
			{
				index = i;
				flag = false;
			}
			else
			{
				index = -1;
			}
		}
		return index;
	}

	//Function to allocate  a Perishable or Non-Perishable Item Based on the user's entry in an iProduct pointer.

	int AidMan::addItem() {
		unsigned temp=0;
		if ((m_noOfiProducts<sdds_max_num_items))
		{
			Menu menu = { 2,"1- Perishable\n2- Non-Perishable\n-----------------\n" };
			temp=menu.run();
			if (temp!=0)
			{ 
				if (temp==1)//if perishable is selected
				{
					m_ptr[m_noOfiProducts] = nullptr;
					m_ptr[m_noOfiProducts] = new Perishable;
					int sku = m_ptr[m_noOfiProducts]->readSku(cin);
					if (search(sku) < 0)
					{
						m_ptr[m_noOfiProducts]->read(cin);
						if (cin.fail())
						{
							m_ptr[m_noOfiProducts]->display(cout);
							delete m_ptr[m_noOfiProducts];
							m_ptr[m_noOfiProducts] = nullptr;
						}
						else
						{
							m_noOfiProducts++;
						}
					}
					else
					{
						cout << "Sku: " << sku << " is already in the system, try updating quantity instead.\n";
						delete m_ptr[m_noOfiProducts];
						m_ptr[m_noOfiProducts] = nullptr;
					}
				}			
				else//if non-perishable is selected
				{
					m_ptr[m_noOfiProducts] = nullptr;
					m_ptr[m_noOfiProducts] = new Item;
					int sku = m_ptr[m_noOfiProducts]->readSku(cin);
					if (search(sku) < 0)
					{
						m_ptr[m_noOfiProducts]->read(cin);
						if (cin.fail())
						{
							m_ptr[m_noOfiProducts]->display(cout);
							delete m_ptr[m_noOfiProducts];
							m_ptr[m_noOfiProducts] = nullptr;
						}
						else
						{
							m_noOfiProducts++;
						}
					}
					else
					{
						cout << "Sku: " << sku << " is already in the system, try updating quantity instead.\n";
						delete m_ptr[m_noOfiProducts];
						m_ptr[m_noOfiProducts] = nullptr;
					}
				}				
			}				
			else
			{
				cout << "Aborted\n";
			}				
		}
		else// no more space to add items
		{
			cout << "Database full!" << endl;
		}
		return temp;
	}

	// function to remove the iproduct pointer at the passed index from the object

	void AidMan::remove(int index) {
		delete m_ptr[index];  // delete iProduct at the index in iProduct Pointers
		m_ptr[index] = nullptr;
		for (int i = index; i < m_noOfiProducts-1; i++)//to shif all the iProducts to left once 
		{
			m_ptr[i] = m_ptr[i + 1];

		}
		m_ptr[m_noOfiProducts-1]=nullptr;
		m_noOfiProducts--;
		 // reduce the no of iProduct items by one


	}

	//function to remove the item

	void AidMan::removeItem() {
		bool flag=true;
		int temp=0;
		string str;
		int sku=0;
		cout << "Item description: ";
		cin.ignore();
		getline(cin, str, '\n');
		if (list(str.c_str())>0)// it the inputed substring found in description then =true
		{
			cout << "Enter SKU: ";
			cin >> sku;
			for (int i = 0; i < m_noOfiProducts&&flag; i++)
			{
				if (m_ptr[i]->search(str.c_str()))
				{
					if (*m_ptr[i] == sku)
					{
						cout << "Following item will be removed: " << endl;
						m_ptr[i]->linear(false);
						m_ptr[i]->display(cout) << endl;  // display the items to be removed
						cout << "Are you sure?" << endl;
						Menu menu = { 1, "1- Yes!\n" };
						temp = menu.run();
						if (temp)
						{
							remove(i);  // remove the item 
							cout << "Item removed!" << endl << endl;
							flag = false;
						}
						else
						{
							flag = false;
							cout << "Aborted!\n\n";
						}
						
					}
				
				}

			}
			
		}

	}
	void AidMan::updateQuantity() {
		bool flag = true;
		int temp = 0;
		string str; 
		int sku = 0;
		cout << "Item description: ";
		cin.ignore();
		getline(cin, str, '\n');  //receives a sub-description from the user dynamically.
		if (list(str.c_str()) > 0)// it the inputed substring found in description
		{
			cout << "Enter SKU: ";
			cin >> sku;
			for (int i = 0; i < m_noOfiProducts && flag; i++)
			{
				if (m_ptr[i]->search(str.c_str()))     //  search for the SKU to find the index of the iProcuct in the iProduct Pointers.
				{
					if (*m_ptr[i] == sku)  //If a match is found
					{
						flag = false;
						Menu menu = { 2, "1- Add\n2- Reduce\n" };
						temp = menu.run();
						switch (temp)
						{
						case 1:
							if (m_ptr[i]->qtyNeeded()!=m_ptr[i]->qty())
							{
								int toadd = ut.getint(1, m_ptr[i]->qtyNeeded(), "Quantity to add: ", NULL, cin);      // fool-proof quantity value is received from 1 up to the maximum amount needed to fulfill the needed quantity 
								 *m_ptr[i] += toadd;   //the quantity is increased by the entered amount.
								cout << toadd << " items added!\n\n";
							}
							else
							{
								cout << "Quantity Needed already fulfilled!\n\n";
							}
							
							break;
						case 2:
							if (m_ptr[i]->qty()!=0)
							{
								int toreduce = ut.getint(1, m_ptr[i]->qty(), "Quantity to reduce: ", NULL, cin);    //fool-proof quantity value is received from 1 up to the quantity on hand
								*m_ptr[i] -= toreduce; //the quantity is reduced by the entered amount.
								cout << toreduce << " items removed!\n\n";
							}
							else
							{
								cout << "Quaintity on hand is zero!\n\n";
							}
						
							break;
						default:
							
							cout << "Aborted!\n\n";
							break;
						}
		
					}
					else   //If a match is not found for sku
					{
						cout << "SKU not found!\n\n";
						flag = false;
					}

				}

			}
		}
		else  //If a match is not found for substring in description
		{
			cout << "No matches found!\n\n";
		}

	}

	//function to sort the array of iProduct pointers

	void AidMan::sort() {

			iProduct* temp;					
				for (int i = 0; i < m_noOfiProducts; i++)
					{
						for (int j = 0; j <= m_noOfiProducts - i - 2; j++) {
							if (qtyDiffQtyneeded(j) < qtyDiffQtyneeded(j + 1))
							{
								temp = m_ptr[j];
								m_ptr[j] = m_ptr[j + 1];
								m_ptr[j + 1] = temp;
							}
					
						}
				}
				cout << "Sort completed!" << endl << endl;
	}

	//function to calculate the difference between quantity on hand and quantity needed

	int AidMan::qtyDiffQtyneeded(int index)const {  
			int diff = std::abs(m_ptr[index]->qty() - m_ptr[index]->qtyNeeded());
			return diff;
	}

	//loop through all the iProduct Pointers elements and if the quantity needed and quantity on hand of the product is a match print it in the linear format into the file and remove it from the iProduct Pointers array.

	void AidMan::ship() {
		int t_year = 0;
		int t_month = 0;
		int t_day = 0;
		int shipped=0;
		ut.getSystemDate(&t_year, &t_month, &t_day);
		ofstream File("shippingOrder.txt");
		File<<"Shipping Order, Date: " << t_year << "/" << std::setfill('0') << std::setw(2) << t_month << "/" << t_day << endl;
		File<< " ROW |  SKU " << " | " << std::left << setfill(' ') << setw(35) << "Description" << " | " << std::right << setfill(' ') << setw(4) << "Have" << " | " << std::right << setfill(' ') << setw(4) << "Need" << " | " << " Price  | " << std::left << "Expiry" << endl;
		File << "-----+-------+-------------------------------------+------+------+---------+-----------\n";
		for (int i = 0; i < m_noOfiProducts; i++)
		{
			if (m_ptr[i]->qty() == m_ptr[i]->qtyNeeded())
			{
				m_ptr[i]->linear(true);
				shipped++;
				File << "   " << (shipped) << " | ";
				m_ptr[i]->display(File);
				File << endl;
				remove(i);
			
			}
		}
		File << "-----+-------+-------------------------------------+------+------+---------+-----------\n";
		cout << "Shipping Order for " << shipped << " times saved!\n\n";
	}
}

