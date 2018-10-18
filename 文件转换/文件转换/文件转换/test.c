#define _CRT_SECURE_NO_WARNINGS 1

#include "CommentConvert.h"

int main()
{
	FILE* pfRead = NULL;
	FILE* pfWrite = NULL;
	pfRead = fopen("input.txt", "r");
	if (pfRead == NULL)
	{
		perror("file can't be reading");
		exit(EXIT_FAILURE);
	}
	pfWrite = fopen("output.txt", "w");
	if (pfWrite == NULL)
	{
		perror("file can't be writing");
		exit(EXIT_FAILURE);
	}
	CommentConvert(pfRead, pfWrite);
	fclose(pfRead);
	fclose(pfWrite);
	pfRead = NULL;
	pfWrite = NULL;
	system("pause");
	return 0;
}