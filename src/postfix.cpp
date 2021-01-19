// Copyright 2021 Egor Trukhin
#include "postfix.h"

bool isNumber(char symb) { return (('0' <= symb && symb <= '9')); }

std::string infix2postfix(const std::string infix) {
  std::string result;
  MyStack<char> stack;

  std::map<char, int> priority = {{'(', 0}, {')', 1}, {'+', 2},
                                  {'-', 2}, {'*', 3}, {'/', 3}};

  for (auto symbol : infix) {
    if (symbol == ' ') continue;

    if (isNumber(symbol) || symbol == '.') {
      result += symbol;
      continue;
    }

    if (result.length() != 0) {
      char last = result[result.length() - 1];
      if (isNumber(last)) {
        result += ' ';
      }
    }

    if (stack.isEmpty()) {
      stack.push(symbol);
      continue;
    } else if ((symbol == '(') || (priority[symbol] > priority[stack.get()])) {
      stack.push(symbol);
      continue;
    }

    if (symbol == ')') {
      while (!stack.isEmpty() && stack.get() != '(') {
        result += stack.pop();
        result += ' ';
      }
      if (!stack.isEmpty()) stack.pop();
      continue;
    }

    while (!stack.isEmpty() && (priority[symbol] <= priority[stack.get()])) {
      result += stack.pop();
      result += ' ';
    }

    stack.push(symbol);
  }

  char last = result[result.length() - 1];
  if (isNumber(last)) result += ' ';

  while (!stack.isEmpty()) {
    result += stack.pop();
    result += ' ';
  }

  result.pop_back();
  return result;
}
