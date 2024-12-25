#include <iostream>
#include <string>

#include "MagicHeader.h"


int main() {

    Integer value1(7);
    std::cout << "Value: " << value1.getMagicValue() << std::endl;   
    value1.printMagicValue();
    value1.setMagicValue(9);
    Integer value2(value1);
    value2.printMagicValue();
    Integer value3(11);
    std::cout << "Absolute magic value is: " << value3.absoluteMagicValue << std::endl;
    
    return 0;
}