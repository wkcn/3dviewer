#include "mainwindow.h"
MainWindow::MainWindow(GLUT_Thread *t, QWidget *parent):QMainWindow(parent), glut(t), ui(new Ui::MainWindow){
	//resize(300, 800);
	ui->setupUi(this);
	ui->comboBox->addItem("纹理模式", TEX_MODE);
	ui->comboBox->addItem("面模式", FACE_MODE);
	ui->comboBox->addItem("线模式", LINE_MODE);
	ui->comboBox->addItem("点模式", POINT_MODE);
	connect(ui->comboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(SelectViewMode(int)));
	move(300 + 800, 100);
}

void MainWindow::SelectViewMode(int i){
	glut->SetViewMode((VIEW_MODE)i);
}
