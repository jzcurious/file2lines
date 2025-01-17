#include "txt2lines/file.hpp"
#include <filesystem>

using namespace t2l;

File::File(const char* path)
    : path(path)
    , _ifstream(path) {}

File::File(const std::string& path)
    : path(path)
    , _ifstream(path) {}

fs::path File::full_path() const {
  return fs::canonical(path);
}

std::string File::get_chunk(const char delim) {
  std::string chunk;
  std::getline(_ifstream, chunk, delim);
  return chunk;
}
