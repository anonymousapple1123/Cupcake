#include <iostream>
#include "llm_talker.cpp"

int main() {
    std::string model_name{"qwen3"};
    std::string user_query{"Write a python code to add 2 numbers"};
    //std::cout<<"\nModel :";
    //std::cin>>model_name;
    //std::cout<<"\nQuery to llm :";
    // std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    //std::getline(std::cin,user_query,';');
    talker(model_name, user_query);
    return 0;
}
