#include <cstdio>
#include <cctype>
#include <cstring>
#include <iostream>
#include "defs.h"
#include "data.h"


int next() {
    int c;

    if (Putback) {
        c = Putback;
        Putback = 0;
        return c;
    }

    c = fgetc(Infile);
    if ('\n' == c) {
        Line++;
    }

    return c;
}

void putback(int c) {
    Putback = c;
}

int skip() {
    int c;

    c = next();

    while (' ' == c || '\t' == c || '\n' == c || '\r' == c || '\f' == c) {
        c = next();
    }

    return (c);
}

long chrpos(char *s, int c) {
    char *p;

    p = strchr(s, c);
    return (p ? p - s : -1);
}

int scanint(int c) {
    int k;
    int val = 0;

    while ((k = chrpos("0123456789", c)) >= 0) {
        val = val * 10 + k;
        c = next();
    }

    putback(c);
    return val;
}


int scan(struct token *t) {
    int c;

    // Skip whitespace
    c = skip();

    switch (c) {
        case EOF:
            return (0);
        case '+':
            t->token = T_PLUS;
            break;
        case '-':
            t->token = T_MINUS;
            break;
        case '*':
            t->token = T_STAR;
            break;
        case '/':
            t->token = T_SLASH;
            break;
        default:
            if (isdigit(c)) {
                t->intvalue = scanint(c);
                t->token = T_INTLIT;
                break;
            }
    }

    return (1);
}


void scanfile() {
    char *tokstr[] = {"+", "-", "*", "/", "intlit"};

    struct token T{};

    while (scan(&T)) {
        std::cout << "token" << tokstr[T.token] << std::endl;

        if(T.token == T_INTLIT) {
            std::cout << T.intvalue << std::endl;
        }
    }

}