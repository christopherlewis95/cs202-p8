#ifndef _CLASS_H
#define _CLASS_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class card{

	public:
	
	card();
	card( const card& );
	~card();

	string getSuit();
	string getRank();
	string getLocation();
	
	void setSuit(const string );
	void setRank(const string );
	void setLocation(const string );

	card& operator=( const card& );
	bool operator!=(const card& );

	friend ostream& operator<<( ostream&, const card& );
	friend ifstream& operator>>( ifstream &, card& );
	friend bool operator==(const card&, const card&);

	


	private:

	string suit;
	string rank;
	string location;

};

class player{

	public:
	
	player();
	player( const player& );
	~player();
	string getName();
	card* getHand();
	float getBet();
	void setBet( float );
	void setHand( card* );
	void setName( string );

	friend ostream& operator<<(ostream&, const player&);
	friend ifstream& operator>>(ifstream&, player& );




	private:
	string name;
	card *hand;
	float bet;
	
};

#endif
