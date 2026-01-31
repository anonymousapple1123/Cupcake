#include "dependencies/httplib.h"
#include <iostream>
#include <fstream>

static bool talker(){
    httplib::Client cli("localhost", 5000);

    std::string body = R"({
            "model": "qwen2.5-coder",
            "messages": [
                {"role":"user", "content":"Write a C++ function to check if a number is prime."}
            ]
        })";

    auto res = cli.Post(
            "/v1/chat/completions",
            body,
            "application/json"
        );

        if (!res) {
            std::cerr << "Request error\n";
            return 1;
        }
        std::ofstream out("model_output.json");
            out << res->body;
            out.close();

            return true;
}
