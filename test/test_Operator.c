#include "unity.h"
#include "Operator.h"
#include "mock_Token.h"
#include <stdio.h>
#include "Stack.h"
#include "NumberToken.h"
#include "OperatorToken.h"	
#include "TokenDebug.h"
#include "CException.h"
#include "ErrorCode.h"

void setUp(void){}

void tearDown(void){}

void test_OperatorByID_should_print_out_ADD_OP_details_due_to_ADD_OP_parameter_is_passed_in(void)
{
	OperatorInfo *info = getOperatorByID(ADD_OP);
	TEST_ASSERT_NOT_NULL(info);
	TEST_ASSERT_EQUAL(ADD_OP, info->id);	
}

void test_OperatorByID_should_print_out_DIV_OP_details_due_to_DIV_OP_parameter_is_passed_in(void)
{
	OperatorInfo *info = getOperatorByID(DIV_OP);
	TEST_ASSERT_NOT_NULL(info);
	TEST_ASSERT_EQUAL(DIV_OP, info->id);	
	
}

void test_OperatorByID_should_print_out_BITWISE_OR_OP_details_due_to_BITWISE_OR_OP_parameter_is_passed_in(void)
{
	OperatorInfo *info = getOperatorByID(OR_OP);
	TEST_ASSERT_NOT_NULL(info);
	TEST_ASSERT_EQUAL(OR_OP, info->id);	
}

void test_OperatorByID_should_not_print_out_due_to_the_operator_is_not_in_the_table(void)
{
	OperatorInfo *info = getOperatorByID(UNKNOWN_OP);
	TEST_ASSERT_NOT_NULL(info);
}

void test_OperatorByName_should_print_out_ADD_OP_details_due_to_ADD_OP_parameter_is_passed_in(void)
{
	OperatorInfo *info = getOperatorByName("+");
	TEST_ASSERT_NOT_NULL(info);
	TEST_ASSERT_EQUAL_STRING("+", info->name);	
}

void test_OperatorByName_should_print_out_DIV_OP_details_due_to_DIV_OP_parameter_is_passed_in(void)
{
	OperatorInfo *info = getOperatorByName("/");
	TEST_ASSERT_NOT_NULL(info);
	TEST_ASSERT_EQUAL_STRING("/", info->name);	
}

void test_OperatorByName_should_print_out_BITWISE_OR_OP_details_due_to_BITWISE_OR_OP_parameter_is_passed_in(void)
{
	OperatorInfo *info = getOperatorByName("||");
	TEST_ASSERT_NOT_NULL(info);
	TEST_ASSERT_EQUAL_STRING("||", info->name);	
	// printf("Name: %s\n", info->name);
}

void test_OperatorByName_should_not_print_out_UNKNOWN_OP_details_due_to_UNKNOWN_OP_parameter_is_passed_in(void)
{
	OperatorInfo *info = getOperatorByName("asd");
	TEST_ASSERT_NULL(info);
}

void test_executeAdd_whether_it_can_push_two_number_in_and_pop_out(void)
{
	Stack *stack = stackNew(10);
	int result;
	Number *value1 = numberNew(2);
	Number *value2 = numberNew(3);
	
	stackPush(stack, value1);
	stackPush(stack, value2);
	

	result = executeAdd(stack);
	stackDel(stack);
}

void test_executeAdd_after_push_an_operator_type_should_throw_an_exception(void)
{
	Stack *stack = stackNew(10);
	int *result;
	CEXCEPTION_T err;
	
	Try
	{
		
		TEST_FAIL_MESSAGE("Should have throw an exception due to incomplete number!");
	}
	Catch(err)
	{
		TEST_ASSERT_EQUAL_MESSAGE(ERR_INCOMPLETE_NUMBER, err, "Expect ERR_INCOMPLETE_NUMBER exception");
		printf("Expected exception\n", err);
	}
	
	stackDel(stack);
}
	
