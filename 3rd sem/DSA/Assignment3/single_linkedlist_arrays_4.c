#define MAX_LIST 500 
#include <stdio.h>
#include <stdlib.h>
#define NIL -1
typedef struct nodetag{
	int info;
	int cursor;
}node;


void init_l();
void insert_front(int);
void insert_after(int,int);
void insert_end(int);
void delete_front();
void delete_after(int);
void display();

node list[MAX_LIST];
int avail,head,end;

int main(){
	avail=head=end=0;
	int ch,choice,data,data1,pos,time=0;
	printf("1.Insert Front\n2.Insert in Between\n3.Insert End\n4.Delete in Between\n5.Delete Front\n6.Display\n");
	do{
		printf("Choice:");
		scanf("%d",&ch);
		switch(ch){

			case 1:		printf("Data:");
						scanf("%d",&data);
						if(time==0){
							init_l(data);
							++time;
						}
						else{
							insert_front(data);
							++time;
						}
						break;

			case 2:		printf("Data:");
						scanf("%d",&data);
						printf("After which data:");
						scanf("%d",&data1);
						insert_after(data,data1);
						break;

			case 3:		printf("Data:");
						scanf("%d",&data);
						insert_end(data);
						break;

			case 4:		
						printf("Data prev to the data being deleted:");
						scanf("%d",&data1);				
						delete_after(data1);
						break;

			case 5:		delete_front();
						break;

			case 6:		display();
						break;

			default:	break;
						
		}
		printf("Do you want to perform more operation(1 for yes/ 0 for no):");
		scanf("%d",&choice);
	}while(choice==1);
}

void init_l(int data){
	list[0].info=data;
	list[0].cursor=-1;
	avail++;
}

void insert_front(int data){
	
	list[avail].info=data;
	list[avail].cursor=head;
	head=avail;
	avail++;
}

void insert_after(int data,int prev){
	int i=head;
	while(list[i].info!=prev){
		i=list[i].cursor;
	}
	int temp=list[i].cursor;
	list[i].cursor=avail;
	list[avail].info=data;
	list[avail].cursor=temp;
	avail++;
}

void delete_front(){
	int temp=list[head].cursor;
	list[head].info=NIL;
	list[head].cursor=NIL;;
	head=temp;
}

void delete_after(int prev){
	int i=head;
	while(list[i].info!=prev){
		i=list[i].cursor;
	}
	int cur=list[i].cursor;
	int temp=list[cur].cursor;
	list[cur].info=NIL;
	list[cur].cursor=NIL;
	list[i].cursor=temp;	
}

void insert_end(int data){
	int cur=head;
	while(list[cur].cursor!=NIL){
		cur=list[cur].cursor;
	}
	list[cur].cursor=avail;
	list[avail].info=data;
	list[avail].cursor=NIL;
	avail++;
}

void display(){
	int cur=head;
	printf("%d <-\n",list[cur].info);
	while(list[cur].cursor!=NIL){
		cur=list[cur].cursor;
		printf("%d\n",list[cur].info);
	}
}
