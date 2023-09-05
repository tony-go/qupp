#pragma once

#include <qupp/io/io.h>

#include <optional>
#include <string>

namespace qupp::prompt {

using StringResult = std::optional<std::string>;

struct Prompt {
  // The explicit keyword is used to avoid implicit conversions.
  Prompt(qupp::io::TerminalInterface &terminal =
             qupp::io::Terminal::get_instance());

  StringResult ask_for_input(const std::string &message);

private:
  qupp::io::TerminalInterface &terminal_;
};
} // namespace qupp::prompt
