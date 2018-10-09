#include <iostream>

#define CPS 13 // Cards per suit

using namespace std;

enum suit {HEARTS, DIAMONDS, SPADES, CLUBS, N_SUITS};

struct Card {
	suit s;
	unsigned v; // 1:A, 2-10:2-10, 11:J, 12:Q, 13:K
};

const char suit_chars[N_SUITS] = {'H', 'D', 'S', 'C'};
const char value_chars[CPS] = {
	'A', '2', '3', '4', '5', '6', '7', '8', '9', 'X', 'J', 'Q', 'K'
};

void printCard(const Card* c)
{
	if(c == nullptr)
		cout << "missing\n";
	else
		cout << suit_chars[c->s] << ' ' << value_chars[c->v - 1] << '\n';
}

Card* deck[N_SUITS * CPS];

void createDeck()
{
	for(unsigned i = 0; i < N_SUITS; i++)
	{
		for(unsigned j = 0; j < CPS; j++)
		{
			deck[i * CPS + j] = new Card;
			deck[i * CPS + j]->s = (suit)i;
			deck[i * CPS + j]->v = j + 1;
		}
	}
}

void destroyDeck()
{
	for(unsigned i = 0; i < N_SUITS * CPS; i++)
	{
		delete deck[i];
	}
}

Card* pick(unsigned i)
{
	if(i >= N_SUITS * CPS)
	{
		return nullptr;
	}
	Card* c = deck[i];
	for(unsigned j = i; j < N_SUITS * CPS - 1; j++)
	{
		deck[j] = deck[j + 1];
	}
	deck[N_SUITS * CPS - 1] = nullptr;
	return c;
}

unsigned count()
{
	unsigned n = N_SUITS * CPS;
	for(int i = N_SUITS * CPS - 1; i >= 0; i--)
	{
		if(deck[i] != nullptr)
		{
			break;
		}
		n--;
	}
	return n;
}

int main()
{
	createDeck();

	cout << count() << '\n';
	delete pick(6);
	cout << count() << '\n';

	for(unsigned i = 0; i < N_SUITS * CPS; i++)
	{
			printCard(deck[i]);
	}

	destroyDeck();
	return 0;
}

