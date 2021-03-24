#include "Direction.hpp"
#include <string>
using namespace std;

namespace ariel{

    class Board {

    public:

        Board() { }

        ~Board() { }

        //unsigned?
        void post(int row, int column, Direction direction, string message);

        string read(int row, int column, Direction direction, int length);

        void show();
    }; 

}