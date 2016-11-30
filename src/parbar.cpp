#include "parbar.h"
#include "ui_parbar.h"
#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
using namespace std;

ParBar::ParBar(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ParBar)
{
    ui->setupUi(this);
    ui->comboBox->addItem("纹理模式");
    ui->comboBox->addItem("面模式");
    ui->comboBox->addItem("线模式");
    ui->comboBox->addItem("点模式");
	connect(ui->comboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(SelectViewMode(int)));
	connect(ui->comboBox_fix, SIGNAL(currentIndexChanged(int)), this, SLOT(SelectFixMode(int)));

	ui->lineEditX->setValidator(new QDoubleValidator(-1000, 1000, 4, this));
	ui->lineEditY->setValidator(new QDoubleValidator(-1000, 1000, 4, this));
	ui->lineEditZ->setValidator(new QDoubleValidator(-1000, 1000, 4, this));
	ui->lineEditW->setValidator(new QDoubleValidator(-1000, 1000, 4, this));

	QString s = "0";
	ui->lineEditX->setText(s);
	ui->lineEditY->setText(s);
	ui->lineEditZ->setText(s);
	ui->lineEditW->setText(s);

	ui->comboBoxShape->addItem("正方形");
	ui->comboBoxShape->addItem("圆锥");
	connect(ui->btnAddShape, SIGNAL(clicked()), this, SLOT(AddShape()));

	connect(ui->listWidgetM, SIGNAL(currentRowChanged(int)), this, SLOT(SelectModel(int)));  

	ui->comboBox_fix->addItem("平移");
	ui->comboBox_fix->addItem("旋转");
	ui->comboBox_fix->addItem("放缩");
    ui->comboBox_fix->addItem("变换矩阵");
    ui->comboBox_fix->addItem("局部矩阵设置");
	// 生成4x4矩阵
	ui->label_fix_name->setText("未选择模型");
	for (int r = 0;r < 4;++r){
		for (int c = 0;c < 4;++c){
			matEdit[r][c] = new QLineEdit(ui->widget_mat); 
			matEdit[r][c]->setGeometry(QRect(r * 50,c * 50,48,48));
			matEdit[r][c]->setValidator(new QDoubleValidator(-1000, 1000, 4, this));
			QString s;
			s.setNum(int(r == c));
			matEdit[r][c]->setText(s);
		}
	}
	connect(ui->btn_ichange, SIGNAL(clicked()), this, SLOT(IChange()));
	connect(ui->btn_change, SIGNAL(clicked()), this, SLOT(Change()));
	connect(ui->btn_fix_apply, SIGNAL(clicked()), this, SLOT(FixApply()));
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

glm::mat4 ParBar::GetChangeMat(int kind){
	double x = ui->lineEditX->text().toDouble(); 
	double y = ui->lineEditY->text().toDouble(); 
	double z = ui->lineEditZ->text().toDouble(); 
	double w = ui->lineEditW->text().toDouble(); 
	glm::mat4 mat;
	switch(kind){
		// 平移 
		case 0:
			mat = glm::translate(glm::mat4(1.0), glm::vec3(x, y, z));
			break;
		// 旋转
		case 1:
			mat = glm::rotate(glm::mat4(1.0),float(w), glm::vec3(x, y, z));
			break;
		// 放缩
		case 2:
			mat = glm::scale(glm::mat4(1.0),glm::vec3(x, y, z));
			break;
        // 矩阵
		case 3:
			for (int r = 0;r < 4;++r){
				for (int c = 0;c < 4;++c){
					mat[r][c] = matEdit[r][c]->text().toDouble(); 
				}
			}
	}
	return mat;
}
void ParBar::IChange(){
	size_t mid = ui->listWidgetM->currentRow();
	if (mid >= gl->models.size())return;
	glm::mat4 &mat = gl->models[mid].mat; 
	glm::mat4 q = GetChangeMat(ui->comboBox_fix->currentIndex());
	mat = mat * glm::inverse(q);
	UpdateFixPar();
	gl->update();
}
void ParBar::Change(){
	size_t mid = ui->listWidgetM->currentRow();
	if (mid >= gl->models.size())return;
    glm::mat4 &mat = gl->models[mid].mat;
    int kind = ui->comboBox_fix->currentIndex();
    if (kind == 4){
        for (int r = 0;r < 4;++r){
            for (int c = 0;c < 4;++c){
                mat[r][c] = matEdit[r][c]->text().toDouble();
            }
        }
    }else{
        mat = mat * GetChangeMat(kind);
    }
	UpdateFixPar();
	gl->update();
}
void ParBar::FixApply(){
	size_t mid = ui->listWidgetM->currentRow();
	if (mid < gl->models.size()){
		gl->models[mid].MatMapVertices();
		UpdateFixPar();
	}
}
void ParBar::SelectModel(int i){
	size_t mid = ui->listWidgetM->currentRow();
	if (mid >= gl->models.size())return;
	if (gl -> models.size() > 0){
		if (i >= int(gl->models.size()))i = 0;
		QString s = QString("选择模型: %1(%2)").arg(QString::fromStdString(gl->models[i].name)).arg(i);
		ui->label_fix_name->setText(s);
		UpdateFixPar();
	}
}

void ParBar::UpdateFixPar(){
	size_t mid = ui->listWidgetM->currentRow();
	if (mid >= gl->models.size())return;
	for (int r = 0; r < 4;++r){
		for (int c = 0;c < 4;++c){
			QString s;
			s.setNum(gl->models[mid].mat[r][c]);
			matEdit[r][c]->setText(s);
		}
	}
}

void ParBar::SelectFixMode(int i){
	ui->lineEditW->setText("0");
    switch(i){
	case 0:
	case 1:
        ui->lineEditX->setText("0");
		ui->lineEditY->setText("0");
		ui->lineEditZ->setText("0");
		break;
	case 2:
		ui->lineEditX->setText("1");
		ui->lineEditY->setText("1");
		ui->lineEditZ->setText("1");
		break;
    case 3:
        for (int r = 0;r < 4;++r){
            for (int c = 0;c < 4;++c){
                QString s;
                s.setNum(int(r == c));
                matEdit[r][c]->setText(s);
            }
        }
        break;
    case 4:
        break;
	}
    if (i != 4)
        ui->btn_change->setText("正变换(&C)");
    else
        ui->btn_change->setText("设置(&S)");
    ui->btn_ichange->setEnabled(i != 4);

}
