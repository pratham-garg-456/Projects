#ifndef SDDS_AIDMAN_H
#define SDDS_AIDMAN_H
#include"Status.h"
#include"Utils.h"
#include "Menu.h"

namespace sdds {

	class AidMan{
		char* m_fileName{};
		Menu m_menu;
		unsigned int menu()const;
	public:
		AidMan();
		AidMan(const AidMan& A) = delete;
		AidMan& operator=(const AidMan& A) = delete;
		~AidMan();
		void run()const;
	};

}
#endif