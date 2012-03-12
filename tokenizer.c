/**
* @file tokenizer.c
* @brief Tokenizer to separate out words in a sentence, split on passed
*        in character
* @author Rohan Ambli
*/

#include"tokenizer.h"

/*!***************************************************************************
	\fn free_tokens(char **tokens, int num_token)
   \brief - Free the tokens and then the pointer to the array of string tokens
	\param **tokens - Array of tokens
	\param num_tokens - number of tokens
	\return void
*****************************************************************************/

void free_tokens(char **tokens, int num_tokens)
{
   if(NULL == tokens)
      return;
   int i = 0;
   for(i = 0; i < num_tokens; i++)
   {
      free(tokens[i]);
      tokens[i] = NULL;
   }
   free(tokens);
   tokens = NULL;
   return;
}

/*!***************************************************************************
   \fn tokenize(char *string, char ***tokens)
   \brief Passed in a string, the function returns a char** of all the individual
          words in the string as members of the token array.
	\param string - string to be tokenized
	\param split_on - string to be tokenized at this char
	\param tokens - Array of token sent back to the caller
	\return int - number of tokens in the string
   \note The caller must free ***tokens by calling free_tokens() function only
*****************************************************************************/
int tokenize(char *string, char split_on, char ***tokens)
{
   if((NULL == tokens) || (NULL == string))
   {
      printf("Bad args: %p %p\n", tokens, string);
      return 0;
   }

   char *tmp = string;
   int num_tokens = 0;
   int longest_token = 0;
   int token_length = 0;

   /* Parse how many tokens and the longest one as well 
    * TODO: Think about allocating memory and tokenizing in this loop 
    * instead of in a second one below. */
   while(*tmp)
   {
      /* split_on is the token character */
      if(split_on == *tmp)
      {
         if(longest_token < token_length)
            longest_token = token_length;
         token_length = 0;
         num_tokens++;
      }
      token_length++;
      tmp++;
   }
   num_tokens++;  // to account for the last word
   
   printf("\nWe have %d tokens, longest one is %d chars\n", num_tokens, longest_token);

   /* Allocate space to hold array of strings */
   *tokens = (char **)malloc(num_tokens * sizeof(char*));
   if(NULL == *tokens)
   {
      printf("Failed to malloc space for %d strings\n", num_tokens);
      return;
   }

   /* Now allocate space for individual strings in the array */
   /* TODO: Instead of allocating longest_token length for each token,
    * allocate only the token length number of bytes */
   int i = 0;
   for(i = 0 ; i < num_tokens ; i++)
   {
      (*tokens)[i] = (char*)malloc(sizeof(char) * longest_token);
   }

   /* Reset tmp to beginning of string to start extracting tokens */
   tmp = string; 

   i = 0;
   /* Tokenize the string here, dump in the above malloc'ed strings 
    * and send back the string array */
   while(*tmp && (i < num_tokens))
   {
      int j = 0;
      while((split_on != *tmp) && (j < longest_token))
      {
         (*tokens)[i][j] = *tmp;
         j++;
         tmp++;
      }
      /* Done copying a token, increment i to move to populating the next token */
      i++;
      tmp++;
   }
   return (num_tokens);
}

/* End tokenizer.c */
