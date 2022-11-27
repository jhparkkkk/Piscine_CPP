/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 19:40:33 by jeepark           #+#    #+#             */
/*   Updated: 2022/11/26 17:10:55 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

/*********************** CONSTRUCTOR & DESTRUCTOR *****************************/

Bureaucrat::Bureaucrat() :
_name("default")
{
    std::cout << "Bureaucrat " << _name << " created" << std::endl;
    return;
}
/* 
    Since name is const, attributs must be set with initialization list.
    If grade value is incorrect, exception is thrown. This will be caught by
    createBureaucrat(). (if I catch exception directly in the constructor,
    bureaucrat is still created)
*/
Bureaucrat::Bureaucrat(std::string const & name, int grade) :
_name(name),
_grade(grade)
{
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
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

/*
    form passed as parameter is signed by bureaucrat only if _grade < _gradeToSign.
*/
void    Bureaucrat::signForm(AForm & form)
{
    try
    {
        form.beSigned(*this);
        std::cout << _name << " signed " << form.getName() << std::endl;
    }
    catch (AForm::GradeTooLowException & exception)
    { std::cout << _name << " can't sign " << form.getName()
        << " because " << exception.what() << std::endl; }
}

void    Bureaucrat::executeForm(AForm const & form)
{
    try 
    {
        form.execute(*this);
        std::cout << _name << " executed " << form.getName() << std::endl;
    }
    catch (std::exception & ex)
    {
        std::cout << _name << " can't execute " << form.getName()
        << " because " <<  ex.what() << std::endl;
    }
    return;
}

/************************* NON MEMBER FUNCTION *******************************/

std::ostream & operator<<( std::ostream & o, Bureaucrat const & rhs)
{
    o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << ".";
    return o;
}

/************************** EXCEPTIONS ****************************************/

const char * Bureaucrat::GradeTooHighException::what() const throw()
{
    return "grade is too high";
}

const char * Bureaucrat::GradeTooLowException::what()const throw()
{
	return "grade is too low" ;
}

const char * Bureaucrat::FailedExecutionException::what()const throw()
{
    return "cannot execute." ;
}