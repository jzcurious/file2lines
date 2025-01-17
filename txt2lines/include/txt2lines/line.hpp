#ifndef _T2L_LINE_HPP_
#define _T2L_LINE_HPP_

#include <string>

namespace t2l {

struct MaybeLine;

struct Line {
  std::size_t num;
  std::string content;
  operator MaybeLine();
  operator std::string();
};

struct MaybeLine final : Line {
  operator bool();  // return true if line is not empty
};

}  // namespace t2l

#endif  // _T2L_LINE_HPP_
