#include "unity.h"
#include "mock_Token.h"
#include "TokenDebug.h"
#include "Token.h"
#include "Stack.h"
#include "OperatorToken.h"
#include "Operator.h"
#include "NumberToken.h"
#include "ErrorCode.h"
#include "CException.h"








void setUp(void){}



void tearDown(void){}



void test_OperatorByID_should_print_out_ADD_OP_details_due_to_ADD_OP_parameter_is_passed_in(void)

{

 OperatorInfo *info = getOperatorByID(ADD_OP);

 if ((((info)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)20);;};

 UnityAssertEqualNumber((_U_SINT)((ADD_OP)), (_U_SINT)((info->id)), (((void *)0)), (_U_UINT)21, UNITY_DISPLAY_STYLE_INT);

}



void test_OperatorByID_should_print_out_DIV_OP_details_due_to_DIV_OP_parameter_is_passed_in(void)

{

 OperatorInfo *info = getOperatorByID(DIV_OP);

 if ((((info)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)27);;};

 UnityAssertEqualNumber((_U_SINT)((DIV_OP)), (_U_SINT)((info->id)), (((void *)0)), (_U_UINT)28, UNITY_DISPLAY_STYLE_INT);



}



void test_OperatorByID_should_print_out_BITWISE_OR_OP_details_due_to_BITWISE_OR_OP_parameter_is_passed_in(void)

{

 OperatorInfo *info = getOperatorByID(OR_OP);

 if ((((info)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)35);;};

 UnityAssertEqualNumber((_U_SINT)((OR_OP)), (_U_SINT)((info->id)), (((void *)0)), (_U_UINT)36, UNITY_DISPLAY_STYLE_INT);

}



void test_OperatorByID_should_not_print_out_due_to_the_operator_is_not_in_the_table(void)

{

 OperatorInfo *info = getOperatorByID(UNKNOWN_OP);

 if ((((info)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)42);;};

}



void test_OperatorByName_should_print_out_ADD_OP_details_due_to_ADD_OP_parameter_is_passed_in(void)

{

 OperatorInfo *info = getOperatorByName("+");

 if ((((info)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)48);;};

 UnityAssertEqualString((const char*)("+"), (const char*)(info->name), (((void *)0)), (_U_UINT)49);

}



void test_OperatorByName_should_print_out_DIV_OP_details_due_to_DIV_OP_parameter_is_passed_in(void)

{

 OperatorInfo *info = getOperatorByName("/");

 if ((((info)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)55);;};

 UnityAssertEqualString((const char*)("/"), (const char*)(info->name), (((void *)0)), (_U_UINT)56);

}



void test_OperatorByName_should_print_out_BITWISE_OR_OP_details_due_to_BITWISE_OR_OP_parameter_is_passed_in(void)

{

 OperatorInfo *info = getOperatorByName("||");

 if ((((info)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)62);;};

 UnityAssertEqualString((const char*)("||"), (const char*)(info->name), (((void *)0)), (_U_UINT)63);



}



void test_OperatorByName_should_not_print_out_UNKNOWN_OP_details_due_to_UNKNOWN_OP_parameter_is_passed_in(void)

{

 OperatorInfo *info = getOperatorByName("asd");

 if ((((info)) == ((void *)0))) {} else {UnityFail( (" Expected NULL"), (_U_UINT)(_U_UINT)(_U_UINT)70);;};

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

 UnityAssertEqualNumber((_U_SINT)((5)), (_U_SINT)((result)), (((void *)0)), (_U_UINT)85, UNITY_DISPLAY_STYLE_INT);

 stackDel(stack);

}



void test_executeAdd_after_push_an_operator_type_should_throw_an_exception(void)

{

 Stack *stack = stackNew(10);

 int result;

 Operator *operator;

 operator = operatorNewByID(ADD_OP);

 unsigned int err;



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame)

 {

  stackPush(stack, operator);

  result = executeAdd(stack);

  UnityFail( ("Should have throw an exception due to it is not a number token!"), (_U_UINT)101);;

 }

 else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { err = CExceptionFrames[MY_ID].Exception; err=err; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A))

 {

  UnityAssertEqualNumber((_U_SINT)((ERR_NOT_NUMBER_TOKEN)), (_U_SINT)((err)), ("Expect ERR_NOT_NUMBER_TOKEN exception"), (_U_UINT)105, UNITY_DISPLAY_STYLE_INT);

 }

 stackDel(stack);

}



void test_executeAdd_will_throw_an_exception_if_the_first_or_second_popResult_is_NULL(void)

{

 Stack *stack = stackNew(10);

 int result;

 Number *value1 = numberNew(2);

 unsigned int err;



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame)

 {

  stackPush(stack, value1);

  result = executeAdd(stack);

  UnityFail( ("Should have throw an exception due to incomplete number"), (_U_UINT)121);;

 }

 else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { err = CExceptionFrames[MY_ID].Exception; err=err; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A))

 {

  UnityAssertEqualNumber((_U_SINT)((ERR_INCOMPLETE_NUMBER)), (_U_SINT)((err)), ("Expect ERR_INCOMPLETE_NUMBER exception"), (_U_UINT)125, UNITY_DISPLAY_STYLE_INT);

 }

 stackDel(stack);

}
