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

void UzytkownikMeneger :: wypiszWszystkichUzytkownikow()
{
     for(int i=0; i < uzytkownicy.size(); i++)
   {
       cout << uzytkownicy[i].pobierzId() << endl;
       cout << uzytkownicy[i].pobierzLogin() << endl;
       cout << uzytkownicy[i].pobierzHaslo() << endl;
   }
}

void UzytkownikMeneger :: wczytajUzytkownikowZPliku()
 {
    uzytkownicy = plikZUzytkownikami.wczytajUzytkownikowZPliku();
 }

 int UzytkownikMeneger :: logowanieUzytkownika()
{

    string login = "", haslo = "";

    system("cls");
    cout << "Podaj login: ";
    login = metodyPomocnicze.wczytajLinie();

   for(int i=0; i <= uzytkownicy.size(); i++)
   {
        if ( uzytkownicy[i].pobierzLogin() == login)
        {
            for (int iloscProb = 3; iloscProb > 0; iloscProb--)
            {
                cout << "Podaj haslo. Pozostalo prob: " << iloscProb << ": ";
                haslo = metodyPomocnicze.wczytajLinie();

                if (uzytkownicy[i].pobierzHaslo() == haslo)
                {
                    cout << endl << "Zalogowales sie." << endl << endl;
                    system("pause");
                    zalogowanyUzytkownik = uzytkownicy[i];
                    return uzytkownicy[i].pobierzId();
                }
            }
            cout << "Wprowadzono 3 razy bledne haslo." << endl;
            system("pause");
            return 0;
        }

    }
    cout << "Nie ma uzytkownika z takim loginem" << endl << endl;
    system("pause");
    return 0;
}

void UzytkownikMeneger :: ustawIdZalogowanegoUzytkownika()
{
    zalogowanyUzytkownik.ustawId(logowanieUzytkownika());

}
 int UzytkownikMeneger :: pobierzIdZalogowanegoUzytkownika()
 {
     return zalogowanyUzytkownik.pobierzId();
 }

 int UzytkownikMeneger :: wczytajAdresatowZalogowanegoUzytkownikaZPliku()
{
    Adresat adresat;
    PlikZAdresatami plikZAdresatami;
    AdresatMeneger adresatMeneger;

    int idOstatniegoAdresata = 0;
    string daneJednegoAdresataOddzielonePionowymiKreskami = "";
    string daneOstaniegoAdresataWPliku = "";

    system ("pause");
    fstream plikTekstowy;
    plikTekstowy.open(plikZAdresatami.nazwaPlikuZAdresatami.c_str(), ios::in);

    if (plikTekstowy.good() == true)
    {
        while (getline(plikTekstowy, daneJednegoAdresataOddzielonePionowymiKreskami))
        {
            if(pobierzIdZalogowanegoUzytkownika() == plikZAdresatami.pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(daneJednegoAdresataOddzielonePionowymiKreskami))
            {
                adresat = plikZAdresatami.pobierzDaneAdresata(daneJednegoAdresataOddzielonePionowymiKreskami);
                adresaci.push_back(adresat);
            }
        }
        daneOstaniegoAdresataWPliku = daneJednegoAdresataOddzielonePionowymiKreskami;
    }
    else
        cout << "Nie udalo sie otworzyc pliku i wczytac danych." << endl;

    plikTekstowy.close();

    if (daneOstaniegoAdresataWPliku != "")
    {
        idOstatniegoAdresata = plikZAdresatami.pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(daneOstaniegoAdresataWPliku);
        return idOstatniegoAdresata;
    }
    else
        return 0;
}

void UzytkownikMeneger :: wyswietlAdresatowZalogowanegoUzytkownika()
{
    system("cls");
    if (!adresaci.empty())
    {
        cout << "             >>> ADRESACI <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        for (int i=0; i<adresaci.size(); i++)
        {
            wyswietlDaneAdresata(adresaci[i]);
        }
        cout << endl;
    }
    else
    {
        cout << endl << "Ksiazka adresowa jest pusta." << endl << endl;
    }
    system("pause");
}

void UzytkownikMeneger :: wyswietlDaneAdresata(Adresat adresat)
{
    cout << endl << "Id:                 " << adresat.pobierzId() << endl;
    cout << "Imie:               " << adresat.pobierzImie() << endl;
    cout << "Nazwisko:           " << adresat.pobierzNazwisko()  << endl;
    cout << "Numer telefonu:     " << adresat.pobierzNumerTelefonu()  << endl;
    cout << "Email:              " << adresat.pobierzEmail()  << endl;
    cout << "Adres:              " << adresat.pobierzAdres()  << endl;
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



