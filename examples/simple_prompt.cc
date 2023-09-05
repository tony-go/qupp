#include "qupp/prompt/prompt.h"

#include <iostream> // std::cout, std::endl

int main() {
  qupp::prompt::Prompt prompt;
  auto result = prompt.ask_for_input("This is a question:");
  if (result.has_value()) {
    std::cout << "You answered: " << result.value() << std::endl;
  } else {
    std::cout << "You did not answer." << std::endl;
  }

  return 0;
}
