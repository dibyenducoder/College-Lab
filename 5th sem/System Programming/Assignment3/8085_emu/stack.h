
// stack start from 1000h mem address

int SP,BP;

void push(int x)
{
	if(SP > BP + 1) { printf("\nSP > BP + 1\n"); exit(1); }
	char* t = dectohex(x);


	SP--; free(mem[SP]);
	mem[SP] = (char*)malloc(5*sizeof(char));
	mem[SP][0] = t[0]; mem[SP][1] = t[1]; mem[SP][2] = '\0';


	SP--; free(mem[SP]);
	mem[SP] = (char*)malloc(5*sizeof(char));
	mem[SP][0] = t[2]; mem[SP][1] = t[3]; mem[SP][2] = '\0';


}

int pop()
{
	//printf("\npop pop pop\n");

	if(SP > BP + 1) { printf("\nSP > BP + 1\n"); exit(1); }
	if(SP == BP + 1) // empty
	{ printf("\nStack Empty\n"); return 0; }

	char* t1 = copy(mem[SP]);
	char* t2 = copy(mem[SP + 1]);

	char* t = add(t2, t1);
	int x = hextodec(t);
	
	free(t);
	free(mem[SP]);
	free(mem[SP + 1]);

	//printf("%s %s\n", mem[SP], mem[SP+1]);

	SP += 2;
	return x;
}