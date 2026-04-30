#pragma once
#include "file_parser.hpp"
#include "llm_talker.hpp"
#include <iostream>

void display_start();
std::string model_selection();
std::string user_query();

std::string model_selection(const int b_parameters, const int k_quantized){
    //Some way to fetch model names from hugging face or ollama
    // For Now its hard coded.
    std::string model_name{"qwen2.5-coder"};
    return model_name;
}
