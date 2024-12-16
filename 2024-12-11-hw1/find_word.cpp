#include <iostream>
#include <string>
#include <vector>
#include <fstream>


int main() {

    std::string word;
    std::vector<std::string> vect; 

    std::ifstream file("text.txt");

    if (!file.is_open()) {
        std::cerr << "The file could not be opened" << std::endl;
        return 1;
    }
        
    while (file >> word) {
        vect.push_back(word);
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