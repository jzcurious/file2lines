#include "txt2lines/reader.hpp"

using namespace t2l;

Reader::Reader(const char* path_to_file, const char* skip_regex)
    : path_to_file(path_to_file)
    , skip_regex(skip_regex)
    , _ifstream(path_to_file)
    , _line_counter(0) {}

bool Reader::eof() const {
  return _ifstream.eof();
}

MaybeLine Reader::read_line() {
  std::string content = "";

  for (; not eof(); ++_line_counter) {
    std::getline(_ifstream, content, '\n');
    if (not std::regex_match(content, skip_regex)) break;
  }

  return Line{_line_counter, content};
}
