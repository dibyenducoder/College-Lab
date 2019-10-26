#include <stdio.h>
#include <stdlib.h>
#include "double_circular_linkedlist.h"

int main(){
	node *last,**plast;
	last=NULL;
	plast=&(last);
	int ch,choice,data,data1,pos;
	printf("1.Insert Front\n2.Insert in Between\n3.Insert End\n4.Delete in Between\n5.Display\n");
	do{
		printf("Choice:");
		scanf("%d",&ch);
		switch(ch){

			case 1:		printf("Data:");
						scanf("%d",&data);
						last=insert_front(plast,data);
						break;

			case 2:		printf("Data:");
						scanf("%d",&data);
						printf("After which data:");
						scanf("%d",&data1);
						node *cur=last;
						while(cur->data!=data1){
							cur=cur->next;
							
						}
						insert_after(cur,data);
						break;

			case 3:		printf("Data:");
						scanf("%d",&data);
						insert_end(plast,data);
						break;

			case 4:		
						printf("Data to delete:");
						scanf("%d",&data1);
						cur=last;
						while((cur->next)->data!=data1){
							cur=cur->next;
							
							
						}
						
						delete_after(cur);
						break;

			case 5:		display(*plast);

			default:	break;
						
		}
		printf("Do you want to perform more operation(1 for yes/ 0 for no):");
		scanf("%d",&choice);
	}while(choice==1);
}
