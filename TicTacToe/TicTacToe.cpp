#include <iostream>
#include <conio.h> 

using namespace std;

class TicTacToe {
private:
	char board[3][3];
	char mark;
	int turn;
	int won;
	int input;
public:
	TicTacToe() :board{ '1','2','3','4','5','6','7','8','9' } {
		turn = 1;
		mark = 'O';
		won = 0;
		input = 0;
	}
	int GetResult() {
		return won;
	}
	void Play() {
		for (int i = 0; i < 9; i++) {
			system("cls");
			PrintBoard();

			Input();

			int validInput = AddMark();
			if (!validInput) {
				i--;
				continue;
			}

			Result(i);
			if (won != 0)	break;

			turn = !turn;
		}
	}
	void Result(int i) {
		if (Check()) {
			system("cls");
			PrintBoard();
			if (turn) {
				cout << endl << "*** Player 1 - You Won ***";
				won = 1;
				return;
			}
			else {
				cout << endl << "*** Player 2 - You Won ***";
				won = 2;
				return;
			}
		}
		if (i == 8) {
			system("cls");
			PrintBoard();
			cout << endl << "*** Match Draw ***";
			won = 3;
			return;
		}
		won = 0;
	}
	void Input() {
		cout << "Enter a number (1-9): ";
		cin >> input;
		while (input < 1 || input > 9) {
			cout << "Invalid input. Please re-enter a number between 1 and 9: ";
			cin >> input;
		}
		mark = turn ? 'O' : 'X';
	}

	void PrintBoard() {
		cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << " " << endl;
		cout << "-----------" << endl;
		cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << " " << endl;
		cout << "-----------" << endl;
		cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << " " << endl;

		if (turn) cout << "O - Player 1: ";
		else cout << "X - Player 2: ";
	}
	int AddMark() {
		for (int i = 0, k = 1; i < 3; i++) {
			for (int j = 0; j < 3; j++, k++) {
				if (k == input) {
					if (board[i][j] != 'O' && board[i][j] != 'X') {
						board[i][j] = mark;
						return 1;  // Valid placement
					}
					else {
						cout << "Position already taken. Try another position.\n";
						return 0;  // Position taken
					}
				}
			}
		}
		return 0;  // In case input is out of bounds (redundancy)
	}

	int Check() {
		// Rows
		if (board[0][0] == mark && board[0][1] == mark && board[0][2] == mark) return 1;
		if (board[1][0] == mark && board[1][1] == mark && board[1][2] == mark) return 1;
		if (board[2][0] == mark && board[2][1] == mark && board[2][2] == mark) return 1;

		// Columns
		if (board[0][0] == mark && board[1][0] == mark && board[2][0] == mark) return 1;
		if (board[0][1] == mark && board[1][1] == mark && board[2][1] == mark) return 1;
		if (board[0][2] == mark && board[1][2] == mark && board[2][2] == mark) return 1;

		// Diagonals
		if (board[0][0] == mark && board[1][1] == mark && board[2][2] == mark) return 1;
		if (board[0][2] == mark && board[1][1] == mark && board[2][0] == mark) return 1;

		return 0;  // Return 0 if no win condition is met
	}

	void Reset() {
		board[0][0] = '1'; board[0][1] = '2'; board[0][2] = '3';
		board[1][0] = '4'; board[1][1] = '5'; board[1][2] = '6';
		board[2][0] = '7'; board[2][1] = '8'; board[2][2] = '9';
		turn = 1;
		mark = 'O';
		won = 0;
		input = 0;
	}
};

#include <conio.h> 

int main() {
	TicTacToe t;
	char replay;
	do {
		t.Play();
		t.Reset();

		cout << endl << endl << "Do you want to play again (Y/N): ";
		replay = _getche();  // Remplacez `getche` par `_getche`
	} while (replay == 'y' || replay == 'Y');

	_getch();  // Remplacez `getch` par `_getch`
	return 0;
}
