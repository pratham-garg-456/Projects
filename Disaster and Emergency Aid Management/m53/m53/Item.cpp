/* Citation and Sources...
Final Project Milestone 5 part 2
Module: Item

Name : Pratham Garg
Email : pgarg13@myseneca.ca
Student ID : 117900217
Date : 08 - 04 - 2022

I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
---------------------------------------------------------- -
---------------------------------------------------------- - */
#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <string>
#include <iomanip>
#include <cstring>
#include "Item.h"
#include"Utils.h"
#include <fstream>
using namespace std;
namespace sdds {

	// default constructor for item

	Item::Item() {
		m_description = NULL;
		m_linear = false;
		m_price = 0;
		m_qty = 0;
		m_qtyNeeded = 0;
		m_sku = 0;
		m_state = 0;
	}

	// copy constructor for item

	Item::Item(const Item& N) {
		if (N)
		{
			*this = N;
		}
	}

	// copy assignment operator for item

	Item& Item:: operator=(const Item& N) {
		if (this != &N)
		{
			if (N.m_description!=NULL)
			{
				ut.alocpy(m_description, N.m_description);
			}			
			m_linear = N.linear();
			m_price = N.m_price;
			m_qty = N.m_qty;
			m_qtyNeeded = N.m_qtyNeeded;
			m_sku = N.m_sku;
			m_state = N.m_state;
		}
		return *this;
	}

	// destructor

	Item::~Item() {
		delete[]m_description;
		m_description = nullptr;
	}

	// a query that returns the linear flag of the Item

	bool Item::linear()const {
		return m_linear;
	}

	// clears the state of the item

	void Item::clear() {
		m_state.clear();
	}

	// Display method iProduct overrides

	ostream& Item::display(std::ostream& ostr)const {
		if (m_state)
		{
			if (m_linear) {
				ostr << std::left << setw(5) << m_sku << " | " << std::left;
				if (strlen(m_description) > 35)
				{
					ostr.write(m_description, 35);
				}
				else
				{
					ostr << setfill(' ') << setw(35) << m_description;
				}
				ostr << " | " << std::right << setfill(' ') << setw(4) << m_qty << " | " << std::right << setfill(' ') << setw(4) << m_qtyNeeded << " | " << std::right << setfill(' ') << setw(7) << fixed<< setprecision(2) << m_price << " |";
			}
			else
			{
				ostr << "AMA Item:" << endl;
				ostr << m_sku << ": " << m_description << endl;
				ostr << "Quantity Needed: " << m_qtyNeeded << endl;
				ostr << "Quantity Available: " << m_qty << endl;
				ostr << "Unit Price: $" << std::fixed << setprecision(2) << m_price << endl;
				ostr << "Needed Purchase Fund: $" << std::fixed << setprecision(2) << ((m_qtyNeeded - m_qty) * m_price) << endl;
			}
		}
		else
		{
			ostr << m_state;
		}
		return ostr;
	}

	// load method iProduct overrides

	ifstream& Item::load(std::ifstream& ifstr) {

		ifstr >> m_sku;
		ifstr.ignore();
		char temp[500];
		ifstr.getline(temp, 500, '\t');
		ut.alocpy(m_description, temp);

		ifstr >> m_qty;
		ifstr.ignore();
		ifstr >> m_qtyNeeded;
		ifstr.ignore();
		ifstr >> m_price;
		ifstr.ignore();
		if (ifstr.bad())
		{
			m_state = "Input file stream read failed";
		}
		return ifstr;
	}

	// return the state of the item

	Item::operator bool()const {
		return m_state;
	}

	//query to return the product the price of item

	Item::operator double()const {
		return m_price;
	}

	// assignment operator to assign the quantity on hand

	int Item::operator=(int qty) {
		return qty;
	}

	 // to increase the quantity on hand

	int Item::operator+=(int qty) {
		m_qty += qty;
		return m_qty;
	}

	// to decrease the quantity on hand

	int Item::operator-=(int qty) {
		m_qty -= qty;
		return m_qty;
	}

	//determines if the item is displayed in a linear format or descriptive format by assigning the value of the parameter

	void Item::linear(bool isLinear) {
		m_linear = isLinear;
	}

	// return true if the sku is a match to the Item's sku

	bool Item::operator==(int sku)const {
		return m_sku == sku;
	}

	// returns true if the description is found in the Item's description

	bool Item::operator==(const char* description)const {
		bool flag = true;
		char* p = strstr(m_description, description);
		if (p)
		{
		}
		else
		{
			flag = false;
		}
		return flag;

	}

	// query to retun the quantity on hand

	int Item::qty()const {
		return m_qty;
	}

	// query to return the target quantity needed

	int Item::qtyNeeded()const {
		return m_qtyNeeded;
	}

	// to read the Stock-Keeping Unit from console before main data entry.It makes sure the SKU number begins with digits 4 to 9 and it is 5 digits long.

	int  Item::readSku(std::istream& istr) {
		m_sku = ut.getint(40000, 99999, "SKU: ", NULL, istr);
		return m_sku;
	}

	//If the state of the Item is good, it will write SKU, description, on-hand quantity, needed quantity and price in tab-separated format.

	std::ofstream& Item::save(std::ofstream& ofstr)const {
		if (m_state)
		{
			ofstr << m_sku << "\t" << m_description << "\t" << m_qty << "\t" << m_qtyNeeded << "\t" << std::fixed << std::setprecision(2) << m_price;
		}
		return ofstr;
	}

	//After deleting the description and clearing the state.Read will first prompt the user with the title "AMA Item" and then displays the SKU and reads the rest of the information in a full - proof way(the same as SKU).

	std::istream& Item::read(std::istream& istr)
	{
		string temp;
		//delete[]m_description;
		m_state.clear();
		cout << "AMA Item:\n";
		cout << "SKU: " << m_sku << endl;

		cout << "Description: ";
		if (istr.peek()=='\n')
		{
			istr.ignore();
		}
		getline(istr, temp, '\n');
		if (m_description != NULL)
		{
			m_description = nullptr;
		}
		ut.alocpy(m_description, temp.c_str());

		m_qtyNeeded = ut.getint(1, 9999, "Quantity Needed: ", NULL, istr);
		m_qty = ut.getint(0, m_qtyNeeded, "Quantity On Hand: ", NULL, istr);
		m_price = ut.getdoub(0.00, 9999.00, "Unit Price: $", NULL, istr);
		if (istr.fail())
		{
			m_state = "Console entry failed!";
		}
		return istr;
	}

	// function to search for substring in description

	bool Item::search(const char* substr) const{
		bool flag = false;
		if (strstr(m_description,substr))
		{
			flag = true;
		}
		 return flag;
	}

}