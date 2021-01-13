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


using namespace std;

class AdresatMeneger
{
    vector <Adresat> adresaci;
    MetodyPomocnicze metodyPomocnicze;
    //UzytkownikMeneger uzytkownikMeneger;


    Adresat podajDaneNowegoAdresata();

    public:

    AdresatMeneger();
    int idOstatniegoAdresata;
    int dodajAdresata();

};

#endif

