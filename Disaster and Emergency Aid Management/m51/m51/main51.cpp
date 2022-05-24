/* ------------------------------------------------------
Final project Milestone 51
Filename: main.cpp
Version 1.0
Author: Fardad Soleimanloo   2022-04-01
Revision History
-----------------------------------------------------------
Date          Reason
----------------------------------------------------------
Name : Pratham Garg
Email : pgarg13@myseneca.ca
Student ID : 117900217
Date : 06 - 04 - 2022

I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
---------------------------------------------------------- -
---------------------------------------------------------- - */
#include <iostream>
#include <fstream>
#include "AidMan.h"
#include "Utils.h"
using namespace sdds;
using namespace std;

void copyfile(const char* to, const char* from);
void displayFile(const char* file);

int main() {
   copyfile("data.dat", "data51.dat");
   ut.testMode();
   AidMan().run();
   displayFile("data.dat");
   return 0;
}

void displayFile(const char* file) {
   ifstream in(file);
   char ch;
   cout << "File: " << file << endl;
   while (in.get(ch)) cout << ch;
}

void copyfile(const char* to, const char* from) {
   std::ifstream in(from);
   std::ofstream out(to);
   char ch;
   while (in.get(ch)) out.put(ch);
}
