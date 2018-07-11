#include "TextParser.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

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

int stringCompare(char *str1, char *str2)
{
  int i = 0,j = 0;
  char *temp1,*temp2;
  temp1 = convertToLowerCase(str1);
  temp2 = convertToLowerCase(str2);
  while(temp1[i] != '\0' || temp2[j] != '\0')
  {
    if(temp1[i] == temp2[j])
    {
      i++; j++;
    }
    else if(temp1[i] == ' ')
    {
      i++;
    }
    else if(temp2[j] == ' ')
    {
      j++;
    }
    else
    {
      return 0;
    }
  }
  return 1;
  /*if(strlen(temp1) == strlen(temp2))
  {
    while(temp1[i] != '\0' || temp2[i] != '\0')
    {
      if(temp1[i] == temp2[i])
      {
        i++;
      }
      else
      {
        //FALSE
        return 0;
      }
    }
    //TRUE
    return 1;
  }
  else
  {
    //FALSE
    return 0;
  }*/
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
