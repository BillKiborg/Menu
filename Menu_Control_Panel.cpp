#include "Menu_Control_Panel.h"

Menu_Control_Panel::Menu_Control_Panel(){
	ui.setupUi(this);
	move(1100, 700);
	this->setWindowFlag(Qt::WindowStaysOnTopHint);

	QWidget::connect(
		ui.up_bt, &QPushButton::clicked,
		[this] {
			try	{
				if (!controller) throw std::runtime_error{ "Controller is not found" };
				controller->to_up();
			}
			catch (std::runtime_error& exc) {
				qDebug() << "Menu_Control_Panel Exc: " << exc.what();
			}
		});	

	QWidget::connect(
		ui.down_bt, &QPushButton::clicked,
		[this] {
			try	{
				if (!controller) throw std::runtime_error{ "Controller is not found" };
				controller->to_down();
			}
			catch (std::runtime_error& exc) {
				qDebug() << "Menu_Control_Panel Exc: " << exc.what();
			}
		}
	);

}


