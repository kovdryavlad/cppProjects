#define _CRTDBG_MAP_ALLOC	//for memory leacks detecting
#include <stdlib.h>
#include <crtdbg.h>
#include "Dbg_new_macros.h"

#include <iostream>
#include <string>
#include <array>
#include "CustomLst.h"
#include "main.h"


using std::string;
using std::getline;

CustomLst* get_list_from_console_input() 
{
	std::cout << "Please, input values(leave empty string for sorting)" << std::endl;

	CustomLst* result_list = new CustomLst();
	string str;
	bool flag = false;

	while (!flag)
	{
		getline(std::cin, str);
		flag = str.empty();

		if (!flag)
		{
			int n = std::atoi(str.c_str());
			result_list->add(n);
		}
	}

	str.~basic_string();

	return result_list;
}

void output_array(int* arr, int lenght)
{
	std::cout << std::endl << "Sorted input data: ";

	for (size_t i = 0; i < lenght; i++)
		std::cout << arr[i] << " ";
	
	std::cout << std::endl;
}

int main()
{
	//memory leacks
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	_CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_DEBUG);

	CustomLst* lst = get_list_from_console_input();
	int lenght = lst->m_size;

	//converting to array and sotring
	int* arr = lst->ToArray();
	std::sort(arr, arr + lenght);

	output_array(arr, lenght);

	//deleting block
	delete arr;
	delete lst;

	_CrtDumpMemoryLeaks();	//memory leacks outputing

	system("pause");
	return EXIT_SUCCESS;
}


