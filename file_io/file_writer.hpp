# pragma once
#include <string>
class text_writer{
  public:

        static inline bool dump_buffer(const std::string& file_name, const std::string& buffer );
        static inline bool read_file(const std::string& file_name);
};
