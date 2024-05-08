#include "DoubleLinkedList.h"
#include "FileHandler.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void DisplayDoubleList(Info e[])
{
	printf("%s\n", e);
}

void format(char text[])
{
	if (text[strlen(text) - 1] != '\n')
	{
		strcat(text, "\n");
	}
	else
	{
		if (text[strlen(text) - 2] == '\n')
			text[strlen(text) - 1] = '\0';
	}
}

char *getString()
{
	char *str = (char *)malloc(150 * sizeof(char));
	fgets(str, 150, stdin);
	size_t len = strlen(str);
	if (len > 0 && str[len - 1] == '\n')
	{
		str[len - 1] = '\0';
	}

	return str;
}

int getChoice()
{
	char input[8];
	fgets(input, sizeof(input), stdin);
	int number = atoi(input);
	return number;
}
void Menu()
{
	DoubleList l;
	char text[150], FileName[150];
	int choice, exp, index, num, pos, flag;
	CreateDoubleList(&l);
	FILE *fptr;
	Info e;
	do
	{
		printf("\nMENU:\n0-Insert data into a file\n");
		printf("1-R: Read File Into DS\n");
		printf("2-W: Write the lines stored in the DS Into The File\n");
		printf("3-I: Insert a new line at a specific Line number\n");
		printf("4-D: Delete a specific line from the DS and the file\n");
		printf("5-V: Remove all lines from the DS and the File\n");
		printf("6-L: Show the length of a specific line\n");
		printf("7-T: Sort all lines in the DS\n");
		printf("8-S: Show all lines\n");
		printf("9-C: Replace a specific line\n");

		printf("\n\nADDITIONAL FUNCTIONS:\n");

		printf("10-Show all lines in the DS\n");
		printf("11-Show the length of a specific line in the DS\n");
		printf("Enter (-1) to EXIT\n");
		printf("\nEnter Your choice: ");
		choice = getChoice();

		switch (choice)
		{
			case 0:
				printf("\nEnter file name: ");
				strcpy(FileName, getString());
				printf("\nEnter number of lines: ");
				num = getChoice();
				if (num == 0)
				{
					exp = removeAllLines(FileName);
					if (exp == 0)
						printf("File doesn't exist or couldn't be opened\n");
					else
						printf("File created but is empty\n");
				}
				else
				{
					printf("\nEnter text:\n");
					for (int i = 0; i < num; i++)
					{
						strcpy(text, getString());
						exp = appendInFile(FileName, text);
						if (exp == 0)
							printf(
								"File doesn't exist or couldn't be opened\n");
					}
				}
				break;

			case 1:
				if (!DoubleListEmpty(&l))
					destroy(&l);
				printf("\nEnter file name: ");
				strcpy(FileName, getString());
				exp = readFileIntoList(FileName, &l);
				fptr = fopen(FileName, "r");
				if (fptr == NULL)
					printf("File doesn't exist or couldn't be opened\n");
				else if (getc(fptr) == EOF)
					printf("This file is empty\n");
				else
					printf("Read Successfully!\n");
				break;

			case 2:
				printf("\nEnter file name: ");
				strcpy(FileName, getString());
				index = lenght(&l);
				if (index == 0)
				{
					printf("Your list is empty do you want to delete the file "
						   "contents?\n");
					printf("1-Yes\n2-No\n");
					flag = getChoice();
					if (flag == 1)
					{
						exp = UploadToFile(FileName, &l);

						if (exp == 0)
							printf("file not exist or cannot open.\n");
						else
							printf("Written Successfully!\n");
					}
				}
				else
				{
					exp = UploadToFile(FileName, &l);
					if (exp == 0)
						printf("file not exist or cannot open.\n");
					else
						printf("Written Successfully!\n");
				}
				break;

			case 3:
				printf("\nEnter the position: ");
				pos = getChoice();
				if (pos >= 0 && pos <= lenght(&l))
				{
					printf("\nEnter text: ");
					strcpy(text, getString());
					format(text);
					InsertInPos(&l, pos, text);
					printf("1- To save the changes into the file\n");
					printf("2- To discard the changes\n");
					printf("Enter your choice: ");
					flag = getChoice();
					if (flag == 1)
					{
						printf("\nEnter file name: ");
						strcpy(FileName, getString());
						exp = UploadToFile(FileName, &l);
						if (exp == 0)
							printf(
								"File doesn't exist or couldn't be opened\n");
						else
							printf("Inserted Successfully!\n");
					}
				}
				else
					printf("Position not found.\n");

				break;
			case 4:
				printf("\nEnter the position: ");
				pos = getChoice();
				if (pos >= 0 && pos < lenght(&l))
				{
					DeleteInPos(&l, pos, text);
					printf("The deleted line is: %s \n", text);
					printf("1- To save the changes into the file\n");
					printf("2- To discard the changes\n");
					printf("Enter your choice: ");
					flag = getChoice();
					if (flag == 1)
					{
						printf("\nEnter file name: ");
						strcpy(FileName, getString());
						exp = UploadToFile(FileName, &l);
						if (exp == 0)
							printf(
								"File doesn't exist or couldn't be opened\n");
						else
							printf("Inserted Successfully!\n");
					}
				}
				else
					printf("Position not found.\n");
				break;
			case 5:
				printf("\nEnter file name: ");
				strcpy(FileName, getString());
				fptr = fopen(FileName, "r");
				if (fgetc(fptr) == EOF)
				{
					printf("This file is empty\n");
					break;
				}
				destroy(&l);
				exp = removeAllLines(FileName);
				if (exp == 0)
					printf("File doesn't exist or couldn't be opened\n");
				else if (exp == -1)
					printf("File couldn't be truncated\n");
				else
					printf("Deleted Successfully!\n");
				break;
			case 6:
				printf("\nEnter file name: ");
				strcpy(FileName, getString());
				printf("\nEnter line number: ");
				pos = getChoice();
				exp = ShowLineLength(FileName, pos);
				if (exp == 0)
					printf("File doesn't exist or couldn't be opened\n");
				else if (exp == -1)
					printf("Line doesn't exist\n");
				else
					printf("Length of line %d is %d\n", pos, exp);
				break;
			case 7:
				sortList(&l);
				printf("1- To save the changes into the file\n");
				printf("2- To discard the changes\n");
				printf("Enter your choice: ");
				flag = getChoice();
				if (flag == 1)
				{
					printf("\nEnter file name: ");
					strcpy(FileName, getString());
					exp = UploadToFile(FileName, &l);
					if (exp == 0)
						printf("File doesn't exist or couldn't be opened\n");
					else
						printf("Inserted Successfully!\n");
				}
				break;

			case 8:
				printf("Enter file name: ");
				strcpy(FileName, getString());
				fptr = fopen(FileName, "r");
				if (!fptr)
					printf("File doesn't exist or couldn't be opened\n");
				else if (fgetc(fptr) == EOF)
					printf("This file is empty\n");
				else
					ShowAllLines(FileName);
				break;
			case 9:
				printf("\nEnter the position: ");
				pos = getChoice();
				if (pos >= 0 && pos < lenght(&l))
				{
					printf("\nEnter the line: ");
					strcpy(text, getString());
					format(text);
					ReplaceLine(&l, pos, text);
					printf("1- To save the changes into the file\n");
					printf("2- To discard the changes\n");
					printf("Enter your choice: ");
					flag = getChoice();
					if (flag == 1)
					{
						printf("\nEnter file name: ");
						strcpy(FileName, getString());
						exp = UploadToFile(FileName, &l);
						if (exp == 0)
							printf(
								"File doesn't exist or couldn't be opened\n");
						else
							printf("Inserted Successfully!\n");
					}
				}
				else
					printf("Position not found.\n");
				break;
			case 10:
				TraverseDoubleList(&l, &DisplayDoubleList);
				break;

			case 11:
				printf("\nEnter the position: ");
				pos = getChoice();
				if (pos >= 0 && pos < lenght(&l))
				{
					exp = showLength(&l, pos);
					printf("length = %d\n", exp);
				}
				else
					printf("position not found.\n");
				break;

			case -1:
				printf("Exiting...\n");
				break;
			default:
				printf("\nEnter a valid choice: ");
				break;
		}
	} while (choice != -1);
}
int main()
{
	Menu();
	return 0;
}
