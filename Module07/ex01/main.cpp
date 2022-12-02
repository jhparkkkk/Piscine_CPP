/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeepark <jeepark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 22:45:12 by jeepark           #+#    #+#             */
/*   Updated: 2022/12/02 18:26:46 by jeepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <cmath>

// class A
// {
//     public:
//         A(): _n(42) {return;}
//         int get() const {return this->_n;}
//     private:
//         int _n;
// };

// std::ostream & operator<<(std::ostream & o, A const & rhs) { o << rhs.get(); return o;}
// template<typename T>
// void    print(T const &x) { std::cout << x << std::endl; return;}

// int main()
// {
//     int tab[] = {0, 1, 2, 3, 4};
//     A tab2[5];

//     ::iter(tab, 5, print);
//     ::iter(tab2, 5, print);    
//     return 0;
// }

template <typename T>
void    test(T & n)
{
    n += n;
    return;
}

template <typename T>
void    toUpper(T & s)
{
    for (size_t i = 0; i < s.size(); i++)
        s[i] -= 32;
        
}

int main()
{
    double tab[] = {0.10, 1.32, 2.2423, 3.5245, 4.523};
    
    ::iter<double>(tab, 5, &::test);

    for(int i = 0; i < 5; i++)
        std::cout << tab[i]<< std::endl;
    
    std::string str[2] = {"jee", "park"};
    for(int i = 0; i < 2; i++)
        std::cout << str[i]<< std::endl;
    ::iter(str, 2, &::toUpper);
    for(int i = 0; i < 2; i++)
        std::cout << str[i]<< std::endl;
    
    return 0;
}