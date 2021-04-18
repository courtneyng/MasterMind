/*
Courtney Ng
Period 4
Mastermind
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


int pos(string ans, string guess);
int dig(string ans, string guess);


int main(){
	srand(time(0));
	int tries = 12;
	int numDigits, range; // should be able to change
	string numbers = "", guess = "", ans = "";	
	string user;
	
	//----------------------------------------------------------------------------------------------------------------
	//intro
	cout << "this is mastermind." << endl;
	cout << "the rules: \nthe computer will generate a number combination for the player to guess within a \nset number ";
	cout << "range of the player's choosing and a set length of the player's choosing." << endl << endl;
	cout << "how many digits do you want to guess? \n (1) 4 \n (2) 5 \n (3) 6 \n (4) 7 \n (5) 8" << endl;
	cin >> numDigits;
	
	//----------------------------------------------------------------------------------------------------------------
	//Num digits change
	switch(numDigits){
		case 1: numDigits = 4; break;
		case 2: numDigits = 5; break;
		case 3: numDigits = 6; break;
		case 4: numDigits = 7; break;
		case 5: numDigits = 8; break;
	}
	//----------------------------------------------------------------------------------------------------------------
	
	cout << "select a range: \n (1) 1-5 \n (2) 1-6 \n (3) 1-7 \n (4) 1-8 \n (5) 1-9" << endl;
	cin >> range;
	//----------------------------------------------------------------------------------------------------------------
	//range change
	switch(range){
		case 1: numbers = "12345"; break;
		case 2: numbers = "123456"; break;
		case 3: numbers = "1234567"; break;
		case 4: numbers = "12345678"; break;
		case 5: numbers = "123456789"; break;
	}
	//----------------------------------------------------------------------------------------------------------------
	cout << "you have " << tries << " tries to guess a combination of " << numDigits << " numbers"<< endl;
	
	//----------------------------------------------------------------------------------------------------------------

	//functions correct spots and digits
	
	
	
	//----------------------------------------------------------------------------------------------------------------
	//Computer Guess.
	int r; //random
	
	string together = ""; 
	for (int i = 0; i < numDigits; i++){
		do{
			r = rand() % numbers.length(); 
		}while(numbers[r] == 'x');
		
		//together += numbers[rand() % numbers.length()]; //concatination
		ans += numbers[r];
		numbers[r] = 'x';
	}
	//cout << numbers << endl;
	//cout << together << endl;
	//----------------------------------------------------------------------------------------------------------------
	
	//----------------------------------------------------------------------------------------------------------------
	//actual game text
	//lets you know pos, correct, player # etc
	//cout << ans << endl; //help check if weird parts in code, prints answer
	
	
	for(int i = 1; i < 13; i++){
		if(pos(ans, guess) == ans.length() && dig(ans, guess) == ans.length()){
			cout << "you win";
			i = 12;
		}
		else{
			cout << "Enter your guess: ";
			cin >> guess;
			
			if (guess.length() > ans.length()){
				cout << "Enter your guess: ";
				cin >> guess;
			}
			cout << "guess (" << i << ")" << endl;
			cout << "position(s) correct: " << pos(ans, guess) << endl;
			cout << "digit(s) correct: " << dig(ans, guess) << endl;
			cout << endl;
			if(i >= 11){
				cout << "game over. \nthe correct answer: " << ans;
			}
		}
		
	}
	
	//----------------------------------------------------------------------------------------------------------------
}

//----------------------------------------------------------------------------------------------------------------
//Correct position check

int pos(string ans, string guess){
	int count = 0;
	for (int i = 0; i < ans.length(); i++){
		if (ans [i] == guess[i]){
			count++;
		
		}
	}
	return count;
}

//----------------------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------------------
//check # of digits
int dig(string guess, string ans){
	int count = 0;
	for (int i = 0; i < ans.length(); i++){
		for (int j = 0; j < ans.length(); j++){
			if(guess[i] == ans[j]){
				count++;
		}
	}
}
	return count;
}

//----------------------------------------------------------------------------------------------------------------


