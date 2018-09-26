#include <stdio.h>
#include <conio.h>

#define YES  1 
#define NO   0 
#define MAXLINE 1000 
void process_line(char buffer[]);
void main(void)
{
	char line[MAXLINE];
	gets_s(line);
	process_line(line);
	puts(line);
	_getch();
}
void process_line(char buffer[])
{
	char *buf_ptr;  //  указатель на текущий символ буфера  
	char *end;  // указатель на конец слова 
	char *begin; // указатель на начало слова
	char c;  // текущий символ
	char prev_c; // предыдущий символ
	int found; // признак слова начинающегося на гласную
	int flag;  // признак слова

	flag = NO;
	found = NO;
	prev_c = ' ';
	buf_ptr = buffer;
	begin = buffer;
	end = buffer;

	do
	{
		c = *buf_ptr; // взять текущий символ из буфера 
		if (c == ' ' || c == '.' || c == ',' || c == '\n' || c == '\0')
		{
			if (flag == YES)
			{
				end = buf_ptr - 1;  // запомнить позицию конца слова    
				if (found == YES)
				{
					char *src = end + 1;
					char *dst = begin ;
					while ((*dst++ = *src++) != '\0');
					buf_ptr = begin;
				}
			}
			flag = NO;
			found = NO;
		}
		else
		{
			if (flag == NO)
				begin = buf_ptr;
			if ((prev_c == ' ' || prev_c == '.' || prev_c == ',' || prev_c == '\n' || prev_c == '\0') && (c == 'A' || c == 'E' || c == 'Y' || c == 'U' || c == 'I' || c == 'O' || c == 'a' || c == 'e' || c == 'y' || c == 'u' || c == 'i' || c == 'o'))
				found = YES;
			flag = YES;
		}
		prev_c = c;
		buf_ptr++;
	} while (c != '\0');
}
