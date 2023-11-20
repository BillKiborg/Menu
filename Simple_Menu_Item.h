#pragma once
#include "Display_Interfaces.h"
#include "ui_Simple_Menu_Item.h"

class Simple_Menu_Item : public Menu_Element{	
	Q_OBJECT
private:

	Ui::Simple_Menu_Item ui;

public:

	Simple_Menu_Item();
	Simple_Menu_Item(QString inscription);
	void to_focus(bool) override;

};

