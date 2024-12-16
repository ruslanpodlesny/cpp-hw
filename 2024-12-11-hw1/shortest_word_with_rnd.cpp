#include <iostream>
#include <string>
#include <ctime>
#include <vector>

int rnd_gen(int lower_bound, int upper_bound) {
    return rand() % (upper_bound - lower_bound + 1) + lower_bound;
}


int main() {
    
    srand(time(0));     // where should it be placed?
    
    int vect_size;
    std::cin >> vect_size;      

    std::vector<std::string> vect(vect_size); 
        
    for (int i = 0; i < vect.size(); ++i ) {
        
        int word_len = rnd_gen(3, 15);
        std::string gen_str(word_len,' '); // приводит ли это к нерациональному расходу памяти? 
                
        for (int j = 0; j < word_len; ++j) {
            gen_str[j] = rnd_gen(97, 122);  // random character in a - z range
        }

        //std::cout << gen_str << std::endl;
        vect[i] = gen_str;
        //gen_str = "";
    }

    for (std::string str : vect) {
        std::cout << str << std::endl;
    }


 
    std::string max_word;
    std::string min_word;
        
    int max_len;
    int min_len;
    
    for (int i = 0; i < vect.size(); ++i) {
             
        
        if (i == 0) {
            max_len = min_len = vect[i].length();
        }
        
        if (vect[i].length() > max_len) {
            max_len = vect[i].length();
            max_word = vect[i];
        }
        else if (vect[i].length() < min_len) {
            min_len = vect[i].length();
            min_word = vect[i];
        }

    }
    std::cout << std::endl;
    std::cout << "Max word: " << max_word << " Length: " << max_len << std::endl;
    std::cout << "Min word: " << min_word << " Length: " << min_len << std::endl;
   
}