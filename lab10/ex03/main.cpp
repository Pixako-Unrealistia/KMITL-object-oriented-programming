





#include <iostream>
#include <vector>
#include <string>
#include <sstream>


/*Grammar rules because I have absolutely no clue how to make them

ragged_array  ::= '[' row { ';' row } ']' 
row           ::= element { ',' element }
element       ::= INT


*/


std::vector<std::vector<int>> parse_ragged_array(const std::string& input) {
    std::vector<std::vector<int>> result;
    std::stringstream ss(input);
    char c;
    ss >> c; 
    while (ss.peek() != ']') {
        std::vector<int> row;
        while (ss.peek() != ';' && ss.peek() != ']') {
            int value;
            ss >> value;
            row.push_back(value);
            if (ss.peek() == ',') {
                ss.ignore();
            }
        }
        result.push_back(row);
        if (ss.peek() == ';') {
            ss.ignore();
        }
    }
    return result;
}

std::string ragged_array_to_string(const std::vector<std::vector<int>>& array) {
    std::string result = "Array(";
    for (const std::vector<int>& row : array) {
        result += "[";
        for (int value : row) {
            result += std::to_string(value) + ",";
        }
        if (!row.empty()) {
            result.pop_back();
        }
        result += "],";
    }
    if (!array.empty()) {
        result.pop_back(); 
    }
    result += ")";
    return result;
}

int main() {
    std::string input = "[1, 2, 3; 4, 5; 6, 7, 8, 9]";
    std::vector<std::vector<int>> array = parse_ragged_array(input);
    std::string output = ragged_array_to_string(array);
    std::cout << output << std::endl; // should output: Array([1,2,3],[4,5],[6,7,8,9])
    return 0;
}
