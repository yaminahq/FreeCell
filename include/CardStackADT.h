//Yaminah Qureshi
//qureshiy

/**
 *  \file CardStackADT.h
 *  \brief Generates an abstract data type for representing a stack of cards
 */


#ifndef CARDSTACKADT_H
#define CARDSTACKADT_H

#include "CardADT.h"
#include "CardTypes.h"
#include <vector>

/**
 *  \brief Class representing a stack of cards
 */
class CardStackT
{
  private:
    // the stack of cards as represented by a sequence of CardT objects
    std::vector<CardT> S;

  public:
/**
 *  \brief Constructs a new cardstack object
 *  \param s The sequence of cards that will represent the stack
 */
    CardStackT(std::vector<CardT> s);

/**
 *  \brief Returns the top card on the cardstack
 *  \return The top card of the cardstack
 */
    CardT top();

/**
 *  \brief Returns the size of the cardstack
 *  \return The number of cards in the stack
 */
    int size();

/**
 *  \brief Creates a new cardstack object with another card added to the top of the current stack
 *  \param card The card to add to the existing stack
 *  \return The new cardstack
 */    
    CardStackT push(CardT card);

/**
 *  \brief Creates a new cardstack object with the top card of the current stack removed
 *  \return The new cardstack
 */  
    CardStackT pop();

};

#endif