/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_O;
    QAction *action_L;
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QListWidget *listWidgetM;
    QPushButton *btnDel;
    QPushButton *btnAdd;
    QRadioButton *hided;
    QLineEdit *lineEdit;
    QLabel *label_10;
    QWidget *tab_2;
    QWidget *layoutWidget;
    QGridLayout *gridLayout_3;
    QLabel *label_5;
    QLineEdit *lineEditDX;
    QLabel *label_6;
    QLineEdit *lineEditDY;
    QLabel *label_7;
    QLineEdit *lineEditDZ;
    QPushButton *btnAddShape;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *shapeLabel;
    QComboBox *comboBoxShape;
    QWidget *tab_3;
    QPushButton *btnSetLight;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_9;
    QComboBox *comboBoxLight;
    QWidget *widget2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QLineEdit *lineEditX;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_3;
    QLineEdit *lineEditY;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_4;
    QLineEdit *lineEditZ;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_8;
    QLineEdit *lineEditZ_2;
    QComboBox *comboBox;
    QLabel *label;
    QMenuBar *menubar;
    QMenu *menu_S;
    QMenu *menu_P;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(300, 800);
        action_O = new QAction(MainWindow);
        action_O->setObjectName(QStringLiteral("action_O"));
        action_L = new QAction(MainWindow);
        action_L->setObjectName(QStringLiteral("action_L"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(10, 220, 278, 521));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        listWidgetM = new QListWidget(tab);
        listWidgetM->setObjectName(QStringLiteral("listWidgetM"));
        listWidgetM->setGeometry(QRect(9, 9, 256, 301));
        btnDel = new QPushButton(tab);
        btnDel->setObjectName(QStringLiteral("btnDel"));
        btnDel->setGeometry(QRect(150, 430, 104, 32));
        btnAdd = new QPushButton(tab);
        btnAdd->setObjectName(QStringLiteral("btnAdd"));
        btnAdd->setGeometry(QRect(20, 430, 104, 32));
        hided = new QRadioButton(tab);
        hided->setObjectName(QStringLiteral("hided"));
        hided->setGeometry(QRect(150, 360, 127, 28));
        lineEdit = new QLineEdit(tab);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(102, 320, 151, 28));
        label_10 = new QLabel(tab);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(20, 320, 83, 22));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        layoutWidget = new QWidget(tab_2);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 70, 231, 101));
        gridLayout_3 = new QGridLayout(layoutWidget);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout_3->addWidget(label_5, 0, 0, 1, 1);

        lineEditDX = new QLineEdit(layoutWidget);
        lineEditDX->setObjectName(QStringLiteral("lineEditDX"));

        gridLayout_3->addWidget(lineEditDX, 0, 1, 1, 1);

        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout_3->addWidget(label_6, 1, 0, 1, 1);

        lineEditDY = new QLineEdit(layoutWidget);
        lineEditDY->setObjectName(QStringLiteral("lineEditDY"));

        gridLayout_3->addWidget(lineEditDY, 1, 1, 1, 1);

        label_7 = new QLabel(layoutWidget);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout_3->addWidget(label_7, 2, 0, 1, 1);

        lineEditDZ = new QLineEdit(layoutWidget);
        lineEditDZ->setObjectName(QStringLiteral("lineEditDZ"));

        gridLayout_3->addWidget(lineEditDZ, 2, 1, 1, 1);

        btnAddShape = new QPushButton(tab_2);
        btnAddShape->setObjectName(QStringLiteral("btnAddShape"));
        btnAddShape->setGeometry(QRect(20, 190, 104, 32));
        widget = new QWidget(tab_2);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(20, 20, 211, 31));
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        shapeLabel = new QLabel(widget);
        shapeLabel->setObjectName(QStringLiteral("shapeLabel"));

        horizontalLayout_2->addWidget(shapeLabel);

        comboBoxShape = new QComboBox(widget);
        comboBoxShape->setObjectName(QStringLiteral("comboBoxShape"));

        horizontalLayout_2->addWidget(comboBoxShape);

        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        btnSetLight = new QPushButton(tab_3);
        btnSetLight->setObjectName(QStringLiteral("btnSetLight"));
        btnSetLight->setGeometry(QRect(20, 60, 104, 32));
        widget1 = new QWidget(tab_3);
        widget1->setObjectName(QStringLiteral("widget1"));
        widget1->setGeometry(QRect(20, 20, 144, 30));
        horizontalLayout_7 = new QHBoxLayout(widget1);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        label_9 = new QLabel(widget1);
        label_9->setObjectName(QStringLiteral("label_9"));

        horizontalLayout_7->addWidget(label_9);

        comboBoxLight = new QComboBox(widget1);
        comboBoxLight->setObjectName(QStringLiteral("comboBoxLight"));

        horizontalLayout_7->addWidget(comboBoxLight);

        tabWidget->addTab(tab_3, QString());
        widget2 = new QWidget(centralwidget);
        widget2->setObjectName(QStringLiteral("widget2"));
        widget2->setGeometry(QRect(20, 60, 189, 140));
        verticalLayout = new QVBoxLayout(widget2);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_2 = new QLabel(widget2);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_3->addWidget(label_2);

        lineEditX = new QLineEdit(widget2);
        lineEditX->setObjectName(QStringLiteral("lineEditX"));

        horizontalLayout_3->addWidget(lineEditX);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_3 = new QLabel(widget2);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_4->addWidget(label_3);

        lineEditY = new QLineEdit(widget2);
        lineEditY->setObjectName(QStringLiteral("lineEditY"));

        horizontalLayout_4->addWidget(lineEditY);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_4 = new QLabel(widget2);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_5->addWidget(label_4);

        lineEditZ = new QLineEdit(widget2);
        lineEditZ->setObjectName(QStringLiteral("lineEditZ"));

        horizontalLayout_5->addWidget(lineEditZ);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_8 = new QLabel(widget2);
        label_8->setObjectName(QStringLiteral("label_8"));

        horizontalLayout_6->addWidget(label_8);

        lineEditZ_2 = new QLineEdit(widget2);
        lineEditZ_2->setObjectName(QStringLiteral("lineEditZ_2"));

        horizontalLayout_6->addWidget(lineEditZ_2);


        verticalLayout->addLayout(horizontalLayout_6);

        comboBox = new QComboBox(centralwidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(110, 21, 121, 28));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(21, 21, 78, 22));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 300, 32));
        menu_S = new QMenu(menubar);
        menu_S->setObjectName(QStringLiteral("menu_S"));
        menu_S->setGeometry(QRect(273, 158, 124, 86));
        menu_P = new QMenu(menubar);
        menu_P->setObjectName(QStringLiteral("menu_P"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menu_S->menuAction());
        menubar->addAction(menu_P->menuAction());
        menu_S->addAction(action_O);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Control", 0));
        action_O->setText(QApplication::translate("MainWindow", "\346\211\223\345\274\200(&O)...", 0));
        action_L->setText(QApplication::translate("MainWindow", "\345\205\211\347\205\247(&L)", 0));
        btnDel->setText(QApplication::translate("MainWindow", "\345\210\240\351\231\244(&D)", 0));
        btnAdd->setText(QApplication::translate("MainWindow", "\346\267\273\345\212\240(&A)", 0));
        hided->setText(QApplication::translate("MainWindow", "\346\230\276\347\244\272\346\250\241\345\236\213", 0));
        label_10->setText(QApplication::translate("MainWindow", "\345\220\215\347\247\260\357\274\232", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "\346\250\241\345\236\213", 0));
        label_5->setText(QApplication::translate("MainWindow", "dx:", 0));
        label_6->setText(QApplication::translate("MainWindow", "dy:", 0));
        label_7->setText(QApplication::translate("MainWindow", "dz:", 0));
        btnAddShape->setText(QApplication::translate("MainWindow", "\346\267\273\345\212\240(&A)", 0));
        shapeLabel->setText(QApplication::translate("MainWindow", "\345\275\242\347\212\266\357\274\232", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "\345\275\242\347\212\266", 0));
        btnSetLight->setText(QApplication::translate("MainWindow", "PushButton", 0));
        label_9->setText(QApplication::translate("MainWindow", "\345\217\202\346\225\260:", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MainWindow", "\345\205\211\347\205\247", 0));
        label_2->setText(QApplication::translate("MainWindow", "X:", 0));
        label_3->setText(QApplication::translate("MainWindow", "Y:", 0));
        label_4->setText(QApplication::translate("MainWindow", "Z:", 0));
        label_8->setText(QApplication::translate("MainWindow", "W:", 0));
        label->setText(QApplication::translate("MainWindow", "\346\230\276\347\244\272\346\250\241\345\274\217:", 0));
        menu_S->setTitle(QApplication::translate("MainWindow", "\346\226\207\344\273\266(&F)", 0));
        menu_P->setTitle(QApplication::translate("MainWindow", "\345\217\202\346\225\260(&P)", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
