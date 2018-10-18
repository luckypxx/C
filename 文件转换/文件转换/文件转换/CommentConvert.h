#ifndef __COMMENT_CONVERT__
#define __COMMENT_CONVERT__

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

enum STATE
{
	NUL_STATE,
	C_STATE,
	Cpp_STATE,
	END_STATE
};
void CommentConvert(FILE* pfIn, FILE* pfOut);
void Do_NUL_Convert(FILE* pfIn, FILE* pfOut, enum STATE* state);
void Do_C_Convert(FILE* pfIn, FILE* pfOut, enum STATE* state);
void Do_Cpp_Convert(FILE* pfIn, FILE* pfOut, enum STATE* state);


#endif //__COMMENT_CONVERT__