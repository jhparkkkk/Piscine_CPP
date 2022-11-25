/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 19:40:10 by jeepark           #+#    #+#             */
/*   Updated: 2022/11/25 15:21:26 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
int main()
{
    Bureaucrat alpha = Bureaucrat("Bernard", -7);
    Bureaucrat beta = Bureaucrat("Lenina", 12);
    Bureaucrat epsilon = Bureaucrat("John", 158);
    Bureaucrat alpha_plus = Bureaucrat("Mustapha", 1);
    alpha_plus.gradeUp();
    std::cout << beta << std::endl;
    beta.gradeUp();
    std::cout << beta << std::endl;
    epsilon.gradeDown();
    beta.gradeDown();
    std::cout << beta << std::endl;

    Form invalid_form_1 = Form("Form 1", -10, 50);
    Form invalid_form_2 = Form("Form 2", 10, 151);
    Form form = Form("no. 1", 20, 50);
    
    beta.signForm(form);
    epsilon.signForm(form);

    return 0;
}