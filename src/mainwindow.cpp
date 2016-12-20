#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),gl(new QtGL(this)), bar(new ParBar(this))
{

	QDesktopWidget *desktopWidgt = QApplication::desktop();
    QRect deskRect = desktopWidgt->availableGeometry();
    int deskWidth = deskRect.width();
    int deskHeight = deskRect.height();
    int w = deskHeight - 256;
    int x = (deskWidth - w - 300) / 2;
    int y = (deskHeight - w - 36) / 2;

    ui->setupUi(this);
    resize(w, w + 36);
    gl->resize(w,w);
    gl->move(0,36);
    setCentralWidget(gl);

    connect(ui->action_O, SIGNAL(triggered(bool)), this, SLOT(OpenFile(bool)));
	move(x,y);
	bar->SetGL(gl);
    bar->show();
    bar->move(x+w, y);



}

MainWindow::~MainWindow(){
    delete gl;
    delete ui;
}

void MainWindow::OpenFile(bool){
    QString filename = QFileDialog::getOpenFileName(this, "Select a *.obj file", "", "*.obj");
    if (filename.size()){
        gl->addModel(filename);
        bar->UpdatePar();
    }
}
