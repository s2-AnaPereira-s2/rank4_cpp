#include "WrongAnimal.hpp"


WrongAnimal::WrongAnimal() : type("") 
{
    std::cout << "WrongAnimal constructed" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) : type(other.type) {}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
    if (this != &other)
    {
        this->type = other.type;
    }
    return *this;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal destroyed!!!" << std::endl;
}

std::string WrongAnimal::getType() const
{
    return this->type;
}

void WrongAnimal::makeSound() const 
{
    std::cout << "...WrongAnimal sound..." << std::endl;
} 