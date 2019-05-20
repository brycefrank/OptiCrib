#include <iostream>

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

int main() {
	Card c [52];
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
			c[i] = card;
			i += 1;
		}
	}
	cout << c[0].getvalue();
	return 0;
}

