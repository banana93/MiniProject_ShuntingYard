#include <stdlib.h>
#include <stdio.h>
#include "Debug.h"
#include "Evaluate.h"
#include "StringObject.h"
#include "Token.h"
#include "TokenDebug.h"
#include "Stack.h"

int evaluate(String *expression)
{
	int counter = 0;
	Token *token;
	Stack *stack = stackNew(10);
	do
	{
		token = getToken(expression);
		if(token != NULL)
		{
			tokenDump(token);
			counter++;
			stackPush(stack, token);
		}
		else
		{
			printf("NULL: %p\n", token);
		}	
		
	}while(token != NULL);
	
	do
	{
		token = stackPop(stack);
		if(token != NULL)
			tokenDump(token);
		else	
			printf("Stack NULL: %p\n", token);
		
	}while(token != NULL);
	
	
	return counter;
}

