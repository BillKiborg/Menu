#pragma once
#include "Display_Interfaces.h"

class Menu_Controller : public Controller{
private:

	void setup();
	QList<Menu_Element*>::const_iterator get_current_element();
	QList<Menu_Element*> menu_elements_list;

public:

	void set_menu(Menu*) override;
	void to_up() override;
	void to_down() override;

};

