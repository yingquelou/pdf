%{
#include "template.config.h"
#include <iostream>
%}
%option noyywrap noline
%x Nat
%s One Two
space [[:space:]]
alpha [[:alpha:]]
digit [[:digit:]]
xdigit [[:xdigit:]]
%%
<Two>{digit} {
    std::cout<<"digit\t"<<yytext<<'\n';
}
<One>{xdigit} {
    BEGIN Two;
    std::cout<<"xdigit\t"<<yytext<<'\n';
}

{alpha} {
    std::cout<<"alpha\t"<<yytext<<'\n';
}
<INITIAL>{space} {
    BEGIN One;
    std::cout<<"space"<<'\n';
}
