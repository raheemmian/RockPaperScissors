#include <iostream>
#include <string>
#include <ctime>

using namespace std;
static const string alphabet[3] = { "r", "p", "s" };
int numberofgames = 0;
int playerscore = 0;
int computerscore = 0;
void gameLogic(string m);
string moveGenerator();
void getfinalscore();
string getMove(string x);

int main() {
	string remark;
	string move;
	while (1) {
		cout << "Are you ready to play Rock Paper Scissors ? (y or n) (q to quit) ";
		cin >> remark;
		if (remark.compare("y") == 0) {
			cout << "Enter number of games you wish to play: ";
			cin >> numberofgames;
			break;
		}
		else if(remark.compare("n") == 0){
			continue;
		}
		else if (remark.compare("q") == 0) {
			return 0;
		}
		else {
			cout << "incorrect Response" << endl;
			continue;
		}
	}
	for (int i = 0; i < numberofgames; i++) {
		cout << "pick a move (r, p, s): ";
		cin >> move;
		if (move == "q") break;
		gameLogic(move);
	}
	getfinalscore();
	return 0;
}

void gameLogic(string m) {
	string randomMove = moveGenerator();
	if (m == "s" && randomMove == "p" || m == "r" && randomMove == "s" || m == "p" && randomMove == "r") {
		playerscore++;
		cout << "You Won ! " << "players: " << getMove(m) << " beats computers: " << getMove(randomMove) << endl;
		cout << "Your score is: " << playerscore << " the CPU score is: " << computerscore << endl;
	}
	else if (randomMove == "s" && m == "p" || randomMove == "r" && m == "s" || randomMove == "p" && m == "r") {
		computerscore++;
		cout << "You Lost ! " << "players: " << getMove(m) << " loses against computers: " << getMove(randomMove) << endl;
		cout << "Your score is: " << playerscore << " the CPU score is: " << computerscore << endl;

	}
	else if (randomMove == m) {
		cout << "Its a tie ! " << "players: "<< getMove(m) << " ties with computers: " << getMove(randomMove) << endl;
		cout << "Your score is: " << playerscore << " the CPU score is: " << computerscore << endl;
	}
	else {
		cout << "move not recognized, pick from r,p,s" << endl;
		string tryAgainMove;
		cin >> tryAgainMove;
		return gameLogic(tryAgainMove);
	}
}

string moveGenerator() {
	srand(time(0));
	return alphabet[rand() % 3];
}

void getfinalscore() {
	if (playerscore > computerscore) {
		cout << "YOU WON" << endl;
	}
	else if (computerscore > playerscore) {
		cout << "YOU LOST" << endl;
	}
	else {
		cout << "ITS A TIE" << endl;
	}
	cout << "final Score:";
	cout << " player: " << playerscore;
	cout << " computerscore: " << computerscore << endl;
}

string getMove(string x) {
	if (x == "s") {
		return "Scissors";
	}
	else if (x == "r") {
		return "Rock";
	}
	else{
		return "Paper";
	}
}