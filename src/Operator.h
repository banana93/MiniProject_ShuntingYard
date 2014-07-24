#ifndef Operator_H
#define Operator_H
#include "OperatorToken.h"
#include "Token.h"
#include "Stack.h"
#include "ErrorCode.h"

int executeAdd(Stack *dataStack);
int executeSub(Stack *stack);
int executeMul(Stack *stack);
int executeNPercent(Stack *stack);


#endif // Operator_H
