#include<stdio.h>
#include<stdlib.h>
#include<string.h>


void rev_string(char *string)
{
   char **tokens = NULL;

   /* Don't directly free tokens, call free_tokens instead */
   int num_tokens = tokenize(string, ' ', &tokens);

   if(NULL == tokens)
   {
      printf("Failed to tokenize string\n");
      return;
   }
   int i = 0;
   /* We have the tokens, print them in reverse now */
   //for(i = num_tokens-1; i >= 0; i--)
   for(i = 0; i < num_tokens; i++)
   {
      printf("<%s>", tokens[i]);
   }
   free_tokens(tokens, num_tokens);
   return;
}

int main()
{
   rev_string("Reverse this string please and if you do, you get the job.");
   rev_string("Oh, reverse this too");
   printf("\n");
}
