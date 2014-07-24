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
									 

int executeAdd(Stack *dataStack)
{
	Number *popResult;
	int count = 0, *result = 0;
	
	// do
	// {
		popResult = (Number *)stackPop(dataStack);
		tokenDump((Token *)popResult);
		// count++;
		// result = result + popResult;
		// printf("result: %d\n", result);
		
		// if(count < 2 || popResult == NULL)
		// {
			// Throw(ERR_INCOMPLETE_NUMBER);
		// }
	// }while(popResult != NULL);
	
	
	return 1;
}