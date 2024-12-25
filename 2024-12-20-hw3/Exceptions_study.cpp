#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>

int main() {

    std::string word;
    std::vector<std::string> vect;

    std::ifstream file("text.txt");

    try {
        if (!file.is_open()) {
            throw "Error!\nThe file could not be found!";
        }
    }
    catch (const char* error_message) {
        std::cout << error_message << std::endl;
        return 1;
    }

    try {
        while (file >> word) {
            if (std::all_of(word.begin(), word.end(), [](char ch) { return std::isalpha(ch);})) {
                vect.push_back(word);
            }
            else {
                throw "Digits have been detected!";
            }
            
        }
    }
    catch(const char* error_message){
        std::cout << error_message << std::endl;
        return 1;
    }

    file.close();

    std::string max_word = "";
    int max_word_count = 0;
    int counter;

    for (int i = 0; i < vect.size(); ++i) {
        counter = 0;
        for (int j = 0; j < vect.size(); ++j) {
            if (vect[i] == vect[j])
                ++counter;
        }
        if (max_word_count < counter) {
            max_word = vect[i];
            max_word_count = counter;
        }

    }

    std::cout << "The word \"" << max_word << "\" was found " << max_word_count << " times." << std::endl;

    return 0;
}