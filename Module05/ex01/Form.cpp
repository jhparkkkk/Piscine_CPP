/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 10:36:18 by jeepark           #+#    #+#             */
/*   Updated: 2022/11/25 14:47:44 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

/*********************** CONSTRUCTOR & DESTRUCTOR *****************************/
Form::Form() : _name("default"), _isSigned(NO), _gradeToSign(10), _gradeToExecute(100) { return; }

Form::Form(std::string const & name, int grade1, int grade2) : _name(name), _isSigned(NO), _gradeToSign(grade1), _gradeToExecute(grade2)
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
    std::cout << "Form " << _name << " created" << std::endl;
    return;
}

Form::Form( Form const & src) : _name(src._name), _isSigned(src._isSigned), _gradeToSign(src._gradeToSign), _gradeToExecute(src._gradeToExecute)
{
    std::cout << "Form Copy constructor called" << std::endl;
    *this = src;
    return;
}

Form & Form::operator=(Form const & rhs)
{
    std::cout << "Form Copy assignment operator called" << std::endl;
    _isSigned = rhs._isSigned;
    return  *this;
}

Form::~Form( void )
{
    std::cout << "Form destroyed" << std::endl;
    return;
}
/**************************** SETTERS & GETTERS *****************************/

std::string const   Form::getName() const { return _name ; }

bool    Form::getSigned() const { return _isSigned ; }

int Form::getGradeTosign() const { return _gradeToSign ; }

int Form::getGradeToExecute() const { return _gradeToExecute ;}

/*********************** PUBLIC MEMBER FUNCTION *****************************/

void    Form::beSigned(Bureaucrat const & bureaucrat)
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

/************************* NON MEMBER FUNCTION *******************************/

std::ostream & operator<<( std::ostream & o, Form const & rhs)
{
    o << "Form name : " << rhs.getName() << std::endl 
    << "Signed: " << rhs.getSigned() << std::endl
    << "Grade to sign: " << rhs.getGradeTosign() << std::endl
    << "Grade to execute: " << rhs.getGradeToExecute() << std::endl;
    return o;
}