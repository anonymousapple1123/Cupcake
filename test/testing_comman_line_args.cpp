#include <iostream>
#include <string>

int main(int argc, char *argv[]) {
  std::cout << "Program name: " << argv[0] << '\n';
  std::cout << "Argument count: " << argc << '\n';

  // Print all arguments
  for (int i = 1; i < argc; ++i)
    std::cout << "arg[" << i << "]: " << argv[i] << '\n';

  // Example: parse first argument as int (if present)
  if (argc > 1) {
    try {
      int x = std::stoi(argv[1]);
      std::cout << "Parsed integer: " << x << '\n';
    } catch (...) {
      std::cout << "First argument is not a valid integer\n";
    }
  }
  return 0;
}
