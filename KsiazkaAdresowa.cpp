#include "KsiazkaAdresowa.h"

KsiazkaAdresowa :: KsiazkaAdresowa()
{
    uzytkownikMeneger.wczytajUzytkownikowZPliku();
}

void KsiazkaAdresowa :: rejestracjaUzytkownika()
{
    uzytkownikMeneger.rejestracjaUzytkownika();
}

void KsiazkaAdresowa :: wypiszWszystkichUzytkownikow()
{
    uzytkownikMeneger.wypiszWszystkichUzytkownikow();
}




