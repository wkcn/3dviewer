#include "parbar.h"
#include "ui_parbar.h"
#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <QMessageBox>
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
    ui->comboBox->addItem("水晶质感");
    ui->comboBox->addItem("材质模式");
	connect(ui->comboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(SelectViewMode(int)));

	ui->lineEditX->setValidator(new QDoubleValidator(-1000, 1000, 4, this));
	ui->lineEditY->setValidator(new QDoubleValidator(-1000, 1000, 4, this));
	ui->lineEditZ->setValidator(new QDoubleValidator(-1000, 1000, 4, this));
	ui->lineEditW->setValidator(new QDoubleValidator(-1000, 1000, 4, this));

	QString s = "0";
	ui->lineEditX->setText(s);
	ui->lineEditY->setText(s);
	ui->lineEditZ->setText(s);
	ui->lineEditW->setText(s);

    ui->AxisViewed->setChecked(true);


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
            matEdit[r][c]->setFocusPolicy(Qt::NoFocus);
            QString s;
			s.setNum(int(r == c));
			matEdit[r][c]->setText(s);
		}
	}


    connect(ui->comboBox_fix, SIGNAL(currentIndexChanged(int)), this, SLOT(SelectFixMode(int)));

    connect(ui->btn_ichange, SIGNAL(clicked()), this, SLOT(IChange()));
	connect(ui->btn_change, SIGNAL(clicked()), this, SLOT(Change()));
	connect(ui->btn_fix_apply, SIGNAL(clicked()), this, SLOT(FixApply()));

    connect(ui->btnAdd, SIGNAL(clicked(bool)), this, SLOT(OpenFile(bool)));
    connect(ui->btnDel, SIGNAL(clicked(bool)), this, SLOT(DeleteModel(bool)));
    connect(ui->foutyFiveLight, SIGNAL(clicked()), this, SLOT(FortyFiveLight()));
    connect(ui->bottomLight, SIGNAL(clicked()), this, SLOT(ButtomLight()));
    connect(ui->environmentLight, SIGNAL(clicked()), this, SLOT(EnvironmentLight()));


    connect(ui->blueLight, SIGNAL(clicked()), this, SLOT(blueLight()));
    connect(ui->whiteLight, SIGNAL(clicked()), this, SLOT(whiteLight()));
    connect(ui->redLight, SIGNAL(clicked()), this, SLOT(redLight()));
    connect(ui->yellowLight, SIGNAL(clicked()), this, SLOT(yellowLight()));

    connect(ui->checkBox_md, SIGNAL(clicked(bool)), this, SLOT(OnModelHided(bool)));
    connect(ui->checkBox_tex, SIGNAL(clicked(bool)), this, SLOT(OnModelTex(bool)));
    connect(ui->md_name, SIGNAL(editingFinished()), this, SLOT(OnModelChangeName()));

    // 添加形状
    //模型 pushButton
    connect(ui->pushButton_1, SIGNAL(clicked()), this, SLOT(pushButton1()));
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(pushButton2()));
    connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(pushButton3()));
    connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(pushButton4()));
    connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(pushButton5()));
    connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(pushButton6()));
    connect(ui->pushButton_7, SIGNAL(clicked()), this, SLOT(pushButton7()));
    connect(ui->pushButton_8, SIGNAL(clicked()), this, SLOT(pushButton8()));
    connect(ui->pushButton_9, SIGNAL(clicked()), this, SLOT(pushButton9()));
    connect(ui->pushButton_10, SIGNAL(clicked()), this, SLOT(pushButton10()));

    connect(ui->AxisViewed, SIGNAL(clicked(bool)), this, SLOT(on_AxisViewed_clicked(bool)));
    connect(&timer, SIGNAL(timeout()), this, SLOT(on_Timer()));

}

void ParBar::on_Timer(){
    Change();
}

void ParBar::ButtomLight(){
    gl->EnvironmentLight[0] = 0;
    gl->EnvironmentLight[1] = 0;
    gl->EnvironmentLight[2] = 0;
    gl->EnvironmentLight[3] = 0;

    gl->DiffuseLight[0] = 1;
    gl->DiffuseLight[1] = 1;
    gl->DiffuseLight[2] = 1;
    gl->DiffuseLight[3] = 1;

    gl->LightPostion[0] = 0;
    gl->LightPostion[1] = 0;
    gl->LightPostion[2] = 2;
    gl->LightPostion[3] = 1;

    gl->update();
}
void ParBar::HeadLight(){

    gl->EnvironmentLight[0] = 0;
    gl->EnvironmentLight[1] = 0;
    gl->EnvironmentLight[2] = 0;
    gl->EnvironmentLight[3] = 0;

    gl->DiffuseLight[0] = 1;
    gl->DiffuseLight[1] = 1;
    gl->DiffuseLight[2] = 1;
    gl->DiffuseLight[3] = 1;

    gl->LightPostion[0] = 0;
    gl->LightPostion[1] = 0;
    gl->LightPostion[2] = -2;
    gl->LightPostion[3] = 1;

    gl->update();
};
void ParBar::FortyFiveLight(){

    gl->EnvironmentLight[0] = 0;
    gl->EnvironmentLight[1] = 0;
    gl->EnvironmentLight[2] = 0;
    gl->EnvironmentLight[3] = 0;

    gl->DiffuseLight[0] = 1;
    gl->DiffuseLight[1] = 1;
    gl->DiffuseLight[2] = 1;
    gl->DiffuseLight[3] = 1;

    gl->LightPostion[0] = 2;
    gl->LightPostion[1] = 2;
    gl->LightPostion[2] = 2;
    gl->LightPostion[3] = 1;
    gl->update();
};
void ParBar::EnvironmentLight(){

    gl->EnvironmentLight[0] = 1;
    gl->EnvironmentLight[1] = 1;
    gl->EnvironmentLight[2] = 1;
    gl->EnvironmentLight[3] = 1;

    gl->DiffuseLight[0] = 0;
    gl->DiffuseLight[1] = 0;
    gl->DiffuseLight[2] = 0;
    gl->DiffuseLight[3] = 0;

    gl->LightPostion[0] = 2;
    gl->LightPostion[1] = 2;
    gl->LightPostion[2] = 2;
    gl->LightPostion[3] = 1;
    gl->update();
};

void ParBar::yellowLight(){
    gl->DiffuseLight[0] = 1;
    gl->DiffuseLight[1] = 1;
    gl->DiffuseLight[2] = 1;
    gl->DiffuseLight[2] = 0;
    gl->update();
}


void ParBar::redLight(){
    gl->DiffuseLight[0] = 1;
    gl->DiffuseLight[1] = 1;
    gl->DiffuseLight[2] = 1;
    gl->DiffuseLight[1] = 0;
    gl->DiffuseLight[2] = 0;
    gl->update();
}


void ParBar::blueLight(){
    gl->DiffuseLight[0] = 1;
    gl->DiffuseLight[1] = 1;
    gl->DiffuseLight[2] = 1;
    gl->DiffuseLight[0] = 0;
    gl->DiffuseLight[1] = 0;
    gl->update();
}


void ParBar::whiteLight(){
    gl->DiffuseLight[0] = 1;
    gl->DiffuseLight[1] = 1;
    gl->DiffuseLight[2] = 1;
    gl->update();
}

ParBar::~ParBar(){
    delete ui;
}

void ParBar::SetGL(QtGL *_gl){
	gl = _gl;
    connect(gl, SIGNAL(UpdateMousePosS(glm::vec3)), this, SLOT(UpdateMousePos(glm::vec3)));
    connect(gl, SIGNAL(SelectModelID(int)), this, SLOT(SelectModelID(int)));
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
            mat = glm::rotate(glm::mat4(1.0),float(w * PI / 180), glm::vec3(x, y, z));
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
        for (int r = 0; r < 4;++r){
            for (int c = 0;c < 4;++c){
                QString s;
                s.setNum(gl->models[mid].mat[r][c]);
                matEdit[r][c]->setText(s);
            }
        }
	}
}
void ParBar::SelectModel(int i){
	size_t mid = ui->listWidgetM->currentRow();
	if (mid >= gl->models.size())return;
    if (gl -> models.size() > 0){
		if (i >= int(gl->models.size()))i = 0;
        Model &md = gl->models[i];
        QString s = QString("选择模型: %1(%2)").arg(QString::fromStdString(md.name)).arg(md.id);
		ui->label_fix_name->setText(s);
        ui->checkBox_md->setChecked(md.viewed);
        ui->checkBox_tex->setChecked(md.texed);
        ui->md_name->setText(QString::fromStdString(md.name));
		UpdateFixPar();
        gl->SELECTED_MODEL = &md;
        gl->update();
	}
}

void ParBar::UpdateFixPar(){
	size_t mid = ui->listWidgetM->currentRow();
	if (mid >= gl->models.size())return;
    if (ui->comboBox_fix->currentIndex() != 3){
        for (int r = 0; r < 4;++r){
            for (int c = 0;c < 4;++c){
                QString s;
                s.setNum(gl->models[mid].mat[r][c]);
                matEdit[r][c]->setText(s);
            }
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
    if (i <= 2){
        for (int r = 0; r < 4;++r){
            for (int c = 0;c < 4;++c){
                matEdit[r][c]->setFocusPolicy(Qt::NoFocus);
            }
        }
    }else{
        for (int r = 0; r < 4;++r){
            for (int c = 0;c < 4;++c){
                matEdit[r][c]->setFocusPolicy(Qt::StrongFocus);
            }
        }
    }
    if (i != 4)
        ui->btn_change->setText("正变换(&C)");
    else
        ui->btn_change->setText("设置(&S)");
    ui->btn_ichange->setEnabled(i != 4);

}

void ParBar::OpenFile(bool){
    QString filename = QFileDialog::getOpenFileName(this, "Select a *.obj file", "", "*.obj");
    if (filename.size()){
        gl->addModel(filename);
        Model &md = *(gl->models.end() - 1);
        AddShape(md);
    }
}

void ParBar::DeleteModel(bool){
    size_t mid = ui->listWidgetM->currentRow();
    if (mid >= gl->models.size())return;
    gl->models.erase(gl->models.begin() + mid);
    UpdatePar();
    gl->update();
}

void ParBar::UpdateMousePos(glm::vec3 v){
    char tmp[128];
    sprintf(tmp, "顶点坐标：%lf, %lf, %lf", v.x, v.y, v.z);
    ui->label_pos->setText(tmp);
}

void ParBar::SelectModelID(int id){
    for (size_t i = 0;i < gl->models.size();++i){
        if (gl->models[i].id == id){
            ui->listWidgetM->setCurrentRow(i);
            break;
        }
    }
}

void ParBar::OnModelHided(bool viewed){
    size_t mid = ui->listWidgetM->currentRow();
    if (mid >= gl->models.size())return;
    Model &md = gl->models[mid];
    md.viewed = viewed;
    gl->update();
}

void ParBar::OnModelTex(bool viewed){
    size_t mid = ui->listWidgetM->currentRow();
    if (mid >= gl->models.size())return;
    Model &md = gl->models[mid];
    md.texed = viewed;
    gl->update();
}

void ParBar::OnModelChangeName(){
    size_t mid = ui->listWidgetM->currentRow();
    if (mid >= gl->models.size())return;
    gl->models[mid].name = ui->md_name->text().toStdString();
    UpdatePar();
    ui->listWidgetM->setCurrentRow(mid);
}

void ParBar::on_btn_save_clicked(){
    size_t mid = ui->listWidgetM->currentRow();
    if (mid >= gl->models.size()){
        QMessageBox::information(this,"提示","请选择一个模型");
        return;
    }
    QString filename = QFileDialog::getSaveFileName(this, "Save to a *.obj file", "", "*.obj");
    gl->models[mid].Save(filename.toStdString());
}

void ParBar::on_btn_tex_clicked(){
    size_t mid = ui->listWidgetM->currentRow();
    if (mid >= gl->models.size()){
        QMessageBox::information(this,"提示","请选择一个模型");
        return;
    }
    QString filename = QFileDialog::getOpenFileName(this, "Select a picture file", "", "Images (*.png *.bmp *.jpg *.tif *.GIF )");
    gl->models[mid].tex_name = filename.toStdString();
    gl->update();
}

//正方体
void ParBar::pushButton1(){
    Model md = GetCube(2, 2, 2);
    gl->models.push_back(md);
    AddShape(*(gl->models.end() - 1));
}
//三棱锥
void ParBar::pushButton2(){
    Model md = GetCone(1, 2, 3);
    md.name = "三棱锥";
    gl->models.push_back(md);
    AddShape(*(gl->models.end() - 1));
}
//四棱锥
void ParBar::pushButton3(){
    Model md = GetCone(1, 2, 4);
    md.name = "四棱锥";
    gl->models.push_back(md);

    AddShape(*(gl->models.end() - 1));
}
//三棱柱
void ParBar::pushButton4(){
    Model md = GetPodetium(1, 2, 3);
    md.name = "三棱柱";
    gl->models.push_back(md);
    AddShape(*(gl->models.end() - 1));
}
//六棱柱
void ParBar::pushButton5(){
    Model md = GetPodetium(1, 2, 6);
    md.name = "六棱柱";
    gl->models.push_back(md);
    AddShape(*(gl->models.end() - 1));
}
//球体
void ParBar::pushButton6(){
    Model md = GetBall(1, 100, 100);
    gl->models.push_back(md);
    AddShape(*(gl->models.end() - 1));
}
//圆锥体
void ParBar::pushButton7(){
    Model md = GetCone(1, 2, 100);
    gl->models.push_back(md);
    AddShape(*(gl->models.end() - 1));
}
//圆柱体
void ParBar::pushButton8(){
    Model md = GetPodetium(1, 2, 100);
    gl->models.push_back(md);
    AddShape(*(gl->models.end() - 1));
}
//长方体
void ParBar::pushButton9(){
    Model md = GetCube(2, 2, 3);
    gl->models.push_back(md);
    AddShape(*(gl->models.end() - 1));
}

void ParBar::pushButton10(){
    Model md = GetLoudou(1, 100, 100);
    gl->models.push_back(md);
    AddShape(*(gl->models.end() - 1));
}

void ParBar::AddShape(Model &md){
    double x = ui->lineEditX->text().toDouble();
    double y = ui->lineEditY->text().toDouble();
    double z = ui->lineEditZ->text().toDouble();
    md.mat = glm::translate(md.mat, glm::vec3(x,y,z));
    UpdatePar();
    gl->update();
}


void ParBar::on_AxisViewed_clicked(bool checked){
    gl->AxisViewed = checked;
    gl->update();
}

void ParBar::on_horizontalSlider_valueChanged(int value)
{
    //cout << value << endl;
    if (value == 0)timer.stop();
    else{
        timer.start(1000 / value);
    }
}
