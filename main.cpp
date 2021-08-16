#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

void boardGraphic (vector<string>& displayBoard, int& printWidth){

    for (int i = 0; i <= printWidth - 1; i++){
        cout << "|";
        for (int j = 0; j <= printWidth - 1; j++){
            cout << setw(3) << displayBoard[(i * printWidth) + j] << " | ";
        }
        cout << endl;
        for (int k = 0; k <= printWidth - 1; k++){
            cout << "------";
        }
        cout<< endl;
    }
}

//This function tests the board matrix for a winner
bool boardStatus (vector<string>& showBoard, int& boardWidth){

    bool winnerFound = false;
    bool checkComplete = false;

    while (winnerFound == false && checkComplete == false){
            //Checking for a winner on the horizontals
            for (int i = 0; i <= boardWidth - 1; i++){
                if (winnerFound == true){
                    break;
                }
                for (int j = 0; j <= boardWidth - 2; j++){
                    if ((showBoard[(i * boardWidth) + j] != showBoard[(i * boardWidth) + (j + 1)])){
                        break;
                    }
                    if ((showBoard[(i * boardWidth) + j] == showBoard[(i * boardWidth) + (j + 1)]) && (j == boardWidth - 2)){
                        winnerFound = true;
                        break;
                    }
                    else {}
                }
            }
            if (winnerFound == true){
                break;
            }
            //Checking for a winner on the verticals
            for (int k = 0; k <= boardWidth - 1; k++){
                for (int y = 1; y <= boardWidth - 1; y++){
                    if (winnerFound == true){
                        break;
                    }
                    if (showBoard[k] != showBoard[(y * boardWidth) + k]){
                        break;
                    }
                    if (showBoard[k] == showBoard[(y * boardWidth) + k] && (y == boardWidth - 1)){
                        winnerFound = true;
                        break;
                    }
                    else{}
                }
            }
            if (winnerFound == true){
                break;
            }
            //Checking for a winner on the diagonals, board index positions 0-4-8 & 6-4-2 in a 3x3 for reference
            int q = 0; //Settings comparison for vector index 0 to check downward diagonal
            for (int w = 1; w <= boardWidth - 1; w++){
                cout << "First Diagonal " << showBoard[q] << " " <<showBoard[(w * boardWidth) + w] << endl;
                if (winnerFound == true){
                    break;
                }
                if (showBoard[q] != showBoard[(w * boardWidth) + w]){
                    break;
                }
                if (showBoard[q] == showBoard[(w * boardWidth) + w] && (w == boardWidth - 1)){
                    winnerFound = true;
                }
                else{}
            }
            if (winnerFound == true){
                break;
            }
            q = boardWidth - 1; //Settings comparison for vector index boardWidth to check upward diagonal
            for (int r = 1; r <= boardWidth - 1; r++){
                cout << "Second Diagonal " << showBoard[q] << " " <<showBoard[q + (r * boardWidth) - 1] << endl;
                if (winnerFound == true){
                    break;
                }
                if (showBoard[q] != showBoard[q + (r * boardWidth) - 1]){
                    break;
                }
                if (showBoard[q] == showBoard[q + (r * boardWidth) - 1] && (r == boardWidth - 1)){
                    winnerFound == true;
                }
                else{}
            }
            if (winnerFound == true){
                break;
            }
            checkComplete = true; //Exit if all possible winning positions have been checked
    }
    return winnerFound;
}


int main()
{
    string start;
    //Variable to indicate status of game initialized to false at beginning
    bool winner = false;
    //These are the letter indicators assigned to each player and the standard size board (later to add selected nxn sized board determined by input
    string player1, player2, board;
    int selection, currentPlayer, boardSize, boardNSize;

    //Populates board with options
//    for (int i = 0; i <= (sizeof(board)/sizeof(board[0]))-1; i++){
//        board[i] = to_string(i + 1);
//    }

    cout << "Welcome to TicTacToe" << endl;
    cout << "Would you like to play? (Type Yes or No)"<< endl;
    cin >> start;

    if (start == "Yes"){
        cout << "Welcome" << endl;
        cout << "This is a two player game" << endl;
        cout << "Player 1 chose X or O " << endl;
        cin >> player1;
        if (player1.compare("X") == 0){
            player2 = "O";
        }
        else{
            player2 = "X";
        }

        cout << "Please chose board dimension (N) for an NxN board" << endl;
        cin >> boardNSize;
        boardSize = boardNSize * boardNSize;
        vector<string> board;

        for (int i = 0; i < boardSize; i++){
            board.push_back(to_string(i+1));
        }

        cout << "Player 1 will play as " << player1 << endl;
        cout << "Player 2 will play as " << player2 << endl;
        cout << "Lets begin" << endl;
        // boardStatus (boardPtr) call function to display current board passing pointers of player
        boardGraphic (board, boardNSize);
        int numTurns = 0;
        currentPlayer = 1;
        //While loop where the game is played that exits when a winner is declared.
        while (winner != true){

            cout << "Player " << currentPlayer << ", Please select a number position you would like to place a marker" << endl;
            cin >> selection;
            if (currentPlayer == 1){
                board[selection-1] = player1;
                //board
            } else {
                board[selection-1] = player2;
            }
            boardGraphic (board, boardNSize);
            winner = boardStatus(board, boardNSize);
            if (winner == true){
                cout << "Congratulations Player " << currentPlayer << " has won the game" << endl;
                break;
            }
            else{
                numTurns++;
            }
            if (numTurns == board.size()){
                cout << "The game is a tie" << endl;
                break;
            }
            if (currentPlayer == 1){
                currentPlayer = 2;
            }
            else {
                currentPlayer = 1;
            }
        }
        cout << "Play again soon" << endl;
    }
    else {
        cout << "Goodbye" << endl;
    }
    return 0;
}