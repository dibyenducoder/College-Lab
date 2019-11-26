char* add(char* a, char* b)
{
	if(a == NULL) { a = (char*)malloc(sizeof(char)); a[0] = '\0'; }
	if(b == NULL) { b = (char*)malloc(sizeof(char)); b[0] = '\0'; }

	char* c =(char*)malloc(W*sizeof(char));
	int idx = 0; int i = 0;
	while(1) { if(a[i] == '\0') break; c[idx++] = a[i]; i++; }

	i = 0;
	while(1) { if(b[i] == '\0') break; c[idx++] = b[i]; i++; }

	c[idx] = '\0';

	free(a); free(b);
	return c;

}

int is(char *a, char* b)
{
	if(a == NULL || b == NULL) return 0;

	int i = 0;
	while(1)
	{
		char x = a[i]; char y = b[i];

		if(x >= 'A' && x <= 'Z') x += ('a' - 'A');
		if(y >= 'A' && y <= 'Z') y += ('a' - 'A');

		if(x != y) return 0;
		if(x == '\0' && y == '\0') return 1;
		if(x == '\0' || y == '\0') return 0;
		i++;

	}
	return 1;
}

int hash(char* y)
{
	if(y == NULL) return 0;
	int i = 0; int x = 0, z = 1;
	while(1)
	{
		char ch = y[i++]; if(ch == '\0') break;
		if(ch == ' ' || ch == ',' || ch == '\n') continue;
		if(ch >= 'A' && ch <= 'Z') ch += ('a' - 'A');
		x = (x + (z*(int)ch)%M)%M; z = (z*31)%M;
	}
	return x;
}

int is_mem_or_data(char* a)
{
	if(a == NULL) return 0;
	if(a[0] >= '0' && a[0] <= '9') return 1;
	return 0;
}

int is_data(char* a)
{
	if(a == NULL) return 0;
	int i = 0;
	if( !(a[i] >= '0' && a[i] <= '9') && !(a[i] >= 'A' && a[i] <= 'F') && !(a[i] >= 'a' && a[i] <= 'f') )
	return 0;
	i++;
	if( !(a[i] >= '0' && a[i] <= '9') && !(a[i] >= 'A' && a[i] <= 'F') && !(a[i] >= 'a' && a[i] <= 'f') )
	return 0;
	if(a[2] != '\0' && a[2] != 'H' && a[2] != 'h') return 0;
	return 1;
}

int is_mem(char* a)
{
	if(a == NULL) return 0;
	int i = 0;
	if( !(a[i] >= '0' && a[i] <= '9') && !(a[i] >= 'A' && a[i] <= 'F') && !(a[i] >= 'a' && a[i] <= 'f') )
	return 0;
	i++;
	if( !(a[i] >= '0' && a[i] <= '9') && !(a[i] >= 'A' && a[i] <= 'F') && !(a[i] >= 'a' && a[i] <= 'f') )
	return 0;
	i++;
	if( !(a[i] >= '0' && a[i] <= '9') && !(a[i] >= 'A' && a[i] <= 'F') && !(a[i] >= 'a' && a[i] <= 'f') )
	return 0;
	i++;
	if( !(a[i] >= '0' && a[i] <= '9') && !(a[i] >= 'A' && a[i] <= 'F') && !(a[i] >= 'a' && a[i] <= 'f') )
	return 0;



	if(a[4] != '\0' && a[4] != 'H' && a[4] != 'h') return 0;
	return 1;
}

void dprint(char* t)
{
	int i = 0;
	if(t == NULL) { printf("null\n\n"); return; }
	//printf("--debug--->"); fflush(stdout);
	while(1)
	{
		if(t[i] == '\0') { printf("#");  break; }
		else if(t[i] == '\n') { printf("*"); }
		else if(t[i] == ' ') { printf("+"); }
		else { printf("%c", t[i]);  }
		i++; 
		if(i >= 50) break;
	}
	t[i] = '\0'; 
	printf("    %lld", hash(t));
	printf("\n\n"); 
}

int is_number(char* a)
{
	if(a == NULL) return -1;
	int i = 0; int x = 0;
	while(1)
	{
		if(a[i] == '\0') break;
		if(a[i] < '0' || a[i] > '9') { return -1;}
		x = (x*10) + (a[i] - '0');
		i++;
	} 
	return x;

}