/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 19:40:33 by jeepark           #+#    #+#             */
/*   Updated: 2022/11/25 10:32:59 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

#define LOWEST_GRADE 150
#define HIGHEST_GRADE 1

/*********************** CONSTRUCTOR & DESTRUCTOR *****************************/
Bureaucrat::Bureaucrat() : _name("default")
{
    std::cout << "Bureaucrat " << _name << " created" << std::endl;
    return;
}

Bureaucrat::Bureaucrat(std::string const & name, int grade) : _name(name), _grade(grade)
{
    try
    {
        if (_grade < 1)
            throw GradeTooHighException();
        else if (_grade > 150)
            throw GradeTooLowException();
    }
    catch (Bureaucrat::GradeTooHighException & exception)
    { std::cout << *this <<  exception.what() << std::endl; }
    catch (Bureaucrat::GradeTooLowException & exception)
    { std::cout << *this <<  exception.what() << std::endl; }
    std::cout << "Bureaucrat " << _name << " created" << std::endl;
    return;
}

Bureaucrat::Bureaucrat( Bureaucrat const & src)
{
    std::cout << "Bureaucrat Copy constructor called" << std::endl;
    *this = src;
    return;
}

Bureaucrat & Bureaucrat::operator=(Bureaucrat const & rhs)
{
    std::cout << "Bureaucrat Copy assignment operator called" << std::endl;
    _grade = rhs.getGrade();
    return  *this;
}

Bureaucrat::~Bureaucrat( void )
{
    std::cout << "Bureaucrat destroyed" << std::endl;
    return;
}
/**************************** SETTERS & GETTERS *****************************/

std::string const   Bureaucrat::getName() const { return _name ; }
int                 Bureaucrat::getGrade() const { return _grade ; }


/*********************** PUBLIC MEMBER FUNCTION *****************************/

std::ostream & operator<<( std::ostream & o, Bureaucrat const & rhs)
{
    o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << ".";
    return o;
}

/*
    _grade is decremented to grade up one's bureaucrat.
    If bureaucrat is equal or lower than the highest grade, an exception is thrown.
*/
void    Bureaucrat::gradeUp()
{
    try
    {
        if (_grade <= HIGHEST_GRADE)
            throw GradeTooHighException();
        else
            _grade--;
    }
    catch (Bureaucrat::GradeTooHighException & exception)
    { std::cout << _name << " cannot grade up: " << exception.what() << std::endl; }
    return;
}

/*
    _grade is incremented to grade down one's bureaucrat.
    If bureaucrat is equal or greater than the lowest grade, an exception is thrown.
*/
void    Bureaucrat::gradeDown()
{
    try
    {
        if (_grade >= LOWEST_GRADE)
            throw GradeTooLowException();
        else
            _grade++;
    }
    catch (Bureaucrat::GradeTooLowException & exception)
    { std::cout << _name << " cannot grade down: " << exception.what() << std::endl; }
    return;
}