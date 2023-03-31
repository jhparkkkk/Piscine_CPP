#ifndef PMERGEME_HPP
 #define PMERGEME_HPP

#include <iostream>
#include <deque>
#include <vector>
#include <ctime>
#include <assert.h>

class PmergeMe {

    public:
        /* constructors and destructor */
        PmergeMe(char**av, int ac);
        PmergeMe(PmergeMe const &);
        PmergeMe& operator=(PmergeMe const &);
        ~PmergeMe();

        /* parsing */
        void    parseInput(char **, int);
        void    findDuplicates();
        void    displayUnsortedSequence();
        void    fillContainers();
        
        /* merge-insert sort */
        void    mergeInsertSort();
        void    displayResult();

        /* vector */
        void    vFindStraggler();
        void    vCreatePairs();
        void    vSortPairs();
        void    vSortByLargerValue();
        void    vInsertionSortPairs(int size);
        void    vCreateRes();
        void    vBinarySearch();

        /* deque */
        void    dFindStraggler();
        void    dCreatePairs();
        void    dSortPairs();
        void    dSortByLargerValue();
        void    dInsertionSortPairs(int size);
        void    dCreateRes();
        void    dBinarySearch();

        /* utils */
        void    displayPairs();
        void    displayResultVector();
        void    displayResultDeque();

        class InputException : public std::exception {
            public:
                virtual const char* what() const throw();
        };
    
    private:
        std::string                         _buf;
        std::vector<int>                    _cVector;
        std::deque<int>                     _cDeque;    
        float                               _timeVector;
        float                               _timeDeque;
        bool                                _isStraggler;
        int                                 _straggler;
        std::vector<std::pair<int, int> >   _splitVector;
        std::deque<std::pair<int, int> >   _splitDeque;
        std::vector<int>                    _vectorRes;
        std::deque<int>                     _dequeRes;

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
