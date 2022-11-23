/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 10:29:45 by jeepark           #+#    #+#             */
/*   Updated: 2022/11/23 15:03:52 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream> 

int main ()
{
    std::cout << "**** Construction ****" << std::endl;
    // Animal abstract = Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    
    std::cout << std::endl;
    
    const Animal* animal[10];
    for (int i = 0; i < 5; i++)
        animal[i] = new Cat();
    for (int i = 5; i < 10; i++)
        animal[i] = new Dog();
    for (int i = 0; i < 10; i++)
        animal[i]->makeSound();
    for (int i = 0; i < 10; i++)
        delete animal[i];

    {
        std::cout << std::endl << "* DEEP COPY *" << std::endl;
        Cat *cat = new Cat();
        Dog *dog = new Dog();
        cat->displayIdeas();
        std::cout << std::endl;
        dog->displayIdeas();
        Cat *cat_copy = new Cat(*cat);
        Dog *dog_copy = new Dog(*dog);
        cat->setIdeas("Nothing");
        delete cat;
        delete dog;
        cat_copy->displayIdeas();
        dog_copy->displayIdeas();
        delete cat_copy;
        delete dog_copy;
    }

    {
        std::cout << std::endl << "* SHALLOW COPY *" << std::endl;
        Cat *cat = new Cat();
        Dog *dog = new Dog();
        cat->displayIdeas();
        std::cout << std::endl;
        dog->displayIdeas();
        cat->setType("old cat");
        Cat *cat_copy = cat;
        Dog *dog_copy = dog;
        cat->setIdeas("Nothing");
        delete cat;
        delete dog;
        cat_copy->displayIdeas();
        dog_copy->displayIdeas();
        delete cat_copy;
        delete dog_copy;
    }
    

    
        
    
    
    std::cout << std::endl << std::endl << "**** Destruction ****" << std::endl;
    delete j;//should not create a leak
    delete i;
    return 0;
}