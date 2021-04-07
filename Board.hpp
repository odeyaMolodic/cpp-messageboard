#include "Direction.hpp"
#include <limits.h>
#include <string>
#include <map>
using namespace std;

struct blankChar{
    char letter = '_';
};

namespace ariel{

    class Board {

        map<unsigned int, map<unsigned int, blankChar>> board;
        unsigned int minRows;
        unsigned int maxRows;
        unsigned int minColumns;
        unsigned int maxColumns;

        void resize(const unsigned int &row, const unsigned int &endRow, const unsigned int &column, const unsigned int &endCol, const unsigned int &length);

    public:

        Board(): maxRows(0), maxColumns(0), minRows(UINT_MAX), minColumns(UINT_MAX) { }

        ~Board() { }

        /*
        Gets a position (row and column), direction (horizontal or vertical), and a string that represents an ad, 
        and pastes the string on the board in the appropriate place.
        */
        void post(unsigned int row, unsigned int column, Direction direction, const string &message);

        /*
        Gets position (row and column), direction (horizontal or vertical), and number of characters, 
        reads what is written on the board at the given position and length, and returns a string. 
        The letter in each place on the board is the last letter pasted there.
        */
        string read(unsigned int row, unsigned int column, Direction direction, unsigned int length);

        /*
        Displays the current message-board for easy reading
        */
        void show();
    }; 

}