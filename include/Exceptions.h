//Yaminah Qureshi
//qureshiy
/**
 *  \file Exceptions.h
 *  \brief Implements a game of Freecell
 */
#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <exception>

class invalid_card : public std::exception {
   const char * what () const throw () {
      return "invalid card";
   }
};

class empty_stack : public std::exception {
   const char * what () const throw () {
      return "empty cardstack";
   }
};

class setup_error : public std::exception {
   const char * what () const throw () {
      return "setup error";
   }
};

class invalid_index : public std::exception {
   const char * what () const throw () {
      return "invalid index";
   }
};

class invalid_move : public std::exception {
   const char * what () const throw () {
      return "invalid move";
   }
};

#endif