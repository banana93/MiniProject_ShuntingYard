#include "unity.h"
#include "mock_Token.h"
#include "TokenDebug.h"
#include "StringObject.h"
#include "Stack.h"
#include "OperatorToken.h"
#include "Operator.h"
#include "NumberToken.h"
#include "ErrorCode.h"
#include "CException.h"




void setUp(void){}



void tearDown(void){}



void test_getOperatorByIDInSecondaryTable_after_ADD_OP_is_passed_in_it_should_return_back_the_info_of_it(void)

{

 OperatorInfo *info = getOperatorByIDInSecondaryTable(ADD_OP);

 if ((((info)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)19);;};

 UnityAssertEqualNumber((_U_SINT)((ADD_OP)), (_U_SINT)((info->id)), (((void *)0)), (_U_UINT)20, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((100)), (_U_SINT)((info->precedence)), (((void *)0)), (_U_UINT)21, UNITY_DISPLAY_STYLE_INT);

}



void test_getOperatorByIDInSecondaryTable_after_BITWISE_NOT_OP_is_passed_in_it_should_return_the_info_of_it(void)

{

 OperatorInfo *info = getOperatorByIDInSecondaryTable(BITWISE_NOT_OP);

 if ((((info)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)27);;};

 UnityAssertEqualNumber((_U_SINT)((BITWISE_NOT_OP)), (_U_SINT)((info->id)), (((void *)0)), (_U_UINT)28, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((90)), (_U_SINT)((info->precedence)), (((void *)0)), (_U_UINT)29, UNITY_DISPLAY_STYLE_INT);

}



void test_getOperatorByIDInSecondaryTable_after_UNKNOWN_OP_is_passed_in_it_should_return_NULL(void)

{

 OperatorInfo *info = getOperatorByIDInSecondaryTable(UNKNOWN_OP);

 if ((((info)) == ((void *)0))) {} else {UnityFail( (" Expected NULL"), (_U_UINT)(_U_UINT)(_U_UINT)35);;};

}



void test_getOperatorByNameInSecondaryTable_after_plus_is_passed_in_it_should_return_back_the_info_of_it(void)

{

 OperatorInfo *info = getOperatorByNameInSecondaryTable("+");

 if ((((info)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)41);;};

 UnityAssertEqualString((const char*)("+"), (const char*)(info->name), (((void *)0)), (_U_UINT)42);

 UnityAssertEqualNumber((_U_SINT)((100)), (_U_SINT)((info->precedence)), (((void *)0)), (_U_UINT)43, UNITY_DISPLAY_STYLE_INT);

}



void test_getOperatorByNameInSecondaryTable_after_Bitwise_NOT_is_passed_in_it_should_return_back_the_info_of_it(void)

{

 OperatorInfo *info = getOperatorByNameInSecondaryTable("~");

 if ((((info)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)49);;};

 UnityAssertEqualString((const char*)("~"), (const char*)(info->name), (((void *)0)), (_U_UINT)50);

 UnityAssertEqualNumber((_U_SINT)((90)), (_U_SINT)((info->precedence)), (((void *)0)), (_U_UINT)51, UNITY_DISPLAY_STYLE_INT);

}



void test_getOperatorByNameInSecondaryTable_after_unknown_string_is_passed_in_it_should_return_back_NULL(void)

{

 OperatorInfo *info = getOperatorByNameInSecondaryTable("asd");

 if ((((info)) == ((void *)0))) {} else {UnityFail( (" Expected NULL"), (_U_UINT)(_U_UINT)(_U_UINT)57);;};

}



void test_operatorTryConvertToPrefix_will_convert_the_SUB_OP_to_prefix(void)

{

 OperatorInfo *info = getOperatorByID(SUB_OP);

 Operator subOp = {.type = OPERATOR_TOKEN, info};

 Operator *operator = operatorTryConvertToPrefix(&subOp);

 if ((((operator)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)65);;};

 UnityAssertEqualNumber((_U_SINT)((SUB_OP)), (_U_SINT)((operator->info->id)), (((void *)0)), (_U_UINT)66, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((100)), (_U_SINT)((operator->info->precedence)), (((void *)0)), (_U_UINT)67, UNITY_DISPLAY_STYLE_INT);

}
