#include "Cat.hpp"


Cat::Cat() : Animal()
{
    type = "Cat";
    std::cout << "Hi, " << type << " has been constructed!!!" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other) {}

Cat& Cat::operator=(const Cat& other)
{
    if (this != &other)
        Animal::operator=(other);
    return *this;
}

Cat::~Cat()
{
    std::cout << "Ouch " << type << " destroyed!!!" << std::endl;
}

std::string Cat::getType() const
{
    return this->type;
}

void Cat::makeSound() const
{
    std::cout << "miau miau miau" << std::endl;
}