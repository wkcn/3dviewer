#ifndef PARBAR_H
#define PARBAR_H

#ifndef OS_LINUX
#pragma execution_character_set("utf-8")
#endif
#include <QMainWindow>
#include <QTableWidgetItem>
#include <QFileDialog>
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
private:
	QtGL *gl;
	QLineEdit *matEdit[4][4];

private slots:
	void SelectModel(int);
	void SelectViewMode(int);
	void SelectFixMode(int);
	void AddShape();
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
};

#endif
