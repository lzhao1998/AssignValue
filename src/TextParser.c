#include "TextParser.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

char *convertToLowerCase(char *name)
{
  //if there is no word/NULL
  if(name == NULL)
  {
    return NULL;
  }
  int i = 0;
  char *buffer;
  buffer = (char*)malloc(strlen(name)+1);
  strcpy(buffer,name);
  //convert the word to lowercase 1 by 1 when the last character is not NULL
  while(buffer[i] != '\0')
  {
   buffer[i] = tolower(buffer[i]);
    ++i;
  }
    return buffer;
}

// Only compare the 1st word in the string, if there is another word or number
// behind the word in the strings, ignore it.
//
// EXAMPLE:
// string is 'hello world'  what we need is 'hello'  ==> return 1;
//
// If there is space infront both string,  ignore it.
// If the 1st word in the string is wrong, return 0;
//
//                 whole string     what we need
//                        |           |
int stringCompare(char *str1, char *str2)
{
  int i = 0,j = 0;//strlength = 0;
  char *temp1,*temp2;
  temp1 = convertToLowerCase(str1);
  temp2 = convertToLowerCase(str2);
  while(temp1[i] != '\0' || temp2[j] != '\0') //if both is not NULL (still need some improvement here)
  {
    if(temp1[i] == temp2[j])  // if both are same, both pointer move forward 1
    {
      i++; j++;
    //  strlength++;
    }
    else if(temp1[i] == ' ')  //if 1 of then got 'space' move pointer forward
    {
      i++;
    //  strlength++;
    }
    else if(temp2[j] == '\0') //if the 1st word compare is all true, return 1;
    {
      return 1;
      //return strlength;
    }
    else if(temp2[j] == ' ')
    {
      j++;
    }
    else  //if wrong then return 0
    {
      return 0;
    }
  }
  return 1; //if pass, return 1
  //return strlength;
}

/* If there is alphabet or symbol in front of the number, return 0
** If there is alphabet or symbol behing of the number, return number
** If there is a space, ignroe the space and pointer move forward
** Return number if there is only number in it
*/
int getNumber(char *str)
{
  int i = 0, tempNum1 = 0, tempNum2 = 0, output = 0;
  char *temp1;
  temp1 = str;
  while(isdigit(temp1[i]) || temp1[i] == ' ')
  {
    if(temp1[i] == ' ')
    {
      i++;
    }
    else
    {
      tempNum1 = temp1[i] - 48;
      printf("tempNum1 is %d\n",tempNum1 );
      output = (output * 10) + tempNum1;
      printf("output is %d\n",output);
      i++;
    }
  }
  return output;
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
  return 0; //(for temp use only)
}

int parseTextAndAssignValues()
{

}
