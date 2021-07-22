#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "component/StartUI/start_ui.h"

MainWindow::MainWindow(QWidget *parent)
        : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
}

MainWindow::~MainWindow() {
    delete ui;
}
