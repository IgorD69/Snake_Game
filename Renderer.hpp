/**
 * @file Renderer.hpp
 * @brief Definirea clasei Renderer pentru randare cu Raylib
 *
 * @project Snake Game
 * @author Dodan Igor
 * @date 2025
 *
 * Acest fișier conține definirea clasei Renderer care implementează
 * AbstractRenderer pentru randare grafică folosind biblioteca Raylib.
 * Oferă o interfață grafică modernă cu fereastră dedicată și culori.
 */

#pragma once

#include "Abstract_Renderer.hpp"
#include <raylib.h>

/**
 * @class Renderer
 * @brief Implementare a randării grafice folosind Raylib
 *
 * Renderer gestionează afișarea grafică a jocului într-o fereastră
 * dedicată folosind biblioteca Raylib. Oferă:
 * - Fereastră grafică redimensionabilă
 * - Randare pe bază de grilă (grid-based)
 * - Culori diferite pentru elemente (verde=șarpe, roșu=măr)
 * - Text pentru scor și mesaje
 * - Control al frame rate-ului
 *
 * Sistemul de coordonate:
 * - Fiecare celulă din joc ocupă cellSize x cellSize pixeli
 * - Coordonatele (0,0) sunt în colțul stânga-sus
 *
 * @note Necesită biblioteca Raylib instalată și linkată
 */
class Renderer : public AbstractRenderer {
private:
    int windowWidth;   ///< Lățimea ferestrei în pixeli
    int windowHeight;  ///< Înălțimea ferestrei în pixeli
    int cellSize;      ///< Dimensiunea unei celule de joc în pixeli
    Font font;         ///< Font-ul folosit pentru text

public:
    /**
     * @brief Constructor cu parametri opționali
     * @param width Lățimea ferestrei în pixeli (implicit 800)
     * @param height Înălțimea ferestrei în pixeli (implicit 600)
     * @param cellSize Dimensiunea unei celule în pixeli (implicit 20)
     *
     * Inițializează fereastra Raylib și configurează sistemul de randare:
     * - Creează fereastra cu dimensiunile specificate
     * - Setează FPS-ul țintă la 60
     * - Încarcă font-ul implicit
     *
     * @code
     * Renderer renderer(1024, 768, 25);  // Fereastră 1024x768, celule de 25px
     * @endcode
     *
     * @note Fereastra este creată cu titlul "Snake Game"
     * @warning Trebuie apelat CloseWindow() sau distrugătorul pentru cleanup
     */
    Renderer(int width = 800, int height = 600, int cellSize = 20);

    /**
     * @brief Destructor
     *
     * Închide fereastra Raylib și eliberează resursele alocate.
     *
     * @note Apelat automat la distrugerea obiectului
     */
    ~Renderer() override;

    /**
     * @brief Șterge ecranul
     *
     * În Raylib, această metodă este goală deoarece ștergerea este
     * gestionată automat de BeginDrawing()/EndDrawing().
     *
     * @note Funcția este prezentă pentru compatibilitate cu interfața
     */
    void ClearScreen() override;

    /**
     * @brief Desenează imaginea jocului
     * @param topLeft Poziția de start pentru desenare (offset în pixeli)
     * @param bottomRight Nefolosit (păstrat pentru compatibilitate)
     * @param image Matricea de caractere reprezentând jocul
     *
     * Parcurge imaginea și desenează fiecare celulă ca un dreptunghi colorat:
     * - 'O' → Verde (șarpe)
     * - '@' → Roșu (măr)
     * - '.' → Nu se desenează (transparent)
     * - '#' → Alb (pereți)
     *
     * @code
     * GameImage img(20, std::string(40, '.'));
     * img[10][20] = '@';
     * renderer.DrawImage(Position(10, 10), Position(0, 0), img);
     * @endcode
     *
     * @note Fiecare celulă este desenată cu 2px padding (cellSize - 2)
     */
    void DrawImage(Position topLeft, Position bottomRight, const GameImage& image) override;

    /**
     * @brief Scrie text pe ecran
     * @param position Poziția textului (în pixeli)
     * @param text Textul de afișat
     *
     * Afișează textul la poziția specificată folosind font-ul implicit
     * cu dimensiunea 20 și culoarea albă.
     *
     * @code
     * renderer.WriteText(Position(10, 550), "Score: 15");
     * renderer.WriteText(Position(300, 300), "GAME OVER!");
     * @endcode
     */
    void WriteText(Position position, const std::string& text) override;

    // Metode specifice Raylib

    /**
     * @brief Verifică dacă fereastra trebuie închisă
     * @return true dacă utilizatorul a cerut închiderea ferestrei, false altfel
     *
     * Wrapper peste WindowShouldClose() din Raylib.
     * Folosit în loop-ul principal pentru a determina când să oprească jocul.
     *
     * @code
     * while (!renderer.ShouldClose()) {
     *     // Loop-ul de joc
     * }
     * @endcode
     */
    bool ShouldClose() const;

    /**
     * @brief Începe un nou frame de desenare
     *
     * Trebuie apelat înaintea oricăror operații de desenare.
     * Șterge ecranul cu culoarea neagră și pregătește buffer-ul de randare.
     *
     * @code
     * renderer.BeginDrawing();
     * renderer.DrawImage(...);  // Desenează jocul
     * renderer.WriteText(...);  // Scrie text
     * renderer.EndDrawing();
     * @endcode
     *
     * @note Trebuie urmat întotdeauna de EndDrawing()
     */
    void BeginDrawing();

    /**
     * @brief Finalizează frame-ul de desenare
     *
     * Trebuie apelat după toate operațiile de desenare.
     * Afișează buffer-ul pe ecran și sincronizează cu FPS-ul țintă.
     *
     * @note Trebuie precedat de BeginDrawing()
     */
    void EndDrawing();
};
