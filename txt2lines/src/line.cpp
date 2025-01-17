#include "txt2lines/line.hpp"

using namespace t2l;

MaybeLine::operator bool() {
  return content.size() or num;
}

Line::operator MaybeLine() {
  return MaybeLine{num, content};
}

Line::operator std::string() {
  return content;
}
