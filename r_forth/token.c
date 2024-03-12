#include <ctype.h>
#include <string.h>
#include "token.h"

char *generateSpaceless(char *input)
{
    char *token;
    token = strtok(input, " ");
    return token;
}

TOKEN parseTokens(char *token)
{
    TOKEN returnToken;

    if (*token == '+' || *token == '-' || *token == '*' || *token == '/')
        returnToken.type_t = ARITH_OP;

    else if (*token == ':' || *token == ';')
        returnToken.type_t = SYMB;

    else if (isdigit(*token) != 0)
        returnToken.type_t = NUM;

    else
        returnToken.type_t = WORD;

    returnToken.text = token;

    return returnToken;
}

char *resolveToString(enum token_type_t type_t)
{
    if (type_t == WORD)
        return "Word";

    else if (type_t == NUM)
        return "Number";

    else if (type_t == SYMB)
        return "Symbol";

    else if (type_t == ARITH_OP)
        return "Arithmetic Operator";

    return "NULL";
}
