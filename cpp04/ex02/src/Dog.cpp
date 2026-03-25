#include "Dog.hpp"


Dog::Dog() : Animal()
{
    type = "Dog";
    dogBrain = new Brain();
    std::cout << type << " has been constructed!!!" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other) 
{
    dogBrain = new Brain(*other.dogBrain);
    std::cout << "Dog copy constructed" << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
    if (this != &other)
    {
        Animal::operator=(other); //copy parent
        delete dogBrain; // avoid memory leak, deleting old brain
        std::cout << "Dog copy assignment operator called!!!" << std::endl;
        dogBrain = new Brain(*other.dogBrain); // deep copy, creating new brain
    }
    return *this;
}

Dog::~Dog()
{
    delete dogBrain;
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