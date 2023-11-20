#pragma once
#include "Display_Interfaces.h"
#include "ui_Main_Menu.h"

class Main_Menu : public Menu{
	Q_OBJECT
private:

	Ui::Main_Menu ui;

public:

	Main_Menu();
	void add_elem(Menu_Element*) override;
	QList<Menu_Element*> get_elements_list() override;

};

