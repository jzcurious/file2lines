#include "txt2lines/line.hpp"
#include "txt2lines/reader.hpp"
#include <gtest/gtest.h>
#include <string>

static const char* src_path = "../../assets/tests.udl";

TEST(Reader, read_line) {
  auto r1 = t2l::Reader(src_path);
  auto r2 = t2l::Reader(src_path);
  auto istream = std::ifstream(src_path);

  std::vector<std::string> lines1;
  std::vector<std::string> lines2;

  auto mline = t2l::MaybeLine{};

  // TODO: conv to string
  // TODO: eof()

  do {
    mline = r1.read_line();
    if (mline) lines1.push_back(mline.content);
  }
  while (mline);

  auto ifstream = std::ifstream(src_path);
  std::string string;

  while (not ifstream.eof()) {
    std::getline(ifstream, string, '\n');
    if (not std::regex_match(string, std::regex(R"(^\s*$)"))) lines2.push_back(string);
  }

  EXPECT_EQ(lines1, lines2);
}
