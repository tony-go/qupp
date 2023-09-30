#include "qupp/io/io.h"

#include <iostream> // std::cout, std::endl

namespace qupp::io {
Terminal &Terminal::get_instance() {
  static Terminal instance;
  return instance;
}

void Terminal::print(const std::string &message, bool break_line) {
  std::cout << message;
  if (break_line) {
    std::cout << std::endl;
  }
}

void Terminal::move_cursor_left(int n) { std::cout << "\033[" << n << "D"; }
void Terminal::move_cursor_right(int n) { std::cout << "\033[" << n << "C"; }
void Terminal::move_cursor_up(int n) { std::cout << "\033[" << n << "A"; }
void Terminal::move_cursor_down(int n) { std::cout << "\033[" << n << "B"; }

std::string Terminal::read() {
  std::string input;
  std::cin >> input;
  return input;
}
} // namespace qupp::io
