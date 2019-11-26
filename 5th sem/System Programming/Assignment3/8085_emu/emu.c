#include<stdio.h>
#include<stdlib.h>
#define int long long

#define W 100
int M = 100000;

#include"getline1.h"
#include"hexmem.h"
#include"aaa.h"




char **F, **FF;
int N, P, real_M;
int limit;
char* op_table[1000000];
int sym_table[1000000];
char* mem[1000000];
FILE* fp,*fp2,*fp3;
size_t len;
char* line; int l_idx; int mem_idx;
int mem_len;

char* get()
{
	char* a =(char*)malloc(W*sizeof(char));
	int idx = 0; char ch;

	//printf("ttttt\n");

	if(l_idx == -1) { free(a); return NULL; }

	while(1) { 
		ch = line[l_idx++];  
		if(ch == '\0' || ch == ';' || ch == '\n') { free(a);  l_idx = -1; return NULL;} 
		if(ch != ' ' && ch != '\t' && ch != ':' && ch != ',' && ch != '\n') 
		{ a[idx++] = ch; break; } 
	} // skip space/:/,/\t/ etc 

	while(1)
	{
		ch = line[l_idx++];
		if(ch == '\0' || ch == ';' || ch == '\n') { l_idx = -1; a[idx] = '\0'; break; }
		if(ch == ' ' || ch == '\t' || ch == ':' || ch == ',') { a[idx] = '\0'; break; }
		a[idx++] = ch;
	}

	return a;
}

#include"stack.h"
#include"simu.c"

#include "macro.c"

#undef int
int main(int argc,char** argv)
#define int long long
{
	//init
	F = (char**)malloc(1000*sizeof(char*));
	FF = (char**)malloc(1000*sizeof(char*));
	for(int i = 0; i < 1000000; i++) { op_table[i] = NULL; sym_table[i] = -1; mem[i] = "00\0"; }
	limit = 1000;
	N = 0; 

	//printf("----> %d\n\n",hash("MVI C,\0"));

	//generate table
	line = NULL;  l_idx = 0;
	fp = fopen("optab.txt", "r"); int f = 0;
	while(getline1(&line, &len, fp) != -1)
	{
		char *x,*y; y = NULL; x = NULL;
		y = get();
		op_table[hash(y)] = "inst";
		while(1)
		{
			x = get();
			if(x == NULL) break;
			if(is(x,"-\0")) break;
			y = add(y,x);

		}
		x = get();
		if(op_table[hash(y)] != NULL && !is(op_table[hash(y)], "inst\0") )
		{
			printf("\n\ncollision: %s %s\n\n", op_table[hash(y)], x);
			f = 1;
			
		}
		op_table[hash(y)] = x;
		free(y);
		free(line); line = NULL;
		l_idx = 0; 

	}
	fclose(fp); 
	if(f == 1) return 0; // collision


	//file name
	printf("%s\n\n", argv[1]);

	//file
	fp = fopen(argv[1], "r");
	if(fp == NULL) { printf("nei\n");  return 0; }

	int op;
	printf("1: Assembly language   2: Direct Opcode\n");
	printf(">>>> ");
	scanf("%lld", &op);

	put_mem();

	if(op == 2)
	{
		line = NULL; l_idx = 0; mem_idx = 8192;
		while(getline1(&line, &len, fp) != -1)
		{
			mem[mem_idx] = (char*)malloc(4*sizeof(char));
			mem[mem_idx][0] = line[0];
			mem[mem_idx][1] = line[1];
			mem[mem_idx][2] = '\0';
			mem_idx++;
		}

		int l = mem_idx; mem_len = mem_idx;

		//return 0;

		fp = fopen("object_code.txt","w");
		for(int i = 8192; i < l; i++)
		{
			printf("%s: %s\n", conv(i), mem[i]);
			fprintf(fp, "%s\n", mem[i]);
		}

		simu();
		check();

		fclose(fp);
		printf("\n");
		return 0;

	}

	N = 0; line = NULL;
	while(getline1(&line, &len, fp) != -1)
	{
		F[N++] = line;
		line = NULL;
	}
	P = N;

	// int j = 0;
	// while(line[j] != '\0')

	macro();
	reduce();


	//after expansion
	fclose(fp); fopen("macro_expanded.txt", "w");
	for(int i=0;i<P;i++) fprintf(fp,"%s",F[i]);
	fclose(fp);

	fp3 = fopen("intermediate_file.txt","w");

	//input - pass 1
	fp2 = fopen("sym_table.txt", "w");
	line = NULL; l_idx = 0; mem_idx = 8192; int i = 0; N = 1;
	while(N <= P)
	{
		line = F[N-1]; N++;

		//printf("%d  ", mem_idx);
		//dprint(line);
		fprintf(fp3, "%s: %s", dectohex(mem_idx), line);

		char* x;

		restart:
		x = get();


		if(x == NULL) 
		{ free(x); line = NULL; l_idx = 0; continue; }
		
		//label----------------------------------
		if(op_table[hash(x)] == NULL) 
		{
			//printf("-->%s %lld %s\n", x, mem_idx, dectohex(mem_idx));
			char ch = '\0';
			if(l_idx != -1) ch = line[l_idx-1];
			//char*t = get();
			// if(t != NULL) { 
			// 	//dprint(t);
			// 	printf("Invalid Command: %d\n", N); return 0;
			//  }
			sym_table[hash(x)] = mem_idx;
			fprintf(fp2,"%s  %lld  %s\n", x, hash(x), dectohex(mem_idx));
			goto restart;

			line = NULL;
			free(x); l_idx = 0;
			continue;
		}

		//instruction----------------------------
		char *o = NULL;
		
		o = get(); // 1st operand
		char* o1 = copy(o); // 1st operand backup

		if(o == NULL) // implied addressing eg, RLC, RAR
		{
			mem_idx += 1;
			free(x); free(o); line = NULL; l_idx = 0; continue; 
		}

		char* y = copy(x); // copy instruction


		y = add(y, o); 
		if(op_table[hash(y)] != NULL) // 1 operand  or imediate addressing
		{
			o = get(); // 2nd operand

			if(o == NULL) // 1 operand (register) eg INC A
			{
				mem_idx += 1;
			}
			else if(is_data(o)) // imediate addressing with data eg MVI A,20
			{
				mem_idx += 2;
			}
			else if(is_mem(o)) // imediate addressing with address eg LXI H 2050
			{
				mem_idx += 3;
			}
			else 
			{
				printf("Invalid Command: %d\n", N); return 0;
			}

			o = get();
			if(o != NULL) { printf("Extra Characters on line: %d\n", N); return 0; }

			free(x); free(y); free(o); line = NULL; l_idx = 0; continue; 
		}

		o = get(); // 2nd operand

		if(o == NULL) // 1st operand = label (jmp loop1) or memory (lda 2000) or data (ani ff)
		{
			if(is_data(o1)) // ani ff
			{
				mem_idx += 2;
			}
			else if(is_mem(o1)) // lda 2000
			{
				mem_idx += 3;
			}
			else // label
			{
				mem_idx += 3;
			}
		}
		else if(is_mem_or_data(o)) // imediate adressing but command not in optab
		{
			printf("Invalid Command: %d\n", N); return 0;
		}
		else
		{
			y = add(y,o);
			//dprint(y);
			if(op_table[hash(y)] != NULL) // double operand eg MOV A,B
			{
				mem_idx += 1;
			}
			else 
			{
				printf("Invalid Command: %d\n", N); return 0;
			}
			
		}

		free(o); 
		o = get();
		if(o != NULL) { printf("Extra Characters on line: %d\n", N); return 0; }


		line = NULL; l_idx = 0;
		free(o); free(x); free(y); free(o1);

	}

	fclose(fp3);

	//return 0;
	//printf("\n\n--------------------------\n\n");

	//pass 2
	fclose(fp);
	fp = fopen("intermediate_file.txt", "r");
	N = 1; l_idx = 0; line = NULL; mem_idx = 8192;
	// while(N <= P)
	while(getline1(&line, &len, fp) != -1)
	{
		printf("%d  ", mem_idx);
		dprint(line);

		char* x; 
		x = get(); // mem_idx

		restart2:
		x = get(); // first word of instruction

		if(x == NULL) 
		{ free(x); line = NULL; l_idx = 0; N++; continue; }
		
		//label----------------------------------
		if(op_table[hash(x)] == NULL) 
		{
			// char ch = '\0';
			// if(l_idx != -1) ch = line[l_idx-1];
			// char*t = get();
			// if(t != NULL || ch != ':') { printf("Extra Characters on line: %d\n", N); return 0; }
			// sym_table[hash(x)] = mem_idx;
			goto restart2;

			line = NULL;
			free(x); l_idx = 0;
			N++; continue;
		}

		//instruction----------------------------
		char *o = NULL,*o1;



		o = get(); // 1st operand
		o1 = copy(o); // 1st operand backup

		if(o == NULL) // implied addressing eg, RLC, RAR
		{
			mem[mem_idx] = op_table[hash(x)];
			mem_idx += 1;
			//free(x); free(o); 
			line = NULL; l_idx = 0;
			N++; continue; 
		}

		char* y = copy(x); // copy instruction

		y = add(y, o); 
		if(op_table[hash(y)] != NULL) // 1 operand  or imediate addressing
		{

			o = get(); // 2nd operand

			if(o == NULL) // 1 operand (register) eg INC A
			{
				mem[mem_idx] = op_table[hash(y)];
				mem_idx += 1;
			}
			else if(is_data(o)) // imediate addressing with data eg MVI A,20
			{
				mem[mem_idx] = op_table[hash(y)];
				mem[mem_idx+1] = (char*)malloc(4*sizeof(char));
				mem[mem_idx+1][0] = o[0]; mem[mem_idx+1][1] = o[1];  mem[mem_idx+1][2] = '\0'; 
				mem_idx += 2;
			}
			else if(is_mem(o)) // imediate addressing with address eg LXI H 2050
			{
				mem[mem_idx] = op_table[hash(y)];
				mem[mem_idx+1] = (char*)malloc(4*sizeof(char));
				mem[mem_idx+2] = (char*)malloc(4*sizeof(char));

				mem[mem_idx+1][0] = o[2]; mem[mem_idx+1][1] = o[3];  mem[mem_idx+1][2] = '\0';
				mem[mem_idx+2][0] = o[0]; mem[mem_idx+2][1] = o[1];  mem[mem_idx+2][2] = '\0';
				mem_idx += 3;
			}
			else 
			{
				printf("Invalid Command: %d\n", N); return 0;
			}

			o = get();
			if(o != NULL) { printf("Extra Characters on line: %d\n", N); return 0; }

			free(x); free(y); free(o); free(o1); line = NULL; l_idx = 0; N++; continue; 
		}

		o = get(); // 2nd operand

		if(o == NULL) // 1st operand = label (jmp loop1) or memory (lda 2000) or data (ani ff)
		{
			if(is_data(o1)) // ani ff
			{
				mem[mem_idx] = op_table[hash(x)];
				mem[mem_idx+1] = (char*)malloc(4*sizeof(char));
				mem[mem_idx+1][0] = o1[0]; mem[mem_idx+1][1] = o1[1];  mem[mem_idx+1][2] = '\0'; 
				mem_idx += 2;
			}
			else if(is_mem(o1)) // lda 2000
			{
				mem[mem_idx] = op_table[hash(x)];
				mem[mem_idx+1] = (char*)malloc(4*sizeof(char));
				mem[mem_idx+2] = (char*)malloc(4*sizeof(char));

				mem[mem_idx+1][0] = o1[2]; mem[mem_idx+1][1] = o1[3];  mem[mem_idx+1][2] = '\0';
				mem[mem_idx+2][0] = o1[0]; mem[mem_idx+2][1] = o1[1];  mem[mem_idx+2][2] = '\0';

				mem_idx += 3;
			}
			else // label
			{
				int z = sym_table[hash(o1)];
				if(z == -1)
				{
					printf("Undefined Label: %d\n", N);
					return 0;
				}
				char* t = conv(z);

				mem[mem_idx] = op_table[hash(x)];
				mem[mem_idx+1] = (char*)malloc(4*sizeof(char));
				mem[mem_idx+2] = (char*)malloc(4*sizeof(char));

				mem[mem_idx+1][0] = t[2]; mem[mem_idx+1][1] = t[3];  mem[mem_idx+1][2] = '\0';
				mem[mem_idx+2][0] = t[0]; mem[mem_idx+2][1] = t[1];  mem[mem_idx+2][2] = '\0';

				mem_idx += 3;
			}
		}
		else if(is_mem_or_data(o)) // imediate adressing but command not in optab
		{
			printf("Invalid Command: %d\n", N); return 0;
		}
		else
		{
			y = add(y,o);
			if(op_table[hash(y)] != NULL) // double operand eg MOV A,B
			{
				mem[mem_idx] = op_table[hash(y)];
				mem_idx += 1;
			}
			else 
			{
				printf("Invalid Command: %d\n", N); return 0;
			}
			
		}

		free(o);
		o = get();
		if(o != NULL) { printf("Extra Characters on line: %d\n", N); return 0; }


		line = NULL; l_idx = 0;
		free(o); free(x); free(y); N++; free(o1);

	}

	int l = mem_idx; mem_len = mem_idx;

	//return 0;

	fp = fopen("object_code.txt","w");
	for(int i = 8192; i < l; i++)
	{
		printf("%s: %s\n", conv(i), mem[i]);
		fprintf(fp, "%s\n", mem[i]);
	}

	listing();

	simu();
	check();

	fclose(fp);
	printf("\n");
	return 0;
}
