#include <iostream>

#include "binary_trie.h"

#define IP_ADDRESS(A, B, C, D) (A * 0x1000000u + B * 0x10000 + C * 0x100 + D)

enum route_type{
    host, network
};

struct fib_data{

    uint32_t next_hop;
};

void test_4bit(){
    binary_trie_node<fib_data>* root = (binary_trie_node<fib_data>*) calloc(1, sizeof(binary_trie_node<fib_data>));

    fib_data* a = (fib_data*) calloc(1, sizeof(fib_data));
    a->next_hop = 0xfc;

    fib_data* b = (fib_data*) calloc(1, sizeof(fib_data));
    b->next_hop = 0xdd;


    add(root, 0b0000, 4, a);
    add(root, 0b1111, 3, b);

    printf("%x\n", search(root, 0b0000)->next_hop);
    printf("%x\n", search(root, 0b1100)->next_hop);
    printf("%x\n", search(root, 0b0100)->next_hop);
    printf("%x\n", search(root, 0b1110)->next_hop);
    printf("%x\n", search(root, 0b1111)->next_hop);
}

int main(){
    std::cout << "Hello, World!" << std::endl;

    binary_trie_node<fib_data>* root = (binary_trie_node<fib_data>*) calloc(1, sizeof(binary_trie_node<fib_data>));

    fib_data* a = (fib_data*) calloc(1, sizeof(fib_data));
    a->next_hop = 0xfc;

    add(root, IP_ADDRESS(192, 168, 1, 0), 24, a);


    if(search(root, IP_ADDRESS(192, 168, 1, 1)) != nullptr){
        printf("%d\n", search(root, IP_ADDRESS(192, 168, 1, 1))->next_hop);
    }
    if(search(root, IP_ADDRESS(192, 168, 2, 1)) != nullptr){
        printf("%d\n", search(root, IP_ADDRESS(192, 168, 1, 1))->next_hop);
    }
    if(search(root, IP_ADDRESS(192, 168, 1, 25)) != nullptr){
        printf("%d\n", search(root, IP_ADDRESS(192, 168, 1, 1))->next_hop);
    }
    if(search(root, IP_ADDRESS(1, 168, 1, 1)) != nullptr){
        printf("%d\n", search(root, IP_ADDRESS(192, 168, 1, 1))->next_hop);
    }


    return 0;
}
