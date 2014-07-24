#include "unity.h"
#include "mock_Token.h"
#include "mock_StringObject.h"
#include "TokenDebug.h"
#include "Stack.h"
#include "OperatorToken.h"
#include "Operator.h"
#include "NumberToken.h"
#include "Evaluate.h"


void setUp(void){}



void tearDown(void){}



void test_explore_whether_it_regconize_the_NUMBER_TOKEN_and_print_it_out(void)

{

 int result;

 Stack *stack = stackNew(10);

 String expression = {.string = "2"};

 Number num5= {.type = NUMBER_TOKEN, .value = 5};



 getToken_CMockExpectAndReturn(22, &expression, (Token *)&num5);

 getToken_CMockExpectAndReturn(23, &expression, ((void *)0));



 result = evaluate(&expression);

 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((result)), (((void *)0)), (_U_UINT)26, UNITY_DISPLAY_STYLE_INT);

}



void test_explore_whether_it_regconize_the_OPERATOR_TOKEN_and_print_it_out(void)

{

 int result;

 Stack *stack = stackNew(10);

 OperatorInfo *info = getOperatorByID(ADD_OP);

 String expression = {.string = "+"};

 Operator plusOp = {.type = OPERATOR_TOKEN, info};



 getToken_CMockExpectAndReturn(37, &expression, (Token *)&plusOp);

 getToken_CMockExpectAndReturn(38, &expression, ((void *)0));



 result = evaluate(&expression);

}



void test_explore_whether_it_can_print_out_2_plus_3(void)

{

 int result;

 Stack *stack = stackNew(10);

 OperatorInfo *info = getOperatorByID(ADD_OP);

 String expression = {.string = "2+3"};



 Number value1 = {.type = NUMBER_TOKEN, .value = 2};

 Operator plusOp = {.type = OPERATOR_TOKEN, info};

 Number value2 = {.type = NUMBER_TOKEN, .value = 3};



 getToken_CMockExpectAndReturn(54, &expression, (Token *)&value1);

 getToken_CMockExpectAndReturn(55, &expression, (Token *)&plusOp);

 getToken_CMockExpectAndReturn(56, &expression, (Token *)&value2);

 getToken_CMockExpectAndReturn(57, &expression, ((void *)0));



 result = evaluate(&expression);

 UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((result)), (((void *)0)), (_U_UINT)60, UNITY_DISPLAY_STYLE_INT);

}



void test_whether_the_token_number_can_be_pushed_into_the_stack(void)

{

 int result;

 Stack *stack = stackNew(10);

 String expression = {.string = "2"};



 Number value = {.type = NUMBER_TOKEN, .value = 2};



 getToken_CMockExpectAndReturn(71, &expression, (Token *)&value);

 getToken_CMockExpectAndReturn(72, &expression, ((void *)0));



 result = evaluate(&expression);

 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((result)), (((void *)0)), (_U_UINT)75, UNITY_DISPLAY_STYLE_INT);

}



void test_whether_the_operator_token_can_be_pushed_into_the_stack(void)

{

 int result;

 Stack *stack = stackNew(10);

 OperatorInfo *info = getOperatorByID(ADD_OP);

 String expression = {.string = "+"};



 Operator addOp = {.type = OPERATOR_TOKEN, info};



 getToken_CMockExpectAndReturn(87, &expression, (Token *)&addOp);

 getToken_CMockExpectAndReturn(88, &expression, ((void *)0));



 result = evaluate(&expression);

 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((result)), (((void *)0)), (_U_UINT)91, UNITY_DISPLAY_STYLE_INT);

}



void test_whether_the_number_token_and_operator_token_can_be_pushed_into_the_stack(void)

{

 int result;

 Stack *stack = stackNew(10);

 OperatorInfo *info = getOperatorByID(ADD_OP);

 String expression = {.string = "2+3"};



 Number value1 = {.type = NUMBER_TOKEN, .value = 2};

 Operator addOp = {.type = OPERATOR_TOKEN, info};

 Number value2 = {.type = NUMBER_TOKEN, .value = 3};



 getToken_CMockExpectAndReturn(105, &expression, (Token *)&value1);

 getToken_CMockExpectAndReturn(106, &expression, (Token *)&addOp);

 getToken_CMockExpectAndReturn(107, &expression, (Token *)&value2);

 getToken_CMockExpectAndReturn(108, &expression, ((void *)0));



 result = evaluate(&expression);

 UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((result)), (((void *)0)), (_U_UINT)111, UNITY_DISPLAY_STYLE_INT);

}
