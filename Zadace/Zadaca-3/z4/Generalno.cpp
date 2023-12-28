#include "Generalno.hpp"
#include "BazaPredmeta.hpp"
#include "BazaStudenata.hpp"
#include "Ocjena.hpp"
#include <iostream>
#include <limits>
#include <stdexcept>
#include <string>

#define BROJ_IZBORA_STUDENT 8

namespace ms
{
BazaStudenata baza_studenata;
BazaPredmeta baza_predmeta;
}

void provjeri_handle_nevalidan_unos()
{
  if (std::cin.fail())
  {
    if (std::cin.eof())
    {
      std::cout << std::endl;

      std::cin.clear();
      std::clearerr(stdin);

      throw std::runtime_error("Detektovan EOF karakter!");
    }

    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    throw std::runtime_error("Unos nije validan!");
  }
}

void unos_studenta()
{
  std::string ime, prezime, brojIndeksa, grad;

  std::cout << "\nUNOS STUDENTA\n\n";

  std::cout << "Broj indeksa: ";
  std::getline(std::cin, brojIndeksa);
  std::cout << "Ime: ";
  std::getline(std::cin, ime);
  std::cout << "Prezime: ";
  std::getline(std::cin, prezime);
  std::cout << "Grad: ";
  std::getline(std::cin, grad);

  try
  {
    provjeri_handle_nevalidan_unos();
    ms::baza_studenata.dodaj_studenta(brojIndeksa, ime, prezime, grad);
    std::cout << "\nStudent uspjesno unesen!\n\n";
  }
  catch (std::domain_error err)
  {
    std::cout << std::endl
              << err.what() << "\n\n";
  }
  catch (std::runtime_error err)
  {
    std::cout << std::endl
              << err.what() << "\n\n";
  }
}

void unos_predmeta()
{
  std::string naziv, odsjek;
  std::cout << "\nUNOS PREDMETA\n\n";

  std::cout << "Naziv: ";
  std::getline(std::cin, naziv);
  std::cout << "Odsjek: ";
  std::getline(std::cin, odsjek);

  try
  {
    provjeri_handle_nevalidan_unos();
    ms::baza_predmeta.dodaj_predmet(naziv, odsjek);
    std::cout << "\nPredmet uspjesno unesen!\n\n";
  }
  catch (std::domain_error err)
  {
    std::cout << std::endl
              << err.what() << "\n\n";
  }
  catch (std::runtime_error err)
  {
    std::cout << std::endl
              << err.what() << "\n\n";
  }
}

void studenti_podaci()
{
  try
  {
    std::cout << std::endl;
    ms::baza_studenata.ispis();
  }
  catch (std::runtime_error err)
  {
    std::cout << std::endl
              << err.what() << "\n\n";
  }
}

void studenti_ocjene()
{
  try
  {
    std::cout << std::endl;
    ms::baza_studenata.ispis_full();
  }
  catch (std::runtime_error err)
  {
    std::cout << std::endl
              << err.what() << "\n\n";
  }
}

void prosjek()
{
  try
  {
    auto prosjek_predmeti = ms::baza_studenata.prosjek_predmeti();

    std::cout << "\nPROSJEK\n\n"
                 "Ukupni prosjek: "
              << ms::baza_studenata.prosjek_ukupni() << std::endl
              << "Prosjek po predmetima:\n";

    for (auto&& el : prosjek_predmeti)
      std::cout << el.first << " -> " << el.second << std::endl;
  }
  catch (std::runtime_error err)
  {
    std::cout << std::endl
              << err.what() << "\n\n";
  }
}

void odabir_izmjena_studenta()
{
  std::cout << "\nODABIR STUDENTA\n\n";

  std::string br_in;
  std::cout << "Broj indeksa: ";
  std::getline(std::cin, br_in);

  try
  {
    provjeri_handle_nevalidan_unos();
  }
  catch (std::runtime_error err)
  {
    std::cout << std::endl
              << err.what() << "\n\n";
    return;
  }

  auto student = ms::baza_studenata.pronadji(br_in);

  if (student == ms::baza_studenata.end())
  {
    std::cout << "\n\nStudent ne postoji!\n\n";
    return;
  }

  int izbor = 0;

  std::cout << std::endl;
  while (izbor >= 0 && izbor <= BROJ_IZBORA_STUDENT)
  {
    std::cout << std::endl
              << "STUDENT MENI\n\n"
                 "1. ispis podataka\n"
                 "2. promijeni broj indeksa\n"
                 "3. promijeni ime\n"
                 "4. promijeni prezime\n"
                 "5. promijeni grad\n"
                 "6. ispis ocjena i prosjeka\n"
                 "7. brisanje svih ocijena\n"
                 "8. dodavanje ocjene\n"
                 "0. glavni meni\n\n"
                 "Odaberite opciju: ";

    std::cin >> izbor;
    try
    {
      provjeri_handle_nevalidan_unos();
    }
    catch (std::runtime_error err)
    {
      std::cout << std::endl
                << err.what() << "\n\n";
      continue;
    }

    if (izbor == 0)
    {
      std::cout << std::endl;
      return;
    }

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << std::endl;

    switch (izbor)
    {
    case 1:
      std::cout << "\nPODACI O STUDENTU\n\n";
      student->ispisi_podatke();
      std::cout << std::endl;
      break;
    case 2:
      student_promijeni_broj_indeksa(student->broj_indeksa);
      break;
    case 3:
      student_promijeni_ime(student->broj_indeksa);
      break;
    case 4:
      student_promijeni_prezime(student->broj_indeksa);
      break;
    case 5:
      student_promijeni_grad(student->broj_indeksa);
      break;
    case 6:
      std::cout << "\nOCJENE I PROSJEK STUDENTA\n\n"
                << "Student: " << student->ime << " " << student->prezime << ", " << student->broj_indeksa << "\n\n";

      if (student->ocjene.size() > 0)
      {
        std::cout << "Ocjene:\n";
        student->ispisi_ocjene();
        std::cout << "\nProsjek: " << student->prosjek() << std::endl;
      }
      else
        std::cout << "Nema unesenih ocjena!\n\n";
      break;
    case 7:
      ms::baza_studenata.pronadji_nc(*student)->izbrisi_ocjene();
      std::cout << "Ocjene studenta " << student->ime << " " << student->prezime << ", " << student->broj_indeksa << " uspjesno izbrisane!\n\n";
      break;
    case 8:
      student_dodavanje_ocjene(student->broj_indeksa);
      break;
    default:
      std::cout << "\nIzbor nije validan!\n\n";
      izbor = 0;
    }
  }
}

void student_promijeni_broj_indeksa(std::string stari_broj_indeksa)
{
  auto student = ms::baza_studenata.pronadji_nc(stari_broj_indeksa);
  std::string broj_indeksa;

  std::cout << "Student: " << student->ime << " " << student->prezime << ", " << student->broj_indeksa << "\n\n"
            << "Novi broj indeksa: ";

  std::getline(std::cin, broj_indeksa);

  try
  {
    provjeri_handle_nevalidan_unos();
    student->promijeni_broj_indeksa(broj_indeksa);
    std::cout << "\nBroj indeksa uspjesno promijenjen!\n\n";
  }
  catch (std::domain_error err)
  {
    std::cout << std::endl
              << err.what() << "\n\n";
  }
  catch (std::runtime_error err)
  {
    std::cout << std::endl
              << err.what() << "\n\n";
  }
}

void student_promijeni_ime(std::string broj_indeksa)
{
  auto student = ms::baza_studenata.pronadji_nc(broj_indeksa);
  std::string ime;

  std::cout << "Student: " << student->ime << " " << student->prezime << ", " << student->broj_indeksa << "\n\n"
            << "Novo ime: ";

  std::getline(std::cin, ime);

  try
  {
    provjeri_handle_nevalidan_unos();
    student->promijeni_ime(ime);
    std::cout << "\nIme uspjesno promijenjeno!\n\n";
  }
  catch (std::domain_error err)
  {
    std::cout << std::endl
              << err.what() << "\n\n";
  }
}

void student_promijeni_prezime(std::string broj_indeksa)
{
  auto student = ms::baza_studenata.pronadji_nc(broj_indeksa);
  std::string prezime;

  std::cout << "Student: " << student->ime << " " << student->prezime << ", " << student->broj_indeksa << "\n\n"
            << "Novo prezime: ";

  std::getline(std::cin, prezime);

  try
  {
    provjeri_handle_nevalidan_unos();
    student->promijeni_prezime(prezime);
    std::cout << "\nPrezime uspjesno promijenjeno!\n\n";
  }
  catch (std::domain_error err)
  {
    std::cout << std::endl
              << err.what() << "\n\n";
  }
}

void student_promijeni_grad(std::string broj_indeksa)
{
  auto student = ms::baza_studenata.pronadji_nc(broj_indeksa);
  std::string grad;

  std::cout << "Student: " << student->ime << " " << student->prezime << ", " << student->broj_indeksa << " - " << student->grad << "\n\n"
            << "Novi grad: ";

  std::getline(std::cin, grad);

  try
  {
    provjeri_handle_nevalidan_unos();
    student->promijeni_grad(grad);
    std::cout << "\nGrad uspjesno promijenjen!\n\n";
  }
  catch (std::domain_error err)
  {
    std::cout << std::endl
              << err.what() << "\n\n";
  }
  catch (std::runtime_error err)
  {
    std::cout << std::endl
              << err.what() << "\n\n";
  }
}

void student_dodavanje_ocjene(std::string broj_indeksa)
{
  auto student = ms::baza_studenata.pronadji_nc(broj_indeksa);
  std::string naziv_predmeta;
  int ocjena = 0;

  std::cout << "\nDODAVANJE OCJENE STUDENTU\n\n"
            << "Student: " << student->ime << " " << student->prezime << ", " << student->broj_indeksa << " - " << student->grad << "\n\n";

  std::cout << "Naziv predmeta: ";
  std::getline(std::cin, naziv_predmeta);

  std::cout << "Ocjena: ";
  std::cin >> ocjena;

  try
  {
    provjeri_handle_nevalidan_unos();
    student->dodaj_ocjenu(OcjenaIzPredmeta(ocjena, naziv_predmeta, ms::baza_predmeta));
    std::cout << "\nOcjena uspjesno dodana!\n\n";
  }
  catch (std::out_of_range err)
  {
    std::cout << std::endl
              << err.what() << "\n\n";
  }
  catch (std::runtime_error err)
  {
    std::cout << std::endl
              << err.what() << "\n\n";
  }
}
