#include <iostream>
#include<vector>
#include<string>
#include<iostream>
#include<fstream>

class courseSchedule {
public:
    std::string courseID, courseName, preRequisite1, preRequisite2;
    int input(std::string line);

private:
    //vector int 
};

int courseSchedule::input(std::string line) {

    std::string current;
    std::vector<std::string> tokens;
    for (int i = 0; i < line.size(); i++) {
        current.push_back(line[i]);
        if (line[i] == ',') {
            tokens.push_back(current);
            current.clear();
        }
    }
    courseID = tokens[0];
    courseName = tokens[1];
    if (tokens.size() > 2) {
        preRequisite1 = tokens[2];
    }
    if (tokens.size() > 3) {
        preRequisite2 = tokens[3];
    }
    return 0;
}