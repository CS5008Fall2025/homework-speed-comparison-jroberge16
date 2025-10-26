/**
 * Singly linked list implementation.
 *
 * @author: Joshua Roberge
 * @class: CS 5008
 * @term: 2025 Fall
 */

#include <stdlib.h>
#include <stdbool.h>
#include <errno.h>


#include "movie.h"
#include "linked_list.h"



node * _ll_get_node(LinkedList *list, int n) {
    node *curr = list->head;
    if (n < 0 || n >= list->size) {
        return NULL;
    }
    for (int i = 0; i < n; i++) {
        curr = curr->next;
    }
    return curr;
}



/** 
 * Creates a new linked list node.
*/
node * __ll__new_node(Movie *movie) {
    node *new_node = (node *) malloc(sizeof(node));
    new_node->movie = movie;
    new_node->next = NULL;
    return new_node;
}

/**
 * Creates a new linked list.
 * 
 * @return a pointer to the new linked list
 */
LinkedList *new_linked_list() {
    LinkedList *list = (LinkedList *) malloc(sizeof(LinkedList));
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return list;
}

/**
 * Frees the memory associated with a linked list.
 * 
 * Frees just the linked list and nodes, the movies
 * stored are not freed. 
 * @param list the linked list to free
 */
void free_linked_list(LinkedList *list) {
    node *curr = list->head;
    node *next;
    while (curr != NULL) {
        next = curr->next;
        free(curr);
        curr = next;
    }
    free(list);
}

/**
 * Frees the memory, including memory allocated
 * to movies stored in the link list. 
 * 
 * @param list the linked list to free
*/
void clear_and_free_linked_list(LinkedList *list) {
    node *curr = list->head;
    node *next;
    while (curr != NULL) {
        next = curr->next;
        free_movie(curr->movie);
        free(curr);
        curr = next;
    }
    free(list);
}

/**
 * Adds a movie to the front of a linked list.
 * 
 * Don't forget to update the tail pointer if the list is empty,
 * as when there is a single node, head and tail should both point
 * towards it.
 * 
 * @param list the linked list to add to
 * @param movie the movie to add
 */
void ll_add_front(LinkedList *list, Movie *movie) {
    if (list == NULL) {
        return; // Index out of bounds
    }

    node *new_node = __ll__new_node(movie);
    if (new_node == NULL) {
        return;
    }

    // new_node -> movie  = movie;

    // if list is empty and no tail node
    if (list->head == NULL){
        list->head = new_node;
        list->tail = new_node; 
    } else{
        new_node-> next  = list->head;
        list->head = new_node;
    }
    // ll_to_str(list);
    
    list->size++;
}

/**
 * Adds a movie to the back of a linked list.
 *
 * Don't forget to update the head pointer if the list is empty,
 * as when there is a single node, head and tail should both point
 * towards it.
 *
 * @param list the linked list to add to
 * @param movie the movie to add
 */
void ll_add_back(LinkedList *list, Movie *movie) {
    
    if (list == NULL) {
        return;
    }
    node *new_node = __ll__new_node(movie);
    if (new_node == NULL) {
        return;
    }

    // new_node -> movie  = movie;

    // if list is empty and no tail node
    if (ll_is_empty(list)){
        list->head = new_node;
        list->tail = new_node; 
    } else {
        list->tail->next = new_node;
        list->tail = new_node;
    }
    list->size++;
}


/**
 * Inserts a movie into a linked list at a given index.
 * 
 * if n == 0, safe to call ll_add_front, if n == list->size, safe to call ll_add_back
 * 
 * if n is out of bounds, do nothing (return early)
 * 
 * @param list the linked list to insert into
 * @param movie the movie to insert
 * @param n the index to insert at
 */
void ll_insert(LinkedList *list, Movie *movie, int n) {
    // base cases
    if (list==NULL|| n<0 || n > list->size){
        return;
    } else if(n==0){
        ll_add_front(list, movie);
        return;
    } else if (n == list->size){
        ll_add_back(list, movie);
        return;
    } 

    // making the new node
    node * new_node = __ll__new_node(movie);
    if (new_node == NULL) {
        return;
    }
    
    // node * previous_node = list -> head;
    node * previous_node = _ll_get_node(list, n-1);
    node * node_2_push = previous_node -> next;
    previous_node -> next = new_node;
    new_node -> next = node_2_push;
    list->size++;
    return;
    
}


/**
 * Removes the first movie from a linked list.
 * 
 * Don't forget if there is only one item in the list, and it is removed,
 * to update the tail pointer.
 * 
 * @param list the linked list to remove from
 * @return the movie that was removed
 */
Movie * ll_remove_front(LinkedList *list) {
    if (list == NULL || list->size == 0){
        errno = ERANGE;
        return NULL;
    }

    node *removed_node = list-> head;
    Movie *removed_movie = removed_node -> movie;
    list->size--;

    if(list-> size <= 0 || removed_node -> next == NULL){
        list->head = NULL;
        list->tail = NULL;
    } else{
        list-> head  = removed_node -> next;
    }
    
    free(removed_node);
    return removed_movie;

}

/**
 * Removes the last movie from a linked list.
 * 
 * Don't forget if there is only one item in the list, and it is removed,
 * to update the head pointer.
 * 
 * @param list the linked list to remove from
 * @return the movie that was removed
 */
Movie * ll_remove_back(LinkedList *list) {
    if (list == NULL || list->size == 0){
        errno = ERANGE;
        return NULL;
    }
    
    node *removed_node = list-> tail;
    Movie *removed_movie = removed_node -> movie;
    list->size--;

    if(list-> size == 0){
        list->head = NULL;
        list->tail = NULL;
    } else{
        node *new_tail = _ll_get_node(list, list->size - 1);
        new_tail->next = NULL;
        list->tail = new_tail;
    }
    
    free(removed_node);
    return removed_movie;
}

/**
 * Removes a movie from a linked list at a given index.
 * 
 * if n == 0, safe to call ll_remove_front, if n == list->size - 1, safe to call ll_remove_back
 * 
 * if n is out of bounds, return NULL
 * 
 * @param list the linked list to remove from
 * @param n the index to remove at
 * @return the movie that was removed
 */
Movie * ll_remove(LinkedList *list, int n) {
    // base cases
    if (list==NULL|| n<0 || n > list->size-1){
        return NULL;
    } else if(n==0){
        Movie *removed_movie = ll_remove_front(list);
        return removed_movie;
    } else if (n == list->size-1){
        Movie *removed_movie = ll_remove_back(list);
        return removed_movie;
    }
    
    node * prev_node = _ll_get_node(list, n-1);
    node *removed_node = prev_node->next;
    Movie *removed_movie = removed_node -> movie;
    prev_node-> next = removed_node -> next;

    list->size--;

    free(removed_node);
    return removed_movie;
}

/**
 * Gets a movie from a linked list at a given index.
 * 
 * if n is out of bounds, return NULL
 * 
 * @param list the linked list to get from
 * @param n the index to get at
 * @return the movie at the given index
 */
Movie* ll_get(LinkedList *list, int n) {
    node *curr = list->head;
    if (n < 0 || n >= list->size) {
        return NULL;
    }
    for (int i = 0; i < n; i++) {
        curr = curr->next;
    }
    return curr->movie;
}




/**
 * Checks if a linked list contains a given movie.
 * 
 * Rare if a linked list contains a movie more than once, but
 * if so, just immediately return true.
 * 
 * @param list the linked list to check
 * @param movie the movie to check for
 * @return true if the linked list contains the movie, false otherwise
 */
bool ll_contains(LinkedList *list, Movie *movie) {
    node *curr = list->head;
    while (curr != NULL) {
        if (curr->movie == movie) {
            return true;
        }
        curr = curr->next;
    }
    return false;
}

/**
 * Checks if a linked list is empty.
 * 
 * @param list the linked list to check
 * @return true if the linked list is empty, false otherwise
 */
bool ll_is_empty(LinkedList *list) {
    return list->size == 0;
}

/**
 * Converts a linked list to a string representation.
 * 
 * 
 * @param list the linked list to convert
 * @return a string representation of the linked list
 */
char* ll_to_str(LinkedList *list) {
    
    // Calculate allocation size, ensuring minimum of 3 bytes for "[]"
    size_t alloc_size = (MAX_MOVIE_STR_LEN + 3) * list->size;
    if (alloc_size < 3) {
        alloc_size = 3;
    }
    char *str = (char *)malloc(sizeof(char) * alloc_size);
    if (list->size == 0) {
        strcpy(str, "[]");
        return str; // early exit
    }
    // implied else
    strcpy(str, "[");
    node *curr = list->head;
    while (curr != list->tail) {
        char *movie_str = movie_to_str(curr->movie);
        strcat(str, movie_str);
        strcat(str, ", ");
        free(movie_str);
        curr = curr->next;
    }
    // now add the tail
    char *movie_str = movie_to_str(curr->movie);
    strcat(str, movie_str);
    free(movie_str);
    strcat(str, "]");

    return str;
}

