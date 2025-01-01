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
			const Animal *j = new Dog();
			const Animal *i = new Cat();
			delete j; // should not create a leak
			delete i;
		}
		catch(const std::bad_alloc& e)
		{
			std::cerr << e.what() << '\n';
		}

	}
	{
		cout << GREEN << "\n----------====EXIRCISE II====---------\n"
			 << ORANGE << endl;
		try
		{
			const Animal *j = new Dog();
			const Animal *i = new Cat();
			const Dog *y = new Dog();
			const Cat *x = new Cat();
			j->makeSound();
			i->makeSound();
			delete i;
			delete j;
			j = x;
			i = y;
			j->makeSound();
			i->makeSound();
			delete x;
			delete y;
		}
		catch (std::bad_alloc &e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	{
		cout << GREEN << "\n---------====EXIRCISE III====---------\n" << ORANGE << endl;
		size_t count = 10;
		Animal *animals[count];
		try
		{
			for (size_t i = 0; i < count; i++)
			{
				if (i % 2 == 0)
					animals[i] = new Dog();
				else
					animals[i] = new Cat();
			}
		}
		catch(const std::bad_alloc& e)
		{
			std::cerr << e.what() << '\n';
		}
		std::cout <<  BLUE << "-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-" << std::endl;
		for (size_t i = 0; i < count; i++)
			animals[i]->makeSound();
		std::cout <<  RED << "-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-" << std::endl;
		for (size_t i = 0; i < count; i++)
			delete animals[i];
	}
	{
		cout << GREEN << "\n---------====EXIRCISE IV====---------\n" << ORANGE << endl;
		Dog a;
		Cat b;

		Brain bcat;
		Brain bdog;
		bcat.setIdea(0, "I'm a cat");
		bcat.setIdea(2, "I'm a cat");
		bdog.setIdea(0, "I'm a dog");
		bdog.setIdea(2, "I'm a dog");
		a.setBrain(bdog);
		b.setBrain(bcat);
		a.printIdeas();
		b.printIdeas();

	}
	cout << RESET;
}
