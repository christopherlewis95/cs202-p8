#include "class.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <cstdio>


#define CARDS_PER_DECK 52

//// Function Prototypes ///


void readPlayersFromFile( ifstream&, char*, player*, int& );
void readDeckFromFile( ifstream&, char*, card*, card*, bool& );
void DisplayMenu();
int MakeSelection();
void shuffleDeck( card* );
void swap( card*, card* );
void dealCards( player*, card*, card* , int, int& , int&);

int main()
{
// Variables
int i, throwAway, stockAway;
ifstream fin;
int numPlayers;
char *filename = new char[20];
bool isOtherDeckFull = false;
card* deck = new card[CARDS_PER_DECK];
card* shuffledDeck = new card[CARDS_PER_DECK];
card* stock = new card[CARDS_PER_DECK];
card* discard = new card[CARDS_PER_DECK];
bool done = false;
char selection;
int disPile;
int stockPile;
cout << "Num Players: ";
cin >> numPlayers;

player* table = new player[numPlayers];

  while(!done)
    {
       DisplayMenu(); 
       selection = MakeSelection();
       
       switch(selection)
       {
           case 1:
           {
		readPlayersFromFile( fin, filename, table, numPlayers );


               break;
           }

           case 2:
           {
        	readDeckFromFile( fin, filename, deck, shuffledDeck, isOtherDeckFull );

               break;
           }

           case 3:
           {
            shuffleDeck( shuffledDeck );
            for(  int val = 0; val < CARDS_PER_DECK; val++ )
				{

				stock[val] = shuffledDeck[val];
				stock[val].setLocation( "Stock Pile" );
				}
		   break;
           }

           case 4:
           {
     		
			dealCards( table, stock, discard , numPlayers, throwAway, stockAway );
               break;
           }

           case 5:
           {
               for( i = 0; i < CARDS_PER_DECK; i++ )
				{
				cout << deck[i] << endl;


				}
               break;
           }

		   case 6:
           {
                for( i = 0; i < CARDS_PER_DECK; i++ )
				{
				cout << shuffledDeck[i] << endl;


				}
			
               break;
           }

   		   case 7:
           {
              for( i = 0; i < numPlayers; i++ )
				{
				cout << table[i] << endl;

				}
			
               break;
           }
   		   case 8:
           {
               
			for( i = stockAway; i < CARDS_PER_DECK; i++ )
				{
				cout << stock[i] << endl;

				}
               break;
           }

   		   case 9:
           {
             for( i = 0; i < throwAway; i++ )
				{
				cout << discard[i] << endl;

				}  
			
               break;
           }

   		   case 10:
           {
               
			done = true;
               break;
           }


       }
    }

delete[] discard;
delete[] stock;
delete[] shuffledDeck;
delete[] filename;
delete[] table;
delete[] deck;
return 0;
}

void readPlayersFromFile( ifstream& fin, char* filename, player* name, int& numPlayers)
{
int index;

cout << endl << endl;
cout << "Enter name file: ";
cin >> filename;

fin.clear();
fin.open( filename );
if( fin.good() )
{

for( index = 0; index < numPlayers; index++ )
	{

	fin >> name[index];
	
	cout << name[index] << endl;
	}
}
else
{
 cout << "ERROR: Wrong File name or contents of file are corrupted. " << endl;
}
fin.close();
}

void readDeckFromFile( ifstream& fin, char* filename , card* deck, card* deck2, bool& deckCheck )
{
int index;
cout << endl << endl;
cout << "Enter name card file: ";
cin >> filename;

fin.clear();
fin.open( filename );
if( fin.good() )
{

for( index = 0; index < CARDS_PER_DECK; index++ )
	{

	fin >> deck[index];
	
	}

// fill other deck if it hasnt been filled
if( deckCheck == false )
{
for( index = 0; index < CARDS_PER_DECK; index++ )
	{
	deck2[index] = deck[index];
	deck2[index].setLocation( "Shuffled" );
	}
}


}
else
{
 cout << "ERROR: Wrong File name or contents of file are corrupted. " << endl;
}
fin.close();
}

void DisplayMenu()
{
    cout << endl;
    cout << "********************************************************" << endl;
    cout << "   5 Card Draw Featuring the host Chris!" << endl;
    cout << "   -------------------------------------" << endl << endl;
 
    cout << "1.) Allow Players to take a seat (Reads Player File)" << endl;
    cout << "2.) Get out a deck (Reads in Unshuffled Deck)" << endl;
    cout << "3.) Shuffle the cards" << endl;
    cout << "4.) Deal the cards to the lovely guests" << endl;
    cout << "5.) Print Unshuffled Deck" << endl;
    cout << "6.) Print Shuffled Deck" << endl;
    cout << "7.) Print Players Hands" << endl;
	cout << "8.) Print Stock" << endl;
	cout << "9.) Print Discards " << endl;
	cout << "10.) End the game (Since youre the host) " << endl;
    cout << "********************************************************" << endl;
}

void swap( card* object1, card* object2 )
{
card* temp;

temp = object1;
object1 = object2;
object2 = temp;


}

int MakeSelection()
{
    int selection;
    cout << "Input number: ";
    cin >> selection;
    cout << "********************************************************" << endl;
    return selection;
}

void shuffleDeck( card* deck )
{
    srand((unsigned)time(NULL));
 int index1, index2;

 for( int i = 0; i < 250; i++ )
	{
	index1 = ( rand() % CARDS_PER_DECK );
	index2 = ( rand() % CARDS_PER_DECK );

	swap( deck[index1], deck[index2] );


	} 

}

void dealCards( player* guy, card* stock, card* discPile , int numPlayers, int& throwAway, int& stockAway )
{
int i, j, k = 0;
card temp[8][5];
int counter = 0;
stockAway = 0;
throwAway = 0;
for( i = 0; i < 5; i++ )
	{	
	for( j = 0; j < numPlayers; j++ )
		{
		temp[j][i] = stock[k];
		temp[j][i].setLocation( "Player Hand" );
		guy[j].setHand( temp[j] );
		stockAway++;
	    k++;
		}
	discPile[counter] = stock[k];
	discPile[counter].setLocation( "Discard Pile" );
	throwAway++;
	counter++;
	k++; 
	}

}




