// rows_cols.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

bool is_mult_sq(int n) {
	if (n < 8) return false;
	int n_2 = 0;
	bool found_div = false;
	while (n % 2 == 0) {
		n /= 2;
		++n_2;
	}
	if (n_2 > 2) return true;
	if (n_2 > 0) found_div = true;
	for (int i = 3; i * i < n; i += 2) {
		if (n == 1) return false;
		int n_i = 0;
		while (n % i == 0) {
			n /= i;
			++n_i;
		}
		if (n_i > 1 && (n > 1 || found_div)) return true;
		if (n_i > 0) found_div = true;
	}
	return false;
}
constexpr int N = 4;
bool can_remove(int t[N][N]) {
	bool can[N][N];
	for (int y = 0; y < N; ++y)
		for (int x = 0; x < N; ++x)
			can[y][x] = is_mult_sq(t[y][x]); //Garek nie kaza³ modifyfikowaæ oryginalnej tablicy 

	int n_cols[N] = {};
	for (int x = 0; x < N; ++x)
		for (int y = 0; y < N; ++y)
			n_cols[x] += can[y][x] ? 0 : 1;

	for (int row = 0; row < N; ++row) {
		int n_bad = 0;
		for (int x = 0; x < N; ++x) {
			int n_col_bad = n_cols[x] - (can[row][x] ? 0 : 1);
			if (n_col_bad > 0) {
				++n_bad;
				if (n_bad > 2) break;
			}
		}
		if (n_bad <= 2) return true;
	}
	return false;
}

int main()
{
	int t[N][N] = {
		{1, 1, 8, 8},
		{8, 1, 8, 1},
		{1, 8, 8, 8},
		{8, 1, 8, 8}
	};
	int t2[N][N] = {
		{1, 1, 8, 1},
		{8, 1, 8, 1},
		{1, 8, 8, 8},
		{8, 1, 8, 8}
	};
	std::cout << can_remove(t) << '\n';
	std::cout << can_remove(t2) << '\n';
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
