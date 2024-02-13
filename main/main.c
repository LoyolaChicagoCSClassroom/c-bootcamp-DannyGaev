#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "token.c"

int main(int argc, char *argv[])
{
    char *token = generateSpaceless(argv[1]);
    
    while(token != NULL) 
    {
        TOKEN returnToken = parseTokens(token);
        printf("CLASS: %s, TEXT: %s\n",resolveToString(returnToken.type_t),returnToken.text);
        token = strtok(NULL," ");
    }
    return EXIT_SUCCESS;
}