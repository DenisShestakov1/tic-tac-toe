#include <iostream>
#include <conio.h>

using namespace std;


 char board[3][3];

void draw_board() {

	cout << " 1 2 3" << "\n";
	cout << " —-----" << "\n";
	for (int i = 0; i < 3; i++) {
		cout << i + 1 << "|";
		for (int j = 0; j < 3; j++) {
			cout << board[i][j] << "|";
		}
		cout << "\n";
		cout << " —-----" << "\n";
	}
}



char check_winner() {

	for (int i = 0; i < 3; i++) {
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') {
			return board[i][0];
		}

		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ') {
			return board[0][i];
		}
	}
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
		draw_board();
		cout << "Ход игрока " << player << "\n";

		int x = 0, y = 0;
		char input;

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				cout << board[i][j] << " ";

			}
			cout << "\n";
		}

		while (true) {

			input = _getch();

			switch (input) {
			case 'w':
				if (y > 0) y--;
				break;
			case 'a':
				if (x > 0) x--;
				break;
			case 's':
				if (y < 2) y++;
				break;
			case 'd':
				if (x < 2) x++;
				break;
			case ' ':
				if (board[y][x] == ' ')
				{
					board[y][x] = player;

					if (player == 'X') {
						player = 'O';
					}
					else {
						player = 'X';
					}
				}
				break;
			}

			system("cls");

			cout << " 1 2 3" << "\n";
			cout << " —-----" << "\n";

			for (int i = 0; i < 3; i++) {
				cout << i + 1 << "|";
				for (int j = 0; j < 3; j++) {
					if (i == y && j == x and board[i][j] == ' ') {
						cout << "*" << "|";
					}
					else cout << board[i][j] << "|";
				}
				cout << "\n";
				cout << " —-----" << "\n";
			}

			char winner = check_winner();
			if (winner != ' ') {
				if (winner == 'D') {
					cout << "Ничья!" << "\n";
				}
				else {
					cout << "Победил игрок " << winner << "!" << "\n";
				}
				break;
			}
		}
	}
