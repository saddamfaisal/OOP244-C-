
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include "Menu.h"
using namespace std;

namespace sdds {
	
	MenuItem::MenuItem() {

		MenuTitle = nullptr;
	}

	MenuItem::MenuItem(const char* m_value) {
		
		if (m_value != nullptr) {

			MenuTitle = new char[strlen(m_value) + 1];
			strcpy(MenuTitle, m_value);

		} else {
			
			MenuTitle = nullptr;
		}
	}

	void MenuItem::displayMenuItem() const {
		
		if (MenuTitle != nullptr) {
			cout << MenuTitle << endl;
		}
	}

	MenuItem::~MenuItem() {
		delete[] MenuTitle;
		MenuTitle = nullptr;
	}

	Menu::Menu() {
		MenuTitle = nullptr;
		*MenuItems = nullptr;
		m_Indt = 0;
		items_Num = 0;
	}

	Menu::Menu(const char* t_title, int indent) {

		if (t_title != nullptr) {
				
			MenuTitle = new char[strlen(t_title) + 1];
			strcpy(MenuTitle, t_title);
			*MenuItems = nullptr;
			m_Indt = indent;
			items_Num = 0;
		} else {

			MenuTitle = nullptr;
			*this = Menu();
		}
	}


	Menu& Menu::operator=(const Menu& MN) {

		if (this != &MN) {

			delete[] MenuTitle;
			MenuTitle = nullptr;

			for (int i = 0; i < items_Num; ++i) {
				delete MenuItems[i];
				MenuItems[i] = nullptr;
			}

			m_Indt = 0;
			items_Num = 0;

			m_Indt = MN.m_Indt;
			items_Num = MN.items_Num;

			if (MN.MenuTitle != nullptr) {

				MenuTitle = new char[strlen(MN.MenuTitle) + 1];
				strcpy(MenuTitle, MN.MenuTitle);
				for (int i = 0; i < MN.items_Num; i++) {
					MenuItems[i] = new MenuItem(MN.MenuItems[i]->MenuTitle);
				}

			}
			else {

				delete[] MenuTitle;
				MenuTitle = nullptr;

				for (int i = 0; i < items_Num; ++i) {
					delete MenuItems[i];
					MenuItems[i] = nullptr;
				}

				m_Indt = 0;
				items_Num = 0;
			}
		}

		return *this;
	}

	Menu::Menu(const Menu& MI) {

		m_Indt = MI.m_Indt;
		items_Num = MI.items_Num;

		if (MI.MenuTitle != nullptr) {

			MenuTitle = new char[strlen(MI.MenuTitle) + 1];  
			strcpy(MenuTitle, MI.MenuTitle);

			for (int i = 0; i < MI.items_Num; i++) {

				if (MI.MenuItems[i] != nullptr) {

					MenuItems[i] = new MenuItem(MI.MenuItems[i]-> MenuTitle);
				}
				else {
                 
					MenuItems[i] = nullptr;
				}
			}
		}
		else {
			MenuTitle = nullptr;
		}

	}


	Menu::operator bool() const {

		return MenuTitle != nullptr && items_Num <= MAX_NO_OF_ITEMS && items_Num > 0 && m_Indt >= 0;
	}

	bool Menu::isEmpty() const	{
		
		return *this;
	}

	ostream& Menu::display(ostream& ml) const {

		if (MenuTitle == nullptr) {

			ml << "Invalid Menu!" << endl;
		} else if (*MenuItems == nullptr || MenuItems[0]-> MenuTitle == nullptr) {

			for (int i = 0; i < m_Indt; i++) {
				ml << "    ";
			}

			cout << MenuTitle << endl;
			ml << "No Items to display!" << endl;
		}
		else {
			
			for (int i = 0; i < m_Indt; i++) {
				ml << "    ";
			}

			ml << MenuTitle << endl;
			for (int i = 0; i < items_Num && MenuItems[i] != nullptr; i++) {
				if (MenuItems[i]->MenuTitle != nullptr) {

					for (int i = 0; i < m_Indt; i++) {
						ml << "    ";
					}

					ml << i + 1 << "- " << MenuItems[i]->MenuTitle << endl;
				}
			}
			for (int i = 0; i < m_Indt; i++) {
				ml << "    ";
			}
			ml << "> ";
		}
		return ml;
	}


	void Menu::add(const char* item_mu) {

		if (item_mu != nullptr) {

			MenuItems[items_Num] = new MenuItem(item_mu);
			items_Num++;
		} else {

			delete[] MenuTitle;
			MenuTitle = nullptr;

			for (int i = 0; i < items_Num; ++i) {
				delete MenuItems[i];
				MenuItems[i] = nullptr;
			}

			m_Indt = 0;
			items_Num = 0;
		}
	}

	Menu& Menu::operator<<(const char* menuitem) {
		
		add(menuitem);
		return *this;
	}

	Menu& Menu::operator=(const char* ti) {
		
		if (MenuTitle != nullptr) {

			delete[] MenuTitle;
			MenuTitle = nullptr;

			MenuTitle = new char[strlen(ti) + 1];
			strcpy(MenuTitle, ti);
		} else {

			delete[] MenuTitle;
			MenuTitle = nullptr;

			for (int i = 0; i < items_Num; ++i) {
				delete MenuItems[i];
				MenuItems[i] = nullptr;
			}

			MenuTitle = nullptr;
			m_Indt = 0;
			items_Num = 0;
		}
		return *this;
	}


	Menu::operator int() const {
		return run();
	}

	int Menu::run() const {

		int select = 0;

		display();

		if (isEmpty()) {
			while ((select <= 0 || select > items_Num)) {

				cin >> select;

				if (cin.fail()) {

					cout << "Invalid Integer, try again: ";
					cin.clear();
					cin.ignore(2000, '\n');
				}	else if (select <= 0 || select > items_Num) {

					cout << "Invalid selection, try again: ";
					cin.clear();
					cin.ignore(2000, '\n');
				}
				else {

					cin.clear();
					cin.ignore(100, '\n');
				}
			}
		}
		return select;
	}



	Menu::~Menu() {

		delete[] MenuTitle;
		MenuTitle = nullptr;

		for (int i = 0; i < items_Num; ++i) {
			delete MenuItems[i];
			MenuItems[i] = nullptr;
		}
	}
}



