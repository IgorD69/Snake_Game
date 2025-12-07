/**
 * @file Apple.hpp
 * @brief Definirea clasei Apple pentru gestionarea mărului în joc
 *
 * @project Snake Game
 * @author Dodan Igor
 * @date 2025
 *
 * Acest fișier conține definirea clasei Apple care reprezintă
 * mărul colectabil în jocul Snake. Mărul are o poziție și poate
 * fi plasat aleatoriu pe hartă.
 */

#pragma once

#include <iostream>
#include "Position.hpp"

/**
 * @class Apple
 * @brief Clasă pentru reprezentarea mărului în jocul Snake
 *
 * Apple stochează poziția mărului pe hartă și oferă funcționalități
 * pentru plasarea și verificarea poziției acestuia.
 *
 * @note Când șarpele mănâncă mărul, acesta trebuie replasat într-o poziție nouă
 */
class Apple {
   Position _position; ///< Poziția curentă a mărului pe hartă

public:
   /**
    * @brief Constructor implicit
    *
    * Creează un măr la poziția (0,0).
    * Această poziție poate fi modificată ulterior prin SetPosition().
    */
   Apple();

   /**
    * @brief Constructor cu poziție specificată
    * @param position Poziția inițială a mărului
    *
    * Creează un măr la poziția dată.
    *
    * @code
    * Position pos(10, 15);
    * Apple apple(pos);  // Măr la poziția (10,15)
    * @endcode
    */
   Apple(const Position& position);

   /**
    * @brief Constructor de copiere
    * @param other Mărul de copiat
    *
    * Creează o copie a unui alt măr, inclusiv poziția acestuia.
    */
   Apple(const Apple& other);

   /**
    * @brief Obține poziția curentă a mărului
    * @return Position Poziția mărului
    *
    * Returnează o copie a poziției curente a mărului pe hartă.
    *
    * @code
    * Apple apple(Position(5, 5));
    * Position pos = apple.GetPosition();
    * std::cout << "Mărul este la: " << pos << std::endl;
    * @endcode
    */
   Position GetPosition() const;

   /**
    * @brief Operator de atribuire
    * @param other Mărul sursă
    * @return Apple Referință la obiectul curent
    *
    * Copiază poziția din alt măr în mărul curent.
    */
   Apple operator = (const Apple& other);

   /**
    * @brief Operator de egalitate
    * @param other Mărul de comparat
    * @return true dacă mărele au aceeași poziție, false altfel
    *
    * Compară două mere verificând dacă se află la aceeași poziție.
    *
    * @code
    * Apple apple1(Position(5, 5));
    * Apple apple2(Position(5, 5));
    * if (apple1 == apple2) {
    *     std::cout << "Merele sunt la aceeași poziție\n";
    * }
    * @endcode
    */
   bool operator == (const Apple& other) const;
};

/**
 * @brief Operator de intrare pentru citirea unui măr
 * @param in Stream-ul de intrare
 * @param apple Mărul în care se va citi
 * @return Referință la stream-ul de intrare
 *
 * Citește poziția mărului din stream în format "x y".
 */
std::istream& operator >> (std::istream& in, Apple& apple);

/**
 * @brief Operator de ieșire pentru afișarea unui măr
 * @param out Stream-ul de ieșire
 * @param apple Mărul de afișat
 * @return Referință la stream-ul de ieșire
 *
 * Scrie poziția mărului în stream în format "x y".
 */
std::ostream& operator << (std::ostream& out, const Apple& apple);
