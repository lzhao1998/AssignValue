#include <stdio.h>
#include <malloc.h>
#include <stdarg.h>
#include <ctype.h>
#include "unity.h"
#include "Error.h"
#include "TextParser.h"
#include "Exception.h"
#include "CException.h"

void setUp(void){}
void tearDown(void){}

/*  TEST THE STRINGCOMPARE FUNCTION  */
void test_stringCompare_assign_with_assign_return_true(void)
{
  char *str1 = "assign";
  char *str2 = "assign";
  char *originalStr1 = str1;
  int i = stringCompare(&str1, str2);
  TEST_ASSERT_EQUAL(1,i);
  TEST_ASSERT_EQUAL_PTR(originalStr1+6, str1);
}

void test_stringCompare_assign_with_space_assign_return_true(void)
{
  char *str1 = "assign";
  char *str2 = " assign";
  char *originalStr1 = str1;
  int i = stringCompare(&str1, str2);
  TEST_ASSERT_EQUAL(1,i);
  TEST_ASSERT_EQUAL_PTR(originalStr1+6, str1);
}

void test_stringCompare_assign_with_assign_space_return_true(void)
{
  char *str1 = "assign";
  char *str2 = "assign ";
  char *originalStr1 = str1;
  int i = stringCompare(&str1, str2);
  TEST_ASSERT_EQUAL(1,i);
  TEST_ASSERT_EQUAL_PTR(originalStr1+6, str1);
}

void test_stringCompare_space_assign_with_assign_return_true(void)
{
  char *str1 = " assign";
  char *str2 = "assign";
  char *originalStr1 = str1;
  int i = stringCompare(&str1, str2);
  TEST_ASSERT_EQUAL(1,i);
  TEST_ASSERT_EQUAL_PTR(originalStr1+7, str1);
}

void test_stringCompare_assign_space_with_assign_return_true(void)
{
  char *str1 = "assign ";
  char *str2 = "assign";
  char *originalStr1 = str1;
  int i = stringCompare(&str1, str2);
  TEST_ASSERT_EQUAL(1,i);
  TEST_ASSERT_EQUAL_PTR(originalStr1+6, str1);
}

void test_stringCompare_assign_space_with_assign_space_return_true(void)
{
  char *str1 = "assign ";
  char *str2 = "assign ";
  char *originalStr1 = str1;
  int i = stringCompare(&str1, str2);
  TEST_ASSERT_EQUAL(1,i);
  TEST_ASSERT_EQUAL_PTR(originalStr1+7, str1);
}

void test_stringCompare_space_assign_with_space_assign_return_true(void)
{
  char *str1 = "assign ";
  char *str2 = " assign";
  char *originalStr1 = str1;
  int i = stringCompare(&str1, str2);
  TEST_ASSERT_EQUAL(1,i);
  TEST_ASSERT_EQUAL_PTR(originalStr1+6, str1);
}

void test_stringCompare_asign_with_assign_return_false(void)
{
  char *str1 = "asign";
  char *str2 = "assign";
  char *originalStr1 = str1;
  int i = stringCompare(&str1, str2);
  TEST_ASSERT_EQUAL(0,i);
  TEST_ASSERT_EQUAL_PTR(originalStr1+2, str1);
}

void test_stringCompare_assign_with_asign_return_false(void)
{
  char *str1 = "assign";
  char *str2 = "asign";
  char *originalStr1 = str1;
  int i = stringCompare(&str1, str2);
  TEST_ASSERT_EQUAL(0,i);
  TEST_ASSERT_EQUAL_PTR(originalStr1+2, str1);
}

void test_stringCompare_ass_space_ign_with_assign_return_false(void)
{
  char *str1 = "ass ign";
  char *str2 = "assign";
  char *originalStr1 = str1;
  int i = stringCompare(&str1, str2);
  TEST_ASSERT_EQUAL(0,i);
  TEST_ASSERT_EQUAL_PTR(originalStr1+3, str1);
}

void test_stringCompare_assign_with_ass_spcae_ign_return_false(void)
{
  char *str1 = "assign";
  char *str2 = "ass ign";
  char *originalStr1 = str1;
  int i = stringCompare(&str1, str2);
  TEST_ASSERT_EQUAL(0,i);
  TEST_ASSERT_EQUAL_PTR(originalStr1+3, str1);
}

//FOR NOT ONLY JUST INPUT ASSIGN
void test_stringCompare_assign_space_apple_with_assign_return_true(void)
{
  char *str1 = "assign apple";
  char *str2 = "assign";
  char *originalStr1 = str1;
  int i = stringCompare(&str1, str2);
  TEST_ASSERT_EQUAL(1,i);
  TEST_ASSERT_EQUAL_PTR(originalStr1+6, str1);
}

void test_stringCompare_assign_space_apple_with_space_assign_return_true(void)
{
  char *str1 = "assign apple";
  char *str2 = " assign";
  char *originalStr1 = str1;
  int i = stringCompare(&str1, str2);
  TEST_ASSERT_EQUAL(1,i);
  TEST_ASSERT_EQUAL_PTR(originalStr1+6, str1);
}

void test_stringCompare_space_assign_space_apple_with_assign_return_true(void)
{
  char *str1 = " assign apple";
  char *str2 = "assign";
  char *originalStr1 = str1;
  int i = stringCompare(&str1, str2);
  TEST_ASSERT_EQUAL(1,i);
  TEST_ASSERT_EQUAL_PTR(originalStr1+7, str1);
}

void test_stringCompare_space_assign_space_apple_equal_89_with_assign_return_true(void)
{
  char *str1 = " assign apple = 89";
  char *str2 = "assign";
  char *originalStr1 = str1;
  int i = stringCompare(&str1, str2);
  TEST_ASSERT_EQUAL(1,i);
  TEST_ASSERT_EQUAL_PTR(originalStr1+7, str1);
  TEST_ASSERT_EQUAL_STRING(" apple = 89",str1);
}

void test_stringCompare_apple_space_assign_with_assign_return_false(void)
{
  char *str1 = "apple assign";
  char *str2 = "assign";
  char *originalStr1 = str1;
  int i = stringCompare(&str1, str2);
  TEST_ASSERT_EQUAL(0,i);
  TEST_ASSERT_EQUAL_PTR(originalStr1+1, str1);
}

void test_stringCompare_space_assign_space_apple_with_space_assign_space_space_return_true(void)
{
  char *str1 = "  assign apple";
  char *str2 = "   assign        ";
  char *originalStr1 = str1;
  int i = stringCompare(&str1, str2);
  TEST_ASSERT_EQUAL(1,i);
  TEST_ASSERT_EQUAL_PTR(originalStr1+9, str1);
}

void test_stringCompare_assign_space_apple_with_space_assign_space_space_and_original_pointer_plus7_return_true_(void)
{
  char *str1 = "assign apple";
  char *originalStr1 = str1;
  char *str2 = "assign        ";
  int i = stringCompare(&str1, str2);
  TEST_ASSERT_EQUAL(1,i);
  //is +7, not +6 is because the 'space' behind both string is same place
  TEST_ASSERT_EQUAL_PTR(originalStr1+7, str1);
}

//FOR COMPARE EQUAL SIGN
void test_stringCompare_equal_with_equal_return_true(void)
{
  char *str1 = "=";
  char *str2 = "=";
  char *originalStr1 = str1;
  int i = stringCompare(&str1, str2);
  TEST_ASSERT_EQUAL(1,i);
  TEST_ASSERT_EQUAL_PTR(originalStr1+1, str1);
}

void test_stringCompare_equal_with_semicolon_return_false(void)
{
  char *str1 = "=";
  char *str2 = ";";
  char *originalStr1 = str1;
  int i = stringCompare(&str1, str2);
  TEST_ASSERT_EQUAL(0,i);
  TEST_ASSERT_EQUAL_PTR(originalStr1, str1);
}

/*  TEST THE PARSEANDCONVERTTONUM FUNCTION  */
void test_parseTextAndAssignValues_given_input_command_is_NULL_should_do_nothing(void) {
  CEXCEPTION_T e;
  int kiwi = 0;
  VariableMapping varTableMapping[] = {
    {"kiwi", &kiwi},
    {NULL, NULL},
  };
  char *line = "  ";

  Try {
    parseTextAndAssignValues(&line, varTableMapping);
    // Should reach here because no command given
  } Catch(e) {
    printf(e->errorMsg);
    freeError(e);
  }
}

// assign apple  = 21346 orange = 1 lemon=10
void test_parseTextAndAssignValues_given_apple_21346_orange_1_lemon_10_should_assigned_correctly(void) {
  CEXCEPTION_T e;
  int orange = 0, apple = 0, lemon = 0;
  VariableMapping varTableMapping[] = {
    {"apple", &apple},
    {"orange", &orange},
    {"lemon", &lemon},
    {NULL, NULL},
  };
  char *line = "assign apple  = 21346 orange = 1 lemon=10";

  Try {
    parseTextAndAssignValues(&line, varTableMapping);
    TEST_ASSERT_EQUAL(21346, apple);
    TEST_ASSERT_EQUAL(1, orange);
    TEST_ASSERT_EQUAL(10, lemon);
  } Catch(e) {
    printf(e->errorMsg);
    freeError(e);
  }
}

void test_parseTextAndAssignValues_given_melon_and_value_with_trailing_spaces_should_parse_properly(void) {
  CEXCEPTION_T e;
  int melon = 0;
  VariableMapping varTableMapping[] = {
    {"melon  ", &melon},
    {NULL, NULL},
  };
  char *line = "assign melon  = 89   ";

  Try {
    parseTextAndAssignValues(&line, varTableMapping);
    TEST_ASSERT_EQUAL(89, melon);
  } Catch(e) {
    printf(e->errorMsg);
    freeError(e);
  }
}


void test_parseTextAndAssignValues_given_text_without_assign_should_throw_ERR_UNKNOWN_COMMAND(void) {
  CEXCEPTION_T e;
  int papaya = 0;
  VariableMapping varTableMapping[] = {
    {"papaya", &papaya},
    {NULL, NULL},
  };
  char *line = "  papaya = 345 ";

  Try {
    parseTextAndAssignValues(&line, varTableMapping);
    TEST_FAIL_MESSAGE("Expect ERR_UNKNOWN_COMMAND. But no exception thrown.");
  } Catch(e) {
    printf(e->errorMsg);
    TEST_ASSERT_EQUAL(ERR_UNKNOWN_COMMAND, e->errorCode);
    freeError(e);
  }
}


void test_parseTextAndAssignValues_given_guava_23_cucumber_92_should_throw_ERR_UNKNOWN_VARIABLE(void) {
  CEXCEPTION_T e;
  int guava = 0;
  VariableMapping varTableMapping[] = {
    {"guava", &guava},
    {NULL, NULL},
  };
  char *line = "assign guava=23 cucumber=92";

  Try {
    parseTextAndAssignValues(&line, varTableMapping);
    TEST_FAIL_MESSAGE("Expect ERR_UNKNOWN_VARIABLE. But no exception thrown.");
  } Catch(e) {
    TEST_ASSERT_EQUAL(23, guava);
    printf(e->errorMsg);
    TEST_ASSERT_EQUAL(ERR_UNKNOWN_VARIABLE, e->errorCode);
    freeError(e);
  }
}


void test_parseTextAndAssignValues_given_malform_pineapple_without_equal_sign_should_throw_ERR_MALFORM_ASSIGN(void) {
  CEXCEPTION_T e;
  int pineapple = 0;
  VariableMapping varTableMapping[] = {
    {"pineapple", &pineapple},
    {NULL, NULL},
  };
  char *line = "assign pineapple 23 ";

  Try {
    parseTextAndAssignValues(&line, varTableMapping);
    TEST_FAIL_MESSAGE("Expect ERR_MALFORM_ASSIGN. But no exception thrown.");
  } Catch(e) {
    printf(e->errorMsg);
    TEST_ASSERT_EQUAL(ERR_MALFORM_ASSIGN, e->errorCode);
    freeError(e);
  }
}

void test_parseTextAndAssignValues_given_malform_ciku_without_number_should_throw_ERR_NOT_A_NUMBER(void) {
  CEXCEPTION_T e;
  int ciku = 0;
  VariableMapping varTableMapping[] = {
    {"ciku", &ciku},
    {NULL, NULL},
  };
  char *line = "assign ciku =  durian = 6";

  Try {
    parseTextAndAssignValues(&line, varTableMapping);
    TEST_FAIL_MESSAGE("Expect ERR_NOT_A_NUMBER. But no exception thrown.");
  } Catch(e) {
    printf(e->errorMsg);
    TEST_ASSERT_EQUAL(ERR_NOT_A_NUMBER, e->errorCode);
    freeError(e);
  }
}
