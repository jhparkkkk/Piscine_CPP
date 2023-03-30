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

    

}

void    PmergeMe::sortPairs()
{
    for(size_t i=0; i < _splitData.size(); i++)
    {
        if (_splitData[i].first > _splitData[i].second)
            std::swap(_splitData[i].first, _splitData[i].second);
    }
    std::cout << "\n";
    
}

void    PmergeMe::insertionSortPairs(int n)
{
    // Base case
    if (n <= 1)
        return;
  
    // Sort first n-1 elements
    insertionSortPairs( n-1 );
  
    // Insert last element at its correct position
    // in sorted array.
    int last = _splitData[n-1].second;
    int j = n-2;
    
    /* Move elements of _splitData[0..i-1], that are
    greater than key, to one position ahead
    of their current position */
    while (j >= 0 && _splitData[j].second > last)
    {
        std::swap(_splitData[j+1], _splitData[j]);
        j--;
    }
    _splitData[j+1].second = last;
}


void    PmergeMe::sortByLargerValue()
{
    int size = _splitData.size();
    
    insertionSortPairs(size);
}

void    PmergeMe::createRes()
{
    size_t size = _splitData.size();
    for (size_t i=0; i < size; i++)
    {
        _vectorRes.push_back(_splitData[i].second);
    }

    for (size_t i=0; i< size; i++)
    {
        std::vector<int>::iterator lower = std::lower_bound(_vectorRes.begin(), _vectorRes.end(), _splitData[i].first);
        _vectorRes.insert(lower, _splitData[i].first);

    }
}

void    PmergeMe::mergeInsertSort()
{
    findStraggler();
    createPairs();
    sortPairs();
    sortByLargerValue();
    createRes();
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
    for (std::vector<int>::iterator it=_vectorRes.begin(); it != _vectorRes.end(); ++it)
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