#include "dependencies/httplib.h"
#include <iostream>
#include <fstream>

static bool talker(std::string model_name, std::string user_query){
    httplib::Client cli("localhost", 11434);

    std::string body = R"({
        "model": ")" + model_name + R"(",
        "messages": [
            {"role": "user", "content": ")" + user_query + R"("}
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
