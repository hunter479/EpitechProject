/*
** EPITECH PROJECT, 2019
** ex00
** File description:
** Parser
*/

#include <stack>
#include <iostream>
#include "Parser.hpp"

static int isAnOperator(char a)
{
    if (a == ' ')
        return -1;
    if (a == '+' || a == '-' || a == '(')
        return (1);
    if (a == '*' || a == '/' || a == '%')
        return (2);
    return (-1);
}

static void pushOpe(std::string ope, std::stack<std::string> *list, int i)
{
    std::string tmp;

    tmp += ope[i];

    if (isAnOperator(ope[i]) != -1 && isAnOperator(ope[i]) != 3)
        list->push(tmp);
}

static std::string getNbr(const std::string &str, int &i)
{
    std::string nb;

    while (str[i] >='0' && str[i] <= '9') {
        nb += str[i];
        i++;
    };
    return (nb);
}

int do_op(int a, int b, char op)
{
    if (op == '+')
        return (a + b);
    if (op == '-')
        return (a - b);
    if (op == '*')
        return (a * b);
    if (op == '/')
        return (a / b);
    if (op == '%')
        return (a % b);
    return (0);
}

void reverse(std::stack<std::string> &number)
{
    std::stack<std::string> tmp;

    while (!number.empty()) {
        tmp.push(number.top());
        number.pop();
    }
    number = tmp;
}

void calc(std::stack<std::string> &number, char op, bool reverse)
{
    std::string tmp ;

    if (number.size() == 1)
        return;
    int a = std::stoi(number.top());
    number.pop();
    int b = std::stoi(number.top());
    number.pop();
    if (reverse == true)
        tmp = std::to_string(do_op(b, a, op));
    else
        tmp = std::to_string(do_op(a, b, op));
    number.push(tmp);
}

void Parser::feed(const std::string &str)
{
    std::stack<std::string> ope;
    std::stack<std::string> number;

    for (int i = 0; str[i] != '\0'; i++) {
        if (isAnOperator(str[i]) != -1)
                pushOpe(str, &ope, i);
        else if (str[i] >= '0' && str[i] <= '9') {
            number.push(getNbr(str, i));
            i--;
        }
        else if (str[i] == ')') {
            calc(number, ope.top()[0], true);
            ope.pop();
            ope.pop();
        }
    }
    reverse(number);
    reverse(ope);
    while (!ope.empty()) {
        calc(number, ope.top()[0], false);
        ope.pop();
    }
    _result += std::stoi(number.top());
}