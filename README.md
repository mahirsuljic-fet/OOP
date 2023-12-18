Ovo je repozitorija za predmet Objektno orjentirano programiranje (OOP).
Kako bi skinuli repozitoriju potrebno je u terminalu izvšiti komandu `git clone https://github.com/mahirsuljic-fet/OOP.git`,
nakon čega će se napraviti direktorija "OOP" na mjestu gdje ste izvršili komandu. Kako bi updateali repozitoriju potrebno je u terminalu izvršiti komandu `git pull`.

<br>

Opis direktorija:
- _Predavanja_	- prezentacije, kod i bilješke sa predavanja  
- _Vjezbe_		- zadaci i bilješke sa vježbi  
- _Zadace_   	- urađene zadaće sa classroom-a  
- _Zadaci_  	- urađeni zadaci, vezani za gradivo predmeta
	- _Random_ 	- urađeni zadaci, nevezani za gradivo predmeta
- _Testovi_  	- urađeni testovi sa rokova
- _Learning_  	- kod koji nije nužno vezan za predmet, ali demonstrira neke povezane koncepte, uglavnom ignorisati

<br>

Opis fajlova:  
- **usefulminifuncs.cpp**  
	Ovo je fajl koji je napravljen da posluži pri vježbanju programiranja.
	U njemu se nalaze neke kratke funkcije kao npr. funkcija _print_container_ koja služi za ispis std containera (vector, list, map, ...).
	Na početku se nalaze deklaracije funkcija sa opisima šta rade i kako se koriste.
	Sve je napisano u jednom cpp fajlu da bi se na početku vašeg cpp fajla moglo samo napisati `#include "path-to-file/usefulminifuncs.cpp"` te da se ne fajl ne mora odvojeno kompajlirati.
	_path-to-file_ je putanja do mjesta gdje se nalazi _usefulminifuncs.cpp_, npr. ako se nalazi u Documents, treba napisati `#include "~Documents/usefulminifuncs.cpp"`
	Definicije funkcija mogu pomoći pri učenju te ih vrijedi pogledati, ali nisu nužno napisane za tu namjenu i njihov kod nije pojašnjen.
	Primjer kako se ovaj fajl i funkcije u njemu mogu koristiti je dat u fajlu _usefulminifuncs-example.cpp_.

- **.clang-format**  
	U ovom fajlu se nalazi konfiguracija po kojoj nvim formatira kod koristeći clang-format. Uglavnom ignorisati.
