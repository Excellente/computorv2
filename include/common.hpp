#ifndef LIB_HPP
#define LIB_HPP

#define TOK_LP '('
#define TOK_RP ')'
#define TOK_LSB '['
#define TOK_RSB ']'
#define TOK_EQ '='
#define TOK_QM '?'
#define TOK_CO ','
#define TOK_SC ';'
#define TOK_OA '+'
#define TOK_OS '-'
#define TOK_OD '/'
#define TOK_OM '*'
#define TOK_DP '.'

#define _EOF_ "^\0"
#define BUFF_SIZE 1024
#define __sqrt(x) sqrt(x)

#include <map>
#include <regex>
#include <vector>
#include <string>
#include <math.h>
#include <stdio.h>
#include <iostream>

using namespace std;

bool isalpha(char c);
bool isname(string &s);
bool isnumber(string &s);
string tolower(string s);
bool iswhitespace(char c);
string _substr(string l, int s, int e);

typedef vector<string>::iterator mapit_t;

static vector<string> strsplit(string del, string _exp)
{
    int len;
    size_t pos;
    vector<int> delpos;
    vector<string> terms;

    len = 0;
    for (int i = 0; i != string::npos;)
    {
        delpos.push_back((i = _exp.find(del, i + 1)));
        len++;
    }
    terms.push_back(_exp.substr(0, delpos[0]));
    for (int i = 1; i < len; i++)
        terms.push_back(_exp.substr(delpos[i - 1] + 1, (delpos[i] - delpos[i - 1]) - 1));
    return (terms);
}

#endif