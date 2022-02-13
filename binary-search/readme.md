# Binary Search
## C++ STL Functions
Note: All of these should be used on sorted data.

- binary_search(first, last, num) : this function returns whether the element occurs in the array or not.
  ```cpp
  array = {1,2,3,5};
  int pos = binary_search(arr, arr + 4, 4);
  // output will be false
  ```
- lower_bound(first, last, num) : this function returns the iterator to the occurence of the element. If the element is not present, it returns the next iterator.
  ```cpp
  array = {1,2,3,5};
  int pos = lower_bound(arr, arr + 4, 4);
  // output will be 3
  ```
- upper_bound(first, last, num) : this function returns the iterator which always points to the next element. if the num is found, then it returns the next one, if not found then also it returns the next one.
  ```cpp
  array = {1,2,3,5};
  int pos = upper_bound(arr, arr + 4, 4);
  // output will be 3
  int pos - upper_bound(arr, arr + 4, 3);
  // output will be 3

- on sets : when using the upper_bound or lower_bound on sets, the syntax is : 
  ```cpp
  auto it = set.lower_bound(num);    
  ```
- Time complexity : O(log n) when the data is sorted.