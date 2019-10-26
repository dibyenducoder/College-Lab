#include <stdio.h>

typedef struct   //user defined function called list

{
	float element[121];          //max of elements can hold

}list;


list initialize_list(list l_intl)     //initialize the list 
{
	int ii;
	for(ii=1;ii<=120;ii++)   //number of elements can be put by user if wis 
        l_intl.element[ii]=-1;   //if no input then gives no element in the list
	return(l_intl);
}

/*wishing to enter the elements or not */

list inputlist(list l_in){

	float val;int in=1; 
        int choice;  //for taking input or not
	printf("Press '1' for yes taking input :\nPress 'any key' for terminate : \n");
	scanf("%d",&choice);  //1 for tasking input and 0
        printf("\n");
	while(choice==1){
		printf("Enter a non-negative element : ");
		scanf("%f",&val);
		l_in.element[in]=val;
		in++;
		printf("Press 'yes' for taking input\nPress 'any key' for terminate\n");
		scanf("%d",&choice);
                printf("\n");
	}
	return(l_in);
}

/*check whether the list of elements is empty or not*/

int emptylist(list l_empty){
	if(l_empty.element[1]==-1) return 0;
	else return 1;
}

/*finding the length of nodes */

int length(list ll){
	int cnt=0;
	if(emptylist(ll)!=0)	{
		while(ll.element[cnt+1]!=-1) cnt++;
	}
	return(cnt);
}

/*printing the list of elements*/

void printlist(list l_pr){
	int j;
	for(j=1;j<=length(l_pr);j++)
        printf("Element no : %d = %f\n",j,l_pr.element[j]);
}
/*writing the elements by user input*/
void write_element(list lw,int n){
	if(n<=length(lw)){
		printf("%dth element is : %f\n",n,lw.element[n]);
	}
	else printf("%dth elements is not available\n",n);
}

/*inserting the elements in which you want to insert on the particular nodes*/

list insert(list l_ins,int ins,float value){
	int i,la,temp;
	la=length(l_ins);
	for(i=la;i>=ins;i--){
		l_ins.element[i+1]=l_ins.element[i];
	}
	l_ins.element[ins]=value;
	return(l_ins);
}

/*deleting the element in which you want to delete the number on the particalr nodes*/

list delete_element(list l_del,int del){
	int i_del,ld;
	ld=length(l_del);
	for(i_del=del;i_del<=ld;i_del++) l_del.element[i_del]=l_del.element[i_del+1];
	return(l_del);
}

/*sorting it in desending order*/

list sortlist(list l_sort){
	int ls;
	ls=length(l_sort);
	int i,j;float key;
	for(i=2;i<=ls;i++){
		key=l_sort.element[i];
		j=i-1;
		while(l_sort.element[j]>key && j>=1) {
                      l_sort.element[j+1]=l_sort.element[j];
                       j--;
                }
		l_sort.element[j+1]=key;
	}
	return(l_sort);
}

/*Main function starts ---*/

int main(){

	list sortl,l,l1;int lngth,na,ni,nd;float insertion;
	l=initialize_list(l);
	l=inputlist(l);
	lngth=length(l);
	printf("\n\nCHECKING EMPTY LIST\n\n");
	if(emptylist(l)==0) printf("List is empty\n");
	else printf("List is non-empty\n");
	printf("\n\nFINDING LIST-LENGTH\n\n");
	printf("Length of the list is : %d\n",lngth);
	printf("\n\nPRINTING ORIGINAL LIST\n\n");
	printlist(l);
	printf("\n\nSHOWING nth ELEMENT\n\n");
	printf("Enter the node number whose element to be printed : ");
	scanf("%d",&na);
	write_element(l,na);
	printf("\n\nPRINTING INSERTED LIST\n\n");
	printf("Enter the node number in which element to be inserted : ");
	scanf("%d",&ni);
	printf("Enter value to be inserted : ");
	scanf("%f",&insertion);
	l=insert(l,ni,insertion);
	printlist(l);
	printf("\n\nPRINTING DELETED LIST\n\n");
	printf("Enter the node number in which element to be deleted : ");
	scanf("%d",&nd);
	l1=delete_element(l,nd);
	printlist(l1);
	printf("\n\nPRINTING SORTED LIST\n\n");
	sortl=sortlist(l);
	printlist(sortl);
	return 0;

}
