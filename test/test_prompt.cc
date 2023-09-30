#include "qupp/io/io.h"
#include "qupp/prompt/prompt.h"

#include <gtest/gtest.h>

#include <vector>

struct MockTerminal : public qupp::io::TerminalInterface {
  void print(const std::string &message, bool) override {
    messages_.push_back(message);
  }

  std::string read() override { return answer_; }

  void move_cursor_left(int n) override {}
  void move_cursor_right(int n) override {}
  void move_cursor_up(int n) override {}
  void move_cursor_down(int n) override {}

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

TEST(ask_for_input, happy_path) {
  std::string question = "This a question.";
  std::string answer = "This is an answer.";
  MockTerminal mock_terminal;
  mock_terminal.mock_answer(answer);

  qupp::prompt::Prompt prompt(mock_terminal);
  auto result = prompt.ask_for_input(question);

  EXPECT_EQ(result.value(), answer);
  EXPECT_TRUE(mock_terminal.has_printed(question));
}

TEST(ask_for_input, empty_question) {
  std::string empty_question = "";
  MockTerminal mock_terminal;

  qupp::prompt::Prompt prompt(mock_terminal);
  auto result = prompt.ask_for_input(empty_question);

  EXPECT_FALSE(result.has_value());
  EXPECT_FALSE(mock_terminal.has_printed(empty_question));
}
