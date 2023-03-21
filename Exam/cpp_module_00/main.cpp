#include "Warlock.hpp"

int main()
 {
     Warlock const toto("Toto", "King of Peanut");
     toto.introduce();

     Warlock *jack = new Warlock("Jack", "the Pirat");
     jack->introduce();
     jack->setTitle("pawn");
     jack->introduce();

     delete jack;
     return 0;
 }