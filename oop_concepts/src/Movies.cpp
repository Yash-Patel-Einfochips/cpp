/******************************************************************
 * Section 13 Challenge
 * Movies.h
 * 
 * Models a collection of Movies as a std::vector
 * 
 * ***************************************************************/
#include <iostream>
#include "Movies.h"

 /*************************************************************************
    Movies no-args constructor
**************************************************************************/
Movies::Movies() {
}

/*************************************************************************
    Movies destructor
**************************************************************************/
Movies::~Movies() {
}

  /*************************************************************************
    add_movie expects the name of the move, rating and watched count
    
    It will search the movies vector to see if a movie object already exists
    with the same name. 
    
    If it does then return false since the movie already exists
    Otherwise, create a movie object from the provided information
    and add that movie object to the movies vector and return true
    *********************************************************************/
bool Movies::add_movie(std::string name, std::string rating, int watched) {
    // you implement this method
    for (auto movie_obj : movies) {
        if (movie_obj.get_name() == name) {
            return false;
        }
    }
    Movie m {name, rating, watched};
    movies.push_back(m);
    
    return true;
}

 /*************************************************************************
    increment_watched expects the name of the move to increment the
    watched count
    
    It will search the movies vector to see if a movie object already exists
    with the same name. 
    If it does then increment that objects watched by 1 and return true.

    Otherwise, return false since then no movies object with the movie name
    provided exists to increment
    *********************************************************************/
bool Movies::increment_watched(std::string name) {
   // you implement this method
   bool obj_found = false;
   for (auto movie_obj : movies) {
        if (movie_obj.get_name() == name) {
            obj_found = true;
            int count = movie_obj.get_watched();
            movie_obj.set_watched(count++);
            break;
        }
    }
   return (obj_found) ? true : false;
}

/*************************************************************************
    display
    
    display all the movie objects in the movies vector.
    for each movie call the movie.display method so the movie
    object displays itself
    *********************************************************************/
void Movies::display() const {
    // You implement this method
    if (movies.empty()) {
        std::cout << "Sorry, no movies to display" << std::endl;
    } else {
        for (auto movie_obj: movies) {
                movie_obj.display();
        }
    }
}