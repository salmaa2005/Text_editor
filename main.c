#include "DoubleLinkedList.h"
#include "FileHandler.h"

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
	int choice, exp, index, num, pos;
	CreateDoubleList(&l);

	do
	{
		printf("0-Insert data into a file\n");
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

		printf("10-Insert a new line at a specific position in the DS\n");
		printf("11-Show all lines in the DS\n");
		printf("12-Delete a specific line from the DS\n");
		printf("13-Replace a specific line in the DS\n");
		printf("14-Search for a specific line in the DS\n");
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
				printf("\nEnter text:\n");
				for (int i = 0; i < num; i++)
				{
					strcpy(text, getString());
					exp = appendInFile(FileName, text);
					if (exp == 0)
						printf("File doesn't exist or couldn't be opened\n");
				}
				break;

			case 1:
				if (!DoubleListEmpty(&l))
					destroy(&l);
				printf("\nEnter file name: ");
				strcpy(FileName, getString());
				exp = readFileIntoList(FileName, &l);
				if (exp == 0)
					printf("File doesn't exist or couldn't be opened\n");
				else
					printf("Inserted Successfully\n");
				break;

			case 2:
				printf("Enter file name.\n");
				strcpy(FileName, getString());
				exp = UploadToFile(FileName, &l);
				if (exp == 0)
					printf("file not exist or cannot open.\n");
				else
					printf("Inserted.\n");
				break;

			case 3:
				break;
			case 4:
				break;
			case 5:
				break;
			case 6:
				break;
			case 7:
				sortList(&l);
				break;

			case 8:
				break;
			case 9:
				break;
			case 10:
				printf("Enter the position.\n");
				pos = getChoice();
				if (pos >= 0 && pos <= lenght(&l))
				{
					printf("Enter the line.\n");
					strcpy(text, getString());
					format(text);
					InsertInPos(&l, pos, text);
				}
				else
					printf("position cannot found.\n");
				break;

			case 11:
				TraverseDoubleList(&l, &DisplayDoubleList);
				break;

			case 12:
				break;
			case 13:
				printf("Enter the position.\n");
				pos = getChoice();
				if (pos >= 0 && pos < lenght(&l))
				{
					printf("Enter the line.\n");
					strcpy(text, getString());
					format(text);
					ReplaceLine(&l, pos, text);
				}
				else
					printf("position cannot found.\n");
				break;

			case 14:
				printf("Enter the position.\n");
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
