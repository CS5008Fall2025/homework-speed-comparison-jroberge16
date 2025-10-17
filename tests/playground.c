#include <stdio.h>

#include "../lib/movie.h"
#include "../lib/linked_list.h"

#include "testing_util.h"
#include "movie_globals.h"


#define GROUP_GENERAL  "GENERAL"
#define GROUP_ADD      "ADD"
#define GROUP_REMOVE   "REMOVE"
#define GROUP_GET      "GET"
#define GROUP_SORTED   "SORTED"



Movie* movie1;
Movie* movie2;
Movie* movie3;
Movie* movie4;
Movie* movie5;
Movie* movie6;




int main(const int argc, const char *argv[]) {
    movie1 = new_movie("A Movie One", 1);
    movie2 = new_movie("B Movie Two", 2);
    movie3 = new_movie("C Movie Three", 3);
    movie4 = new_movie("D Movie Four", 4);
    movie5 = new_movie("E Movie Five", 5);
    movie6 = new_movie("F Movie Six", 6);

    LinkedList *list = new_linked_list();
    ll_add_front(list, movie1);
    ll_add_front(list, movie2);
    ll_add_front(list, movie3);
    ll_add_front(list, movie4);
    ll_add_front(list, movie5);

    printf("List size: %d\n", list->size);
    char *str = ll_to_str(list);
    printf("List contents: %s\n", str);

    ll_insert(list, movie1, 2);
    
    printf("List size: %d\n", list->size);
    char *str2 = ll_to_str(list);
    printf("List contents: %s\n", str2);

    return 0;
}

