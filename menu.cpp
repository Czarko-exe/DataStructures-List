#include <iostream>
#include <string>
#include "menu.hpp"
#include "Tester.hpp"

int menu() {
	bool running = true;
	bool amount_menu = false;
	bool function_menu = false;
	int choice;
	std::string structure;
	int amount;
	std::string function;
	while (running) {
		std::cout << "=====MENU=====" << std::endl;
		std::cout << "1. Test everything" << std::endl;
		std::cout << "2. Dynamic Array" << std::endl;
		std::cout << "3. Singly Linked List" << std::endl;
		std::cout << "4. Doubly Linked List" << std::endl;
		std::cout << "0. Exit" << std::endl;
		std::cout << std::endl;
		std::cin >> choice;
		switch (choice) {
			case 1:
				structure = "All";
				break;
			case 2:
				structure = "Dynamic_Array";
				break;
			case 3:
				structure = "Singly_Linked_List";
				break;
			case 4:
				structure = "Doubly_Linked_List";
				break;
			case 0:
				running = false;
				break;
			default:
				std::cerr << "Incorrect choice" << std::endl;
				break;
		}
		if (0 < choice && choice < 5) {
			amount_menu = true;
		}

		while (amount_menu) {
			std::cout << "Select data amount:" << std::endl;
			std::cout << "1. 1000" << std::endl;
			std::cout << "2. 2000" << std::endl;
			std::cout << "3. 3000" << std::endl;
			std::cout << "4. 4000" << std::endl;
			std::cout << "5. 5000" << std::endl;
			std::cout << "6. 6000" << std::endl;
			std::cout << "7. 7000" << std::endl;
			std::cout << "8. 8000" << std::endl;
			std::cout << "0. Back" << std::endl;
			std::cout << std::endl;
			std::cin >> choice;
			switch (choice) {
				case 1:
					amount = 1000;
					break;
				case 2:
					amount = 2000;
					break;
				case 3:
					amount = 3000;
					break;
				case 4:
					amount = 4000;
					break;
				case 5:
					amount = 5000;
					break;
				case 6:
					amount = 6000;
					break;
				case 7:
					amount = 7000;
					break;
				case 8:
					amount = 8000;
					break;
				case 0:
					amount_menu = false;
					break;
				default:
					std::cerr << "Incorrect choice" << std::endl;
					break;
			}

			if (0 < choice && choice < 9) {
				amount_menu = false;
				function_menu = true;
			}
		}
		

		while (function_menu) {
			std::cout << "Select function:" << std::endl;
			std::cout << "1. Adding in front" << std::endl;
			std::cout << "2. Adding at the end" << std::endl;
			std::cout << "3. Adding randomly" << std::endl;
			std::cout << "4. Remove in front" << std::endl;
			std::cout << "5. Remove at the end" << std::endl;
			std::cout << "6. Remove randomly" << std::endl;
			std::cout << "7. Search" << std::endl;
			std::cout << "0. Back" << std::endl;
			std::cout << std::endl;
			std::cin >> choice;
			switch (choice) {
				case 1:
					function = "push_front";
					break;
				case 2:
					function = "push_back";
					break;
				case 3:
					function = "push_random";
					break;
				case 4:
					function = "pop_front";
					break;
				case 5:
					function = "pop_back";
					break;
				case 6:
					function = "pop_random";
					break;
				case 7:
					function = "find";
					break;
				case 0:
					function_menu = false;
					break;
				default:
					std::cerr << "Incorrect choice" << std::endl;
					break;
			}

			if (0 < choice && choice < 8) {
				function_menu = false;
			}
		}
		if (structure != "" && function != "" && amount != 0) {
			running = false;
			if (structure == "All") {
				test_structure("Dynamic_Array", amount, function);
				test_structure("Singly_Linked_List", amount, function);
				test_structure("Doubly_Linked_List", amount, function);
			}
			else {
				test_structure(structure, amount, function);
			}
		}

	}

	

	return 0;
}