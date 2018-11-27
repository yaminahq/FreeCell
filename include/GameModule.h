//Yaminah Qureshi
//qureshiy
/**
 *  \file BoardADT.h
 *  \brief generates a abstract data type to represent the board used in the game Freecell
 */

#ifndef GAMEMODULE_H
#define GAMEMODULE_H

#include "CardStackADT.h"
#include "CardADT.h"
#include "CardTypes.h"
#include <vector>

/**
 *  \brief Class representing the board from a game of Freecell
 *  \details comprised by a sequence of cardstacks
 */

class GameModule
{
  private:
    // the sequence of cardstacks or cells that make up the board
    // The first 8 cadstacks of CardS represent the tableau piles, the next 4 cardstacks represent
    // the foundation piles and the final four cardstacks represent the four cells
    static std::vector<CardStackT> CardS;
/**
 *  \brief Removes the top card from the specified cardstack
 *  \param i the index of the cardstak from which the top card will be removed
 *  \return a new sequence of cardstacks with the top of one of the cardstacks removed
 */
    static std::vector<CardStackT> removeCard(int j, std::vector<CardStackT> cards);

/**
 *  \brief Checks if the second card is the same suit as and one rank higher than the first
 *  \param card1 The first card
 *  \param card2 The second card that is checked to see if its the same suit as and one rank higher
 *               than the first card
 *  \return true if the second card is the same suit as and one rank higher than the first
 */
    static bool nextCard(CardT card1, CardT card2);

/**
 *  \brief Checks if the second card is the same colour as and one rank lower than the first
 *  \param card1 The first card
 *  \param card2 The second card that is checked to see if its the same colour as and one rank lower
 *               than the first card
 *  \return true if the second card is the same colour as and one rank lower than the first
 */
    static bool validCard(CardT card1, CardT card2);
/**
 *  \brief Checks if two cards are the same colour
 *  \param card1 The first card
 *  \param card2 The second card
 *  \return true if both cards are the same colour
 */
   static bool sameColour(CardT card1, CardT card2);

/**
 *  \brief Checks if a move between columns and free cells is valid
 *  \param i the index of the cardstack a card will be moved to 
 *  \param j the index of the cardstack from which the top card will be moved
 *  \return true if the move is allowed
 */
    static bool invalidMove(int i, int j);
    
/**
 *  \brief Checks if moving a card to a tableau pile is valid
 *  \param i the index of the cardstack a card will be moved to 
 *  \param j the index of the cardstack from which the top card will be moved
 *  \return true if the move is allowed
 */
    static bool invalidMoveToTableau(int i, int j);

/**
 *  \brief Checks if moving a card to a foundation pile is valid
 *  \param i the index of the cardstack a card will be moved to 
 *  \param j the index of the cardstack from which the top card will be moved
 *  \return true if the move is allowed
 */
    static bool invalidMoveToFoundation(int i, int j);

/**
 *  \brief Checks if moving a card to a free cell is valid
 *  \param i the index of the cardstack a card will be moved to 
 *  \param j the index of the cardstack from which the top card will be moved
 *  \return true if the move is allowed
 */
    static bool invalidMoveToFreeCell(int i, int j);



    GameModule();

  public:

/**
 *  \brief Constructs a new board from a game of Freecell
 *  \details The first 4 groups of 7 cards are added to the first 4 tableau piles respectively,
 *            the next 4 groups of 6 cards each are added to the remaining 4 tableau piles respectively
 *  \param cards A sequence of 52 unique cards, in any order
 */
    static void init(std::vector<CardT> cards);
/**
 *  \brief Removes the top card from one cardstack and adds it to the top of another cardstack
 *  \details Moving to the tableau piles requires the card to be a different colour and 1 rank smaller
 *           than the top card of the tableau pile. Moving to the foundation piles requires the card
 *           be ace or one rank higher and the same suit as the top card of the foundation pile. The
 *           four cells can hold only one card at a time
 *  \param i the index of the cardstack to which a card will be added
 *  \param j the index of the cardstack from which the top card will be moved
 */
    static void moveCard(int i, int j);
/**
 *  \brief Determines if the board is in a winning state
 *  \return True if the board is in a winning state
 */
    static bool win();

/**
 *  \brief Determines if there are any valid moves left for the current board
 *  \return True if no more valid moves are left
 */
    static bool noMoreMoves();

/**
 *  \brief Retrieves the specified column of cards
 *  \details Can get cardstack from tableau piles, cells and foundation piles
 *  \param i the index of the cardstack to be retrieved
 *  \return The stack of cards
 */
    static CardStackT getColumn(int i);

};

#endif