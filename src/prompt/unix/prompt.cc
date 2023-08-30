#include "qupp/prompt/prompt.h"

#include <iostream> // std::cout, std::endl
#include <string>   // std::string

namespace qupp::prompt {
Prompt::Prompt(qupp::io::TerminalInterface &terminal) : terminal_(terminal) {}

std::string Prompt::ask_for_input(const std::string &question) {
  terminal_.print(question);
  return terminal_.read();
}
} // namespace qupp::prompt
