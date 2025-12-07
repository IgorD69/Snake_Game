/**
 * @file CmdListener.hpp
 * @brief Definirea clasei CmdListener pentru input în terminal
 *
 * @project Snake Game
 * @author Dodan Igor
 * @date 2025
 *
 * Acest fișier conține definirea clasei CmdListener care implementează
 * AbstractListener pentru input în linia de comandă folosind termios
 * (Linux/Unix/macOS).
 */

#pragma once

#include "AbstractListener.hpp"

/**
 * @class CmdListener
 * @brief Implementare a input-ului pentru terminal
 *
 * CmdListener gestionează input-ul de la tastatură în modul terminal
 * folosind biblioteca termios pentru configurare non-canonică și
 * non-blocking I/O.
 *
 * Caracteristici:
 * - Input non-blocant (nu blochează executia programului)
 * - Modul raw (citește fiecare tastă individual, fără buffer)
 * - Nu afișează caracterele apăsate (no echo)
 * - Restaurează setările terminalului la distrugere
 *
 * @note Funcționează doar pe sisteme POSIX (Linux, macOS, Unix)
 * @warning Modifică setările terminalului - trebuie restaurate corect
 *
 * @code
 * CmdListener listener;
 * while (true) {
 *     if (listener.IsKeyPressed(0)) {
 *         char key = listener.OnKeyPress();
 *         if (key == 'q') break;
 *     }
 * }
 * // Setările terminalului sunt restaurate automat la distrugere
 * @endcode
 */
class CmdListener : public AbstractListener {
public:
    /**
     * @brief Constructor
     *
     * Inițializează listener-ul și configurează terminalul pentru:
     * - Modul non-canonic (ICANON disabled)
     * - Echo-ul dezactivat (ECHO disabled)
     * - I/O non-blocant (O_NONBLOCK)
     *
     * Salvează setările vechi ale terminalului pentru restaurare ulterioară.
     *
     * @note Modifică setările globale ale terminalului
     */
    CmdListener();

    /**
     * @brief Destructor
     *
     * Restaurează setările originale ale terminalului salvate în constructor.
     * Esențial pentru a nu lăsa terminalul într-o stare inconsistentă.
     *
     * @note Apelat automat la distrugerea obiectului
     */
    ~CmdListener() override;

    /**
     * @brief Citește următorul caracter din input
     * @return char Caracterul citit sau 0 dacă nu există input
     *
     * Încearcă să citească un caracter din stdin în mod non-blocant.
     *
     * @return Caracterul apăsat dacă există, 0 altfel
     *
     * @code
     * CmdListener listener;
     * char ch = listener.OnKeyPress();
     * if (ch != 0) {
     *     std::cout << "Ai apăsat: " << ch << std::endl;
     * }
     * @endcode
     *
     * @note Metodă non-blocantă - returnează imediat chiar dacă nu există input
     */
    char OnKeyPress() override;

    /**
     * @brief Verifică dacă există input disponibil
     * @param key Parametru nefolosit (pentru compatibilitate cu interfața)
     * @return true dacă există input disponibil, false altfel
     *
     * Folosește select() pentru a verifica instant dacă există date
     * disponibile în stdin fără a le citi efectiv.
     *
     * @code
     * CmdListener listener;
     * if (listener.IsKeyPressed(0)) {
     *     char ch = listener.OnKeyPress();
     *     // Procesează input-ul
     * }
     * @endcode
     *
     * @note Timeout-ul este 0, deci verificarea este instantanee
     * @note Parametrul key nu este folosit în această implementare
     */
    bool IsKeyPressed(int key) override;
};
