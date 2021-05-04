#ifndef CONTAINER_HPP
#define CONTAINER_HPP

#include <iterator>

namespace diurdeva{
  class Container
  {
  public:
    Container() = default;
    class IteratorFact : public std::iterator<std::bidirectional_iterator_tag, size_t>
    {
    public:
      static const int MAX_POS = 11;
      static const int MIN_POS = 1;

      IteratorFact(size_t pos);

      const size_t& operator*() const;
      IteratorFact& operator++();
      IteratorFact operator++(int);
      IteratorFact& operator--();
      IteratorFact operator--(int);

      bool operator==(const IteratorFact& rhs) const;
      bool operator!=(const IteratorFact& rhs) const;
    private:
      size_t pos_;
      size_t value_;
      inline size_t factor(size_t number);
    };

    IteratorFact begin();
    IteratorFact end();
  };
}

#endif
