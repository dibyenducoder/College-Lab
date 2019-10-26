#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<math.h>
typedef struct co{float x,y;}Coo;
typedef Coo* Coord;
int main()
{
    Coord bird=(Coord)malloc(sizeof(Coo));
    Coord pig=(Coord)malloc(sizeof(Coo));
    pig->y=0;
    pig->x=rand()%100;
    bird->x=0;
    bird->y=rand()&100;
    float vel,ang;
    printf("Height of cliff : %d\nDistance of Pig : %d\nEnter velocity and angle : ",bird->y,pig->x);
    scanf("%f %f",&vel,&ang);
    if(pig->x==vel*vel*sin(ang*22/(180*7))/(float)10)
        printf("Point scored");
    else
        printf("Point not scored");
}
