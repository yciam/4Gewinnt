//
// Created by Raphael Straub on 31.03.19.
//

#ifndef INC_4GEWINNT_GAME_H
#define INC_4GEWINNT_GAME_H


#include <SDL2/SDL.h>
#include <unordered_map>
#include "Board.h"

class Game {
public:
    Game();

    ~Game();

    void run();

private:
    void handleEvents();

    void draw(Board board);

    void checkRelease();

    void doMove();

    SDL_Window *win;
    SDL_Renderer *renner;
    SDL_Event event;
    std::unordered_map<int, int> keys;
    bool running = true;
    bool waitForRelease = false;
    Board board;
    State player = State::YELLOW;
};


#endif //INC_4GEWINNT_GAME_H
