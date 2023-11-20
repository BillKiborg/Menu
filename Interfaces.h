#pragma once
#include <QString>
#include <QObject>
#include <QWidget>


class Interface : public QObject {
	Q_OBJECT
public:
	virtual ~Interface() = default;
	virtual void method() = 0;
};

class Widget : public QWidget, public Interface {
	Q_OBJECT
public:
	void method() override {

	}
};