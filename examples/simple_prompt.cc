#include "qupp/prompt/prompt.h"

#include <chrono>
#include <iostream>
#include <thread>

void display_prompt() { std::cout << "Prompt from qupp!" << std::endl; }

void move_cursor_down(int n) { std::cout << "\033[" << n << "B" << std::flush; }

void move_cursor_up(int n) { std::cout << "\033[" << n << "A" << std::flush; }

int main() {

  display_prompt();
  move_cursor_down(1);
  std::this_thread::sleep_for(std::chrono::seconds(1));
  move_cursor_up(1);
  std::this_thread::sleep_for(std::chrono::seconds(1));

  return 0;
}
