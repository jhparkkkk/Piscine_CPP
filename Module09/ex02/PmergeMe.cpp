#include "PmergeMe.hpp"
#include <sstream>
#include <limits.h>
#include <stdlib.h>
#include <algorithm>

/*********************** CONSTRUCTOR & DESTRUCTOR *****************************/
PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(char** av, int ac)
{
    try
    {
        parseInput(av, ac);
        findDuplicates();
    }
    catch (InputException & e) {
        std:: cout << e.what() << "\n";
        exit(1); }
    
    displayUnsortedSequence();
    fillContainers();
    mergeInsertSort();
    // doSort(this->_cList, this->_timeList);
    // doSort(this->_cVector, this->_timeVector);
    displayResultVector();
    return;
}

PmergeMe::PmergeMe( PmergeMe const & src)
{
      *this = src;
      return;
}

PmergeMe & PmergeMe::operator=(PmergeMe const & o)
{
    this->_buf = o._buf;
    this->_toSort = o._toSort;
    this->_cVector = o._cVector;
    this->_cList = o._cList;
    this->_timeVector = o._timeVector;
    this->_timeList = o._timeList;
    return  *this;
}

PmergeMe::~PmergeMe( void ) {}

/************************** PUBLIC MEMBER FUNCTION ****************************/

/* if number of element is odd, take off a straggler */
void    PmergeMe::findStraggler()
{
    if (_cVector.size() % 2 != 0)
    {
        _straggler = _cVector.back(); 
        _cVector.pop_back();
    }

}

/* split data into pairs */
void   PmergeMe::createPairs()
{
    int nb_pairs = _cVector.size() / 2;
    int i = 0;
    while(nb_pairs-- > 0)
    {
        _splitData.push_back(std::make_pair(_cVector[i], _cVector[i + 1]));
        i += 2;
    }

    displayPairs();

}

void    PmergeMe::sortPairs()
{
    for(size_t i=0; i < _splitData.size(); i++)
    {
        if (_splitData[i].first > _splitData[i].second)
            std::swap(_splitData[i].first, _splitData[i].second);
    }
    std::cout << "\n";
    displayPairs();
}

void    PmergeMe::insertionSortPairs(int size)
{
    if (size < 1)
        return;
    // else
    // {
    //     insertionSortPairs(size);
    //     // insert();
    // }
}


void    PmergeMe::sortByLargerValue()
{
    int n = _splitData.size() - 1;
    int last = _splitData.size() - 1;

    std::cout << "size: " << n << "\n";
    
    // if (_splitData[0].second > _splitData[1].second)
        // std::swap(_splitData[0], _splitData[1]);
    int i = n ;
    while (n >= 0)
    {
        i = last - 1;
        n--;
        int j = i -1;
        while (_splitData[i].second < _splitData[i - 1].second && i > 0)
        {
            std::cout << "data[" << i << "] = " << _splitData[i].second << " ";
            std::swap(_splitData[i], _splitData[i - 1]);
            i--;
        }
        std::cout << "\n";
        displayPairs();

    }
        std::cout << "\n";

    displayPairs();
    // insertionSortPairs(size);


}

void    PmergeMe::mergeInsertSort()
{
    findStraggler();
    createPairs();
    sortPairs();
    sortByLargerValue();

}

void    PmergeMe::fillContainers()
{
    std::copy(_toSort.begin(), _toSort.end(), std::back_inserter(_cList));
    std::copy(_toSort.begin(), _toSort.end(), std::back_inserter(_cVector));
}

void    PmergeMe::findDuplicates()
{
    std::vector<int> tmp (_toSort);
    std::sort(tmp.begin(), tmp.end());
    for (size_t i=0; i<tmp.size() -1; i++)
        if (tmp[i] == tmp[i+1])
            throw (InputException());
}

void    PmergeMe::parseInput(char** av, int ac)
{
    for (int i  = 1; i < ac; i++)
    {
        _buf += *(av + i);
        _buf += " ";
    }
    
    std::stringstream ss(_buf);
    size_t value;

    while(ss >> value) {
        if (value > INT_MAX ||  value < 0)
            throw(InputException());
        _toSort.push_back(value);
    }

    if (!ss.eof() || _toSort.empty())
        throw (InputException());


}

void    PmergeMe::displayUnsortedSequence() 
{
    std::cout << "Before: ";
    for (size_t i=0; i<_toSort.size();++i)
        std::cout << _toSort[i] << " ";
    std::cout << "\n";
}

void    PmergeMe::displayResult()
{
    std::cout << "After: ";
    for (std::list<int>::iterator it=_cList.begin(); it != _cList.end(); ++it)
        std::cout << *it << " ";
    std::cout << "\n";
    std::cout << "Time to process a range of " << _toSort.size() << " elements with std::vector : " << _timeVector << " ms.\n";
    std::cout << "Time to process a range of " << _toSort.size() << " elements with std::list : " << _timeList << " ms.\n";

}

void    PmergeMe::displayResultVector()
{
    std::cout << "After: ";
    for (std::vector<int>::iterator it=_cVector.begin(); it != _cVector.end(); ++it)
        std::cout << *it << " ";
    std::cout << "\n";

}

void    PmergeMe::displayPairs()
{
    std::vector< std::pair<int, int> >::iterator it = _splitData.begin();
    while (it != _splitData.end())
    {
        std::cout << it->first << " " << it->second << "\n";
        it++;
    }
}


/************************** NON MEMBER FUNCTION *******************************/
/************************** EXCEPTIONS ****************************************/

const char * PmergeMe::InputException::what() const throw() { return "Error"; }