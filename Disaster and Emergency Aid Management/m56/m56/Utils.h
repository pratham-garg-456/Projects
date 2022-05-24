/* Citation and Sources...
Final Project Milestone 5 part 6
Module: Utils


Name : Pratham Garg
Email : pgarg13@myseneca.ca
Student ID : 117900217
Date : 10-04-2022

I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
-----------------------------------------------------------*/

#ifndef SDDS_UTILS_H
#define SDDS_UTILS_H

namespace sdds {
    const int sdds_testYear = 2022;
    const int sdds_testMon = 03;
    const int sdds_testDay = 31;
    class Utils {
        bool m_testMode = false;
    public:
        void getSystemDate(int* year = nullptr, int* mon = nullptr, int* day = nullptr);
        int daysOfMon(int mon, int year)const;
        void testMode(bool testmode = true);
        void alocpy(char*& destination, const char* source);
        int getint(const char* prompt = nullptr, std::istream& istr = std::cin);
        double getdoub(const char* prompt = nullptr, std::istream& istr = std::cin);
        int getint(int min, int max, const char* prompt = nullptr, const char* errMes = nullptr, std::istream& istr = std::cin);
        double getdoub(double min, double max, const char* prompt = nullptr, const char* errMes = nullptr, std::istream& istr = std::cin);
    };
    extern Utils ut;
}

#endif // !SDDS_UTILS_H
