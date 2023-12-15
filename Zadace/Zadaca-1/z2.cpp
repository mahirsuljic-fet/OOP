// Mahir Suljic - OOP Zadaca 2023. - Zadatak 2

#include <iostream>

namespace Register
{
  unsigned short A = 0;
  unsigned short B = 0;
  unsigned short current = 0;
}

int main()
{
  /*
    pretpostavljam da ne smijemo koristiti pointere
    pa sam odlucio rijesit odabir registra koristeci indekse
    korisnik izabere koji registar zeli promijeniti
    program zapamti koji je registar izabran preko
    njegovog indeksa, zatim korisnik modifikuje
    registar current koji overwrite-a prvobitno
    izabrani registar pri kraju while petlje
  */
 
  short currentRegIndex = 0; // 1-A; 2-B
  short option = 0;

  // REGISTER MENU
  while (true)
  {
    std::cout << "1. Register A\n"
                 "2. Register B\n"
                 "3. Swap registers A and B\n"
                 "4. Exit\n"
                 "Your choice: ";

    std::cin >> currentRegIndex;

    if (currentRegIndex == 4)
      return 0;

    if (currentRegIndex == 3)
    {
      unsigned short temp = Register::A;
      Register::A = Register::B;
      Register::B = temp;

      std::cout << "\nRegisters swapped!\n";
      continue;
    }

    if (currentRegIndex < 1 || currentRegIndex > 2)
    {
      std::cout << "Invalid choice!\n\n";
      continue;
    }

    // CHOICE MENU
    while (true)
    {
      if (currentRegIndex == 1)
        std::cout << "\nRegister A\n";
      if (currentRegIndex == 2)
        std::cout << "\nRegister B\n";

      std::cout << "1. Print register\n"
                   "2. Set bit in register\n"
                   "3. Reset bit in register\n"
                   "4. Exit\n"
                   "Enter option: ";

      std::cin >> option;

      // postavi current registar na vrijednost izabranog
      if (option >= 1 && option <= 3)
      {
        switch (currentRegIndex)
        {
        case 1:
          Register::current = Register::A;
          break;
        case 2:
          Register::current = Register::B;
          break;
        }
      }

      switch (option)
      {
      // Set bit in register
      case 2:
      // Reset bit in register
      case 3:
      {
        short bitIndex = -1;
        unsigned short c = 1;

        while (bitIndex < 0 || bitIndex > 15)
        {
          std::cout << "Enter bit number: ";
          std::cin >> bitIndex;

          if (bitIndex < 0 || bitIndex > 15)
            std::cout << "\nInvalid input!\n\n";
        }

        c <<= bitIndex;

        if (option == 2) // set bit
          Register::current |= c;
        else if (option == 3) // reset bit
          Register::current -= c;

        std::cout << "New register value: " << Register::current << std::endl;
      }
      // Print register
      case 1:
      {
        // pomjeri 1 na najsignifikantniji bit
        // kako bi se omogucio ispis sa lijeva na desno
        unsigned short c = 1 << 15; // cursor

        for (int i = 0; i < 16; i++)
        {
          std::cout << ((Register::current & c) != 0 ? "1" : "0");
          c >>= 1;
        }

        std::cout << std::endl;
      }
      break;
      default:
        std::cout << "\nInvalid input!\n\n";
        break;
      // Exit
      case 4:
        std::cout << std::endl;
        break;
      }

      if (option == 4)
        break;
      else
      {
        switch (currentRegIndex)
        {
        case 1:
          Register::A = Register::current;
          break;
        case 2:
          Register::B = Register::current;
          break;
        }

        Register::current = 0;
      }
    }
  }

  return 0;
}