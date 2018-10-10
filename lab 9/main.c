#include <stdio.h> 
#define MAXLINE 1024 
void main()
{
	FILE *fpin;   // входной файл  
	FILE *fpout;  // выходной файл  
	char line[MAXLINE]; // текущая строка  
	char *ptr;
	char c;
	int cnt = 0;
	int flag = 0;
	int max = 0;
	int number = 0;
	int string = 0;
	int i;
	fopen_s(&fpin, "test.txt", "rt"); // открыть файл для чтения  
	if (fpin == NULL)
		return;    // ошибка при открытии файла 
	fopen_s(&fpout, "result.txt", "wt"); // открыть файл для записи  
	if (fpout == NULL)
		return;    // ошибка при открытии файла 
	while (!feof(fpin))// цикл до конца входного файла
	{
		ptr = fgets(line, MAXLINE, fpin); // чтение строки 
		if (ptr == NULL)
			break; // файл исчерпан 
		do // цикл до конца строки
		{
			c = *ptr;
			if (c == ' ' || c == '.' || c == ',' || c == '\0' || c == '!' || c == '?' || c == '\n' || c == EOF)
			{
				if (flag == 1)
					cnt++;
				flag = 0;
			}
			else
			{
				if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z')// Проверка слова
					flag = 1;					
			}
			ptr++; // продвигаем указатель по строке
		}
		while (c != '\0');
		if (max < cnt)
		{
			max = cnt;
			number = string;
		}
		cnt = 0;
		string++;
	}
	fseek(fpin, 0, SEEK_SET);
	for (i = 0; i < string; i++)
	{
		ptr = fgets(line, MAXLINE, fpin); // чтение строки 
		if (ptr == NULL)
			break; // файл исчерпан 
		if (i == number)
			continue;
		else
			fputs(line, fpout); // запись строки
	}
	fclose(fpin); // закрыть входной файл
	fclose(fpout); // закрыть выходной файл
}
