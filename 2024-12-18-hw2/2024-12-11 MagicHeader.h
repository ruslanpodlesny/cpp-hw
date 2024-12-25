#pragma once

class Integer
{
private:
    int magicValue;
    
public:
    const int absoluteMagicValue = 777;

    Integer(int enterMagicValue);

    Integer(const Integer& value_x);

    void setMagicValue(int value);

    int getMagicValue() const;

    void printMagicValue() const;

};