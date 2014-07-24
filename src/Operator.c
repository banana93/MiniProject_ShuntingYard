#include "Operator.h"
#include <stdio.h>
#include "Debug.h"
#include "Token.h"
#include "Stack.h"
#include "NumberToken.h"
#include "OperatorToken.h"
#include "Operator.h"
#include "TokenDebug.h"
#include "CException.h"
#include "ErrorCode.h"

int executeAdd(Stack *dataStack)
{
	Number *left;
	Number *right;
	int result = 0;
	
	right = (Number *)stackPop(dataStack);
	tokenDump((Token *)right);
	
	if((Token *)right == NULL)
		Throw(ERR_INCOMPLETE_NUMBER);
	
	if(right->type != NUMBER_TOKEN)
		Throw(ERR_NOT_NUMBER_TOKEN);
		
	left = (Number *)stackPop(dataStack);
	tokenDump((Token *)left);
	
	if((Token *)left == NULL)
		Throw(ERR_INCOMPLETE_NUMBER);
		
	if(left->type != NUMBER_TOKEN)
		Throw(ERR_NOT_NUMBER_TOKEN);
		
	result = left->value + right->value;
		
	return result;
}