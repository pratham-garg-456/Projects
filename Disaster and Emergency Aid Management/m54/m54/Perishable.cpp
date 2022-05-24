/* Citation and Sources...
Final Project Milestone 5 part 4
Module: Perishable

Name : Pratham Garg
Email : pgarg13@myseneca.ca
Student ID : 117900217
Date : 10 - 04 - 2022

I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
---------------------------------------------------------- -
---------------------------------------------------------- - */
#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <string>
#include <iomanip>
#include <cstring>
#include "Perishable.h"
#include"Utils.h"
#include <fstream>
using namespace std;
namespace sdds {

	//constructor

	Perishable::Perishable() {
		m_handling = nullptr;
	}

	//destructor

	Perishable::~Perishable() {
		delete[]m_handling;
		m_handling = nullptr;
	}

	//copy constructor

	Perishable::Perishable(const Perishable& P) {
		*this = P;
	}

	//copy assignment operator

	Perishable& Perishable::operator=(const Perishable& P) {
		if (this!=&P)
		{
			Item::operator =(P);
			if (m_handling != nullptr)
			{
				delete[]m_handling;
				m_handling = nullptr;
			}
			if (P.m_handling!=NULL)
			{
				m_handling = new char[strlen(P.m_handling) + 1];
				strcpy(m_handling, P.m_handling);
			}
			m_expiry = P.m_expiry;	
		}
		else
		{
			delete[]m_handling;
			m_handling = nullptr;
		}
		return *this;
		}

	//check if the item is perishable. A Perishable item, unlike an Item, has an SKU that starts with digits 1 to 3. (10000 to 39999)

	Perishable::operator bool()const {
		return m_sku >= 10000 && m_sku <= 39999;
	}

	// a query that returns a constant reference of the expiry date.

	const Date& Perishable::expiry()const {
		return m_expiry;
	}

	//Override readSKU function to only receive SKU numbers between 10000 and 39999 (only SKUs starting with digits 1 to 3)

	int Perishable::readSku(std::istream& istr) {
		m_sku = ut.getint(10000, 39999, "SKU: ", NULL, istr);
		return m_sku;
	 }

	// save override

	std::ofstream& Perishable::save(std::ofstream& ofstr)const {
		if (m_state)
		{
			Item::save(ofstr);  //call the save of the Base class.
			ofstr << '\t';  //writes a tab
			if (m_handling!=NULL)
			{
				ofstr << m_handling;  //writes the handling instructions, if handling instructions exist and the attribute is not empty.
			}
			ofstr << '\t';   //writes a tab
			Date d = m_expiry;
			d = false;
			ofstr << d;   //writes an unformatted copy of the expiry date
		}
		return ofstr;
	 }

	//load override

	std::ifstream& Perishable::load(std::ifstream& ifstr) {

		Item::load(ifstr); //  calls the load of the Base class.

		string temp;
		getline(ifstr, temp, '\t');
		ut.alocpy(m_handling, temp.c_str()); //reads the handling instructions dynamically into the handling instructions attribute

		ifstr >> m_expiry;  //reads the expiry date
		ifstr.ignore();  //ignores the newline.
		if (ifstr.fail())
		{
			m_state = "Input file stream read (perishable) failed!";  //if the ifstream object has failed, it will set the state of the Item to this
		}
		return ifstr;
	 }

	//display override

	std::ostream& Perishable::display(std::ostream& ostr)const {
		if (!m_state)
		{
			ostr << m_state;  //if the Perishable Item is in a bad state, the state is printed
		}
		if (linear()) //if linear
		{
			Item::display(ostr); //display of the base class is called
			if (m_handling!=NULL&&m_handling[0] != '\t'&&m_handling[0] != '\0')  //if handling instructions are not null and not empty a single asterisk ('*') is printed otherwise a single space (' ') is printed.
			{
				ostr << '*';
			}
			else
			{
				ostr << ' ';
			}
			ostr << m_expiry; //the expiry date is printed

		}
		else
		{
			ostr << "Perishable ";
			Item::display(ostr);   //displays the base class
			ostr << "Expiry date: ";
			ostr << m_expiry<<endl;   //printed the expiry date (formatted)
			if (m_handling != NULL && m_handling[0] != '\t'&&m_handling[0] != '\0')
			{
				ostr << "Handling Instructions: " << m_handling << endl;
			}
		}
		return ostr;
	 }

	//read override

	std::istream& Perishable::read(std::istream& istr) {

		Item::read(istr);  //read of the base class is called

		cout << "Expiry date (YYMMDD): ";
		istr >> m_expiry;  //the expiry date is read
		istr.ignore();
		cout << "Handling Instructions, ENTER to skip: ";
		char ch = istr.peek();
		if (ch== '\n') //peeks and if the very first character is '\n'
		{
			// nothing is read and the attribute remains null.
		}
		else //if not it will read the instructions dynamically into the instructions attribute
		{
			string temp;
			getline(istr, temp, '\n');
			ut.alocpy(m_handling, temp.c_str());

		}
		if (istr.fail())  //if istream object is in a fail state, it will set the state of the Perishable Item to this
		{
			m_state = "Perishable console date entry failed!";
		}
		return istr;

	}

	// function to search for substring in description

	bool Perishable::search(const char* substr) const {
		return Item::search(substr);
	}
}