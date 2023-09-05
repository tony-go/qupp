🚧 **Disclaimer:** This project is currently under development and might not be production-ready.

# qupp

**qupp** is a lightweight library designed to simplify the user input prompt process in C++ applications.

## 🌟 Features

- 🎉 Simplified user input prompts.
- 🌍 Cross-platform (work in progress).
- 🛠️ CMake-friendly integration (work in progress)

## 📖 Usage

```cpp
#include <qupp/prompt/prompt.h>

int main() {
    qupp::prompt::Prompt prompt;
    std::string input = prompt.ask_for_input("What's your name? ");
    std::cout << "Hello, " << input << "!" << std::endl;
    return 0;
}
```

## 🤝 Contributing

### Building

1. Clone the repository:
   ```bash
   git clone https://github.com/tony-go/qupp.git
   ```
2. Build
   ```bash
   make
   ```

### 🧪 Testing

Tests are implemented using Google Test.

After building, run:
   ```bash
   make test
   ```

## 📜 License

MIT License. See `LICENSE` for more information.

