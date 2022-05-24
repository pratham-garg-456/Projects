/* Citation and Sources...
Final Project Milestone 1
Module: Whatever
Filename: Whatever.cpp
Version 1.0
Author	John Doe
Revision History
-----------------------------------------------------------
Date      Reason
2020/?/?  Preliminary release
2020/?/?  Debugged DMA
-----------------------------------------------------------

Name : Pratham Garg
Email : pgarg13@myseneca.ca
Student ID : 117900217
Date : 09-03-2022

I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
-----------------------------------------------------------*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <iomanip>
#include <cstring>
#include <ctime>
#include "Utils.h"
using namespace std;
namespace sdds {
   Utils ut;
   void Utils::testMode(bool testmode) {
      m_testMode = testmode;
   }
   void Utils::getSystemDate(int* year, int* mon, int* day) {
      if (m_testMode) {
         if(day) *day = sdds_testDay;
         if(mon) *mon = sdds_testMon;
         if(year) *year = sdds_testYear;
      }
      else {
         time_t t = std::time(NULL);
         tm lt = *localtime(&t);
         if (day) *day = lt.tm_mday;
         if (mon) *mon = lt.tm_mon + 1;
         if (year) *year = lt.tm_year + 1900;
      }
   }
   int Utils::daysOfMon(int month, int year)const {
      int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
      int mon = (month >= 1 && month <= 12 ? month : 13)-1;
      return days[mon] + int((mon == 1) * ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
   }

   void Utils::alocpy(char*& destination, const char* source) {

       delete[] destination;
       destination = nullptr;
       if (source != NULL)
       {
           destination = new char[strlen(source) + 1];
           strcpy(destination, source);
       }
   }

   int Utils::getint(const char* prompt) {
       //if (prompt!=nullptr)
       //{
       //    do
       //    {

       //  
       //    if (//integeristrue) {
       //        ;
       //    }
       //else{
       //    cout<<"Invalid Integer, retry: "<<endl;

       //}
       //} while (true);
       return 3;
   }

   int Utils::getint(int min, int max, const char* prompt, const char* errMes ) {

       getint(prompt);
       return 3;
   }

   
}