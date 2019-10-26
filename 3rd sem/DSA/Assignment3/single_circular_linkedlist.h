typedef struct nodetag
{
    int data;
    struct nodetag *next;
}node;
 
  node* addToEmpty(node **plast, int data)
{
    // This function is only for empty list
    if (*plast == NULL)
	{      
 
    // Creating a node dynamically.
  	node *temp = 
           (node*)malloc(sizeof(node));
 
    // Assigning the data.
    temp -> data = data;
    (*plast) = temp;
 
    // Creating the link.
    (*plast) -> next = *plast;
 	}
    return *plast;
}
 
node* insert_front(node **plast, int data)
{
    if (*plast == NULL){
          return  addToEmpty(plast, data);
    }
 	else{

    node *temp = 
            (node *)malloc(sizeof(node));
 
    temp -> data = data;
    temp -> next = (*plast) -> next;
    (*plast) -> next = temp;
    return *plast;
	} 
   
}
 
void insert_end(node **plast, int data)
{
    if (*plast == NULL){
            addToEmpty(plast, data);
    }
     
    else{
    	node *temp = 
        (node *)malloc(sizeof(node));
 
    temp -> data = data;
    temp -> next = (*plast) -> next;
    (*plast) -> next = temp;
    *plast = temp;
}
 
    
}
 
void insert_after(node *prev,int data)
{
    node *target =  (node*)malloc(sizeof(node));
    target -> data = data;
    node *cur=prev->next;
    prev->next=target;
    target->next=cur;
    
 
}

void delete_after(node *prev){
	node *cur = prev->next;
	prev->next = cur->next;
	free(cur);
}
 
void display(node *last)
{
    if(last==NULL){
    	printf("Empty list\n");
    }
    else{
    	node *cur,*p;
    	cur=last->next;
    	p=cur;
    	//pointing at the starting node
    	printf("%d <-\n",cur->data);
    	while(cur->next!=p){
    		cur=cur->next;
    		//Traversing the nodes
    		printf("%d\n",cur->data);
    	}
    }
    

 
}
