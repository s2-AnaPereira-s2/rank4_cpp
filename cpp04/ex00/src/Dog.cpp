#include "Dog.hpp"


Dog::Dog() : Animal()
{
    type = "Dog";
    std::cout << type << " has been constructed!!!" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other) {}

Dog& Dog::operator=(const Dog& other)
{
    if (this != &other)
        Animal::operator=(other);
    return *this;
}

Dog::~Dog()
{
    std::cout << "Au au auuuuuu, " << type << " destroyed!!!" << std::endl;
}

std::string Dog::getType() const
{
    return this->type;
}

void Dog::makeSound() const
{
    std::cout << "au au au" << std::endl;
} 