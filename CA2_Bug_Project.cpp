#include "Board.h";
using namespace std;

void printMenu()
{
    cout << endl
         << "1. Initialize Bug Board" << endl;
    cout << "2. Display All Bugs" << endl;
    cout << "3. Find a Bug by ID" << endl;
    cout << "4. Tap the Bug Board" << endl;
    cout << "5. Tap the Bug Board x Times" << endl;
    cout << "6. Display Life History of all Bugs" << endl;
    cout << "7. Display All Cells" << endl;
    cout << "8. Exit" << endl;
    cout << "Choose An Option: ";
}

int main()
{
    cout << "\x1B[32mWelcome to the Bug Game\033[0m\t\t" << endl;
    enum menuOptions
    {
        INITIALIZE_BOARD = 1,
        DISPLAY_ALL_BUGS,
        FIND_BUG_BY_ID,
        TAP_BOARD,
        TAP_BOARD_X_TIMES,
        DISPLAY_HISTORY_ALL_BUGS,
        DISPLAY_ALL_BOARD_CELLS,
        EXIT,
    };
    Board game;
    int userInput = 0;

    while (userInput != EXIT)
    {
        printMenu();
        cin >> userInput;
        switch (userInput)
        {
        case INITIALIZE_BOARD:
            game.initialiseBugBoard();
            break;
        case DISPLAY_ALL_BUGS:
            game.displayAllBugs();
            break;
        case FIND_BUG_BY_ID:
            game.findBugByID();
            break;
        case TAP_BOARD:
            game.tapBoard();
            break;
        case TAP_BOARD_X_TIMES:
            game.tapBoardX();
            break;
        case DISPLAY_HISTORY_ALL_BUGS:
            game.displayHistoryAllBugs();
            break;
        case DISPLAY_ALL_BOARD_CELLS:
            game.displayAllCells();
            break;
        case EXIT:
            game.exit();
            break;
        default:
            cout << "\x1B[31mNot a valid option!\033[0m\t\t" << endl; // makes text red
            break;
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    /*

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
    */
    return 0;
}
