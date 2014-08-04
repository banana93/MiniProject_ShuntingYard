#include "unity.h"
#include "mock_Token.h"
#include "OperatorToken.h"
#include "StringObject.h"
#include "NumberToken.h"
#include "CException.h"

void setUp(void){}

void tearDown(void){}

void test_getOperatorByIDInSecondaryTable_after_ADD_OP_is_passed_in_it_should_return_back_the_info_of_it(void)
{
	OperatorInfo *info = getOperatorByIDInSecondaryTable(ADD_OP);
	TEST_ASSERT_NOT_NULL(info);
	TEST_ASSERT_EQUAL(ADD_OP, info->id);
	TEST_ASSERT_EQUAL(100, info->precedence);
}

void test_getOperatorByIDInSecondaryTable_after_UNKNOWN_OP_is_passed_in_it_should_return_NULL(void)
{
	OperatorInfo *info = getOperatorByIDInSecondaryTable(BITWISE_NOT_OP);
	TEST_ASSERT_NOT_NULL(info);
	TEST_ASSERT_EQUAL(BITWISE_NOT_OP, info->id);
}

void test_getOperatorByIDInSecondaryTable_after_UNKNOWN_OP_is_passed_in_it_should_return_NULL(void)
{
	OperatorInfo *info = getOperatorByIDInSecondaryTable(UNKNOWN_OP);
	TEST_ASSERT_NULL(info);
}


// void xtest_operatorTryConvertToPrefix_will_convert_the_SUB_OP_to_prefix(void)
// {
	// OperatorInfo *info = getOperatorByID(SUB_OP);
	// Operator subOp = {.type = OPERATOR_TOKEN, info};
	// Operator *newInfo = operatorTryConvertToPrefix(&subOp);
	// printf("result: %d\n", newInfo->id);
// }
