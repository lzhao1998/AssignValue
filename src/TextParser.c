#include "TextParser.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

/* Only compare the 1st word in the string, if there is another word or number
** behind the word in the strings, ignore it.
**
** EXAMPLE:
** string is 'hello world'  what we need is 'hello'  ==> return 1;
**
** If there is space infront both string,  ignore it.
** If the 1st word in the string is wrong, return 0;
**
**                 whole string     what we need
**                        |           |
*/
int stringCompare(char **str1, char *str2)
{
  int i = 0,j = 0;
  char *temp2;
  char *temp1 = (char *)malloc(strlen(*str1));
  strcpy(temp1,(*str1));
  temp2 = str2;
  while(temp1[i] != '\0' || temp2[j] != '\0') //if both is not NULL (still need some improvement here)
  {
    if(temp1[i] == temp2[j])  // if both are same, both pointer move forward 1
    {
      i++; j++;
    }
    else if(temp2[j] == '\0') //if the 1st word compare is all true, return 1;
    {
      (*str1) = (*str1) + i;
     free(temp1);
      return 1;
    }
    else if(temp1[i] == ' ' && isalpha(temp2[i-1])  && isalpha(temp2[i+1]))
    {
      (*str1) = (*str1) + i;
      return 0;
    }
    else if(temp2[i] == ' ' && isalpha(temp1[i-1])  && isalpha(temp1[i+1]))
    {
      (*str1) = (*str1) + i;
      return 0;
    }
    else if(temp2[j] == ' ')  //if 1 of then got 'space' move pointer forward
    {
      j++;
    }
    else if(temp1[i] == ' ')
    {
      i++;
    }
    else  //if wrong then return 0
    {
      (*str1) = (*str1) + i;
      free(temp1);
      return 0;
    }
  }
  (*str1) = (*str1) + i;
  free(temp1);
  return 1; //if pass, return 1
}

/**
* Parse and compare the string. It ignored all the spaces.  ('^')/
* If the strings are equal, it returns non-zero,
* otherwise zero value.
**/
int parseAndCompare(char **linePtr, char *cmpStr)
{
  return 0; //(for temp use only)
}

/**
* Parse and convert the first string number to value.
* It ignored all the spaces.  ('^')/
* The value is returned if the number is succesfully
* converted. If there is no number, ERR_NOT_A_NUMBER          (cannot return 0 cuz '0' also is number)
* is thrown.
**/
int parseAndConvertToNum(char **linePtr)
{
  int i = 0, tempNum1 = 0, output = 0;
  char *temp1 = (char *)malloc(strlen(*linePtr));
  strcpy(temp1,(*linePtr));
  while(isdigit(temp1[i]) || temp1[i] == ' ')
  {
    if(temp1[i] == ' ')
    {
      i++;
    }
    else
    {
      tempNum1 = temp1[i] - 48;
      output = (output * 10) + tempNum1;
      i++;
    }
  }
  (*linePtr) = (*linePtr) + i;
  free(temp1);
  return output;
}

int parseTextAndAssignValues()
{

}
