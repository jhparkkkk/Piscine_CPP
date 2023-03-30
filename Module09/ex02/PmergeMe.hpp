#ifndef PMERGEME_HPP
 #define PMERGEME_HPP

#include <iostream>
#include <list>
#include <vector>
#include <ctime>
#include <assert.h>

class PmergeMe {

    public:
        PmergeMe(char**av, int ac);
        PmergeMe(PmergeMe const &);
        PmergeMe& operator=(PmergeMe const &);
        ~PmergeMe();

        void    parseInput(char **, int);
        void    findDuplicates();
        void    displayUnsortedSequence();
        void    fillContainers();
        void    displayResult();
        void    displayResultVector();

        void    mergeInsertSort();
        void    findStraggler();
        void    createPairs();
        void    sortPairs();
        void    sortByLargerValue();
        void    insertionSortPairs(int size);
        void    createRes();
        /* debug */
        void    displayPairs();

        class InputException : public std::exception {
            public:
                virtual const char* what() const throw();
        };
    
    private:
        std::string             _buf;
        std::vector<int>        _toSort;
        std::vector<int>        _cVector;     
        std::list<int>          _cList;
        long double             _timeVector;
        long double             _timeList;

        int                     _straggler;
        std::vector<std::pair<int, int> >   _splitData;
        std::vector<int>        _vectorRes;
        PmergeMe();
};

#endif

/*
    mergeInsertSort();
    findStraggler();
    createPairs();
    SortPairs();
    SortByLargerValue();
    insertionSortPairs();
    Insert();
    createRes();
    buildJacobInsertionSequence();
    Jacobsthal();
*/
