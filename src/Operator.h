#ifndef Operator_H
#define Operator_H
#include "OperatorToken.h"
#include "Token.h"
#include "Stack.h"
#include "ErrorCode.h"

void executeAdd(Stack *dataStack);
void executeSub(Stack *stack);
void executeMul(Stack *stack);
void executeModulo(Stack *stack);


#endif // Operator_H
