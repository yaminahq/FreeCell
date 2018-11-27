//Yaminah Qureshi
//qureshiy

#include "catch.h"

 #include "CardADT.h"
 #include "CardStackADT.h"
 #include "CardTypes.h"
 #include "GameModule.h"
 //#include "GameModule.h"
 #include "Exceptions.h"

#include <iostream>
#include <vector>

bool equalCards(CardT c1, CardT c2) {
  return c1.suit() == c2.suit() and c1.rank() == c2.rank();
}

TEST_CASE( "tests for CardT" , "[CardT]" ) {
  
  /*
   *  At the start of your test case, you can set up variables
   *  that you will use in your tests.  These variables are reconstructed
   *  before every test, so if you modify some of them in a test
   *  they will be reset at the start of the next test.
   */

  CardT c1(1, Clover);
  CardT c2(2, Clubs);
  CardT c3(3, Hearts);
  CardT c4(13, Diamonds);




   SECTION( "constructor for CardT" ){
     REQUIRE( c1.rank() == 1) ;
     REQUIRE( c2.rank() == 2) ;
     REQUIRE( c3.rank() == 3) ;
     REQUIRE( c4.rank() == 13);
     REQUIRE( c1.suit() == Clover) ;
     REQUIRE( c2.suit() == Clubs) ;
     REQUIRE( c3.suit() == Hearts) ;
     REQUIRE( c4.suit() == Diamonds) ;
   }

   SECTION( "invalid rank when constructing a card" ){
    REQUIRE_THROWS_AS(CardT(0, Clover), invalid_card);
    REQUIRE_THROWS_AS( CardT(14, Clover), invalid_card);
   }

    SECTION( "rank for CardT" ){
     REQUIRE( c1.rank() == 1) ;
     REQUIRE( c2.rank() == 2) ;
     REQUIRE( c3.rank() == 3) ;
     REQUIRE( c4.rank() == 13);
   }

   SECTION( "suit for CardT" ){
     REQUIRE( c1.suit() == Clover) ;
     REQUIRE( c2.suit() == Clubs) ;
     REQUIRE( c3.suit() == Hearts) ;
     REQUIRE( c4.suit() == Diamonds) ;
   }
}

TEST_CASE( "tests for CardStackT" , "[CardStackT]" ) {
  
  /*
   *  At the start of your test case, you can set up variables
   *  that you will use in your tests.  These variables are reconstructed
   *  before every test, so if you modify some of them in a test
   *  they will be reset at the start of the next test.
   */

  CardT c1(1, Clover);
  CardT c2(2, Clubs);
  CardT c3(3, Hearts);
  CardT c4(13, Diamonds);
  std::vector<CardT> seq;
  seq.push_back(c1);
  seq.push_back(c2);
  seq.push_back(c3);
  seq.push_back(c4);
  CardStackT s1(seq);

   SECTION( "constructor for CardStackT" ){
     REQUIRE( s1.size() == 4);
     REQUIRE(equalCards(s1.top(), CardT(13, Diamonds)));
     s1 = s1.pop();
     REQUIRE(equalCards(s1.top(), CardT(3, Hearts)));
     s1 = s1.pop();
     REQUIRE(equalCards(s1.top(), CardT(2, Clubs)));
     s1 = s1.pop();
     REQUIRE(equalCards(s1.top(), CardT(1, Clover)));
   }

    SECTION( "top for CardStackT" ){
      REQUIRE(equalCards(s1.top(), CardT(13, Diamonds)));
      s1 = s1.pop();
      REQUIRE(equalCards(s1.top(), CardT(3, Hearts)));
   }

   SECTION( "cardstack is empty when calling top exception" ){
      std::vector<CardT> seq;
      CardStackT s1(seq);
      REQUIRE_THROWS_AS(s1.top(), empty_stack);

   }

  SECTION( "size for CardStackT" ){
    REQUIRE( s1.size() == 4);
    s1 = s1.pop();
    REQUIRE( s1.size() == 3);
   }

   SECTION( "push for CardStackT" ){
      REQUIRE(equalCards(s1.top(), CardT(13, Diamonds)));
      s1 = s1.push(CardT(4, Clover));
      REQUIRE(equalCards(s1.top(), CardT(4, Clover)));
   }

    SECTION( "pop for CardStackT" ){
      REQUIRE(equalCards(s1.top(), CardT(13, Diamonds)));
      s1 = s1.pop();
      REQUIRE(equalCards(s1.top(), CardT(3, Hearts)));
   }

    SECTION( "cardstack is empty when calling pop exception" ){
      std::vector<CardT> seq;
      CardStackT s1(seq);
      REQUIRE_THROWS_AS(s1.pop(), empty_stack);

   }
}

TEST_CASE( "tests for BoardT" , "[BoardT]" ) {
  
  /*
   *  At the start of your test case, you can set up variables
   *  that you will use in your tests.  These variables are reconstructed
   *  before every test, so if you modify some of them in a test
   *  they will be reset at the start of the next test.
   */

    std::vector<CardT> newseq;
    for (int i = 1; i<=13; i++){
      newseq.push_back(CardT(i, Clover));
    }
    for (int i = 1; i<=13; i++){
      newseq.push_back(CardT(i, Clubs));
    }
        for (int i = 1; i<=13; i++){
      newseq.push_back(CardT(i, Diamonds));
    }
    for (int i = 1; i<=13; i++){
      newseq.push_back(CardT(i, Hearts));
    }
    GameModule::init(newseq);


    SECTION( "init for GameModule" ){
      REQUIRE( GameModule::getColumn(0).size() == 7) ;
      REQUIRE( equalCards(GameModule::getColumn(0).top(), CardT(7, Clover)));
     REQUIRE( GameModule::getColumn(1).size() == 7) ;
     REQUIRE( equalCards(GameModule::getColumn(1).top(), CardT(1, Clubs)));
     REQUIRE( GameModule::getColumn(2).size() == 7) ;
     REQUIRE( equalCards(GameModule::getColumn(2).top(), CardT(8, Clubs)));
     REQUIRE( GameModule::getColumn(3).size() == 7) ;
     REQUIRE( equalCards(GameModule::getColumn(3).top(), CardT(2, Diamonds)));
     REQUIRE( GameModule::getColumn(4).size() == 6) ;
     REQUIRE( equalCards(GameModule::getColumn(4).top(), CardT(8, Diamonds)));
     REQUIRE( GameModule::getColumn(5).size() == 6) ;
     REQUIRE( equalCards(GameModule::getColumn(5).top(), CardT(1, Hearts)));
     REQUIRE( GameModule::getColumn(6).size() == 6) ;
     REQUIRE( equalCards(GameModule::getColumn(6).top(), CardT(7, Hearts)));
     REQUIRE( GameModule::getColumn(7).size() == 6) ;
     REQUIRE( equalCards(GameModule::getColumn(7).top(), CardT(13, Hearts)));
     REQUIRE( GameModule::getColumn(8).size() == 0) ;
     REQUIRE( GameModule::getColumn(9).size() == 0) ;
     REQUIRE( GameModule::getColumn(10).size() == 0) ;
     REQUIRE( GameModule::getColumn(11).size() == 0) ;
     REQUIRE( GameModule::getColumn(12).size() == 0) ;
     REQUIRE( GameModule::getColumn(13).size() == 0) ;
     REQUIRE( GameModule::getColumn(14).size() == 0) ;
     REQUIRE( GameModule::getColumn(15).size() == 0) ;
    }

 SECTION( "initializing GameModule with incorectly sized sequence of cards exception" ){
    newseq.pop_back();
    REQUIRE_THROWS_AS(GameModule::init(newseq), setup_error);
   }

 SECTION( "initializing GameModule with a sequence of card containing duplicates exception" ){
    newseq.pop_back();
    newseq.push_back(CardT(12, Hearts));
    REQUIRE_THROWS_AS(GameModule::init(newseq), setup_error);
   }

  SECTION( "move Card to tableau pile" ){
     REQUIRE( equalCards(GameModule::getColumn(0).top(), CardT(7, Clover)));
     REQUIRE( equalCards(GameModule::getColumn(4).top(), CardT(8, Diamonds)));
     GameModule::moveCard(4,0);
     REQUIRE( equalCards(GameModule::getColumn(4).top(), CardT(7, Clover)));
     REQUIRE( equalCards(GameModule::getColumn(0).top(), CardT(6, Clover)));
   }

  SECTION( "move Card to empty tableau pile" ){
    std::vector<CardT> newseq;
    for (int i = 1; i<=13; i++){
      newseq.push_back(CardT(i, Clover));
    }
    newseq.push_back(CardT(8, Clubs));
    newseq.push_back(CardT(7, Clubs));
    newseq.push_back(CardT(6, Clubs));
    newseq.push_back(CardT(5, Clubs));
    newseq.push_back(CardT(4, Clubs));
    newseq.push_back(CardT(3, Clubs));
    newseq.push_back(CardT(2, Clubs));
    newseq.push_back(CardT(1, Clubs));
    newseq.push_back(CardT(9, Clubs));
    newseq.push_back(CardT(10, Clubs));
    newseq.push_back(CardT(11, Clubs));
    newseq.push_back(CardT(12, Clubs));
    newseq.push_back(CardT(13, Clubs));
    
    for (int i = 1; i<=13; i++){
      newseq.push_back(CardT(i, Diamonds));
    }
    for (int i = 1; i<=13; i++){
      newseq.push_back(CardT(i, Hearts));
    }
    GameModule::init(newseq);

    REQUIRE( equalCards(GameModule::getColumn(2).top(), CardT(1, Clubs)));
    for (int i = 1; i <=7 ; i++){
      GameModule::moveCard(8,2);

    }
     REQUIRE(GameModule::getColumn(2).size()==0);
     REQUIRE( equalCards(GameModule::getColumn(0).top(), CardT(7, Clover)));
     GameModule::moveCard(2,0);
     REQUIRE( equalCards(GameModule::getColumn(2).top(), CardT(7, Clover)));
   }

  SECTION( "move Card to tableau pile but card isn't opposite colour or one rank smaller exception" ){
     REQUIRE( equalCards(GameModule::getColumn(0).top(), CardT(7, Clover)));
     REQUIRE( equalCards(GameModule::getColumn(3).top(), CardT(2, Diamonds)));
     REQUIRE( equalCards(GameModule::getColumn(5).top(), CardT(1, Hearts)));
     REQUIRE_THROWS_AS(GameModule::moveCard(3,5), invalid_move);
     REQUIRE_THROWS_AS(GameModule::moveCard(0,5), invalid_move);
   }

  SECTION( "moveCard to foundation pile" ){
    std::vector<CardT> newseq;
    for (int i = 1; i<=13; i++){
      newseq.push_back(CardT(i, Clover));
    }
    newseq.push_back(CardT(1, Clubs));
    newseq.push_back(CardT(8, Clubs));
    newseq.push_back(CardT(3, Clubs));
    newseq.push_back(CardT(4, Clubs));
    newseq.push_back(CardT(5, Clubs));
    newseq.push_back(CardT(6, Clubs));
    newseq.push_back(CardT(7, Clubs));
    newseq.push_back(CardT(2, Clubs));
    newseq.push_back(CardT(9, Clubs));
    newseq.push_back(CardT(10, Clubs));
    newseq.push_back(CardT(11, Clubs));
    newseq.push_back(CardT(12, Clubs));
    newseq.push_back(CardT(13, Clubs));
    
    for (int i = 1; i<=13; i++){
      newseq.push_back(CardT(i, Diamonds));
    }
    for (int i = 1; i<=13; i++){
      newseq.push_back(CardT(i, Hearts));
    }
    GameModule::init(newseq);

     REQUIRE( equalCards(GameModule::getColumn(1).top(), CardT(1, Clubs)));
     REQUIRE( equalCards(GameModule::getColumn(2).top(), CardT(2, Clubs)));
     GameModule::moveCard(8,1);
     REQUIRE( equalCards(GameModule::getColumn(8).top(), CardT(1, Clubs)));
     GameModule::moveCard(8,2);
     REQUIRE( equalCards(GameModule::getColumn(8).top(), CardT(2, Clubs)));
   }

  SECTION( "move Card to foundation pile but card isn't same suit or one rank higher exception" ){
     REQUIRE( equalCards(GameModule::getColumn(3).top(), CardT(2, Diamonds)));
     REQUIRE( equalCards(GameModule::getColumn(5).top(), CardT(1, Hearts)));
     REQUIRE( equalCards(GameModule::getColumn(6).top(), CardT(7, Hearts)));
     GameModule::moveCard(8,5);
     REQUIRE( equalCards(GameModule::getColumn(8).top(), CardT(1, Hearts)));
     REQUIRE_THROWS_AS(GameModule::moveCard(8,3), invalid_move);
     REQUIRE_THROWS_AS(GameModule::moveCard(8,6), invalid_move);
   }

  SECTION( "move Card to empty foundation pile but card isn't ace exception" ){
     REQUIRE( equalCards(GameModule::getColumn(3).top(), CardT(2, Diamonds)));
     REQUIRE( GameModule::getColumn(8).size() == 0);
     REQUIRE_THROWS_AS(GameModule::moveCard(8,3), invalid_move);
   }

  SECTION( "moveCard to free cell" ){
     REQUIRE( equalCards(GameModule::getColumn(3).top(), CardT(2, Diamonds)));
     REQUIRE( equalCards(GameModule::getColumn(0).top(), CardT(7, Clover)));
     GameModule::moveCard(12,3);
     REQUIRE( equalCards(GameModule::getColumn(12).top(), CardT(2, Diamonds)));
     REQUIRE( equalCards(GameModule::getColumn(3).top(), CardT(1, Diamonds)));
     GameModule::moveCard(15, 0);
     REQUIRE( equalCards(GameModule::getColumn(15).top(), CardT(7, Clover)));
     REQUIRE( equalCards(GameModule::getColumn(0).top(), CardT(6, Clover)));
   }

   SECTION( "moveCard from free cell to tableau pile" ){
     REQUIRE( equalCards(GameModule::getColumn(0).top(), CardT(7, Clover)));
     REQUIRE( equalCards(GameModule::getColumn(4).top(), CardT(8, Diamonds)));
     GameModule::moveCard(12,0);
     REQUIRE( equalCards(GameModule::getColumn(12).top(), CardT(7, Clover)));
     GameModule::moveCard(4,12);
     REQUIRE( equalCards(GameModule::getColumn(4).top(), CardT(7, Clover)));
   }

   SECTION( "moveCard from free cell to foundation pile" ){
    std::vector<CardT> newseq;
    for (int i = 1; i<=13; i++){
      newseq.push_back(CardT(i, Clover));
    }
    newseq.push_back(CardT(1, Clubs));
    newseq.push_back(CardT(8, Clubs));
    newseq.push_back(CardT(3, Clubs));
    newseq.push_back(CardT(4, Clubs));
    newseq.push_back(CardT(5, Clubs));
    newseq.push_back(CardT(6, Clubs));
    newseq.push_back(CardT(7, Clubs));
    newseq.push_back(CardT(2, Clubs));
    newseq.push_back(CardT(9, Clubs));
    newseq.push_back(CardT(10, Clubs));
    newseq.push_back(CardT(11, Clubs));
    newseq.push_back(CardT(12, Clubs));
    newseq.push_back(CardT(13, Clubs));
    
    for (int i = 1; i<=13; i++){
      newseq.push_back(CardT(i, Diamonds));
    }
    for (int i = 1; i<=13; i++){
      newseq.push_back(CardT(i, Hearts));
    }
    GameModule::init(newseq);

     REQUIRE( equalCards(GameModule::getColumn(1).top(), CardT(1, Clubs)));
     REQUIRE( equalCards(GameModule::getColumn(2).top(), CardT(2, Clubs)));
     GameModule::moveCard(8,1);
     REQUIRE( equalCards(GameModule::getColumn(8).top(), CardT(1, Clubs)));
     GameModule::moveCard(12,2);
     REQUIRE( equalCards(GameModule::getColumn(12).top(), CardT(2, Clubs)));
     GameModule::moveCard(8,12);
     REQUIRE( equalCards(GameModule::getColumn(8).top(), CardT(2, Clubs)));
   }

  SECTION( "move Card to an occupied free cell exception" ){
     REQUIRE( equalCards(GameModule::getColumn(0).top(), CardT(7, Clover)));
     REQUIRE( equalCards(GameModule::getColumn(4).top(), CardT(8, Diamonds)));
     GameModule::moveCard(12,4);
     REQUIRE_THROWS_AS(GameModule::moveCard(12,0), invalid_move);
   }

  SECTION( "move Card to free cell when all free cells are occupied exception" ){
     REQUIRE( equalCards(GameModule::getColumn(0).top(), CardT(7, Clover)));
     REQUIRE( equalCards(GameModule::getColumn(3).top(), CardT(2, Diamonds)));
     REQUIRE( equalCards(GameModule::getColumn(5).top(), CardT(1, Hearts)));
     REQUIRE( equalCards(GameModule::getColumn(4).top(), CardT(8, Diamonds)));
     REQUIRE( equalCards(GameModule::getColumn(6).top(), CardT(7, Hearts)));

     GameModule::moveCard(12,0);
     GameModule::moveCard(13,3);
     GameModule::moveCard(14,5);
     GameModule::moveCard(15,4);

     for (int i = 12; i<=15; i++){
        REQUIRE_THROWS_AS(GameModule::moveCard(i,6), invalid_move);
     }
     
   }

   SECTION( "board is not in winning state" ){
     REQUIRE(GameModule::win()== false);
   }

   SECTION( "board is in winning state" ){
    std::vector<CardT> newseq;
    for (int i = 7; i >= 1; i--){
      newseq.push_back(CardT(i, Clover));
    }
    newseq.push_back(CardT(1, Clubs));
    for (int i = 13; i>=8; i--){
      newseq.push_back(CardT(i, Clover));
    }
    for (int i = 8; i>=2; i--){
      newseq.push_back(CardT(i, Clubs));
    }
    newseq.push_back(CardT(2, Diamonds));
    newseq.push_back(CardT(1, Diamonds));
    for (int i = 13; i>=9; i--){
      newseq.push_back(CardT(i, Clubs));
    }
    for (int i = 8; i>=3; i--){
      newseq.push_back(CardT(i, Diamonds));
    }
    newseq.push_back(CardT(1, Hearts));
    for (int i = 13; i>=9; i--){
      newseq.push_back(CardT(i, Diamonds));
    }
    for (int i = 7; i>=2; i--){
      newseq.push_back(CardT(i, Hearts));
    }
    for (int i = 13; i>=8; i--){
      newseq.push_back(CardT(i, Hearts));
    }
    REQUIRE(newseq.size() == 52);
    GameModule::init(newseq);
    REQUIRE( equalCards(GameModule::getColumn(0).top(), CardT(1, Clover)));
    REQUIRE( equalCards(GameModule::getColumn(1).top(), CardT(8, Clover)));
    REQUIRE( equalCards(GameModule::getColumn(2).top(), CardT(2, Clubs)));
    REQUIRE( equalCards(GameModule::getColumn(3).top(), CardT(9, Clubs)));
    REQUIRE( equalCards(GameModule::getColumn(4).top(), CardT(3, Diamonds)));
    REQUIRE( equalCards(GameModule::getColumn(5).top(), CardT(9, Diamonds)));
    REQUIRE( equalCards(GameModule::getColumn(6).top(), CardT(2, Hearts)));
    REQUIRE( equalCards(GameModule::getColumn(7).top(), CardT(8, Hearts)));

    for (int i = 1; i <= 7; i++){
      GameModule::moveCard(8,0);
    }
     for (int i = 8; i <= 13; i++){
       GameModule::moveCard(8,1);
     }
     GameModule::moveCard(9,1);
     for (int i = 2; i <= 8; i++){
       GameModule::moveCard(9,2);
     }
     for (int i = 9; i <= 13; i++){
       GameModule::moveCard(9,3);
     }
     GameModule::moveCard(10,3);
     GameModule::moveCard(10,3);
     for (int i = 3; i <= 8; i++){
       GameModule::moveCard(10,4);
     }
     for (int i = 9; i <= 13; i++){
       GameModule::moveCard(10,5);
     }
     GameModule::moveCard(11,5);
     for (int i = 2; i <= 7; i++){
       GameModule::moveCard(11,6);
     }
     for (int i = 8; i <= 13; i++){
       GameModule::moveCard(11,7);
     }


     REQUIRE(GameModule::win()== true);
    }

    SECTION( "valid moves are still possible for current board configuration" ){
      REQUIRE(GameModule::noMoreMoves()== false);
    }

    SECTION( "no valid moves are possible for current board configuration" ){
     std::vector<CardT> newseq;

     for (int i = 1; i<=4; i++){
       newseq.push_back(CardT(i, Clover));
     }
     newseq.push_back(CardT(6, Clover));
     newseq.push_back(CardT(7, Clover));
     newseq.push_back(CardT(5, Clover));
     for (int i = 8; i<=13; i++){
       newseq.push_back(CardT(i, Clover));
     }
     newseq.push_back(CardT(2, Clubs));
     newseq.push_back(CardT(1, Clubs));
     for (int i = 3; i<=13; i++){
       newseq.push_back(CardT(i, Clubs));
     }
     for (int i = 1; i<=13; i++){
       newseq.push_back(CardT(i, Diamonds));
     }
     newseq.push_back(CardT(2, Hearts));
     newseq.push_back(CardT(1, Hearts));
     for (int i = 3; i<=13; i++){
       newseq.push_back(CardT(i, Hearts));
     }
     GameModule::init(newseq);

     GameModule::moveCard(12,0);
     GameModule::moveCard(13,2);
     GameModule::moveCard(14,4);
     GameModule::moveCard(15,7);

     REQUIRE( equalCards(GameModule::getColumn(0).top(), CardT(7, Clover)));
     REQUIRE( equalCards(GameModule::getColumn(1).top(), CardT(2, Clubs)));
     REQUIRE( equalCards(GameModule::getColumn(2).top(), CardT(7, Clubs)));
     REQUIRE( equalCards(GameModule::getColumn(3).top(), CardT(2, Diamonds)));
     REQUIRE( equalCards(GameModule::getColumn(4).top(), CardT(7, Diamonds)));
     REQUIRE( equalCards(GameModule::getColumn(5).top(), CardT(2, Hearts)));
     REQUIRE( equalCards(GameModule::getColumn(6).top(), CardT(7, Hearts)));
     REQUIRE( equalCards(GameModule::getColumn(7).top(), CardT(12, Hearts)));

     REQUIRE(GameModule::noMoreMoves()== true);
    }

}

