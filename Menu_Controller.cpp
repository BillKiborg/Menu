#include "Menu_Controller.h"

void Menu_Controller::setup(){
	qDebug() << "setup";
	menu_elements_list = menu->get_elements_list();
	std::for_each(menu_elements_list.cbegin() + 1, menu_elements_list.cend(), [](Menu_Element* element) {
		element->to_focus(false);
		});
}

QList<Menu_Element*>::const_iterator Menu_Controller::get_current_element(){	

	auto element = std::find_if(menu_elements_list.cbegin(), menu_elements_list.cend(), [](Menu_Element* element) {
		if (element->get_focus_status()) {
			return true;
		}
		return false;
		});

	if (element == menu_elements_list.end()) {
		throw std::runtime_error{ "Current element is not found" };
	}	

	return element;
}

void Menu_Controller::set_menu(Menu* _menu){
	
	menu = _menu;
	setup();
}

void Menu_Controller::to_up(){
	qDebug() << "to up";
	qDebug() << "element list count:" << menu->get_elements_list().count();
	qDebug() << "---------------------------------";

	auto current_element = get_current_element();

	if (current_element != menu_elements_list.cbegin()) {
		auto prev_elem = std::prev(current_element);
		(*prev_elem)->to_focus(true);
		(*current_element)->to_focus(false);		
	}

}

void Menu_Controller::to_down(){

	qDebug() << "to down";
	qDebug() << "element list count:" << menu->get_elements_list().count();
	qDebug() << "---------------------------------";	

	auto current_element = get_current_element();		

	auto next_elem = std::next(current_element);
	if (next_elem != menu_elements_list.cend()) {
		(*next_elem)->to_focus(true);
		(*current_element)->to_focus(false);
	}	

}
