#include "PmergeMe.hpp"
#include <sstream>
#include <limits>
// #include <time.h>

/*********************** CONSTRUCTOR & DESTRUCTOR *****************************/
Sort::Sort() {}

Sort::Sort(char** av, int ac)
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
    doSort(this->_cList, this->_timeList);
    doSort(this->_cVector, this->_timeVector);
    displayResult();
    return;
}

Sort::Sort( Sort const & src)
{
      *this = src;
      return;
}

Sort & Sort::operator=(Sort const & o)
{
    this->_buf = o._buf;
    this->_toSort = o._toSort;
    this->_cVector = o._cVector;
    this->_cList = o._cList;
    this->_timeVector = o._timeVector;
    this->_timeList = o._timeList;
    return  *this;
}

Sort::~Sort( void ) {}

/************************** PUBLIC MEMBER FUNCTION ****************************/

void    Sort::fillContainers()
{
    std::copy(_toSort.begin(), _toSort.end(), std::back_inserter(_cList));
    std::copy(_toSort.begin(), _toSort.end(), std::back_inserter(_cVector));
}

void    Sort::findDuplicates()
{
    std::vector<int> tmp (_toSort);
    std::sort(tmp.begin(), tmp.end());
    for (size_t i=0; i<tmp.size() -1; i++)
        if (tmp[i] == tmp[i+1])
            throw (InputException());
}

void    Sort::parseInput(char** av, int ac)
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

void    Sort::displayUnsortedSequence() 
{
    std::cout << "Before: ";
    for (size_t i=0; i<_toSort.size();++i)
        std::cout << _toSort[i] << " ";
    std::cout << "\n";
}

void    Sort::displayResult()
{
    std::cout << "After: ";
    for (std::list<int>::iterator it=_cList.begin(); it != _cList.end(); ++it)
        std::cout << *it << " ";
    std::cout << "\n";
    std::cout << "Time to process a range of " << _toSort.size() << " elements with std::vector : " << _timeVector << " ms.\n";
    std::cout << "Time to process a range of " << _toSort.size() << " elements with std::list : " << _timeList << " ms.\n";

}

void    Sort::displayResultVector()
{
    std::cout << "After: ";
    for (std::vector<int>::iterator it=_cVector.begin(); it != _cVector.end(); ++it)
        std::cout << *it << " ";
    std::cout << "\n";

}


/************************** NON MEMBER FUNCTION *******************************/
/************************** EXCEPTIONS ****************************************/

const char * Sort::InputException::what() const throw() { return "Error"; }

/*----------------------------------- NOTES --------------------------------------
>>> std::prev/next : not sure if c++98 
void Sort::insertList(std::list<int>& a)
{
    int key;
    std::list<int>::iterator jt;
    for (std::list<int>::iterator it = a.begin(); it != a.end(); ++it) {
        key = *it;
        jt = std::prev(it);
        while(jt != std::prev(a.begin()) && key < *jt)
        {
            *(std::next(jt)) = *jt;
            jt = std::prev(jt);
        }
        *(std::next(jt)) = key;
    }
}

void Sort::insertList(std::list<int>& a)
{
    int key;
    std::list<int>::iterator jt;
    std::list<int>::iterator stop = a.begin();
    std::advance(stop, -1);

    for (std::list<int>::iterator it = a.begin(); it != a.end(); ++it) {
        key = *it;
        jt = it;
        std::advance(jt, -1);
        while(jt != stop && key < *jt)
        {
            int tmp = *jt;
            std::list<int>::iterator tmpit = jt;
            std::advance(jt, +1);
            *jt= tmp;
            std::advance(tmpit, -1);
            jt = tmpit;
        }
        std::list<int>::iterator tmpit = jt;
        std::advance(tmpit, +1);
        *tmpit = key;
    }
}
void Sort::mergeVector(std::vector<int>& a, std::vector<int>& b, std::vector<int>& res) {
    while (!a.empty() && !b.empty()) {
        if (a.front() < b.front()) {
            res.push_back(a.front());
            pop_front(a);
        } else {
            res.push_back(b.front());
            pop_front(b);
        }
    }
    while (!a.empty()) {
        res.push_back(a.front());
        pop_front(a);
    }
    while (!b.empty()) {
        res.push_back(b.front());
        pop_front(b);
    }
}

*/
