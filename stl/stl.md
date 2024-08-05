# C++ STL
# Index
- [C++ STL](#c-stl)
- [Index](#index)
  - [Basics of C++ STL](#basics-of-c-stl)
    - [What is STL?](#what-is-stl)
    - [Why Use STL?](#why-use-stl)
    - [Basic Containers and Their Functions](#basic-containers-and-their-functions)
      - [1. `vector`](#1-vector)
      - [2. `set`](#2-set)
      - [3. `unordered_set`](#3-unordered_set)
      - [4. `map`](#4-map)
    - [Algorithms](#algorithms)
      - [1. `sort()`](#1-sort)
      - [2. `min_element()` and `max_element()`](#2-min_element-and-max_element)
      - [3. `next_permutation()`](#3-next_permutation)
      - [4. `__builtin_popcount()`](#4-__builtin_popcount)
    - [Advanced Concepts](#advanced-concepts)
    - [Advanced Concepts in C++ STL](#advanced-concepts-in-c-stl)
      - [1. Custom Comparators for `set`, `map`, and `sort`](#1-custom-comparators-for-set-map-and-sort)
        - [Custom Comparator for `set` and `map`](#custom-comparator-for-set-and-map)
        - [Custom Comparator for `sort`](#custom-comparator-for-sort)
      - [2. Usage of `priority_queue` for Efficient Priority-Based Data Management](#2-usage-of-priority_queue-for-efficient-priority-based-data-management)
      - [3. Efficient Use of `deque` and `list` for Specific Use Cases](#3-efficient-use-of-deque-and-list-for-specific-use-cases)
        - [`deque`](#deque)
        - [`list`](#list)
      - [4. Understanding and Using `unordered_map`, `unordered_multiset`, and `unordered_multimap` for Average-Case Constant Time Complexity](#4-understanding-and-using-unordered_map-unordered_multiset-and-unordered_multimap-for-average-case-constant-time-complexity)
        - [`unordered_map`](#unordered_map)
        - [`unordered_multiset`](#unordered_multiset)
        - [`unordered_multimap`](#unordered_multimap)



## Basics of C++ STL

### What is STL?
The Standard Template Library (STL) is a powerful feature of C++ that provides a set of common classes and interfaces for data structures and algorithms. It helps you avoid writing repetitive code and focuses on solving the problem at hand. The STL includes:

1. **Containers:** Collections of objects or data (e.g., `vector`, `set`, `map`).
2. **Algorithms:** Procedures to process data in containers (e.g., `sort`, `min_element`, `max_element`).
3. **Iterators:** Objects that enable traversal through the elements of a container.

### Why Use STL?
- **Efficiency:** Provides optimized implementations for common data structures and algorithms.
- **Reusability:** Templates allow for reusing code with different data types.
- **Productivity:** Reduces the amount of code you need to write.

### Basic Containers and Their Functions

#### 1. `vector`
A dynamic array that can resize itself automatically when an element is added or removed.

**Common Operations:**
- `push_back(value)`: Adds an element at the end.
- `pop_back()`: Removes the last element.
- `size()`: Returns the number of elements.
- `at(index)`: Accesses the element at the specified position.
- `begin()`: Returns an iterator to the first element.
- `end()`: Returns an iterator to the element following the last element.

**Example:**
```cpp
#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);

    for(int i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << " ";
    }

    return 0;
}
```

#### 2. `set`
A collection of unique elements, stored in a sorted order.

**Common Operations:**
- `insert(value)`: Adds an element.
- `erase(value)`: Removes an element.
- `find(value)`: Searches for an element.
- `size()`: Returns the number of elements.
- `begin()`: Returns an iterator to the first element.
- `end()`: Returns an iterator to the element following the last element.

**Example:**
```cpp
#include <iostream>
#include <set>

int main() {
    std::set<int> mySet;
    mySet.insert(3);
    mySet.insert(1);
    mySet.insert(2);

    for(auto it = mySet.begin(); it != mySet.end(); ++it) {
        std::cout << *it << " ";
    }

    return 0;
}
```

#### 3. `unordered_set`
Similar to `set`, but does not keep the elements in any particular order. It offers average-case constant time complexity for most operations.

**Example:**
```cpp
#include <iostream>
#include <unordered_set>

int main() {
    std::unordered_set<int> mySet;
    mySet.insert(3);
    mySet.insert(1);
    mySet.insert(2);

    for(auto it = mySet.begin(); it != mySet.end(); ++it) {
        std::cout << *it << " ";
    }

    return 0;
}
```

#### 4. `map`
A collection of key-value pairs, where each key is unique, and the keys are stored in sorted order.

**Common Operations:**
- `insert({key, value})`: Adds a key-value pair.
- `erase(key)`: Removes a key-value pair.
- `find(key)`: Searches for a key.
- `size()`: Returns the number of key-value pairs.
- `begin()`: Returns an iterator to the first key-value pair.
- `end()`: Returns an iterator to the pair following the last key-value pair.

**Example:**
```cpp
#include <iostream>
#include <map>

int main() {
    std::map<int, std::string> myMap;
    myMap[1] = "one";
    myMap[2] = "two";
    myMap[3] = "three";

    for(auto it = myMap.begin(); it != myMap.end(); ++it) {
        std::cout << it->first << ": " << it->second << " ";
    }

    return 0;
}
```

### Algorithms

#### 1. `sort()`
Sorts the elements in a range.

**Example:**
```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> vec = {3, 1, 4, 1, 5};
    std::sort(vec.begin(), vec.end());

    for(int n : vec) {
        std::cout << n << " ";
    }

    return 0;
}
```

#### 2. `min_element()` and `max_element()`
Returns an iterator to the minimum/maximum element in a range.

**Example:**
```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> vec = {3, 1, 4, 1, 5};
    auto minIt = std::min_element(vec.begin(), vec.end());
    auto maxIt = std::max_element(vec.begin(), vec.end());

    std::cout << "Min: " << *minIt << "\n";
    std::cout << "Max: " << *maxIt << "\n";

    return 0;
}
```

#### 3. `next_permutation()`
Transforms the range into the next permutation of elements in lexicographical order.

**Example:**
```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> vec = {1, 2, 3};
    do {
        for(int n : vec) {
            std::cout << n << " ";
        }
        std::cout << "\n";
    } while(std::next_permutation(vec.begin(), vec.end()));

    return 0;
}
```

#### 4. `__builtin_popcount()`
Counts the number of set bits (1s) in an integer. Note that this is a GCC-specific function.

**Example:**
```cpp
#include <iostream>

int main() {
    int n = 5; // 101 in binary
    std::cout << "__builtin_popcount(5): " << __builtin_popcount(n) << "\n";

    return 0;
}
```

### Advanced Concepts

Once you are comfortable with the basics, you can dive into more advanced topics such as:
- Custom comparators for `set`, `map`, and `sort`.
- Usage of `priority_queue` for efficient priority-based data management.
- Efficient use of `deque` and `list` for specific use cases.
- Understanding and using `unordered_map`, `unordered_multiset`, and `unordered_multimap` for average-case constant time complexity.

Feel free to ask about any specific container or algorithm, and I can provide more detailed explanations and examples!

### Advanced Concepts in C++ STL

Let's dive into the advanced topics you've mentioned:

#### 1. Custom Comparators for `set`, `map`, and `sort`

##### Custom Comparator for `set` and `map`

By default, `set` and `map` use the `<` operator to compare elements and maintain order. You can provide a custom comparator if you need a different ordering.

**Example: Custom Comparator for `set`**
```cpp
#include <iostream>
#include <set>

// Custom comparator
struct CustomCompare {
    bool operator()(const int& lhs, const int& rhs) const {
        return lhs > rhs; // Reverse order
    }
};

int main() {
    std::set<int, CustomCompare> mySet = {1, 2, 3, 4, 5};

    for (const int& elem : mySet) {
        std::cout << elem << " "; // Output: 5 4 3 2 1
    }

    return 0;
}
```

**Example: Custom Comparator for `map`**
```cpp
#include <iostream>
#include <map>

// Custom comparator
struct CustomCompare {
    bool operator()(const int& lhs, const int& rhs) const {
        return lhs > rhs; // Reverse order
    }
};

int main() {
    std::map<int, std::string, CustomCompare> myMap;
    myMap[1] = "one";
    myMap[2] = "two";
    myMap[3] = "three";

    for (const auto& pair : myMap) {
        std::cout << pair.first << ": " << pair.second << " "; // Output: 3: three 2: two 1: one
    }

    return 0;
}
```

##### Custom Comparator for `sort`

You can provide a custom comparator function or lambda to the `sort` algorithm.

**Example: Custom Comparator for `sort`**
```cpp
#include <iostream>
#include <vector>
#include <algorithm>

// Custom comparator function
bool customCompare(int a, int b) {
    return a > b; // Reverse order
}

int main() {
    std::vector<int> vec = {3, 1, 4, 1, 5};
    std::sort(vec.begin(), vec.end(), customCompare);

    for (int n : vec) {
        std::cout << n << " "; // Output: 5 4 3 1 1
    }

    return 0;
}
```

#### 2. Usage of `priority_queue` for Efficient Priority-Based Data Management

A `priority_queue` is a container adaptor that provides constant time complexity for insertion and extraction of the maximum element. By default, it is a max-heap, but you can customize it to be a min-heap.

**Example: Max-Heap and Min-Heap**
```cpp
#include <iostream>
#include <queue>
#include <vector>

int main() {
    // Max-Heap
    std::priority_queue<int> maxHeap;
    maxHeap.push(3);
    maxHeap.push(1);
    maxHeap.push(4);
    maxHeap.push(1);
    maxHeap.push(5);

    std::cout << "Max-Heap: ";
    while (!maxHeap.empty()) {
        std::cout << maxHeap.top() << " "; // Output: 5 4 3 1 1
        maxHeap.pop();
    }
    std::cout << "\n";

    // Min-Heap
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
    minHeap.push(3);
    minHeap.push(1);
    minHeap.push(4);
    minHeap.push(1);
    minHeap.push(5);

    std::cout << "Min-Heap: ";
    while (!minHeap.empty()) {
        std::cout << minHeap.top() << " "; // Output: 1 1 3 4 5
        minHeap.pop();
    }

    return 0;
}
```

#### 3. Efficient Use of `deque` and `list` for Specific Use Cases

##### `deque`
A `deque` (double-ended queue) allows fast insertion and deletion at both ends.

**Example:**
```cpp
#include <iostream>
#include <deque>

int main() {
    std::deque<int> dq;
    dq.push_back(1);
    dq.push_front(2);
    dq.push_back(3);
    dq.push_front(4);

    for (const int& elem : dq) {
        std::cout << elem << " "; // Output: 4 2 1 3
    }

    return 0;
}
```

##### `list`
A `list` (doubly linked list) allows fast insertion and deletion at any position.

**Example:**
```cpp
#include <iostream>
#include <list>

int main() {
    std::list<int> lst;
    lst.push_back(1);
    lst.push_back(2);
    lst.push_back(3);

    auto it = lst.begin();
    ++it; // Points to the second element
    lst.insert(it, 4); // Inserts 4 before the second element

    for (const int& elem : lst) {
        std::cout << elem << " "; // Output: 1 4 2 3
    }

    return 0;
}
```

#### 4. Understanding and Using `unordered_map`, `unordered_multiset`, and `unordered_multimap` for Average-Case Constant Time Complexity

##### `unordered_map`
An `unordered_map` is a hash table-based implementation of a map, offering average-case constant time complexity for insertions, deletions, and lookups.

**Example:**
```cpp
#include <iostream>
#include <unordered_map>

int main() {
    std::unordered_map<int, std::string> umap;
    umap[1] = "one";
    umap[2] = "two";
    umap[3] = "three";

    for (const auto& pair : umap) {
        std::cout << pair.first << ": " << pair.second << " ";
    }

    return 0;
}
```

##### `unordered_multiset`
An `unordered_multiset` is similar to `unordered_set`, but it allows duplicate elements.

**Example:**
```cpp
#include <iostream>
#include <unordered_set>

int main() {
    std::unordered_multiset<int> umset;
    umset.insert(1);
    umset.insert(2);
    umset.insert(2);
    umset.insert(3);

    for (const int& elem : umset) {
        std::cout << elem << " "; // Output order may vary
    }

    return 0;
}
```

##### `unordered_multimap`
An `unordered_multimap` is similar to `unordered_map`, but it allows duplicate keys.

**Example:**
```cpp
#include <iostream>
#include <unordered_map>

int main() {
    std::unordered_multimap<int, std::string> ummap;
    ummap.insert({1, "one"});
    ummap.insert({2, "two"});
    ummap.insert({2, "dos"});
    ummap.insert({3, "three"});

    for (const auto& pair : ummap) {
        std::cout << pair.first << ": " << pair.second << " ";
    }

    return 0;
}
```

These advanced concepts should give you a deeper understanding of how to use STL containers and algorithms efficiently for various programming tasks. If you have any specific questions or need further examples, feel free to ask!