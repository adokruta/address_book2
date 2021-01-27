#include "PlikZAdresatami.h"

string PlikZAdresatami :: zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat)
{
    string liniaZDanymiAdresata = "";

    liniaZDanymiAdresata += metodyPomocnicze.konwerjsaIntNaString(adresat.pobierzId()) + '|';
    liniaZDanymiAdresata += metodyPomocnicze.konwerjsaIntNaString(adresat.pobierzIdUzytkownika()) + '|';
    liniaZDanymiAdresata += adresat.pobierzImie() + '|';
    liniaZDanymiAdresata += adresat.pobierzNazwisko() + '|';
    liniaZDanymiAdresata += adresat.pobierzNumerTelefonu() + '|';
    liniaZDanymiAdresata += adresat.pobierzEmail() + '|';
    liniaZDanymiAdresata += adresat.pobierzAdres() + '|';

    return liniaZDanymiAdresata;
}

int PlikZAdresatami :: pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami)
{
    int pozycjaRozpoczeciaIdUzytkownika = daneJednegoAdresataOddzielonePionowymiKreskami.find_first_of('|') + 1;
    int idUzytkownika = metodyPomocnicze.konwersjaStringNaInt(metodyPomocnicze.pobierzLiczbe(daneJednegoAdresataOddzielonePionowymiKreskami, pozycjaRozpoczeciaIdUzytkownika));

    return idUzytkownika;
}

int PlikZAdresatami :: pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami)
{
    int pozycjaRozpoczeciaIdAdresata = 0;
    int idAdresata = metodyPomocnicze.konwersjaStringNaInt(metodyPomocnicze.pobierzLiczbe(daneJednegoAdresataOddzielonePionowymiKreskami, pozycjaRozpoczeciaIdAdresata));
    return idAdresata;
}

vector <Adresat>  PlikZAdresatami :: wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika)
{
    vector <Adresat> adresaci;
    Adresat adresat;
    string daneJednegoAdresataOddzielonePionowymiKreskami = "";
    string daneOstaniegoAdresataWPliku = "";
    fstream plikTekstowy;
    plikTekstowy.open(pobierzNazwePliku().c_str(), ios::in);

    if (plikTekstowy.good() == true)
    {
        while (getline(plikTekstowy, daneJednegoAdresataOddzielonePionowymiKreskami))
        {
            if(idZalogowanegoUzytkownika == pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(daneJednegoAdresataOddzielonePionowymiKreskami))
            {
                adresat = pobierzDaneAdresata(daneJednegoAdresataOddzielonePionowymiKreskami);
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
        idOstatniegoAdresata = pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(daneOstaniegoAdresataWPliku);
    }
    else
        return adresaci;
}

Adresat PlikZAdresatami :: pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami)
{
    Adresat adresat;
    string pojedynczaDanaAdresata = "";
    int numerPojedynczejDanejAdresata = 1;

    for (int pozycjaZnaku = 0; pozycjaZnaku < daneAdresataOddzielonePionowymiKreskami.length(); pozycjaZnaku++)
    {
        if (daneAdresataOddzielonePionowymiKreskami[pozycjaZnaku] != '|')
        {
            pojedynczaDanaAdresata += daneAdresataOddzielonePionowymiKreskami[pozycjaZnaku];
        }
        else
        {
            switch(numerPojedynczejDanejAdresata)
            {
            case 1:
                adresat.ustawId(atoi(pojedynczaDanaAdresata.c_str()));
                break;
            case 2:
                adresat.ustawIdUzytkownika(atoi(pojedynczaDanaAdresata.c_str())) ;
                break;
            case 3:
                adresat.ustawImie(pojedynczaDanaAdresata) ;
                break;
            case 4:
                adresat.ustawNazwisko(pojedynczaDanaAdresata) ;
                break;
            case 5:
                adresat.ustawNumerTelefonu(pojedynczaDanaAdresata) ;
                break;
            case 6:
                adresat.ustawEmail(pojedynczaDanaAdresata) ;
                break;
            case 7:
                adresat.ustawAdres(pojedynczaDanaAdresata) ;
                break;
            }
            pojedynczaDanaAdresata = "";
            numerPojedynczejDanejAdresata++;
        }
    }
    return adresat;
}

bool PlikZAdresatami :: dopiszAdresataDoPliku(Adresat adresat)
{
    string liniaZDanymiAdresata = "";
    fstream plikTekstowy;

    plikTekstowy.open(pobierzNazwePliku().c_str(), ios::out | ios::app);

    if (plikTekstowy.good() == true)
    {
        liniaZDanymiAdresata = zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(adresat);
        plikTekstowy <<  liniaZDanymiAdresata << endl;

        idOstatniegoAdresata++;
        plikTekstowy.close();
        return true;
    }
return false;
}

   int PlikZAdresatami :: pobierzIdOstatniegoAdresata()
   {
    fstream odczytywanyPlikTekstowy;
    string wczytanaLinia = "";

    odczytywanyPlikTekstowy.open(pobierzNazwePliku().c_str(), ios::in);

    if (odczytywanyPlikTekstowy.good() == true)
        {
            while (getline(odczytywanyPlikTekstowy, wczytanaLinia))
            {
                idOstatniegoAdresata = pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(wczytanaLinia);
            }

            odczytywanyPlikTekstowy.close();
            return idOstatniegoAdresata;
        }
        else
            return 0;
   }

   void PlikZAdresatami :: usunWybranaLinieWPliku(int idUsuwanegoAdresata)
{
    fstream odczytywanyPlikTekstowy;
    fstream tymczasowyPlikTekstowy;
    string wczytanaLinia = "";


    odczytywanyPlikTekstowy.open(pobierzNazwePliku().c_str(), ios::in);
    tymczasowyPlikTekstowy.open("TymczasowyPlik.txt", ios::out | ios::app);

    if (odczytywanyPlikTekstowy.good() == true)
    {
        while (getline(odczytywanyPlikTekstowy, wczytanaLinia))
        {
            if(idUsuwanegoAdresata != pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(wczytanaLinia))
            {
                tymczasowyPlikTekstowy << wczytanaLinia << endl;
                idOstatniegoAdresata = pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(wczytanaLinia);
            }

        }

        odczytywanyPlikTekstowy.close();
        tymczasowyPlikTekstowy.close();

        remove(pobierzNazwePliku().c_str());
        rename("TymczasowyPlik.txt",pobierzNazwePliku().c_str());
    }
}

int PlikZAdresatami :: zwrocIdOstatniegoAdresata ()
{
    return idOstatniegoAdresata;
}

void PlikZAdresatami :: zaktualizujDaneWybranegoAdresata(Adresat adresat)
{
    string liniaZDanymiAdresata = "";

    liniaZDanymiAdresata = zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(adresat);
    edytujWybranaLinieWPliku(liniaZDanymiAdresata);

    cout << endl << "Dane zostaly zaktualizowane." << endl << endl;
}


void PlikZAdresatami :: edytujWybranaLinieWPliku(string liniaZDanymiAdresataOddzielonePionowymiKreskami)
{
    fstream odczytywanyPlikTekstowy, tymczasowyPlikTekstowy;
    string wczytanaLinia = "";
    int iDEdytowanegoAdresata = pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(liniaZDanymiAdresataOddzielonePionowymiKreskami);

    odczytywanyPlikTekstowy.open(pobierzNazwePliku().c_str(), ios::in);
    tymczasowyPlikTekstowy.open("TymczasowyPlik.txt", ios::out | ios::app);

    if (odczytywanyPlikTekstowy.good() == true)
    {
        while (getline(odczytywanyPlikTekstowy, wczytanaLinia))
        {
            if ( iDEdytowanegoAdresata == pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(wczytanaLinia))
            {
                    tymczasowyPlikTekstowy << liniaZDanymiAdresataOddzielonePionowymiKreskami << endl;             }
            else
            {
                    tymczasowyPlikTekstowy << wczytanaLinia << endl;
            }
        }

        odczytywanyPlikTekstowy.close();
        tymczasowyPlikTekstowy.close();

        remove(pobierzNazwePliku().c_str());
        rename("TymczasowyPlik.txt",pobierzNazwePliku().c_str());
    }
}
