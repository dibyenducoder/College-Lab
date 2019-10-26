#include <stdio.h>
#include <stdlib.h>
#include "single_linear_linkedlist.h"
	
int main(){
	int num,ch;
	FILE *fptr;
	node *head1,*cur1,*head2,*cur2,**phead1;
	

	printf("Menu:\n1.Read in same order\n2.Read in reverse order\n\n");
	scanf("%d",&ch);
	switch(ch){
	case 2:		fptr=fopen("numbers.txt","r");
				if(fptr==NULL){
				printf("No such file exist!\n");
				exit(0);
				}
				fscanf(fptr,"%d",&num);
				head1=create(num);
				phead1=&(head1);
				while(!feof(fptr)){
					fscanf(fptr,"%d",&num);
					cur1=create(num);
					insert_front(cur1,phead1);
					
				};
				fclose(fptr);
				display(head1);
				break;
				
	case 1:		fptr=fopen("numbers.txt","r");
				if(fptr==NULL){
				printf("No such file exist!\n");
				exit(0);
				}
				
				fscanf(fptr,"%d",&num);
				head2=create(num);
				
				while(!feof(fptr)){
					fscanf(fptr,"%d",&num);
					cur2=create(num);
					insert_end(cur2,head2);
					
				};
				fclose(fptr);

				
				display(head2);
				break;

	default:	break;
			}

	return 0;
}
