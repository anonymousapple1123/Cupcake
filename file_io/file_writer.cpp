#include "file_writer.hpp"
#include <iostream>
#include <fstream>

bool text_writer::dump_buffer(const std::string& file_name, const std::string& buffer ){
    std::fstream file(file_name, std::ios::app);

    if(!file){
        std::cerr<<"dump_buffer : Unable to open file";
        return false;
    }
    file<<buffer;
    return true;
}

bool text_writer::read_file(const std::string& file_name){
    std::fstream file(file_name, std::ios::in);
    if(!file){
        std::cerr<<"read_file : Unable to readfile.";
        return false;
    }
   std::string text;
    while(std::getline(file,text)){
        std::cout<<text<<'\n';
    }
    return true;

}
