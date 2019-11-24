#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtGui>
#include <QtCore>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public slots:
    void Mouse_Pressed();
    void showMousePosition(QPoint& pos);
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_show_axes_clicked();

    void on_set_point1_clicked();

    void on_set_point2_clicked();

    void on_setgridbutton_clicked();

    void on_gridspinbox_editingFinished();

    void on_resetButton_clicked();

    void on_drawcircleButton_clicked();

    void draw_DDA_line(int r,int g,int b);
    void on_DDAButton_clicked();

    void on_bresenhamButton_clicked();

    void on_bresenhamCircleButton_clicked();

    void drawCircle(int xc,int yc, int x1,int y1);

    void on_valueAspinBox_editingFinished();

    void on_valueBspinBox_editingFinished();

    void on_drawEllipsepushButton_clicked();

    void ellipsePoint(int centerx, int centery, int x1, int y1);

    void on_scanlineButton_clicked();

    void on_boundaryfillButton_clicked();

    void boundaryfill(int fx,int fy,QRgb edge_color,QRgb new_color,int r,int g,int b);

    void on_floodfillButton_clicked();

    void floodfill(int fx,int fy,QRgb old_color,int r,int g,int b);

    void on_setVertexButton_clicked();

    void initEdgeTable();
    void storeEdgeInTable (int x1,int y1, int x2, int y2);

    int* matMul3x3(double mat[3][3],int coord[3]);
    void drawPoly(std::vector<std::pair<int,int> > vlist,int r,int g,int b);
    void on_translateButton_clicked();


    void on_clearVertexButton_clicked();

    void on_setCP1Button_clicked();

    void on_setCP2Button_clicked();

    void on_polygonClippingButton_clicked();
    void draw_Window();
    int x_intersect(int x1, int y1, int x2, int y2,int x3, int y3, int x4, int y4);
    int y_intersect(int x1, int y1, int x2, int y2,int x3, int y3, int x4, int y4);
    void clip(int x1, int y1, int x2, int y2);
    void suthHodgClip();

    void on_scaleButton_clicked();

    void on_rotateButton_clicked();

    void on_shearButton_clicked();

    int computeCode(int x, int y);
    void cohenSutherlandClip(int x1, int y1,int x2, int y2);
    void on_lineClippingButton_clicked();

    void on_clearBezButton_clicked();

    void on_setBezButton_clicked();

    void on_drawBezierButton_clicked();

    void bezierCurve();

    void on_reflectionButton_clicked();

private:
    Ui::MainWindow *ui;
    QPoint p1,p2;
    QPoint cp1,cp2;
    void point(int,int,int,int,int);
};

#endif // MAINWINDOW_H
