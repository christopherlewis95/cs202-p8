#include "class.h"
//#include <iostream>
//#include <fstream>
//#include <string>

using namespace std;

//// Card Class ////////////////
/// card:: ///


card::card()
{
 suit = "suit";
 rank = "rank";
 location = "location";

}

card::card( const card& x )
{
	suit = x.suit;
	rank = x.rank;
	location = x.location;

}
	
card::~card()
{
 suit = "suit";
 rank = "rank";
 location = "location";

}

string card::getSuit()
{
 return suit;
}

string card::getRank()
{
 return rank;

}

string card::getLocation()
{
 return location;

}
	
void card::setSuit( const string var )
{
 suit = var;

}
	
void card::setRank( const string var )
{
 rank = var;

}
	
void card::setLocation( const string var )
{
 location = var;

}

card& card::operator=( const card& x )
{
if( this != &x )
{
	suit = x.suit;
	rank = x.rank;
	location = x.location;
}
return *this;
}
	
bool card::operator!=(const card& x)
{
if( ( suit == x.suit ) || ( rank == x.rank ) || ( location == x.location ) )
	{
	return false;
	}

return true;
}

ostream& operator<<( ostream& out, const card& y)
{
out << y.rank << "	" << y.suit << "	" << y.location << endl;

return out;
}
	
ifstream& operator>>( ifstream& in, card& y)
{
in  >> y.suit >> y.rank;

y.location = "Unshuffled";

}

bool operator==(const card& x, const card& y)
{
if( x == y )
	{	
	return true;
	}
return false;
}


/////////// Player class /////////////////////
/// player::

player::player()
{
 name = "name";
 hand = NULL;
 bet = 0.0;

}

player::player( const player& x )
{
 name = x.name;
 hand = new card[5];
 for( int i = 0; i < 5; i++ )
	{
	hand[i] = x.hand[i];
	}
 bet = x.bet;
}

player::~player()
{
delete[] hand;
hand = NULL;

 name = "name";
 bet = 0.0;

}

string player::getName()
{
return name;
}

card* player::getHand()
{
return hand;
}

float player::getBet()
{
return bet;
}

void player::setBet( float num )
{
bet = num;
}

void player::setHand( card*  x )
{
if( hand == NULL )
	{
	hand = new card[5];
	}
for( int ndx = 0; ndx < 5; ndx++ )
	{
	hand[ndx] = x[ndx];
	}
}

void player::setName( string x )
{
name = x;
}

ostream& operator<<(ostream& out , const player& x)
{
out <<  x.name << "	" << x.bet << endl;
if(x.hand != NULL){
for( int num = 0; num < 5; num++ )
	{	
	out << x.hand[num] << "	";
	}
}
return out;
}

ifstream& operator>>(ifstream& fin, player& x)
{
string temp;
fin >> x.name >> temp;
x.name += " ";
x.name += temp;
x.name += "	";
}
