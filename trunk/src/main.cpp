#include <QApplication>
#include <QMainWindow>

#include "mainwindow.h"

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);

	QMainWindow *main_window = new QMainWindow(0);

	Ui_MainWindow auto_design;

	auto_design.setupUi(main_window);

	main_window->show();

	return app.exec();
}
