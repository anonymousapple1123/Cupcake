#include "/dependencies/httplib.h"
#include <iostream>
#include <fstream>

bool talker(){
    httplib::Client cli("localhost", 8080);

    std::string body = R"({
            "model": "qwen-coder-2.5",
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
}
