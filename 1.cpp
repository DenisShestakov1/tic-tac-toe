#include <iostream>
using namespace std;


char board[3][3]; 

void draw_board() {
  
    cout << "  1 2 3" << endl;
    cout << " -------" << endl;
    for (int i = 0; i < 3; i++) {
        cout << i + 1 << "|";
        for (int j = 0; j < 3; j++) {
            cout << board[i][j] << "|";
        }
        cout << endl;
        cout << " -------" << endl;
    }
}

bool is_valid_move(int x, int y) {
   
    if (x < 0 || x >= 3 ||  y < 0 || y >= 3) {
        return false; 
    }
    if (board[x][y] != ' ') {
        return false; 
    }
    return true;
}

char check_winner() {

    for (int i = 0; i < 3; i++) {
        // проверяем строки
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') {
            return board[i][0]; // победитель
        }
        // проверяем столбцы
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ') {
            return board[0][i]; 
        }
    }
    // проверяем диагонали
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') {
        return board[0][0]; 
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ') {
        return board[0][2]; 
    }
   
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                return ' '; 
            }
        }
    }
    return 'D'; 
}

int main() {
    setlocale(LC_ALL, "Russian");

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
  
    char player = 'X';
    while (true) {
        draw_board();
        cout << "Ход игрока " << player << endl;

        int x, y;
        cout << "Введите номер строки: ";
        cin >> x;
        cout << "Введите номер столбца: ";
        cin >> y;
        --x;
        --y;

      
        if (!is_valid_move(x, y)) {
            cout << "Недопустимый ход! Попробуйте еще раз." << endl;
            continue;
        }

     
        board[x][y] = player;

      
        char winner = check_winner();
        if (winner != ' ') {
            draw_board();
            if (winner == 'D') {
                cout << "Ничья!" << endl;
            }
            else {
                cout << "Победил игрок " << winner << "!" << endl;
            }
            break;
        }

        // Сменить игрока
        if (player == 'X') {
            player = 'O';
        }
        else {
            player = 'X';
        }
    }
}
