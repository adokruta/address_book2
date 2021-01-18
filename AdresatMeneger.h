#ifndef ADRESATMENEGER_H
#define ADRESATMENEGER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>

#include "Adresat.h"
#include "MetodyPomocnicze.h"
#include "UzytkownikMeneger.h"
#include "PlikZAdresatami.h"


using namespace std;

class AdresatMeneger
{
    friend class KsiazkaAdresowa;
    friend class UzytkownikMeneger;

    //
    int idOstatniegoAdresata;
    vector <Adresat> adresaci;
    Adresat adresat;
    MetodyPomocnicze metodyPomocnicze;
    Adresat podajDaneNowegoAdresata();

    public:

    AdresatMeneger();

    int dodajAdresata();


};

#endif

