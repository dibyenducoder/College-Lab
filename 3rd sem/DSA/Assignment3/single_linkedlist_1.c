#include <stdio.h>
#include <stdlib.h>
#include "single_linear_linkedlist.h"

int main(){
	node *head,**phead,*cur1,*cur2;
	phead=&(head);
	int ch,choice,data,data1,pos;
	printf("1.Insert Front\n2.Insert in Between\n3.Insert End\n4.Delete in Between\n5.Delete Front\n6.Display\n");
	do{
		printf("Choice:");
		scanf("%d",&ch);
		switch(ch){

			case 1:		printf("Data:");
						scanf("%d",&data);
						cur1=create(data);
						insert_front(cur1,phead);
						break;

			case 2:		printf("Data:");
						scanf("%d",&data);
						cur1=head;

						printf("After which data:");
						scanf("%d",&data1);
						cur2=create(data);
						while(cur1->info!=data1){
							cur1=cur1->next;
						}
						insert_after(cur2,cur1);
						break;

			case 3:		printf("Data:");
						scanf("%d",&data);
						cur1=create(data);
						insert_end(cur1,head);
						break;

			case 4:		
						printf("Data prev to the data being deleted:");
						scanf("%d",&data1);	
						cur1=head;
						while(cur1->info!=data1){
							cur1=cur1->next;
						}			
						delete_after(cur1);
						break;

			case 5:		delete_front(phead);
						break;

			case 6:		display(head);
						break;

			default:	break;
						
		}
		printf("Do you want to perform more operation(1 for yes/ 0 for no):");
		scanf("%d",&choice);
	}while(choice==1);
}
