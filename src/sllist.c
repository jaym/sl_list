#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<sys/types.h>
#include "sllist.h"


int sl_list_push(sl_list** listptr, void* data, size_t size)
{
    sl_packet* packet;
    sl_list*   list;
    sl_node*   node;
    void*      d;

    if(listptr == NULL)
        return SL_ERROR;

    list = *listptr;

    if(!list){
        list = malloc(sizeof(sl_list));
        if(!list)
            return SL_NO_MEM;
        list->head = NULL;
        list->tail = NULL;
        list->count = 0;
        *listptr = list;
    }

    packet = malloc(sizeof(sl_packet));
    node   = malloc(sizeof(sl_node));
    d      = malloc(sizeof(size));

    if(!packet || !node || !d)
        return SL_NO_MEM;

    memcpy(d, data, size);
    
    packet->data = d;
    packet->size = size;
    node->packet = packet;
    node->next   = list->head;
    list->head   = node;
    list->tail   = list->tail == NULL ? list->head : list->tail;
    list->count++;

    return SL_SUCCESS;
}

int sl_list_enqueue(sl_list** listptr, void* data, size_t size)
{
    sl_packet* packet;
    sl_list*   list;
    sl_node*   node;
    void*      d;

    if(listptr == NULL)
        return SL_ERROR;

    packet = malloc(sizeof(sl_packet));
    node   = malloc(sizeof(sl_node));
    d      = malloc(sizeof(size));

    if(!packet || !node || !d)
        return SL_NO_MEM;

    memcpy(d, data, size);

    list = *listptr;

    packet->data = d;
    packet->size = size;
    node->packet = packet;
    node->next = NULL;

    if(!list){
        list = malloc(sizeof(sl_list));
        if(!list)
            return SL_NO_MEM;
        list->head = node;
        list->tail = node;
        list->count = 1;
        *listptr = list;
    }else{
        list->tail->next = node;
        list->tail = node;
        list->count++;
    }

    return SL_SUCCESS;
}

int main() {
    int A = 0xFFFFFFFF;
    int B = 0xAAAAAAAA;
    int C = 0x11111111;

    sl_list* list = NULL;
    
    sl_list_push(&list, &A, sizeof(int));
    sl_list_push(&list, &B, sizeof(int));
    sl_list_push(&list, &C, sizeof(int));
}
