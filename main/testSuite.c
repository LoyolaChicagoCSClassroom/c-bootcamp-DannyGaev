#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "token.c"

void tester(char* testCase, char* expectedType, char* expectedText);

int main(int argc, char *argv[])
{
    char* testWord = "hello";
    tester(testWord,"Word","hello");

    char* testNum = "1";
    tester(testNum,"Number","1");

    char* testOp = "+";
    tester(testOp,"Arithmetic Operator","+");

    char* testSym = ";";
    tester(testSym,"Symbol",";");
   
    return EXIT_SUCCESS;
}



void tester(char* testCase, char* expectedType, char* expectedText)
{
    char *token = generateSpaceless(testCase);

    while(token != NULL) 
    {   
        TOKEN returnToken = parseTokens(token);
        printf((resolveToString(returnToken.type_t)==expectedType && returnToken.text==expectedText) ? "Passed the test ☑\n" : "Failed the test ☒\n");
        token = strtok(NULL," ");
    }
    
}