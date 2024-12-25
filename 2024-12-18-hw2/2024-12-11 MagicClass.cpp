#include <iostream>
#include <string>

#include "MagicHeader.h"


Integer::Integer(int enterMagicValue){
    magicValue = enterMagicValue;
    std::cout << "Magic value \"" << magicValue << "\" has been assigned!" << std::endl;
}

Integer::Integer(const Integer& value_x){
    this->magicValue = value_x.magicValue;
}
void Integer::setMagicValue(int value) {
    this->magicValue = value;
    std::cout << "Magic value has been changed to \"" << magicValue << "\"!" << std::endl;
}

int Integer::getMagicValue() const {
    return magicValue;
}

void Integer::printMagicValue() const {
    std::cout << "Value \"" << magicValue << "\" has some magic!" << std::endl;
}

