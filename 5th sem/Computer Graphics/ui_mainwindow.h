/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.0.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include <my_label.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    my_label *frame;
    QLabel *mouse_movement;
    QLabel *label_3;
    QLabel *mouse_pressed;
    QLabel *label_5;
    QFrame *x_axis;
    QFrame *y_axis;
    QCheckBox *show_axes;
    QSpinBox *circle_radius;
    QPushButton *set_point1;
    QPushButton *set_point2;
    QPushButton *resetButton;
    QSpinBox *gridspinbox;
    QPushButton *setgridbutton;
    QPushButton *drawcircleButton;
    QPushButton *DDAButton;
    QPushButton *bresenhamButton;
    QLabel *circlelabel;
    QLabel *linelabel;
    QPushButton *bresenhamCircleButton;
    QLabel *ellipselabel;
    QSpinBox *valueAspinBox;
    QSpinBox *valueBspinBox;
    QPushButton *drawEllipsepushButton;
    QLabel *filllLabel;
    QPushButton *scanlineButton;
    QPushButton *boundaryfillButton;
    QPushButton *floodfillButton;
    QLabel *label;
    QPushButton *setVertexButton;
    QGroupBox *transformationBox;
    QPushButton *translateButton;
    QLabel *label_2;
    QLabel *label_4;
    QSpinBox *trans_x;
    QSpinBox *trans_y;
    QLabel *label_6;
    QLabel *label_7;
    QSpinBox *scale_x;
    QSpinBox *scale_y;
    QPushButton *scaleButton;
    QPushButton *rotateButton;
    QPushButton *shearButton;
    QLabel *label_8;
    QLabel *label_9;
    QSpinBox *rotate_angle;
    QSpinBox *shear_x;
    QSpinBox *shear_y;
    QPushButton *reflectionButton;
    QPushButton *clearVertexButton;
    QGroupBox *groupBox;
    QPushButton *setCP1Button;
    QPushButton *setCP2Button;
    QPushButton *polygonClippingButton;
    QPushButton *lineClippingButton;
    QLabel *label_10;
    QGroupBox *groupBox_2;
    QPushButton *clearBezButton;
    QPushButton *setBezButton;
    QPushButton *drawBezierButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(999, 736);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        frame = new my_label(centralWidget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(0, -20, 700, 700));
        frame->setMouseTracking(true);
        frame->setStyleSheet(QStringLiteral("background-color: rgb(0, 0, 0);"));
        frame->setFrameShape(QFrame::Box);
        frame->setLineWidth(1);
        mouse_movement = new QLabel(centralWidget);
        mouse_movement->setObjectName(QStringLiteral("mouse_movement"));
        mouse_movement->setGeometry(QRect(720, 70, 111, 31));
        mouse_movement->setFrameShape(QFrame::Panel);
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(720, 50, 111, 20));
        mouse_pressed = new QLabel(centralWidget);
        mouse_pressed->setObjectName(QStringLiteral("mouse_pressed"));
        mouse_pressed->setGeometry(QRect(840, 70, 111, 31));
        mouse_pressed->setFrameShape(QFrame::Panel);
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(860, 50, 81, 20));
        x_axis = new QFrame(centralWidget);
        x_axis->setObjectName(QStringLiteral("x_axis"));
        x_axis->setGeometry(QRect(0, 225, 700, 1));
        x_axis->setStyleSheet(QStringLiteral("background-color: rgb(255, 85, 255);"));
        x_axis->setFrameShape(QFrame::HLine);
        x_axis->setFrameShadow(QFrame::Sunken);
        y_axis = new QFrame(centralWidget);
        y_axis->setObjectName(QStringLiteral("y_axis"));
        y_axis->setGeometry(QRect(225, 0, 1, 700));
        y_axis->setStyleSheet(QLatin1String("\n"
"background-color: rgb(85, 255, 255);"));
        y_axis->setFrameShape(QFrame::VLine);
        y_axis->setFrameShadow(QFrame::Sunken);
        show_axes = new QCheckBox(centralWidget);
        show_axes->setObjectName(QStringLiteral("show_axes"));
        show_axes->setGeometry(QRect(720, 10, 91, 21));
        circle_radius = new QSpinBox(centralWidget);
        circle_radius->setObjectName(QStringLiteral("circle_radius"));
        circle_radius->setGeometry(QRect(790, 110, 46, 20));
        set_point1 = new QPushButton(centralWidget);
        set_point1->setObjectName(QStringLiteral("set_point1"));
        set_point1->setGeometry(QRect(770, 170, 81, 23));
        set_point2 = new QPushButton(centralWidget);
        set_point2->setObjectName(QStringLiteral("set_point2"));
        set_point2->setGeometry(QRect(860, 170, 81, 23));
        resetButton = new QPushButton(centralWidget);
        resetButton->setObjectName(QStringLiteral("resetButton"));
        resetButton->setGeometry(QRect(730, 640, 101, 41));
        gridspinbox = new QSpinBox(centralWidget);
        gridspinbox->setObjectName(QStringLiteral("gridspinbox"));
        gridspinbox->setGeometry(QRect(720, 30, 42, 22));
        gridspinbox->setMinimum(1);
        setgridbutton = new QPushButton(centralWidget);
        setgridbutton->setObjectName(QStringLiteral("setgridbutton"));
        setgridbutton->setGeometry(QRect(770, 30, 75, 23));
        drawcircleButton = new QPushButton(centralWidget);
        drawcircleButton->setObjectName(QStringLiteral("drawcircleButton"));
        drawcircleButton->setGeometry(QRect(720, 140, 121, 21));
        DDAButton = new QPushButton(centralWidget);
        DDAButton->setObjectName(QStringLiteral("DDAButton"));
        DDAButton->setGeometry(QRect(720, 200, 91, 21));
        bresenhamButton = new QPushButton(centralWidget);
        bresenhamButton->setObjectName(QStringLiteral("bresenhamButton"));
        bresenhamButton->setGeometry(QRect(820, 200, 121, 21));
        circlelabel = new QLabel(centralWidget);
        circlelabel->setObjectName(QStringLiteral("circlelabel"));
        circlelabel->setGeometry(QRect(720, 110, 61, 21));
        linelabel = new QLabel(centralWidget);
        linelabel->setObjectName(QStringLiteral("linelabel"));
        linelabel->setGeometry(QRect(720, 170, 61, 21));
        bresenhamCircleButton = new QPushButton(centralWidget);
        bresenhamCircleButton->setObjectName(QStringLiteral("bresenhamCircleButton"));
        bresenhamCircleButton->setGeometry(QRect(850, 140, 131, 23));
        ellipselabel = new QLabel(centralWidget);
        ellipselabel->setObjectName(QStringLiteral("ellipselabel"));
        ellipselabel->setGeometry(QRect(720, 230, 61, 16));
        valueAspinBox = new QSpinBox(centralWidget);
        valueAspinBox->setObjectName(QStringLiteral("valueAspinBox"));
        valueAspinBox->setGeometry(QRect(780, 230, 42, 22));
        valueBspinBox = new QSpinBox(centralWidget);
        valueBspinBox->setObjectName(QStringLiteral("valueBspinBox"));
        valueBspinBox->setGeometry(QRect(830, 230, 42, 22));
        drawEllipsepushButton = new QPushButton(centralWidget);
        drawEllipsepushButton->setObjectName(QStringLiteral("drawEllipsepushButton"));
        drawEllipsepushButton->setGeometry(QRect(720, 260, 131, 23));
        filllLabel = new QLabel(centralWidget);
        filllLabel->setObjectName(QStringLiteral("filllLabel"));
        filllLabel->setGeometry(QRect(730, 320, 21, 16));
        scanlineButton = new QPushButton(centralWidget);
        scanlineButton->setObjectName(QStringLiteral("scanlineButton"));
        scanlineButton->setGeometry(QRect(910, 320, 75, 23));
        boundaryfillButton = new QPushButton(centralWidget);
        boundaryfillButton->setObjectName(QStringLiteral("boundaryfillButton"));
        boundaryfillButton->setGeometry(QRect(750, 320, 75, 23));
        floodfillButton = new QPushButton(centralWidget);
        floodfillButton->setObjectName(QStringLiteral("floodfillButton"));
        floodfillButton->setGeometry(QRect(830, 320, 75, 23));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(730, 290, 71, 20));
        setVertexButton = new QPushButton(centralWidget);
        setVertexButton->setObjectName(QStringLiteral("setVertexButton"));
        setVertexButton->setGeometry(QRect(800, 290, 75, 23));
        transformationBox = new QGroupBox(centralWidget);
        transformationBox->setObjectName(QStringLiteral("transformationBox"));
        transformationBox->setGeometry(QRect(730, 340, 261, 171));
        translateButton = new QPushButton(transformationBox);
        translateButton->setObjectName(QStringLiteral("translateButton"));
        translateButton->setGeometry(QRect(180, 20, 75, 23));
        label_2 = new QLabel(transformationBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 20, 46, 13));
        label_4 = new QLabel(transformationBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(100, 20, 46, 13));
        trans_x = new QSpinBox(transformationBox);
        trans_x->setObjectName(QStringLiteral("trans_x"));
        trans_x->setGeometry(QRect(30, 20, 42, 22));
        trans_y = new QSpinBox(transformationBox);
        trans_y->setObjectName(QStringLiteral("trans_y"));
        trans_y->setGeometry(QRect(120, 20, 42, 22));
        label_6 = new QLabel(transformationBox);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(10, 50, 46, 13));
        label_7 = new QLabel(transformationBox);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(100, 50, 46, 13));
        scale_x = new QSpinBox(transformationBox);
        scale_x->setObjectName(QStringLiteral("scale_x"));
        scale_x->setGeometry(QRect(30, 50, 42, 22));
        scale_y = new QSpinBox(transformationBox);
        scale_y->setObjectName(QStringLiteral("scale_y"));
        scale_y->setGeometry(QRect(120, 50, 42, 22));
        scaleButton = new QPushButton(transformationBox);
        scaleButton->setObjectName(QStringLiteral("scaleButton"));
        scaleButton->setGeometry(QRect(180, 50, 75, 23));
        rotateButton = new QPushButton(transformationBox);
        rotateButton->setObjectName(QStringLiteral("rotateButton"));
        rotateButton->setGeometry(QRect(180, 80, 75, 23));
        shearButton = new QPushButton(transformationBox);
        shearButton->setObjectName(QStringLiteral("shearButton"));
        shearButton->setGeometry(QRect(180, 110, 75, 23));
        label_8 = new QLabel(transformationBox);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(10, 110, 46, 13));
        label_9 = new QLabel(transformationBox);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(100, 110, 46, 13));
        rotate_angle = new QSpinBox(transformationBox);
        rotate_angle->setObjectName(QStringLiteral("rotate_angle"));
        rotate_angle->setGeometry(QRect(120, 80, 42, 22));
        shear_x = new QSpinBox(transformationBox);
        shear_x->setObjectName(QStringLiteral("shear_x"));
        shear_x->setGeometry(QRect(30, 110, 42, 22));
        shear_y = new QSpinBox(transformationBox);
        shear_y->setObjectName(QStringLiteral("shear_y"));
        shear_y->setGeometry(QRect(120, 110, 42, 22));
        reflectionButton = new QPushButton(transformationBox);
        reflectionButton->setObjectName(QStringLiteral("reflectionButton"));
        reflectionButton->setGeometry(QRect(180, 140, 75, 23));
        clearVertexButton = new QPushButton(centralWidget);
        clearVertexButton->setObjectName(QStringLiteral("clearVertexButton"));
        clearVertexButton->setGeometry(QRect(880, 290, 75, 23));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(730, 510, 261, 81));
        setCP1Button = new QPushButton(groupBox);
        setCP1Button->setObjectName(QStringLiteral("setCP1Button"));
        setCP1Button->setGeometry(QRect(10, 20, 101, 23));
        setCP2Button = new QPushButton(groupBox);
        setCP2Button->setObjectName(QStringLiteral("setCP2Button"));
        setCP2Button->setGeometry(QRect(120, 20, 101, 23));
        polygonClippingButton = new QPushButton(groupBox);
        polygonClippingButton->setObjectName(QStringLiteral("polygonClippingButton"));
        polygonClippingButton->setGeometry(QRect(120, 50, 91, 23));
        lineClippingButton = new QPushButton(groupBox);
        lineClippingButton->setObjectName(QStringLiteral("lineClippingButton"));
        lineClippingButton->setGeometry(QRect(10, 50, 91, 23));
        label_10 = new QLabel(centralWidget);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(810, 430, 46, 13));
        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(730, 590, 261, 51));
        clearBezButton = new QPushButton(groupBox_2);
        clearBezButton->setObjectName(QStringLiteral("clearBezButton"));
        clearBezButton->setGeometry(QRect(0, 20, 75, 23));
        setBezButton = new QPushButton(groupBox_2);
        setBezButton->setObjectName(QStringLiteral("setBezButton"));
        setBezButton->setGeometry(QRect(80, 20, 75, 23));
        drawBezierButton = new QPushButton(groupBox_2);
        drawBezierButton->setObjectName(QStringLiteral("drawBezierButton"));
        drawBezierButton->setGeometry(QRect(170, 20, 75, 23));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 999, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        frame->setText(QString());
        mouse_movement->setText(QString());
        label_3->setText(QApplication::translate("MainWindow", "    Mouse Movement", 0));
        mouse_pressed->setText(QString());
        label_5->setText(QApplication::translate("MainWindow", "Mouse Pressed", 0));
        show_axes->setText(QApplication::translate("MainWindow", "Show Axes", 0));
        set_point1->setText(QApplication::translate("MainWindow", "Set point 1", 0));
        set_point2->setText(QApplication::translate("MainWindow", "Set point 2", 0));
        resetButton->setText(QApplication::translate("MainWindow", "RESET", 0));
        setgridbutton->setText(QApplication::translate("MainWindow", "Set Grid", 0));
        drawcircleButton->setText(QApplication::translate("MainWindow", "Draw Circle(mid point) ", 0));
        DDAButton->setText(QApplication::translate("MainWindow", "Draw line (DDA)", 0));
        bresenhamButton->setText(QApplication::translate("MainWindow", "Draw line (Bresenham)", 0));
        circlelabel->setText(QApplication::translate("MainWindow", "Draw Circle", 0));
        linelabel->setText(QApplication::translate("MainWindow", "Draw Line", 0));
        bresenhamCircleButton->setText(QApplication::translate("MainWindow", "Draw Circle(Bresenham)", 0));
        ellipselabel->setText(QApplication::translate("MainWindow", "Draw Ellipse", 0));
        drawEllipsepushButton->setText(QApplication::translate("MainWindow", "Draw Ellipse (mid point)", 0));
        filllLabel->setText(QApplication::translate("MainWindow", "Fill ", 0));
        scanlineButton->setText(QApplication::translate("MainWindow", "Scanline fill", 0));
        boundaryfillButton->setText(QApplication::translate("MainWindow", "Boundary fill", 0));
        floodfillButton->setText(QApplication::translate("MainWindow", "Flood fill", 0));
        label->setText(QApplication::translate("MainWindow", "Draw Polygon", 0));
        setVertexButton->setText(QApplication::translate("MainWindow", "Set Vertex", 0));
        transformationBox->setTitle(QApplication::translate("MainWindow", "Transformation", 0));
        translateButton->setText(QApplication::translate("MainWindow", "Translate", 0));
        label_2->setText(QApplication::translate("MainWindow", "x:", 0));
        label_4->setText(QApplication::translate("MainWindow", "y:", 0));
        label_6->setText(QApplication::translate("MainWindow", "x:", 0));
        label_7->setText(QApplication::translate("MainWindow", "y:", 0));
        scaleButton->setText(QApplication::translate("MainWindow", "Scale", 0));
        rotateButton->setText(QApplication::translate("MainWindow", "Rotate", 0));
        shearButton->setText(QApplication::translate("MainWindow", "Shear", 0));
        label_8->setText(QApplication::translate("MainWindow", "x:", 0));
        label_9->setText(QApplication::translate("MainWindow", "y:", 0));
        reflectionButton->setText(QApplication::translate("MainWindow", "Reflection", 0));
        clearVertexButton->setText(QApplication::translate("MainWindow", "Clear Vertex", 0));
        groupBox->setTitle(QApplication::translate("MainWindow", "Clipping", 0));
        setCP1Button->setText(QApplication::translate("MainWindow", "Set Corner point 1", 0));
        setCP2Button->setText(QApplication::translate("MainWindow", "Set Corner point 2", 0));
        polygonClippingButton->setText(QApplication::translate("MainWindow", "Polygon Clipping", 0));
        lineClippingButton->setText(QApplication::translate("MainWindow", "Line Clipping", 0));
        label_10->setText(QApplication::translate("MainWindow", "angle:", 0));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Bezier Curve", 0));
        clearBezButton->setText(QApplication::translate("MainWindow", "Clear Points", 0));
        setBezButton->setText(QApplication::translate("MainWindow", "Set Points", 0));
        drawBezierButton->setText(QApplication::translate("MainWindow", "Draw Curve", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
