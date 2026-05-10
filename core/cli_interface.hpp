#pragma once
#include <iostream>

// void display_help();
// std::string model_switch(const int, const int);
// std::string usr_query();

std::string model_switch(const int b_parameters, const int k_quantized) {
  // Some way to fetch model names from hugging face or ollama
  //  For Now its hard coded.
  std::string model_name{"qwen2.5-coder"};
  return model_name;
}

std::string usr_query() {
  std::string query = "";
  std::cout << "\nPress Enter to input prompt..." << std::endl;
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  std::cout << ">>";
  std::getline(std::cin, query, ';');
  query.erase(query.find_last_not_of(" \n\r\t") + 1);
  return query;
}

void display_help() {
  std::cout << "**************** Custom LLM ****************";
  std::cout << "-h , --help [Display help for terminal commands]";
  std::cout << "-v , --verbose [Display steps on the terminal]";
}
