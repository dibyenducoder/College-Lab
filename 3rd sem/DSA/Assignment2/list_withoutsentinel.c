#include <stdio.h>

typedef struct
{

	float element[121];  //max of elements can hold

}list;

list initialize_list(list l_intl){ //initialize the list 
	int ii;
	for(ii=1;ii<=120;ii++)   //number of elements can be put by user if wish
         l_intl.element[ii]=-1;  //if no input then gives no element in the list
	return(l_intl);
}

/*enter elements by user*/

list inputlist(list l_in){
	float val,sze;int in;
	printf("Enter length of the list : ");
	scanf("%f",&sze);
	l_in.element[0]=sze;
	for(in=1;in<=sze;in++)
	{
		printf("Enter element %d : ",in);
		scanf("%f",&l_in.element[in]);
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
	return((int)ll.element[0]);
}

/*printing the list of elements*/

void printlist(list l_pr){
	int j;
	for(j=1;j<=length(l_pr);j++) printf("Element no  %d = %f\n",j,l_pr.element[j]);
}

/*writing the list of elements*/

void write_element(list lw,int n){
	if(n<=length(lw)){
		printf("%d no element is : %f\n",n,lw.element[n]);
	}
	else printf("%d no element is not available\n",n);
}

/*inserting the elements in which you want to insert on the particular nodes*/

list insert(list l_ins,int ins,float value){
	int i,temp;float la;
	la=length(l_ins);
	for(i=la;i>=ins;i--)	{
		l_ins.element[i+1]=l_ins.element[i];
	}
	l_ins.element[ins]=value;
	l_ins.element[0]++;
	return(l_ins);
}

/*deleting the element in which you want to delete the number on the particalr nodes*/

list delete_element(list l_del,int del){
	int i_del;float ld;
	ld=length(l_del);
	for(i_del=del;i_del<=ld;i_del++) l_del.element[i_del]=l_del.element[i_del+1];
	l_del.element[0]--;
	return(l_del);
}

/*sorting it in desending order*/

list sortlist(list l_sort){
	float ls;
	ls=length(l_sort);
	int i,j;float key;
	for(i=2;i<=ls;i++){
		key=l_sort.element[i];
		j=i-1;
		while(l_sort.element[j]>key && j>=1) {l_sort.element[j+1]=l_sort.element[j];j--;}
		l_sort.element[j+1]=key;
	}
	return(l_sort);
}

/*Main function starts ---*/

int main(){
	list sortl,l,l1,l2;int lngth,na,ni,nd;float insertion;	
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
	l2=insert(l,ni,insertion);
	printlist(l2);
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

