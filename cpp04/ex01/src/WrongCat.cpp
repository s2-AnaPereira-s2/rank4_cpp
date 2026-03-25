#include "WrongCat.hpp"


WrongCat::WrongCat() : WrongAnimal()
{
    type = "WrongCat";
    std::cout << type << " constructed!!" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other) {}

WrongCat& WrongCat::operator=(const WrongCat& other)
{
    if (this != &other)
        WrongAnimal::operator=(other);
    return *this;
}

WrongCat::~WrongCat()
{
    std::cout << "Bye WrongCat has been destroyed!" << std::endl;
}

std::string WrongCat::getType() const
{
    return this->type;
}

void WrongCat::makeSound() const
{
    std::cout << "wrong miau miau miau" << std::endl;
}