/*
 * Colton Holoday
 * choloday@umich.edu
 *
 * Purpose: provide a general implementation for the union find algorithm
 */
#include "union_find.h"

#include <iostream>
#include <vector>
#include <numeric>
#include <exception>

Union_find::Union_find(int size) {
    if (size < 0) {
        throw std::invalid_argument("Union_find::size");
    }

    items.resize(size);
    std::iota(items.begin(), items.end(), 0);
}

/*
 * Each item holds an identifier to another item and therefore "points"
 * to another item. Each representative of a group points to itself.
 * If an item isn't a representative then it points to an item that 
 * leads to the representative
 *
 * This function compresses the chain from an item to it's representative
 * as it finds the representative.
 */
int Union_find::find_rep(int item) {
    if (items[item] != item) {
        items[item] = find_rep(items[item]);
    }

    return items[item];
}

void Union_find::union_sets(int item1, int item2) {
    if (item1 < 0 || item1 >= (int)items.size() ||
        item2 < 0 || item2 >= (int)items.size() ) {

        throw std::invalid_argument("Union_find::union_sets");
    }

    if (find_rep(item1) == find_rep(item2)) {
        return;
    }

    // arbritrary convention of combining groups
    if (items[item1] < items[item2]) {
        //item1 and item2 in the vector must "point" directly to their 
        //representative because of path compression
        items[items[item2]] = items[item1];
    }
    else {
        items[items[item1]] = items[item2];
    }
}

void Union_find::add() {
    items.push_back(items.size());
}

bool Union_find::in_same_set(int item1, int item2) {
    if (item1 < 0 || item1 >= (int)items.size() ||
        item2 < 0 || item2 >= (int)items.size() ) {

        throw std::invalid_argument("Union_find::union_sets");
    }

    return find_rep(item1) == find_rep(item2);
}

void Union_find::reset() {
    items.resize(0);
}

