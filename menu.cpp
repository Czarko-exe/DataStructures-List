#include <iostream>
#include "menu.hpp"

int menu() {
	bool running = true;
	int structure;
	int amount;
	int function;
	loop:
	while (running) {
		std::cout << "=====MENU=====" << std::endl;
		std::cout << "1. Dynamic Array" << std::endl;
		std::cout << "2. Singly Linked List" << std::endl;
		std::cout << "3. Doubly Linked List" << std::endl;
		std::cout << "0. Exit" << std::endl;
		std::cout << std::endl;
		std::cin >> structure;
		switch (structure) {
			case 1:
				break;
			case 2:
				break;
			case 3:
				break;
			case 0:
				running = false;
				goto loop;
				break;
			default:
				std::cerr << "Incorrect choice" << std::endl;
				goto loop;
				break;
		}
		choice2:
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
		std::cin >> amount;
		switch (amount) {
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		case 7:
			break;
		case 8:
			break;
		case 0:
			goto loop;
			break;
		default:
			std::cerr << "Incorrect choice" << std::endl;
			goto choice2;
			break;
		}

	choice3:
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
	std::cin >> function;
	switch (function) {
	case 1:
		break;
	case 2:
		break;
	case 3:
		break;
	case 4:
		break;
	case 5:
		break;
	case 6:
		break;
	case 7:
		break;
	case 0:
		goto choice2;
		break;
	default:
		std::cerr << "Incorrect choice" << std::endl;
		goto choice3;
		break;
	}

	}
	return 0;
}