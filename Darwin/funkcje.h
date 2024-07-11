/** @file  */

// DECLARATIONS (HEADERS) OF FUNCTIONS 

#ifndef FUNKCJE_H
#define FUNKCJE_H

#include <string>
#include <vector>

#include "struktury.h"




///    @brief Funkcja generuje plilk z przykladowa populacja
///    @param file nazwa pliku generowanego
///    @param il_wierszy ilosc wierszy w pliku
///    @param maks_dl maksymalna dlugos osobnika
///    @param min_dl minimalna dlugos osobnika
///    @param maksyzmalna_wartosc maksymalna wartosc jednego genu u osobnika
///    @param minimalna_warotsc minimalna wartosc jednego genu u osobnika
///    @return plik nic nie zwraca
///    @note funkcja tworzy plik w folderze w ktorym jest prokejt
void file_generator(const std::string& file , const std::size_t& il_wierszy, const std::size_t& maks_dl,const int min_dl, const std::size_t& maksyzmalna_wartosc,const int minimalna_warotsc);

/**
    @brief Funkcja sprawdza poprawnosc przelacznikow podanych na wejsciu
    @param ile dlugosc tablicy
    @param params[] tablica parametrow
    @return zwraca 1 gdy przelaczniki sa zle dobrane lub 0 gdy przelaczniki sa poprawne
*/
int sprawdzanie_przel(const int ile,char* params[]);

/**
    @brief Funkcja tworzy mape przelacznikow
    @param ile dlugosc tablicy
    @param params[] tablica parametrow
    @return mapa przelacznikow
    @note przyklad (mapa[-p]=12)
*/
std::map<std::string, char*> f_przel(const int ile,char* params[]);

/** 
    @brief Funkcja odczytuje z pliku populacje
    @param nazwa_pliku nazwa pliku odczytywanego
    @return populacje odczytana
*/
populacja odczyt(const std::string& nazwa_pliku);

/**
    @brief Funkcja zapisuje do pliku populacje
    @param POPA populacja do zapisania 
    @param nazwa_pliku nazwa pliku do ktorego zapisujemy populacje
    @note Funkcja nadpisuje lub tworzy plik o podanej nazwie 
*/
void zapisz_do_pliku(const populacja& POPA,const std::string& nazwa_pliku);

/**
    @brief Funkcja wypisuje na ekran populacje
    @param POPA populacja do wypisania
    @return Funkcja nic nie zwraca
*/
void wypisz_populacje(const populacja& POPA);

/**
    @brief Funkcja wypisuje na ekran osobnik
    @param osA osobnik do wypisania
    @return Funkcja nic nie zwraca
*/
void wypisz_osobnik(const osobnik& osA);

/**
    @brief Funkcja losuje z dodatniego przedzialu liczbe calkowita
    @param mini minimalna wartosc do wypisania
    @param maks maksymalna wartosc do wypisania
    @return funkcja zwraca wartosc calkowita z podanego przedzialu
*/
std::size_t los(const int mini, const std::size_t& maks);

/**
    @brief Funkcja oceny osobnika piec "ocenia osobnika wzgledem ilosci parzystych i nieparystych"
    @param osobni osobnik do oceny
    @return wspolczynnik przystosowania si�
*/
double funkcja5(const osobnik& osobni);

/**
    @brief Funkcja oceny osobnika trzy "ocenia osobnika wzgledem ilosci podanej cyfry"
    @param osobni osobnik do oceny
    @return wspolczynnik przystosowania si�
*/
double funkcja4(const osobnik& osobni);

/**
    @brief Funkcja oceny osobnika trzy "ocenia osobnika wzgledem sredniej arytmetycznej"
    @param osobni osobnik do oceny
    @return wspolczynnik przystosowania si�
*/
double funkcja3(const osobnik& osobni);

/**
    @brief Funkcja oceny osobnika dwa "ocenia osobnika wzgledem dlugosci n"
    @param osobni osobnik do oceny
    @return wspolczynnik przystosowania si�
*/
double funkcja2(const osobnik& osobni);

/**
    @brief Funkcja zapisujaca osobnikow niewymierajacych oraz osobnikow rozmnazajacych sie
    @param POPA populacja przeszukiwana
    @param ws_wymier wspolczynnik wymierania
    @param ws_rozm wspolczynnik rozmnazania sie
    @return pare populacji 1.niewymirajacych 2.rozmnazajacych
*/
std::pair<populacja, populacja> wymieranie_rozmnazanie(const populacja& POPA, const double ws_wymier, const double ws_rozm);

/**
    @brief Funkcja krzyzuje dwoch osobnikow tworzac dwoch osobnikow
    @param POPB populacja w ktorej zachodzi krzyzowanie
    @return zwraca dwoch osobnikow powstalych dzieki krzyzowaniu
*/
std::pair<osobnik, osobnik> krzyzowanie(const populacja& POPB);

/**
    @brief Funkcja wpisuje populacje POP do populacji POPA
    @param POP populacja ktora wpisujemy
    @param POPA populacja do ktorej wpisujemy
    @return funkcja nic nie zwraca, lecz modyfikuje POPA
*/
void wpisanie(const populacja& POP, populacja& POPA);

#endif
