#include "StringObject.h"






typedef enum

{

 UNKOWN,

 NUMBER_TOKEN,

 OPERATOR_TOKEN,

 IDENTIFIER_TOKEN

}TokenType;



typedef struct

{

 TokenType type;

}Token;



Token *getToken(String *expression);
