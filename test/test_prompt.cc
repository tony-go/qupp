#include "qupp/io/io.h"
#include "qupp/prompt/prompt.h"

#include <cassert>

struct MockTerminal : public qupp::io::TerminalInterface {
  void print(const std::string &message) override {}

  std::string read() override { return "answer"; }
};

int main() {
  MockTerminal mock_terminal;
  qupp::prompt::Prompt prompt(mock_terminal);

  assert(prompt.ask_for_input("This a question.") == "answer");

  return 0;
}
