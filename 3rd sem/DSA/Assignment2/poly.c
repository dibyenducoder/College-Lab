#include <stdio.h>

long a[2][1000],fr[2][1000],x=0,freet=0,freep=0,start=0,end;//x denotes no of pol in termpool

struct storage

{

	long power[100000];

	float coeff[100000];

};

typedef struct

{

	float coeff[100];

	long power[100];

}pol;

struct storage termpool;

pol inputpoly(pol p)

{

	long term,i;

	printf("Enter no of terms : ");

	scanf("%ld",&term);

	p.coeff[0]=0;

	p.power[0]=term;

	for(i=1;i<=term;i++) 

	{

		printf("Enter coeff of %d no term : ",i);

		scanf("%f",&p.coeff[i]);

		printf("Enter power of %d no term : ",i);

		scanf("%ld",&p.power[i]);

	}

	return(p);

}

void storepoly(pol p_str)

{

	long i,term;

	term=p_str.power[0];

	for(i=1;i<=term;i++) 

	{

		termpool.coeff[start+i-1]=p_str.coeff[i];

		termpool.power[start+i-1]=p_str.power[i];

	}

	end=start+term-1;

	a[0][x]=start;

	a[1][x]=end;

	freep++;

	freet+=term;

	fr[0][x]=freep;

	fr[1][x]=freet;

	start=end+1;

	x++;

}

void printpoly(pol p_print,int cnt)

{

	long loop,term;

	term=p_print.power[0];

	for(loop=1;loop<term;loop++) 

	{

		printf("%fx^%d+",p_print.coeff[loop],p_print.power[loop]);

	}

	if(p_print.power[term]==0) printf("%f",p_print.coeff[term]);

	else printf("%fx^%d",p_print.coeff[term],p_print.power[term]);

	printf("\n");

}

pol bringpoly(long i)

{

	pol pi;

	long start,end,count,term;

	start=a[0][i];

	end=a[1][i];

	//printf("%ld	%ld",start,end);

	term=end+1-start;

	pi.power[0]=term;

	pi.coeff[0]=0;

	for(count=1;count<=term;count++)

	{

		pi.coeff[count]=termpool.coeff[start+count-1];

		pi.power[count]=termpool.power[start+count-1];

	}

	return(pi);

}

pol cmult(pol p,float c)

{

	long i,term;

	pol pc;

	term=p.power[0];

	for(i=0;i<=term;i++)

	{

		pc.coeff[i]=c*p.coeff[i];

		pc.power[i]=p.power[i];

	}

	return(pc);

}

long deg(pol p_deg)

{

	long max_power;

	max_power=p_deg.power[1];

	return(max_power);

}

pol delete_term(pol p,long i)

{

	long term=p.power[0],j;

	if(i!=term)

	{

		for(j=i;j<=term-1;j++) 

		{

			p.coeff[j]=p.coeff[j+1];

			p.power[j]=p.power[j+1];

		}

	}

	p.power[0]--;

	return(p);

}

pol ommitzero(pol p_ommit)

{

	long loop,term=p_ommit.power[0];

	for(loop=1;loop<=p_ommit.power[0];loop++)

	{

		if(p_ommit.coeff[0]==0) {p_ommit=delete_term(p_ommit,loop);loop--;}

	}

	return(p_ommit);

}

pol addpol(pol p1,pol p2)

{

	pol p_add;long lngth,min_degree,md1,md2,k_pow,k_coeff,pow,i,j,lp1,lp2,degree1,degree2,degree,term1,term2,max_t,found;

	term1=p1.power[0];

	term2=p2.power[0];

	degree1=deg(p1);

	degree2=deg(p2);

	md1=p1.power[term1];

	md2=p1.power[term2];

	degree=degree1;

	if(degree2>degree1) degree=degree2;

	min_degree=md1;

	if(md2<md1) min_degree=md2;

	lngth=degree+1-min_degree;

	p_add.power[0]=lngth;

	for(i=1;i<=lngth;i++)

	{

		p_add.coeff[i]=0;

		p_add.power[i]=0;

	}

	for(lp1=1;lp1<=term1;lp1++)

	{

		pow=p1.power[lp1];

		p_add.coeff[degree+1-pow]+=p1.coeff[lp1];

		p_add.power[degree+1-pow]=p1.power[lp1];

	}

	for(lp2=1;lp2<=term2;lp2++)

	{

		pow=p2.power[lp2];

		p_add.coeff[degree+1-pow]+=p2.coeff[lp2];

		p_add.power[degree+1-pow]=p2.power[lp2];

	}

	p_add=ommitzero(p_add);

	return(p_add);

}

void multiply(pol pa,pol pb)

{

	pol sum,p;

	float cf;

	long pow1,pow2,pow,lp1,lp2,md1,md2,max_deg,min_deg,term1,term2,deg1,deg2,lngth;

	term1=pa.power[0];

	term2=pb.power[0];

	deg1=deg(pa);

	deg2=deg(pb);

	max_deg=deg1+deg2;

	md1=pa.power[term1];

	md2=pb.power[term2];

	min_deg=md1+md2;

	lngth=max_deg+1-min_deg;

	sum.power[0]=lngth;

	sum.coeff[0]=0;

	for(lp1=1;lp1<=lngth;lp1++)

	{

		sum.coeff[lp1]=0;

		sum.power[lp1]=0;

	}

	for(lp1=1;lp1<=term1;lp1++)

	{	

		pow1=pa.power[lp1];

		for(lp2=1;lp2<=term2;lp2++)

		{

			pow2=pb.power[lp2];

			pow=pow1+pow2;

			sum.coeff[max_deg+1-pow]+=pa.coeff[lp1]*pb.coeff[lp2];

			sum.power[max_deg+1-pow]=pow;

		}

	}

		ommitzero(sum);

	storepoly(sum);

	printf("Product is : ");

	printpoly(sum,x-1);

}



void zeropol_check(pol p0)

{

	long i,term;

	int chck=0;

	term=p0.power[0];

	for(i=1;i<=term;i++)

	{

		if(p0.coeff[i]!=0) {chck=1;break;}

	}

	printf("Given polynomial is :");

	if(chck==1) printf("non-");

	printf("zero polynomial\n");

}	

int main()

{

	

	int choice,chc,err=0,err1,err2;

	float c;

	long a,b,q;

	pol sum_p,p,pc,p1,p2,p3,product,zero_p;

	printf("Enter a choice \n1 for degree\n2 for constant multiplication\n3 for addition\n4 for polynomial multiplication\n5 for checking zero polynomial\n0 to terminate\n");

	scanf("%d",&choice);

	while(choice!=0){

	err=0;err1=0;err2=0;

	if(choice==1)

	{

		printf("\npress 0 for entering new pol\npress 1 for using used pol\n\n[for first time enter new pol]\n");

		scanf("%ld",&chc);

		if(chc==0) {p=inputpoly(p);storepoly(p);}

		if(chc==1)

		{

			printf("Enter no of which pol to be taken : ");

			scanf("%d",&a);

			if(a<x) p=bringpoly(a);

			else {printf("ERROR\n");err=1;}

		}

		if(err==0)

		{

		printpoly(p,x-1);

		printf("Degree is : %ld\n",deg(p));

		}

	}

	if(choice==2)

	{

		printf("\npress 0 for entering new pol\npress 1 for using used pol\n\n[for first time enter new pol]\n");

		scanf("%ld",&chc);

		if(chc==0) {p=inputpoly(p);storepoly(p);}

		if(chc==1)

		{

			printf("Enter no of which pol to be taken : ");

			scanf("%d",&a);

			if(a<x) p=bringpoly(a);

			else {printf("ERROR\n");err=1;}

		}

		if(err==0)

		{

		printf("Enter a constant : ");

		scanf("%f",&c);

		pc=cmult(p,c);

		storepoly(pc);

		printf("Given polynomial : ");

		printpoly(p,x-1);

		printf("Product is : ");

		printpoly(pc,x-1);

		}

	}

	if(choice==3)

	{

		printf("taking 1 st pol\n");

		printf("\npress 0 for entering new pol\npress 1 for using used pol\n\n[for first time enter new pol]\n");

		scanf("%ld",&chc);

		if(chc==0) {p=inputpoly(p);storepoly(p);}

		if(chc==1)

		{

			printf("Enter no of which pol to be taken : ");

			scanf("%d",&a);

			if(a<x) p=bringpoly(a);

			else {printf("ERROR\n");err=1;}

		}

		printf("taking 2 nd pol\n");

		printf("\npress 0 for entering new pol\npress 1 for using used pol\n\n[for first time enter new pol]\n");

		scanf("%ld",&chc);

		if(chc==0) {p1=inputpoly(p1);storepoly(p1);}

		if(chc==1)

		{

			printf("Enter no of which pol to be taken : ");

			scanf("%d",&a);

			if(a<x) p1=bringpoly(a);

			else {printf("ERROR\n");err=1;}

		}

		if(err==0)

		{

		printf("1 st polynomial : ");

		printpoly(p,x-1);

		printf("2 nd polynomial : ");

		printpoly(p1,x-1);

		sum_p=addpol(p,p1);

		storepoly(sum_p);

		printf("Sum is :");

		printpoly(sum_p,x-1);

		}

	}

	if(choice==4)

	{

		printf("taking 1 st pol\n");

		printf("\npress 0 for entering new pol\npress 1 for using used pol\n\n[for first time enter new pol]\n");

		scanf("%ld",&chc);

		if(chc==0) {p2=inputpoly(p2);storepoly(p2);}

		if(chc==1)

		{

			printf("Enter no of which pol to be taken : ");

			scanf("%d",&a);

			if(a<x) p2=bringpoly(a);

			else {printf("ERROR\n");err=1;}

		}

		printf("taking 2 nd pol\n");

		printf("\npress 0 for entering new pol\npress 1 for using used pol\n\n[for first time enter new pol]\n");

		scanf("%ld",&chc);

		if(chc==0) {p3=inputpoly(p3);storepoly(p3);}

		if(chc==1)

		{

			printf("Enter no of which pol to be taken : ");

			scanf("%d",&a);

			if(a<x) p3=bringpoly(a);

			else {printf("ERROR\n");err=1;}

		}

		if(err==0)

		{

		printf("1 st polynomial is : ");

		printpoly(p2,x-1);

		printf("2 nd  polynomial is : ");

		printpoly(p3,x-1);

		multiply(p2,p3);

		}

	}

	if(choice==5)

	{

		printf("\npress 0 for entering new pol\npress 1 for using used pol\n\n[for first time enter new pol]\n");

		scanf("%ld",&chc);

		if(chc==0) {zero_p=inputpoly(zero_p);storepoly(zero_p);}

		if(chc==1)

		{

			printf("Enter no of which pol to be taken : ");

			scanf("%d",&a);

			if(a<x) zero_p=bringpoly(a);

			else {printf("ERROR\n");err=1;}

		}

		if(err==0) zeropol_check(zero_p);

	}

	if(choice!=1 && choice!=2 && choice!=3 && choice!=4 && choice!=5) printf("Enter 1/2/3/4/5\n");

	printf("\n\nfree terms %ld free polynomials %ld\n",fr[0][x-1],fr[1][x-1]);

	printf("Enter a choice \n1 for degree\n2 for constant multiplication\n3 for addition\n4 for polynomial multiplication\n5 for checking zero polynomial\n0 to terminate\n");

	scanf("%d",&choice);

	}

	return 0;

}
