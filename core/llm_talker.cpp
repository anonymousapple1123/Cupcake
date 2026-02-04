#include "../dependencies/httplib.h"
#include "../dependencies/json.hpp"
#include <iostream>
#include <fstream>

using json = nlohmann::json;

static bool talker(std::string& model_name, std::string& user_query){
    httplib::Client cli("localhost", 11434);

    json body_json;

    body_json["model"] = model_name;
    body_json["messages"] = json::array({
        {
            {"role", "user"},
            {"content", user_query}
        }
    });

    std::string body = body_json.dump();


    auto res = cli.Post(
            "/v1/chat/completions",
            body,
            "application/json"
        );

        if (!res) {
            std::cerr << "Request error\n";
            return 1;
        }
        // future me : add linearly progressable names for the json files
        std::ofstream out("model_output.json");
            out << res->body;
            out.close();

            return true;
}
