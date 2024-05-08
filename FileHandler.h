#ifndef FILEHANDLER_H_INCLUDED
#define FILEHANDLER_H_INCLUDED

#define BUFFER_SIZE 1024

int appendInFile(char *Filename, char *text);
int writeInFile(char *Filename, char *text);
int ShowAllLines(char *fileName);
int removeAllLines(char *filename);
int ShowAllLines(char *fileName);
int ShowLineLength(char *fileName, int lineNum);

#endif // FILEHANDLER_H_INCLUDED
