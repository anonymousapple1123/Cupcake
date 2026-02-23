#include <iostream>
#include <fstream>
#include "../dependencies/json.hpp"

using json = nlohmann::json;

void extract_and_save_response(const std::string& json_file_path, const std::string& output_txt_path) {
    std::ifstream json_file(json_file_path);
    if (!json_file.is_open()) {
        std::cerr << "Could not open the JSON file!" << std::endl;
        return;
    }

    json data;
    try {
        json_file >> data;
    } catch (const json::parse_error& e) {
        std::cerr << "Failed to parse JSON: " << e.what() << std::endl;
        return;
    }

    std::string main_response;
    try {
        main_response = data["choices"][0]["message"]["content"];
    } catch (const json::exception& e) {
        std::cerr << "Failed to extract the main response: " << e.what() << std::endl;
        return;
    }

    std::ofstream txt_file(output_txt_path);
    if (txt_file.is_open()) {
        txt_file << main_response;
        std::cout << "The response has been saved to " << output_txt_path << "." << std::endl;
    } else {
        std::cerr << "Could not open the text file for writing!" << std::endl;
    }
}

int main() {

    extract_and_save_response("../codex_res/model_output.json", "response.txt");
    return 0;
}
