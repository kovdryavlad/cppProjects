#include <iostream>
#include <stdlib.h>
#include <algorithm>

extern int LCS_recursive(char* a, char* b, int m, int n);
extern int LCS_dynamic_programming(char* a, char* b, int m, int n);

int main() 
{
	char X[] = "AGGTAB";
	char Y[] = "GXTXAYB";

	int m = strlen(X);
	int n = strlen(Y);

	int res = LCS_dynamic_programming(X, Y, m, n);
	std::cout << res << std::endl;

	return EXIT_SUCCESS;
}

//longest common subsequence
int LCS_recursive(char* a, char* b, int m, int n) 
{
	if (m == 0 || n == 0)
		return 0;
	else if (a[m - 1] == b[n - 1])
		return 1 + LCS_recursive(a, b, m - 1, n - 1);
	else
		return std::max(LCS_recursive(a, b, m - 1, n), LCS_recursive(a, b, m, n - 1));
}

int LCS_dynamic_programming(char* a, char* b, int m, int n)
{	
	int** table = new int*[m + 1];
	for (size_t i = 0; i <= m; i++)
		table[i] = new int[n+1];
	

	for (size_t i = 0; i <= m; i++)
	{
		for (size_t j = 0; j <= n; j++)
		{
			if (i == 0 || j == 0)
				table[i][j] = 0;

			else if (a[i-1] == b[j-1])
				table[i][j] = 1 + table[i-1][j-1];

			else
				table[i][j] = std::max(table[i - 1][j], table[i][j - 1]);
		}
	}

	int res = table[m][n];

	for (size_t i = 0; i <= m; i++)
		delete table[i];

	delete table;

	return res;
}