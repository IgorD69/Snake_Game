/**
 * @file Engine.hpp
 * @brief Definirea clasei Engine pentru gestionarea logicii jocului
 *
 * @project Snake Game
 * @author Dodan Igor
 * @date 2025
 *
 * Acest fișier conține definirea clasei Engine care orchestrează
 * întregul joc: inițializare, loop-ul principal, verificarea coliziunilor,
 * și integrarea cu sistemul de randare.
 */

#pragma once

#include "Map.hpp"
#include "Apple.hpp"
#include "Player.hpp"
// #include "Direction.hpp"

/**
 * @class Engine
 * @brief Clasă principală pentru gestionarea jocului Snake
 *
 * Engine este nucleul jocului care coordonează toate componentele:
 * - Inițializarea hărții, șarpelui și mărului
 * - Loop-ul principal de joc cu input, update, și render
 * - Detectarea coliziunilor cu pereții și cu propriul corp
 * - Gestionarea stării de game over și restart
 *
 * @note Folosește biblioteca Raylib pentru randare și input
 */
class Engine {
    Map map;        ///< Harta jocului (spațiul de joc)
    Player player;  ///< Șarpele controlat de jucător
    Apple apple;    ///< Mărul colectabil
    bool gameOver;  ///< Indicator pentru starea game over

public:
    /**
     * @brief Constructor implicit
     *
     * Creează engine-ul cu starea inițială.
     * Trebuie apelat Init() înainte de Run().
     */
    Engine();

    /**
     * @brief Inițializează sau resetează jocul
     *
     * Configurează toate componentele jocului:
     * - Creează o hartă 40x20
     * - Plasează șarpele în centrul hărții
     * - Plasează mărul la poziția inițială (5,5)
     * - Resetează starea gameOver la false
     * - Inițializează generatorul de numere aleatoare
     *
     * @code
     * Engine engine;
     * engine.Init();  // Pregătește jocul
     * engine.Run();   // Pornește loop-ul de joc
     * @endcode
     *
     * @note Poate fi apelat multiple ori pentru restart
     */
    void Init();

    /**
     * @brief Pornește loop-ul principal al jocului
     *
     * Rulează jocul în buclă până când:
     * - Jucătorul apasă Q sau ESC (închide jocul)
     * - Fereastra este închisă
     *
     * Loop-ul gestionează:
     * - Input-ul de la tastatură (WASD/săgeți pentru mișcare, R pentru restart)
     * - Update-ul logicii (mișcare șarpe, coliziuni, mâncat mere)
     * - Randarea grafică (hartă, șarpe, măr, scor, mesaje)
     *
     * @code
     * Engine engine;
     * engine.Init();
     * engine.Run();  // Intră în loop-ul de joc
     * @endcode
     *
     * @note Folosește timing pentru a controla viteza șarpelui (0.15s între mișcări)
     * @warning Trebuie apelat Init() înainte de Run()
     */
    void Run();

    /**
     * @brief Verifică dacă jocul s-a terminat
     * @return true dacă jocul este în starea game over, false altfel
     *
     * Interogare pentru verificarea stării jocului.
     *
     * @code
     * Engine engine;
     * engine.Init();
     * if (engine.IsFinished()) {
     *     std::cout << "Game Over!\n";
     * }
     * @endcode
     */
    bool IsFinished();

    /**
     * @brief Verifică coliziunile șarpelui
     * @return true dacă șarpele s-a lovit, false altfel
     *
     * Detectează două tipuri de coliziuni:
     * 1. Coliziune cu pereții - capul șarpelui depășește limitele hărții
     * 2. Coliziune cu propriul corp - capul atinge un alt segment al șarpelui
     *
     * @code
     * if (engine.CheckCollision()) {
     *     // Game Over - șarpele s-a lovit
     * }
     * @endcode
     *
     * @note Verifică doar capul șarpelui (primul segment)
     */
    bool CheckCollision();
};
