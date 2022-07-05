cmake_minimum_required(VERSION 3.16)
project(binary_trie_for_fib)

set(CMAKE_CXX_STANDARD 14)

add_executable(binary_trie_for_fib main.cpp binary_trie.cpp binary_trie.h)
