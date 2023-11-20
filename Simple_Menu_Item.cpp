#include "Simple_Menu_Item.h"

Simple_Menu_Item::Simple_Menu_Item(){
	ui.setupUi(this);
}

Simple_Menu_Item::Simple_Menu_Item(QString inscription){
	ui.setupUi(this);
	setAttribute(Qt::WA_StyledBackground, true);
	ui.label->setText(inscription);
}

void Simple_Menu_Item::to_focus(bool value){

	focus_status = value;

	if (value) {		
		setStyleSheet("color : yellow; background-color : blue;");
	}
	else {
		setStyleSheet("color : black; background-color : transparent;");
	}

}
