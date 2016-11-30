#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),gl(new QtGL(this)), bar(new ParBar(this))
{
    ui->setupUi(this);
    gl->resize(800,800);
    gl->move(0,36);
    setCentralWidget(gl);

	QDesktopWidget *desktopWidgt = QApplication::desktop();
    QRect deskRect = desktopWidgt->availableGeometry();
    int deskWidth = deskRect.width();
    int deskHeight = deskRect.height();
	int x = (deskWidth - 1200) / 2;
	int y = (deskHeight - 836) / 2;

    connect(ui->action_O, SIGNAL(triggered(bool)), this, SLOT(OpenFile(bool)));
	move(x,y);
	bar->SetGL(gl);
    bar->show();
	bar->move(x+800,y);



}

MainWindow::~MainWindow(){
    delete gl;
    delete ui;
}

void MainWindow::OpenFile(bool){
    QString filename = QFileDialog::getOpenFileName(this, "Select a *.obj file", ".", "*.obj");
    if (filename.size()){
        gl->addModel(filename);
        bar->UpdatePar();
    }
}


void MainWindow::mousePressEvent(QMouseEvent *event){
    gl->mousePressEvent(event);
}
void MainWindow::mouseMoveEvent(QMouseEvent *event){gl->mouseMoveEvent(event);}
void MainWindow::mouseReleaseEvent(QMouseEvent *event){gl->mouseReleaseEvent(event);}
void MainWindow::wheelEvent(QWheelEvent *event){gl->wheelEvent(event);}
void MainWindow::keyPressEvent(QKeyEvent *event){gl->keyPressEvent(event);}
