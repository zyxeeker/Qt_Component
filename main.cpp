#include "mainwindow.h"
#include "component/StartUI/startui.h"
#include <QApplication>
#include <QSplashScreen>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    StartUI s;
    s.show();
    MainWindow w;
    w.show();
    return a.exec();
}
