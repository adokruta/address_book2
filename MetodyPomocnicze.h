#ifndef METODYPOMOCNICZE_H
#define METODYPOMOCNICZE_H

#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

class MetodyPomocnicze
{
public:
     static string konwerjsaIntNaString(int liczba);
     string wczytajLinie();
     static char wybierzOpcjeZMenuGlownego();
     static char wczytajZnak();
     string zamienPierwszaLitereNaDuzaAPozostaleNaMale(string tekst);
     int konwersjaStringNaInt(string liczba);
     string pobierzLiczbe(string tekst, int pozycjaZnaku);
     static char wybierzOpcjeZMenuUzytkownika();
     static int wczytajLiczbeCalkowita();
};

#endif
