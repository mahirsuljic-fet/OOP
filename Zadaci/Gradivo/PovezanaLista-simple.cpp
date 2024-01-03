#include <iostream>

struct Node
{
    int podatak;
    Node* sljedeci; // pokazuje na sljedeci element u listi

    Node(int n) :
      podatak(n), sljedeci(nullptr) { }

    Node(int n, Node* p) :
      podatak(n), sljedeci(p) { }
};

void dodaj_element_kraj(Node*& glava, const int& n)
{
  // za slucaj kada je lista prazna
  // moramo napravit novu glavu liste
  // zbog ovog moramo proslijedit glavu po referenci
  if (glava == nullptr)
  {
    glava = new Node(n);
    return;
  }

  // dodji do zadnjeg elementa u listi
  // koristimo kopiju glave kako ne bi je pomjerili
  // jer je proslijedjena po referenci
  Node* it = glava;
  while (it->sljedeci != nullptr) it = it->sljedeci;

  // dodaj novi element na kraj liste
  it->sljedeci = new Node(n);
}

void dodaj_element_pocetak(Node*& glava, const int& n)
{
  // napravi novi node ciji je sljedeci glava,
  // sada je galva drugi element u listi
  Node* novi = new Node(n, glava);

  // da bi glava ostala pocetak liste
  // stavit cemo da je nas novi element glava
  // zbog ovog moramo proslijedit glavu po referenci
  glava = novi;
}

void printaj_listu(Node* glava)
{
  while (glava != nullptr)
  {
    std::cout << glava->podatak << std::endl;

    // glava je proslijedjena po vrijednosti
    // pa je smijemo pomijerati
    glava = glava->sljedeci;
  }
}

void izbrisi_listu(Node*& glava)
{
  while (glava != nullptr)
  {
    // moramo sacuvat podatak gdje smo u listi
    // jer ako izbrisemo element na kojem smo trenutno
    // necemo znati gdje se sljedeci element nalazi
    // ovdje je svejedno da li pomijeramo glavu ili
    // njenu kopiju jer svejedno brisemo listu
    Node* temp = glava->sljedeci;
    delete glava;
    glava = temp;
  }

  // oznacimo da je lista prazna
  glava = nullptr;
}

int main(int argc, char* argv[])
{
  Node* glava = nullptr;

  dodaj_element_kraj(glava, 1);
  dodaj_element_kraj(glava, 2);
  dodaj_element_pocetak(glava, 0);
  printaj_listu(glava);

  izbrisi_listu(glava);

  return 0;
}
