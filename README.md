# txt2lines
A tiny library for line-by-line reading of text files

### Sample

```
#include <iostream>
#include <txt2lines/reader.hpp>

static void print_txt_with_enumeration(const char* path_to_file) {
  auto reader = t2l::Reader(path_to_file);

  for (t2l::MaybeLine mline; not reader.eof();) {
    mline = reader.read_line();
    std::cout << mline.num << "  " << mline.content << std::endl;
  }
}

int main() {
  print_txt_with_enumeration("../../assets/tests.udl");
  return (0);
}

```
