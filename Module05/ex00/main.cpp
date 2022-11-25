/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 19:40:10 by jeepark           #+#    #+#             */
/*   Updated: 2022/11/25 10:25:52 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

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
    return 0;
}