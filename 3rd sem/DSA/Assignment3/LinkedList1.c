#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int info;
	struct node *next;
}nodetype;

nodetype* createNode(int item);
nodetype* init_l();
int isEmpty(nodetype* head);
int atEnd(nodetype* cur);
void insertFront(nodetype* target, nodetype **phead);
void insertAfter(nodetype* target, nodetype *prev);
void deleteFront(nodetype **phead);
void deleteAfter(nodetype* prev);
void display(nodetype** head);

 int main(){
 	int n;
 	printf("Enter the total number of node :");
    scanf("%d",&n);
    
 	nodetype* start;
 	start=createNode(n);
 	display(&start);
 	
// 	nodetype* target;
// 	target=createNode(3);
// 	insertFront(target,&start);

// 	target=createNode(4);
// 	insertFront(target,&start);
// 	display(&start);
	 	
// 	deleteFront(&start);
// 	display(&start);

    
 	return 0;
 }

//Function to display a linked list
void display(nodetype** head){
	nodetype* cur=(nodetype*)malloc(sizeof(nodetype));
	if(head!=NULL){
		cur=*head;
		while(cur!=NULL){
			printf("%d ",cur->info);
			cur=cur->next;
			
		}
		printf("\n");
	}
	else
		printf("Empty list\n");
}

//Function to create node
nodetype* createNode(int item){
	nodetype* head=NULL;
	if((head=(nodetype*)malloc(sizeof(nodetype)))==NULL)
		perror("malloc error");
	else{
		head->info=item;
		head->next=NULL;
	}
	return head;
}

//Initialise a linked list
nodetype* init_l(){
	return NULL;
}

//Check whether list is empty
int isEmpty(nodetype* head){
	return (head==NULL);
}

//Check whether the current node is at end
int atEnd(nodetype* cur){
	if(cur==NULL)
		return 0;
	else
		return (cur->next==NULL);
}

//Function to insert a node at front
void insertFront(nodetype* target, nodetype **phead){
	target->next=*phead;
	*phead=target;
}

//Function to insert a node after a given node
void insertAfter(nodetype* target, nodetype *prev){
	nodetype* cur=(nodetype*)malloc(sizeof(nodetype));
	cur=prev->next;
	target->next=cur;
	prev->next=target;
}

//Function to delete node from front of linked list
void deleteFront(nodetype **phead){
	nodetype* cur=(nodetype*)malloc(sizeof(nodetype));
	cur=*phead;
	*phead=(*phead)->next;
	free(cur);
}

//Function to delete a node after a particular node
void deleteAfter(nodetype* prev){
	nodetype* cur=(nodetype*)malloc(sizeof(nodetype));
	if(!atEnd(prev)){
		cur=prev->next;
		prev->next=cur->next;
		free(cur);
	}
}
