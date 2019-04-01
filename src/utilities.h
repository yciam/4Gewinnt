//
// Created by Raphael Straub on 01.04.19.
//

#ifndef INC_4GEWINNT_UTILITIES_H
#define INC_4GEWINNT_UTILITIES_H


#include <SDL_rect.h>
#include <SDL_render.h>

/**
 * @namespace utilities
 */
namespace utilities {
    /**
     * @brief Draws the Circle
     * @param rect the Destination of the Circle
     * @param color the Color of the Circle (Border will be White)
     * @param renner will render the Circle 
     */
    void drawCircle(SDL_Rect rect, SDL_Color color, SDL_Renderer* renner);
};


#endif //INC_4GEWINNT_UTILITIES_H
