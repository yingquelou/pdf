%{
#include"template.config.h"
%}
%language "c++"
%no-lines
%define api.token.constructor
%define api.value.type variant

%token <std::string> STR

%start start
%%
start:
;
