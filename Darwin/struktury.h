/** @file  */

#ifndef STRUKTURY_H
#define STRUKTURY_H


#include <vector>


/// @brief Struktura reprezentuje chromosom
/// @brief ktory zawiera informacje genach
struct chromosom
{
	std::vector<int> geny; ///< wektor liczb calkowitych przechowujacy geny jednego osobnika
};






/// @brief Struktura reprezentuje osobnika
/// @brief ktory zawiera informacje o chromosomach
struct osobnik
{
	chromosom jadro;  ///< jadro osobnika przechowujace informacje o chromosomie
};






/// @brief Struktura reprezentuje populacje
/// @brief ktora zawiera osobnikow oraz wskaznik do funkcji oceny
struct populacja
{
	std::vector<osobnik> osobniki;   ///< wektor osobnikow przechowujacy informacje o osobnikach
	double (*pf) (const osobnik&);   ///< funkcja oceny osobnikow w populacji


};

#endif
