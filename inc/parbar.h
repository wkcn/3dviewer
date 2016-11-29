#ifndef PARBAR_H
#define PARBAR_H

#include <QMainWindow>
#include <QTableWidgetItem>
#include "qtgl.h"

namespace Ui {
class MainWindow;
}

class ParBar : public QMainWindow
{
    Q_OBJECT

public:
    Ui::MainWindow *ui;
    explicit ParBar(QWidget *parent = 0);
    ~ParBar();
public:
	void SetGL(QtGL*);
	void UpdatePar();
private:
	QtGL *gl;

private slots:
	void SelectViewMode(int);
	void AddShape();
};

#endif
