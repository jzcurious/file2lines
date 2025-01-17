#include "txt2lines/reader.hpp"

using namespace t2l;

Reader::Reader(const char* path_to_file)
    : path_to_file(path_to_file)
    , skipping(false)
    , _skip_regex("")
    , _ifstream(path_to_file)
    , _line_counter(0) {}

Reader::Reader(const char* path_to_file, const char* skip_regex)
    : path_to_file(path_to_file)
    , skipping(true)
    , _skip_regex(skip_regex)
    , _ifstream(path_to_file)
    , _line_counter(0) {}

bool Reader::eof() const {
  return _ifstream.eof();
}

MaybeLine Reader::read_line() {
  for (std::string content = "";;) {
    if (eof()) return Line{0, ""};
    ++_line_counter;
    std::getline(_ifstream, content, '\n');
    if (not skipping or not std::regex_match(content, _skip_regex))
      return Line{_line_counter, content};
  }
}
