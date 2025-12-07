/**
 * @file Map.hpp
 * @brief Definirea clasei Map pentru gestionarea hărții jocului
 *
 * @project Snake Game
 * @author Dodan Igor
 * @date 2025
 *
 * Acest fișier conține definirea clasei Map care reprezintă
 * spațiul de joc în care se mișcă șarpele. Harta are dimensiuni
 * fixe (lățime și înălțime) și oferă funcții pentru verificarea limitelor.
 */

#pragma once

#include <iostream>

/**
 * @class Map
 * @brief Clasă pentru reprezentarea hărții jocului Snake
 *
 * Map stochează dimensiunile hărții de joc și oferă funcționalități
 * pentru verificarea limitelor și compararea hărților.
 *
 * @note Coordonatele valide sunt în intervalul [0, width) și [0, height)
 * @note Dimensiunea implicită este 40x40 unități
 */
class Map {
   int width;  ///< Lățimea hărții (număr de unități pe orizontală)
   int height; ///< Înălțimea hărții (număr de unități pe verticală)

public:
   /**
    * @brief Constructor cu dimensiuni opționale
    * @param width Lățimea hărții (implicit 40)
    * @param height Înălțimea hărții (implicit 40)
    *
    * Creează o hartă cu dimensiunile specificate.
    *
    * @code
    * Map defaultMap;           // Hartă 40x40
    * Map customMap(60, 30);    // Hartă 60x30
    * @endcode
    *
    * @warning Dimensiunile trebuie să fie pozitive
    */
   Map(int width = 40, int height = 40);

   /**
    * @brief Constructor de copiere
    * @param other Harta de copiat
    *
    * Creează o copie exactă a unei alte hărți, inclusiv dimensiunile.
    */
   Map(const Map& other);

   /**
    * @brief Obține lățimea hărții
    * @return int Lățimea în unități
    *
    * Returnează numărul de unități pe orizontală.
    *
    * @code
    * Map map(60, 30);
    * int w = map.GetWidth();  // w = 60
    * @endcode
    */
   int GetWidth() const;

   /**
    * @brief Obține înălțimea hărții
    * @return int Înălțimea în unități
    *
    * Returnează numărul de unități pe verticală.
    *
    * @code
    * Map map(60, 30);
    * int h = map.GetHeight();  // h = 30
    * @endcode
    */
   int GetHeight() const;

   /**
    * @brief Operator de atribuire
    * @param other Harta sursă
    * @return Map Referință la obiectul curent
    *
    * Copiază dimensiunile din altă hartă în harta curentă.
    */
   Map operator = (const Map& other);

   /**
    * @brief Operator de egalitate
    * @param other Harta de comparat
    * @return true dacă hărțile au aceleași dimensiuni, false altfel
    *
    * Compară două hărți verificând dacă au aceeași lățime și înălțime.
    *
    * @code
    * Map map1(40, 40);
    * Map map2(40, 40);
    * if (map1 == map2) {
    *     std::cout << "Hărțile au aceleași dimensiuni\n";
    * }
    * @endcode
    */
   bool operator == (const Map& other) const;
};

/**
 * @brief Operator de intrare pentru citirea unei hărți
 * @param in Stream-ul de intrare
 * @param board Harta în care se va citi
 * @return Referință la stream-ul de intrare
 *
 * Citește dimensiunile hărții din stream în format "width height".
 *
 * @code
 * Map map;
 * std::cin >> map;  // Citește "60 30" de la intrare
 * @endcode
 */
std::istream& operator >> (std::istream& in, Map& board);

/**
 * @brief Operator de ieșire pentru afișarea unei hărți
 * @param out Stream-ul de ieșire
 * @param board Harta de afișat
 * @return Referință la stream-ul de ieșire
 *
 * Scrie dimensiunile hărții în stream în format "width height".
 *
 * @code
 * Map map(60, 30);
 * std::cout << map;  // Afișează "60 30"
 * @endcode
 */
std::ostream& operator << (std::ostream& out, const Map& board);
