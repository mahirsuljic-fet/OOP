// Koja je razlika izmedju funkcija deklarisanih
// unutar neke strukture kao ispod?

virtual void foo();
virtual void foo() = 0;

// odgovor:

// virtual void foo() je virtuelna funkcija dok je 
// virtual void foo() = 0 cisto virtuelna funkcija.
// Klasa ili struktura u kojoj je deklasirana bar jedna
// cisto virtuelna funkcija postaje apstraktna i 
// ne moze se instancirati. Izvedene klase moraju
// implementirati cisto vrituelne metode.
