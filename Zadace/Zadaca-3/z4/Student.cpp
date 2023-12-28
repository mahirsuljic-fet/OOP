#include "Student.hpp"
#include <iostream>
#include <string>

void Student::ispisi_podatke() const
{
  std::cout << "Broj indeksa: " << this->broj_indeksa << std::endl
            << "Ime: " << this->ime << std::endl
            << "Prezime: " << this->prezime << std::endl
            << "Grad: " << this->grad
            << std::endl;
}

void Student::ispisi_ocjene() const
{
  if (this->ocjene.size() == 0) return;

  // std::cout << "Ocjene za " << this->ime << " " << this->prezime << ", " << this->brojIndeksa << std::endl;

  for (const auto& o : this->ocjene)
    std::cout << o.predmet->naziv << " -> " << o.ocjena << std::endl;
}

void Student::promijeni_broj_indeksa(std::string broj_indeksa)
{
  if (broj_indeksa.size() == 0 || broj_indeksa.find_first_not_of(' ') == std::string::npos)
    throw std::domain_error("Student ne moze imati prazan broj indeksa!");
  if (broj_indeksa.find(' ') != std::string::npos)
    throw std::domain_error("Broj indeksa ne moze biti sacinjen od vise rijeci!");

  this->broj_indeksa = broj_indeksa;
}

void Student::promijeni_ime(std::string ime)
{
  if (ime.size() == 0 || ime.find_first_not_of(' ') == std::string::npos)
    throw std::domain_error("Student ne moze imati prazno ime!");

  this->ime = ime;
}

void Student::promijeni_prezime(std::string prezime)
{

  if (prezime.size() == 0 || prezime.find_first_not_of(' ') == std::string::npos)
    throw std::domain_error("Student ne moze imati prazno prezime!");

  this->prezime = prezime;
}

void Student::promijeni_grad(std::string grad)
{
  if (grad.size() == 0 || grad.find_first_not_of(' ') == std::string::npos)
    throw std::domain_error("Student ne moze imati prazano polje grad!");

  this->grad = grad;
}

double Student::prosjek() const
{
  double prosjek = 0;

  for (auto o : this->ocjene)
    prosjek += o.ocjena;

  return prosjek / this->ocjene.size();
}
