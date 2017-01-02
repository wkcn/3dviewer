#ifndef PARBAR_H
#define PARBAR_H

#ifndef OS_LINUX
#pragma execution_character_set("utf-8")
#endif
#include <QMainWindow>
#include <QTableWidgetItem>
#include <QFileDialog>
#include <QTimer>
#include "qtgl.h"

namespace Ui {
class ParBar;
}

class ParBar : public QMainWindow
{
    Q_OBJECT

public:
    Ui::ParBar *ui;
    explicit ParBar(QWidget *parent = 0);
    ~ParBar();
public:
	void SetGL(QtGL*);
	void UpdatePar();
	void UpdateFixPar();
private:
    glm::mat4 GetChangeMat(int kind);
    void AddShape(Model &);
private:
	QtGL *gl;
	QLineEdit *matEdit[4][4];
    QTimer timer;

private slots:
	void SelectModel(int);
	void SelectViewMode(int);
	void SelectFixMode(int);
	void IChange();
	void Change();
	void FixApply();
    void OpenFile(bool);
    void DeleteModel(bool);
    void UpdateMousePos(glm::vec3);
    void SelectModelID(int);
    void ButtomLight();
    void HeadLight();
    void FortyFiveLight();
    void EnvironmentLight();
    void yellowLight();
    void blueLight();
    void redLight();
    void whiteLight();
    void OnModelHided(bool);
    void OnModelTex(bool);
    void OnModelChangeName();
    void on_btn_save_clicked();
    void on_btn_tex_clicked();
    // add shape
    void pushButton1();
    void pushButton2();
    void pushButton3();
    void pushButton4();
    void pushButton5();
    void pushButton6();
    void pushButton7();
    void pushButton8();
    void pushButton9();
    void pushButton10();
    void on_AxisViewed_clicked(bool checked);
    void on_horizontalSlider_valueChanged(int value);
    void on_Timer();
};

#endif
