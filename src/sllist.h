#include<stdlib.h>

#define SL_ERROR -1
#define SL_SUCCESS 0
#define SL_NO_MEM -2

typedef struct sl_list
{
    struct sl_node* head;
    struct sl_node* tail;
    size_t count;
}sl_list;

typedef struct sl_node
{
    struct sl_node* next;
    struct sl_packet* packet;
}sl_node;

typedef struct sl_packet
{
    void* data;
    size_t size;
}sl_packet;

int sl_list_push(sl_list** listptr, void* data, size_t size);
int sl_list_enqueue(sl_list** listptr, void* data, size_t size);
int sl_list_get(sl_list** listptr, size_t index, size_t* size);
//int sl_list_ordered(sl_list** listptr, void* data, size_t size);
//int sl_list_remove(sl_list** listptr, void* data)
//void sl_list_foreach(sl_list** listptr, void (*func)(void* data, size_t size));
