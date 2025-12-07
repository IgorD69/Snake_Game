/**
 * @file Player.hpp
 * @brief Definirea clasei Player pentru gestionarea șarpelui
 *
 * @project Snake Game
 * @author Dodan Igor
 * @date 2025
 *
 * Acest fișier conține definirea clasei Player care reprezintă
 * șarpele controlat de jucător. Șarpele este format din segmente
 * și poate să se miște, să crească și să verifice coliziuni.
 */

#pragma once

#include "Apple.hpp"
#include "Position.hpp"
#include "Direction.hpp"
#include <vector>

/**
 * @class Player
 * @brief Clasă pentru reprezentarea șarpelui în joc
 *
 * Player gestionează toate aspectele legate de șarpe: poziția,
 * mișcarea, creșterea atunci când mănâncă mere, și verificarea
 * coliziunilor cu sine sau cu pereții.
 *
 * Șarpele este format dintr-o listă de segmente (Position),
 * unde primul segment este capul șarpelui.
 *
 * @note Capul șarpelui este întotdeauna la indexul 0 în vectorul de segmente
 */
class Player {
   std::vector<Position> _segments; ///< Lista segmentelor șarpelui (capul la index 0)

public:
   /**
    * @brief Constructor implicit
    *
    * Creează un șarpe gol (fără segmente).
    * Trebuie să adăugați manual segmente sau să folosiți constructorul cu poziție.
    */
   Player();

   /**
    * @brief Constructor cu poziție inițială
    * @param _position Poziția de start a șarpelui (capul)
    *
    * Creează un șarpe cu un singur segment (capul) la poziția specificată.
    *
    * @code
    * Position start(20, 20);
    * Player snake(start);  // Șarpe cu capul la (20, 20)
    * @endcode
    */
   Player(const Position& _position);

   /**
    * @brief Mișcă șarpele într-o direcție
    * @param direction Direcția în care se mișcă șarpele
    *
    * Mută șarpele cu o unitate în direcția specificată.
    * Capul se mișcă în direcția dată, iar restul segmentelor
    * urmează capul. Ultimul segment dispare (dacă nu s-a mâncat un măr).
    *
    * @code
    * Player snake(Position(10, 10));
    * snake.Move(Direction::RIGHT);  // Mișcă la dreapta
    * @endcode
    *
    * @note Dacă șarpele tocmai a mâncat un măr, ultimul segment nu dispare
    */
   void Move(Direction direction);

   /**
    * @brief Obține numărul de segmente ale șarpelui
    * @return int Numărul total de segmente (lungimea șarpelui)
    *
    * Returnează lungimea curentă a șarpelui, care corespunde și cu scorul.
    *
    * @code
    * Player snake(Position(10, 10));
    * snake.Eat(apple);
    * int size = snake.GetSize();  // size = 2
    * @endcode
    */
   int GetSize() const;

   /**
    * @brief Obține poziția capului șarpelui
    * @return Position Poziția curentă a capului
    *
    * Returnează poziția primului segment (capul) al șarpelui.
    *
    * @code
    * Player snake(Position(10, 10));
    * Position head = snake.GetPosition();
    * @endcode
    */
   Position GetPosition() const;

   /**
    * @brief Obține toate segmentele șarpelui
    * @return std::vector<Position> Vector cu toate pozițiile segmentelor
    *
    * Returnează o copie a vectorului cu toate segmentele șarpelui,
    * unde primul element este capul.
    *
    * @code
    * Player snake(Position(10, 10));
    * auto segments = snake.GetSegments();
    * for (const auto& seg : segments) {
    *     // Procesează fiecare segment
    * }
    * @endcode
    *
    * @note Util pentru detectarea coliziunilor cu propriul corp
    */
   std::vector<Position> GetSegments() const;

   /**
    * @brief Șarpele mănâncă un măr
    * @param apple Mărul mâncat
    *
    * Crește șarpele cu un segment. Noul segment va fi adăugat
    * efectiv după următoarea mișcare.
    *
    * @code
    * Player snake(Position(10, 10));
    * Apple apple(Position(11, 10));
    * if (snake.GetPosition() == apple.GetPosition()) {
    *     snake.Eat(apple);  // Șarpele crește
    * }
    * @endcode
    *
    * @note Segmentul se adaugă la coadă și devine vizibil după următoarea mișcare
    */
   void Eat(const Apple& apple);
};
