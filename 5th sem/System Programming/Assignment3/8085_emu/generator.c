#include <stdio.h>
#include <malloc.h>
#include"getline.h"
#define W 100

FILE* fp,*fp1;
size_t len;
char* line; int l_idx;


char* get()
{
	char* a =(char*)malloc(W*sizeof(char));
	int idx = 0; char ch;

	//printf("ttttt\n");

	if(l_idx == -1) { free(a); return NULL; }

	while(1) { 
		ch = line[l_idx++];  
		if(ch == '\0' || ch == ';' || ch == '\n') { free(a);  l_idx = -1; return NULL;} 
		if(ch != ' ' && ch != ':' && ch != ',' && ch != '\n') 
		{ a[idx++] = ch; break; } 
	} // skip space/:/, etc 

	while(1)
	{
		ch = line[l_idx++];
		if(ch == '\0' || ch == ';' || ch == '\n') { l_idx = -1; a[idx] = '\0'; break; }
		if(ch == ' ' || ch == ':' || ch == ',') { a[idx] = '\0'; break; }
		a[idx++] = ch;
	}

	return a;
}

int main()
{	
	line = NULL;  l_idx = 0;
	fp = fopen("optab.txt", "r"); int f = 0;
	fp1 = fopen("ttt.txt", "w");

	while(getline(&line, &len, fp) != -1)
	{
		char *x,*y; y = NULL; x = NULL;
		y = (char*)malloc(50*sizeof(char));
		int idx = 0;
		while(1)
		{
			char ch = line[l_idx++];
			if(ch == '-') { y[idx] = '\0'; break; }
			y[idx++] = ch;
		}
		x = get();
		fprintf(fp1, "else if(is(I, \"%s\")) // %s \n", x, y);
		fprintf(fp1, "{\n\n}\n");
		//printf("%s %s\n", y, x);


		free(y);
		free(line); line = NULL;
		l_idx = 0; 

	}

	fclose(fp);
	fclose(fp1);

	return 0;
}