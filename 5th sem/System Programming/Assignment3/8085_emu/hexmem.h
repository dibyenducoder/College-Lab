
void rev(char* a)
{
	int i = 0;
	while(1) { if(a[i] == '\0') break; i++; }
	i--;
	int j = 0;
	while(j < i)
	{
		char tmp = a[j];
		a[j] = a[i];
		a[i] = tmp;
		j++; i--;
	}
}


char* dectohex(int a)
{
	char* ans = (char*)malloc(10*sizeof(char)); 
	int idx = 0;
	if(a == 0)
	{
		ans[idx++] = '0';
	}
	while(a)
	{
		int x = a%16;

		if(x <= 9)
		{
			ans[idx++] = '0' + x;
		}
		else
		{
			ans[idx++] = 'A' + (x - 10);
		}

		a = a/16;
	}
	ans[idx] = '\0';
	rev(ans);
	if(idx == 1)
	{
		ans[1] = ans[0];
		ans[0] = '0';
		ans[2] = '\0';
	}
	if(idx == 3)
	{
		ans[3] = ans[2];
		ans[2] = ans[1];
		ans[1] = ans[0];
		ans[0] = '0';
		ans[4] = '\0';
	}
	return ans;
}

int hextodec(char* a)
{
	int x = 0;
	int i = 0;
	while(1)
	{  char ch = a[i]; if(ch == '\0') break; i++; }
	
	i--; int k = 1;
	while(i >= 0)
	{
		char ch = a[i]; int z = 0;
		if(ch >= '0' && ch <= '9') z = ch - '0';
		else if(ch >= 'A' && ch <= 'F') z = ch - 'A' + 10;
		else if(ch >= 'a' && ch <= 'f') z = ch - 'a' + 10;
		x = x + z*k; k = k*16;
		i--;
	}
	return x;

}

char* conv(int x)
{
	int y = x; // + 2000h 8192
	return dectohex(y);
}

char* copy(char* a)
{
	if(a == NULL) return NULL;
    int i = 0;
    while(1) { if(a[i] == '\0') break; i++; }
    char* t = (char*)malloc((i+5)*sizeof(char));
    i = 0;
    while(1)
    {
        t[i] = a[i];
        if(a[i] == '\0') break;
        i++;
    }
    return t;

}

char* disp(int x)
{
	char* t = dectohex(x);
	if(t[1] == '\0')
	{
		char* a = (char*)malloc(5*sizeof(char));
		a[0] = '0';
		a[1] = t[0];
		a[2] = '\0';
		free(t);
		return a;
	}
	return t;
}

char* disph(char* t)
{

	if(t == NULL) return t;
	int i = 0;
	while(1)
	{
		if(t[i] == '\0') break;
		i++;
	}
	int x = 4 - i;
	int idx = 0; 
	char* a = (char*)malloc(10*sizeof(char));
	while(x--)
	{
		a[idx++] = '0';
	}
	i = 0;
	while(1)
	{
		a[idx++] = t[i]; 
		if(t[i] == '\0') break;
		i++;
	}
	return a;
}

