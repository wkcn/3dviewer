#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),gl(new QtGL(this))
{
    ui->setupUi(this);
    //setCentralWidget(gl);
    gl->resize(800,800);
    gl->move(0,36);
}

MainWindow::~MainWindow(){
    delete gl;
    delete ui;
}


void MainWindow::mousePressEvent(QMouseEvent *event){
    gl->mousePressEvent(event);
}
void MainWindow::mouseMoveEvent(QMouseEvent *event){gl->mouseMoveEvent(event);}
void MainWindow::mouseReleaseEvent(QMouseEvent *event){gl->mouseReleaseEvent(event);}
void MainWindow::wheelEvent(QWheelEvent *event){gl->wheelEvent(event);}
void MainWindow::keyPressEvent(QKeyEvent *event){gl->keyPressEvent(event);}
