//Yaminah Qureshi
//qureshiy

#include "CardADT.h"
#include "Exceptions.h"

CardT::CardT(int R, SuitsT S)
{
  if (R < 1 or R > 13)
  	throw invalid_card();
  this->r = R;
  this->s = S;
}

int CardT::rank()
{
  return this->r;
}

SuitsT CardT::suit()
{
  return this->s;
}


