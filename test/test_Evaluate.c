#include "unity.h"
#include "Evaluate.h"
#include "mock_Token.h"
#include "mock_StringObject.h"
#include "TokenDebug.h"
#include "Operator.h"
#include "OperatorToken.h"
#include "NumberToken.h"
#include "Stack.h"

void setUp(void){}

void tearDown(void){}

void test_explore_whether_it_regconize_the_NUMBER_TOKEN_and_print_it_out(void)
{
	int result;
	Stack *stack = stackNew(10);
	String expression = {.string = "5"};
	Number num5= {.type = NUMBER_TOKEN, .value = 5};
	
	getToken_ExpectAndReturn(&expression, (Token *)&num5);
	getToken_ExpectAndReturn(&expression, NULL);
	
	result = evaluate(&expression);
	TEST_ASSERT_EQUAL(1, result);
}

void test_explore_whether_it_regconize_the_OPERATOR_TOKEN_and_print_it_out(void)
{
	int result;
	Stack *stack = stackNew(10);
	OperatorInfo *info = getOperatorByID(ADD_OP);
	String expression = {.string = "+"};
	Operator plusOp = {.type = OPERATOR_TOKEN, info};
	
	getToken_ExpectAndReturn(&expression, (Token *)&plusOp);
	getToken_ExpectAndReturn(&expression, NULL);
	
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

	getToken_ExpectAndReturn(&expression, (Token *)&value1);
	getToken_ExpectAndReturn(&expression, (Token *)&plusOp);
	getToken_ExpectAndReturn(&expression, (Token *)&value2);
	getToken_ExpectAndReturn(&expression, NULL);
	
	result = evaluate(&expression);
	TEST_ASSERT_EQUAL(3, result);
}

void test_whether_the_token_number_can_be_pushed_into_the_stack(void)
{
	int result;
	Stack *stack = stackNew(10);
	String expression = {.string = "2"};
	
	Number value = {.type = NUMBER_TOKEN, .value = 2};
	
	getToken_ExpectAndReturn(&expression, (Token *)&value);
	getToken_ExpectAndReturn(&expression, NULL);
	
	result = evaluate(&expression);
	TEST_ASSERT_EQUAL(1, result);
}

void test_whether_the_operator_token_can_be_pushed_into_the_stack(void)
{
	int result;
	Stack *stack = stackNew(10);
	OperatorInfo *info = getOperatorByID(ADD_OP);
	String expression = {.string = "+"};
	
	Operator addOp = {.type = OPERATOR_TOKEN, info};

	getToken_ExpectAndReturn(&expression, (Token *)&addOp);
	getToken_ExpectAndReturn(&expression, NULL);
	
	result = evaluate(&expression);
	TEST_ASSERT_EQUAL(1, result);
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
	
	getToken_ExpectAndReturn(&expression, (Token *)&value1);
	getToken_ExpectAndReturn(&expression, (Token *)&addOp);
	getToken_ExpectAndReturn(&expression, (Token *)&value2);
	getToken_ExpectAndReturn(&expression, NULL);
	
	result = evaluate(&expression);
	TEST_ASSERT_EQUAL(3, result);
}

// void test_whether_the_number_token_can_be_pushed_and_pop_out(void)
// {
	// int *ptrResult;
	// Stack *stack = stackNew(10);
	// String expression = {.string = "2"};
	
	// Number value = {.type = NUMBER_TOKEN, .value = 2};
	
	// getToken_ExpectAndReturn(&expression, (Token *)&value);
	// getToken_ExpectAndReturn(&expression, NULL);
	
	// ptrResult = (int *)evaluate(&expression);
	// printf("value: %d\n", ptrResult);
	// TEST_ASSERT_EQUAL(&value, ptrResult);
// }

// void test_whether_the_operator_token_can_be_pushed_and_pop_out(void)
// {
	// int result;
	// int *ptrResult;
	// OperatorInfo *info = getOperatorByID(ADD_OP);
	// Stack *stack = stackNew(10);
	// String expression = {.string = "+"};
	
	// Operator addOp = {.type = OPERATOR_TOKEN, info};
	
	// getToken_ExpectAndReturn(&expression, (Token *)&addOp);
	// getToken_ExpectAndReturn(&expression, NULL);
	
	// ptrResult = (int *)evaluate(&expression);
	// TEST_ASSERT_EQUAL((Token *)&addOp, ptrResult);
// }

// void xtest_whether_the_number_token_and_operator_token_can_be_pushed_and_pop_out(void)
// {
	// int result;
	// int *ptrResult1, *ptrResult2, *ptrResult3;
	// OperatorInfo *info = getOperatorByID(ADD_OP);
	// Stack *stack = stackNew(10);
	// String expression = {.string = "4+5"};
	
	// Number value1 = {.type = NUMBER_TOKEN, .value = 4};
	// Operator addOp = {.type = OPERATOR_TOKEN, info};
	// Number value2 = {.type = NUMBER_TOKEN, .value = 5};
	
	// getToken_ExpectAndReturn(&expression, (Token *)&value1);
	// stackPush(stack, (Token *)&value1);
	// getToken_ExpectAndReturn(&expression, (Token *)&addOp);
	// stackPush(stack, (Token *)&addOp);
	// getToken_ExpectAndReturn(&expression, (Token *)&value2);
	// stackPush(stack, (Token *)&value2);
	// getToken_ExpectAndReturn(&expression, NULL);
	
	// ptrResult1 = stackPop(stack);
	// ptrResult2 = stackPop(stack);
	// ptrResult3 = stackPop(stack);
	
	// result = evaluate(&expression);
	
	// TEST_ASSERT_EQUAL((Token *)&value1, ptrResult3);
	// TEST_ASSERT_EQUAL((Token *)&addOp, ptrResult2);
	// TEST_ASSERT_EQUAL((Token *)&value2, ptrResult1);	
// }