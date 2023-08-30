#pragma once

#include <string>

namespace qupp::io {
struct TerminalInterface {
  virtual ~TerminalInterface() = default;

  virtual void print(const std::string &message) = 0;
  virtual std::string read() = 0;
};

struct Terminal : public TerminalInterface {
  static Terminal &get_instance();

  void print(const std::string &message);
  std::string read();

private:
  // This is a key part of the Singleton Pattern; it prevents the creation of
  // additional instances.
  Terminal() = default;
  Terminal(const Terminal &) = delete;
  Terminal &operator=(const Terminal &) = delete;
};
} // namespace qupp::io
