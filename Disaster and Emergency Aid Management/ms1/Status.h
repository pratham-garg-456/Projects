#ifndef SDDS_STATUS_H
#define SDDS_STATUS_H
namespace sdds {
	class Status
	{
		char* m_desc{};
		int m_code=0;

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