/**
 * @file Abstract_Renderer.hpp
 * @brief Definirea interfeței AbstractRenderer pentru sistemul de randare
 *
 * @project Snake Game
 * @author Dodan Igor
 * @date 2025
 *
 * Acest fișier conține definirea interfeței AbstractRenderer care
 * oferă o abstracție pentru sistemele de randare grafică. Permite
 * implementări diferite (terminal, Raylib, SDL, etc.).
 */

#pragma once

#include "Position.hpp"
#include <vector>
#include <string>

/**
 * @typedef GameImage
 * @brief Tip alias pentru reprezentarea unei imagini de joc
 *
 * GameImage este un vector de șiruri de caractere, unde fiecare șir
 * reprezintă o linie din imagine. Fiecare caracter din șir reprezintă
 * un pixel/celulă din joc.
 *
 * Exemple de caractere:
 * - '.' = spațiu gol
 * - '#' = perete/margine
 * - 'O' = segment șarpe
 * - '@' = măr
 *
 * @code
 * GameImage image(20, std::string(40, '.'));  // Imagine 40x20 goală
 * image[10][20] = '@';  // Plasează măr la poziția (20, 10)
 * @endcode
 */
using GameImage = std::vector<std::string>;

/**
 * @struct AbstractRenderer
 * @brief Interfață abstractă pentru sistemele de randare
 *
 * AbstractRenderer definește contractul pentru toate clasele care
 * gestionează afișarea grafică a jocului. Folosește pattern-ul
 * Strategy pentru a permite schimbarea sistemului de randare.
 *
 * Implementările concrete pot include:
 * - CmdRenderer pentru randare în terminal (ncurses)
 * - Renderer pentru randare cu Raylib
 * - SDLRenderer pentru randare cu SDL
 *
 * @note Toate metodele sunt pure virtual și trebuie implementate de clasele derivate
 */
struct AbstractRenderer {
    /**
     * @brief Destructor virtual
     *
     * Asigură că destructorii claselor derivate sunt apelați corect
     * când obiectele sunt șterse prin pointeri la clasa de bază.
     */
    virtual ~AbstractRenderer() = default;

    /**
     * @brief Șterge ecranul
     *
     * Pregătește ecranul pentru un nou frame de randare.
     * În funcție de implementare, poate:
     * - Șterge terminalul și repoziționa cursorul
     * - Umple fereastra cu o culoare de fundal
     * - Reseta buffer-ul de randare
     *
     * @code
     * AbstractRenderer* renderer = new Renderer();
     * renderer->ClearScreen();  // Șterge ecranul
     * // Desenează noile elemente...
     * @endcode
     *
     * @note Apelată de obicei la începutul fiecărui frame
     */
    virtual void ClearScreen() = 0;

    /**
     * @brief Desenează o imagine în regiunea specificată
     * @param topLeft Colțul stânga-sus al regiunii de desenat
     * @param bottomRight Colțul dreapta-jos al regiunii de desenat (nefolosit în implementarea actuală)
     * @param image Imaginea de desenat (matrice de caractere)
     *
     * Randează imaginea jocului (harta, șarpele, mărul) pe ecran.
     * Fiecare caracter din imagine este interpretat și desenat cu
     * culoarea/stilul corespunzător:
     * - '.' = gol (nu se desenează)
     * - '#' = perete (alb/gri)
     * - 'O' = șarpe (verde)
     * - '@' = măr (roșu)
     *
     * @code
     * GameImage image(20, std::string(40, '.'));
     * image[10][20] = '@';  // Măr
     * image[10][21] = 'O';  // Șarpe
     * renderer->DrawImage(Position(0, 0), Position(800, 600), image);
     * @endcode
     *
     * @note Implementarea concretă decide cum se mapează caracterele la grafică
     */
    virtual void DrawImage(Position topLeft, Position bottomRight, const GameImage& image) = 0;

    /**
     * @brief Scrie text la o poziție specificată
     * @param position Poziția unde se scrie textul (colțul stânga-sus)
     * @param text Textul de afișat
     *
     * Afișează text pe ecran la coordonatele date.
     * Folosit pentru:
     * - Afișarea scorului
     * - Afișarea mesajelor (Game Over, instrucțiuni)
     * - Debugarea poziițiilor
     *
     * @code
     * renderer->WriteText(Position(10, 10), "Score: 5");
     * renderer->WriteText(Position(300, 300), "GAME OVER!");
     * @endcode
     *
     * @note Poziția poate fi în pixeli sau în caractere, depinde de implementare
     */
    virtual void WriteText(Position position, const std::string& text) = 0;
};
