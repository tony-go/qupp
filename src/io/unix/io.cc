#include "qupp/io/io.h"

#include <iostream> // std::cout, std::endl

namespace qupp::io {
Terminal &Terminal::get_instance() {
  static Terminal instance;
  return instance;
}

void Terminal::print(const std::string &message) {
  std::cout << message << std::endl;
}

std::string Terminal::read() {
  std::string input;
  std::cin >> input;
  return input;
}
} // namespace qupp::io
