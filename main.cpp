#include "player.h"
#include "enemy.h"

#include <iostream>
#include <string>
#include <thread>
#include <chrono>  

using namespace std;

//function prototypes
void delayScroll(int delayMS, int lineCount);
character* generateEnemy();
void encounterEnemy(character *player, character *enemy);
void fightDecisions(character *player);

void delayScroll(int delayMS, int lineCount) {
	for (int i = 0; i < lineCount; i++) {
		cout << "" << endl;
		this_thread::sleep_for(chrono::milliseconds(delayMS));
	}
}

character* generateEnemy() {
	character *e = new enemy("Umbrella", "A household object that keeps you dry in the rain.");
	e->setStats(1);
	return e;
}

void encounterEnemy(character *player, character *enemy) {
	while (player->isAlive() && enemy->isAlive()) {
		player->fight(enemy);
		enemy->fight(player);
		delayScroll(10, 1);
	}
	fightDecisions(player);
}

void fightDecisions(character *player) {
	if (player->isAlive()) {
		character *anEnemy = generateEnemy();
		int option = 0;
		cout << "You encounter " << anEnemy->name << endl;
		cout << "1. Encounter" << endl;
		cout << "2. Run" << endl;
		cout << ">";
		cin >> option;
		cout << endl;

		if (option == 1)
			encounterEnemy(player, anEnemy);
		else
			cout << "You run away, the game ends." << endl;
	}
	else
		cout << "You lose! Hope you enjoyed playing!" << endl;
}

int main() {
	srand(time(NULL));
	string intro = "BATTLE ADVENTURE";

	cout << intro << endl;

	string playerName;
	string playerDescription;

	cout << "What is your name?" << endl;
	cout << "> ";
	getline(cin, playerName);
	cout << "Describe yourself" << endl;
	cout << "> ";
	getline(cin, playerDescription);
	cout << "Excellent! Let's get started with " << playerName << "'s Adventure!" << endl;
	this_thread::sleep_for(chrono::milliseconds(1000));
	delayScroll(10, 30);

	character *player1 = new player(playerName, playerDescription);
	player1->setStats(4);

	fightDecisions(player1);	
}