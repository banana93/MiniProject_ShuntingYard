#include "unity.h"
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

 if ((((info)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)19);;};

 UnityAssertEqualNumber((_U_SINT)((ADD_OP)), (_U_SINT)((info->id)), (((void *)0)), (_U_UINT)20, UNITY_DISPLAY_STYLE_INT);

}



void test_OperatorByID_should_print_out_DIV_OP_details_due_to_DIV_OP_parameter_is_passed_in(void)

{

 OperatorInfo *info = getOperatorByID(DIV_OP);

 if ((((info)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)26);;};

 UnityAssertEqualNumber((_U_SINT)((DIV_OP)), (_U_SINT)((info->id)), (((void *)0)), (_U_UINT)27, UNITY_DISPLAY_STYLE_INT);



}



void test_OperatorByID_should_print_out_BITWISE_OR_OP_details_due_to_BITWISE_OR_OP_parameter_is_passed_in(void)

{

 OperatorInfo *info = getOperatorByID(OR_OP);

 if ((((info)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)34);;};

 UnityAssertEqualNumber((_U_SINT)((OR_OP)), (_U_SINT)((info->id)), (((void *)0)), (_U_UINT)35, UNITY_DISPLAY_STYLE_INT);

}



void test_OperatorByID_should_not_print_out_due_to_the_operator_is_not_in_the_table(void)

{

 OperatorInfo *info = getOperatorByID(UNKNOWN_OP);

 if ((((info)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)41);;};

}



void test_OperatorByName_should_print_out_ADD_OP_details_due_to_ADD_OP_parameter_is_passed_in(void)

{

 OperatorInfo *info = getOperatorByName("+");

 if ((((info)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)47);;};

 UnityAssertEqualString((const char*)("+"), (const char*)(info->name), (((void *)0)), (_U_UINT)48);

}



void test_OperatorByName_should_print_out_DIV_OP_details_due_to_DIV_OP_parameter_is_passed_in(void)

{

 OperatorInfo *info = getOperatorByName("/");

 if ((((info)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)54);;};

 UnityAssertEqualString((const char*)("/"), (const char*)(info->name), (((void *)0)), (_U_UINT)55);

}



void test_OperatorByName_should_print_out_BITWISE_OR_OP_details_due_to_BITWISE_OR_OP_parameter_is_passed_in(void)

{

 OperatorInfo *info = getOperatorByName("||");

 if ((((info)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)61);;};

 UnityAssertEqualString((const char*)("||"), (const char*)(info->name), (((void *)0)), (_U_UINT)62);



}



void test_OperatorByName_should_not_print_out_UNKNOWN_OP_details_due_to_UNKNOWN_OP_parameter_is_passed_in(void)

{

 OperatorInfo *info = getOperatorByName("asd");

 if ((((info)) == ((void *)0))) {} else {UnityFail( (" Expected NULL"), (_U_UINT)(_U_UINT)(_U_UINT)69);;};

}



void test_executeAdd_whether_it_can_push_two_number_in_and_pop_out(void)

{

 Stack *stack = stackNew(10);

 Number *value1 = numberNew(2);

 Number *value2 = numberNew(3);



 stackPush(stack, value1);

 stackPush(stack, value2);



 executeAdd(stack);

 stackDel(stack);

}



void test_executeAdd_after_push_an_operator_type_should_throw_an_exception(void)

{

 Stack *stack = stackNew(10);

 Operator *operator;

 operator = operatorNewByID(ADD_OP);

 unsigned int err;



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame)

 {

  stackPush(stack, operator);

  executeAdd(stack);

  UnityFail( ("Should have throw an exception due to it is not a number token!"), (_U_UINT)96);;

 }

 else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { err = CExceptionFrames[MY_ID].Exception; err=err; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A))

 {

  UnityAssertEqualNumber((_U_SINT)((ERR_NOT_NUMBER_TOKEN)), (_U_SINT)((err)), ("Expect ERR_NOT_NUMBER_TOKEN exception"), (_U_UINT)100, UNITY_DISPLAY_STYLE_INT);

 }

 stackDel(stack);

}



void test_executeAdd_will_throw_an_exception_if_the_first_or_second_popResult_is_NULL(void)

{

 Stack *stack = stackNew(10);

 Number *value1 = numberNew(2);

 unsigned int err;



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame)

 {

  stackPush(stack, value1);

  executeAdd(stack);

  UnityFail( ("Should have throw an exception due to incomplete number"), (_U_UINT)115);;

 }

 else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { err = CExceptionFrames[MY_ID].Exception; err=err; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A))

 {

  UnityAssertEqualNumber((_U_SINT)((ERR_INCOMPLETE_NUMBER)), (_U_SINT)((err)), ("Expect ERR_INCOMPLETE_NUMBER exception"), (_U_UINT)119, UNITY_DISPLAY_STYLE_INT);

 }

 stackDel(stack);

}



void test_executeAdd_after_push_the_value_4_and_5_it_should_pop_out_the_result_9(void)

{

 Stack *stack = stackNew(10);

 Number *result;

 Number *value1 = numberNew(4);

 Number *value2 = numberNew(5);



 stackPush(stack, value1);

 stackPush(stack, value2);



 executeAdd(stack);

 result = (Number *)stackPop(stack);

 printf("result: %d\n", result->value);

 stackDel(stack);

}



void test_executeSub_after_an_operator_ID_is_pushed_in_it_should_throw_an_exception(void)

{

 Stack *stack = stackNew(10);

 Operator *operator;

 operator = operatorNewByID(SUB_OP);

 unsigned int err;



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame)

 {

  stackPush(stack, operator);

  executeSub(stack);

  UnityFail( ("Should have throw an exception due to it is not a number token!"), (_U_UINT)151);;

 }

 else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { err = CExceptionFrames[MY_ID].Exception; err=err; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A))

 {

  UnityAssertEqualNumber((_U_SINT)((ERR_NOT_NUMBER_TOKEN)), (_U_SINT)((err)), ("Expect ERR_NOT_NUMBER_TOKEN exception"), (_U_UINT)155, UNITY_DISPLAY_STYLE_INT);

 }

 stackDel(stack);

}



void test_executeSub_it_should_throw_an_exception_due_to_either_first_or_second_pop_result_is_NULL(void)

{

 Stack *stack = stackNew(10);

 Number *value1 = numberNew(2);

 unsigned int err;



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame)

 {

  stackPush(stack, value1);

  executeSub(stack);

  UnityFail( ("Should have throw an exception due to incomplete number"), (_U_UINT)170);;

 }

 else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { err = CExceptionFrames[MY_ID].Exception; err=err; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A))

 {

  UnityAssertEqualNumber((_U_SINT)((ERR_INCOMPLETE_NUMBER)), (_U_SINT)((err)), ("Expect ERR_INCOMPLETE_NUMBER exception"), (_U_UINT)174, UNITY_DISPLAY_STYLE_INT);

 }

 stackDel(stack);

}



void test_executeSub_after_integer_5_and_4_pop_out_it_should_return_1(void)

{

 Stack *stack = stackNew(10);

 Number *result;

 Number *value1 = numberNew(5);

 Number *value2 = numberNew(4);



 stackPush(stack, value1);

 stackPush(stack, value2);



 executeSub(stack);

 result = (Number *)stackPop(stack);

 printf("result: %d\n", result->value);

 stackDel(stack);

}
