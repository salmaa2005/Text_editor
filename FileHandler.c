#include "FileHandler.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int appendInFile(char *Filename, char *text)
{
	FILE *file;
	char lines[150];

	file = fopen(Filename, "a");

	if (file == NULL)
	{
		return 0;
	}
	fprintf(file, "%s", text);
	fprintf(file, "\n");
	fclose(file);
	return 1;
}

int writeInFile(char *Filename, char *text)
{
	FILE *file;
	char lines[150];

	file = fopen(Filename, "w");

	if (file == NULL)
	{
		return 0;
	}
	fprintf(file, "%s", text);
	fprintf(file, "\n");
	fclose(file);
	return 1;
}

// returns 0 if file could not be opened
// returns 1 if file was successfully displayed
int ShowAllLines(char *fileName)
{
	int LineNum = 1;
	FILE *fp = fopen(fileName, "r");
	if (!fp)
		return 0;
	char buffer[150];
	while (fgets(buffer, sizeof(buffer), fp))
	{
		printf("%d. %s", LineNum, buffer);
		LineNum++;
	}
	fclose(fp);
	return 1;
}

// returns 0 if file could not be opened
// returns -1 if file could not be truncated
// returns 1 if file was successfully removed
int removeAllLines(char *filename)
{
	FILE *file;
	char lines[150];

	file = fopen(filename, "w");

	if (file == NULL)
	{
		return 0;
	}
	if (truncate(filename, 0) != 0)
	{
		fclose(file);
		return -1;
	}
	fclose(file);
	return 1;
}
