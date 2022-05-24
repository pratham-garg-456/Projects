#ifndef SDDS_MENU_H
#define SDDS_MENU_H
#include"Status.h"
#include"Utils.h"

namespace sdds {
	class Menu {
		char* m_menuContent{};
		unsigned int m_noOfOptions=0;
	public:
		Menu(unsigned int options=0, const char* menuContent=NULL);
		Menu(const Menu& M)=delete;
		Menu& operator=(const Menu& M) = delete;
		~Menu();
		unsigned int run()const;

	 };
}
#endif