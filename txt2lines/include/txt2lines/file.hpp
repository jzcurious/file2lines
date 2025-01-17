#ifndef _T2L_FILE_HPP_
#define _T2L_FILE_HPP_

#include <filesystem>
#include <fstream>

namespace t2l {

namespace fs = std::filesystem;

struct File {
 public:
  const fs::path path;

 private:
  std::ifstream _ifstream;

 public:
  File(const char* path);
  File(const std::string& path);
  fs::path full_path() const;
  std::string get_chunk(const char delim = '\n');
};

}  // namespace t2l

#endif  // _T2L_FILE_HPP_
