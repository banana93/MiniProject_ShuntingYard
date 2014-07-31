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

 if ((((info)) == ((void *)0))) {} else {UnityFail( (" Expected NULL"), (_U_UINT)(_U_UINT)(_U_UINT)68);;};

}



void test_getInfixValues_after_integer_1_and_2_is_pushed_should_display_out_1_and_2(void)

{

 Stack *stack = stackNew(10);

 int valueA, valueB;



 Number *value1 = numberNew(1);

 Number *value2 = numberNew(2);



 stackPush(stack, value1);

 stackPush(stack, value2);



 getInfixValues(&valueA, &valueB, stack);

 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((valueA)), (((void *)0)), (_U_UINT)83, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((valueB)), (((void *)0)), (_U_UINT)84, UNITY_DISPLAY_STYLE_INT);



 stackDel(stack);

}



void test_getInfixValues_after_push_an_operator_type_should_throw_an_exception(void)

{

 Stack *stack = stackNew(10);

 int valueA, valueB;

 Operator *operator;

 operator = operatorNewByID(ADD_OP);

 unsigned int err;



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame)

 {

  stackPush(stack, operator);

  getInfixValues(&valueA, &valueB, stack);

  UnityFail( ("Should have throw an exception due to it is not a number token!"), (_U_UINT)101);;

 }

 else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { err = CExceptionFrames[MY_ID].Exception; err=err; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A))

 {

  UnityAssertEqualNumber((_U_SINT)((ERR_NOT_NUMBER_TOKEN)), (_U_SINT)((err)), ("Expect ERR_NOT_NUMBER_TOKEN exception"), (_U_UINT)105, UNITY_DISPLAY_STYLE_INT);

 }

 stackDel(stack);

}



void test_getInfixValues_will_throw_an_exception_if_the_first_or_second_popResult_is_NULL(void)

{

 Stack *stack = stackNew(10);

 int valueA, valueB;

 Number *value1 = numberNew(1);

 unsigned int err;



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame)

 {

  stackPush(stack, value1);

  getInfixValues(&valueA, &valueB, stack);

  UnityFail( ("Should have throw an exception due to incomplete number"), (_U_UINT)121);;

 }

 else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { err = CExceptionFrames[MY_ID].Exception; err=err; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A))

 {

  UnityAssertEqualNumber((_U_SINT)((ERR_INCOMPLETE_NUMBER)), (_U_SINT)((err)), ("Expect ERR_INCOMPLETE_NUMBER exception"), (_U_UINT)125, UNITY_DISPLAY_STYLE_INT);

 }

 stackDel(stack);

}



void test_getInfixValues_will_throw_an_exception_if_nothing_is_pushed_into_the_stack(void)

{

 Stack *stack = stackNew(10);

 int valueA, valueB;

 Number *value1 = numberNew(1);

 unsigned int err;



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame)

 {

  getInfixValues(&valueA, &valueB, stack);

  UnityFail( ("Should have throw an exception due to incomplete number"), (_U_UINT)140);;

 }

 else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { err = CExceptionFrames[MY_ID].Exception; err=err; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A))

 {

  UnityAssertEqualNumber((_U_SINT)((ERR_INCOMPLETE_NUMBER)), (_U_SINT)((err)), ("Expect ERR_INCOMPLETE_NUMBER exception"), (_U_UINT)144, UNITY_DISPLAY_STYLE_INT);

 }

 stackDel(stack);

}



void test_pushNewNumber_after_getInfixValues_is_called_whether_2_plus_3_will_give_us_the_result_5(void)

{

 Stack *stack = stackNew(10);

 int valueA, valueB;

 Number *result;

 Number *value1 = numberNew(2);

 Number *value2 = numberNew(3);



 stackPush(stack, value1);

 stackPush(stack, value2);



 getInfixValues(&valueA, &valueB, stack);

 pushNewNumber(valueA + valueB, stack);



 result = (Number *)stackPop(stack);

 UnityAssertEqualNumber((_U_SINT)((5)), (_U_SINT)((result->value)), (((void *)0)), (_U_UINT)164, UNITY_DISPLAY_STYLE_INT);

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

  UnityFail( ("Should have throw an exception due to it is not a number token!"), (_U_UINT)179);;

 }

 else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { err = CExceptionFrames[MY_ID].Exception; err=err; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A))

 {

  UnityAssertEqualNumber((_U_SINT)((ERR_NOT_NUMBER_TOKEN)), (_U_SINT)((err)), ("Expect ERR_NOT_NUMBER_TOKEN exception"), (_U_UINT)183, UNITY_DISPLAY_STYLE_INT);

 }

 stackDel(stack);

}



void test_executeAdd_will_throw_an_exception_if_the_first_or_second_popResult_is_NULL(void)

{

 Stack *stack = stackNew(10);

 Number *value1 = numberNew(1);

 unsigned int err;



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame)

 {

  stackPush(stack, value1);

  executeAdd(stack);

  UnityFail( ("Should have throw an exception due to incomplete number"), (_U_UINT)198);;

 }

 else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { err = CExceptionFrames[MY_ID].Exception; err=err; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A))

 {

  UnityAssertEqualNumber((_U_SINT)((ERR_INCOMPLETE_NUMBER)), (_U_SINT)((err)), ("Expect ERR_INCOMPLETE_NUMBER exception"), (_U_UINT)202, UNITY_DISPLAY_STYLE_INT);

 }

 stackDel(stack);

}



void test_executeAdd_will_throw_an_exception_if_nothing_is_pushed_into_the_stack(void)

{

 Stack *stack = stackNew(10);

 Number *value1 = numberNew(1);

 unsigned int err;



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame)

 {

  executeAdd(stack);

  UnityFail( ("Should have throw an exception due to incomplete number"), (_U_UINT)216);;

 }

 else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { err = CExceptionFrames[MY_ID].Exception; err=err; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A))

 {

  UnityAssertEqualNumber((_U_SINT)((ERR_INCOMPLETE_NUMBER)), (_U_SINT)((err)), ("Expect ERR_INCOMPLETE_NUMBER exception"), (_U_UINT)220, UNITY_DISPLAY_STYLE_INT);

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

 UnityAssertEqualNumber((_U_SINT)((9)), (_U_SINT)((result->value)), (((void *)0)), (_U_UINT)237, UNITY_DISPLAY_STYLE_INT);

 stackDel(stack);

}



void test_executeSub_after_integer_5_and_4_processed_it_should_return_1(void)

{

 Stack *stack = stackNew(10);

 Number *result;

 Number *value1 = numberNew(5);

 Number *value2 = numberNew(4);



 stackPush(stack, value1);

 stackPush(stack, value2);



 executeSub(stack);

 result = (Number *)stackPop(stack);

 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((result->value)), (((void *)0)), (_U_UINT)253, UNITY_DISPLAY_STYLE_INT);

 stackDel(stack);

}



void test_executeMul_after_integer_2_and_1_is_processed_it_should_return_2(void)

{

 Stack *stack = stackNew(10);

 Number *result;

 Number *value1 = numberNew(2);

 Number *value2 = numberNew(1);



 stackPush(stack, value1);

 stackPush(stack, value2);



 executeMul(stack);

 result = (Number *)stackPop(stack);

 UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((result->value)), (((void *)0)), (_U_UINT)269, UNITY_DISPLAY_STYLE_INT);

 stackDel(stack);

}



void test_executeModulo_after_integer_1_and_2_is_processed_it_should_return_the_remainder_1(void)

{

 Stack *stack = stackNew(10);

 Number *result;

 Number *value1 = numberNew(1);

 Number *value2 = numberNew(2);



 stackPush(stack, value1);

 stackPush(stack, value2);



 executeModulo(stack);

 result = (Number *)stackPop(stack);

 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((result->value)), (((void *)0)), (_U_UINT)285, UNITY_DISPLAY_STYLE_INT);

 stackDel(stack);

}



void test_executeDiv_after_integer_2_and_2_is_processed_it_should_return_1(void)

{

 Stack *stack = stackNew(10);

 Number *result;

 Number *value1 = numberNew(2);

 Number *value2 = numberNew(2);



 stackPush(stack, value1);

 stackPush(stack, value2);



 executeDiv(stack);

 result = (Number *)stackPop(stack);

 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((result->value)), (((void *)0)), (_U_UINT)301, UNITY_DISPLAY_STYLE_INT);

 stackDel(stack);

}



void test_executeOr_after_integer_1_and_0_is_processed_it_should_return_1(void)

{

 Stack *stack = stackNew(10);

 Number *result;

 Number *value1 = numberNew(1);

 Number *value2 = numberNew(0);



 stackPush(stack, value1);

 stackPush(stack, value2);



 executeOr(stack);

 result = (Number *)stackPop(stack);

 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((result->value)), (((void *)0)), (_U_UINT)317, UNITY_DISPLAY_STYLE_INT);

 stackDel(stack);

}



void test_executeOr_after_integer_0_and_0_is_processed_it_should_return_0(void)

{

 Stack *stack = stackNew(10);

 Number *result;

 Number *value1 = numberNew(0);

 Number *value2 = numberNew(0);



 stackPush(stack, value1);

 stackPush(stack, value2);



 executeOr(stack);

 result = (Number *)stackPop(stack);

 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((result->value)), (((void *)0)), (_U_UINT)333, UNITY_DISPLAY_STYLE_INT);

 stackDel(stack);

}



void test_executeXor_after_integer_2_and_5_is_processed_it_should_return_7(void)

{

 Stack *stack = stackNew(10);

 Number *result;

 Number *value1 = numberNew(2);

 Number *value2 = numberNew(5);



 stackPush(stack, value1);

 stackPush(stack, value2);



 executeXor(stack);

 result = (Number *)stackPop(stack);

 UnityAssertEqualNumber((_U_SINT)((7)), (_U_SINT)((result->value)), (((void *)0)), (_U_UINT)349, UNITY_DISPLAY_STYLE_INT);

 stackDel(stack);

}



void test_executeAnd_after_integer_1_and_0_is_processed_it_should_return_0(void)

{

 Stack *stack = stackNew(10);

 Number *result;

 Number *value1 = numberNew(1);

 Number *value2 = numberNew(0);



 stackPush(stack, value1);

 stackPush(stack, value2);



 executeAnd(stack);

 result = (Number *)stackPop(stack);

 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((result->value)), (((void *)0)), (_U_UINT)365, UNITY_DISPLAY_STYLE_INT);

 stackDel(stack);

}



void test_executeAnd_after_integer_1_and_1_is_processed_it_should_return_1(void)

{

 Stack *stack = stackNew(10);

 Number *result;

 Number *value1 = numberNew(1);

 Number *value2 = numberNew(1);



 stackPush(stack, value1);

 stackPush(stack, value2);



 executeAnd(stack);

 result = (Number *)stackPop(stack);

 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((result->value)), (((void *)0)), (_U_UINT)381, UNITY_DISPLAY_STYLE_INT);

 stackDel(stack);

}



void test_executeBitAnd_after_integer_2_and_3_is_processed_it_should_return_2(void)

{

 Stack *stack = stackNew(10);

 Number *result;

 Number *value1 = numberNew(2);

 Number *value2 = numberNew(3);



 stackPush(stack, value1);

 stackPush(stack, value2);



 executeBitAnd(stack);

 result = (Number *)stackPop(stack);

 UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((result->value)), (((void *)0)), (_U_UINT)397, UNITY_DISPLAY_STYLE_INT);

 stackDel(stack);

}



void test_executeBitOr_after_integer_14_and_1_is_processed_it_should_return_15(void)

{

 Stack *stack = stackNew(10);

 Number *result;

 Number *value1 = numberNew(14);

 Number *value2 = numberNew(1);



 stackPush(stack, value1);

 stackPush(stack, value2);



 executeBitOr(stack);

 result = (Number *)stackPop(stack);

 UnityAssertEqualNumber((_U_SINT)((15)), (_U_SINT)((result->value)), (((void *)0)), (_U_UINT)413, UNITY_DISPLAY_STYLE_INT);

 stackDel(stack);

}
