#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>


int main() {
    std::ifstream input_file;
    input_file.open("input");
    int left;
    int right;
    std::string line;
    std::vector<int> left_values;
    std::vector<int> right_values;
    if (input_file.is_open()) {
        while (std::getline (input_file, line)) {
            std::stringstream ss;
            ss << line;
            ss >> left >> right;
            left_values.push_back(left);
            right_values.push_back(right);
        }
    }
    else {
        std::cout << "Problem opening file.\n";
    }
    std::sort(left_values.begin(), left_values.end());
    std::sort(right_values.begin(), right_values.end());
   



    int sum_diffs = 0;
    for (auto i = 0; i < right_values.size(); ++i) {
        int diff = std::abs(left_values[i] - right_values[i]);
        //std::cout << "Current diff is " << left_values[i] << " minus " 
        //<< right_values[i] << " for a result of " << diff << '\n';
        sum_diffs = sum_diffs + diff;
        

    }
    std::cout << "Total distance: " << sum_diffs << '\n';
}