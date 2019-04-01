//
// Created by Raphael Straub on 31.03.19.
//

#include "Board.h"
#include "debug.hpp"

State Board::getState(int pos) const {
    if(pos < 0 || pos > 42)
        DEB_ERR("Position out of Bounds (" +  _T(pos) + ")")
    return this->field[pos];
}

Board::Board() {
    /* There will be a purpose for this  */
}

bool Board::add(int row, State player) {
    if(row < 1 || row > 7){
        DEB_ERR("Row out of bounds (" + _T(row) + ")")
        return false;
    }
    if(this->field[row-1] != State::BLANK)
        return false;
    for(int i = row-1;; i += 7){
        if(this->field[i] != State::BLANK || i+7 > 49){
            this->field[i-7] = player;
            return true;
        }
    }
}

bool Board::checkWin() {
    bool stillBlank = false;

    for(auto i = 0; i < 42; i++){
        if(this->field[i] == State::BLANK)
            stillBlank = true;
        else{
            if(this->winHorizontal(i) || this->winVertical(i) || this->winDiagonal(i)){
                DEB_WAR("Winner detected")
                return true;
            }
        }
    }
    return !stillBlank;
}

bool Board::winHorizontal(int pos) {
    if(pos % 7 < 4){
        if(this->field[pos] == this->field[pos+1] && this->field[pos] == this->field[pos+2] && this->field[pos] == this->field[pos+3])
            return true;
    }
    return false;
}

bool Board::winVertical(int pos) {
    if(pos / 6 < 3){
        if(this->field[pos] == this->field[pos+7] && this->field[pos] == this->field[pos+14] && this->field[pos] == this->field[pos+21])
            return true;
    }
    return false;
}

bool Board::winDiagonal(int pos) {
    if(pos % 7 < 4 && pos / 6 < 3){
        if(this->field[pos] == this->field[pos+8] && this->field[pos] == this->field[pos+16] && this->field[pos] == this->field[pos+24])
            return true;
    }
    if(pos % 7 > 2 && pos / 6 < 3){
        if(this->field[pos] == this->field[pos+6] && this->field[pos] == this->field[pos+12] && this->field[pos] == this->field[pos+18])
            return true;
    }
    return false;
}
