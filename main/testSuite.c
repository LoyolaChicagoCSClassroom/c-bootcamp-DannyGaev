#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "token.c"

void testCase(TOKEN returnToken, char* expectedType, char* expectedText);

int main(int argc, char *argv[])
{


    char testCaseNum[] = "1";
    char *token = generateSpaceless(testCaseNum);
    while(token != NULL) 
    {
        TOKEN returnToken = parseTokens(token);
        testCase(returnToken,"Number","1");
        token = strtok(NULL," ");
    }

    char testCaseWord[] = "num";
    token = generateSpaceless(testCaseWord);
    while(token != NULL) 
    {
        TOKEN returnToken = parseTokens(token);
        testCase(returnToken,"Word","num");
        token = strtok(NULL," ");
    }

    char testCaseArithOp[] = "+";
    token = generateSpaceless(testCaseArithOp);
    while(token != NULL) 
    {
        TOKEN returnToken = parseTokens(token);
        testCase(returnToken,"Arithmetic Operator","+");
        token = strtok(NULL," ");
    }

    char testCaseSymbol[] = ":";
    token = generateSpaceless(testCaseSymbol);
    while(token != NULL) 
    {
        TOKEN returnToken = parseTokens(token);
        testCase(returnToken,"Symbol",":");
        token = strtok(NULL," ");
    }


    return EXIT_SUCCESS;
}



void testCase(TOKEN returnToken, char* expectedType, char* expectedText)
{
    printf((resolveToString(returnToken.type_t)==expectedType && *returnToken.text==*expectedText) ? "Passed the test\n" : "Failed the test\n");
}