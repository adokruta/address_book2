#include "UzytkownikMeneger.h"

void UzytkownikMeneger :: rejestracjaUzytkownika()
{
    Uzytkownik uzytkownik = podajDaneNowegoUzytkownika();

    uzytkownicy.push_back(uzytkownik);
    plikZUzytkownikami.dopiszUzytkownikaDoPliku(uzytkownik);

    cout << endl << "Konto zalozono pomyslnie" << endl << endl;
    system("pause");
}

Uzytkownik UzytkownikMeneger :: podajDaneNowegoUzytkownika()
{
    Uzytkownik uzytkownik;

    uzytkownik.ustawId( pobierzIdNowegoUzytkownika());
    string login;
    do
    {
        cout << "Podaj login: ";
        cin >> login;

        uzytkownik.ustawLogin(login);

    } while (czyIstniejeLogin(uzytkownik.pobierzLogin()) == true);

    string haslo;
    cout << "Podaj haslo: ";
    cin >> haslo;
    uzytkownik.ustawHaslo(haslo);

    return uzytkownik;
}

int UzytkownikMeneger :: pobierzIdNowegoUzytkownika()
{
    if (uzytkownicy.empty() == true)
        return 1;
    else
        return uzytkownicy.back().pobierzId() + 1;
}

bool UzytkownikMeneger :: czyIstniejeLogin(string login)
{
   for(int i=0; i < uzytkownicy.size(); i++)
   {
       if(uzytkownicy[i].pobierzLogin() == login)
       {
           cout << endl << "Istnieje uzytkownik o takim loginie." << endl;
           return true;
       }
   }
    return false;
}

 void UzytkownikMeneger :: logowanieUzytkownika()
{
 if( !uzytkownicy.empty())
 {
    string login = "", haslo = "";

    system("cls");
    cout << "Podaj login: ";
    login = metodyPomocnicze.wczytajLinie();

   for(int i=0; i < uzytkownicy.size(); i++)
   {
        if ( uzytkownicy[i].pobierzLogin() == login)
        {
            for (int iloscProb = 3; iloscProb > 0; iloscProb--)
            {
                cout << "Podaj haslo. Pozostalo prob: " << iloscProb << ": ";
                haslo = metodyPomocnicze.wczytajLinie();

                if (uzytkownicy[i].pobierzHaslo() == haslo)
                {
                    idZalogowanegoUzytkownika = uzytkownicy[i].pobierzId();
                    cout << endl << "Zalogowales sie." << endl << endl;
                    system("pause");
                    return;
                }
            }
            cout << "Wprowadzono 3 razy bledne haslo." << endl;
            system("pause");
            return;
        }

    }
    cout << "Nie ma uzytkownika z takim loginem" << endl;
    system("pause");
    return;

 }
 else
 {
     cout << "Plik z uzytkownikami jest pusty. Zaloguj sie." << endl;
     system ("pause");
    return;
 }
}

 int UzytkownikMeneger :: pobierzIdZalogowanegoUzytkownika()
 {
     return idZalogowanegoUzytkownika;
 }

void UzytkownikMeneger ::  zmianaHaslaZalogowanegoUzytkownika()
{
    string noweHaslo = "";
    cout << "Podaj nowe haslo: ";
    noweHaslo = metodyPomocnicze.wczytajLinie();

    for (int i=0; i <=uzytkownicy.size(); i++)
    {
        if (uzytkownicy[i].pobierzId() == pobierzIdZalogowanegoUzytkownika())
        {
            uzytkownicy[i].ustawHaslo(noweHaslo);
            cout << "Haslo zostalo zmienione." << endl << endl;
            system("pause");
        }
    }
    plikZUzytkownikami.zapiszWszystkichUzytkownikowDoPliku(uzytkownicy);
}

bool UzytkownikMeneger ::  czyUzytkownikJestZalogowany()
{
    if(idZalogowanegoUzytkownika > 0)
        return true;
    else
        return false;
}

 void UzytkownikMeneger :: wylogujUzytkownika()
 {
     idZalogowanegoUzytkownika = 0;
 }


