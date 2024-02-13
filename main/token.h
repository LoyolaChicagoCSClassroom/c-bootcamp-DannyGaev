#ifndef TOKEN_H
#define TOKEN_H

struct token_t;

enum token_type_t {
    NUM,
    ARITH_OP,
    SYMB,
    WORD
} type_t;

typedef struct token_t {
    enum token_type_t type_t;
    char *text;
} TOKEN;

extern TOKEN parseTokens(char *token);

#endif