#include "core/cli_interface.hpp"
#include "core/file_parser.hpp"
#include "core/llm_talker.hpp"
#include <exception>
#include <iostream>

const int PARAMETERS{0};//not implemeted yet, looks like i was testing the model selection process
                        // It appears I have no way to get model name(without huggingface API) and the
                        // user had to input the name of the model.
                        // Probably need to Implement the API Calls later for now I must hard code some model names.
const int QUANTIZATION{0}; // And yes i dunno how this will work for hard coded version. :/

int main(int argc, char *argv[]) {
  // Adding cli args later
  bool verbose = false;
  for (int i = 1; i< argc; ++i){
      std::string arg  = argv[i];
      if(arg == "-v" || "--verbose"){
          verbose = true;
      }else{
          std::cout<<"Unknown option: "<<arg<<std::endl;
      }
  }
  std::string model_name = model_switch(PARAMETERS, QUANTIZATION);
  // std::string model_name{"qwen2.5-coder"};

  std::string user_query = usr_query();

  if (!user_query.empty()) {
    if(verbose){
        std::cout << "\nGenerating..." << std::endl;
    }
    try {
      talker(model_name, user_query);
    } catch (std::exception e) {
      std::cout << "Error in llm connection: " << e.what() << std::endl;
    }
    if(verbose){
        std::cout << "\nAttempting Parsing..." << std::endl;
    }
    try {
      extract_and_save_response("model_output.json", "response.txt");
    } catch (std::exception e) {
      std::cout << "Error in parsing : " << e.what() << std::endl;
    }
  } else {
    if(verbose){
        std::cout << "Empty prompt: exiting..." << std::endl;
    }
  }
  return 0;
}
