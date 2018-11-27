//Yaminah Qureshi
//qureshiy

#include "GameModule.h"
#include "Exceptions.h"

std::vector<CardStackT> GameModule::CardS;

GameModule::GameModule() {}

void GameModule::init(std::vector<CardT> cards)
{


	if (cards.size() != 52) //a deck of 52 cards must be passed
		throw setup_error();
	for (int i = 0; i < 52; i++){
		for (int j = 0; j < 52; j++){
			if (cards[i].suit() == cards[j].suit() and cards[i].rank() == cards[j].rank() and i !=j) //check if there are any duplicate cards in passed deck
				throw setup_error();
	}
	}

	CardS = std::vector<CardStackT>();

	//create 4 tableau piles of 7 cards
	CardS.push_back(CardStackT(std::vector<CardT>(cards.begin(), cards.begin() + 7)));
	CardS.push_back(CardStackT(std::vector<CardT>(cards.begin()+7, cards.begin()+14)));
	CardS.push_back(CardStackT(std::vector<CardT>(cards.begin()+14, cards.begin()+21)));
	CardS.push_back(CardStackT(std::vector<CardT>(cards.begin()+21, cards.begin()+28)));

	//create 4 tableau piles of 6 cards
	CardS.push_back(CardStackT(std::vector<CardT>(cards.begin()+28, cards.begin()+34)));
	CardS.push_back(CardStackT(std::vector<CardT>(cards.begin()+34, cards.begin()+40)));
	CardS.push_back(CardStackT(std::vector<CardT>(cards.begin()+40, cards.begin()+46)));
	CardS.push_back(CardStackT(std::vector<CardT>(cards.begin()+46, cards.begin()+52)));
	
	//create 4 empty foundation piles
	CardS.push_back(CardStackT(std::vector<CardT>()));
	CardS.push_back(CardStackT(std::vector<CardT>()));
	CardS.push_back(CardStackT(std::vector<CardT>()));
	CardS.push_back(CardStackT(std::vector<CardT>()));

	//create 4 empty free cells
	CardS.push_back(CardStackT(std::vector<CardT>()));
	CardS.push_back(CardStackT(std::vector<CardT>()));
	CardS.push_back(CardStackT(std::vector<CardT>()));
	CardS.push_back(CardStackT(std::vector<CardT>()));
}

	
void GameModule::moveCard(int i, int j)
{
	//ensure valid indices are passed
	if (i >= CardS.size() or i < 0 or j >= CardS.size() or j < 0 or i == j)
		throw invalid_index();

	
	if (GameModule::invalidMove(i, j))
		throw invalid_move();

	//move top card from column i to column j
	std::vector<CardStackT> moveACard = CardS;
	moveACard[i] = moveACard[i].push(moveACard[j].top());
	CardS = GameModule::removeCard(j, moveACard);
}


bool GameModule::win()
{
	//check if all foundation  piles contain 13 cards
	for (int i = 8; i <= 11; i = i + 1){
		if (CardS[i].size() != 13)
			return false;
	}

	return true;
}

bool GameModule::noMoreMoves()
{
	//check for any valid move
	for (int i = 0; i <= 15; i++){
		for (int j = 0; j <= 15; j++){
			if (i!=j and CardS[j].size() != 0){
				if (!(GameModule::invalidMove(i,j)))
					return false;
		}


	}
}
	return true;
			
}

CardStackT GameModule::getColumn(int i)
{
	if (i < 0 or i >= CardS.size())
		throw invalid_index();
	return CardS[i];	
}

std::vector<CardStackT> GameModule::removeCard(int j, std::vector<CardStackT> cards)
{
	cards[j] = cards[j].pop();
	return cards;	
}


bool GameModule::nextCard(CardT card1, CardT card2)
{
	return card2.rank() == card1.rank() + 1 and card2.suit() == card1.suit();
}


bool GameModule::validCard(CardT card1, CardT card2)
{
	return card2.rank() == card1.rank() - 1 and !(GameModule::sameColour(card2, card1));
}

bool GameModule::sameColour(CardT card1, CardT card2)
{
  if (card1.suit() == card2.suit())
  	return true;
  if (card1.suit() == Clover and card2.suit() == Clubs)
  	return true;  
  if (card1.suit() == Clubs and card2.suit() == Clover)
  	return true;  
   if (card1.suit() == Hearts and card2.suit() == Diamonds)
  	return true;  
  if (card1.suit() == Diamonds and card2.suit() == Hearts)
  	return true;  
  return false;
}

bool GameModule::invalidMove(int i, int j)
{
	//invalid moves to tableau piles
	if (i == j) 
		return true;

	//invalid moves to tableau piles
	if (i <= 7) {
		if (GameModule::invalidMoveToTableau(i,j)) {
			return true;
		} 
	}

	//invalid moves to foundation piles
	if (i <= 11 and i >= 8) {
		if (GameModule::invalidMoveToFoundation(i,j)) { 
			return true;
		} 
	}

	//invalid moves to freecells
	if (i >= 12){
		if (GameModule::invalidMoveToFreeCell(i,j)) { 
			return true;
		} 
	}
	return false;	
}

bool GameModule::invalidMoveToTableau(int i, int j)
{
	if (!(CardS[i].size()==0)) { //if column i is empty then any card can be moved there
		if (!(GameModule::validCard(CardS[i].top(), CardS[j].top()))) //otherwise card must be opposite colour one less than the top card of column i
			return true;
	} 
	return false;
}

bool GameModule::invalidMoveToFoundation(int i, int j)
{
	if (CardS[i].size()==0) {
		if (!(CardS[j].top().rank() == 1)) //if column i is empty then the ace card of any suit can be moved there
			return true;
	} else
		if (!(GameModule::nextCard(CardS[i].top(), CardS[j].top()))) //otherwise card must be one greater than the top card of column i
			return true;
	return false;
}

bool GameModule::invalidMoveToFreeCell(int i, int j)
{
	if ((CardS[i].size()!=0))
		return true;
	return false;
}
