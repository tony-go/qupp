#include "qupp/io/io.h"
#include "qupp/prompt/prompt.h"

#include <gtest/gtest.h>

#include <cassert>
#include <vector>

struct MockTerminal : public qupp::io::TerminalInterface {
  void print(const std::string &message) override {
    messages_.push_back(message);
  }

  std::string read() override { return answer_; }

  // Test helper function.

  bool has_printed(const std::string &message) {
    return std::find(messages_.begin(), messages_.end(), message) !=
           messages_.end();
  }

  void mock_answer(const std::string &answer) { answer_ = answer; }

private:
  std::vector<std::string> messages_;
  std::string answer_;
};

TEST(prompt, ask_for_input) {
  std::string question = "This a question.";
  std::string answer = "This is an answer.";
  MockTerminal mock_terminal;
  mock_terminal.mock_answer(answer);

  qupp::prompt::Prompt prompt(mock_terminal);
  auto result = prompt.ask_for_input(question);

  EXPECT_EQ(result, answer);
  EXPECT_TRUE(mock_terminal.has_printed(question));
}
