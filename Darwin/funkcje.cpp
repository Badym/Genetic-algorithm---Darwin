

// definicje (implementacje) funkcji

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <random>
#include <chrono>
#include <map>

#include "struktury.h"
#include "funkcje.h"

void file_generator(const std::string& file ,const std::size_t& il_wierszy, const std::size_t& maks_dl, const int min_dl, const std::size_t& maksyzmalna_wartosc, const int minimalna_warotsc) 
{
    
    std::ofstream plik(file);
    populacja POPA;
    for (int i = 0; i < il_wierszy; i++) {
        std::size_t z = los(min_dl, maks_dl);
        osobnik tmpa;
        for (std::size_t w = 0; w < z; w++) {
            std::size_t tmp = los(minimalna_warotsc, maksyzmalna_wartosc);
            
            tmpa.jadro.geny.push_back(tmp);

        }
        POPA.osobniki.push_back(tmpa);
    }
    
    if (plik.is_open())
    {
        for (int i = 0; i < POPA.osobniki.size(); i++) {
            for (int y = 0; y < POPA.osobniki[i].jadro.geny.size(); y++) {
                plik << POPA.osobniki[i].jadro.geny[y] << " ";
            }
            plik << std::endl;
        }
        plik.close();
    }
}
////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
int sprawdzanie_przel(const int ile,char* params[])
{
    if (ile != 13) {
        std::cout << "zbyt mala liczba przelacznikow, lub brakuje spacji";
        return 1;
        
    }
    for (int i = 1; i < ile; i = i + 2){
        if (std::string(params[i]) == "-w" or std::string(params[i]) == "-r" or std::string(params[i]) == "-p" or std::string(params[i]) == "-k" or std::string(params[i]) == "-i" or std::string(params[i]) == "-o") {
            
        }
        else {
            std::cout << "zle dobrane przelaczniki" << std::endl;
            return 1;
            
        }
    }

    return 0;
    
}
////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
std::map<std::string, char*> f_przel(const int ile,char* params[])
{
    // std::map<std::string, std::string>
    std::map<std::string, char*> przelaczniki;

    for (int i = 1; i < ile; i = i + 2)
    {

        przelaczniki[params[i]] = params[i + 1]; 
    }
    return przelaczniki;

}
////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
populacja odczyt(const std::string& nazwa_pliku)
{
    populacja POPA;
    std::ifstream plik(nazwa_pliku);
    if (plik.is_open()) {                                  //odczyt z pliku

        std::string linia;

        while (getline(plik, linia)) {
            osobnik osob;

            std::stringstream ss(linia);
            int liczba;
            while (ss >> liczba) {
                osob.jadro.geny.push_back(liczba);
            }
            POPA.osobniki.push_back(osob);
        }
        plik.close();
    }
    return POPA;
}
////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
void zapisz_do_pliku(const populacja& POPA, const std::string& nazwa_pliku) 
{

    std::ofstream plik(nazwa_pliku);

    if (plik.is_open())
    {

        // for (:)
        //    for(:)

        for (int i = 0; i < POPA.osobniki.size(); i++) {
            for (int y = 0; y < POPA.osobniki[i].jadro.geny.size(); y++) {
                //liczba = ;
                plik << POPA.osobniki[i].jadro.geny[y] << " ";
            }
            plik << std::endl;
        }
        plik.close();
    }

}
////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
void wypisz_populacje(const populacja& POPA) {

    for (int i = 0; i < POPA.osobniki.size(); i++) {                                    
        std::cout << "[" << i << "] ";// wypisz_osobnika
        wypisz_osobnik(POPA.osobniki[i]);
        std::cout << std::endl;

    }
}
////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
void wypisz_osobnik(const osobnik& osA) // rodzaj meskorzeczowy
{
    for (int w = 0; w < osA.jadro.geny.size(); w++) {
        std::cout << osA.jadro.geny[w] << " ";
    }
}
////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
std::size_t los(const int mini, const std::size_t& maks) // std::size_t
{

    std::default_random_engine silnik(std::chrono::system_clock::now().time_since_epoch().count());
    std::uniform_int_distribution<std::size_t> rozklad(mini, maks);

    return rozklad(silnik);
}
////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
double funkcja5(const osobnik& osobni) {
    int n = 1;
    double sigma = 0.3;
    int suma_p = 0;
    int suma_n = 0;

    long long int dl = osobni.jadro.geny.size();
    for (long long int i = 0; i < dl; i++) {
        if (osobni.jadro.geny[i] % 2 == 0) {
            suma_p += 1;
        }
        else suma_n += 1;
    }
    double srednia = suma_p * 1.0 / suma_n;
    return exp(-(n - srednia) * (n - srednia) / (2 * sigma * sigma));
}
////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
double funkcja4(const osobnik& osobni) {  
    int pref_dl = 15;
    double sigma = 1.5;
    double sigma1 = 3;
    long long int dl = osobni.jadro.geny.size();
    double ws_dl= exp(-(pref_dl - dl) * (pref_dl - dl) / (2 * sigma1 * sigma1));

    int cyfra = 10;
    int pref_ilosc = 4;
    int suma = 0;
    for (std::size_t i = 0; i < dl; i++) {
        if (osobni.jadro.geny[i] == cyfra) {
            suma += 1;
        }
    }
    return  exp(-(pref_ilosc - suma) * (pref_ilosc - suma) / (2 * sigma * sigma))* ws_dl*1.0;
   
}
////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
double funkcja3(const osobnik& osobni) {
    int n = 55;
    double sigma = 1;
    int suma = 0;
    long long int dl = osobni.jadro.geny.size();
    for (long long int i = 0; i < dl; i++) {
        suma += osobni.jadro.geny[i];
    }
    double srednia = suma*1.0/dl;
    return exp(-(n - srednia) * (n - srednia) / (2 * sigma * sigma));
}
////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
double funkcja2(const osobnik& osobni) {
    int n = 10;
    double sigma = 1;
    long long int dl = osobni.jadro.geny.size();

    return exp(-(n - dl) * (n - dl) / (2 * sigma * sigma));
}
////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
std::pair<populacja, populacja> wymieranie_rozmnazanie(const populacja& POPA, const double ws_wymier, const double ws_rozm) {

    populacja POPB;
    populacja POPC;
    for (std::size_t c = 0; c < POPA.osobniki.size(); c++) {
        if (POPA.pf(POPA.osobniki[c]) >= ws_wymier) {
            POPB.osobniki.push_back(POPA.osobniki[c]);
        }
        if (POPA.pf(POPA.osobniki[c]) > ws_rozm) {
            POPC.osobniki.push_back(POPA.osobniki[c]);
        }
    }
    return { POPB,POPC };
}
////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
std::pair<osobnik, osobnik> krzyzowanie(const populacja& POPB) {
    std::size_t a = 0;
    std::size_t b = 0;
    while (a == b) {                                     //losujemy indeksy osobnikow do krzyzowania
        a = los(0, POPB.osobniki.size() - 1);
        b = los(0, POPB.osobniki.size() - 1);
    }
    std::size_t pkt_a = los(0, POPB.osobniki[a].jadro.geny.size());                  // losujemy miejsca przeciecia
    std::size_t pkt_b = los(0, POPB.osobniki[b].jadro.geny.size());
    osobnik tmp1;
    osobnik tmp2;
    for (std::size_t z = 0; z < pkt_a; z++) {                                          //tworzenie nowego osobnika 
        tmp1.jadro.geny.push_back(POPB.osobniki[a].jadro.geny[z]);
    }

    for (std::size_t x = pkt_b; x < POPB.osobniki[b].jadro.geny.size(); x++) {
        tmp1.jadro.geny.push_back(POPB.osobniki[b].jadro.geny[x]);
    }

    for (std::size_t z = 0; z < pkt_b; z++) {                                          //tworzenie nowego osobnika 
        tmp2.jadro.geny.push_back(POPB.osobniki[b].jadro.geny[z]);
    }

    for (std::size_t x = pkt_a; x < POPB.osobniki[a].jadro.geny.size(); x++) {
        tmp2.jadro.geny.push_back(POPB.osobniki[a].jadro.geny[x]);
    }

    
    std::pair<osobnik, osobnik> para;
    para.first = tmp1;
    para.second = tmp2;

    return para; 
}
////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
void wpisanie(const populacja& POP,populacja& POPA) {

    for (int i = 0; i < POP.osobniki.size(); i++) {
        POPA.osobniki.push_back(POP.osobniki[i]);
    }

}
////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
