#include "unity.h"
#include "mock_Token.h"
#include "StringObject.h"
#include "OperatorToken.h"
#include "NumberToken.h"
#include "CException.h"




void setUp(void){}



void tearDown(void){}



void test_getOperatorByIDInSecondaryTable_after_ADD_OP_is_passed_in_it_should_return_back_the_info_of_it(void)

{

 OperatorInfo *info = getOperatorByIDInSecondaryTable(ADD_OP);

 if ((((info)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)15);;};

 UnityAssertEqualNumber((_U_SINT)((ADD_OP)), (_U_SINT)((info->id)), (((void *)0)), (_U_UINT)16, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((100)), (_U_SINT)((info->precedence)), (((void *)0)), (_U_UINT)17, UNITY_DISPLAY_STYLE_INT);

}



void test_getOperatorByIDInSecondaryTable_after_BITWISE_NOT_OP_is_passed_in_it_should_return_the_info_of_it(void)

{

 OperatorInfo *info = getOperatorByIDInSecondaryTable(BITWISE_NOT_OP);

 if ((((info)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)23);;};

 UnityAssertEqualNumber((_U_SINT)((BITWISE_NOT_OP)), (_U_SINT)((info->id)), (((void *)0)), (_U_UINT)24, UNITY_DISPLAY_STYLE_INT);

}



void test_getOperatorByIDInSecondaryTable_after_UNKNOWN_OP_is_passed_in_it_should_return_NULL(void)

{

 OperatorInfo *info = getOperatorByIDInSecondaryTable(UNKNOWN_OP);

 if ((((info)) == ((void *)0))) {} else {UnityFail( (" Expected NULL"), (_U_UINT)(_U_UINT)(_U_UINT)30);;};

}
