/* Citation and Sources...
Final Project Milestone 3
Module: Item


Name : Pratham Garg
Email : pgarg13@myseneca.ca
Student ID : 117900217
Date : 30 - 03 - 2022

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

	Perishable::Perishable() {
		m_handling = nullptr;
	}
	Perishable::~Perishable() {
		delete[]m_handling;
		m_handling = nullptr;
	}
	Perishable::Perishable(const Perishable& P) {
		*this = P;
	}
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

	Perishable::operator bool()const {
		return m_sku >= 10000 && m_sku <= 39999;
	}

	const Date& Perishable::expiry()const {
		return m_expiry;
	}
	int Perishable::readSku(std::istream& istr) {
		m_sku = ut.getint(10000, 39999, "SKU: ", NULL, istr);
		return m_sku;
	 }
	std::ofstream& Perishable::save(std::ofstream& ofstr)const {
		if (m_state)
		{
			Item::save(ofstr);
			ofstr << '\t';
			if (m_handling!=NULL)
			{
				ofstr << m_handling;
			}
			ofstr << '\t';
			Date d = m_expiry;
			d = false;
			ofstr << d;

		}
		return ofstr;
	 }
	std::ifstream& Perishable::load(std::ifstream& ifstr) {
		Item::load(ifstr);
		if (m_handling!=NULL)
		{
			delete[]m_handling;
			m_handling = nullptr;
		}
		string temp;
		getline(ifstr, temp, '\t');
		m_handling = new char[temp.length() + 1];
		strcpy(m_handling, temp.c_str());
		ifstr >> m_expiry;
		ifstr.ignore();
		if (ifstr.fail())
		{
			m_state = "Input file stream read (perishable) failed!";
		}
		return ifstr;

	 }
	std::ostream& Perishable::display(std::ostream& ostr)const {
		if (!m_state)
		{
			ostr << m_state;
		}
		if (linear())
		{
			Item::display(ostr);
			if (m_handling!=NULL&&m_handling[0] != '\t'&&m_handling[0] != '\0')
			{
				ostr << '*';
			}
			else
			{
				ostr << ' ';
			}
			ostr << m_expiry;
		}
		else
		{
			ostr << "Perishable ";
			Item::display(ostr);
			ostr << "Expiry date: ";
			ostr << m_expiry<<endl;
			if (m_handling != NULL && m_handling[0] != '\t'&&m_handling[0] != '\0')
			{
				ostr << "Handling Instructions: " << m_handling << endl;
			}
		}
		return ostr;
	 }
	std::istream& Perishable::read(std::istream& istr) {
		Item::read(istr);
		delete[]m_handling;
		m_handling = nullptr;
		cout << "Expiry date (YYMMDD): ";
		istr >> m_expiry;
		istr.ignore();
		cout << "Handling Instructions, ENTER to skip: ";
		char ch = istr.peek();
		if (ch== '\n')
		{

		}
		else
		{
			string temp;
			getline(istr, temp, '\n');
			m_handling = new char[temp.length() + 1];
			strcpy(m_handling, temp.c_str());
		}
		if (istr.fail())
		{
			m_state = "Perishable console date entry failed!";
		}
		return istr;
	 }
}