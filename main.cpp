#include <iostream>
#include<vector>
#include<string>
#include<iostream>
#include<fstream>
#include<sstream>
using namespace std;

//course class
class courseSchedule {
public:
	std::string courseID, courseName, preRequisite1, preRequisite2;
	void input(std::string line);
 
};

//function to allow all types of user input
string makeUpper(string str) {
	string result = "";
	for (int i = 0; i < str.size(); ++i) {
		result += toupper(str[i]);
	}
	return result;
}


//reading the file line by line, seperated by commas
void courseSchedule::input(std::string line) {
	stringstream ss(line);

	getline(ss, courseID, ',');
	if (!getline(ss, courseName, ',')) {
		std::cout << "Error: missing name of the course id " << courseID << std::endl;
		exit(0);
	}
	if (!getline(ss, preRequisite1, ',')) {
		preRequisite1 = "";

	}
	if (!getline(ss, preRequisite2, ',')) {
		preRequisite2 = "";
	}
}


//selection sort to sort the courses alphabetically
void selectionSort(vector<courseSchedule>& course) {
	int smallest;
	for (int i = 0; i < course.size(); ++i) {
		smallest = i;
		for (int j = i + 1; j < course.size(); j++) {
			if (course[j].courseName.compare(course[smallest].courseName) < 0) {
				smallest = j;
			}
		}
		if (smallest != i)
			swap(course[i], course[smallest]);
	}
}


int main() {

	//create course objects
	courseSchedule course;
	std::vector<courseSchedule> courses;

	int userInput = 0;
	string courseSelection;

	std::cout << "MENU" << std::endl;
	std::cout << "CHOICE 1: LOAD DATA" << std::endl;
	std::cout << "CHOICE 2: PRINT COURSE LIST" << std::endl;
	std::cout << "CHOICE 3: PRINT COURSE ALONG WITH PREREQUISITES FOR THAT COURSE" << std::endl;
	std::cout << "CHOICE 4: EXIT" << std::endl;

	std::cin >> userInput;


	//take userinput when userinput is not 4
	while (userInput != 4) {
		if (userInput != 1 && userInput != 2 && userInput != 3 && userInput != 4) {
			cout << "Invalid input" << endl;
			cin.clear();
			cin.ignore(1000000, '\n');
		}
		switch (userInput) {
		//load data into the data structure froma file
		case 1:
		{ 
		std::string line;
		std::ifstream fileObj;
		string userFile;
		std::cout << "Please enter the file you would like to open." << std::endl;
		std::cin >> userFile;
		fileObj.open(userFile);
		if (!fileObj.is_open()) {
			std::cout << "Could not open file" << endl;
			break;
			return 1;
			
		}
		else {
			//add objects to a vector
			std::cout << "Reading from file" << std::endl;
			while (fileObj.good()) {
				getline(fileObj, line);
				courseSchedule course1;
				course1.input(line);
				courses.push_back(course1);


			}
			fileObj.close();
		}
		cout << "File has been loaded" << endl;

		break;
		}
		case 2:
			//sort and print out all courses in the data structure
			selectionSort(courses);
			for (const auto& course : courses) {
				cout << course.courseID << endl;
				cout << course.courseName << endl;
				cout << endl;
			}
			break;
		case 3:
			//provide info based on certain courses
			cout << "What course would you like to know about?" << endl;
			cin >> courseSelection;

			//loop through data strucutre based on course selected and print prerequisites
			for (int i = 0; i < courses.size(); i++) {
				if (makeUpper(courseSelection) == courses[i].courseID) {
					cout << courses[i].courseName << endl;
					cout << "Prerequisites: " << courses[i].preRequisite1 << ", " << courses[i].preRequisite2 << endl;
				}
			}
			break;
		case 4:
			break;

		}
		std::cout << "MENU" << std::endl;
		std::cout << "CHOICE 1: LOAD DATA" << std::endl;
		std::cout << "CHOICE 2: PRINT COURSE LIST" << std::endl;
		std::cout << "CHOICE 3: PRINT COURSE ALONG WITH PREREQUISITES FOR THAT COURSE" << std::endl;
		std::cout << "CHOICE 4: EXIT" << std::endl;
		std::cin >> userInput;

	}


}


