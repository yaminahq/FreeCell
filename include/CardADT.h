//Yaminah Qureshi
//qureshiy
/**
 *  \file CardADT.h
 *  \brief generates an ADT for representing a playing card
 */

#ifndef CARDADT_H
#define CARDADT_H

#include "CardTypes.h"

/**
 *  \brief Class representing a playing card
 */
class CardT 
{
    private:
    // the rank of the card
    int r;
    // the suit of the card
    SuitsT s;

  public:
/**
 *  \brief Constructs a Card object, representing a playing
 *  \param R the rank of the card
 *  \param S the suit of the card
 */
    CardT(int R, SuitsT S);
/**
 *  \brief Returns the rank of a card
 *  \return The rank of a card
 */
    int rank();
/**
 *  \brief Returns the suit of a card
 *  \return The suit of the card
 */
    SuitsT suit();
};
#endif