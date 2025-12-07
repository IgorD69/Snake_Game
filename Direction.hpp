/**
 * @file Direction.hpp
 * @brief Definirea enumerării Direction pentru direcțiile de mișcare
 *
 * @project Snake Game
 * @author Dodan Igor
 * @date 2025
 *
 * Acest fișier conține definirea enumerării Direction care reprezintă
 * cele patru direcții posibile de mișcare în joc (sus, jos, stânga, dreapta).
 * Include și funcții helper pentru conversia între direcții și caractere.
 */

#pragma once

#include <iostream>

/**
 * @enum Direction
 * @brief Enumerare pentru reprezentarea direcțiilor de mișcare
 *
 * Direction definește cele patru direcții cardinale în care se poate
 * mișca șarpele. Fiecare direcție este asociată cu o tastă WASD.
 *
 * @note Valorile sunt stocate ca caractere pentru mapare directă cu tastele
 */
enum class Direction: char {
   UP      = 'w',  ///< Mișcare în sus (tasta W)
   DOWN    = 's',  ///< Mișcare în jos (tasta S)
   LEFT    = 'a',  ///< Mișcare la stânga (tasta A)
   RIGHT   = 'd'   ///< Mișcare la dreapta (tasta D)
};

/**
 * @brief Convertește o direcție în șir de caractere
 * @param direction Direcția de convertit
 * @return std::string Reprezentarea textuală ("UP", "DOWN", "LEFT", "RIGHT")
 *
 * Returnează numele direcției ca șir de caractere pentru afișare
 * sau debugging.
 *
 * @code
 * Direction dir = Direction::UP;
 * std::string name = ToString(dir);  // name = "UP"
 * @endcode
 */
std::string ToString(const Direction& direction);

/**
 * @brief Convertește o direcție în caracter
 * @param direction Direcția de convertit
 * @return char Caracterul asociat ('w', 's', 'a', sau 'd')
 *
 * Returnează tasta asociată direcției.
 *
 * @code
 * Direction dir = Direction::UP;
 * char key = ToChar(dir);  // key = 'w'
 * @endcode
 */
char ToChar(const Direction& direction);

/**
 * @brief Convertește un caracter în direcție
 * @param c Caracterul de convertit ('w', 's', 'a', sau 'd')
 * @return Direction Direcția corespunzătoare
 * @throws std::invalid_argument Dacă caracterul nu este valid
 *
 * Creează o direcție din tasta apăsată de utilizator.
 *
 * @code
 * char input = 'w';
 * Direction dir = FromChar(input);  // dir = Direction::UP
 * @endcode
 *
 * @warning Aruncă excepție dacă caracterul nu este 'w', 's', 'a', sau 'd'
 */
Direction FromChar(char c);

/**
 * @brief Operator de ieșire pentru afișarea unei direcții
 * @param out Stream-ul de ieșire
 * @param direction Direcția de afișat
 * @return Referință la stream-ul de ieșire
 *
 * Scrie reprezentarea textuală a direcției în stream.
 *
 * @code
 * Direction dir = Direction::RIGHT;
 * std::cout << dir;  // Afișează "RIGHT"
 * @endcode
 */
std::ostream& operator<<(std::ostream& out, const Direction& direction);
