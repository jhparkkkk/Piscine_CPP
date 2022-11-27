/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 10:36:18 by jeepark           #+#    #+#             */
/*   Updated: 2022/11/26 16:20:11 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

/************************** CONSTRUCTOR & DESTRUCTOR **************************/
AForm::AForm() :
_name("default"),
_isSigned(NO),
_gradeToSign(10),
_gradeToExecute(100)
{ return; }

AForm::AForm(std::string const & name, int grade1, int grade2) :
_name(name),
_isSigned(NO),
_gradeToSign(grade1),
_gradeToExecute(grade2)
{
    try
    {
        if (_gradeToSign < HIGHEST_GRADE || _gradeToExecute < HIGHEST_GRADE)
            throw GradeTooHighException();
        else if (_gradeToSign > LOWEST_GRADE || _gradeToExecute > LOWEST_GRADE)
            throw GradeTooLowException();
    }
    catch (GradeTooHighException & exception)
    { std::cout << *this <<  exception.what() << std::endl; }
    catch (GradeTooLowException & exception)
    { std::cout << *this <<  exception.what() << std::endl; }
    
    std::cout << "AForm " << _name << " created" << std::endl;
    return;
}

AForm::AForm( AForm const & src) : _name(src._name),
_isSigned(src._isSigned),
_gradeToSign(src._gradeToSign),
_gradeToExecute(src._gradeToExecute)
{
    std::cout << "AForm Copy constructor called" << std::endl;
    *this = src;
    return;
}

AForm & AForm::operator=(AForm const & rhs)
{
    std::cout << "AForm Copy assignment operator called" << std::endl;
    _isSigned = rhs._isSigned;
    return  *this;
}

AForm::~AForm( void )
{
    std::cout << "AForm destroyed" << std::endl;
    return;
}
/************************** SETTERS & GETTERS ********************************/

std::string const   AForm::getName() const { return _name ; }

bool    AForm::getSigned() const { return _isSigned ; }

int AForm::getGradeTosign() const { return _gradeToSign ; }

int AForm::getGradeToExecute() const { return _gradeToExecute ;}

/************************** PUBLIC MEMBER FUNCTION ***************************/

/*
    Checks if bureaucrat's grade is high enough before signing the form.
*/
void    AForm::beSigned(Bureaucrat const & bureaucrat)
{
    if (bureaucrat.getGrade() > _gradeToSign)
    {
            throw GradeTooLowException();
    }
    else
    {
        _isSigned = YES;
    }
}

/*
    checks if form is signed and if executor's grade is high enough to execute.
    Function is called by concrete classes that inherit from this method.
*/
void	AForm::execute(Bureaucrat const & executor) const
{
    if (_isSigned == NO)
        throw FormNotSignedException();
    else if (executor.getGrade() > _gradeToExecute)
        throw GradeTooLowException();
    return;
}


/************************** NON MEMBER FUNCTION *******************************/

std::ostream & operator<<( std::ostream & o, AForm const & rhs)
{
    o << "Form name : " << rhs.getName() << std::endl 
    << "Signed: " << rhs.getSigned() << std::endl
    << "Grade to sign: " << rhs.getGradeTosign() << std::endl
    << "Grade to execute: " << rhs.getGradeToExecute() << std::endl;
    return o;
}

/************************** EXCEPTIONS ****************************************/

const char * AForm::GradeTooHighException::what() const throw()
{
    return "grade is too high";
}

const char * AForm::GradeTooLowException::what()const throw()
{
	return "grade is too low" ;
}

const char * AForm::FormNotSignedException::what()const throw()
{
	return "form is not signed" ;
}