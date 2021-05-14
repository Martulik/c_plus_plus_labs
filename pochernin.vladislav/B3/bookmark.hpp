#ifndef BOOKMARK_HPP
#define BOOKMARK_HPP

#include <string>
#include <iostream>

namespace pochernin
{
  struct Bookmark
  {
    std::string name;
  };
  bool operator<(const Bookmark& lhs, const Bookmark& rhs);
  std::istream& operator>>(std::istream& in, Bookmark& bookmark);
}

#endif
