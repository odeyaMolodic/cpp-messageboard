/**
 * message-board exercise
 * This program allows you to read or write ads on the board
 * And display it conveniently.
 * 
 * Author: Odeya Lavi
 * Since : 2021-04
 */

#include "Board.hpp"

#include <iostream>
#include <stdexcept>
using namespace std;

namespace ariel{

    void Board::resize(const unsigned int &row, const unsigned int &endRow, const unsigned int &column, const unsigned int &endCol, const unsigned int &length){
        minRows = min(minRows, row);
        maxRows = max(maxRows, endRow);
        minColumns = min(minColumns, column);
        maxColumns = max(maxColumns, endCol);
    }

    void Board::post(unsigned int row, unsigned int column, Direction direction, const string &message){
        unsigned int msgSize = message.size();
        unsigned int endRow;
        unsigned int endCol;
        
        if(direction == Direction::Vertical){
            for(unsigned int i = 0; i < msgSize; i++){
                board[row+i][column].letter = message.at(i);
            }
            endRow = row + msgSize-1;
            endCol = column;

        }else{
            for(unsigned int i = 0; i < msgSize; i++){
                board[row][column+i].letter = message.at(i);
            }
            endRow = row;
            endCol = column + msgSize-1;
        }

        resize(row, endRow, column, endCol, msgSize);
    }

    string Board::read(unsigned int row, unsigned int column, Direction direction, unsigned int length){
        string ans;
        if(direction == Direction::Vertical){
            for(unsigned int i = 0; i < length; i++){
                ans += board[row+i][column].letter;
            }
        }else{
            for(unsigned int i = 0; i < length; i++){
                ans += board[row][column+i].letter;
            }
        }
        return ans;
    }

    void Board::show(){
        //string spaces;
        for (unsigned int i = minRows; i <= maxRows; i++) {
            cout << i << ": ";
            for (unsigned int j = minColumns; j <= maxColumns; j++) {
                cout << board[i][j].letter;
            }
            cout << endl;
        }
        cout << endl;
    }

}