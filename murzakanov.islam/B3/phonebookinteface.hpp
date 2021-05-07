#ifndef PHONE_BOOK_INTERFACE_HPP
#define PHONE_BOOK_INTERFACE_HPP

#include <memory>
#include <map>
#include <string>
#include "phone-book.hpp"

namespace murzakanov
{
  class BookInterface
  {
  public:
    using note_t = murzakanov::PhoneBook::note_t;
    using iteratorType = std::map< std::string, murzakanov::PhoneBook::iterator >::iterator;
    explicit BookInterface(PhoneBook& book);
    void add(const note_t& note);
    void store(const std::string& bookmark, const std::string& newBookmark, std::ostream& out);
    void insertBefore(const std::string& bookmark, const note_t& note, std::ostream& out);
    void insertAfter(const std::string& bookmark, const note_t& note, std::ostream& out);
    void deleteNote(const std::string& bookmark, std::ostream& out);
    void show(const std::string& bookmark, std::ostream& out);
    void move(const std::string& bookmark, int steps, std::ostream& out);
    void move(const std::string& bookmark, const std::string& keyWord, std::ostream& out);
  private:
    std::unique_ptr< murzakanov::PhoneBook > book_;
    std::map< std::string, murzakanov::PhoneBook::iterator > bookmarks_;
  };
}

#endif
