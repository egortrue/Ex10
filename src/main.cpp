// Copyright 2021 Egor Trukhin
#include <iostream>
#include <string>
#include <vector>

#include "postfix.h"

int main() {
  std::vector<std::string> examples = {
      std::string("2 + 2"),
      std::string("2 + 6 * 3 / (4 - 2)"),
      std::string("(2 + 8.3) * (6 - 3.2)"),
      std::string("(6 * (4 - 2) + 5) * (2.6 + 3 * 7) - 9"),
  };

  for (auto expr : examples) {
    std::cout << "Expression:" << std::endl;
    std::cout << "  Infix: " << expr << std::endl;
    std::cout << "  Postfix: " << infix2postfix(expr) << std::endl;
    std::cout << std::endl;
  }
  return 0;
}
