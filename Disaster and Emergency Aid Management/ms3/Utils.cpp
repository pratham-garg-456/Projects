/* Citation and Sources...
Final Project Milestone 3
Module: Utils


Name : Pratham Garg
Email : pgarg13@myseneca.ca
Student ID : 117900217
Date : 30-03-2022

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
            if (day) *day = sdds_testDay;
            if (mon) *mon = sdds_testMon;
            if (year) *year = sdds_testYear;
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
        int mon = (month >= 1 && month <= 12 ? month : 13) - 1;
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

    int Utils::getint(const char* prompt, istream& istr) {
         int ttemp=0;
        bool flag = true;
        if (prompt != nullptr)
        {
            cout << prompt;
            do
            {
                istr >> ttemp;
                if (istr.fail())
                {
                    istr.clear();
                    istr.ignore(1000, '\n');
                    cout << "Invalid Integer, retry: ";
                }
                else
                {
                    flag = false;
                }

            } while (flag);
        }
        return ttemp;
    }

    double Utils::getdoub(const char* prompt, istream& istr) {
        double ttemp = 0.0;
        bool flag = true;
        if (prompt != nullptr)
        {
            cout << prompt;
            do
            {
                istr >> ttemp;
                if (istr.fail())
                {
                    istr.clear();
                    istr.ignore(1000, '\n');
                    cout << "Invalid number, retry: ";
                }
                else
                {
                    flag = false;
                }

            } while (flag);
        }
        return ttemp;
    }

    double Utils::getdoub(double min, double max, const char* prompt, const char* errMes, istream& istr) {
        double temp;
        bool flag = true;
        temp = getdoub(prompt, istr);
        do
        {
            if (temp<min|| temp>max)
            {
                if (errMes != NULL)
                {
                    cout << errMes << ",retry";
                }
                else
                {
                    cout << "Value out of range [" << std::fixed <<setprecision(2) << min << "<=val<=" << std::fixed <<setprecision(2) << max << "]:";
                }
                temp = getdoub(" ");
            }
            else
            {
                flag = false;
            }
        } while (flag);
        return temp;
    }

    int Utils::getint(int min, int max, const char* prompt, const char* errMes, istream& istr) {
        unsigned int temp;
        bool flag = true;
        temp = getint(prompt,istr);
        do
        {
            if (temp<unsigned(min) || temp>unsigned(max))
            {
                if (errMes != NULL)
                {
                    cout << errMes << ",retry";
                }
                else
                {
                    cout << "Value out of range [" << min << "<=val<=" << max << "]:";
                }
                temp = getint(" ");
            }
            else
            {
                flag = false;
            }
        } while (flag);
        return temp;

    }
}