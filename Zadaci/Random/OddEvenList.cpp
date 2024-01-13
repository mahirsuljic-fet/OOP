#include <iostream>
#include <string>
#include <vector>

struct ListNode
{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) { }
    ListNode(int x) : val(x), next(nullptr) { }
    ListNode(int x, ListNode* next) : val(x), next(next) { }
};

void insertNode(ListNode* pre_location, ListNode* pre_node)
{
  ListNode* node = pre_node->next;
  pre_node->next = node->next;

  node->next = pre_location->next;
  pre_location->next = node;
}

void printList(ListNode* head)
{
  std::cout << "List: ";
  for (; head != nullptr; head = head->next) std::cout << head->val << " ";
  std::cout << std::endl;
}

void vectorToList(ListNode* head, std::vector<int> vec)
{
  if (vec.size() == 0) return;

  head->val = vec[0];
  for (int i = 1; i < vec.size(); i++)
  {
    head->next = new ListNode(vec[i]);
    head = head->next;
  }
}

ListNode* oddEvenList(ListNode* head)
{
  if (head == nullptr) return head;

  ListNode* oddSearch = head->next;
  ListNode* headCopy;
  unsigned short numElements = 0;

  for (headCopy = head; headCopy != nullptr; headCopy = headCopy->next) numElements++;

  headCopy = head;
  unsigned short iters = numElements % 2 ? numElements / 2 : numElements / 2 - 1;
  delete (&numElements);

  for (unsigned short i = 0; i < iters; i++)
  {
    ListNode* oddCopy = oddSearch;
    oddSearch = oddSearch->next->next;

    insertNode(headCopy, oddCopy);

    headCopy = headCopy->next;
  }

  return head;
}

int main(int argc, char* argv[])
{
  ListNode* head = new ListNode();

  // vectorToList(head, std::vector<int> { 1, 2, 3, 4, 5 });
  vectorToList(head, std::vector<int> { 1, 2, 3, 4, 5, 6, 7, 8 });
  printList(head);
  oddEvenList(head);
  printList(head);

  return 0;
}
