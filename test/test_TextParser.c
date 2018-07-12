#include <stdio.h>
#include <malloc.h>
#include <stdarg.h>
#include <ctype.h>
#include <string.h>
#include "unity.h"
//#include "Error.h"
#include "TextParser.h"
//#include "Exception.h"
//#include "CException.h"

void setUp(void){}
void tearDown(void){}

void test_ting(void)
{
  char* contents = "Oh MY GOD~";
  if (contents[0] == '\n')
  memmove(contents, contents+1, strlen(contents)-1);
  printf("strlen of content is %d\n", strlen(contents)-1);
  printf("contents is %s\n", contents);
}

/*  TEST THE STRINGCOMPARE FUNCTION  */
void test_stringCompare_assign_with_assign_return_true(void)
{
  char *str1 = "assign";
  char *str2 = "assign";
  int i = stringCompare(str1, str2);
  TEST_ASSERT_EQUAL(1,i);
}

void test_stringCompare_assign_with_space_assign_return_true(void)
{
  char *str1 = "assign";
  char *str2 = " assign";
  int i = stringCompare(str1, str2);
  TEST_ASSERT_EQUAL(1,i);
}

void test_stringCompare_assign_with_assign_space_return_true(void)
{
  char *str1 = "assign";
  char *str2 = "assign ";
  int i = stringCompare(str1, str2);
  TEST_ASSERT_EQUAL(1,i);
}

void test_stringCompare_space_assign_with_assign_return_true(void)
{
  char *str1 = " assign";
  char *str2 = "assign";
  int i = stringCompare(str1, str2);
  TEST_ASSERT_EQUAL(1,i);
}

void test_stringCompare_assign_space_with_assign_return_true(void)
{
  char *str1 = "assign ";
  char *str2 = "assign";
  int i = stringCompare(str1, str2);
  TEST_ASSERT_EQUAL(1,i);
}

void test_stringCompare_assign_space_with_assign_space_return_true(void)
{
  char *str1 = "assign ";
  char *str2 = "assign ";
  int i = stringCompare(str1, str2);
  TEST_ASSERT_EQUAL(1,i);
}

void test_stringCompare_space_assign_with_space_assign_return_true(void)
{
  char *str1 = "assign ";
  char *str2 = " assign";
  int i = stringCompare(str1, str2);
  TEST_ASSERT_EQUAL(1,i);
}

void test_stringCompare_asign_with_assign_return_false(void)
{
  char *str1 = "asign";
  char *str2 = "assign";
  int i = stringCompare(str1, str2);
  TEST_ASSERT_EQUAL(0,i);
}

void test_stringCompare_assign_with_asign_return_false(void)
{
  char *str1 = "assign";
  char *str2 = "asign";
  int i = stringCompare(str1, str2);
  TEST_ASSERT_EQUAL(0,i);
}

//FOR NOT ONLY JUST INPUT ASSIGN
void test_stringCompare_assign_space_apple_with_assign_return_true(void)
{
  char *str1 = "assign apple";
  char *str2 = "assign";
  int i = stringCompare(str1, str2);
  TEST_ASSERT_EQUAL(1,i);
}

void test_stringCompare_assign_space_apple_with_space_assign_return_true(void)
{
  char *str1 = "assign apple";
  char *str2 = " assign";
  int i = stringCompare(str1, str2);
  TEST_ASSERT_EQUAL(1,i);
}

void test_stringCompare_space_assign_space_apple_with_assign_return_true(void)
{
  char *str1 = " assign apple";
  char *str2 = "assign";
  int i = stringCompare(str1, str2);
  TEST_ASSERT_EQUAL(1,i);
}

void test_stringCompare_apple_space_assign_with_assign_return_false(void)
{
  char *str1 = "apple assign";
  char *str2 = "assign";
  int i = stringCompare(str1, str2);
  TEST_ASSERT_EQUAL(0,i);
}

void test_stringCompare_space_assign_space_apple_with_space_assign_space_space_return_true(void)
{
  char *str1 = "  assign apple";
  char *str2 = "   assign        ";
  int i = stringCompare(str1, str2);
  TEST_ASSERT_EQUAL(1,i);
}

//FOR COMPARE EQUAL SIGN
void test_stringCompare_equal_with_equal_return_true(void)
{
  char *str1 = "=";
  char *str2 = "=";
  int i = stringCompare(str1, str2);
  TEST_ASSERT_EQUAL(1,i);
}

void test_stringCompare_space_equal_with_equal_space_return_true(void)
{
  char *str1 = " =";
  char *str2 = "= ";
  int i = stringCompare(str1, str2);
  TEST_ASSERT_EQUAL(1,i);
}

void test_stringCompare_equal_space_with_space_equal_return_true(void)
{
  char *str1 = "= ";
  char *str2 = " =";
  int i = stringCompare(str1, str2);
  TEST_ASSERT_EQUAL(1,i);
}

void test_stringCompare_equal_with_semicolon_return_false(void)
{
  char *str1 = "=";
  char *str2 = ";";
  int i = stringCompare(str1, str2);
  TEST_ASSERT_EQUAL(0,i);
}


/*  TEST THE GETNUM FUNCTION  */
void test_getNum_input_using_string_123_return_123(void)
{
  char *str = "123";
  int i = getNumber(str);
  TEST_ASSERT_EQUAL(123,i);
}

void test_getNum_input_using_string_123a_return_123(void)
{
  char *str = "123a";
  int i = getNumber(str);
  TEST_ASSERT_EQUAL(123,i);
}

void test_getNum_input_using_string_space_123_return_123(void)
{
  char *str = " 123";
  int i = getNumber(str);
  TEST_ASSERT_EQUAL(123,i);
}

void test_getNum_input_using_string_a123_return_0(void)
{
  char *str = "a123";
  int i = getNumber(str);
  TEST_ASSERT_EQUAL(0,i);
}

/*
void test_parseTextAndAssignValues_given_no_table_mapping_should_throw_ERR_TABLE_IS_MISSING(void) {
  CEXCEPTION_T e;
  char *line = " assign mango = 589 ";

  Try {
    parseTextAndAssignValues(line, NULL);
    TEST_FAIL_MESSAGE("Expect ERR_TABLE_IS_MISSING. But no exception thrown.");
  } Catch(e) {
    printf(e->errorMsg);
    freeError(e);
  }
}

void test_parseTextAndAssignValues_given_no_command_should_do_nothing(void) {
  CEXCEPTION_T e;
  int tomato = 0;
  VariableMapping varTableMapping[] = {
    {"tomato", &tomato},
    {NULL, NULL},
  };
  char *line = NULL;

  Try {
    parseTextAndAssignValues(line, varTableMapping);
    // Should reach here because no command given
  } Catch(e) {
    printf(e->errorMsg);
    freeError(e);
  }
}

void test_parseTextAndAssignValues_given_input_command_is_NULL_should_do_nothing(void) {
  CEXCEPTION_T e;
  int kiwi = 0;
  VariableMapping varTableMapping[] = {
    {"kiwi", &kiwi},
    {NULL, NULL},
  };
  char *line = "  ";

  Try {
    parseTextAndAssignValues(line, varTableMapping);
    // Should reach here because no command given
  } Catch(e) {
    printf(e->errorMsg);
    freeError(e);
  }
}

// assign orange  = 21346 apple = 1 lemon=10
void test_parseTextAndAssignValues_given_orange_21346_apple_1_lemon_10_should_assigned_correctly(void) {
  CEXCEPTION_T e;
  int orange = 0, apple = 0, lemon = 0;
  VariableMapping varTableMapping[] = {
    {"apple", &apple},
    {"orange", &orange},
    {"lemon", &lemon},
    {NULL, NULL},
  };
  char *line = "assign orange  = 21346 apple = 1 lemon=10";

  Try {
    parseTextAndAssignValues(line, varTableMapping);

    TEST_ASSERT_EQUAL(21346, orange);
    TEST_ASSERT_EQUAL(1, apple);
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
  char *line = "assign melon = 89   ";

  Try {
    parseTextAndAssignValues(line, varTableMapping);
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
    parseTextAndAssignValues(line, varTableMapping);
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
    parseTextAndAssignValues(line, varTableMapping);
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
    parseTextAndAssignValues(line, varTableMapping);
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
    parseTextAndAssignValues(line, varTableMapping);
    TEST_FAIL_MESSAGE("Expect ERR_NOT_A_NUMBER. But no exception thrown.");
  } Catch(e) {
    printf(e->errorMsg);
    TEST_ASSERT_EQUAL(ERR_NOT_A_NUMBER, e->errorCode);
    freeError(e);
  }
}
*/
