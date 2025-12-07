/**
 * @file AbstractListener.hpp
 * @brief Definirea interfeței AbstractListener pentru input
 *
 * @project Snake Game
 * @author Dodan Igor
 * @date 2025
 *
 * Acest fișier conține definirea interfeței AbstractListener care
 * oferă o abstracție pentru sistemele de input (keyboard listener).
 * Permite implementări diferite pentru diverse platforme sau contexte.
 */

#pragma once

/**
 * @struct AbstractListener
 * @brief Interfață abstractă pentru sistemele de input
 *
 * AbstractListener definește contractul pentru toate clasele care
 * gestionează input-ul de la utilizator. Folosește pattern-ul
 * Strategy pentru a permite schimbarea sistemului de input la runtime.
 *
 * Implementările concrete pot include:
 * - CmdListener pentru input în terminal (folosind termios)
 * - WindowListener pentru input în ferestre grafice
 *
 * @note Toate metodele sunt pure virtual și trebuie implementate de clasele derivate
 */
struct AbstractListener {
    /**
     * @brief Destructor virtual
     *
     * Asigură că destructorii claselor derivate sunt apelați corect
     * când obiectele sunt șterse prin pointeri la clasa de bază.
     */
    virtual ~AbstractListener() = default;

    /**
     * @brief Așteaptă și returnează următoarea tastă apăsată
     * @return char Caracterul corespunzător tastei apăsate
     *
     * Metodă blocantă care așteaptă ca utilizatorul să apese o tastă
     * și returnează caracterul corespunzător.
     *
     * @code
     * AbstractListener* listener = new CmdListener();
     * char key = listener->OnKeyPress();  // Așteaptă input
     * if (key == 'w') {
     *     // Mișcă în sus
     * }
     * @endcode
     *
     * @note Implementarea concretă depinde de platforma/contextul de input
     */
    virtual char OnKeyPress() = 0;

    /**
     * @brief Verifică dacă o tastă specifică este apăsată
     * @param key Codul tastei de verificat
     * @return true dacă tasta este apăsată, false altfel
     *
     * Metodă non-blocantă care verifică instant starea unei taste.
     * Util pentru verificări rapide în loop-ul de joc.
     *
     * @code
     * AbstractListener* listener = new CmdListener();
     * if (listener->IsKeyPressed('w')) {
     *     // Tasta W este apăsată chiar acum
     * }
     * @endcode
     *
     * @note Parametrul key poate fi cod ASCII sau cod specific platformei
     */
    virtual bool IsKeyPressed(int key) = 0;
};
