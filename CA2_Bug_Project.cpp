#include "Board.h";
using namespace std;

void printMenu()
{
    cout << "1. Initialize Bug Board" << endl;
    cout << "2. Display All Bugs" << endl;
    cout << "3. Find a Bug by ID" << endl;
    cout << "4. Tap the Bug Board" << endl;
    cout << "5. Display Life History of all Bugs" << endl;
    cout << "6. Display All Cells" << endl;
    cout << "7. Exit" << endl;
}

int main()
{
    Board game;
    game.initialiseBugBoard();
    game.displayAllBugs();
    for (int i = 0; i < 1; i++)
    {
        game.tapBoard();
    }
    cout << "Exit" << endl;
    game.displayAllBugs();
    game.displayAllCells();
    cout << "Finish" << endl;
    return 0;
}
