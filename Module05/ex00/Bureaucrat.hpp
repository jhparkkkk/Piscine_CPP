/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 19:40:29 by jeepark           #+#    #+#             */
/*   Updated: 2022/11/25 10:24:39 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
 #define BUREAUCRAT_HPP
#include <iostream>

class   Bureaucrat {
    public:
        Bureaucrat();
        Bureaucrat(std::string const &, int);
        Bureaucrat(Bureaucrat const &);
        Bureaucrat& operator=(Bureaucrat const &);
        ~Bureaucrat();

        std::string const   getName() const;
        int                 getGrade() const;

        void                gradeUp();
        void                gradeDown();

    class   GradeTooHighException : public std::exception
    {
        public:
            virtual const char * what() const throw()
            { return ": Grade is too high."; }
        
    };
    class   GradeTooLowException : public std::exception
    {
        public:
            virtual const char * what() const throw()
            { return ": Grade is too low."; }
    };
    
    
    private:
        std::string const   _name;
        int                 _grade;  
};

std::ostream & operator<<( std::ostream & o, Bureaucrat const & rhs);

#endif