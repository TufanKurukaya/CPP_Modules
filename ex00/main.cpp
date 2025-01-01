#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	{
		cout << GREEN << "----------====EXIRCISE I====----------\n" << PURPLE << endl;

		Dog Kangal;
		Cat VanKedisi;
		Kangal.makeSound();
		VanKedisi.makeSound();
	}
	{
		cout << GREEN << "\n----------====EXIRCISE II====---------\n" << ORANGE << endl;
		const Animal *meta = new Animal();
		const Animal *j = new Dog();
		const Animal *i = new Cat();
		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		i->makeSound(); // will output the cat sound!
		j->makeSound();
		meta->makeSound();
		delete meta;
		delete j;
		delete i;
	}
	{
		cout << GREEN << "\n----------====EXIRCISE II====---------\n" << ORANGE << endl;
		const WrongAnimal *meta = new WrongAnimal();
		const WrongAnimal *i = new WrongCat();
		std::cout << i->getType() << " " << std::endl;
		i->makeSound(); // will output the Worng animal sound!
		meta->makeSound();
		delete meta;
		delete i;
	}
	cout << RESET;
}
