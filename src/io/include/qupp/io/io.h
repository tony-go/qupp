#pragma once

#include <string>

namespace qupp::io {
struct TerminalInterface {
  virtual ~TerminalInterface() = default;

  virtual void print(const std::string &message, bool break_line) = 0;
  virtual std::string read() = 0;
  virtual void move_cursor_left(int n) = 0;
  virtual void move_cursor_right(int n) = 0;
  virtual void move_cursor_up(int n) = 0;
  virtual void move_cursor_down(int n) = 0;
};

struct Terminal : public TerminalInterface {
  static Terminal &get_instance();

  void print(const std::string &message, bool break_line);
  std::string read();
  void move_cursor_left(int n);
  void move_cursor_right(int n);
  void move_cursor_up(int n);
  void move_cursor_down(int n);

private:
  // This is a key part of the Singleton Pattern; it prevents the creation of
  // additional instances.
  Terminal() = default;
  Terminal(const Terminal &) = delete;
  Terminal &operator=(const Terminal &) = delete;
};
} // namespace qupp::io
