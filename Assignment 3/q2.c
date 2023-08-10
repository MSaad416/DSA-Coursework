// q2.c - Assignment 03 - Muhammad Saad Iqbal
#include <stdio.h>
#include <stdlib.h>

// defining node structure for linked list
typedef struct node {
    int key;
    int value;
    struct node* next;
    struct node* prev;
} node;

// defining cache structure
typedef struct cache {
    int capacity;
    int size;
    node* head;
    node* tail;
    node** table;
} cache;

// global cache instance
struct cache c;

// function to initialize the cache
void Cache(int capacity) {
    // initializing values
    c.capacity = capacity;
    c.size = 0;
    c.head = NULL;
    c.tail = NULL;
    // allocating hash table memory
    c.table = (node**) malloc(capacity * sizeof(node*));
    for (int i = 0; i < capacity; i++) {
        c.table[i] = NULL;
    }
}

// function to return value of a key, returns -1 if key does not exist
int cache_get(int key) {
    // hash value
    int hash = key % c.capacity;

    node* n = c.table[hash];

    // linked list traversal to find node if key
    while (n != NULL) {
        // if key is found
        if (n->key == key) {
            if (n != c.head) {
                if (n == c.tail)     c.tail = n->prev;
                n->prev->next = n->next;
                if (n->next != NULL) n->next->prev = n->prev;
                n->next = c.head;
                n->prev = NULL;
                c.head->prev = n;
                c.head = n;
            }
            // returning key value
            return n->value;
        }
        n = n->next; // increment pointer
    }

    // return -1, if key not found
    return -1;
}

// adding a key-value pair to cache
// updates value of key if key exists
void cache_put(int key, int value) {
    // hash value
    int hash = key % c.capacity;

    // If the key exists in the cache, update the value
    // and move node to the head of the linked list
    node* n = c.table[hash];
    while (n != NULL) {
        if (n->key == key) {
            n->value = value;
            if (n != c.head) {
                if (n == c.tail)      c.tail = n->prev;
                n->prev->next = n->next;
                if (n->next != NULL)  n->next->prev = n->prev;
                n->next = c.head;
                n->prev = NULL;
                c.head->prev = n;
                c.head = n;
            }
            return;
        }
        n = n->next;
    }

    // If new key in the cache, create a new node
    // and add to cache. If the cache is full, evict the least
    // recently used key before
    node * new_node = (node *) malloc(sizeof(node));
    new_node->key = key;
    new_node->value = value;
    new_node->next = c.head;
    new_node->prev = NULL;

    if (c.head != NULL)     c.head->prev = new_node;
    c.head = new_node;

    if (c.tail == NULL)     c.tail = new_node;

    c.table[hash] = new_node;
    c.size++;

    if (c.size > c.capacity) {
        node * old_tail = c.tail;
        c.tail = old_tail -> prev;
        c.tail -> next = NULL;
        c.table[old_tail -> key % c.capacity] = NULL;
        c.size--;
        free(old_tail);
    }
}

// prints the contents of the cache
void cache_print() {
    node * n = c.head;
    while (n != NULL) {
        printf("key: %d, value: %d\n", n->key, n->value);
        n = n->next;
    }
}


int main() {
    Cache(2);
    cache_put(1, 10); // stores key(1) with value 10
    cache_put(2, 20); // stores key(2) with value 20
    cache_get(1); // returns 10
    cache_put(3, 30); // stores key(3) with value 30
    cache_get(2);
    cache_put(4, 40);
    cache_get(1);
    cache_get(3);
    cache_get(4);
    cache_put(5, 50); // stores key(5) with value 50

    /* DISPLAYS THE CACHE CONTENTS TO CONFIRM CORRECT RESULTS*/
    printf("Cache contents:\n");
    cache_print();

    return 0;
}
