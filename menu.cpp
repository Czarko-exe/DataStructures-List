#include <iostream>
#include <string>
#include <vector>
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
			std::cout << "3. 4000" << std::endl;
			std::cout << "4. 8000" << std::endl;
			std::cout << "5. 16000" << std::endl;
			std::cout << "6. 32000" << std::endl;
			std::cout << "7. 64000" << std::endl;
			std::cout << "8. 128000" << std::endl;
			std::cout << "9. All" << std::endl;
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
					amount = 4000;
					break;
				case 4:
					amount = 8000;
					break;
				case 5:
					amount = 16000;
					break;
				case 6:
					amount = 32000;
					break;
				case 7:
					amount = 64000;
					break;
				case 8:
					amount = 128000;
					break;
				case 9:
					amount = -1;
					break;
				case 0:
					amount_menu = false;
					break;
				default:
					std::cerr << "Incorrect choice" << std::endl;
					break;
			}

			if (0 < choice && choice < 10) {
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
			std::cout << "8. All functions" << std::endl;
			std::cout << "0. Back" << std::endl;
			std::cout << std::endl;
			std::cin >> choice;
			switch (choice) {
				case 1:
					function = "pushFront";
					break;
				case 2:
					function = "pushBack";
					break;
				case 3:
					function = "pushAt";
					break;
				case 4:
					function = "popFront";
					break;
				case 5:
					function = "popBack";
					break;
				case 6:
					function = "popAt";
					break;
				case 7:
					function = "find";
					break;
				case 8:
					function = "All";
					break;
				case 0:
					function_menu = false;
					break;
				default:
					std::cerr << "Incorrect choice" << std::endl;
					break;
			}

			if (0 < choice && choice < 9) {
				function_menu = false;
			}
		}
		std::vector <std::string> structures = { 
			"Dynamic_Array", 
			"Singly_Linked_List", 
			"Doubly_Linked_List" 
		};

		std::vector <int> amounts = { 
			1000, 
			2000, 
			3000, 
			4000, 
			5000, 
			6000, 
			7000, 
			8000 
		};

		std::vector <std::string> functions = { 
			"pushFront", 
			"pushBack", 
			"pushAt", 
			"popFront", 
			"popBack", 
			"popAt", 
			"find" 
		};

		if (structure != "" && function != "" && amount != 0) {
			running = false;
			if (structure == "All") {
				if (amount == -1) {
					if (function == "All") {
						for (const auto& s : structures) {
							for (const auto& a : amounts) {
								for (const auto& f : functions) {
									test_structure(s, a, f);
								}
							}
						}
					}
					else {
						for (const auto& s : structures) {
							for (const auto& a : amounts) {
								test_structure(s, a, function);
							}
						}
					}
				}
				else if (function == "All") {
					for (const auto& s : structures) {
						for (const auto& f : functions) {
							test_structure(s, amount, f);
						}
					}
				}
				else {
					for (const auto& s : structures) {
						test_structure(s, amount, function);
					}
				}
			}
			else if (amount == -1) {
				if (function == "All") {
					for (const auto& a : amounts) {
						for (const auto& f : functions) {
							test_structure(structure, a, f);
						}
					}
				}
				else {
					for (const auto& a : amounts) {
						test_structure(structure, a, function);
					}
				}
			}
			else if (function == "All") {
				for (const auto& f : functions) {
					test_structure(structure, amount, f);
				}
			}
			else {
				test_structure(structure, amount, function);
			}
		}

	}

	

	return 0;
}