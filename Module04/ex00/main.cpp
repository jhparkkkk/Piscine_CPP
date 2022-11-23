/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 10:29:45 by jeepark           #+#    #+#             */
/*   Updated: 2022/11/23 12:21:11 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"


#include <iostream> 

/*
    keyword "virtual" converts static function function into dynamic function call.
    Virtual member function == method
    even if I instanciate a cat with class Cat but with type Animal (inherited)
    Cat will behave like a cat. 
*/
int main ()
{
    std::cout << "**** Construction ****" << std::endl;
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    const WrongAnimal* wrong_animal = new WrongAnimal();
    const WrongAnimal* wrong_cat = new WrongCat();
    const WrongCat* cool_cat = new WrongCat();
    
    std::cout << std::endl;
    
    std::cout << "* with keyword <virtual> *" << std::endl;
    std::cout << "Type should be <dog>:" << std::endl;
    std::cout << j->getType() << " " << std::endl;
    std::cout << "Type should be <cat>:" << std::endl;
    std::cout << i->getType() << std::endl;
    std::cout << "Will output the cat sound: " << std::endl;
    i->makeSound();
    std::cout << "Will output the dog sound: " << std::endl;
    j->makeSound();
    std::cout << "Will output default animal sound: " << std::endl;
    meta->makeSound();
    std::cout << "Type should be <cat>:" << std::endl;
    std::cout << wrong_cat->getType() << std::endl;

    std::cout << "* without keyword <virtual> *" << std::endl;
    std::cout << "Will output default animal sound: " << std::endl;
    wrong_animal->makeSound();
    std::cout << "Won't output the cat sound but the default one: " << std::endl;
    wrong_cat->makeSound();
    std::cout << "Type should be <cat>:" << std::endl;
    std::cout << cool_cat->getType() << std::endl;
    std::cout << "Will output the cat sound as it is instanciated with WrongCat type: " << std::endl;
    cool_cat->makeSound();
    
    std::cout << std::endl << "**** Destruction ****" << std::endl;
    delete meta;
    delete j;
    delete i;
    delete wrong_animal;
    delete wrong_cat;
    delete cool_cat;
    return 0;
}