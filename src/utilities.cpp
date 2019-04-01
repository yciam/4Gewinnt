//
// Created by Raphael Straub on 01.04.19.
//

#include "utilities.h"

void utilities::drawCircle(SDL_Rect rect, SDL_Color color, SDL_Renderer* renner) {
    for(auto y = rect.y; y < rect.y + rect.h; y++)
        for(auto x = rect.x; x < rect.x + rect.w; x++)
            if(sqrt(pow(x-(rect.x+rect.w/2),2) + pow(y-(rect.y+rect.h/2),2)) < rect.w/2.0-rect.w/40.0){
                SDL_SetRenderDrawColor(renner, color.r, color.g, color.b, color.a);
                SDL_RenderDrawPoint(renner, x, y);
            }else if(sqrt(pow(x-(rect.x+rect.w/2),2) + pow(y-(rect.y+rect.h/2),2)) < rect.w/2.0-rect.w/100.0){
                SDL_SetRenderDrawColor(renner, 200, 200, 200, color.a);
                SDL_RenderDrawPoint(renner, x, y);
            }
}