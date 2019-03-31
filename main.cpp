#include "./src/definitions.hpp"
#include <SDL2/SDL.h>
#include <src/Game.h>

int filter(void *argumente, SDL_Event *event) {
    return (event->type != SDL_MULTIGESTURE &&
            event->type != SDL_DOLLARGESTURE && event->type != SDL_MULTIGESTURE &&
            event->type != SDL_FINGERMOTION && event->type != SDL_FINGERDOWN &&
            event->type != SDL_FINGERUP);
}

int main() {
    Game spiel;
    spiel.run();
    return 0;
}