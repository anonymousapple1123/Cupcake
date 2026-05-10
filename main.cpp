#include "core/cli_interface.hpp"
#include "core/file_parser.hpp"
#include "core/llm_talker.hpp"
#include <exception>
#include <iostream>

const int PARAMETERS{0};
const int QUANTIZATION{0};

int main(int argc, char *argv[]) {
  // Adding cli args later
  std::string model_name = model_switch(PARAMETERS, QUANTIZATION);
  // std::string model_name{"qwen2.5-coder"};

  std::string user_query = usr_query();

  if (!user_query.empty()) {
    std::cout << "\nGenerating..." << std::endl;
    try {
      talker(model_name, user_query);
    } catch (std::exception e) {
      std::cout << "Error in llm connection: " << e.what() << std::endl;
    }
    std::cout << "\nAttempting Parsing..." << std::endl;
    try {
      extract_and_save_response("model_output.json", "response.txt");
    } catch (std::exception e) {
      std::cout << "Error in parsing : " << e.what() << std::endl;
    }
  } else {
    std::cout << "Empty prompt: exiting..." << std::endl;
  }
  return 0;
}
