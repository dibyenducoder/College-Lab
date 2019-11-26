
int A,B,C,D,E,H,L; // registers
int Carry, Zero, Sign, Parity, AC; // flags

int get_M()
{
	char *h = dectohex(H);
	char* l = dectohex(L);
	
	h = add(h, l);
	int j = hextodec(h);

	free(h);
	return hextodec(mem[j]);
}

void set_M(int x)
{
	char *h = dectohex(H);
	char* l = dectohex(L);
	
	h = add(h, l);
	int j = hextodec(h);

	free(h);
	mem[j] = dectohex(x);
}

void set_parity()
{
	int a = A; int x = 0;
	while(a)
	{
		x += (a&1);
		a = (a >> 1);
	}
	Parity = 1 - (x%2);
	//if(A == 0) Zero = 1;
}

int get_flag_register()
{
	int x = (Sign << 7) + (Zero << 6) + (AC << 4) + (Parity << 2) + (Carry);
	return x;
}

void set_flag_register(int x)
{
	Sign = (x & (1<<7)) ? 1 : 0;
	Zero = (x & (1<<6)) ? 1 : 0;
	AC = (x & (1<<4)) ? 1 : 0;
	Parity = (x & (1<<2)) ? 1 : 0;
	Carry = (x & 1) ? 1 : 0;
}

int Radd(int a, int b) // register addition
{
	int ta = a; int tb = b;

	a = (a&15); // LS
	b = (b&15);

	int c = a+b;
	if(c > 15) AC = 1;

	a = ta; b = tb;
	c = a + b;
	if(c > 255) C = 1;

	Sign = 0;
	c = (c&255); if(c == 0) Zero = 1; else Zero = 0;
	set_parity();
	return c;
}

int RaddC(int a, int b) // register addition with carry
{
	int ta = a; int tb = b;

	a = (a&15); // LS
	b = (b&15);

	int c = a+b+Carry;
	if(c > 15) AC = 1;

	a = ta; b = tb;
	c = a + b;
	if(c > 255) C = 1;

	Sign = 0;
	c = (c&255); if(c == 0) Zero = 1; else Zero = 0;
	set_parity();
	return c;
}

int sub(int a,int b)
{
	int c = a - b;
	if(c < 0) // store 2'c complement
	{
		c = -c;
		c = (c^255);
		c = c + 1;
		Sign = 1;
		Carry = 1;
	}
	else
	{
		Sign = 0; Carry = 0;
	}
	if(c == 0) Zero = 1; else Zero = 0;
	set_parity();
	return c;
}

int subB(int a,int b)
{
	int c = a - b - Carry;
	if(c < 0) // store 2'c complement
	{
		c = -c;
		c = (c^255);
		c = c + 1;
		Sign = 1;
		Carry = 1;
	}
	else
	{
		Sign = 0; Carry = 0;
	}
	if(c == 0) Zero = 1; else Zero = 0;
	set_parity();
	return c;
}

void DAA() // Decimal Adjust Accumulator
{
	int a = A;

	int ls = (A&15); 
	if(ls > 9 || AC == 1)
	{
		ls -= 10;
		A = Radd(A, 16);
	}
	int ms = (A&240); ms = (ms >> 4);
	if(ms > 9 || Carry == 1)
	{
		ms -= 10;
		Carry = 1;
	}
	set_parity();
	A = (ms << 4) + ls;
}


void DAD(int a,int b) // double addition
{
	int d = H; int e = L;

	e = Radd(e,b);
	d = RaddC(d,a);

	H = d; L = e;
}

int R_AND(int a,int b)
{
	int c = (a & b);
	if(c == 0) Zero = 1; else Zero = 0;
	set_parity();
	return c;
}

int R_OR(int a,int b)
{
	int c = (a | b);
	if(c == 0) Zero = 1; else Zero = 0;
	set_parity();
	return c;
}

int R_XOR(int a,int b)
{
	int c = (a ^ b);
	if(c == 0) Zero = 1; else Zero = 0;
	set_parity();
	return c;
}


void simu(){
	//init
	A = B = C = D = E = H = L = 0;
	Carry = Zero = Sign = Parity = AC = 0;
	BP = hextodec("1000");
	SP = BP + 1;

	int itr = 0;

	int pc = 8192; // 2000h
	while(1)
	{
		itr++;
		if(itr > 1000)
		{
			printf("\n\nitr > 1000\n\n");
			break;
		}
		char* I = mem[pc++];

		if(I == NULL)
		{
			printf("\n\nNo Halt\n\n");
			break;
		}

		if(is(I, "CE")) // ACI
		{	
			char* o = mem[pc++]; // operand
			A = RaddC(A, hextodec(o));
		}
		else if(is(I, "8F")) // ADC A
		{
			A = RaddC(A, A);
		}
		else if(is(I, "88")) // ADC B
		{
			A = RaddC(A, B);
		}
		else if(is(I, "89")) // ADC C
		{
			A = RaddC(A, C);
		}
		else if(is(I, "8A")) // ADC D
		{
			A = RaddC(A, D);
		}
		else if(is(I, "8B")) // ADC E
		{
			A = RaddC(A, E);
		}
		else if(is(I, "8C")) // ADC H
		{
			A = RaddC(A, H);
		}
		else if(is(I, "8D")) // ADC L
		{
			A = RaddC(A, L);
		}
		else if(is(I, "8E")) // ADC M
		{
			A = RaddC(A, get_M());
		}
		else if(is(I, "87")) // ADD A
		{
			A = Radd(A, A);
		}
		else if(is(I, "80")) // ADD B
		{
			A = Radd(A, B);
		}
		else if(is(I, "81")) // ADD C
		{
			A = Radd(A, C);
		}
		else if(is(I, "82")) // ADD D
		{
			A = Radd(A, D);
		}
		else if(is(I, "83")) // ADD E
		{
			A = Radd(A, E);
		}
		else if(is(I, "84")) // ADD H
		{
			A = Radd(A, H);
		}
		else if(is(I, "85")) // ADD L
		{
			A = Radd(A, L);
		}
		else if(is(I, "86")) // ADD M
		{
			A = Radd(A, get_M());
		}
		else if(is(I, "C6")) // ADI
		{
			char* o = mem[pc++]; // operand
			A = Radd(A, hextodec(o));
		}
		else if(is(I, "A7")) // ANA A
		{
			A = R_AND(A, A);
		}
		else if(is(I, "A0")) // ANA B
		{
			A = R_AND(A, B);
		}
		else if(is(I, "A1")) // ANA C
		{
			A = R_AND(A, C);
		}
		else if(is(I, "A2")) // ANA D
		{
			A = R_AND(A, D);
		}
		else if(is(I, "A3")) // ANA E
		{
			A = R_AND(A, E);
		}
		else if(is(I, "A4")) // ANA H
		{
			A = R_AND(A, H);
		}
		else if(is(I, "A5")) // ANA L
		{
			A = R_AND(A, L);
		}
		else if(is(I, "A6")) // ANA M
		{
			A = R_AND(A, get_M());
		}
		else if(is(I, "E6")) // ANI
		{
			char* o = mem[pc++]; // operand
			A = R_AND(A, hextodec(o));
		}
		else if(is(I, "CD")) // CALL
		{
			char* o1 = copy(mem[pc++]);
			char* o2 = copy(mem[pc++]);
			char* o = add(o2,o1);
			push(pc);
			pc = hextodec(o);
			free(o);
		}
		else if(is(I, "DC")) // CC (call if carry)
		{
			if(Carry == 0)
			{
				pc++; pc++;
				continue;
			}
			char* o1 = copy(mem[pc++]);
			char* o2 = copy(mem[pc++]);
			char* o = add(o2,o1);
			push(pc);
			pc = hextodec(o);
			free(o);
		}
		else if(is(I, "FC")) // CM (call if minus)
		{
			if(Sign == 0)
			{
				pc++; pc++;
				continue;
			}
			char* o1 = copy(mem[pc++]);
			char* o2 = copy(mem[pc++]);
			char* o = add(o2,o1);
			push(pc);
			pc = hextodec(o);
			free(o);
		}
		else if(is(I, "2F")) // CMA
		{
			A = A ^ 255;
		}
		else if(is(I, "3F")) // CMC
		{
			Carry = 1 - Carry;
		}
		else if(is(I, "BF")) // CMP A
		{
			if(A < A)
			{
				Carry = 1; Zero = 0;
			}
			else if(A == A)
			{
				Carry = 0; Zero = 1;
			}
			else
			{
				Carry = 0; Zero = 0;
			}
		}
		else if(is(I, "B8")) // CMP B
		{
			if(A < B)
			{
				Carry = 1; Zero = 0;
			}
			else if(A == B)
			{
				Carry = 0; Zero = 1;
			}
			else
			{
				Carry = 0; Zero = 0;
			}
		}
		else if(is(I, "B9")) // CMP C
		{
			if(A < C)
			{
				Carry = 1; Zero = 0;
			}
			else if(A == C)
			{
				Carry = 0; Zero = 1;
			}
			else
			{
				Carry = 0; Zero = 0; 	
			}
		}
		else if(is(I, "BA")) // CMP D
		{
			if(A < D)
			{
				Carry = 1; Zero = 0;
			}
			else if(A == D)
			{
				Carry = 0; Zero = 1;
			}
			else
			{
				Carry = 0; Zero = 0;
			}
		}
		else if(is(I, "BB")) // CMP E
		{
			if(A < E)
			{
				Carry = 1; Zero = 0;
			}
			else if(A == E)
			{
				Carry = 0; Zero = 1;
			}
			else
			{
				Carry = 0; Zero = 0;
			}
		}
		else if(is(I, "BC")) // CMP H
		{
			if(A < H)
			{
				Carry = 1; Zero = 0;
			}
			else if(A == H)
			{
				Carry = 0; Zero = 1;
			}
			else
			{
				Carry = 0; Zero = 0;
			}
		}
		else if(is(I, "BD")) // CMP L
		{
			if(A < L)
			{
				Carry = 1; Zero = 0;
			}
			else if(A == L)
			{
				Carry = 0; Zero = 1;
			}
			else
			{
				Carry = 0; Zero = 0;
			}
		}
		else if(is(I, "BE")) // CMP M
		{
			if(A < get_M())
			{
				Carry = 1; Zero = 0;
			}
			else if(A == get_M())
			{
				Carry = 0; Zero = 1;
			}
			else
			{
				Carry = 0; Zero = 0;
			}
		}
		else if(is(I, "D4")) // CNC (call if no carry)
		{
			if(Carry == 1)
			{
				pc++; pc++;
				continue;
			}
			char* o1 = copy(mem[pc++]);
			char* o2 = copy(mem[pc++]);
			char* o = add(o2,o1);
			push(pc);
			pc = hextodec(o);
			free(o);
		}
		else if(is(I, "C4")) // CNZ (call if not zero)
		{
			if(Zero == 1)
			{
				pc++; pc++;
				continue;
			}
			char* o1 = copy(mem[pc++]);
			char* o2 = copy(mem[pc++]);
			char* o = add(o2,o1);
			push(pc);
			pc = hextodec(o);
			free(o);
		}
		else if(is(I, "F4")) // CP (call if positive)
		{
			if(Sign == 1 || Zero == 1)
			{
				pc++; pc++;
				continue;
			}
			char* o1 = copy(mem[pc++]);
			char* o2 = copy(mem[pc++]);
			char* o = add(o2,o1);
			push(pc);
			pc = hextodec(o);
			free(o);
		}
		else if(is(I, "EC")) // CPE (call if parity even)
		{
			if(Parity == 0)
			{
				pc++; pc++;
				continue;
			}
			char* o1 = copy(mem[pc++]);
			char* o2 = copy(mem[pc++]);
			char* o = add(o2,o1);
			push(pc);
			pc = hextodec(o);
			free(o);
		}
		else if(is(I, "FE")) // CPI (compare imediate)
		{
			char* t = mem[pc++];
			int x = hextodec(t);
			if(A < x)
			{
				Carry = 1; Zero = 0;
			}
			else if(A == x)
			{
				Carry = 0; Zero = 1;
			}
			else
			{
				Carry = 0; Zero = 0;
			}
		}
		else if(is(I, "E4")) // CPO (call if parity odd)
		{
			if(Parity == 1)
			{
				pc++; pc++;
				continue;
			}
			char* o1 = copy(mem[pc++]);
			char* o2 = copy(mem[pc++]);
			char* o = add(o2,o1);
			push(pc);
			pc = hextodec(o);
			free(o);
		}
		else if(is(I, "CC")) // CZ (call if zero)
		{
			if(Zero == 0)
			{
				pc++; pc++;
				continue;
			}
			char* o1 = copy(mem[pc++]);
			char* o2 = copy(mem[pc++]);
			char* o = add(o2,o1);
			push(pc);
			pc = hextodec(o);
			free(o);
		}
		else if(is(I, "27")) // DAA  
		{
			DAA();
		}
		else if(is(I, "09")) // DAD B  
		{
			DAD(B, C);
		}
		else if(is(I, "19")) // DAD D  
		{
			DAD(D, E);
		}
		else if(is(I, "29")) // DAD H  
		{
			DAD(H, L);
		}
		else if(is(I, "39")) // DAD SP  
		{
			int sph = (SP & 65280) >> 8;
			int spl = (SP & 255);
			DAD(sph, spl);
		}
		else if(is(I, "3D")) // DCR A  
		{
			A = sub(A,1);
		}
		else if(is(I, "05")) // DCR B  
		{
			B = sub(B,1);
		}
		else if(is(I, "0D")) // DCR C  
		{
			C = sub(C,1);
		}
		else if(is(I, "15")) // DCR D  
		{
			D = sub(D,1);
		}
		else if(is(I, "1D")) // DCR E  
		{
			E = sub(E,1);
		}
		else if(is(I, "25")) // DCR H  
		{
			H = sub(H,1);
		}
		else if(is(I, "2D")) // DCR L  
		{
			L = sub(L,1);
		}
		else if(is(I, "35")) // DCR M  
		{
			int x = get_M();
			x = sub(x, 1);
			set_M(x);
		}
		else if(is(I, "0B")) // DCX B  
		{
			if(C == 0)
			{
				C = 255;
				B = sub(B,1);
			}
			else
			{
				C = sub(C,1);
			}
		}
		else if(is(I, "1B")) // DCX D  
		{
			if(E == 0)
			{
				E = 255;
				D = sub(D,1);
			}
			else
			{
				E = sub(E,1);
			}
		}
		else if(is(I, "2B")) // DCX H  
		{
			if(L == 0)
			{
				L = 255;
				H = sub(H,1);
			}
			else
			{
				L = sub(L,1);
			}
		}
		else if(is(I, "3B")) // DCX SP  
		{
			SP--;
		}
		else if(is(I, "F3")) // DI  
		{
			// Disable Interrupt
		}
		else if(is(I, "FB")) // EI  
		{
			// Enable Interrupt
		}
		else if(is(I, "76")) // HLT  
		{
			break;
		}
		// else if(is(I, "address")) // IN Port 
		// {
		
		// }
		else if(is(I, "3C")) // INR A  
		{
			A = Radd(A,1);
		}
		else if(is(I, "04")) // INR B  
		{
			B = Radd(B,1);
		}
		else if(is(I, "0C")) // INR C  
		{
			C = Radd(C,1);
		}
		else if(is(I, "14")) // INR D  
		{
			D = Radd(D,1);
		}
		else if(is(I, "1C")) // INR E  
		{
			E = Radd(E,1);
		}
		else if(is(I, "24")) // INR H  
		{
			H = Radd(H,1);
		}
		else if(is(I, "2C")) // INR L  
		{
			L = Radd(L,1);
		}
		else if(is(I, "34")) // INR M  
		{
			int x = get_M();
			x = Radd(x,1);
			set_M(x);
		}
		else if(is(I, "03")) // INX B  
		{
			if(C == 255)
			{
				C = 0;
				B = Radd(B,1);
			}
			else
			{
				C = Radd(C,1);
			}
		}
		else if(is(I, "13")) // INX D  
		{
			if(E == 255)
			{
				E = 0;
				D = Radd(D,1);
			}
			else
			{
				E = Radd(E,1);
			}
		}
		else if(is(I, "23")) // INX H  
		{
			if(L == 255)
			{
				L = 0;
				H = Radd(H,1);
			}
			else
			{
				L = Radd(L,1);
			}
		}
		else if(is(I, "33")) // INX SP  
		{
			SP++;
		}
		else if(is(I, "DA")) // JC  
		{
			if(Carry == 0)
			{
				pc++; pc++;
				continue;
			}
			char* o1 = copy(mem[pc++]);
			char* o2 = copy(mem[pc++]);
			char* o = add(o2,o1);
			//push(pc);
			pc = hextodec(o);
			free(o);
		}
		else if(is(I, "FA")) // JM  
		{
			if(Sign == 0)
			{
				pc++; pc++;
				continue;
			}
			char* o1 = copy(mem[pc++]);
			char* o2 = copy(mem[pc++]);
			char* o = add(o2,o1);
			//push(pc);
			pc = hextodec(o);
			free(o);
		
		}
		else if(is(I, "C3")) // JMP  
		{
			char* o1 = copy(mem[pc++]);
			char* o2 = copy(mem[pc++]);
			char* o = add(o2,o1);
			//push(pc);
			pc = hextodec(o);
			free(o);
		}
		else if(is(I, "D2")) // JNC  
		{
			if(Carry == 1)
			{
				pc++; pc++;
				continue;
			}
			char* o1 = copy(mem[pc++]);
			char* o2 = copy(mem[pc++]);
			char* o = add(o2,o1);
			//push(pc);
			pc = hextodec(o);
			free(o);
		}
		else if(is(I, "C2")) // JNZ  
		{
			if(Zero == 1)
			{
				pc++; pc++;
				continue;
			}
			char* o1 = copy(mem[pc++]);
			char* o2 = copy(mem[pc++]);
			char* o = add(o2,o1);
			//push(pc);
			pc = hextodec(o);
			free(o);
		}
		else if(is(I, "F2")) // JP  
		{
			if(Sign == 1 || Zero == 1)
			{
				pc++; pc++;
				continue;
			}
			char* o1 = copy(mem[pc++]);
			char* o2 = copy(mem[pc++]);
			char* o = add(o2,o1);
			//push(pc);
			pc = hextodec(o);
			free(o);
		}
		else if(is(I, "EA")) // JPE  
		{
			if(Parity == 0)
			{
				pc++; pc++;
				continue;
			}
			char* o1 = copy(mem[pc++]);
			char* o2 = copy(mem[pc++]);
			char* o = add(o2,o1);
			//push(pc);
			pc = hextodec(o);
			free(o);
		}
		else if(is(I, "E2")) // JPO  
		{
			if(Parity == 1)
			{
				pc++; pc++;
				continue;
			}
			char* o1 = copy(mem[pc++]);
			char* o2 = copy(mem[pc++]);
			char* o = add(o2,o1);
			//push(pc);
			pc = hextodec(o);
			free(o);
		}
		else if(is(I, "CA")) // JZ  
		{
			if(Zero == 0)
			{
				pc++; pc++;
				continue;
			}
			char* o1 = copy(mem[pc++]);
			char* o2 = copy(mem[pc++]);
			char* o = add(o2,o1);
			//push(pc);
			pc = hextodec(o);
			free(o);
		}
		else if(is(I, "3A")) // LDA   
		{
			char* o1 = copy(mem[pc++]);
			char* o2 = copy(mem[pc++]);
			char* o = add(o2,o1);
			int x = hextodec(o);
			A = hextodec(mem[x]);
			//set_parity();
			free(o);
		}
		else if(is(I, "0A")) // LDAX B  
		{
			char* b = dectohex(B);
			char* c = dectohex(C);

			char* t = add(b,c);
			int x = hextodec(t);
			A = hextodec(mem[x]);
			//set_parity();
			free(t);

		}
		else if(is(I, "1A")) // LDAX D  
		{
			char* d = dectohex(D);
			char* e = dectohex(E);

			char* t = add(d,e);
			int x = hextodec(t);
			A = hextodec(mem[x]);
			//set_parity();
			free(t);
		}
		else if(is(I, "2A")) // LHLD   
		{
			char* o1 = copy(mem[pc++]);
			char* o2 = copy(mem[pc++]);
			char* o = add(o2,o1);
			int x = hextodec(o);
			L = hextodec(mem[x]);
			x++;
			H = hextodec(mem[x]);
			free(o);
		}
		else if(is(I, "01")) // LXI B  
		{
			char* o1 = copy(mem[pc++]);
			char* o2 = copy(mem[pc++]);
			B = hextodec(o2);
			C = hextodec(o1);
			free(o1); free(o2);

		}
		else if(is(I, "11")) // LXI D  
		{
			char* o1 = copy(mem[pc++]);
			char* o2 = copy(mem[pc++]);
			D = hextodec(o2);
			E = hextodec(o1);
			free(o1); free(o2);
		}
		else if(is(I, "21")) // LXI H  
		{
			char* o1 = copy(mem[pc++]);
			char* o2 = copy(mem[pc++]);
			H = hextodec(o2);
			L = hextodec(o1);
			free(o1); free(o2);
		}
		else if(is(I, "31")) // LXI SP  
		{
			char* o1 = copy(mem[pc++]);
			char* o2 = copy(mem[pc++]);
			char* o = add(o2,o1);
			SP = hextodec(o);
			free(o);
		}
		else if(is(I, "7F")) // MOV A, A  
		{
			A=A;
		}
		else if(is(I, "78")) // MOV A, B  
		{
			A=B;
		}
		else if(is(I, "79")) // MOV A, C  
		{
			A=C;
		}
		else if(is(I, "7A")) // MOV A, D  
		{
			A=D;
		}
		else if(is(I, "7B")) // MOV A, E  
		{
			A=E;
		}
		else if(is(I, "7C")) // MOV A, H  
		{
			A=H;
		}
		else if(is(I, "7D")) // MOV A, L  
		{
			A=L;
		}
		else if(is(I, "7E")) // MOV A, M  
		{
			A=get_M();
		}
		else if(is(I, "47")) // MOV B, A  
		{
			B=A;
		}
		else if(is(I, "40")) // MOV B, B  
		{
			B=B;
		}
		else if(is(I, "41")) // MOV B, C  
		{
			B=C;
		}
		else if(is(I, "42")) // MOV B, D  
		{
			B=D;
		}
		else if(is(I, "43")) // MOV B, E  
		{
			B=E;
		}
		else if(is(I, "44")) // MOV B, H  
		{
			B=H;
		}
		else if(is(I, "45")) // MOV B, L  
		{
			B=L;
		}
		else if(is(I, "46")) // MOV B, M  
		{
			B=get_M();
		}
		else if(is(I, "4F")) // MOV C, A  
		{
			C=A;
		}
		else if(is(I, "48")) // MOV C, B  
		{
			C=B;
		}
		else if(is(I, "49")) // MOV C, C  
		{
			C=C;
		}
		else if(is(I, "4A")) // MOV C, D  
		{
			C=D;
		}
		else if(is(I, "4B")) // MOV C, E  
		{
			C=E;
		}
		else if(is(I, "4C")) // MOV C, H  
		{
			C=H;
		}
		else if(is(I, "4D")) // MOV C, L  
		{
			C=L;
		}
		else if(is(I, "4E")) // MOV C, M  
		{
			C=get_M();
		}
		else if(is(I, "57")) // MOV D, A  
		{
			D=A;
		}
		else if(is(I, "50")) // MOV D, B  
		{
			D=B;
		}
		else if(is(I, "51")) // MOV D, C  
		{
			D=C;
		}
		else if(is(I, "52")) // MOV D, D  
		{
			D=D;
		}
		else if(is(I, "53")) // MOV D, E  
		{
			D=E;
		}
		else if(is(I, "54")) // MOV D, H  
		{
			D=H;
		}
		else if(is(I, "55")) // MOV D, L  
		{
			D=L;
		}
		else if(is(I, "56")) // MOV D, M  
		{
			D=get_M();
		}
		else if(is(I, "5F")) // MOV E, A  
		{
			E=A;
		}
		else if(is(I, "58")) // MOV E, B  
		{
			E=B;
		}
		else if(is(I, "59")) // MOV E, C  
		{
			E=C;
		}
		else if(is(I, "5A")) // MOV E, D  
		{
			E=D;
		}
		else if(is(I, "5B")) // MOV E, E  
		{
			E=E;
		}
		else if(is(I, "5C")) // MOV E, H  
		{
			E=H;
		}
		else if(is(I, "5D")) // MOV E, L  
		{
			E=L;
		}
		else if(is(I, "5E")) // MOV E, M  
		{
			E=get_M();
		}
		else if(is(I, "67")) // MOV H, A  
		{
			H=A;
		}
		else if(is(I, "60")) // MOV H, B  
		{
			H=B;
		}
		else if(is(I, "61")) // MOV H, C  
		{
			H=C;
		}
		else if(is(I, "62")) // MOV H, D  
		{
			H=D;
		}
		else if(is(I, "63")) // MOV H, E  
		{
			H=E;
		}
		else if(is(I, "64")) // MOV H, H  
		{
			H=H;
		}
		else if(is(I, "65")) // MOV H, L  
		{
			H=L;
		}
		else if(is(I, "66")) // MOV H, M  
		{
			H=get_M();
		}
		else if(is(I, "6F")) // MOV L, A  
		{
			L=A;
		}
		else if(is(I, "68")) // MOV L, B  
		{
			L=B;
		}
		else if(is(I, "69")) // MOV L, C  
		{
			L=C;
		}
		else if(is(I, "6A")) // MOV L, D  
		{
			L=D;
		}
		else if(is(I, "6B")) // MOV L, E  
		{
			L=E;
		}
		else if(is(I, "6C")) // MOV L, H  
		{
			L=H;
		}
		else if(is(I, "6D")) // MOV L, L  
		{
			L=L;
		}
		else if(is(I, "6E")) // MOV L, M  
		{
			L=get_M();
		}
		else if(is(I, "77")) // MOV M, A  
		{
			set_M(A);
		}
		else if(is(I, "70")) // MOV M, B  
		{
			set_M(B);
		}
		else if(is(I, "71")) // MOV M, C  
		{
			set_M(C);
		}
		else if(is(I, "72")) // MOV M, D  
		{
			set_M(D);
		}
		else if(is(I, "73")) // MOV M, E  
		{
			set_M(E);
		}
		else if(is(I, "74")) // MOV M, H  
		{
			set_M(H);
		}
		else if(is(I, "75")) // MOV M, L  
		{
			set_M(L);
		}
		else if(is(I, "3E")) // MVI A,  
		{
			char* o = mem[pc++]; 
			A=hextodec(o);
		}
		else if(is(I, "06")) // MVI B,  
		{
			char* o = mem[pc++]; 
			B=hextodec(o);
		}
		else if(is(I, "0E")) // MVI C,  
		{
			char* o = mem[pc++]; 
			C=hextodec(o);
		}
		else if(is(I, "16")) // MVI D,  
		{
			char* o = mem[pc++]; 
			D=hextodec(o);
		}
		else if(is(I, "1E")) // MVI E,  
		{
			char* o = mem[pc++]; 
			E=hextodec(o);
		}
		else if(is(I, "26")) // MVI H,  
		{
			char* o = mem[pc++]; 
			H=hextodec(o);
		}
		else if(is(I, "2E")) // MVI L,  
		{
			char* o = mem[pc++]; 
			L=hextodec(o);
		}
		else if(is(I, "36")) // MVI M,  
		{
			char* o = mem[pc++]; 
			set_M(hextodec(o));
		}
		else if(is(I, "00")) // NOP  
		{
		
		}
		else if(is(I, "B7")) // ORA A  
		{
			A = R_OR(A, A);	
		}
		else if(is(I, "B0")) // ORA B  
		{
			A = R_OR(A, B);
		}
		else if(is(I, "B1")) // ORA C  
		{
			A = R_OR(A, C);
		}
		else if(is(I, "B2")) // ORA D  
		{
			A = R_OR(A, D);
		}
		else if(is(I, "B3")) // ORA E  
		{
			A = R_OR(A, E);
		}
		else if(is(I, "B4")) // ORA H  
		{
			A = R_OR(A, H);
		}
		else if(is(I, "B5")) // ORA L  
		{
			A = R_OR(A, L);
		}
		else if(is(I, "B6")) // ORA M  
		{
			A = R_OR(A, get_M());
		}
		else if(is(I, "F6")) // ORI  
		{
			char* o = mem[pc++]; 
			A = R_OR(A, hextodec(o));
		}
		// else if(is(I, "-")) // OUT Port 
		// {
		
		// }
		else if(is(I, "E9")) // PCHL  
		{
			char *h = dectohex(H);
			char *l = dectohex(L);
			char* t = add(h,l);
			int x = hextodec(t);
			pc = x;
		}
		else if(is(I, "C1")) // POP B  
		{
			int x = pop();
			int ms = ((x & 65280) >> 8);
			int ls = (x & 255);
			B = ms;
			C = ls;
		}
		else if(is(I, "D1")) // POP D  
		{
			int x = pop();
			int ms = ((x & 65280) >> 8);
			int ls = (x & 255);
			D = ms;
			E = ls;
		}
		else if(is(I, "E1")) // POP H  
		{
			int x = pop();
			int ms = ((x & 65280) >> 8);
			int ls = (x & 255);
			H = ms;
			L = ls;
		}
		else if(is(I, "F1")) // POP PSW  
		{
			int x = pop();
			int ms = ((x & 65280) >> 8);
			int ls = (x & 255);
			A = ms;
			set_flag_register(ls);
		}
		else if(is(I, "C5")) // PUSH B  
		{
			char* b = dectohex(B);
			char* c = dectohex(C);
			char* t = add(b,c);
			push(hextodec(t));
			free(t);
		}
		else if(is(I, "D5")) // PUSH D  
		{
			char* d = dectohex(D);
			char* e = dectohex(E);
			char* t = add(d,e);
			push(hextodec(t));
			free(t);
		}
		else if(is(I, "E5")) // PUSH H  
		{
			char* d = dectohex(D);
			char* e = dectohex(E);
			char* t = add(d,e);
			push(hextodec(t));
			free(t);
		}
		else if(is(I, "F5")) // PUSH PSW  
		{
			char* a = dectohex(A);
			char* f = dectohex(get_flag_register());
			char* t = add(a,f);
			int x = hextodec(t);
			push(x);
			free(t);

		}
		else if(is(I, "17")) // RAL  
		{
			int tc = Carry;
			Carry = (A&128) ? 1 : 0;
			A = (A << 1);
			A = (A & 254); A = (A | tc);
			A = (A&255);
		}
		else if(is(I, "1F")) // RAR  
		{
			int tc = Carry;
			Carry = (A&1) ? 1 : 0;
			A = (A >> 1);
			A = (A & 127); A = (A | (tc<<7));
			A = (A&255);
		}
		else if(is(I, "D8")) // RC  
		{
			if(Carry == 0)
			{
				continue;
			}
			pc = pop();
		}
		else if(is(I, "C9")) // RET  
		{
			pc = pop();
		}
		else if(is(I, "20")) // RIM  
		{
			// Read Interrupt Mask
		}
		else if(is(I, "07")) // RLC  
		{
			int tc = (A&128) ? 1 : 0;
			A = (A << 1);
			A = (A & 254); A = (A | tc);
			A = (A&255);
		
		}
		else if(is(I, "F8")) // RM  
		{
			if(Sign == 0)
			{
				continue;
			}
			pc = pop();
		}
		else if(is(I, "D0")) // RNC  
		{
			if(Carry == 1)
			{
				continue;
			}
			pc = pop();
		}
		else if(is(I, "C0")) // RNZ  
		{
			if(Zero == 1)
			{
				continue;
			}
			pc = pop();
		}
		else if(is(I, "F0")) // RP  
		{
			if(Sign == 1)
			{
				continue;
			}
			pc = pop();
		}
		else if(is(I, "E8")) // RPE  
		{
			if(Parity == 0)
			{
				continue;
			}
			pc = pop();
		}
		else if(is(I, "E0")) // RPO  
		{
			if(Parity == 1)
			{
				continue;
			}
			pc = pop();
		}
		else if(is(I, "0F")) // RRC  
		{
			int tc = (A&1) ? 1 : 0;
			A = (A >> 1);
			A = (A & 127); A = (A | (tc<<7));
			A = (A&255);
		}
		else if(is(I, "C7")) // RST 0  
		{
			break;
		}
		else if(is(I, "CF")) // RST 1  
		{
			break;
		}
		else if(is(I, "D7")) // RST 2  
		{
			break;
		}
		else if(is(I, "DF")) // RST 3  
		{
			break;
		}
		else if(is(I, "E7")) // RST 4  
		{
			break;
		}
		else if(is(I, "EF")) // RST 5  
		{
			break;
		}
		else if(is(I, "F7")) // RST 6  
		{
			break;
		}
		else if(is(I, "FF")) // RST 7  
		{
			break;
		}
		else if(is(I, "C8")) // RZ  
		{
			if(Zero == 0)
			{
				continue;
			}
			pc = pop();
		}
		else if(is(I, "9F")) // SBB A  
		{
			A = subB(A, A);
		}
		else if(is(I, "98")) // SBB B  
		{
			A = subB(A, B);
		}
		else if(is(I, "99")) // SBB C  
		{
			A = subB(A, C);
		}
		else if(is(I, "9A")) // SBB D  
		{
			A = subB(A, D);
		}
		else if(is(I, "9B")) // SBB E  
		{
			A = subB(A, E);
		}
		else if(is(I, "9C")) // SBB H  
		{
			A = subB(A, H);
		}
		else if(is(I, "9D")) // SBB L  
		{
			A = subB(A, L);
		}
		else if(is(I, "9E")) // SBB M  
		{
			int x = get_M();
			A = subB(A, x);
		}
		else if(is(I, "DE")) // SBI  
		{
			char* o = mem[pc++];
			int x = hextodec(o);
			A = subB(A, x);
		}
		else if(is(I, "22")) // SHLD   
		{
			char* o1 = mem[pc++];
			char* o2 = mem[pc++];
			char* o = add(o2,o1);
			int x = hextodec(o);
			free(mem[x]);
			mem[x] = dectohex(L);
			x++;
			free(mem[x]);
			mem[x] = dectohex(H);

			free(o);
		}
		else if(is(I, "30")) // SIM  
		{
			// Set interrupt mask
		}
		else if(is(I, "F9")) // SPHL  
		{
			char* h = dectohex(H);
			char* l = dectohex(L);
			char* t = add(h,l);
			int x = hextodec(t);
			SP = x;
			free(t);
		}
		else if(is(I, "32")) // STA   
		{
			char* o1 = mem[pc++];
			char* o2 = mem[pc++];
			char* o = add(o2,o1);
			int x = hextodec(o);
			free(mem[x]);
			mem[x] = dectohex(A);
		}
		else if(is(I, "02")) // STAX B  
		{
			char* b = dectohex(B);
			char* c = dectohex(C);
			char* t = add(b,c);
			int x = hextodec(t);
			free(mem[x]);
			mem[x] = dectohex(A);
		}	
		else if(is(I, "12")) // STAX D  
		{
			char* d = dectohex(D);
			char* e = dectohex(E);
			char* t = add(d,e);
			int x = hextodec(t);
			free(mem[x]);
			mem[x] = dectohex(A);
		}
		else if(is(I, "37")) // STC  
		{
			Carry = 1;
		}
		else if(is(I, "97")) // SUB A  
		{
			A = sub(A, A);
		}
		else if(is(I, "90")) // SUB B  
		{
			A = sub(A, B);
		}
		else if(is(I, "91")) // SUB C  
		{
			A = sub(A, C);
		}
		else if(is(I, "92")) // SUB D  
		{
			A = sub(A, D);
		}
		else if(is(I, "93")) // SUB E  
		{
			A = sub(A, E);
		}
		else if(is(I, "94")) // SUB H  
		{
			A = sub(A, H);
		}
		else if(is(I, "95")) // SUB L  
		{
			A = sub(A, L);
		}
		else if(is(I, "96")) // SUB M  
		{	
			int x = get_M();
			A = sub(A, x);
		}
		else if(is(I, "D6")) // SUI  
		{
			char* o = mem[pc++];
			A = sub(A, hextodec(o));
		}
		else if(is(I, "EB")) // XCHG  
		{
			int th = H; int tl = L;
			H = D; L = E;
			D = th; E = tl;
		}
		else if(is(I, "AF")) // XRA A  
		{
			A = R_XOR(A, A);
		}
		else if(is(I, "A8")) // XRA B  
		{
			A = R_XOR(A, B);
		}
		else if(is(I, "A9")) // XRA C  
		{
			A = R_XOR(A, C);
		}
		else if(is(I, "AA")) // XRA D  
		{
			A = R_XOR(A, D);
		}
		else if(is(I, "AB")) // XRA E  
		{
			A = R_XOR(A, E);
		}
		else if(is(I, "AC")) // XRA H  
		{
			A = R_XOR(A, H);
		}
		else if(is(I, "AD")) // XRA L  
		{
			A = R_XOR(A, L);
		}
		else if(is(I, "AE")) // XRA M  
		{
			A = R_XOR(A, get_M());
		}
		else if(is(I, "EE")) // XRI  
		{
			char* o = mem[pc++]; 
			A = R_XOR(A, hextodec(o));
		}
		else if(is(I, "E3")) // XTHL  
		{
			int x = pop();
			char* h = dectohex(H);
			char* l = dectohex(L);
			char* t = add(h,l);
			x = hextodec(t);
			push(x);
			free(t);
		}
	}
}

void check()
{
	printf("\n\nCHK:\n\n");

	//printf("%lld %lld %lld %lld %lld %lld %lld\n\n", A, B, C, D, E, H, L);
	//return;

	while(1)
	{
		char* a = (char*)malloc(20*sizeof(char)); a[15] = '\0';
		char* b = (char*)malloc(20*sizeof(char)); b[15] = '\0';
		int idx = 0;
		char ch;
		printf(">>>>  ");

		line = (char*)malloc(50*sizeof(char));
		scanf(" %[^\n]",line);

		l_idx = 0;
		a = get();

		//printf("--!!--##-->>%s\n", a);

		if(is(a,"reg"))
		{
			printf("----->A=%s B=%s C=%s D=%s E=%s H=%s L=%s\n\n", disp(A), disp(B)
				, disp(C), disp(D), disp(E), disp(H), disp(L));
			continue;
		}

		if(is_mem(a))
		{
			
			int y = -1;
			b = get();
			//printf("--!!--##&&&-->>%s\n", b);
			y = is_number(b);

			

			if(y != -1)
			{
				int aa = hextodec(a);
				while(y--)
				{
					a = dectohex(aa);
					if(a[idx-1] == 'h' || a[idx-1] == 'H')
					{
						a[idx-1] = '\0';
					}
					int x = hextodec(a);
					printf("----->%s : %s\n\n", a,disp(hextodec(mem[x])));
					free(a); aa++;

				}
				continue;

			}

			if(a[idx-1] == 'h' || a[idx-1] == 'H')
			{
				a[idx-1] = '\0';
			}
			int x = hextodec(a);
			printf("----->%s\n\n", disp(hextodec(mem[x])));
		}
		else
		{
			if(is(a, "A"))
			{
				printf("----->%s\n\n", disp(A));
			}
			else if(is(a, "B"))
			{
				printf("----->%s\n\n", disp(B));
			}
			else if(is(a, "C"))
			{
				printf("----->%s\n\n", disp(C));
			}
			else if(is(a, "D"))
			{
				printf("----->%s\n\n", disp(D));
			}
			else if(is(a, "E"))
			{
				printf("----->%s\n\n", disp(E));
			}
			else if(is(a, "H"))
			{
				printf("----->%s\n\n", disp(H));
			}
			else if(is(a, "L"))
			{
				printf("----->%s\n\n", disp(L));
			}
			else if(is(a, "SP"))
			{
				printf("----->%s\n\n", disph(dectohex(SP)));
			}
			else if(is(a, "Cy"))
			{
				printf("----->%d\n\n", Carry);
			}
			else if(is(a, "S"))
			{
				printf("----->%d\n\n", Sign);
			}
			else if(is(a, "Z"))
			{
				printf("----->%d\n\n", Zero);
			}
			else if(is(a, "AC"))
			{
				printf("----->%d\n\n", AC);
			}
			else if(is(a, "exit"))
			{
				break;
			}
			else
			{
				printf("----->invalid\n\n");
			}
		}
	}

}

void put_mem()
{
	printf("\n\nEXMEM:\n\n");

	//printf("%lld %lld %lld %lld %lld %lld %lld\n\n", A, B, C, D, E, H, L);
	//return;

	while(1)
	{
		char* a = (char*)malloc(20*sizeof(char)); a[15] = '\0';
		char* b = (char*)malloc(20*sizeof(char)); b[15] = '\0';
		int idx = 0;
		char ch;
		printf(">>>>  ");

		line = (char*)malloc(50*sizeof(char));
		scanf(" %[^\n]",line);

		l_idx = 0;
		a = get();

		//printf("--!!--##-->>%s\n", a);

		if(is_mem(a))
		{
			
			int y = -1;
			b = get();
			//printf("--!!--##&&&-->>%s\n", b);
			if(b != NULL && is_data(b))
			{
				int aa = hextodec(a);
				mem[aa] = b;
				printf("\n");
			}
			else if(b == NULL)
			{
				int j = 0;
				while(a[j] != '\0') j++;
				if(a[j-1] == 'h' || a[j-1] == 'H')
				{
					a[j-1] = '\0';
				}
				int x = hextodec(a);
				printf("----->%s\n\n", disp(hextodec(mem[x])));
			}
			else
			printf("----->invalid\n\n");
		}
		else if(is(a,"exit") || is(a,"e")) { printf("\n\n"); break; }
		else
		printf("----->invalid\n\n");
		
	}

}