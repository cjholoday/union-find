#include "Union_find.h"
#include <cassert>

int main() {
    Union_find t1(10);

    // basic
    ////////////////////////////////////////////////// 

    t1.union_sets(0, 2);
    assert(t1.find_rep(2) == 0);
    assert(t1.size() == 10);

    // create chain: 3-5-6-7
    ////////////////////////////////////////////////// 

    t1.union_sets(5, 3);
    t1.union_sets(6, 5);
    t1.union_sets(7, 6);

    assert(t1.find_rep(7) == 3);
    
    // check that updating end of chain (7) updates all values
    ////////////////////////////////////////////////// 

    //connect two big groups so that rep is 0 
    t1.union_sets(7, 2);

    assert(t1.find_rep(7) == 0);
    assert(t1.find_rep(3) == 0);
    assert(t1.find_rep(6) == 0);
    assert(t1.find_rep(5) == 0);

    
    // test add function
    ////////////////////////////////////////////////// 

    t1.add();
    assert(t1.size() == 11);
    assert(t1.find_rep(10) == 10);

    Union_find t2;
    assert(t2.size() == 0);

    t2.add();
    assert(t2.size() == 1);
    assert(t2.find_rep(0) == 0);

    // test in_same_set function
    ////////////////////////////////////////////////// 

    Union_find t3(5);
    assert(!t3.in_same_set(0, 1));
    assert(!t3.in_same_set(2, 4));

    t3.union_sets(0, 1);
    assert(t3.in_same_set(0, 1));

    // create chain 0-1-3-4
    t3.union_sets(1, 3);
    t3.union_sets(3, 4);
    assert(t3.in_same_set(0, 4));
    assert(!t3.in_same_set(2, 0));

    // tests reset function
    ////////////////////////////////////////////////// 

    t3.reset();
    assert(t3.size() == 0);
    
    t3.reset();
    assert(t3.size() == 0);
}
