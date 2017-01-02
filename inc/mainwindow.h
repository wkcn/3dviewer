#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#ifndef OS_LINUX
#pragma execution_character_set("utf-8")
#endif
#include <QMainWindow>
#include <QDesktopWidget>
#include "qtgl.h"
#include "parbar.h"
#include <QFileDialog>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private:
    Ui::MainWindow *ui;
	ParBar *bar;
    QtGL *gl;
public slots:
    void OpenFile(bool);
};

#endif // MAINWINDOW_H
