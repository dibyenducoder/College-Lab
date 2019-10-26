#include<stdio.h>
#include<stdlib.h>
typedef struct nodetag{
	int info;
	struct nodetag *next;
}node;





node* init_l(){	return NULL;}

node* create(int info){	
	node *cur;
	if((cur=(node*)malloc(sizeof(struct nodetag)))==NULL){
		printf("Malloc error!\n");
	}
	else{
		cur->info = info;
		cur->next = NULL;
	}
	return cur;
	
}

int atend_l(node *cur){
	if(cur==NULL){
		return 0;
	}
		return(cur->next==NULL);
	}


int empty_l(node *head){
	return (head==NULL);
	
}

void insert_front(node *target,node **phead){

		target->next = *phead;
		*phead = target;
		

}

void insert_after(node *target,node *prev){
	node *cur;
	cur = prev->next;
	prev->next = target;
	target->next = cur;
}

void delete_front(node **phead){
	node *cur;
	cur = *phead;
	*phead = (*phead)->next;
	free(cur);

}

void delete_after(node *prev){
	node *cur;
	cur = prev->next;
	prev->next = cur->next;
	free(cur);
}

void display(node *head){
	node *cur;
	cur=head;
	if(head==NULL){
		printf("No list present\n");
	}
	else{
		printf("%d <-\n",cur->info);
		


			while((cur->next)!=NULL){
				cur = cur->next;

				printf("%d\n",cur->info);
			
			
			}
	}	
}

void insert_end(node *target,node *head){
	

	node *cur;
	cur=head;
	while(cur->next!=NULL){
		cur=cur->next;
	}
	if(head==NULL){
		head=target;
		
	}

	else{
		insert_after(target,cur);
		cur=target;
	}

	
}
