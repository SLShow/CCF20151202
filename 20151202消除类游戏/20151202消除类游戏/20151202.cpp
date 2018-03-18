#include<iostream>
#include<cstdlib>
#include<cstring>

using namespace std;

const int N = 30;
int board[N][N];

int main() {
	int n, m;
	memset(board, 0, sizeof(board));
	cin >> m >> n;
	for (int i = 0;i < m;i++)
		for (int j = 0;j < n;j++)
			cin >> board[i][j];

	for (int i = 0;i < m;i++) {
		for (int j = 0;j < n;j++) {
			if (abs(board[i][j]) == abs(board[i][j + 1]) && abs(board[i][j + 1]) == abs(board[i][j + 2])) {//行记录
				board[i][j] = (-1)*abs(board[i][j]);
				board[i][j+1] = (-1)*abs(board[i][j+1]);
				board[i][j+2] = (-1)*abs(board[i][j+2]);
			}

			if (abs(board[i][j]) == abs(board[i+1][j]) && abs(board[i+1][j]) == abs(board[i+2][j])) {//列记录
				board[i][j] = (-1)*abs(board[i][j]);
				board[i+1][j] = (-1)*abs(board[i+1][j]);
				board[i+2][j] = (-1)*abs(board[i+2][j]);
			}
		}
	}

	for (int i = 0;i < m;i++) {
		for (int j = 0;j < n;j++) {
			if (board[i][j] < 0)
				board[i][j] = 0;
			if (j != 0)
				cout << " ";
			cout << board[i][j];
		}
		cout << endl;
	}

	return 0;
}