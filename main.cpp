#include <iostream>
#include <algorithm>
#include <array>

using namespace std;

class Card {
	private: string suit; int value;

	public:
		 Card() {
			 value = 0;
		 }

		 Card(int v, string s) {
			 value = v;
			 suit = s;
		 }


		 int getvalue() {
			 return value;
		 }

		 string getsuit() {
			 return suit;
		 }

};

class Deck {
	public:
		Card cards[52];

		Deck() {
			int i = 0;
			for (int v=1; v <= 13; v++) {
				for (int s=1; s<=4; s++) {
					string b;
					switch(s) {
						case 1: b = "Hearts";
						break;

						case 2: b = "Spades";
						break;

						case 3: b = "Diamonds";
						break;

						case 4: b = "Clubs";
						break;
					};

					Card card (v, b);
					cards[i] = card;
					i += 1;
				}
			}
		}

		Card getcard(int i) {
			return cards[i];
		}

};

// Returns random integers between 0 and 51 without replacement
int * randomizeDeck() {
	static int order[52];
	int i = 0;

	while (i < 52) {
		// Check if in order using find
		int rand_num = rand() % 52;
		int *finder = find(begin(order), end(order), rand_num);


		if (finder == end(order)){
			// The element was not found, append!
			order[i] = rand_num;
			i += 1;
			cout << order[i];
		}
	}

	return order;
}

int main() {
	Deck d;
	randomizeDeck();
	return 0;
}

