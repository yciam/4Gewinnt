//
// Created by Raphael Straub on 31.03.19.
//

#include <SDL_ttf.h>
#include "Game.h"
#include "./definitions.hpp"
#include "utilities.h"

Game::Game() {
    // SDL Init
    if(SDL_Init(SDL_INIT_EVERYTHING) != 0)
        DEB_ERR(SDL_GetError())
    if (TTF_Init() != 0) {
        DEB_ERR(SDL_GetError())
        DEB_ERR(TTF_GetError())
        SDL_Quit();
        return;
    }
    this->win = SDL_CreateWindow("4Gewinnt", 100, 200, 1000, 800, SDL_WINDOW_SHOWN);
    if(win == nullptr){
        DEB_ERR(SDL_GetError())
        SDL_Quit();
        return;
    }
    this->renner = SDL_CreateRenderer(this->win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if(renner == nullptr){
        SDL_DestroyWindow(this->win);
        DEB_ERR(SDL_GetError())
        SDL_Quit();
        return;
    }
    SDL_SetWindowResizable(this->win, SDL_TRUE);
}

Game::~Game() {
    SDL_DestroyRenderer(this->renner);
    SDL_DestroyWindow(this->win);
    SDL_Quit();
}

void Game::run() {
    while(this->running){
        SDL_SetRenderDrawColor(this->renner, 0, 10, 0, 0);
        SDL_RenderClear(this->renner);

        this->handleEvents();
        this->draw(this->board);
        this->doMove();
        this->running &= !this->board.checkWin();

        SDL_RenderPresent(this->renner);
        SDL_Delay(1);
    }
}

void Game::doMove() {
    for(auto i = '1'; i <= '7' && !this->waitForRelease; i++){
        if(this->keys[i]){
            if(this->board.add(i-'0',this->player)){
                this->player = this->player == State::RED ? State::YELLOW : State::RED;
                this->waitForRelease = true;
                return;
            }
        }
    }
}

void Game::handleEvents() {
    while (SDL_PollEvent(&this->event)) {
        switch(this->event.type){
            case SDL_QUIT: this->running = false; break;
            case SDL_KEYDOWN: this->keys[this->event.key.keysym.sym] = 1; break;
            case SDL_KEYUP: this->keys[this->event.key.keysym.sym] = 0; this->checkRelease(); break;
        }
    }
}

void Game::draw(Board board) {
    SDL_Color fieldColor;
    int wx, wy, picsize, xr, yr;
    SDL_GetWindowSize(win, &wx, &wy);
    for (auto y = 0; y < 7; y++) {
        for (auto x = 0; x < 6; x++) {
            fieldColor = {100,100,100,0};
            picsize = (wx < wy ? wx : wy) / 7;
            yr = picsize == wy / 7 ? (wx - wy) / 2 : 0;
            xr = picsize == wy / 7 ? 0 : (wy - wx) / 2;
            SDL_Rect dst = {y * (picsize) + yr, x * (picsize) + xr + picsize/2, picsize, picsize};
            SDL_SetRenderDrawColor(renner, fieldColor.r, fieldColor.g, fieldColor.b, SDL_ALPHA_OPAQUE);
            SDL_RenderFillRect(renner, &dst);
            SDL_SetRenderDrawColor(renner, 255, 255, 255, SDL_ALPHA_OPAQUE);
            SDL_RenderDrawRect(renner, &dst);

            if(this->board.getState(y+7*x) != State::BLANK){
                this->board.getState(y+7*x) == State::RED ? fieldColor = {200,50,0,0} : fieldColor = {240,200,0,0};
                utilities::drawCircle(dst, fieldColor, this->renner);
            }
        }
    }
}

void Game::checkRelease() {
    for(auto i = '1'; i <= '7'; i++){
        if(this->keys[i]) return;
    }
    this->waitForRelease = false;
}
