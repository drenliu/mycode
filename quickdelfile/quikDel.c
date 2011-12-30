#include<stdio.h>
#include<stdlib.h>
void removeFile(char fileName)
{
	printf("%s\n", fileName);
	remove(fileName);
}


char* readline(FILE* f)
{
	/*
	 * calloc is like malloc, except it allocates cleared memory
	 * so you don't have random bytes in the memory space
	 */
	char* line = (char*) calloc(0, sizeof(char) );;
	char c;
	int len = 0;

	/*
	 * If the readline reaches the end of a file,
	 * I want it to stop just the same
	 */
	while ( (c = fgetc(f) ) != EOF && c != '\n')
		{
			/*
			 * The actual size allocated needs to be 1 more
			 * character than the string itself because '\0'
			 * needs to be added to the end of the string
			 * to prevent garbage
			 */
			line = (char*) realloc(line, sizeof(char) * (len + 2) );
			line[len++] = c;
			line[len] = '\0';
		}
	return line;
}

int main()
{
	FILE *fp = fopen("a.txt", 'r');
	
	char* buffer;
	int i;
	for (i = 0; (rc = getc(fp)) != EOF && i < 5; buffer[i++] = rc)
	printf("%s", buffer[1]);
	fclose(fp);
}
