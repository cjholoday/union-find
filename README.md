# Union Find

## What is union find?

Union find is an algorithm based on disjoint sets. Given a set of items, 
we want to group them together into disjoint sets. To do this, one item in 
each group is designated the representative. Each non representative in a 
group stores an item that leads to the representative, whether directly or 
indirectly through another non-representative.

## Implementation

In this implementation, each item is represented by an integer in 
the range [0, 1, ... , size - 1]. The union find data structure begins
with each item placed in its own disjoint set. 
