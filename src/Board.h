//
// Created by Raphael Straub on 31.03.19.
//

#ifndef INC_4GEWINNT_BOARD_H
#define INC_4GEWINNT_BOARD_H


#include "State.h"
#include "debug.hpp"

class Board {
public:
    Board();
    State getState(int pos) const;

    bool add(int row, State player);

    bool checkWin();
private:
    State field[42] = {State::BLANK};

    bool winHorizontal(int pos);
    bool winVertical(int pos);
    bool winDiagonal(int pos);
};


#endif //INC_4GEWINNT_BOARD_H
