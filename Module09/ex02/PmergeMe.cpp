#include "PmergeMe.hpp"
#include <sstream>
#include <limits.h>
#include <stdlib.h>
#include <algorithm>

///////////////////////////////////////////////////////////////////////////////
// Constructors and destructor

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
        return; }
    
    displayUnsortedSequence();
    fillContainers();
    mergeInsertSort();
    displayResult();
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
    this->_cVector = o._cVector;
    this->_cDeque = o._cDeque;
    this->_timeVector = o._timeVector;
    this->_timeDeque = o._timeDeque;
    return  *this;
}

PmergeMe::~PmergeMe( void ) {}


///////////////////////////////////////////////////////////////////////////////
// vector

/* if number of element is odd, take off a straggler */
void    PmergeMe::vFindStraggler()
{
    if (_cVector.size() % 2 != 0)
    {
        _isStraggler = true;
        _straggler = _cVector.back(); 
        _cVector.pop_back();
    }
    else
        _isStraggler = false;
}

/* split data into pairs */
void   PmergeMe::vCreatePairs()
{
    int nb_pairs = _cVector.size() / 2;
    int i = 0;
    while(nb_pairs-- > 0)
    {
        _splitVector.push_back(std::make_pair(_cVector[i], _cVector[i + 1]));
        i += 2;
    }    

}

void    PmergeMe::vSortPairs()
{
    for(size_t i=0; i < _splitVector.size(); i++)
    {
        if (_splitVector[i].first > _splitVector[i].second)
            std::swap(_splitVector[i].first, _splitVector[i].second);
    }
    std::cout << "\n";
    
}

void    PmergeMe::vInsertionSortPairs(int n)
{
    // Base case
    if (n <= 1)
        return;
  
    // Sort first n-1 elements
    vInsertionSortPairs( n-1 );
  
    // Insert last element at its correct position
    // in sorted array.
    int last = _splitVector[n-1].second;
    int j = n-2;
    
    /* Move elements of _splitVector[0..i-1], that are
    greater than key, to one position ahead
    of their current position */
    while (j >= 0 && _splitVector[j].second > last)
    {
        std::swap(_splitVector[j+1], _splitVector[j]);
        j--;
    }
    _splitVector[j+1].second = last;
}


void    PmergeMe::vSortByLargerValue()
{
    int size = _splitVector.size();
    vInsertionSortPairs(size);
}

void    PmergeMe::vBinarySearch()
{


}

void    PmergeMe::vCreateRes()
{
    size_t size = _splitVector.size();
    for (size_t i=0; i < size; i++)
    {
        _vectorRes.push_back(_splitVector[i].second);
    }

    for (size_t i=0; i< size; i++)
    {
        std::vector<int>::iterator lower = std::lower_bound(_vectorRes.begin(), _vectorRes.end(), _splitVector[i].first);
        _vectorRes.insert(lower, _splitVector[i].first);

    }
    if (_isStraggler)
    {
         std::vector<int>::iterator lower = std::lower_bound(_vectorRes.begin(), _vectorRes.end(), _straggler);
        _vectorRes.insert(lower, _straggler);
    }   
}

///////////////////////////////////////////////////////////////////////////////
// Deque

/* if number of element is odd, take off a straggler */
void    PmergeMe::dFindStraggler()
{
    if (_cDeque.size() % 2 != 0)
    {
        _isStraggler = true;
        _straggler = _cDeque.back(); 
        _cDeque.pop_back();
    }
    else
        _isStraggler = false;
}

/* split data into pairs */
void   PmergeMe::dCreatePairs()
{
    int nb_pairs = _cDeque.size() / 2;
    int i = 0;
    while(nb_pairs-- > 0)
    {
        _splitDeque.push_back(std::make_pair(_cDeque[i], _cDeque[i + 1]));
        i += 2;
    }    

}

void    PmergeMe::dSortPairs()
{
    for(size_t i=0; i < _splitDeque.size(); i++)
    {
        if (_splitDeque[i].first > _splitDeque[i].second)
            std::swap(_splitDeque[i].first, _splitDeque[i].second);
    }
    std::cout << "\n";
    
}

void    PmergeMe::dInsertionSortPairs(int n)
{
    // Base case
    if (n <= 1)
        return;
  
    // Sort first n-1 elements
    dInsertionSortPairs( n-1 );
  
    // Insert last element at its correct position
    // in sorted array.
    int last = _splitDeque[n-1].second;
    int j = n-2;
    
    /* Move elements of _splitDeque[0..i-1], that are
    greater than key, to one position ahead
    of their current position */
    while (j >= 0 && _splitDeque[j].second > last)
    {
        std::swap(_splitDeque[j+1], _splitDeque[j]);
        j--;
    }
    _splitDeque[j+1].second = last;
}


void    PmergeMe::dSortByLargerValue()
{
    int size = _splitDeque.size();
    dInsertionSortPairs(size);
}

void    PmergeMe::dCreateRes()
{
    size_t size = _splitDeque.size();
    for (size_t i=0; i < size; i++)
    {
        _dequeRes.push_back(_splitDeque[i].second);
    }

    for (size_t i=0; i< size; i++)
    {
        std::deque<int>::iterator lower = std::lower_bound(_dequeRes.begin(), _dequeRes.end(), _splitDeque[i].first);
        _dequeRes.insert(lower, _splitDeque[i].first);

    }
    if (_isStraggler)
    {
         std::deque<int>::iterator lower = std::lower_bound(_dequeRes.begin(), _dequeRes.end(), _straggler);
        _dequeRes.insert(lower, _straggler);
    }   
}


///////////////////////////////////////////////////////////////////////////////
// Ford Johnson merge-insert sort 

void    PmergeMe::mergeInsertSort()
{
    /* vector */
    {
        clock_t start = clock();
        vFindStraggler();
        vCreatePairs();
        vSortPairs();
        vSortByLargerValue();
        vCreateRes();
        clock_t end = clock();
        _timeVector = static_cast<float> (end-start) / CLOCKS_PER_SEC * 1000000.0;
    }

    /* deque */
    {
        clock_t start = clock();
        dFindStraggler();
        dCreatePairs();
        dSortPairs();
        dSortByLargerValue();
        dCreateRes();
        clock_t end = clock();
        _timeDeque = static_cast<float> (end-start) / CLOCKS_PER_SEC * 1000000.0;
    }
}

///////////////////////////////////////////////////////////////////////////////
// Utils

void    PmergeMe::fillContainers()
{
    std::copy(_cVector.begin(), _cVector.end(), std::back_inserter(_cDeque));
}

void    PmergeMe::findDuplicates()
{
    std::vector<int> tmp (_cVector);
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
        _cVector.push_back(value);
    }

    if (!ss.eof() || _cVector.empty())
        throw (InputException());


}

void    PmergeMe::displayUnsortedSequence() 
{
    std::cout << "Before: ";
    for (size_t i=0; i<_cVector.size();++i)
        std::cout << _cVector[i] << " ";
    std::cout << "\n";
}

void    PmergeMe::displayResult()
{
    displayResultVector();
    displayResultDeque();
    std::cout << "Time to process a range of " << _cVector.size() << " elements with std::vector : " << _timeVector << " us.\n";
    std::cout << "Time to process a range of " << _cDeque.size() << " elements with std::deque : " << _timeDeque << " ms.\n";

}

void    PmergeMe::displayResultVector()
{
    std::cout << "After: ";
    for (std::vector<int>::iterator it=_vectorRes.begin(); it != _vectorRes.end(); ++it)
        std::cout << *it << " ";
    std::cout << "\n";

}

void    PmergeMe::displayResultDeque()
{
    std::cout << "After: ";
    for (std::deque<int>::iterator it=_dequeRes.begin(); it != _dequeRes.end(); ++it)
        std::cout << *it << " ";
    std::cout << "\n";

}

void    PmergeMe::displayPairs()
{
    std::vector< std::pair<int, int> >::iterator it = _splitVector.begin();
    while (it != _splitVector.end())
    {
        std::cout << it->first << " " << it->second << "\n";
        it++;
    }
}


/************************** EXCEPTIONS ****************************************/

const char * PmergeMe::InputException::what() const throw() { return "Error"; }