#pragma once
#include <QWidget>
#include <QObject>

class My_Widget : public QWidget {	
public:
	virtual ~My_Widget() = default;
};

class Menu_Element : public My_Widget {	
protected:
	bool focus_status = false;
public:
	virtual ~Menu_Element() = default;	
	virtual void to_focus(bool) = 0;
	virtual bool get_focus_status() {
		return focus_status;
	}
};

class Menu : public My_Widget {	
public:
	virtual ~Menu() = default;
	virtual void add_elem(Menu_Element*) = 0;
	virtual QList<Menu_Element*> get_elements_list() = 0;
};


class Controller;

class Control_Panel : public My_Widget {
	Q_OBJECT
protected:
	Controller* controller = nullptr;
public:
	virtual ~Control_Panel() = default;
	virtual void set_controller(Controller* new_controller) {
		controller = new_controller;
	}
};

class Controller : public QObject {	
protected:
	Menu* menu = nullptr;
public:
	virtual ~Controller() = default;
	virtual void set_menu(Menu* addable_menu) {
		menu = addable_menu;
	}
	virtual void to_up() = 0;
	virtual void to_down() = 0;
};

