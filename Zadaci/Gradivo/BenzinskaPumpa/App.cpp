#include "App.hpp"
#include "BenzinskaPumpa.hpp"
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

std::vector<BenzinskaPumpa> App::pretrazi(const std::string& grad)
{
  std::vector<BenzinskaPumpa> pumpe;

  for (const auto& pumpa : _pumpe)
    if (pumpa.grad() == grad)
      pumpe.push_back(pumpa);

  if (pumpe.size() == 0)
    throw std::invalid_argument("Nema benzinskih pumpi u tom gradu!");

  return pumpe;
}

BenzinskaPumpa& App::najjeftinija()
{
  auto it = _pumpe.begin();
  auto najjeftinija = _pumpe.end();

  while (it != _pumpe.end())
  {
    if (*it < *najjeftinija)
      najjeftinija = it;

    ++it;
  }

  return *najjeftinija;
}

BenzinskaPumpa& App::najjeftinija(const std::string& grad)
{
  auto it = _pumpe.begin();
  auto najjeftinija = _pumpe.end();

  while (it != _pumpe.end())
  {
    if (*it < *najjeftinija && it->grad() == grad)
      najjeftinija = it;

    ++it;
  }

  return *najjeftinija;
}

BenzinskaPumpa& App::najjeftinija_tip_goriva(const std::string& tip_goriva)
{
  if (tip_goriva != "dizel" && tip_goriva != "benzin" && tip_goriva != "lpg")
    throw std::invalid_argument("Tip goriva nije validan!");

  auto it = _pumpe.begin();
  auto najjeftinija = _pumpe.end();

  while (it != _pumpe.end())
  {
    if (tip_goriva == "dizel" && it->dizel() < najjeftinija->dizel())
      najjeftinija = it;
    if (tip_goriva == "benzin" && it->benzin() < najjeftinija->benzin())
      najjeftinija = it;
    if (tip_goriva == "lpg" && it->lpg() < najjeftinija->lpg())
      najjeftinija = it;

    ++it;
  }

  return *najjeftinija;
}

void App::dodaj_pumpu(const std::string& ime, std::string grad, std::string adresa)
{
  BenzinskaPumpa nova_pumpa(ime, grad, adresa);
  _pumpe.push_back(nova_pumpa);
}

void App::obrisi_pumpu(const std::string& ime, std::string grad)
{
  auto it = _pumpe.begin();
  while (it != _pumpe.end())
  {
    if (it->ime() == ime && it->grad() == grad)
    {
      _pumpe.erase(it); // za brisanje mora imati definisan copy operator =
      return;
    }

    ++it;
  }
}

void App::ispis(bool cijene) const
{
  for (const auto& el : _pumpe)
  {
    el.ispis(cijene);
    std::cout << std::endl;
  }
}

App::~App()
{
  _pumpe.clear();
}
