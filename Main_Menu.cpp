#include "Main_Menu.h"

Main_Menu::Main_Menu(){
	ui.setupUi(this);	
	ui.scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
}

void Main_Menu::add_elem(Menu_Element* element){

	ui.scrollAreaWidgetContents->layout()->addWidget(element);
}

QList<Menu_Element*> Main_Menu::get_elements_list(){
	return 
		ui.scrollAreaWidgetContents->findChildren<Menu_Element*>(Qt::FindDirectChildrenOnly);
}
