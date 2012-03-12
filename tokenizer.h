/**
* @file tokenizer.h
* @brief Tokenizer public header file 
* @author Rohan Ambli
*/

#ifndef _TOKENIZER_H_
#define _TOKENIZER_H_

#include<stdio.h>
#include<stdlib.h>
#include<string.h>


/*!***************************************************************************
	\fn free_tokens(char **tokens, int num_token)
   \brief - Free the tokens and then the pointer to the array of string tokens
	\param **tokens - Array of tokens
	\param num_tokens - number of tokens
	\return void
*****************************************************************************/

void free_tokens(char **tokens, int num_tokens);

/*!***************************************************************************
   \fn tokenize(char *string, char ***tokens)
   \brief Passed in a string, the function returns a char** of all the individual
          words in the string as members of the token array.
	\param string - string to be tokenized
	\param split_on - string to be tokenized using this char as separator
	\param tokens - Array of token sent back to the caller
	\return int - number of tokens in the string
   \note The caller must free ***tokens by calling free_tokens() function only
*****************************************************************************/
int tokenize(char *string, char split_on, char ***tokens);

#endif // _TOKENIZER_H_
