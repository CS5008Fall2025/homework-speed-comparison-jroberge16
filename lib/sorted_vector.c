/**
 * Contains functions for the sorted vector struct
 *
 * @author: Joshua Roberge
 * @class: CS 5008
 * @term: Fall 2025
**/

#include "vector.h"
#include "movie.h"





/**
 * 
 * This is a private function to find the index of a movie
 * in the sorted vector using binary search.
 * 
 * @source https://www.geeksforgeeks.org/dsa/binary-search/
 * @param vector the sorted vector to search
 * @param title the title of the movie to find
 * @return the index of the movie if found, -1 otherwise
 */
int _find_index_binary(SortedMovieVector * vector, const char * title){
    int low = 0;
    int high = vector->size - 1;
    int mid;

    while (low <= high){
        // safer for overflowing
        mid = low + (high - low) / 2;
        int evaluation  = strcasecmp(title, vector->movies[mid]->title);

        if(evaluation == 0){
            return mid;
        }
        if(evaluation > 0){
            low = mid + 1;
        } else {
            high = mid - 1;
        }

    }
    return -1;
}


/**
 * adds a movie to the sorted vector.
 * 
 * Based on the movie (compare_movies), it will find the correct index
 * using a linear search.
 * 
 * The moment it finds that the movie to add is greater than the
 * current movie, it will insert it at that next index calling vector_insert.
 * 
 * 
 * @param vector the vector to add the movie to
 * @param movie the movie to add
*/
void add_to_sorted_vector(SortedMovieVector * vector, Movie * movie) {
    int n = vector->size - 1;

    for(int i=0; i<=n;i++){
        int eval = strcmp(movie->title, vector->movies[i]->title);
        if (eval < 0){ // less then zero makes this stable
            vector_insert(vector, movie, i);
            return;
        }
    }
     vector_add_back(vector, movie);
}

/**
 * Finds a movie in the sorted vector based on the title only of the movie.
 *
 * strcasecmp is used to compare the titles, so the search is case insensitive.
 *
 * For example: int cmp = strcasecmp(title, movie->title);
 *
 * You will want to implement this as a binary search. It can be done with a loop
 * or using a helper recursive function (your choice). You are free
 * to add the helper function above if you need one. 
 *
 * @param vector the vector to search
 * @param title the title of the movie to find
 * @return the movie if found, NULL otherwise
 */
Movie * find_in_sorted_vector(SortedMovieVector * vector, const char * title) {
    int index = _find_index_binary(vector, title);
    if (index != -1){
        Movie * found_movie = vector->movies[index];
        return found_movie;
        
    }
    return NULL;
}

/**
 * Checks if the sorted vector contains a movie with the given title.
 *
 * Very similar to find_in_sorted_vector, but instead of just finding
 * the movie will call vector_remove(vector, index) to remove the movie
 * returning the resulted removed movie.
 *
 * You will want to implement this as a binary search. It can be done with a loop
 * or using a helper recursive function (your choice). You are free
 * to add the helper function above if you need one.
 *
 * @param vector the vector to check
 * @param title the title to check for
 * @return the movie removed, NULL otherwise
 */
Movie* sorted_vector_remove(SortedMovieVector *vector, const char *title){
    // assumption there are not multiple movies with the same title
    // we can only return one movie anyway.
    int index = _find_index_binary(vector, title);
    if (index != -1){
        Movie * found_movie = vector->movies[index];
        vector_remove(vector, index);
        return found_movie;
        
    }

    return NULL; // not found
}



