#include "functions.h"


int main(void) {

	int choice;

	do
	{
		cout << "\nGAME MENU\n";
		cout << "0 - Exit the program.\n";
		cout << "1 - Dark Dungeon\n";
		cout << "2 - Tic-Tac-Toe\n";
		cout << "3 - Mind Reader\n";
		cout << "4 - Word Jumble\n";
		cout << "5 - Critter Time!\n";
		cout << "6 - Hang-Man\n";
		cout << "7 - Black-Jack\n";
		cout << endl << "Enter choice: ";
		cin >> choice;

		switch (choice)
		{
		case 0: cout << "Good-bye.\n"; break;
		case 1: dungeon_func(); break;
		case 2: tic_tac_toe(); break;
		case 3: hello(); break;
		case 4: jumble(); break;
		case 5: critt(); break;
		case 6: hang(); break;
		case 7: blackj(); break;
		default: cout << "That was not a valid choice.\n";
		}
	} while (choice != 0);

	return 0;
}
