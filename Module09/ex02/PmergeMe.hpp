#ifndef PMERGEME_HPP
 #define PMERGEME_HPP

#include <iostream>
#include <list>
#include <vector>
#include <ctime>

#define THRESHOLD 10

class   Sort 
{
    public:
        Sort(char**av, int ac);
        Sort(Sort const &);
        Sort& operator=(Sort const &);
        ~Sort();

        void    parseInput(char **, int);
        void    findDuplicates();
        void    displayUnsortedSequence();
        void    fillContainers();
        // void    doSort();
        void    displayResult();
        void    displayResultVector();

        template <typename Container>
        void    doSort(Container& container, double& time)
        {
            clock_t start = clock();
            sortSequence(container);
            clock_t end = clock();
            time = (double) (end-start) / CLOCKS_PER_SEC * 1000.0;
        }

        template <typename Container>
        void insertion( Container& a)
        {
            typename Container::iterator iterator;
            typename Container::iterator jt;
            typename Container::iterator tmpit;
            typename Container::iterator stop = a.begin();
            typename Container::iterator it = a.begin();
            std::advance(stop, -1);
            for (; it != a.end(); ++it)
            {
                int key = *it;
                jt = it;
                std::advance(jt, -1);
                while(jt != stop && key < *jt)
                {
                    int tmp = *jt;
                    tmpit = jt;
                    std::advance(jt, +1);
                    *jt= tmp;
                    std::advance(tmpit, -1);
                    jt = tmpit;
                }
            tmpit = jt;
            std::advance(tmpit, +1);
            *tmpit = key;
            }
        }

        template <typename V>
        void pop_front(V & v)
        {
            assert(!v.empty());
            v.erase(v.begin());
        }

        template <typename Container>
        void merge(Container& a, Container& b, Container& res) {
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

        template <typename Container>
        void    sortSequence(Container& data)
        {
            if (data.size() <= 1) { return; }
            if (data.size() <= THRESHOLD)
            {
                insertion(data);
                return;
            }
            Container a;
            Container b;

            int half = data.size() * 0.5;
            for (int i = 0; i < half; ++i) {
                a.push_back(data.front());
                pop_front(data);
            }
            while(!data.empty())
            {
                b.push_back(data.front());
                pop_front(data);
            }
            
            sortSequence(a);
            sortSequence(b);

            merge(a, b, data);
    

        }

        class InputException : public std::exception {
            public:
                virtual const char* what() const throw();
        };


    private:
        std::string         _buf;
        std::vector<int>    _toSort;
        std::vector<int>    _cVector;     
        std::list<int>      _cList;
        double              _timeVector;
        double              _timeList;
        Sort();
};

#endif
/*----------------------------------- NOTES --------------------------------------

        template <typename Container>
        void insert( Container& a)
        {
            typename Container::iterator jt;
            typename Container::iterator tmpit;

            typename Container::iterator stop = a.begin();
            typename Container::iterator it = a.begin();
            std::advance(stop, -1);
            for (; it != a.end(); ++it)
            {
                int key = *it;
                jt = it;
                std::advance(jt, -1);
                while(jt != stop && key < *jt)
                {
                    int tmp = *jt;
                    tmpit = jt;
                    std::advance(jt, +1);
                    *jt= tmp;
                    std::advance(tmpit, -1);
                    jt = tmpit;
                }
            tmpit = jt;
            std::advance(tmpit, +1);
            *tmpit = key;
        }
        }
*/