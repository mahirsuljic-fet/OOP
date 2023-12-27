#include <iostream>
#include <vector>

struct Node
{
    int num;
    Node* next;
};

void printNodes(Node* start)
{
  while (start != nullptr)
  {
    std::cout << start->num << std::endl;
    start = start->next;
  }
}

// Napisati funkciju createList koja treba da kreira 3 Node-a
// na heap-u i uveze ih koristeci pointer next. Za 'num'
// vrijednosti unutar svakog node-a staviti brojeve izmedju 10
// i 20.

Node* createList()
{
  Node* node3 = new Node { 19, nullptr };
  Node* node2 = new Node { 15, node3 };
  Node* node1 = new Node { 12, node2 };

  // NACIN SA VJEZBI:
  //
  // Node* n1 = new Node();
  // Node* n2 = new Node();
  // Node* n3 = new Node();
  //
  // n1->next = n2;
  // n1->n = 12;
  // n2->next = n2;
  // n2->n = 15;
  // n3->next = nullptr;
  // n3->n = 19;

  return node1;
}

// Napisati funkciju removeList koja uzima pocetak uvezanih
// cvorova te ih uklanja sa heap-a.

void removeList(Node* start)
{
  while (start != nullptr)
  {
    Node* temp = start->next;
    delete start;
    start = temp;
  }
}

int main(int argc, char* argv[])
{
  Node* list = createList();
  printNodes(list);
  removeList(list);

  return 0;
}
