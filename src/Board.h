//
// Created by Raphael Straub on 31.03.19.
//

#ifndef INC_4GEWINNT_BOARD_H
#define INC_4GEWINNT_BOARD_H


#include "State.h"
#include "debug.hpp"

/**
 * @class Board
 * @brief this Represents the Board you are playing on
 */
class Board {
public:

    /**
     * @brief Constructor of the Board
     */
    Board();

    /**
     * @brief get the State a specific position
     * @param pos the specific position
     * @return the State at the given Position
     */
    State getState(int pos) const;

    /**
     * @brief add a "coin" (?) at the given row if possible
     * @param row the row you wanna add the coin
     * @param player the Color of the Player playing
     * @return true if the addition of the coin was successfull
     */
    bool add(int row, State player);

    /**
     * @brief checks if the game is over
     * @return true if the game is over
     */
    bool checkWin();
private:
    State field[42] = {State::BLANK};

    /**
     * @brief checks if there is a Horizontal win
     * @param pos the position you wanna check
     * @return true if won
     */
    bool winHorizontal(int pos);

    /**
     * @brief checks if there is a Vertical win
     * @param pos the position you wanna check
     * @return true if won
     */
    bool winVertical(int pos);

    /**
     * @brief checks if there is a diagonal win
     * @param pos the position you wanna check
     * @return true if won
     */
    bool winDiagonal(int pos);
};


#endif //INC_4GEWINNT_BOARD_H
