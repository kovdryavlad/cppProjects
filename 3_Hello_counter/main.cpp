//this is solving problem "hello" from codeground
//first param - numver of strings for reading 
//other params - strings
// we need to calc how many "hello" we can construct from inputed string

//Example
//Input
/*
	3
	hellohellohello
	hellhellhelloo
	hihihibyebyebye
*/

//Output
/*
	Case #1
	3
	Case #2
	2
	Case #3
	0
*/


/*
You should use the statndard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful.
*/

#include <iostream>

using namespace std;

extern int hello_calc(char* str);
extern int min_cust(int* arr, size_t arr_size);
extern int strlen_cust(char* str);

int Answer;

int main(int argc, char** argv)
{
	int T, test_case;
	/*
	   The freopen function below opens input.txt file in read only mode, and afterward,
	   the program will read from input.txt file instead of standard(keyboard) input.
	   To test your program, you may save input data in input.txt file,
	   and use freopen function to read from the file when using cin function.
	   You may remove the comment symbols(//) in the below statement and use it.
	   Use #include<cstdio> or #include <stdio.h> to use the function in your program.
	   But before submission, you must remove the freopen function or rewrite comment symbols(//).
	 */

	 // freopen("input.txt", "r", stdin);

	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{
		char str[10000];
		cin >> str;



		Answer = hello_calc(str);
		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
		   Implement your algorithm here.
		   The answer to the case will be stored in variable Answer.
		 */
		 /////////////////////////////////////////////////////////////////////////////////////////////

		 // Print the answer to standard output(screen).
		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}

int hello_calc(char* str) 
{
	int h_counter = 0;
	int e_counter = 0;
	int l_counter = 0;
	int o_counter = 0;
	
	size_t length = strlen_cust(str);

	for (size_t i = 0; i < length; i++)
	{
		if (str[i] == 'h')
		{
			h_counter++;
			continue;
		}
		else if (str[i] == 'e')
		{
			e_counter++;
			continue;
		}
		else if (str[i] == 'l')
		{
			l_counter++;
			continue;
		}
		else if (str[i] == 'o')
		{
			o_counter++;
			continue;
		}
	}

	l_counter /= 2;

	int arr[4] = {h_counter, e_counter, l_counter, o_counter};
	return min_cust(arr, 4);
}

int min_cust(int* arr, size_t arr_size) 
{
	int min = arr[0];

	for (size_t i = 1; i < arr_size; i++)
	{
		if (arr[i] < min)
			min = arr[i];
	}

	return min;
}

int strlen_cust(char* str) 
{
	int len = 0;
	
	for (size_t i = 0; str[i]!=0; i++)
	{
		len++;
	}

	return len;
}