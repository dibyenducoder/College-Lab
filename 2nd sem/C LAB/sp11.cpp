/*WAP to find A x B x C, where A={1,2,3,4,5}, B={1,2,3} and C={1,2,3,4}. Without using arrays */
#include <stdio.h>
int main()
{
	for (int i=1,j=1,k=1;i<6;k++,((k==5)?(k=1 && j++):1),((j==4)?(j=1,i++):1))    //Follows ternary operation in order to get one line of code
	printf("(%d\t%d\t%d)\n",i,j,k);     //where i ,j , k are A , B , C respectively
}
