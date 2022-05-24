/* Citation and Sources...
Final Project Milestone 3
Module: Status


Name : Pratham Garg
Email : pgarg13@myseneca.ca
Student ID : 117900217
Date : 30 - 03 - 2022

I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
---------------------------------------------------------- -
---------------------------------------------------------- - */

#ifndef SDDS_STATUS_H
#define SDDS_STATUS_H
namespace sdds {
	class Status
	{
		char* m_desc{};
		int m_code = 0;

	public:
		Status(const char* desc = nullptr);
		~Status();
		Status(const Status& S);
		Status& operator=(const char* desc);
		Status& operator=(int code);
		void reallocateandcopy(const char* des, int code);
		void set(const char* desc, int code);
		bool validName(const char* desc);
		operator bool() const;
		operator int() const;
		operator const char* ()const;
		Status& clear();
		std::ostream& print(std::ostream& ostr) const;

	};
	std::ostream& operator<<(std::ostream& ostr, const Status& S);
}
#endif