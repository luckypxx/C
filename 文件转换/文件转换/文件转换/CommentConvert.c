#define _CRT_SECURE_NO_WARNINGS 1

#include "CommentConvert.h"

void Do_NUL_Convert(FILE* pfIn, FILE* pfOut, enum STATE* state)
{
	int first = fgetc(pfIn);
	int second = 0;
	switch (first)
	{
	case '/':
	{
		second = fgetc(pfIn);
		switch (second)
		{
			case '/':
				fputc(first, pfOut);
				fputc(second, pfOut);
				*state = Cpp_STATE;
				break;
			case '*':
				fputc(first, pfOut);
				fputc(first, pfOut);
				*state = C_STATE;
				break;
			default:
				fputc(first, pfOut);
				fputc(second, pfOut);
				break;
		}
	}
		break;
	case EOF:
		*state = END_STATE;
		break;
	default:
		fputc(first, pfOut);
		break;
	}
}
void Do_C_Convert(FILE* pfIn, FILE* pfOut, enum STATE* state)
{
	
	int second = 0;
	int third = 0;
	int tmp = 1;
	while (tmp)
	{
		int first = fgetc(pfIn);
		switch (first)
		{
		case '*':
		{
				second = fgetc(pfIn);
					switch (second)
					{
					case '/':
						tmp = 0;
						*state = NUL_STATE;
						break;
					case '*':
						fputc(first, pfOut);
						third = first;
						break;
					default:
						fputc(first, pfOut);
						fputc(second, pfOut);
						break;
					}
		}
			break;
		case '/':
			if (second == '*')
			{
				tmp = 0;
			}
			else
			{
				fputc(third, pfOut);
				fputc(second, pfOut);
			}
			*state = NUL_STATE;
				break;
		default:
			*state = NUL_STATE;
			break;
		}
	}
}

void Do_Cpp_Convert(FILE* pfIn, FILE* pfOut, enum STATE* state)
{
	int first = fgetc(pfIn);
	switch (first)
	{
	case '\n':
		fputc(first, pfOut);
		*state = NUL_STATE;
		break;
	case EOF:
		fputc(first, pfOut);
		*state = END_STATE;
		break;
	default:
		fputc(first, pfOut);
		*state = NUL_STATE;
		break;
	}
}

void CommentConvert(FILE* pfIn, FILE* pfOut)
{
	enum STATE state = NUL_STATE;
	while (END_STATE != state)
	{
		switch (state)
		{
		case NUL_STATE:
			Do_NUL_Convert(pfIn, pfOut, &state);
			break;
		case C_STATE:
			Do_C_Convert(pfIn, pfOut, &state);
			break;
		case Cpp_STATE:
			Do_Cpp_Convert(pfIn, pfOut, &state);
			break;
		}
	}

}