Objektno orjentirano programiranje (OOP)
========================================

Ovo je repozitorija za predmet Objektno orjentirano programiranje (OOP).
Kako bi skinuli repozitoriju potrebno je u terminalu izvšiti komandu `git clone https://github.com/mahirsuljic-fet/OOP.git`,
nakon čega će se napraviti direktorija "OOP" na mjestu gdje ste izvršili komandu. Kako bi update-ali repozitoriju potrebno je u terminalu izvršiti komandu `git pull`.

## [Predavanja](./Predavanja)
Kod i bilješke sa predavanja  

## [Prezentacije](./Prezentacije)
Profesorove prezentacije

## [Vjezbe](./Vjezbe)		
Zadaci i bilješke sa vježbi  

## [Zadace](./Zadace)   	
Urađene zadaće sa classroom-a  

## [Zadaci](./Zadaci)  	
Urađeni zadaci
- [**Gradivo**](./Zadaci/Gradivo/)  - vezani za gradivo predmeta
- [**Random**](./Zadaci/Random/)    - nevezani za gradivo predmeta

## [Testovi](./Testovi)  	
Urađeni testovi sa rokova

## [Instrukcije](./Instrukcije) 
Primjeri i zadaci sa održanih instrukcija

## [Literatura](./Literatura)  
Knjige vezane za predmet i c++
- [C++ Annotations](./Literatura/C++_Annotations.pdf)
- [The C++ Programming Language](./Literatura/The_C++_Programming_Language.pdf)
- [C++ Primer](./Literatura/C++_Primer.pdf)
- [Clean Code](./Literatura/Clean_Code.pdf)
- [Clean Craftsmanship](./Literatura/Clean_Craftsmanship.pdf)

## [Random Useful](https://github.com/mahirsuljic-fet/RandomUseful)
Ovo je još jedna od mojih repozitorija u kojoj možete naći dosta korisnih stvari kao što su podešavanje sopstvene [neovim](https://github.com/mahirsuljic-fet/RandomUseful/blob/main/nvim.txt) konfiguracije, korisne [bashrc](https://github.com/mahirsuljic-fet/RandomUseful/blob/main/bashrc.txt) komande, moja [clang-format](https://github.com/mahirsuljic-fet/RandomUseful/blob/main/.clang-format) konfiguracija za formatiranje koda, rješenja nekih problema, itd.

### [Skripta za instalaciju/update okruženja](./getcppshell.sh)
Za pokretanje skripte koristi se komanda `. ./getcppshell.sh` pri čemu je potrebno biti u direktoriji gdje se nalazi `getcppshell.sh`.
Skripta automatski skine najnoviju verziju okruženja, odradi sve što je potrebno i vrati terminal u direktoriju u kojoj je i bio.

### Komanda za brisanje NIX cache
Ukoliko se skine okruženje i u nekog kraćem periodu (npr. 1 dan) izađe nova verzija okruženja neće biti moguće preuzeti novu verziju dok ne prođe taj period.
Čekanje se može zaobići brisanjem cache-a komandom `rm -rf ~/.cache/nix/`.

### [**usefulminifuncs.cpp**](./usefulminifuncs.cpp)
Ovo je fajl koji je napravljen da posluži pri vježbanju programiranja.
U njemu se nalaze neke kratke funkcije kao npr. funkcija `print_container` koja služi za ispis std containera (vector, list, map, ...).
Na početku se nalaze deklaracije funkcija sa opisima šta rade i kako se koriste.
Sve je napisano u jednom cpp fajlu da bi se na početku vašeg cpp fajla moglo samo napisati `#include "path-to-file/usefulminifuncs.cpp"` te da se ne fajl ne mora odvojeno kompajlirati.
`path-to-file` je putanja do mjesta gdje se nalazi `usefulminifuncs.cpp`, npr. ako se nalazi u Documents, treba napisati `#include "~Documents/usefulminifuncs.cpp"`.
Definicije funkcija mogu pomoći pri učenju te ih vrijedi pogledati, ali nisu nužno napisane za tu namjenu i njihov kod nije pojašnjen.
Primjer kako se ovaj fajl i funkcije u njemu mogu koristiti je dat u fajlu [`usefulminifuncs-example.cpp`](./usefulminifuncs-example.cpp).
