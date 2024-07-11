#include <string>
#include <fstream>
#include <iostream>
#include <unordered_map>
#include <map>

#include "struktury.h"
#include "funkcje.h"


int main(int ile, char* params[])
{
	double (*pf1) (const osobnik&) = &funkcja2;             //preferowana dl 10
	//double (*pf1) (const osobnik&) = &funkcja3;			  //preferowana srednia arytmetyczna 55
	//double (*pf1) (const osobnik&) = &funkcja4;			  //preferowana dl 15 i preferowana liczba dziesiatek to 4    (wiekszy piorytet ma ilosc dziesiatek)
	//double (*pf1) (const osobnik&) = &funkcja5;             //preferowane osobniki z ta sama iloscia liczb parzystych i nieparzystych
	int z = sprawdzanie_przel(ile, params);
	if (z == 1) {
		return 0;
	}
	std::map<std::string, char*> przelaczniki = f_przel(ile, params);

	double ws_wymier = atof(przelaczniki["-w"]);
	double ws_rozm = atof(przelaczniki["-r"]);
	int il_pokolen = atoi(przelaczniki["-p"]);
	int il_krzyzowan = atoi(przelaczniki["-k"]);
	std::string nazw_pliku_wejscia = std::string(przelaczniki["-i"]);
	std::string nazw_pliku_wyjscia = std::string(przelaczniki["-o"]);

	std::cout << "ws_wymier           " << ws_wymier << std::endl;
	std::cout << "ws_rozm             " << ws_rozm << std::endl;
	std::cout << "il_pokolen          " << il_pokolen << std::endl;
	std::cout << "il_krzyzowan        " << il_krzyzowan << std::endl;
	std::cout << "nazw_pliku_wejscia  " << nazw_pliku_wejscia << std::endl;
	std::cout << "nazw_pliku_wyjscia  " << nazw_pliku_wyjscia << std::endl;

	file_generator(nazw_pliku_wejscia, 2000, 45, 1, 100, 1);

	/////////////////////////////////////////////////////////////////////////////////////////////// tutaj zaczynam projekt 
	
	populacja POPA = odczyt(nazw_pliku_wejscia);
	populacja POPB;           
	POPA.pf = *pf1;

	std::pair<populacja, populacja> paraA = wymieranie_rozmnazanie(POPA, ws_wymier, ws_rozm);
	POPA = paraA.first;
	POPA.pf = *pf1;
	POPB = paraA.second;

	if (POPA.osobniki.size() <= 1) {
		std::cout << "osobniki wymarły";
		wypisz_populacje(POPA);
		return 0;
	}

	if (POPB.osobniki.size() <= 1) {
		std::cout << "osobniki sie nie rozmnazaja";
		return 0;
	}


	for (int powt = 0; powt < il_pokolen; powt++) {
		populacja POPC;
		POPC.pf = *pf1;
		for (int krzyzowka = 0; krzyzowka < il_krzyzowan; krzyzowka++) {
			std::pair<osobnik, osobnik> para = krzyzowanie(POPB);
			POPC.osobniki.push_back(para.first);
			POPC.osobniki.push_back(para.second);
		}
		std::pair<populacja, populacja> paraC = wymieranie_rozmnazanie(POPC, ws_wymier, ws_rozm);
		wpisanie(paraC.first, POPA);
		wpisanie(paraC.second, POPB);
	}
	

	wypisz_populacje(POPA);

	zapisz_do_pliku(POPA, nazw_pliku_wyjscia);
 

	return 0;
}

