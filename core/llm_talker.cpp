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


    auto result = httplib::stream::Post( cli,
        "/v1/chat/completions",
                   body,
                   "application/json"
               );

    if(result){
        std::ofstream out("model_output.json");
        while (result.next()) {
                    //std::cout.write(result.data(), result.size()); //throws llm response to terminal
                    out << result.data();
        }
        out.close();
        }else{
            std::cerr << "Request error\n";
            return false; // Return false on error
        }
        std::cout << "Streaming completed." << std::endl; // Indicate streaming has finished
        return true;
    }
