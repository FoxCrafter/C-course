#include <iostream>
#include <cstdlib>
#include <ctime>

#define CPS 13 // Cards per suit

using namespace std;

enum suit {HEARTS, DIAMONDS, SPADES, CLUBS, N_SUITS};

const char suit_chars[N_SUITS] = {'H', 'D', 'S', 'C'};
const char value_chars[CPS] = {
	'A', '2', '3', '4', '5', '6', '7', '8', '9', 'X', 'J', 'Q', 'K'
};

class Card {
private:
	suit s;
	unsigned v;

public:
	Card(suit s, unsigned v)
	{
		this->s = s;
		this->v = v;
	}

	void print()
	{
		cout << suit_chars[s] << ' ' << value_chars[v - 1] << '\n';
	}
};

class Deck {
private:
	Card** cards;

public:
	Deck()
	{
		cards = new Card*[N_SUITS * CPS];
		for(unsigned i = 0; i < N_SUITS; i++)
		{
			for(unsigned j = 0; j < CPS; j++)
			{
				cards[i * CPS + j] = new Card((suit)i, j + 1);
			}
		}
	}

	~Deck()
	{
		for(unsigned i = 0; i < N_SUITS * CPS; i++)
		{
			delete cards[i];
		}
		delete[] cards;
	}

	void print()
	{
		for(unsigned i = 0; i < N_SUITS * CPS; i++)
		{
			if(cards[i] == NULL)
				cout << "missing\n";
			else
				cards[i]->print();
		}
	}

	Card* pick(unsigned i)
	{
		if(i >= N_SUITS * CPS)
		{
			return NULL;
		}
		Card* c = cards[i];
		for(unsigned j = i; j < N_SUITS * CPS - 1; j++)
		{
			cards[j] = cards[j + 1];
		}
		cards[N_SUITS * CPS - 1] = NULL;
		return c;
	}

	bool put(Card* c, unsigned i)
	{
		if(i >= N_SUITS * CPS || cards[N_SUITS * CPS - 1] != NULL)
		{
			return false;
		}
		for(unsigned j = N_SUITS * CPS; j > i; j--)
		{
			cards[j] = cards[j - 1];
		}
		cards[i] = c;
		return true;
	}

	unsigned count()
	{
		unsigned n = N_SUITS * CPS;
		for(int i = N_SUITS * CPS - 1; i >= 0; i--)
		{
			if(cards[i] != NULL)
			{
				break;
			}
			n--;
		}
		return n;
	}

	bool swap(unsigned i, unsigned j)
	{
		if(i >= N_SUITS * CPS || j >= N_SUITS * CPS)
		{
			return false;
		}
		Card* tmp = cards[i];
		cards[i] = cards[j];
		cards[j] = tmp;
		return true;
	}

	bool shuffle(unsigned n)
	{
		unsigned c = count();
		if(c < 2)
		{
			return false;
		}
		for(unsigned t = 0; t < n; t++)
		{
			swap(rand() % c, rand() % c);
		}
		return true;
	}
};

int main()
{
	srand(time(0));
	Deck deck;
	deck.shuffle(300);

	cout << deck.count() << '\n';
	Card* c = deck.pick(6);
	cout << deck.count() << '\n';

	deck.print();
	
	cout << "----------------------------\n";

	deck.put(c, 33);
	deck.print();

	return 0;
}
