/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 19:40:10 by jeepark           #+#    #+#             */
/*   Updated: 2022/11/26 19:58:10 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
/*
    Attempts to create a bureaucrat:
    if an exception is caught, error msg is displayed and bureaucrat is not created.
    else returns bureaucrat.
*/
Bureaucrat * createBureaucrat(Bureaucrat * bureaucrat, std::string name, int grade)
{
    try
    {
        bureaucrat = new Bureaucrat(name, grade);
    }
    catch (std::exception & e)
    {
        std::cout << "error: " << e.what() << std::endl;
        std::cout << "bureaucrat " << name << " cannot be created. Try [1 - 150]" << std::endl;
    }
    return bureaucrat;
}

int main()
{
    std::cout << std::endl << "*--- BUREAUCRATS ---*" << std::endl;
    Bureaucrat *alpha = NULL;
    Bureaucrat *beta = NULL;
    Bureaucrat *epsilon = NULL;
    
    std::cout << std::endl << "* Invalid bureaucrat *" << std::endl;
    alpha = createBureaucrat(alpha, "Bernard", -1);
    beta = createBureaucrat(beta, "Lenina", 4032);
    epsilon = createBureaucrat(epsilon, "John", 151);
    
    std::cout << std::endl;

    std::cout << "* Valid bureaucrat *" << std::endl;
    alpha = createBureaucrat(alpha, "Bernard", 1);
    beta = createBureaucrat(beta, "Lenina", 6);
    epsilon = createBureaucrat(epsilon, "John", 137);
    
    std::cout << std::endl;

    std::cout << " * Bureaucrats' id *" << std::endl;
    std::cout << *alpha << std::endl;
    std::cout << *epsilon << std::endl;
    
    std::cout << std::endl;
    
    std::cout << std::endl << "*--- FORMS ---*" << std::endl << std::endl;

    AForm *shrub = new  ShrubberyCreationForm("tree");
    AForm *rob = new RobotomyRequestForm("noise");
    AForm *pres = new PresidentialPardonForm("plop");
    
    beta->executeForm(*shrub);
    alpha->signForm(*shrub);
    beta->executeForm(*shrub);
    alpha->signForm(*rob);
    beta->executeForm(*rob);

    beta->signForm(*pres);
    epsilon->executeForm(*pres);
    alpha->executeForm(*pres);

    std::cout << std::endl << "*--- INTERNS ---*" << std::endl << std::endl;
    Intern intern = Intern();
    AForm* rrf;
    
    try 
    {
        rrf = intern.makeForm("randoooom", "pardon");
        std::cout << "Intern creates " << rrf->getName() << std::endl;
    }
    catch (std::exception & ex)
    {
        std::cout << "Intern can't make form because " << ex.what() << std::endl; 
    }

    try 
    {
        rrf = intern.makeForm("robotomy request", "Bender");
        std::cout << "Intern creates " << rrf->getName() << std::endl;
    }
    catch (std::exception & ex)
    {
        std::cout << "Intern can't make form because " << ex.what() << std::endl; 
    }


    std::cout << std::endl << "*--- DESTRUCTION ---*" << std::endl << std::endl;
    
    if (alpha)
        delete alpha;
    if (beta)
        delete beta;
    if (epsilon)
        delete epsilon;

    delete shrub;
    delete rob;
    if (pres)
        delete pres;
    if (rrf)
        delete rrf;
    return 0;
}