#include <stdio.h>
#include <malloc.h>
#include <stdarg.h>
#include <ctype.h>
#include "unity.h"
//#include "Error.h"
#include "TextParser.h"
//#include "Exception.h"
//#include "CException.h"

void setUp(void){}
void tearDown(void){}

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
  char *str2 = "assign ";
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
/*
void xtest_parseAndCompare_given_assign_with_extra_trailing_space_should_return_true(void)
{
  char *line = "assign ";
  char *originalLine = line;

  TEST_ASSERT_TRUE(parseAndCompare(&line, "assign"));
  TEST_ASSERT_EQUAL_PTR(originalLine + 6, line);
}

//assign orange = 120 apple = 1 lemon = 10
void xtest_TextParser_given_orange_120_apple_1_lemon_10_should_assigned_correctly(void)
{
  int orange = 0, apple = 0, lemon = 0;
  VariableMapping varTableMapping[] = {
    {"apple",&apple},
    {"orange",&orange},
    {"lemon",&lemon},
    {NULL,NULL},
  };
  char *line = "assign orange = 120 apple = 1 lemon = 10";

  parseTextAndAssignValues(line, varTableMapping);

  TEST_ASSERT_EQUAL(120, orange);
  TEST_ASSERT_EQUAL(1, apple);
  TEST_ASSERT_EQUAL(10, lemon);
}


void xtest_TextParser_given_guava_23_cucumber_92_should_throw_ERR_VARIABLE_NOT_FOUND(void)
{
  CEXCEPTION_T e;
  int orange = 0, apple = 0, lemon = 0;
  VariableMapping varTableMapping[] = {
    {"guava",&guava},
    {NULL,NULL},
  };
  char *line = "assign guava =23 cucumber =92";

  Try{
    parseTextAndAssignValues(line, varTableMapping);
    TEST_FAIL_MESSAGE("Expect ERR_VARIABLE_NOT_FOUND. But no exception thrown");
  }Catch(e)
  {
    TEST_ASSERT_EQUAL(23, guava);
    printf(e->errorMsg);
    freeError(e);
    TEST_ASSERT_EQUAL(ERR_VARIABLE_NOT_FOUND, e->errorCode);
  }
}

void xtest_TextParser_given_malform_pineapple__without_equal_sign_should_throw_ERR_MALFORM_ASSIGN_FOUND(void)
{
  CEXCEPTION_T e;
  int orange = 0, apple = 0, lemon = 0;
  VariableMapping varTableMapping[] = {
    {"pineapple",&pineapple},
    {NULL,NULL},
  };
  char *line = "assign pineapple 23";

  Try{
    parseTextAndAssignValues(line, varTableMapping);
    TEST_FAIL_MESSAGE("Expect ERR_MALFORM_ASSIGN_FOUND. But no exception thrown");
  }Catch(e)
  {
    TEST_ASSERT_EQUAL(23, pineapple);
    printf(e->errorMsg);
    freeError(e);
    TEST_ASSERT_EQUAL(ERR_MALFORM_ASSIGN_FOUND, e->errorCode);
  }
}

void xtest_TextParser_given_malform_ciku_without_number_should_throw_ERR_MALFORM_ASSIGN_FOUND(void)
{
  CEXCEPTION_T e;
  int orange = 0, apple = 0, lemon = 0;
  VariableMapping varTableMapping[] = {
    {"ciku",&ciku},
    {NULL,NULL},
  };
  char *line = "assign ciku = durian = 6";

  Try{
    parseTextAndAssignValues(line, varTableMapping);
    TEST_FAIL_MESSAGE("Expect ERR_MALFORM_ASSIGN_FOUND. But no exception thrown");
  }Catch(e)
  {
    printf(e->errorMsg);
    freeError(e);
    TEST_ASSERT_EQUAL(ERR_MALFORM_ASSIGN_FOUND, e->errorCode);
  }
}*/
