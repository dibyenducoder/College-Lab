
char* MDT[1000000];
int MNT[1000000];
int MDT_idx;

void macro()
{

	for(int i = 0; i < 1000000; i++)
	{
		MDT[i] = NULL; MNT[i] = -1;
	}


	// Macro Definition
	MDT_idx = 0;
	N = 1; line = NULL; l_idx = 0;
	while(N <= P)
	{
		line = F[N-1]; N++; l_idx = 0;// get next line
		
		//printf("rrrrr\n");

		//dprint(line);

		char* x = get();
		char* y = get();

	
		if(is(y,"macro"))
		{
			//printf("%s   %s", );
			MNT[hash(x)] = MDT_idx;
			line = F[N-1]; N++; l_idx = 0;// get next line
			while(1)
			{
				MDT[MDT_idx++] = line;
				line = F[N-1]; N++; l_idx = 0;// get next line
				char* x = get();

				if(is(x, "mend") || N > P)
				{
					MDT[MDT_idx++] = "$\0";
					break;
				}

			}
		}

	}

	printf("ttttt\n");


	//Macro Expansion
	N = 1; int real_N = 0; line = NULL; l_idx = 0;
	while(N <= P)
	{
		line = F[N-1]; N++; l_idx = 0;// get next line
		char* x = get();
		char* y = get();

		dprint(line);
		
		if(is(y,"macro")) // skip macro definitions
		{
			while(1)
			{
				line = F[N-1]; N++; l_idx = 0;// get next line
				char* x = get();

				if(is(x, "mend") || N > P)
				{
					break;
				}
			}

		}
		else if(MNT[hash(x)] != -1) // expand macro calls
		{

			int z = MNT[hash(x)];

			while(1)
			{
				FF[real_N++] = MDT[z];
				z++;
				if(is(MDT[z],"$"))
				{
					break;
				}

			}
		}
		else if(MNT[hash(y)] != -1) // expand macro calls (macro calll after label)
		{
			x = add(x,": \n");
			FF[real_N++] = x;

			int z = MNT[hash(y)];

			while(1)
			{
				FF[real_N++] = MDT[z];
				z++;
				if(is(MDT[z],"$"))
				{
					break;
				}

			}
		}
		else
		FF[real_N++] = line;

	}

	P = real_N;
	for(int i=0; i < real_N; i++)
	{
		F[i] = FF[i];
	}

}

char* list[10];
int list_idx; 

int listing()
{

	printf("\n\n----------------\n");
	N = 1; l_idx = 0; line = NULL; mem_idx = 8192;
	while(N <= P)
	{
		line = F[N-1];
		//printf("%d  ", mem_idx);
		//dprint(line);

		list_idx = 0;
		char cc; getchar();

		printf("\n%lld %s", N, line);

		int j=0;
		while(line[j] != '\0') j++;
		if(line[j-1] != '\n') printf("\n");

		char* x;

		restart2:
		x = get();

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
			//mem[mem_idx] = op_table[hash(x)];
			printf("%s: %s\n", dectohex(mem_idx), op_table[hash(x)]);
			mem_idx += 1;
			//free(x); free(o); line = NULL; l_idx = 0;
			N++; continue; 
		}

		char* y = copy(x); // copy instruction

		y = add(y, o); 
		if(op_table[hash(y)] != NULL) // 1 operand  or imediate addressing
		{

			o = get(); // 2nd operand

			if(o == NULL) // 1 operand (register) eg INC A
			{
				//mem[mem_idx] = op_table[hash(y)];
				printf("%s: %s\n", dectohex(mem_idx), op_table[hash(y)]);
				mem_idx += 1;
			}
			else if(is_data(o)) // imediate addressing with data eg MVI A,20
			{
				//mem[mem_idx] = op_table[hash(y)];
				printf("%s: %s\n", dectohex(mem_idx), op_table[hash(y)]);
				//mem[mem_idx+1] = (char*)malloc(4*sizeof(char));
				//mem[mem_idx+1][0] = o[0]; mem[mem_idx+1][1] = o[1];  mem[mem_idx+1][2] = '\0';
				printf("%s: %s\n", dectohex(mem_idx+1), o);
				mem_idx += 2;
			}
			else if(is_mem(o)) // imediate addressing with address eg LXI H 2050
			{
				//mem[mem_idx] = op_table[hash(y)];
				printf("%s: %s\n", dectohex(mem_idx), op_table[hash(y)]);
				//mem[mem_idx+1] = (char*)malloc(4*sizeof(char));
				//mem[mem_idx+2] = (char*)malloc(4*sizeof(char));

				//mem[mem_idx+1][0] = o[2]; mem[mem_idx+1][1] = o[3];  mem[mem_idx+1][2] = '\0';
				//mem[mem_idx+2][0] = o[0]; mem[mem_idx+2][1] = o[1];  mem[mem_idx+2][2] = '\0';

				printf("%s: %c%c\n", dectohex(mem_idx+1), o[2],o[3]);
				printf("%s: %c%c\n", dectohex(mem_idx+2), o[0],o[1]);

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
				//mem[mem_idx] = op_table[hash(x)];
				printf("%s: %s\n", dectohex(mem_idx), op_table[hash(x)]);
				//mem[mem_idx+1] = (char*)malloc(4*sizeof(char));
				//mem[mem_idx+1][0] = o1[0]; mem[mem_idx+1][1] = o1[1];  mem[mem_idx+1][2] = '\0'; 
				printf("%s: %s\n", dectohex(mem_idx+1), o1);
				mem_idx += 2;
			}
			else if(is_mem(o1)) // lda 2000
			{
				//mem[mem_idx] = op_table[hash(x)];
				printf("%s: %s\n", dectohex(mem_idx), op_table[hash(x)]);
				//mem[mem_idx+1] = (char*)malloc(4*sizeof(char));
				//mem[mem_idx+2] = (char*)malloc(4*sizeof(char));

				//mem[mem_idx+1][0] = o1[2]; mem[mem_idx+1][1] = o1[3];  mem[mem_idx+1][2] = '\0';
				//mem[mem_idx+2][0] = o1[0]; mem[mem_idx+2][1] = o1[1];  mem[mem_idx+2][2] = '\0';

				printf("%s: %c%c\n", dectohex(mem_idx+1), o1[2],o1[3]);
				printf("%s: %c%c\n", dectohex(mem_idx+2), o1[0],o1[1]);
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

				//mem[mem_idx] = op_table[hash(x)];
				printf("%s: %s\n", dectohex(mem_idx), op_table[hash(x)]);
				//mem[mem_idx+1] = (char*)malloc(4*sizeof(char));
				//mem[mem_idx+2] = (char*)malloc(4*sizeof(char));

				//mem[mem_idx+1][0] = t[2]; mem[mem_idx+1][1] = t[3];  mem[mem_idx+1][2] = '\0';
				//mem[mem_idx+2][0] = t[0]; mem[mem_idx+2][1] = t[1];  mem[mem_idx+2][2] = '\0';
				printf("%s: %c%c\n", dectohex(mem_idx+1), t[2],t[3]);
				printf("%s: %c%c\n", dectohex(mem_idx+2), t[0],t[1]);

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
				//mem[mem_idx] = op_table[hash(y)];
				printf("%s: %s\n", dectohex(mem_idx), op_table[hash(y)]);
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
}

void reduce()
{
	printf("\nREDUCE------------------------\n");
	N = 1; line = NULL; l_idx = 0;
	int real_N = 0;
	while(N <= P)
	{
		line = F[N-1]; N++; l_idx = 0;

		dprint(line);

		char* x = get(); 

		//dprint(x);

		if(x == NULL) continue;

		int i = 0;
		while(1)
		{
			if(line[i] == '\0')
			{
				break;
			}
			if(line[i] == ';')
			{
				line[i] = '\n'; line[i+1] = '\0';  break;
			}
			i++;
		}

		FF[real_N++] = line;

	}

	for(int i=0;i<real_N;i++)
	{
		F[i] = FF[i];
	}

	P = real_N;

	line = F[P-1];

	int i = 0;
	while(line[i] != '\0') i++;
	if(line[i-1] == '\n') line[i-1] = '\0';
	

	printf("\nREDUCE------------------------\n");
}
/*
aaa 	macro
		inr e
		inr a
		inr b
		inr c
		mend

		mvi d,05
		mvi e,00

loop1: 	aaa
		dcr d
		jnz loop1

		hlt
		*/