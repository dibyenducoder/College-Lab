#include <stdio.h>



long x=0,start=0,end,a[2][10000];



typedef struct {      //user defined matrix

	long row[10000];

	long column[10000];

	float value[10000];

}matrix;



struct storage{    //memeory storage

	long row[500000];

	long column[500000];

	float value[500000];

};



struct storage termpool;



matrix inputmat(matrix m){

	long r,c,r_size,c_size,loop;float term,val;

	printf("Enter no of rows :"); 

	scanf("%ld",&r_size);

	printf("Enter no of colums :");

	scanf("%ld",&c_size);

	m.row[0]=r_size;

	m.column[0]=c_size;

	printf("Enter no of non-zero terms : ");

	scanf("%f",&term);

	m.value[0]=term;

	printf("Enter non-zero elemnts in rowwise and ascending order of colums\n");

	for(loop=1;loop<=term;loop++)

	{

		printf("Enter row no of %ld no term : ",loop);

		scanf("%ld",&r);

		m.row[loop]=r;

		printf("Enter column no of %ld no term : ",loop);

		scanf("%ld",&c);

		m.column[loop]=c;

		printf("Enter value of %ld no term : ",loop);

		scanf("%f",&val);

		m.value[loop]=val;

		printf("\n");

	}

	return(m);

}



void storemat(matrix m_str)     //storing matrix 

{

	long i;float trm;

	trm=m_str.value[0];

	for(i=1;i<=trm;i++)

	{

		termpool.row[start+i-1]=m_str.row[i];

		termpool.column[start+i-1]=m_str.column[i];

		termpool.value[start+i-1]=m_str.value[i];

	}

	end=start+trm-1;

	a[0][x]=start;

	a[1][x]=end;

	start=end+1;

	x++;

}



matrix constmult(matrix m_const,float c)       //multiplication  of constant value 

{

	matrix m_result;

	long r_c,c_c,lp; float term_c;          

	r_c=m_const.row[0];                     

	c_c=m_const.column[0];

	term_c=m_const.value[0];

	m_result.row[0]=r_c;

	m_result.column[0]=c_c;

	m_result.value[0]=term_c;

	for(lp=1;lp<=term_c;lp++)

	{

		m_result.row[lp]=m_const.row[lp];

		m_result.column[lp]=m_const.column[lp];

		m_result.value[lp]=c*m_const.value[lp];

	}

	return(m_result);

}

matrix deletehead(matrix m_del,long del)       //deleting matrix 

{

	long k,term_del=m_del.value[0];

	if(del!=term_del)

	{

		for(k=del;k<term_del;k++)

		{

			m_del.column[k]=m_del.column[k+1];

			m_del.row[k]=m_del.row[k+1];

			m_del.value[k]=m_del.value[k+1];

		}

	}

	m_del.value[0]--;

	return(m_del);

}

matrix addmat(matrix ma1,matrix ma2)       //adding matrix

{

	matrix m_add;

	long o1,o2,r1,r2,c1,c2,r_add,c_add,lp1_add,lp2_add,lp_add;float terma1,terma2,term_add;

	r1=ma1.row[0];

	c1=ma1.column[0];

	r2=ma2.row[0];

	c2=ma2.column[0];

		r_add=r1;

		c_add=c1;

		terma1=ma1.value[0];

		terma2=ma2.value[0];

		m_add.row[0]=r_add;

		m_add.column[0]=c_add;

		m_add.value[0]=r_add*c_add;

		for(lp_add=1;lp_add<=r_add*c_add;lp_add++)

		{

			m_add.row[lp_add]=0;

			m_add.column[lp_add]=0;

			m_add.value[lp_add]=0;

		}

		for(lp1_add=1;lp1_add<=terma1;lp1_add++)

		{

		 	r1=ma1.row[lp1_add];

			c1=ma1.column[lp1_add];

			o1=r_add*(r1-1)+c1;

			m_add.row[o1]=r1;

			m_add.column[o1]=c1;

			m_add.value[o1]+=ma1.value[lp1_add];

		} 

		for(lp2_add=1;lp2_add<=terma2;lp2_add++)

		{

		 	r2=ma2.row[lp2_add];

			c2=ma2.column[lp2_add];

			o2=r_add*(r2-1)+c2;

			m_add.row[o2]=r2;

			m_add.column[o2]=c2;

			m_add.value[o2]+=ma2.value[lp2_add];

		}

		for(lp_add=1;lp_add<=m_add.value[0];lp_add++) 

		{

		if(m_add.value[lp_add]==0) {m_add=deletehead(m_add,lp_add);lp_add--;}

		}

		return(m_add);

}

void display(matrix m_pr)  //displaying the matrix

{

	long rs,cs,i,j,lp,p,q;

	rs=m_pr.row[0];

	cs=m_pr.column[0];

	float m_array[rs+1][cs+1],n;

	for(i=1;i<=rs;i++)

	{

		for(j=1;j<=cs;j++) m_array[i][j]=0;

	}

	n=m_pr.value[0];

	for(lp=1;lp<=n;lp++)

	{

		p=m_pr.row[lp];

		q=m_pr.column[lp];

		m_array[p][q]=m_pr.value[lp];

	}

	printf("\n\ngiven matrix is \n");

	for(i=1;i<=rs;i++)

	{

		for(j=1;j<=cs;j++) printf(" %f ",m_array[i][j]);

		printf("\n");

	}

}

matrix multmat(matrix m_mul1,matrix m_mul2) //muliplication of matrix (matrix1 * matrix2 = matrix3)

{

	matrix mul_result;

	long lm1,t,lm2,lp_mul,rl1,rl2,cl1,cl2,row1,col1,row2,col2;float max_size,size1,size2;

	row1=m_mul1.row[0];

	row2=m_mul2.row[0];

	col1=m_mul1.column[0];

	col2=m_mul2.column[0];

	max_size=(float)row1*(float)col2;

	

	size1=m_mul1.value[0];

	size2=m_mul2.value[0];

	mul_result.row[0]=row1;

	mul_result.column[0]=col2;

	mul_result.value[0]=max_size;

	for(lp_mul=1;lp_mul<=max_size;lp_mul++)

	{

		mul_result.row[lp_mul]=0;

		mul_result.column[lp_mul]=0;

		mul_result.value[lp_mul]=0;

	}

	for(lm1=1;lm1<=size1;lm1++)

	{

		rl1=m_mul1.row[lm1];

		cl1=m_mul1.column[lm1];

		for(lm2=1;lm2<=size2;lm2++)

		{

			rl2=m_mul2.row[lm2];

			cl2=m_mul2.column[lm2];

			if(cl1==rl2)

			{

				t=row1*(rl1-1)+cl2;

				mul_result.value[t]=mul_result.value[t]+(m_mul1.value[lm1])*(m_mul2.value[lm2]);

				mul_result.row[t]=rl1;

				mul_result.column[t]=cl2;			

			}

		}

	}

	for(lp_mul=1;lp_mul<=mul_result.value[0];lp_mul++) 

	{

		if(mul_result.value[lp_mul]==0) {mul_result=deletehead(mul_result,lp_mul);lp_mul--;}

	}

		return(mul_result);

}



matrix transpose(matrix m_org) //transpose of user matrix 

{

	matrix m_t;long lt;float lnth;

	m_t.column[0]=m_org.row[0];

	m_t.row[0]=m_org.column[0];

	lnth=m_org.value[0];

	m_t.value[0]=m_org.value[0];

	for(lt=1;lt<=lnth;lt++)

	{

		m_t.column[lt]=m_org.row[lt];

		m_t.row[lt]=m_org.column[lt];

		m_t.value[lt]=m_org.value[lt];

	}

	return(m_t);

}



matrix minor(matrix ma,long a,long b)   //minor of user matrix

{

	matrix m_min=ma;

	long i_minor;float s_minor;

	for(i_minor=1;i_minor<=m_min.value[0];i_minor++)

	{

		if(m_min.row[i_minor]==a || m_min.column[i_minor]==b) 	{m_min=deletehead(m_min,i_minor);i_minor--;}

	}

	for(i_minor=1;i_minor<=m_min.value[0];i_minor++)

	{

		if(m_min.row[i_minor]>a) m_min.row[i_minor]--;

		if(m_min.column[i_minor]>b) m_min.column[i_minor]--;

	}

	m_min.row[0]--;

	m_min.column[0]--;

	return(m_min);

}

float det(matrix m_det)

{

	matrix md;

	long r,c,n,lp_det,i1,i2;

	float sum=0,term;

	n=m_det.row[0];

	term=m_det.value[0];

	float mat[n+1][n+1],sm[n+1];

	for(i1=1;i1<=n;i1++)

	{

		for(i2=1;i2<=n;i2++)

		{

			mat[i1][i2]=0;

		}

	}

	for(lp_det=1;lp_det<=term;lp_det++)

	{

		r=m_det.row[lp_det];

		c=m_det.column[lp_det];

		mat[r][c]=m_det.value[lp_det];

	}

	if(n==2)

	{

		return((mat[1][1]*mat[2][2])-(mat[1][2]*mat[2][1]));

	}

	if(n==1)

	{

		if(term==0) return 0;

		else return(m_det.value[1]);

	}

	for(lp_det=1;lp_det<=n;lp_det++)

	{

		if(mat[1][lp_det]!=0)

		{

			md=minor(m_det,1,lp_det);

			if(lp_det%2==0) sum-=mat[1][lp_det]*det(md);

			else sum+=mat[1][lp_det]*det(md);

		}

	}

	return(sum);

}



matrix adjoint(matrix m_xy)     //adjoint matrix

{

	matrix mr,m_new;

	long sze,ii,ij,k;float dx;

	sze=m_xy.row[0];

	float ax[sze+1][sze+1];

	m_new.row[0]=sze;

	m_new.column[0]=sze;

	m_new.value[0]=(float)(sze*sze);

	for(ii=1;ii<=sze;ii++)

	{

		for(ij=1;ij<=sze;ij++)

		{

			mr=minor(m_xy,ii,ij);

			dx=det(mr);

			if(dx!=0 && (ii+ij)%2!=0) dx*=-1;

			//display(mr);

			//printf("%f\n",dx);

			k=sze*(ii-1)+ij;

			m_new.row[k]=ii;

			m_new.column[k]=ij;

			m_new.value[k]=dx;

		}

	}

	for(ii=1;ii<=m_new.value[0];ii++)

	{

	    if(m_new.value[0]==0) {m_new=deletehead(m_new,ii);ii--;}

	}

	m_new=transpose(m_new);

	return(m_new);

}

matrix inverse(matrix ms)        //inverse of matrix

{

    float di=det(ms);matrix m_inv;

    di=(float)1/di;

    m_inv=adjoint(ms);

    m_inv=constmult(m_inv,di);

    return(m_inv);

    

}

int main()  //main function starts

{

	matrix inv,adj,min_m,mul1,mul2,product,del_m,m1,trans_m,constm,m2,sum_m,mt,mi;

	float cst;

	long head,i,j,no;float d;

	m1=inputmat(m1);

	storemat(m1);

	display(m1);

	printf("\n\nFOR CONSTANT MULTIPLICATION\n\n");

	printf("Enter value of the constant : ");

	scanf("%f",&cst);

	constm=constmult(m1,cst);

	storemat(constm);

	display(constm);

	printf("\n\nFOR MATRIX ADDITION\n\n");

	printf("\n\nEnter a  2nd matrix\n");

	m2=inputmat(m2);

	storemat(m2);

	if(m1.column[0]==m2.column[0] && m1.row[0]==m2.row[0])

	{

		sum_m=addmat(m1,m2);

		storemat(sum_m);

		printf("1st matrix\n");

		display(m1);

		printf("2nd matrix\n");

		display(m2);

		printf("sum\n");

		display(sum_m);

	}

	else printf("ERROR!orders are unmatched\n");

	printf("\n\nFOR MATRIX MULTIPLICATION\n\n");

	printf("Enter 1 st matrix \n");

	mul1=inputmat(mul1);

	storemat(mul1);

	printf("Enter 2nd matrix \n");

	mul2=inputmat(mul2);

	storemat(mul2);

	if(mul1.column[0]==mul2.row[0])

	{

		product=multmat(mul1,mul2);

		storemat(product);

		printf("1st matrix is \n");

		display(mul1);

		printf("2nd matrix is \n");

		display(mul2);

		printf("result is \n");

		display(product);

	}

	else printf("Error!orders are unmatched\n");

	printf("\n\nFOR TRANSPOSING A MATRIX\n\n");

	mt=inputmat(mt);

	storemat(mt);

	trans_m=transpose(mt);

	storemat(trans_m);

	printf("Original matrix : ");

	display(mt);

	printf("Transpose matrix : ");

	display(trans_m);

	printf("\n\nFOR FINDING INVERSE\n\n");

	printf("Please enter a square matrix \n");

	mi=inputmat(mi);

	storemat(mi);

	d=det(mi);

	if(mi.row[0]==mi.column[0])

	{

	    display(mi);

	    if(d!=0)

	    {

	        printf("Inverse of the matrix is : ");

	        inv=inverse(mi);

	        storemat(inv);

	        display(inv);

	    }

	    else printf("Given matrix is singular ,inverse not possible\n");

	}

	else printf("Error!input is not a square matrix\n");

	return 0;

}


