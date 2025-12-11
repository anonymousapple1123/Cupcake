#include "file_writer.cpp"
#include <string>

int main(){
text_writer txt;
std::string file{"testfile.txt"};
std::string text{"help mee !!"};

txt.dump_buffer(file,text);
return 0;
}
