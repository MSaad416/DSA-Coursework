//
// Created by Saad Iqbal on 2022-12-08.
//

#include<stdio.h>
#include<stdlib.h>

typedef struct {
    int key;
    int value;
    struct cache * next;
}cache;


cache cache_head;

void cache_init(int capacity)
{
//    struct cache * new_node = (cache)malloc(sizeof(cache));
    struct cache * new_node = malloc(sizeof(cache));
    new_node->key = capacity;
    new_node->value = 0;
    new_node->next = NULL;
    cache_head = new_node;
}

int get(int key)
{
    cache temp = cache_head;
    while(temp != NULL)
    {
        if(temp->key == key)
        {
            return temp->value;
        }
        temp = temp->next;
    }
    return -1;
}

void put(int key, int value)
{
    cache temp = cache_head;
    while(temp != NULL)
    {
        if(temp->key == key)
        {
            temp->value = value;
            return;
        }
        temp = temp->next;
    }
    cache * new_node = (cache)malloc(sizeof(cach));
    new_node->key = key;
    new_node->value = value;
    new_node->next = NULL;
    if(cache_head->value == cache_head->key)
    {
        temp = cache_head;
        cache_head = cache_head->next;
        free(temp);
    }
    cache_head->value++;
    new_node->next = cache_head;
    cache_head = new_node;
}


int main()
{
    cache_init(2);
    put(1, 10);
    put(2, 20);
    printf("%d\n", get(1));
    put(3, 30);
    printf("%d\n", get(2));
    put(4, 40);
    printf("%d\n", get(1));
    printf("%d\n", get(3));
    printf("%d\n", get(4));
    put(5, 50);
}