#include "KsiazkaAdresowa.h"


void KsiazkaAdresowa :: rejestracjaUzytkownika()
{
    uzytkownikMeneger.rejestracjaUzytkownika();
}

void KsiazkaAdresowa :: wypiszWszystkichUzytkownikow()
{
    uzytkownikMeneger.wypiszWszystkichUzytkownikow();
}

void KsiazkaAdresowa :: logowanieUzytkownika()
{
    uzytkownikMeneger.ustawIdZalogowanegoUzytkownika();
}

void KsiazkaAdresowa :: wyswietlMenu()
{
    while (true)
    {
        if (idZalogowanegoUzytkownika == 0)
        {
           char wybor = metodyPomocnicze.wybierzOpcjeZMenuGlownego();

            switch (wybor)
            {
            case '1':
                rejestracjaUzytkownika();
                break;
            case '2':
                logowanieUzytkownika();
                idZalogowanegoUzytkownika = 1;
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                system("pause");
                break;
            }
        }
        else
        {


            if (adresatMeneger.adresaci.empty() == true)
                {
                    adresatMeneger.idOstatniegoAdresata = uzytkownikMeneger.wczytajAdresatowZalogowanegoUzytkownikaZPliku();
                }

            char wybor = metodyPomocnicze.wybierzOpcjeZMenuUzytkownika();

            switch (wybor)
            {
            case '1':
                adresatMeneger.idOstatniegoAdresata = adresatMeneger.dodajAdresata();
                break;
           /* case '2':
                wyszukajAdresatowPoImieniu(adresaci);
                break;
            case '3':
                wyszukajAdresatowPoNazwisku(adresaci);
                break; */
            case '4':
                uzytkownikMeneger.wyswietlAdresatowZalogowanegoUzytkownika();
                break; /*
            case '5':
                idUsunietegoAdresata = usunAdresata(adresaci);
                idOstatniegoAdresata = podajIdOstatniegoAdresataPoUsunieciuWybranegoAdresata(idUsunietegoAdresata, idOstatniegoAdresata);
                break;
            case '6':
                edytujAdresata(adresaci);
                break; */
            case '7':
                uzytkownikMeneger.zmianaHaslaZalogowanegoUzytkownika();
                break;
            case '8':
                idZalogowanegoUzytkownika = 0;
                adresatMeneger.adresaci.clear();
                break;
            }
        }
    }

}





