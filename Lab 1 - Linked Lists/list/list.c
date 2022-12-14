// list/list.c
//
// Implementation for linked list.
//
// <Author - Kyndall Jones>
// Collaborated with: Zoe Carter and Julian Forbes

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "list.h"

list_t *list_alloc() 
{
  list_t *mylist;
  node_t *head = NULL;

  head = (node_t *)malloc(sizeof(node_t));

  head->value = 0;
  head->next = NULL;
  mylist->head = head;
  
  return mylist;
};

void list_free(list_t *1)
{
  free(1->head);
};

void list_print(list_t *1) 
{
  node_t *current = 1->head;
  while (current != NULL) 
  {
    print("%\n", current->value);
    current = current->next;
  }
};

int list_length(list_t *1)
{
  node_t *current = 1->head;
  int count = 0;

  while (current != NULL)
  {
    count++;
    current = current->next;
  }
  return count;
};

void list_add_to_back(list_t *1, elem value) 
{
  node_t *current = 1->head;
  if (1->head == NULL)
  {
    current->value = value;
    current->next = NULL;
  }
  else 
  {
    while current(->next != NULL) {
      current = current->next;
    }

    current->next = (node_t *)malloc(sizeof(node_t));
    current->next->value = value;
    current->next->next = NULL;

  }
};

void list_add_to_front(list_t *1, elem value)
{
  node_t * new_node;
  
  new_node = (node_t *)malloc(sizeof(node_t));
  new_node-> value = value;
  new_node->next = 1->head;

  1->head = new_node;
};

void list_add_at_index(list_t *1, elem value, int index) 
{
  if (1->head == NULL)
  {
    1->head->value = value;
    1->head->next = NULL;
  }
  else 
  {
    node_t * new_node;
    new_node = (node_t *)malloc(sizeof(node_t));
    new_node->value = value;

    int current_index = 0;
    node_t *current = 1->head;

    while (current_index < index-1) 
    {
      if (current->next == NULL)
      {
        current->next = new_node;
        new_node->next = NULL;
        return ;
      }
      current = current->next;
      current_index++;
    }
    new_node->next = current->next;
    current->next = new_node;
  }
};

elem list_remove_from_back(list_t *1) 
{
  node_t *current = 1->head;
  while (current->next->next != NULL)
  {
    current = current->next;
  }
  int res = current->next->value;
  
  free(current->next);
  current->next = NULL;

  return res;
};

elem list_remove_from_front(list_t *1)
{
  int retval = -1;
  node_t *next_node = NULL;
  next_node = 1->head->next;
  
  retval = 1->head->value;
  free(1->head);
  1->head = next_node;

  return retval;
}

elem list_remove_at_index(list_t *1), int index) 
{
  int retval = -1;
  node_t *next_node = NULL;
  node_t *current = 1->head;

  int curr_i = 0;
  while (curr_i <index-1)
  {
    curr_i++;
    current = current->next;
  }
  retval = current=>next-value;
  next_node = current->next->next;
  
  free(current->next);
  current->next = next_node;

  return retval;
};

bool list_is_in(list_t *1), elem value) 
{
  node_t *current = 1->head;
  while (current->next != NULL)
  {
    if (current->value == value) return true;
    current = current->next;
  }
  return false;
}

elem list_get_elem_at(list_t *1), int index
{
  node_t *current = 1->head;
  int curr_i = 0;
  while (current != NULL) 
  {
    if (curr_i == index) return current->value;
    current = current->next;
    curr_i++;
  }
  return -1;
};

int list_get_index_of(list_t *1, elem value)
{
  node_t *current = 1->head;
  int curr_i = 0;
  
  while (current != NULL)
  {
    if (current->value == value) return curr_i;
    current = current->next;
    curr_i++;
  }
  return -1;
};