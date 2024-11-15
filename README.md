# LRU Cache Implementation in C++

This is a C++ implementation of an **LRU (Least Recently Used) Cache**, designed to efficiently manage memory by evicting the least recently used items when the cache reaches its capacity.

## Problem Statement

An LRU cache is a type of data structure used to store a limited number of items. When the cache is full and a new item needs to be added, the least recently accessed item is evicted from the cache. This project implements an LRU Cache using a **Doubly Linked List** and an **unordered map** for efficient data access and eviction.

## Features

- **O(1) Time Complexity**: 
  - The `get` and `put` operations are both optimized to run in constant time, ensuring fast data retrieval and insertion.
  
- **Efficient Cache Eviction**:
  - The cache uses an LRU eviction policy, which removes the least recently accessed item when the cache exceeds its predefined capacity.
  
- **Memory Efficient**:
  - The cache is implemented using **unordered_map** and **doubly linked list**, which provides efficient memory access and management.

- **Custom Capacity**:
  - You can initialize the cache with a custom capacity, and the cache will handle memory management and eviction based on the set size.

## How It Works

1. **Cache Structure**: The cache uses an **unordered map** to store keys and their corresponding values, while a **doubly linked list** is used to track the order of access.
2. **Eviction Policy**: The least recently used item is always at the back of the list. When the cache reaches its capacity, this item is evicted.
3. **Key Operations**:
   - **`feedin(key, value)`**: Inserts or updates the cache with the given key-value pair.
   - **`gettin(key)`**: Retrieves the value for the given key if it exists, otherwise returns "0".

## Example

```cpp
LRUCache cache(2);  // Initialize cache with capacity 2
cache.feedin(1, "beta");
cache.feedin(3, "alpha");
cache.feedin(8, "gamma");

cout << cache.gettin(1) << endl;  // Output: "0" (Key 1 was evicted)
cout << cache.gettin(3) << endl;  // Output: "alpha"
cout << cache.gettin(8) << endl;  // Output: "gamma"
