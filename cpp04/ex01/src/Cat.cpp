#include "Cat.hpp"


Cat::Cat() : Animal()
{
    type = "Cat";
    catBrain = new Brain();
    std::cout << "Hi, " << type << " has been constructed!!!" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other) 
{
    catBrain = new Brain(*other.catBrain); // deep copy
    std::cout << "Cat copy constructed" << std::endl;
}

Cat& Cat::operator=(const Cat& other)
{
    std::cout << "Cat copy assignment operator called!!!" << std::endl;
    if (this != &other)
    {
        Animal::operator=(other);

        delete catBrain;
        catBrain = new Brain(*other.catBrain); // deep copy
    }
    return *this;
}

Cat::~Cat()
{
    delete catBrain;
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