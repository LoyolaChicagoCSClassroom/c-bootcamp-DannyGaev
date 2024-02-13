#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "token.c"

int testCase(TOKEN returnToken, char* expectedType, char* expectedText);

int main(int argc, char *argv[])
{
    char testCaseNum[] = "1";
    char *token = generateSpaceless(testCaseNum);

    while(token != NULL) 
    {
        TOKEN returnToken = parseTokens(token);
        printf(testCase(returnToken,"Number","1")!=0 ? "Passed the test\n" : "Failed the test\n");
        token = strtok(NULL," ");
    }
    return EXIT_SUCCESS;
}



int testCase(TOKEN returnToken, char* expectedType, char* expectedText)
{

    return((resolveToString(returnToken.type_t)==expectedType && *returnToken.text==*expectedText) ? 1 : 0);

}