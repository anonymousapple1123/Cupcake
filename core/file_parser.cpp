#include <iostream>
#include <fstream>
#include "../dependencies/json.hpp"
using json = nlohmann::json;
int main() {
    // Reading JSON
    std::ifstream inputFile("data.json");
    json jsonData;

    if (inputFile.is_open()) {
        inputFile >> jsonData;
        inputFile.close();
    } else {
        std::cerr << "Could not open the file!" << std::endl;
        return 1;
    }

    if (jsonData.contains("name")) {
        std::cout << "Name: " << jsonData["name"] << std::endl;
    }

    std::ofstream outputFile("output.txt");

    if (outputFile.is_open()) {
        outputFile << jsonData.dump(4);
        outputFile.close();
    } else {
        std::cerr << "Could not open the output file!" << std::endl;
        return 1;
    }

    std::cout << "Data has been successfully written to output.txt" << std::endl;
    return 0;
}
