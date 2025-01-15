#ifndef _T2L_LINE_HPP_
#define _T2L_LINE_HPP_

#include <string>

namespace t2l {

struct MaybeLine;

struct Line {
  const std::size_t num;
  const std::string content;
  operator MaybeLine();
};

struct MaybeLine final : Line {
  operator bool();  // return true if line is not empty
};

}  // namespace t2l

#endif  // _T2L_LINE_HPP_
