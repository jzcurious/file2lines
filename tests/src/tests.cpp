#include "txt2lines/line.hpp"
#include "txt2lines/reader.hpp"
#include <gtest/gtest.h>
#include <string>

static const char* src_path = "../../assets/tests.udl";

TEST(Reader, read_line) {
  auto reader = t2l::Reader(src_path);
  auto istream = std::ifstream(src_path);

  std::vector<std::string> lines1;
  std::vector<std::string> lines2;

  for (t2l::MaybeLine mline; not reader.eof();) {
    mline = reader.read_line();
    if (mline) lines1.push_back(mline.content);
  }

  auto ifstream = std::ifstream(src_path);
  for (std::string str; not ifstream.eof();) {
    std::getline(ifstream, str, '\n');
    lines2.push_back(str);
  }

  EXPECT_EQ(lines1, lines2);
}

TEST(Reader, read_line_skipping) {
  auto reader = t2l::Reader(src_path, R"(^\s*$)");
  auto istream = std::ifstream(src_path);

  std::vector<std::string> lines1;
  std::vector<std::string> lines2;

  for (t2l::MaybeLine mline; not reader.eof();) {
    mline = reader.read_line();
    if (mline) lines1.push_back(mline.content);
  }

  auto ifstream = std::ifstream(src_path);
  for (std::string str; not ifstream.eof();) {
    std::getline(ifstream, str, '\n');
    if (not std::regex_match(str, std::regex(R"(^\s*$)"))) lines2.push_back(str);
  }

  EXPECT_EQ(lines1, lines2);
}
