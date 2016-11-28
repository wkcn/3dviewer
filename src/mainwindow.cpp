#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),gl(new QtGL(this))
{
    ui->setupUi(this);
    gl->resize(800,800);
    gl->move(0,36);
	setCentralWidget(gl);
}

MainWindow::~MainWindow(){
    delete gl;
    delete ui;
}
