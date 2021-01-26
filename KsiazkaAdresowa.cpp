#include "KsiazkaAdresowa.h"

bool  KsiazkaAdresowa ::  czyUzytkownikJestZalogowany()
{
    uzytkownikMeneger.czyUzytkownikJestZalogowany();
}

void KsiazkaAdresowa :: rejestracjaUzytkownika()
{
    uzytkownikMeneger.rejestracjaUzytkownika();
}

void KsiazkaAdresowa :: logowanieUzytkownika()
{
    uzytkownikMeneger.logowanieUzytkownika();
    if(uzytkownikMeneger.czyUzytkownikJestZalogowany())
    {
     adresatMeneger = new AdresatMeneger(NAZWA_PLIKU_Z_ADRESATAMI, uzytkownikMeneger.pobierzIdZalogowanegoUzytkownika());
    }
}

  void KsiazkaAdresowa ::  wylogujUzytkownika()
  {
      uzytkownikMeneger.wylogujUzytkownika();
      delete adresatMeneger;
      adresatMeneger = NULL;
  }

 void  KsiazkaAdresowa :: dodajAdresata()
 {
     if(uzytkownikMeneger.czyUzytkownikJestZalogowany())
        adresatMeneger -> dodajAdresata();
    else
        cout <<"Uzytkownik nie jest zalogowany" << endl;
 }

void KsiazkaAdresowa ::   wyswietlAdresatowZalogowanegoUzytkownika()
{
    adresatMeneger->wyswietlAdresatowZalogowanegoUzytkownika();
}

void KsiazkaAdresowa :: zmianaHaslaZalogowanegoUzytkownika()
{
    uzytkownikMeneger.zmianaHaslaZalogowanegoUzytkownika();
}

void KsiazkaAdresowa :: usunAdresata()
{
    adresatMeneger->usunAdresata();
}

void KsiazkaAdresowa :: edytujAdresata()
{
    adresatMeneger->edytujAdresata();
}
