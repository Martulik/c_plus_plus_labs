#include "phone-book.hpp"

namespace shilyaev {
  PhoneBook::Iterator PhoneBook::insertAfter(PhoneBook::Iterator iterator, const PhoneBook::Entry& entry)
  {
    return entries_.insert(++iterator, entry);
  }

  PhoneBook::Iterator PhoneBook::insertBefore(PhoneBook::Iterator iterator, const PhoneBook::Entry& entry)
  {
    return entries_.insert(iterator, entry);
  }

  PhoneBook::Iterator PhoneBook::move(PhoneBook::Iterator iterator, int n)
  {
    for (int i = 0; i < n; ++i) {
      ++iterator;
    }
    for (int i = 0; i > n; --i) {
      --iterator;
    }
    return iterator;
  }

  PhoneBook::Iterator PhoneBook::pushBack(const PhoneBook::Entry& entry)
  {
    entries_.push_back(entry);
    return --entries_.end();
  }

  size_t PhoneBook::size() const
  {
    return entries_.size();
  }

  PhoneBook::Iterator PhoneBook::erase(PhoneBook::Iterator iterator)
  {
    return entries_.erase(iterator);
  }

  bool PhoneBook::empty() const
  {
    return entries_.empty();
  }

  PhoneBook::Iterator PhoneBook::begin()
  {
    return entries_.begin();
  }

  PhoneBook::Iterator PhoneBook::end()
  {
    return entries_.end();
  }
}
