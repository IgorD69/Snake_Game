/**
 * @file Position.hpp
 * @brief Definirea structurii Position pentru gestionarea coordonatelor în joc
 *
 * @project Snake Game
 * @author Dodan Igor
 * @date 2025
 *
 * Acest fișier conține definirea structurii Position care reprezintă
 * coordonatele 2D ale obiectelor din joc (șarpe, măr, etc.).
 */

#pragma once

#include <iostream>

/**
 * @struct Position
 * @brief Structură pentru reprezentarea unei poziții 2D în spațiul jocului
 *
 * Position stochează coordonatele x și y și oferă operații de bază
 * pentru manipularea și compararea pozițiilor.
 *
 * @note Coordonatele pornesc de la (0,0) în colțul stânga-sus
 */
struct Position {
   int x; ///< Coordonata X (orizontală)
   int y; ///< Coordonata Y (verticală)

   /**
    * @brief Constructor cu parametri opționali
    * @param _x Coordonata X (implicit 0)
    * @param _y Coordonata Y (implicit 0)
    *
    * Creează o nouă poziție cu coordonatele specificate.
    * Dacă nu sunt furnizate parametri, inițializează poziția la (0,0).
    *
    * @code
    * Position origin;           // Creează poziția (0,0)
    * Position pos(10, 20);      // Creează poziția (10,20)
    * @endcode
    */
   Position(int _x = 0, int _y = 0);

   /**
    * @brief Constructor de copiere
    * @param other Poziția de copiat
    *
    * Creează o copie exactă a unei alte poziții.
    */
   Position(const Position& other);

   /**
    * @brief Operator de atribuire
    * @param other Poziția sursă
    * @return Referință la obiectul curent
    *
    * Copiază valorile coordonatelor din altă poziție.
    */
   Position operator = (const Position& other);

   /**
    * @brief Operator de egalitate
    * @param other Poziția de comparat
    * @return true dacă pozițiile sunt identice, false altfel
    *
    * Compară două poziții verificând dacă au aceleași coordonate x și y.
    *
    * @code
    * Position p1(5, 10);
    * Position p2(5, 10);
    * if (p1 == p2) {
    *     std::cout << "Pozițiile sunt identice\n";
    * }
    * @endcode
    */
   bool operator == (const Position& other) const;
};

/**
 * @brief Operator de intrare pentru citirea unei poziții
 * @param in Stream-ul de intrare
 * @param point Poziția în care se va citi
 * @return Referință la stream-ul de intrare
 *
 * Citește două valori întregi (x și y) din stream și le atribuie poziției.
 * Format așteptat: "x y"
 */
std::istream& operator >> (std::istream& in, Position& point);

/**
 * @brief Operator de ieșire pentru afișarea unei poziții
 * @param out Stream-ul de ieșire
 * @param point Poziția de afișat
 * @return Referință la stream-ul de ieșire
 *
 * Scrie coordonatele poziției în format "x y".
 */
std::ostream& operator << (std::ostream& out, const Position& point);
