//Yaminah Qureshi
//qureshiy

#include "CardStackADT.h"
#include "Exceptions.h"

CardStackT::CardStackT(std::vector<CardT> s) : S(s)
{
}

CardT CardStackT::top()
{
	if (this->S.size() == 0)
		throw empty_stack();
	return this->S.back();
}

int CardStackT::size()
{
	return this->S.size();
}

CardStackT CardStackT::push(CardT card)
{
	std::vector<CardT> newSeq = this->S;
	newSeq.push_back(card);

	return CardStackT(newSeq);
}

CardStackT CardStackT::pop()
{
	if (this->S.size() == 0)
		throw empty_stack();
	std::vector<CardT> newSeq = this->S;
	newSeq.pop_back();
	return CardStackT(newSeq);
}