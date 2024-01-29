// Koja je razlika izmedju kljucne rijeci private i protected?

// odgovor
//
// Dijelu klase/strukture oznacen kao private se moze pristupati
// samo iz te iste (bazne) klase/strukture, dok dijelu oznacen kao protected mogu
// pristupati bazna klasa/strukture i klase/strukture koje nasljedjuju od nje.
// Ukoliko se nasljedjuje preko public, tada dio klase/sturkture oznacen sa
// protected je i u izvedenoj klasi protected, ako se nasljedjuje
// preko private tada je dio klase/strukture oznacen sa protected private u
// izvedenoj klasi/strukturi.
// Ove dvije kljucne rijeci se mogu koristiti i kao tipovi nasljedjivanja
// gdje ukoliko se nasljeduje sa protected, tada public dio bazne klase/strukture
// postaje protected, protected dio ostaje protected, a private nije dostupan.
// Ukoliko se nasljedjuje sa private, tada i public i protected dijelovi
// bazne klase/sturkture su private u izvedenoj klasi/strukturi, a private
// dio bazne klase/sturkture nije dostupan u izvedenoj klasi/strukturi.
