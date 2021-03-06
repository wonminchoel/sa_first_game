#include "header/header.h"

void add_list(itemlist **head, itemlist **tail, itemlist data)
{
    if ((*head) == NULL)
    {
        *head = (itemlist *)malloc(sizeof(itemlist));
        *tail = (itemlist *)malloc(sizeof(itemlist));
        (*head)->next = *tail;
    }
    else
    {
        (*tail)->next = (itemlist *)malloc(sizeof(itemlist));
        *tail = (*tail)->next;
    }

    (*tail)->amount = data.amount;
    (*tail)->item_id = data.item_id;
    (*tail)->next = NULL;
}
//pos는 1이상이여야 한다.
void delete_list(itemlist **head, itemlist **tail, unsigned int pos)
{
    itemlist *target;
    itemlist *head_res = *head;

    while (pos - 1)
    {
        head_res = (head_res)->next;
        pos--;
    }
    if (((head_res)->next)->next == NULL)
    {
        target = (head_res)->next;
        (head_res)->next = NULL;
        *tail = head_res;
        printf("error_NULL");
    }
    else
    {
        printf("error_add");
        target = (head_res)->next;
        (head_res)->next = ((head_res)->next)->next;
    }
    free(target);
}
//pos는 1이상이여야 한다.
void between_add_list(itemlist **head, itemlist data, unsigned int pos)
{
    itemlist *res;
    itemlist *head_res = *head;
    while (pos - 1 && ((head_res)->next != NULL))
    {
        head_res = (head_res)->next;
        pos--;
    }
    res = (itemlist *)malloc(sizeof(itemlist));

    (res)->amount = data.amount;
    (res)->item_id = data.item_id;

    (res)->next = (head_res)->next;
    (head_res)->next = res;
}
void all_list_delete(itemlist **head, itemlist **tail)
{
    itemlist *target;
    itemlist *res = *head;
    while (1)
    {
        if (*head == NULL)
        {
            break;
        }
        else if ((res)->next != *tail)
        {
            target = (res)->next;
            (res)->next = ((res)->next)->next;
            free(target);
        }
        else
        {
            free(*head);
            free(*tail);
            *head = (itemlist *)malloc(sizeof(itemlist));
            *tail = (itemlist *)malloc(sizeof(itemlist));
            *head = NULL;
            *tail = NULL;

            break;
        }
    }
}

void all_print(itemlist **head, itemlist **tail)
{
    int count = 1;
    itemlist *temp;
    if (*head == NULL)
    {
        printf("리스트에 아무것도 존재하지 않습니다.\n");
        return;
    }
    temp = (*head)->next;
    while ((temp != NULL))
    {
        printf("%3d번     id : %4d\n", count, temp->item_id);
        printf("%3d번 amount : %4d\n", count, temp->amount);
        if (temp->next == NULL)
        {
            break;
        }
        count++;
        temp = temp->next;
    }
}