#ifndef SDDS_AIDMAN_H
#define SDDS_AIDMAN_H
#include"Status.h"
#include"Utils.h"
#include "Menu.h"
#include"iProduct.h"
#include "Perishable.h"
#include"Item.h"

namespace sdds {
	const int sdds_max_num_items = 100;
	class AidMan{
		iProduct* m_ptr[sdds_max_num_items];
		int m_noOfiProducts=0;
		char* m_fileName{};
		Menu m_menu;
		unsigned int menu();
	public:
		AidMan();
		AidMan(const AidMan& A) = delete;
		AidMan& operator=(const AidMan& A) = delete;
		~AidMan();
		int list(const char* sub_desc = nullptr);
		void run();
		void save()const;
		void load();
	};

}
#endif