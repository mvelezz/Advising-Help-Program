#include <iostream>
#include "Header.h"

int main() {

	courseSchedule course;
	std::vector<courseSchedule> courses;

	int userInput = 0;

	std::cout << "MENU" << std::endl;
	std::cout << "CHOICE 1: LOAD DATA" << std::endl;
	std::cout << "CHOICE 2: PRINT COURSE LIST" << std::endl;
	std::cout << "CHOICE 3: PRINT COURSE ALONG WITH PREREQUISITES FOR THAT COURSE" << std::endl;
	std::cout << "CHOICE 4: EXIT" << std::endl;

	std::cin >> userInput;

	while (userInput == 1 || userInput == 2 || userInput == 3 || userInput == 4) {
		switch (userInput) {
		case 1:
		{std::cout << "Made it to 1" << std::endl;
		std::string line;
		std::ifstream fileObj;
		std::cout << "Opening File. " << std::endl;
		fileObj.open("Courses.txt");
		if (!fileObj.is_open()) {
			std::cout << "Could not open file";
			return 1;
		}
		else {
			std::cout << "Reading from file" << std::endl;
			while (fileObj.good()) {
				getline(fileObj, line);
				courseSchedule course1;
				course1.input(line);
				courses.push_back(course1);
			}
		}
		break;
		}
		case 2:
			std::cout << "made it to 2" << std::endl;
			break;
		case 3:
			std::cout << "made to 3" << std::endl;
			break;
		case 4:
			std::cout << "made it to 4" << std::endl;
			break;

		}
		std::cout << "MENU" << std::endl;
		std::cout << "CHOICE 1: LOAD DATA" << std::endl;
		std::cout << "CHOICE 2: PRINT COURSE LIST" << std::endl;
		std::cout << "CHOICE 3: PRINT COURSE ALONG WITH PREREQUISITES FOR THAT COURSE" << std::endl;
		std::cout << "CHOICE 4: EXIT" << std::endl;
		std::cin >> userInput;

		while (userInput != 1 && userInput != 2 && userInput != 3 && userInput != 4) {
			std::cout << "INVALID INPUT" << std::endl;
			std::cout << "MENU" << std::endl;
			std::cout << "CHOICE 1: LOAD DATA" << std::endl;
			std::cout << "CHOICE 2: PRINT COURSE LIST" << std::endl;
			std::cout << "CHOICE 3: PRINT COURSE ALONG WITH PREREQUISITES FOR THAT COURSE" << std::endl;
			std::cout << "CHOICE 4: EXIT" << std::endl;
			std::cin >> userInput;
		}

	}
	while (userInput != 1 && userInput != 2 && userInput != 3 && userInput != 4) {
		std::cout << "INVALID INPUT" << std::endl;
		std::cout << "MENU" << std::endl;
		std::cout << "CHOICE 1: LOAD DATA" << std::endl;
		std::cout << "CHOICE 2: PRINT COURSE LIST" << std::endl;
		std::cout << "CHOICE 3: PRINT COURSE ALONG WITH PREREQUISITES FOR THAT COURSE" << std::endl;
		std::cout << "CHOICE 4: EXIT" << std::endl;
		std::cin >> userInput;
	}

}