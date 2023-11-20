#include <QtWidgets>
#include "Interfaces.h"
#include "Test.h"

#include "Main_Menu.h"
#include "Menu_Control_Panel.h"
#include "Menu_Controller.h"
#include "Simple_Menu_Item.h"

#include "ui_Main_Menu.h"
#include "ui_Simple_Menu_Item.h"


int main(int argc, char** argv) {
	QApplication App{ argc, argv };
		
	Main_Menu			menu;
	Menu_Control_Panel	control_panel;
	Menu_Controller		controller;	

	control_panel.set_controller(&controller);
	control_panel.show();

	auto menu_item = new Simple_Menu_Item{"Menu Item 1"};
	menu_item->to_focus(true);

	menu.add_elem(menu_item);
	menu.add_elem(new Simple_Menu_Item{ "Menu Item 2" });
	menu.add_elem(new Simple_Menu_Item{ "Menu Item 3" });
	menu.add_elem(new Simple_Menu_Item{ "Menu Item 4" });
	menu.show();

	controller.set_menu(&menu);

	return App.exec();
}