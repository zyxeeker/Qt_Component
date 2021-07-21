#include "mainwindow.h"
#include "component/StartUI/startui.h"
#include "component/ScalableMenu/scalablemenu.h"
#include <QApplication>
#include <QSplashScreen>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
//    StartUI s;
//    s.show();
//    MainWindow w;
//    w.show();
    ScalableMenu SM(0, 200, 20, 40);
    SM.show();
//    SM.InitialBtn();
    return a.exec();
}
