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

/*
	This function will perform addition
	Input:
	left and right
		This two input will receive the pop result from the number structure.
	Output:
		after the left and right is being processed it will push the result back into the stackPop
*/
void executeAdd(Stack *dataStack)
{
	Number *left;
	Number *right;
	Number *answer;
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
	
	numberDel(left);
	numberDel(right);
	
	answer = numberNew(result);
	stackPush(dataStack, answer);	
}

/*
	This function will perform subtraction
	Input:
	left and right
		This two input will receive the pop result from the number structure.
	Output:
		after the left and right is being processed it will push the result back into the stackPop
*/
void executeSub(Stack *dataStack)
{
	Number *left;
	Number *right;
	Number *answer;
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
		
	result = left->value - right->value;
	
	numberDel(left);
	numberDel(right);
	
	answer = numberNew(result);
	stackPush(dataStack, answer);	
}

/*
	This function will perform multiplication
	Input:
	left and right
		This two input will receive the pop result from the number structure.
	Output:
		after the left and right is being processed it will push the result back into the stackPop
*/
void executeMul(Stack *dataStack)
{
	Number *left;
	Number *right;
	Number *answer;
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
		
	result = left->value * right->value;
	
	numberDel(left);
	numberDel(right);
	
	answer = numberNew(result);
	stackPush(dataStack, answer);	
}

/*
	This function will perform modulation
	Input:
	left and right
		This two input will receive the pop result from the number structure.
	Output:
		after the left and right is being processed it will push the result back into the stackPop
*/
void executeModulo(Stack *dataStack)
{
	Number *left;
	Number *right;
	Number *answer;
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
		
	result = left->value % right->value;
	
	numberDel(left);
	numberDel(right);
	
	answer = numberNew(result);
	stackPush(dataStack, answer);	
}

/*
	This function will perform division
	Input:
	left and right
		This two input will receive the pop result from the number structure.
	Output:
		after the left and right is being processed it will push the result back into the stackPop
*/
void executeDiv(Stack *dataStack)
{
	Number *left;
	Number *right;
	Number *answer;
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
		
	result = left->value / right->value;
	
	numberDel(left);
	numberDel(right);
	
	answer = numberNew(result);
	stackPush(dataStack, answer);	
}

/*
	This function will perform logical OR operation
	Input:
	left and right
		This two input will receive the pop result from the number structure.
	Output:
		after the left and right is being processed it will push the result back into the stackPop
*/
void executeOr(Stack *dataStack)
{
	Number *left;
	Number *right;
	Number *answer;
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
		
	result = (left->value) || (right->value);
	
	numberDel(left);
	numberDel(right);
	
	answer = numberNew(result);
	stackPush(dataStack, answer);	
}

/*
	This function will perform XOR operation
	Input:
	left and right
		This two input will receive the pop result from the number structure.
	Output:
		after the left and right is being processed it will push the result back into the stackPop
*/
void executeXor(Stack *dataStack)
{
	Number *left;
	Number *right;
	Number *answer;
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
		
	result = (left->value) ^ (right->value);
	
	numberDel(left);
	numberDel(right);
	
	answer = numberNew(result);
	stackPush(dataStack, answer);	
}

/*
	This function will perform logical AND operation
	Input:
	left and right
		This two input will receive the pop result from the number structure.
	Output:
		after the left and right is being processed it will push the result back into the stackPop
*/
void executeAnd(Stack *dataStack)
{
	Number *left;
	Number *right;
	Number *answer;
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
		
	result = (left->value) && (right->value);
	
	numberDel(left);
	numberDel(right);
	
	answer = numberNew(result);
	stackPush(dataStack, answer);	
}

/*
	This function will perform bitwise AND operation
	Input:
	left and right
		This two input will receive the pop result from the number structure.
	Output:
		after the left and right is being processed it will push the result back into the stackPop
*/
void executeBitAnd(Stack *dataStack)
{
	Number *left;
	Number *right;
	Number *answer;
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
		
	result = (left->value) & (right->value);
	
	numberDel(left);
	numberDel(right);
	
	answer = numberNew(result);
	stackPush(dataStack, answer);	
}

/*
	This function will perform bitwise OR operation
	Input:
	left and right
		This two input will receive the pop result from the number structure.
	Output:
		after the left and right is being processed it will push the result back into the stackPop
*/
void executeBitOr(Stack *dataStack)
{
	Number *left;
	Number *right;
	Number *answer;
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
		
	result = (left->value) | (right->value);
	
	numberDel(left);
	numberDel(right);
	
	answer = numberNew(result);
	stackPush(dataStack, answer);	
}