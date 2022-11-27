/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 19:40:10 by jeepark           #+#    #+#             */
/*   Updated: 2022/11/26 17:08:43 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
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
    
    std::cout << beta << std::endl;
    beta->gradeUp();
    std::cout << beta << std::endl;
    epsilon->gradeDown();
    beta->gradeDown();
    std::cout << beta << std::endl;

    Form invalid_form_1 = Form("Form 1", -10, 50);
    Form invalid_form_2 = Form("Form 2", 10, 151);
    Form form = Form("no. 1", 20, 50);
    
    epsilon->signForm(form);
    beta->signForm(form);

    if (alpha)
        delete alpha;
    if (beta)
        delete beta;
    if (epsilon)
        delete epsilon;

    return 0;
}