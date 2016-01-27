/*
 * Colton Holoday
 * choloday@umich.edu
 *
 * Purpose: provide a general implementation for the union find algorithm
 */

#ifndef UNION_FIND_H
#define UNION_FIND_H

#include <vector>

/*
 * For union-find to work each "item" must have a unique identifier
 *
 * In this implementation, the identifier is a number in the 
 * range [0, 1, 2, ... , size - 1]
 */
class Union_find {
    public:

        Union_find(int size);
        Union_find() {}
        int size() const { return items.size(); }

        /*
         * returns the int in [0, 1, 2, ... , size - 1] that identifies
         * the representative of item
         */
        int find_rep(int item);

        /*
         * Combines the groups represented by item1 and item2
         */
        void union_sets(int item1, int item2);

        /*
         * Adds another entry into the disjoint set. Its unique identifier 
         * is the previous size
         */
        void add();

        bool in_same_set(int item1, int item2);

        /*
         * removes all items from the instantiation
         */
        void reset();

    private:
        std::vector<int> items;
};

#endif 
