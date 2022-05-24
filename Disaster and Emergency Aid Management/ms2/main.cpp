/* ------------------------------------------------------
Final project Milestone 2
Module: Menu and AidMan
Filename: main.cpp
Version 1.0
Author: Fardad Soleimanloo   2022-03-03
Revision History
-----------------------------------------------------------
Date          Reason

Name : Pratham GargEmail: pgarg13@myseneca.ca
Email : pgarg13@myseneca.ca
Student ID : 117900217
Date : 22 - 03 - 2022

I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#include <iostream>
#include "AidMan.h"
#include "Utils.h"
int main() {
   std::cout << "Enter the following:\nabc\n1\n2\n3\n4\n5\n6\n7\n8\n0\n--------\n";
   sdds::ut.testMode();
   sdds::AidMan().run();
   return 0;
}