cmake_minimum_required(VERSION 3.29)
project(Kolos1)

set(CMAKE_CXX_STANDARD 20)

add_executable(Kolos1 main.cpp
        priority_queues/list.h
        priority_queues/list.cpp
        priority_queues/tree.cpp
        priority_queues/tree.h
        priority_queues/heap.cpp
        priority_queues/heap.h
        priority_queues/beap.cpp
        priority_queues/beap.h
        priority_queues/leftist_skew_heap.cpp
        priority_queues/leftist_skew_heap.h
        priority_queues/binomial_tree.cpp
        priority_queues/binomial_tree.h
        priority_queues/binomial_queue.cpp
        priority_queues/binomial_queue.h
        dictionaries/bst.cpp
        dictionaries/bst.h
        dictionaries/avl.cpp
        dictionaries/avl.h
        dictionaries/b_tree.cpp
        dictionaries/b_tree.h
        dictionaries/splay_tree.cpp
        dictionaries/splay_tree.h
        sorting/sort.cpp
        sorting/sort.h
        dictionaries/array.cpp
        dictionaries/array.h
        dictionaries/BB_tree.cpp
        dictionaries/BB_tree.h
        dictionaries/rst.cpp
        dictionaries/rst.h
        dictionaries/hash.cpp
        dictionaries/hash.h
        dictionaries/sbb_tree.cpp
        dictionaries/sbb_tree.h
)
