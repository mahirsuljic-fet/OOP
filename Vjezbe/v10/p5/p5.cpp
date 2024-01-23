#include "PrintLists.hpp"
#include <iostream>

namespace V10
{
namespace Details
{
  struct Node
  {
      std::string value;
      Node* next;
      ~Node()
      {
        std::cout << "Destroying: \"" << value << "\" value!" << std::endl;
      }
  };
}

class StringList
{
  public:
    StringList() = default;

    int size() const
    {
      return count_;
    }

    bool empty() const
    {
      return start_ == nullptr;
    }

    void pushFront(const std::string& s)
    {
      auto* newNode = new Details::Node { s, nullptr };
      ++count_;

      if (start_ == nullptr)
      {
        start_ = newNode;
        return;
      }

      newNode->next = start_;
      start_ = newNode;
    }

    void pushBack(const std::string& s)
    {
      auto* newNode = new Details::Node { s, nullptr };
      ++count_;

      if (start_ == nullptr)
      {
        start_ = newNode;
        return;
      }

      auto* walk = start_;
      while (walk->next != nullptr)
        walk = walk->next;

      walk->next = newNode;
    }

    void popFront()
    {
      if (start_ == nullptr) return;
      --count_;
      auto* next = start_->next;
      delete start_;
      start_ = next;
    }

    void popBack()
    {
      if (start_ == nullptr) return;

      --count_;

      if (start_->next == nullptr)
      {
        delete start_;
        start_ = nullptr;
        return;
      }

      auto* walk = start_;
      auto* stalk = start_;
      while (walk->next != nullptr)
      {
        stalk = walk;
        walk = walk->next;
      }

      stalk->next = nullptr;
      delete walk;
    }

    void print() const
    {
      auto* walk = start_;
      while (walk != nullptr)
      {
        std::cout << walk->value << std::endl;
        walk = walk->next;
      }
    }

    StringList(const StringList& other) : count_(0)
    {
      auto* walk = other.start_;
      Details::Node* prev = nullptr;

      while (walk != nullptr)
      {
        auto* newNode = new Details::Node { walk->value, nullptr };

        walk = walk->next;

        if (prev != nullptr)
          prev->next = newNode;

        if (start_ == nullptr)
          start_ = newNode;

        prev = newNode;
      }
    }

  private:
    Details::Node* start_ = nullptr;
    int count_ = 0;
};
}

// ako napravimo copy operator = brise se copy construktor koji kompajler napravi

int main(int argc, char* argv[])
{
  // Part1
  std::cout << "===============" << std::endl;
  std::cout << "List copy" << std::endl;
  V10::StringList lista1;
  lista1.pushBack("A");
  lista1.pushBack("B");

  V10::StringList lista2(lista1);
  lista2.pushBack("C");

  printLists(lista1, lista2);

  // // Part2
  // std::cout << "List copy assignment" << std::endl;
  // V10::StringList lista3;
  // lista3 = lista2;
  // lista1.popBack();
  // printLists(lista1, lista2, lista3);
  //
  //
  //
  // // Part 3
  // std::cout << "List move" << std::endl;
  // V10::StringList lista4(std::move(lista2));
  // printLists(lista4, lista2);
  //
  //
  //
  // // Part4
  // std::cout << "List move assignment" << std::endl;
  // lista1 = std::move(lista2);
  // printLists(lista1, lista2);

  return 0;
}
