/* Citation and Sources...
Final Project Milestone 5 part 4
Module: iProduct

Name : Pratham Garg
Email : pgarg13@myseneca.ca
Student ID : 117900217
Date : 10 - 04 - 2022

I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
---------------------------------------------------------- -
---------------------------------------------------------- - */

#ifndef SDDS_iProduct_H
#define SDDS_iProduct_H
#include "Status.h"
namespace sdds {

	class iProduct {
	public:
		virtual ~iProduct() = 0;	
		virtual void linear(bool isLinear) = 0;   // determines if the iProduct is displayed in a linear format or descriptive format
		virtual operator bool()const = 0;  // returns if the iProduct is in a good state
		virtual operator double()const = 0;  // returns the price of the produce
		virtual int operator+=(int qty) = 0;  // to increase the quantity on hand
		virtual int operator-=(int qty) = 0;  // to reduce the quantity on hand
		virtual bool operator==(int sku)const = 0;   // return true if the sku is a match to the iProduct's sku
		virtual bool operator==(const char* description)const = 0;    // returns true if the description is found in the iProduct's description
		virtual int qty()const = 0;  // retuns the quantity on hand
		virtual int qtyNeeded()const = 0;   // returns the number of products needed

		virtual int readSku(std::istream& istr) = 0;// to read the Stock-Keeping Unit from console before main data entry
		virtual std::ofstream& save(std::ofstream& ofstr)const = 0;   // saves the iProduct into a file
		virtual std::ostream& display(std::ostream& ostr)const = 0;   // displays the iProduct on the screen
		virtual std::istream& read(std::istream& istr) = 0;  // reads the iProduct from the console
		virtual std::ifstream& load(std::ifstream& ifstr) = 0;   // loads an iProduct from a file
		virtual bool search(const char* substr)const=0;
	};
	std::ostream& operator<<(std::ostream& ostr, const iProduct& D);   // insertion operator overload
	std::istream& operator>>(std::istream& istr, iProduct& D);  // extraction operator overload

}
#endif