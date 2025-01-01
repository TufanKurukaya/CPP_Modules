#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"
int main()
{
	{
		cout << GREEN << "----------====EXIRCISE I====----------\n" << PURPLE << endl;
		try
		{
			const Animal* dog = new Dog();
			const Animal* cat = new Cat();


			std::cout << dog->getType() << " " << std::endl;
			std::cout << cat->getType() << " " << std::endl;

			dog->makeSound(); // "Woof!" gibi bir ses
			cat->makeSound(); // "Meow!" gibi bir ses

			// Belleği temizleyelim
			delete dog;
			delete cat;
		}
		catch(const std::bad_alloc& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	cout << RESET;
}
