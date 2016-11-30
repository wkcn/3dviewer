#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#ifndef OS_LINUX
#pragma execution_character_set("utf-8")
#endif
#include <QMainWindow>
#include <QDesktopWidget>
#include "qtgl.h"
#include "parbar.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void wheelEvent(QWheelEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;
private:
    Ui::MainWindow *ui;
	ParBar *bar;
    QtGL *gl;
};

#endif // MAINWINDOW_H
