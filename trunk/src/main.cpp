#include <QApplication>
#include <QtGui>
#include <unistd.h>

#include "mainwindow.h"

int main(int argc, char *argv[])
{        
    QApplication app(argc, argv);
    
    QSplashScreen *splash = new QSplashScreen(QPixmap("brainfuckStudio.png"));
    splash->show();

    MainWindow mainWin;
    mainWin.show();
    
    //sleep(2);
    splash->finish(&mainWin);
    delete splash;

    return app.exec();
}
