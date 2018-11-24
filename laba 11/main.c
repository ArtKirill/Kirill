#include <stdio.h>
#include <Windows.h>
#include <string.h>
#include <conio.h>
#include <locale.h>
#define MAXLINE 1024
#pragma warning(disable:4996)

int main()
{
	setlocale(LC_ALL, "rus");
	int i, flag = 0, flagp = 0, z;
	char line[MAXLINE];
	char *ptr;
	FILE *fpin = fopen("file1.txt", "rt");
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

	while (!feof(fpin))
	{
		ptr = fgets(line, MAXLINE, fpin);

		if (ptr == NULL)
			break;

		for (i = 0; i <= strlen(line); i++) 	
    {
			if (line[i] == '/' && line[i + 1] == '*')
				flagp = 1;
			if (line[i] == '/' && line[i + 1] == '/' && flagp != '1')
				flag = 1;
			if (flag == 1) 	
      {
				SetConsoleTextAttribute(hStdout, 12);
				for (z = i; z < strlen(line); z++, i++)
					printf("%c", line[z]);
				SetConsoleTextAttribute(hStdout, 7);
			}
			if (flagp == 1)
			{
				SetConsoleTextAttribute(hStdout, 12);
				int z = i;
				for (; z < strlen(line) && flagp == 1; z++, i++)
        {
					if (line[z] == '*' && line[z + 1] == '/') 
          {
						flagp = 0;
						printf("%c", line[z]);
						i++;
						z++;
					}
					printf("%c", line[z]);
				}
				SetConsoleTextAttribute(hStdout, 7);
				if (flagp == 0) 	
        {
					printf("%c", line[i]);
					i++;
				}
			}
			else
				printf("%c", line[i]);
			flag = 0;
		}
	}
	fclose(fpin);
	_getch();
}
