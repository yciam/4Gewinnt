//
// Created by Raphael Straub on 31.03.19.
//

#ifndef INC_4GEWINNT_GAME_H
#define INC_4GEWINNT_GAME_H


#include <SDL2/SDL.h>
#include <unordered_map>
#include "Board.h"

/**
 * @class Game
 * @brief Here the Game happens
 */
class Game {
public:
    /**
     * @brief Constructor
     */
    Game();

    /**
     * @brief Destructor
     */
    ~Game();

    /**
     * @brief Call on time to run the game
     */
    void run();

private:

    /**
     * @brief Handles the events
     */
    void handleEvents();

    /**
     * @brief Draws the Board
     * @param board the Board you wanna draw
     */
    void draw(Board board);

    /**
     * @brief Checks if the all keys you pressed are released
     */
    void checkRelease();

    /**
     * @brief do a Move if a Key is pressed
     */
    void doMove();

    /**
     * @brief Displays the time in the Bottom Left corner
     */
    void showTime();

    SDL_Window *win;
    SDL_Renderer *renner;
    SDL_Event event;
    std::unordered_map<int, int> keys;
    bool running = true;
    bool waitForRelease = false;
    Board board;
    State player = State::YELLOW;
    std::chrono::time_point<std::chrono::system_clock> time;
};


#endif //INC_4GEWINNT_GAME_H
