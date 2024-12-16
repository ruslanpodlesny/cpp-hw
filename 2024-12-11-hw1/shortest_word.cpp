#include <iostream>
#include <string>


// test string
// 7
// alpha beta gamma delta epsilon zeta eta


int main() {
    
    std::string str;
    std::string max_word;
    std::string min_word;

    int num;
    int max_len;
    int min_len;

    std::cin >> num;                            // number of words

    for (int i = 0; i < num; ++i) {
        
        std::cin >> str;
        
        if (i == 0) {
            max_len = min_len = str.length();
        }
        
        if (str.length() > max_len) {
            max_len = str.length();
            max_word = str;
        }
        else if (str.length() < min_len) {
            min_len = str.length();
            min_word = str;
        }

    }
   
    std::cout << "Max word: " << max_word << " Length: " << max_len << std::endl;
    std::cout << "Min word: " << min_word << " Length: " << min_len << std::endl;
    
}