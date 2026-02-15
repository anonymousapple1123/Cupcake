#include "core/llm_talker.cpp"
#include <iostream>

int main() {
  std::string model_name{"qwen2.5-coder"};
  std::string user_query;
  // std::cout<<"\nModel :";
  // std::cin>>model_name;
  std::cout << "\nPress Enter to input prompt..." << std::endl;
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  std::cout << ">>";
  std::getline(std::cin, user_query, ';');
  user_query.erase(user_query.find_last_not_of(" \n\r\t") + 1);
  if (!user_query.empty()) {
    std::cout << "\ngenerating..." << std::endl;
    talker(model_name, user_query);
  } else {
    std::cout << "Empty prompt: exiting..." << std::endl;
  }
  return 0;
}
