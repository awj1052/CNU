#ifndef _SORT_H_
#define _SORT_H_

#include <iterator>

template <typename T, typename N>
void Sort(typename T::iterator begin, typename T::iterator end) {
    N comp = N();
    for (typename T::iterator i = begin; i != end; i++) {
        for (typename T::iterator j = std::next(i); j != end; j++) {
            if (comp(*i, *j)) {
                std::iter_swap(i, j);
            }
        }
    }
}

#endif   // _SORT_H_
