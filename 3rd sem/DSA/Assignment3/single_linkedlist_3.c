#include <stdio.h>
#include <stdlib.h>
#include "single_linear_linkedlist.h"

#define MAX_LIST 5


void create_list();
int search(int,int);
int size(int);
int equal(int,int);
void write(int,int);
void append(int,int);
void delete(int,int);
int order(int);
void merge(int,int);
void add(int,int,int);
void dupli_rem(int);
void swap(int,int,int);
void front(int);
void rem_alter(int);
void rotate(int,int);
void delete_list(int);
void reverse(int);
void sort(int);

 int num;

node *head[MAX_LIST];
node **phead[MAX_LIST];

int main(){
	
	num=0;	
	int choice,ch,result,list_size,n,n1,list_no,key,list_no2;
	do{	
		//Menu for the program
		printf("Menu---\n0.Enter a list\n1.Search for a specific key\n2.Check the size of a list\n3.Check for equality of 2 lists\n4.Print a list\n5.Append a list to the end of another list\n6.Delete nodes\n7.Check the order\n8.Merge lists\n9.Insert nodes\n10.Remove duplicates\n11.Pairwise swap\n12.Move last to front\n13.Delete alternate nodes\n14.Rotate list\n15.Delete list\n16.Reverse list\n17.Sort list\n18.Display the list\n");
		printf("Now enter your choice:");
		scanf("%d",&choice);
		switch(choice){
			//choices executed
			case 0:		if(num<MAX_LIST){
							create_list();
							phead[num]=&(head[num]);
							num++;
						}
						else{
							printf("Run out of space\n");
							exit(0);
						}
						break;

			case 1: 	
	
						printf("Enter the list number to search for:");
						scanf("%d",&list_no);
						if(list_no>=num){
							printf("Not present\n");
							exit(0);
						}
						printf("Enter key:");
						scanf("%d",&key);	
						result=search(list_no,key);
						if(result==-1){
							printf("Not Found!!\n");
						}
						else{
							printf("Key found and deleted\n");
						}
						break;

			case 2:		printf("List no:");
						scanf("%d",&list_no);
						if(list_no>=num){
							printf("Not present\n");
							exit(0);
						}
						list_size=size(list_no);
						printf("Size:%d\n",list_size);
						break;

			case 3:		printf("Enter the list numbers to be compared:");
						scanf("%d %d",&list_no,&list_no2);
						result=equal(list_no,list_no2);
						if(list_no>=num || list_no2>=num){
							printf("Not present\n");
							exit(0);
						}
						if(result==0){
							printf("Not equal!\n");
						}
						else{
							printf("Equal..\n");
						}
						break;

			case 4:		printf("List no:");
						scanf("%d",&list_no);
						if(list_no>=num){
							printf("Not present\n");
							exit(0);
						}
						printf("Enter 1 for same order and 2 for reverse order\n");
						scanf("%d",&ch);
						printf("List-\n");
						write(list_no,ch);
						break;

			case 5:		printf("1st List no:");
						scanf("%d",&list_no);
						printf("2nd List no:");
						scanf("%d",&list_no2);
						if(list_no>=num || list_no2>=num){
							printf("Not present\n");
							exit(0);
						}
						append(list_no,list_no2);
						break;

			case 6:		printf("List no:");
						scanf("%d",&list_no);
						if(list_no>=num){
							printf("Not present\n");
							exit(0);
						}
						printf("Index of node to delete:");
						scanf("%d",&n);
						delete(list_no,n);
						break;

			case 7:		printf("List no:");
						scanf("%d",&list_no);
						if(list_no>=num){
							printf("Not present\n");
							exit(0);
						}
						result=order(list_no);
						if(result==0){
							printf("The list is unordered..\n");
						}
						else{
							printf("The list is orderd..\n");
						}
						break;

			case 8:		printf("List no1:");
						scanf("%d",&list_no);
						printf("List no2:");
						scanf("%d",&list_no2);	
						if(list_no>=num || list_no2>=num){
							printf("Not present\n");
							exit(0);
						}
						merge(list_no,list_no2);
						printf("Merged and stored a list No. %d\n",list_no);
						break;

			case 9:		printf("List no:");
						scanf("%d",&list_no);
						if(list_no>=num){
							printf("Not present\n");
							exit(0);
						}
						printf("Node value:");
						scanf("%d",&n);
						printf("Node position:");
						scanf("%d",&n1);
						add(list_no,n,n1);
						break;

			case 10:	printf("List no:");
						scanf("%d",&list_no);
						if(list_no>=num){
							printf("Not present\n");
							exit(0);
						}
						dupli_rem(list_no);
						break;

			case 11:	printf("List no:");
						scanf("%d",&list_no);
						if(list_no>=num){
							printf("Not present\n");
							exit(0);
						}
						printf("Enter positions to swap..\n");
						scanf("%d %d",&n,&n1);
						swap(list_no,n,n1);
						break;

			case 12:	printf("List no:");
						scanf("%d",&list_no);
						if(list_no>=num){
							printf("Not present\n");
							exit(0);
						}
						front(list_no);
						break;

			case 13:	printf("List no:");
						scanf("%d",&list_no);
						if(list_no>=num){
							printf("Not present\n");
							exit(0);
						}
						rem_alter(list_no);
						break;

			case 14:	printf("List no:");
						scanf("%d",&list_no);
						if(list_no>=num){
							printf("Not present\n");
							exit(0);
						}
						printf("How many times to rotate:");
						scanf("%d",&n);
						rotate(list_no,n);
						break;

			case 15:	printf("List no:");
						scanf("%d",&list_no);
						if(list_no>=num){
							printf("Not present\n");
							exit(0);
						}
						delete_list(list_no);
						break;

			case 16:	printf("List no:");
						scanf("%d",&list_no);
						if(list_no>=num){
							printf("Not present\n");
							exit(0);
						}
						reverse(list_no);
						break;

			case 17:	printf("List no:");
						scanf("%d",&list_no);
						if(list_no>=num){
							printf("Not present\n");
							exit(0);
						}
						sort(list_no);
						break;

		

			case 18:	printf("List no:");
						scanf("%d",&list_no);
						display(head[list_no]);
						break;

	

			default:	break;	

		}
		printf("Continue?(1 for yes/0 for no):");
		scanf("%d",&ch);
	
	}while(ch==1);
	return 0;

}


void create_list(){
	//function to create a list
	int val;
	node *cur;
	printf("Now enter the nodes(Enter -1 to stop)----\n");
	scanf("%d",&val);
	head[num]=create(val);
	cur=head[num];
	phead[num]=&(head[num]);
	while(val!=-1){
		scanf("%d",&val);
		if(val==-1){	break;}
		cur=create(val);
		insert_end(cur,head[num]);
	}

}

int search(int list_no,int key){
	// function to search a key
	node *cur;
	cur=head[list_no];
	while((cur->next)->info!=key && cur->next!=NULL){
		cur=cur->next;
	}
	if((cur->next)->info==key){
		delete_after(cur);
		return key;

	}
	else{
		return -1;
	}
}

void add(int list_no,int val,int pos){
	// function to add keys to the list
	node *cur=create(val);
	node *cur1=head[list_no];
	int iter=1;
	if(pos>size(list_no)){
		printf("Not possible!!");
		exit(0);
	}
	if(pos==1){
		insert_front(cur,phead[list_no]);
	}
	else{
		while(iter<pos-1){
			cur1=cur1->next;
			++iter;
		}
		insert_after(cur,cur1);
	}
}

int size(int list_no){
	// function to determine size of the list
	int list_size=0;
	node* cur;
	cur=head[list_no];
	while(cur->next!=NULL){
		list_size++;
		cur=cur->next;
	}
	return (list_size+1);

}

int equal(int list_no,int list_no2){
	// function to check for equality of 2 lists

	node *cur1,*cur2;
	cur2=head[list_no2];
	cur1=head[list_no];
	int flag=1;
	if(size(list_no)!=size(list_no2)){
		return 0;
	}
	while(cur1!=NULL){
		 if(cur1->info!=cur2->info){
		 	flag=0;
		 	break;
		 }
		 cur1=cur1->next;
		 cur2=cur2->next;

	}
	return flag;
}

void write(int list_no,int ch){
	// function to print a list in either reverse or same manner
	if(ch==1){
		display(head[list_no]);
	}
	else{
		node *cur,*cur1,*head_temp,**phead_temp;
		cur=head[list_no];
		cur1=create(cur->info);
		head_temp=cur1;
		phead_temp=&(head_temp);
		printf("I'm here\n");
		while(cur->next!=NULL){
			cur=cur->next;
			cur1=create(cur->info);
			insert_front(cur1,phead_temp);
		}
		display(*phead_temp);
	}

}
void append(int list_no,int list_no2){
	// function to append a list at the end of another one
	node *cur1;
	cur1=head[list_no];
	while(cur1->next!=NULL){
		cur1=cur1->next;
	}
	cur1->next=head[list_no2];

}

void delete(int list_no,int n){
	// function to delete a node form the list
	int i=0;
	node *cur1;

	if(n==1){
		delete_front(phead[list_no]);
	}

	else{
		cur1=head[list_no];
		i=1;
		while(i<n-1){
			cur1=cur1->next;
			++i;
		}
		delete_after(cur1);
	}
}

int order(int list_no){
	// function to check whether a list is ordered or unordered
	int dif1,dif2,flag=1;
	node *cur1,*cur2;
	cur1=head[list_no];
	cur2=cur1->next;
	dif1=cur2->info - cur1->info;
	while(cur2!=NULL){
		cur1=cur1->next;
		cur2=cur2->next;
		if(cur2==NULL){
			break;
		}
		dif2=cur2->info - cur1->info;
		if(dif2*dif1<0){
			flag=0;
			break;
		}
		dif1=dif2;
	}
	return flag;
}

void dupli_rem(int list_no){
	// function to erase duplicate terms in a list
	node *cur1,*cur2,*cur;
	cur1=head[list_no];
	
	while(cur1->next!=NULL){
		
				cur2=cur1;
				while(cur2->next!=NULL){

					while((cur2->next)->info==cur1->info){
						delete_after(cur2);
					}
					cur2=cur2->next;
				
				}
		
				cur1=cur1->next;
				

	}
	

}

void merge(int list_no,int list_no2){

	// function to merge 2 lists
	int small,big;
	node *cur1,*cur2,*cur;
	if(order(list_no)*order(list_no2)==0){
		printf("The lists are unorderd....aborting!!\n");
		exit(0);
	}
	else{
		if(head[list_no]->info>head[list_no2]->info){
			small=list_no2;
			big=list_no;
		}
		else{
			big=list_no2;
			small=list_no;
		}
		cur1=head[small];
		cur2=head[big];
		if(num>=MAX_LIST){
			printf("Run out of space!!!\n");
			exit(0);
		}
		head[num]=create(cur1->info);
		cur=cur1;
		cur1=cur1->next;
		while(cur->next!=NULL){
			cur=cur->next;
		}
	
		if(cur->info<cur2->info){
			append(list_no,list_no2);
		}
		else{
			while(cur1->next!=NULL || cur2->next!=NULL){
				while(cur1->info<=cur2->info && cur1->next!=NULL){
					insert_end(create(cur1->info),head[num]);		
					cur1=cur1->next;
				}
				
				while(cur2->info<cur1->info && cur2->next!=NULL){
					insert_end(create(cur2->info),head[num]);
					cur2=cur2->next;
				}
				
			}
			if(cur1->info<cur2->info){
				insert_end(create(cur1->info),head[num]);
				insert_end(create(cur2->info),head[num]);
			}	
		
			else{
				insert_end(create(cur2->info),head[num]);
				insert_end(create(cur1->info),head[num]);	
			}	
			head[list_no]=head[num];
			//free(head[num]);
		}
		
		

	}
}
void swap(int list_no,int n,int n1){

	// function to swap 2 nodes of a list
	node *cur1,*cur2;
	int temp,i=0;
	int small=n;
	int big=n1;
	if(n1<n){
		small=n1;
		big=n;
	}
	cur1=head[list_no];i=1;
	while(i<small){
		cur1=cur1->next;
		++i;
	}
	cur2=cur1->next;
	++i;
	while(i<big){
		cur2=cur2->next;
		++i;
	}
	temp=cur1->info;
	cur1->info=cur2->info;
	cur2->info=temp;
}

void front(int list_no){

	// function to bring last node to the front in a list
	int n;
	node *cur=head[list_no];
	n=size(list_no);
	swap(list_no,1,n);

}

void rem_alter(int list_no){
	
	// function to remove alternate nodes
	node *cur;
	cur=head[list_no];
	
	while((cur->next)->next!=NULL){
		delete_after(cur);
		
		cur=cur->next;	
	}
	delete_after(cur);

}

void rotate(int list_no,int n){

	// function to rotate a list
	int i;
	node *cur,*cur1;
	
	for(i=0;i<n;i++){
		cur=head[list_no];
		while((cur->next)->next!=NULL){
			cur=cur->next;
		}
		cur1=create((cur->next)->info);
		delete_after(cur);
		insert_front(cur1,phead[list_no]);
	}

}

void delete_list(int list_no){

	// function to delete a complete list
	head[list_no]=NULL;
}

void reverse(int list_no){

	// function to reverse  a list
		node *cur,*cur1,*head_temp,**phead_temp;
		cur=head[list_no];
		cur1=create(cur->info);
		head_temp=cur1;
		phead_temp=&(head_temp);
		
		while(cur->next!=NULL){
			cur=cur->next;
			cur1=create(cur->info);
			insert_front(cur1,phead_temp);
		}
		delete_list(list_no);
		head[list_no]=head_temp;
		
	}

void sort(int list_no){

	// function to sort a list
	node *cur1,*cur2;
	int small,i,j,pos,flag;
	int len=size(list_no)-1;
	cur1=head[list_no];
	i=j=1;
	while(cur1->next!=NULL){
		flag=0;
		small=cur1->info;
		cur2=cur1->next;
		j=i+1;
		
		while(cur2->next!=NULL){
			if(small>cur2->info){
				small=cur2->info;
				pos=j;
				flag=1;
			}
			cur2=cur2->next;
			++j;
		}
		if(small>cur2->info){
				small=cur2->info;
				pos=j;
				flag=1;
			}
			if(flag==1){
				swap(list_no,i,pos);		
			}

		cur1=cur1->next;
		++i;
	}

}
