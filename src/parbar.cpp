#include "parbar.h"
#include "ui_parbar.h"
#include <iostream>
using namespace std;

ParBar::ParBar(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

	ui->comboBox->addItem("纹理模式", TEX_MODE);
	ui->comboBox->addItem("面模式", FACE_MODE);
	ui->comboBox->addItem("线模式", LINE_MODE);
	ui->comboBox->addItem("点模式", POINT_MODE);
	connect(ui->comboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(SelectViewMode(int)));

	ui->lineEditX->setValidator(new QDoubleValidator(-1000, 1000, 4, this));
	ui->lineEditY->setValidator(new QDoubleValidator(-1000, 1000, 4, this));
	ui->lineEditZ->setValidator(new QDoubleValidator(-1000, 1000, 4, this));
	ui->lineEditW->setValidator(new QDoubleValidator(-1000, 1000, 4, this));
	ui->comboBoxShape->addItem("正方形");
	ui->comboBoxShape->addItem("圆锥");
	connect(ui->btnAddShape, SIGNAL(clicked()), this, SLOT(AddShape()));
}

ParBar::~ParBar(){
    delete ui;
}

void ParBar::SetGL(QtGL *_gl){
	gl = _gl;
}

void ParBar::SelectViewMode(int i){
	if (i >= 0){
		gl -> SetViewMode((VIEW_MODE)i);
	}
}

void ParBar::UpdatePar(){
	int n = gl->models.size();
	cout << n << endl;
	ui->listWidgetM->clear();
	for (int i = 0;i < n;++i){
		ui->listWidgetM->addItem(QString::fromStdString(gl->models[i].name));
	}
}

void ParBar::AddShape(){
	UpdatePar();
}
