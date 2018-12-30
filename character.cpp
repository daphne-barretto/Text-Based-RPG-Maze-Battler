#include "character.h"

using namespace std;

character::character() : character::character("Default Name", "Default Description") {};//default constructor calls the second constructor

character::character(string enteredName, string enteredDescription) {
	name = enteredName;
	description = enteredDescription;
}

void character::describe() {
	cout << name << " " << description << endl;
}