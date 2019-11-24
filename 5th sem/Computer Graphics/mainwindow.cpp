
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include <QImage>
#include <iostream>
#include <QMouseEvent>
#include <QPainter>
#include <QPaintDevice>
#include <QPoint>
#include <cmath>
#include <vector>
#include <utility>
#include <bits/stdc++.h>
#include <string>
#include <sstream>

#define maxHt 1800
#define maxWd 1000
#define maxVer 10000

int gridsize=1;
std::vector<std::pair<int,int> > vertex_list;
QRgb old_color;

int clipper_points[4][2];

namespace patch
{
    template < typename T > std::string to_string( const T& n )
    {
        std::ostringstream stm ;
        stm << n ;
        return stm.str() ;
    }
}

//**********************************************
//**********************************************
//**********for scanline************************
typedef struct edgebucket
{
    int ymax;   //max y-coordinate of edge
    float xofymin;  //x-coordinate of lowest edge point updated only in aet
    float slopeinverse;
}EdgeBucket;

typedef struct edgetabletup
{
    // the array will give the scanline number
    // The edge table (ET) with edges entries sorted
    // in increasing y and x of the lower end

    int countEdgeBucket;    //no. of edgebuckets
    EdgeBucket buckets[maxVer];
}EdgeTableTuple;

EdgeTableTuple EdgeTable[maxHt], ActiveEdgeTuple;

//********************************************************
//********************************************************

QImage img=QImage(700,700,QImage::Format_RGB888);
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->x_axis->hide();
    ui->y_axis->hide();
    connect(ui->frame,SIGNAL(Mouse_Pos()),this,SLOT(Mouse_Pressed()));
    connect(ui->frame,SIGNAL(sendMousePosition(QPoint&)),this,SLOT(showMousePosition(QPoint&)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::point(int x,int y,int r,int g,int b)
{
    if(gridsize==1)
        img.setPixel(x,y,qRgb(r,g,b));
    else
    {
        int x1=(x/gridsize)*gridsize;
        int x2=x1+gridsize;
        int y1=(y/gridsize)*gridsize;
        int y2=y1+gridsize;
        for(int i=x1+1;i<x2;i++)
        {
            for(int j=y1+1;j<y2;j++)
            {
                img.setPixel(i,j,qRgb(r,g,b));
            }
        }
    }
    ui->frame->setPixmap(QPixmap::fromImage(img));
}


void MainWindow::showMousePosition(QPoint &pos)
{
//    ui->mouse_movement->setText(" X : "+QString::number(pos.x()-ui->frame->width()/2)+", Y : "+QString::number(ui->frame->height()/2-pos.y()));
    ui->mouse_movement->setText(" X : "+QString::number(pos.x())+", Y : "+QString::number(pos.y()));
}
void MainWindow::Mouse_Pressed()
{
    ui->mouse_pressed->setText(" X : "+QString::number(ui->frame->x-ui->frame->width()/2)+", Y : "+QString::number(ui->frame->height()/2-ui->frame->y));
//     ui->mouse_pressed->setText(" X : "+QString::number(ui->frame->x)+", Y : "+QString::number(ui->frame->y));
    old_color=img.pixel(ui->frame->x,ui->frame->y);
    point(ui->frame->x,ui->frame->y,255,255,0);
    ui->x_axis->move(0,ui->frame->y);
    ui->y_axis->move(ui->frame->x,0);
}

void MainWindow::on_show_axes_clicked()
{
    if(ui->show_axes->isChecked())
    {
        for(int i=0;i<=ui->frame->width();i++)
        {
            point(i,ui->frame->height()/2,255,0,127);
        }
        for(int i=0;i<=ui->frame->height();i++)
        {
            point(ui->frame->width()/2,i,127,0,255);
        }
        ui->frame->setPixmap(QPixmap::fromImage(img));
    }
    else{
        for(int i=0;i<=ui->frame->width();i++)
        {
            point(i,ui->frame->height()/2,0,0,0);
        }
        for(int i=0;i<=ui->frame->height();i++)
        {
            point(ui->frame->width()/2,i,0,0,0);
        }
        ui->frame->setPixmap(QPixmap::fromImage(img));
    }
}

//******************************************************
//******************************************************
//**************circle drawing algorithm****************


//****************midpoint circle***********************
void MainWindow::on_drawcircleButton_clicked()
{
    int radius=ui->circle_radius->value();
    QPainter painter(&img);
    QPen pen;
    pen.setWidth(1);
    pen.setColor(Qt::green);
    painter.setPen(Qt::green);
    int centerx=ui->frame->x,centery=ui->frame->y;
    centerx=(centerx/gridsize)*gridsize+gridsize/2;
    centery=(centery/gridsize)*gridsize+gridsize/2;
    int x1=radius*gridsize,y1=0;
    point(x1+centerx,y1+centery,0,255,0);
    if(radius>0)
    {
        point(-x1+centerx,-y1+centery,0,255,0);
        point(y1+centerx,x1+centery,0,255,0);
        point(-y1+centerx,-x1+centery,0,255,0);
    }

    int p=(1-radius)*gridsize;
    while(x1>y1)
    {
        y1+=gridsize;
        if(p<=0)
            p=p+2*y1+1;
        else
        {
            x1-=gridsize;
            p=p+2*y1-2*x1+1;
        }
        if(x1<y1) break;
        point(x1+centerx,y1+centery,0,255,0);
        point(-x1+centerx,y1+centery,0,255,0);
        point(x1+centerx,-y1+centery,0,255,0);
        point(-x1+centerx,-y1+centery,0,255,0);
        if(x1!=y1)
        {
            point(y1+centerx,x1+centery,0,255,0);
            point(-y1+centerx,x1+centery,0,255,0);
            point(y1+centerx,-x1+centery,0,255,0);
            point(-y1+centerx,-x1+centery,0,255,0);
        }
    }
    ui->frame->setPixmap(QPixmap::fromImage(img));
}

//******************************************************

//********bressenham circle*****************************

void MainWindow::drawCircle(int xc,int yc, int x1,int y1)
{
    QPainter painter(&img);
    QPen pen;
    pen.setWidth(1);
    pen.setColor(Qt::green);
    painter.setPen(Qt::green);

    point(xc+x1, yc+y1,154,255,0);
    point(xc-x1, yc+y1,154,255,0);
    point(xc+x1, yc-y1,154,255,0);
    point(xc-x1, yc-y1,154,255,0);
    point(xc+y1, yc+x1,154,255,0);
    point(xc-y1, yc+x1,154,255,0);
    point(xc+y1, yc-x1,154,255,0);
    point(xc-y1, yc-x1,154,255,0);
}

void MainWindow::on_bresenhamCircleButton_clicked()
{
    int radius=ui->circle_radius->value();
    QPainter painter(&img);
    QPen pen;
    pen.setWidth(1);
    pen.setColor(Qt::green);
    painter.setPen(Qt::green);
    int centerx=ui->frame->x,centery=ui->frame->y;
    centerx=(centerx/gridsize)*gridsize+gridsize/2;
    centery=(centery/gridsize)*gridsize+gridsize/2;

    int x1 = 0, y1 = radius*gridsize;
    int decision_parameter = (3 - 2 * radius)*gridsize;
    while (y1 >= x1)
    {
        drawCircle(centerx,centery, x1, y1);
        x1+=gridsize;

        if (decision_parameter > 0)
        {
            y1-=gridsize;
            decision_parameter = decision_parameter + 4 * (x1 - y1) + 10;
        }
        else
            decision_parameter = decision_parameter + 4 * x1 + 6;
        drawCircle(centerx,centery, x1, y1);
    }

    ui->frame->setPixmap(QPixmap::fromImage(img));
}

//***********************************************************
//***********************************************************



//**************************************************************
//**************************************************************
//***********line drawing algorithm*****************************

void MainWindow::on_set_point1_clicked()
{
    p1.setX(ui->frame->x);
    p1.setY(ui->frame->y);
}

void MainWindow::on_set_point2_clicked()
{
    p2.setX(ui->frame->x);
    p2.setY(ui->frame->y);
}

//**************DDA line drawing******************************

void MainWindow:: draw_DDA_line(int r,int g,int b)
{
    int sourcex=p1.x()/gridsize;
    int sourcey=p1.y()/gridsize;
    int destx=p2.x()/gridsize;
    int desty=p2.y()/gridsize;
    double dx=destx-sourcex;
    double dy=desty-sourcey;

    double steps=fabs(dx)>fabs(dy)?fabs(dx):fabs(dy);

    double nextx=dx/steps;
    double nexty=dy/steps;

    double x=sourcex*gridsize+gridsize/2;
    double y=sourcey*gridsize+gridsize/2;

    for(int i=0;i<=steps;i++)
    {
        point((int)x,(int)y,r,g,b);
        x+=nextx*gridsize;
        y+=nexty*gridsize;
    }
    ui->frame->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::on_DDAButton_clicked()
{
    QPainter painter(&img);
    QPen pen;
    pen.setWidth(1);
    pen.setColor(Qt::red);
    painter.setPen(Qt::yellow);
//        painter.drawLine(p1,p2);
    draw_DDA_line(255,255,0);

}
//******************************************************

//********bressenham line drawing**********************

void MainWindow::on_bresenhamButton_clicked()
{
    int sourcex=p1.x()/gridsize;
    int sourcey=p1.y()/gridsize;
    int destx=p2.x()/gridsize;
    int desty=p2.y()/gridsize;
    int dx=destx-sourcex;
    int dy=desty-sourcey;

    int x0=sourcex*gridsize+gridsize/2,y0=sourcey*gridsize+gridsize/2,x1=destx*gridsize+gridsize/2,y1=desty*gridsize+gridsize/2;
//    int dx=p2.x()-p1.x(),dy=p2.y()-p1.y();
    int stepx,stepy;
    if(dy<0){dy=-dy; stepy=-1;} else {stepy=1;}
    if(dx<0){dx=-dx; stepx=-1;} else {stepx=1;}

    dy<<=1;dx<<=1;

    point(x0,y0,255,111,0);

    if(dx>dy)
    {
        int fraction=dy-(dx>>1);
        while(x1!=x0)
        {
            x0+=stepx*gridsize;
            if(fraction>=0)
            {
                y0+=stepy*gridsize;
                fraction-=dx;
            }
            fraction+=dy;
            point(x0,y0,255,111,0);
        }
    }
    else
    {
        int fraction=dx-(dy>>1);
        while(y1!=y0)
        {
            y0+=stepy*gridsize;
            if(fraction>=0)
            {
                x0+=stepx*gridsize;
                fraction-=dy;
            }
            fraction+=dx;
            point(x0,y0,255,111,0);
        }
    }
}

//*********************************************************
//*********************************************************

void MainWindow::on_valueAspinBox_editingFinished()
{

}

void MainWindow::on_valueBspinBox_editingFinished()
{

}

void MainWindow::ellipsePoint(int centerx,int centery,int x1,int y1)
{
    point(centerx+x1*gridsize,centery+y1*gridsize,0,247,255);
    point(centerx+x1*gridsize,centery-y1*gridsize,0,247,255);
    point(centerx-x1*gridsize,centery+y1*gridsize,0,247,255);
    point(centerx-x1*gridsize,centery-y1*gridsize,0,247,255);
}

void MainWindow::on_drawEllipsepushButton_clicked()
{
    int x1, y1, p;

    int rx=ui->valueAspinBox->value();
    int ry=ui->valueBspinBox->value();

    int xc=ui->frame->x,yc=ui->frame->y;
    xc=(xc/gridsize)*gridsize+gridsize/2;
    yc=(yc/gridsize)*gridsize+gridsize/2;

    x1=0;
    y1=ry;
    p=(ry*ry)-(rx*rx*ry)+((rx*rx)/4);
    while((2*x1*ry*ry)<(2*y1*rx*rx))
    {
        ellipsePoint(xc,yc,x1,y1);

        if(p<0)
        {
            x1=x1+1;
            p=p+(2*ry*ry*x1)+(ry*ry);
        }
        else
        {
            x1=x1+1;
            y1=y1-1;
            p=p+(2*ry*ry*x1+ry*ry)-(2*rx*rx*y1);
        }
    }
    p=((float)x1+0.5)*((float)x1+0.5)*ry*ry+(y1-1)*(y1-1)*rx*rx-rx*rx*ry*ry;

    while(y1>=0)
    {
        ellipsePoint(xc,yc,x1,y1);

        if(p>0)
        {
            y1=y1-1;
            p=p-(2*rx*rx*y1)+(rx*rx);
        }
        else
        {
            y1=y1-1;
            x1=x1+1;
        p=p+(2*ry*ry*x1)-(2*rx*rx*y1)-(rx*rx);
        }
   }
 }


// Scanline Function
void MainWindow::initEdgeTable()
{
    int i;
    for (i=0; i<maxHt; i++)
    {
        EdgeTable[i].countEdgeBucket = 0;
    }

    ActiveEdgeTuple.countEdgeBucket = 0;
}

void insertionSort(EdgeTableTuple *ett)
{
    int i,j;
    EdgeBucket temp;

    for (i = 1; i < ett->countEdgeBucket; i++)
    {
        temp.ymax = ett->buckets[i].ymax;
        temp.xofymin = ett->buckets[i].xofymin;
        temp.slopeinverse = ett->buckets[i].slopeinverse;
        j = i - 1;

    while ((temp.xofymin < ett->buckets[j].xofymin) && (j >= 0))
    {
        ett->buckets[j + 1].ymax = ett->buckets[j].ymax;
        ett->buckets[j + 1].xofymin = ett->buckets[j].xofymin;
        ett->buckets[j + 1].slopeinverse = ett->buckets[j].slopeinverse;
        j = j - 1;
    }
    ett->buckets[j + 1].ymax = temp.ymax;
    ett->buckets[j + 1].xofymin = temp.xofymin;
    ett->buckets[j + 1].slopeinverse = temp.slopeinverse;
    }
}


void storeEdgeInTuple (EdgeTableTuple *receiver,int ym,int xm,float slopInv)
{
    (receiver->buckets[(receiver)->countEdgeBucket]).ymax = ym;
    (receiver->buckets[(receiver)->countEdgeBucket]).xofymin = (float)xm;
    (receiver->buckets[(receiver)->countEdgeBucket]).slopeinverse = slopInv;

    insertionSort(receiver);

    (receiver->countEdgeBucket)++;


}

void MainWindow::storeEdgeInTable (int x1,int y1, int x2, int y2)
{
    float m,minv;
    int ymaxTS,xwithyminTS, scanline;

    if (x2==x1)
    {
        minv=0.000000;
    }
    else
    {
    m = ((float)(y2-y1))/((float)(x2-x1));

    if (y2==y1)
        return;

    minv = (float)1.0/m;
    }

    if (y1>y2)
    {
        scanline=y2;
        ymaxTS=y1;
        xwithyminTS=x2;
    }
    else
    {
        scanline=y1;
        ymaxTS=y2;
        xwithyminTS=x1;
    }
    storeEdgeInTuple(&EdgeTable[scanline],ymaxTS,xwithyminTS,minv);


}

void removeEdgeByYmax(EdgeTableTuple *Tup,int yy)
{
    int i,j;
    for (i=0; i< Tup->countEdgeBucket; i++)
    {
        if (Tup->buckets[i].ymax == yy)
        {
            for ( j = i ; j < Tup->countEdgeBucket -1 ; j++ )
                {
                Tup->buckets[j].ymax =Tup->buckets[j+1].ymax;
                Tup->buckets[j].xofymin =Tup->buckets[j+1].xofymin;
                Tup->buckets[j].slopeinverse = Tup->buckets[j+1].slopeinverse;
                }
                Tup->countEdgeBucket--;
            i--;
        }
    }
}


void updatexbyslopeinv(EdgeTableTuple *Tup)
{
    int i;

    for (i=0; i<Tup->countEdgeBucket; i++)
    {
        (Tup->buckets[i]).xofymin =(Tup->buckets[i]).xofymin + (Tup->buckets[i]).slopeinverse;
    }
}


void MainWindow::on_scanlineButton_clicked()
{

        int i, j, x1, ymax1, x2, ymax2, FillFlag = 0, coordCount;

        for (i=0; i<maxHt; i++)
        {
            for (j=0; j<EdgeTable[i].countEdgeBucket; j++)
            {
                storeEdgeInTuple(&ActiveEdgeTuple,EdgeTable[i].buckets[j].
                         ymax,EdgeTable[i].buckets[j].xofymin,
                        EdgeTable[i].buckets[j].slopeinverse);
            }

            removeEdgeByYmax(&ActiveEdgeTuple, i);

            insertionSort(&ActiveEdgeTuple);

            j = 0;
            FillFlag = 0;
            coordCount = 0;
            x1 = 0;
            x2 = 0;
            ymax1 = 0;
            ymax2 = 0;
            while (j<ActiveEdgeTuple.countEdgeBucket)
            {
                if (coordCount%2==0)
                {
                    x1 = (int)(ActiveEdgeTuple.buckets[j].xofymin);
                    ymax1 = ActiveEdgeTuple.buckets[j].ymax;
                    if (x1==x2)
                    {
                        if (((x1==ymax1)&&(x2!=ymax2))||((x1!=ymax1)&&(x2==ymax2)))
                        {
                            x2 = x1;
                            ymax2 = ymax1;
                        }

                        else
                        {
                            coordCount++;
                        }
                    }

                    else
                    {
                            coordCount++;
                    }
                }
                else
                {
                    x2 = (int)ActiveEdgeTuple.buckets[j].xofymin;
                    ymax2 = ActiveEdgeTuple.buckets[j].ymax;

                    FillFlag = 0;
                    if (x1==x2)
                    {
                        if (((x1==ymax1)&&(x2!=ymax2))||((x1!=ymax1)&&(x2==ymax2)))
                        {
                            x1 = x2;
                            ymax1 = ymax2;
                        }
                        else
                        {
                            coordCount++;
                            FillFlag = 1;
                        }
                    }
                    else
                    {
                        coordCount++;
                        FillFlag = 1;
                    }

                if(FillFlag)
                {
                        p1.setX(x1);p1.setY(i);
                        p2.setX(x2);p2.setY(i);
                        on_DDAButton_clicked();
                }

            }

            j++;
        }
        updatexbyslopeinv(&ActiveEdgeTuple);
    }

        vertex_list.clear();
        initEdgeTable();
}

void MainWindow::on_clearVertexButton_clicked()
{
    vertex_list.clear();
    initEdgeTable();
}



void MainWindow::on_setVertexButton_clicked()
{
    vertex_list.push_back(std::make_pair((ui->frame->x/gridsize)*gridsize+gridsize/2,(ui->frame->y/gridsize)*gridsize+gridsize/2));
    int i=vertex_list.size();
    if(i>=2)
    {
        storeEdgeInTable(vertex_list[i-2].first, vertex_list[i-2].second, vertex_list[i-1].first, vertex_list[i-1].second);//storage of edges in edge table.
        p1.setX(vertex_list[i-1].first);p1.setY(vertex_list[i-1].second);
        p2.setX(vertex_list[i-2].first);p2.setY(vertex_list[i-2].second);
        on_DDAButton_clicked();
    }
}


void MainWindow::boundaryfill(int fx,int fy,QRgb edge_color,QRgb new_color,int r,int g,int b)
{
    if(img.pixel(fx,fy)!=edge_color&&img.pixel(fx,fy)!=new_color)
    {
        point(fx,fy,r,g,b);
        boundaryfill(fx+gridsize,fy,edge_color,new_color,r,g,b);
        boundaryfill(fx-gridsize,fy,edge_color,new_color,r,g,b);
        boundaryfill(fx,fy+gridsize,edge_color,new_color,r,g,b);
        boundaryfill(fx,fy-gridsize,edge_color,new_color,r,g,b);
        ui->frame->setPixmap(QPixmap::fromImage(img));
    }
}
/*
 * void MainWindow::boundary_fill(int x,int y,QColor fillc,QColor boundc)
{
    if(abs(x)>=225/grid_size || abs(y)>=225/grid_size) {cout<<"wall"<<endl;return;}
    cout<<to_point_x(x)<<" "<<to_point_y(y)<<" "<<endl;
    QColor c=img.pixel(to_point_x(x)+grid_size/2,to_point_y(y)+grid_size/2);
    cout<<c.red()<<" "<<c.green()<<" "<<c.blue()<<endl;
    if( c==fillc || c==boundc) {cout<<"returned"<<endl;return;}

        point(to_point_x(x),to_point_y(y),grid_size,fillc);
        cout<<x<<" "<<y<<endl;
        boundary_fill(x+1,y,fillc,boundc);
        boundary_fill(x-1,y,fillc,boundc);
        boundary_fill(x,y+1,fillc,boundc);
        boundary_fill(x,y-1,fillc,boundc);
}
*/

void MainWindow::on_boundaryfillButton_clicked()
{
    int fx=ui->frame->x,fy=ui->frame->y;
    point(fx,fy,0,0,0);
    QRgb edge_color=qRgba(0,255,0,0xFF);
    QRgb new_color=qRgba(250,250,250,0xFF);
    fx=(fx/gridsize)*gridsize+gridsize/2;
    fy=(fy/gridsize)*gridsize+gridsize/2;
    boundaryfill(fx,fy,edge_color,new_color,251,120,50);
}


void MainWindow::floodfill(int fx,int fy,QRgb old_color,int r,int g,int b)
{
    if(img.pixel(fx,fy)==old_color)
    {
        point(fx,fy,r,g,b);
        floodfill(fx+gridsize,fy,old_color,r,g,b);
        floodfill(fx-gridsize,fy,old_color,r,g,b);
        floodfill(fx,fy+gridsize,old_color,r,g,b);
        floodfill(fx,fy-gridsize,old_color,r,g,b);
    }
}

void MainWindow::on_floodfillButton_clicked()
{
    int fx=ui->frame->x,fy=ui->frame->y;
    point(fx,fy,qRed(old_color),qGreen(old_color),qBlue(old_color));
    ui->frame->setPixmap(QPixmap::fromImage(img));
    fx=(fx/gridsize)*gridsize+gridsize/2;
    fy=(fy/gridsize)*gridsize+gridsize/2;
    floodfill(fx,fy,old_color,0,100,250);
}

int* MainWindow::matMul3x3(double mat[3][3],int coord[3])
{
    int i,k,res[3];
    for (i = 0; i < 3; i++)
    {
            res[i]= 0;
            for (k = 0; k < 3; k++)
            {

                res[i] += mat[i][k]*coord[k];
                std::string s=patch::to_string(mat[i][k])+"||"+patch::to_string(coord[k])+"="+patch::to_string(res[i]);
                qDebug("%s",s.c_str());
            }

    }
    std::string s=patch::to_string(res[0])+"$$"+patch::to_string(res[1])+"$$"+patch::to_string(res[2]);
    qDebug("%s",s.c_str());
    return res;
}

void MainWindow::drawPoly(std::vector<std::pair<int,int> > vlist,int r,int g,int b)
{
    for(int i=0;i<vlist.size()-1;i++)
    {
        p1.setX(vlist[i].first);p1.setY(vlist[i].second);
        p2.setX(vlist[i+1].first);p2.setY(vlist[i+1].second);
        draw_DDA_line(r,g,b);
    }
}

void MainWindow::on_translateButton_clicked()
{
    std::vector<std::pair<int,int> > old_vertex;
    for(int i=0;i<vertex_list.size();i++)
    {
        old_vertex.push_back(vertex_list[i]);
    }

    int k=gridsize;
    int tx=ui->trans_x->value();
    int ty=ui->trans_y->value();
    tx*=k;
    ty*=k;
    ty=-ty;
    int i,len=vertex_list.size();

    // matrix for translation
    double mat[3][3]={{1,0,tx},{0,1,ty},{0,0,1}};

    for(i=0;i<len;i++)
    {
        int* coord=(int*)malloc(3*sizeof(int));
        coord[0]=vertex_list[i].first;
        coord[1]=vertex_list[i].second;
        coord[2]=1;
        coord=matMul3x3(mat,coord);
        vertex_list[i].first=coord[0]/coord[2];
        vertex_list[i].second=coord[1]/coord[2];
    }

    drawPoly(old_vertex,0,0,0);
    drawPoly(vertex_list,255,255,0);

}

void MainWindow::on_scaleButton_clicked()
{
    std::vector<std::pair<int,int> > old_vertex;
    for(int i=0;i<vertex_list.size();i++)
    {
        old_vertex.push_back(vertex_list[i]);
    }

    int sx=ui->scale_x->value();
    int sy=ui->scale_y->value();
    //Point about which to be scaled
    int piv_x=(ui->frame->x/gridsize)*gridsize+gridsize/2;
    int piv_y=(ui->frame->y/gridsize)*gridsize+gridsize/2;

    int i,len=vertex_list.size();

    // matrix for scaling
    double mat[3][3]={{sx,0,0},{0,sy,0},{0,0,1}};

    for(i=0;i<len;i++)
    {
        int* coord=(int*)malloc(3*sizeof(int));
        coord[0]=vertex_list[i].first-piv_x;
        coord[1]=piv_y-vertex_list[i].second;
        coord[2]=1;
        coord=matMul3x3(mat,coord);
        vertex_list[i].first=coord[0]/coord[2]+piv_x;
        vertex_list[i].second=piv_y-coord[1]/coord[2];

    }

    drawPoly(old_vertex,0,0,0);
    drawPoly(vertex_list,255,255,0);


}

void MainWindow::on_rotateButton_clicked()
{
    std::vector<std::pair<int,int> > old_vertex;
    for(int i=0;i<vertex_list.size();i++)
    {
        old_vertex.push_back(vertex_list[i]);
    }

    int angle=ui->rotate_angle->value();
    double dang=(double)angle*M_PI/180.0;
    double sinang=sin(dang);
    double cosang=cos(dang);

    //Point about which to be rotated
    int piv_x=(ui->frame->x/gridsize)*gridsize+gridsize/2;
    int piv_y=(ui->frame->y/gridsize)*gridsize+gridsize/2;

    int i,len=vertex_list.size();

    // matrix for rotation
    double mat[3][3]={{cosang,-sinang,0},{sinang,cosang,0},{0,0,1}};

    for(i=0;i<len;i++)
    {
        int* coord=(int*)malloc(3*sizeof(int));
        coord[0]=vertex_list[i].first-piv_x;
        coord[1]=piv_y-vertex_list[i].second;
        coord[2]=1;
        coord=matMul3x3(mat,coord);

        vertex_list[i].first=coord[0]/coord[2]+piv_x;
        vertex_list[i].second=piv_y-coord[1]/coord[2];
    }

    drawPoly(old_vertex,0,0,0);
    drawPoly(vertex_list,255,255,0);

}

void MainWindow::on_shearButton_clicked()
{
    std::vector<std::pair<int,int> > old_vertex;
    for(int i=0;i<vertex_list.size();i++)
    {
        old_vertex.push_back(vertex_list[i]);
    }

    int shx=ui->shear_x->value();
    int shy=ui->shear_y->value();
    //Point about which to be scaled
    int piv_x=(ui->frame->x/gridsize)*gridsize+gridsize/2;
    int piv_y=(ui->frame->y/gridsize)*gridsize+gridsize/2;

    int i,len=vertex_list.size();

    // matrix for shearing
    double mat[3][3]={{1,shx,0},{shy,1,0},{0,0,1}};

    for(i=0;i<len;i++)
    {
        int* coord=(int*)malloc(3*sizeof(int));
        coord[0]=vertex_list[i].first-piv_x;
        coord[1]=piv_y-vertex_list[i].second;
        coord[2]=1;
        coord=matMul3x3(mat,coord);
        vertex_list[i].first=coord[0]/coord[2]+piv_x;
        vertex_list[i].second=piv_y-coord[1]/coord[2];
    }
    drawPoly(old_vertex,0,0,0);
    drawPoly(vertex_list,255,255,0);

}

void MainWindow::on_reflectionButton_clicked()
{
    int i,len=vertex_list.size();

    double dx=p1.x()-p2.x();
    double dy=p1.y()-p2.y();

    double a=-dy;
    double b=dx;
    double c=p1.x()*dy-p1.y()*dx;

    std::string s1=patch::to_string(p1.x())+","+patch::to_string(p1.y())+" "+patch::to_string(p2.x())+","+patch::to_string(p2.y());
    qDebug("%s",s1.c_str());
    std::string s2=patch::to_string(a)+"*"+patch::to_string(b)+"*"+patch::to_string(c);
    qDebug("%s",s2.c_str());

    for(i=0;i<len;i++)
    {

        int x1=vertex_list[i].first;
        int y1=vertex_list[i].second;

        std::string s3=patch::to_string(x1)+","+patch::to_string(y1);
        qDebug("%s",s3.c_str());

        vertex_list[i].first=(int)((double)x1-(double)(2*a*(a*x1+b*y1+c))/(double)((a*a+b*b)));
        vertex_list[i].second=(int)((double)y1-(double)(2*b*(a*x1+b*y1+c))/(double)((a*a+b*b)));

//        x1=(x1/gridsize)*gridsize+gridsize/2;
//        y1=(y1/gridsize)*gridsize+gridsize/2;

        std::string s4=patch::to_string(vertex_list[i].first)+";"+patch::to_string(vertex_list[i].second);
        qDebug("%s",s4.c_str());

//        vertex_list[i].first=x1;
//        vertex_list[i].second=y1;
    }
    drawPoly(vertex_list,255,255,255);
}

//void MainWindow::on_reflectionButton_clicked()
//{
//    std::vector<std::pair<int,int> > old_vertex;
//    for(int i=0;i<vertex_list.size();i++)
//    {
//        old_vertex.push_back(vertex_list[i]);
//    }
//    std::string s1=patch::to_string(p1.x())+","+patch::to_string(p1.y())+" "+patch::to_string(p2.x())+","+patch::to_string(p2.y());
//    qDebug("%s",s1.c_str());

//    double dx=(p1.x()/gridsize)*gridsize+gridsize/2-(p2.x()/gridsize)*gridsize+gridsize/2;
//    double dy=(p1.y()/gridsize)*gridsize+gridsize/2-(p2.y()/gridsize)*gridsize+gridsize/2;

//    int i,len=vertex_list.size();

//    if(dx==0)
//    {
//        double c=(p1.x()/gridsize)*gridsize+gridsize/2;
//        double mat1[3][3]={{1,0,-c},{0,1,0},{0,0,1}};
//        double mat2[3][3]={{-1,0,0},{0,1,0},{0,0,1}};
//        double mat3[3][3]={{1,0,c},{0,1,0},{0,0,1}};

//        for(i=0;i<len;i++)
//        {
//            int* coord=(int*)malloc(3*sizeof(int));
//            coord[0]=vertex_list[i].first;
//            coord[1]=-vertex_list[i].second;
//            coord[2]=1;

//            coord=matMul3x3(mat1,coord);
//            coord=matMul3x3(mat2,coord);
//            coord=matMul3x3(mat3,coord);

//            vertex_list[i].first=coord[0]/coord[2];
//            vertex_list[i].second=-coord[1]/coord[2];
//        }
//    }
//    else if(dy==0)
//    {
//        double c=(p1.y()/gridsize)*gridsize+gridsize/2;
//        double mat1[3][3]={{1,0,0},{0,1,-c},{0,0,1}};
//        double mat2[3][3]={{-1,0,0},{0,1,0},{0,0,1}};
//        double mat3[3][3]={{1,0,0},{0,1,c},{0,0,1}};

//        for(i=0;i<len;i++)
//        {
//            int* coord=(int*)malloc(3*sizeof(int));
//            coord[0]=vertex_list[i].first;
//            coord[1]=-vertex_list[i].second;
//            coord[2]=1;

//            coord=matMul3x3(mat1,coord);
//            coord=matMul3x3(mat2,coord);
//            coord=matMul3x3(mat3,coord);

//            vertex_list[i].first=coord[0]/coord[2];
//            vertex_list[i].second=-coord[1]/coord[2];
//        }
//    }

//    else
//    {
//        double m=dy/dx;
//        double c=-(double)p1.x()-(double)p1.y()/m;
//        c=double(int(c));
//        c=(c/gridsize)*gridsize+gridsize/2;

//        std::string s=patch::to_string(vertex_list[0].first)+" "+patch::to_string(vertex_list[0].second);
//        qDebug("%s",s.c_str());

//        double cosx1=1.0/(double)sqrt(1+m*m);
//        double sinx1=1.0/(double)sqrt(1+1.0/double(m*m));

//        std::string sm=patch::to_string(cosx1)+" "+patch::to_string(sinx1);
//        qDebug("%s",sm.c_str());

//        double mat1[3][3]={{1,0,-c},{0,1,0},{0,0,1}};
//        double mat2[3][3]={{cosx1,-sinx1,0},{sinx1,cosx1,0},{0,0,1}};
//        double mat3[3][3]={{-1,0,0},{0,1,0},{0,0,1}};
//        double mat4[3][3]={{cosx1,sinx1,0},{-sinx1,cosx1,0},{0,0,1}};
//        double mat5[3][3]={{1,0,c},{0,1,0},{0,0,1}};

//        qDebug("al");

//        for(i=0;i<len;i++)
//        {
//            int* coord=(int*)malloc(3*sizeof(int));
//            coord[0]=vertex_list[i].first;
//            coord[1]=vertex_list[i].second;
//            coord[2]=1;

//            coord=matMul3x3(mat1,coord);
//            std::string a1=patch::to_string(coord[0])+" "+patch::to_string(coord[1])+" "+patch::to_string(coord[2]);
//            qDebug("%s",a1.c_str());
//            coord=matMul3x3(mat2,coord);
//            std::string a2=patch::to_string(coord[0])+" "+patch::to_string(coord[1])+" "+patch::to_string(coord[2]);
//            qDebug("%s",a2.c_str());
//            coord=matMul3x3(mat3,coord);
//            std::string a3=patch::to_string(coord[0])+" "+patch::to_string(coord[1])+" "+patch::to_string(coord[2]);
//            qDebug("%s",a3.c_str());
//            coord=matMul3x3(mat4,coord);
//            std::string a4=patch::to_string(coord[0])+" "+patch::to_string(coord[1])+" "+patch::to_string(coord[2]);
//            qDebug("%s",a4.c_str());
//            coord=matMul3x3(mat5,coord);
//            std::string a5=patch::to_string(coord[0])+" "+patch::to_string(coord[1])+" "+patch::to_string(coord[2]);
//            qDebug("%s",a5.c_str());
//            qDebug("");

//            vertex_list[i].first=coord[0]/coord[2];
//            vertex_list[i].second=coord[1]/coord[2];
//        }
//    }

//    std::string s=patch::to_string(vertex_list[0].first)+" "+patch::to_string(vertex_list[0].second);
//    qDebug("%s",s.c_str());

////    drawPoly(old_vertex,0,0,0);
//    drawPoly(vertex_list,255,255,0);
//}

// =================== LINE CLIPPING =====================================================
// Defining region codes
const int INSIDE = 0; // 0000
const int LEFT = 1;   // 0001
const int RIGHT = 2;  // 0010
const int BOTTOM = 4; // 0100
const int TOP = 8;    // 1000


// Function to compute region code for a point(x, y)
int MainWindow::computeCode(int xa, int ya)
{
    int x_min=cp1.x(),x_max=cp2.x(),y_min=cp1.y(),y_max=cp2.y();

    // initialized as being inside
        int code = INSIDE;
        if (xa < x_min)       // to the left of rectangle
            code |= LEFT;
        else if (xa > x_max)  // to the right of rectangle
            code |= RIGHT;
        if (ya < y_min)       // below the rectangle
            code |= BOTTOM;
        else if (ya > y_max)  // above the rectangle
            code |= TOP;

        return code;
}
// Implementing Cohen-Sutherland algorithm
// Clipping a line from P1 = (x2, y2) to P2 = (x2, y2)
void MainWindow::cohenSutherlandClip(int x1, int y1,int x2, int y2)
{
    int x_min=clipper_points[0][0],x_max=clipper_points[2][0],y_min=clipper_points[0][1],y_max=clipper_points[2][1];
    // Compute region codes for P1, P2
    int code1 = computeCode(x1, y1);
    int code2 = computeCode(x2, y2);

    // Initialize line as outside the rectangular window
    bool accept = false;

    while (true)
    {

        if ((code1 == 0) && (code2 == 0))
        {
            // If both endpoints lie within rectangle
            accept = true;
            break;
        }
        else if (code1 & code2)
        {
            // If both endpoints are outside rectangle,
            // in same region
            break;
        }
        else
        {
            // Some segment of line lies within the
            // rectangle
            int code_out;
            int x, y;

            // At least one endpoint is outside the
            // rectangle, pick it.
            if (code1 != 0)
                code_out = code1;
            else
                code_out = code2;

            // Find intersection point;
            // using formulas y = y1 + slope * (x - x1),
            // x = x1 + (1 / slope) * (y - y1)
            if (code_out & TOP)
            {
                // point is above the clip rectangle
                x = x1 + (int)((double)(x2 - x1) *(double)(y_max - y1) /(double)(y2 - y1));
                y = y_max;
            }
            else if (code_out & BOTTOM)
            {
                // point is below the rectangle
                x = x1 + (int)((double)(x2 - x1) * (double)(y_min - y1) / (double)(y2 - y1));
                y = y_min;
            }
            else if (code_out & RIGHT)
            {
                // point is to the right of rectangle
                y = y1 + (int)((double)(y2 - y1) * (double)(x_max - x1) / (double)(x2 - x1));
                x = x_max;
            }
            else if (code_out & LEFT)
            {
                // point is to the left of rectangle
                y = y1 + (int)((double)(y2 - y1) * (double)(x_min - x1) / (double)(x2 - x1));
                x = x_min;
            }

            // Now intersection point x,y is found
            // We replace point outside rectangle
            // by intersection point
            if (code_out == code1)
            {
                x1 = x;
                y1 = y;
                code1 = computeCode(x1, y1);
            }
            else
            {
                x2 = x;
                y2 = y;
                code2 = computeCode(x2, y2);
            }
        }
    }
    if (accept)
    {
        //If accepted
        //Just reset and draw the boundary and the line
        //Reset the screen and draw the grid

        p1.setX(x1);
        p1.setY(y1);

        p2.setX(x2);
        p2.setY(y2);

        draw_DDA_line(255,255,255);
        draw_Window();
    }
    else
    {
        //If not accepted
        //Just reset and draw the boundary
        //Reset the screen and draw the grid
        draw_Window();
    }

}

void MainWindow::on_lineClippingButton_clicked()
{
    draw_DDA_line(0,0,0);
    cohenSutherlandClip(p1.x(),p1.y(),p2.x(),p2.y());
}

//**************************************************************************
//**************************************************************************
//**************polygon clipping********************************************

const int MAX_POINTS = 20;

// Returns x-value of point of intersectipn of two
// lines
int MainWindow:: x_intersect(int x1, int y1, int x2, int y2,int x3, int y3, int x4, int y4)
{
    y1=ui->frame->height()-y1+1;
    y2=ui->frame->height()-y2+1;
    y3=ui->frame->height()-y3+1;
    y4=ui->frame->height()-y4+1;
    int num = (x1*y2 - y1*x2) * (x3-x4) -
              (x1-x2) * (x3*y4 - y3*x4);
    int den = (x1-x2) * (y3-y4) - (y1-y2) * (x3-x4);
    int retx=num/den;
    return retx;
}

// Returns y-value of point of intersectipn of
// two lines
int MainWindow:: y_intersect(int x1, int y1, int x2, int y2,int x3, int y3, int x4, int y4)
{
    y1=ui->frame->height()-y1+1;
    y2=ui->frame->height()-y2+1;
    y3=ui->frame->height()-y3+1;
    y4=ui->frame->height()-y4+1;
    int num = (x1*y2 - y1*x2) * (y3-y4) -
              (y1-y2) * (x3*y4 - y3*x4);
    int den = (x1-x2) * (y3-y4) - (y1-y2) * (x3-x4);
    int rety= (ui->frame->height()-num/den+1);
    return rety;
}

// This functions clips all the edges w.r.t one clip
// edge of clipping area
void MainWindow:: clip(int x1, int y1, int x2, int y2)
{
    int poly_size=vertex_list.size()-1;
    int new_poly_size = 0;

    std::vector<std::pair<int,int> > new_points;

    // (ix,iy),(kx,ky) are the co-ordinate values of
    // the points
    for (int i = 0; i < poly_size; i++)
    {
        // i and k form a line in polygon
        int k = (i+1) % poly_size;
        int ix = vertex_list[i].first, iy = vertex_list[i].second;
        int kx = vertex_list[k].first, ky = vertex_list[k].second;

        // Calculating position of first and second point

        int i_pos,k_pos;
        if(x2==x1 && ix>x1) i_pos=1;
        else if(x2==x1 && ix<x1) i_pos=-1;
        else if(y2==y1 && iy<y1) i_pos=1;
        else i_pos=-1;

        if(x2==x1 && kx>x1) k_pos=1;
        else if(x2==x1 && kx<x1) k_pos=-1;
        else if(y2==y1 && ky<y1) k_pos=1;
        else k_pos=-1;

        if(y1>y2||x1>x2)
        {
            i_pos=(-1)*i_pos;
            k_pos=(-1)*k_pos;
        }

        // Case 1 : When both points are inside
        if (i_pos >= 0  && k_pos >= 0)
        {
            //Only second point is added
            new_points.push_back(std::make_pair(kx,ky));
            new_poly_size++;
        }

        // Case 2: When only first point is outside
        else if (i_pos < 0  && k_pos >= 0)
        {
            // Point of intersection with edge
            // and the second point is added

            new_points.push_back(std::make_pair(x_intersect(x1,y1, x2, y2, ix, iy, kx, ky),y_intersect(x1,y1, x2, y2, ix, iy, kx, ky)));
            new_poly_size++;

            new_points.push_back(std::make_pair(kx,ky));
            new_poly_size++;
        }

        // Case 3: When only second point is outside
        else if (i_pos >= 0  && k_pos < 0)
        {
            //Only point of intersection with edge is added

            new_points.push_back(std::make_pair(x_intersect(x1,y1, x2, y2, ix, iy, kx, ky),y_intersect(x1,y1, x2, y2, ix, iy, kx, ky)));
            new_poly_size++;
        }

        // Case 4: When both points are outside
        else
        {
            //No points are added
        }
    }

    // Copying new points into original array
    // and changing the no. of vertices
    poly_size = new_poly_size;
    vertex_list.clear();
    for (int i = 0; i < new_points.size(); i++)
    {
        vertex_list.push_back(new_points[i]);
    }
    vertex_list.push_back(new_points[0]);
}

// Implements Sutherland–Hodgman algorithm
void MainWindow:: suthHodgClip()
{
    std::vector<std::pair<int,int> > old_vertex;
    for(int i=0;i<vertex_list.size();i++)
    {
        old_vertex.push_back(vertex_list[i]);
    }
    int clipper_size=4;
    //i and k are two consecutive indexes
    for (int i=0; i<clipper_size; i++)
    {
        int k = (i+1) % clipper_size;

        // We pass the current array of vertices, it's size
        // and the end points of the selected clipper line
        clip(clipper_points[i][0],
             clipper_points[i][1], clipper_points[k][0],
             clipper_points[k][1]);
    }

    drawPoly(old_vertex,0,0,0);
    drawPoly(vertex_list,255,255,255);
    draw_Window();
}



void MainWindow:: draw_Window()
{
    p1.setX(clipper_points[0][0]);
    p1.setY(clipper_points[0][1]);
    p2.setX(clipper_points[1][0]);
    p2.setY(clipper_points[1][1]);
    draw_DDA_line(0,255,255);

    p1.setX(clipper_points[1][0]);
    p1.setY(clipper_points[1][1]);
    p2.setX(clipper_points[2][0]);
    p2.setY(clipper_points[2][1]);
    draw_DDA_line(0,255,255);

    p1.setX(clipper_points[2][0]);
    p1.setY(clipper_points[2][1]);
    p2.setX(clipper_points[3][0]);
    p2.setY(clipper_points[3][1]);
    draw_DDA_line(0,255,255);

    p1.setX(clipper_points[3][0]);
    p1.setY(clipper_points[3][1]);
    p2.setX(clipper_points[0][0]);
    p2.setY(clipper_points[0][1]);
    draw_DDA_line(0,255,255);
}

void MainWindow::on_setCP1Button_clicked()
{
    cp1.setX((ui->frame->x/gridsize)*gridsize+gridsize/2);
    cp1.setY((ui->frame->y/gridsize)*gridsize+gridsize/2);
}
void MainWindow::on_setCP2Button_clicked()
{
    cp2.setX((ui->frame->x/gridsize)*gridsize+gridsize/2);
    cp2.setY((ui->frame->y/gridsize)*gridsize+gridsize/2);

    clipper_points[0][0]=cp1.x();
    clipper_points[0][1]=cp1.y();
    clipper_points[1][0]=cp1.x();
    clipper_points[1][1]=cp2.y();
    clipper_points[2][0]=cp2.x();
    clipper_points[2][1]=cp2.y();
    clipper_points[3][0]=cp2.x();
    clipper_points[3][1]=cp1.y();

    draw_Window();
}

void MainWindow::on_polygonClippingButton_clicked()
{
    //Calling the clipping function
    suthHodgClip();
}



//**********************************************************************
//**********************************************************************

//*********************************************************************
//*********************************************************************
//******************bezier curve***************************************
std::vector<std::pair<int,int> > BezList;

void MainWindow::on_clearBezButton_clicked()
{
     BezList.clear();
}

void MainWindow::on_setBezButton_clicked()
{
    int k=gridsize;
        int x=((ui->frame->x)/k)*k+k/2;
        int y=((ui->frame->y)/k)*k+k/2;
        BezList.push_back(std::make_pair(x,y));

        int i=BezList.size();

        if(BezList.size()>1)
        {
            storeEdgeInTable(BezList[i-2].first, BezList[i-2].second, BezList[i-1].first, BezList[i-1].second);//storage of edges in edge table.

            p1.setX(BezList[BezList.size()-1].first);
            p2.setX(BezList[BezList.size()-2].first);

            p1.setY(BezList[BezList.size()-1].second);
            p2.setY(BezList[BezList.size()-2].second);

            draw_DDA_line(0,255,0);

        }
}

void MainWindow::bezierCurve()
{
    double xu = 0.0 , yu = 0.0 , u = 0.0 ;
    int i = 0 ;
    for(u = 0.0 ; u <= 1.0 ; u += 0.0001)
    {
        xu = pow(1-u,3)*BezList[0].first+3*u*pow(1-u,2)*BezList[1].first+3*pow(u,2)*(1-u)*BezList[2].first+pow(u,3)*BezList[3].first;
        yu = pow(1-u,3)*BezList[0].second+3*u*pow(1-u,2)*BezList[1].second+3*pow(u,2)*(1-u)*BezList[2].second+pow(u,3)*BezList[3].second;
        point((int)xu , (int)yu,255,0,0) ;
    }
}

void MainWindow::on_drawBezierButton_clicked()
{
    bezierCurve();
}
//********************************************************************
///*******************************************************************
void MainWindow::on_resetButton_clicked()
{
    for(int j=0;j<img.height();j++)
    {
        for(int i=0;i<img.width();i++)
        {
            img.setPixel(i,j,qRgb(0,0,0));
        }
    }
    ui->frame->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::on_gridspinbox_editingFinished()
{

}

void MainWindow::on_setgridbutton_clicked()
{
    on_resetButton_clicked();
    int k=ui->gridspinbox->value();
    gridsize=k;
    if(k>1)
    {
        for(int i=0;i<=ui->frame->width();i+=k)
        {
            for(int j=0;j<=ui->frame->height();j++)
            {
                img.setPixel(i,j,qRgb(255,0,0));
            }
        }
        for(int i=0;i<=ui->frame->height();i+=k)
        {
            for(int j=0;j<=ui->frame->width();j++)
            {
                img. setPixel(j,i,qRgb(255,0,0));
            }
        }
        ui->frame->setPixmap(QPixmap::fromImage(img));
    }
}












