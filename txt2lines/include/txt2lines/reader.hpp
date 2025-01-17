#ifndef _T2L_READER_HPP_
#define _T2L_READER_HPP_

#include "txt2lines/line.hpp"

#include <filesystem>
#include <fstream>
#include <regex>

namespace t2l {

namespace fs = std::filesystem;

class Reader {
 private:
  const fs::path path_to_file;
  const std::regex _skip_regex;
  std::ifstream _ifstream;
  std::size_t _line_counter;

 public:
  Reader(const char* path_to_file, const char* skip_regex = R"(^\s*$)");
  MaybeLine read_line();
};

}  // namespace t2l

#endif  //  _T2L_READER_HPP_
