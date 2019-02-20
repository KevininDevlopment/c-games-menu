#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

int main(void) {

	srand(static_cast<unsigned int>(time(0)));

	int number = rand() % 100 + 1;
	int num_guess;

	int num_tries = 0;
	char response;

	// Loop to process the game functionality
	while (true) {
		std::cout << "Enter a number between 1 and 100 there are " << 35 - num_tries << " tries left: ";
		std::cin >> num_guess;
		std::cin.ignore();

		if (num_tries >= 35) {
			break;
		}

		if (num_guess > number) {
			std::cout << "Too high! Try again.\n";
		}
		else if (num_guess < number) {
			std::cout << "Too low! Try again.\n";
		}
		else {
			break;
		}
		// increment for wrong answers
		num_tries++;
	}

	// check for exceeded tries
	if (num_tries >= 35) {
		std::cout << "The game has ended. You have " << num_tries << " left!\n\n";
	}
	// end game if won
	else {
		std::cout << "You have beat the game! " << std::endl;
		std::cout << "You got the right number in " << num_tries << " tries!\n";
	}

	// prompt user to play again
	std::cout << "Would you like to play again (Y/N)? ";
	std::cin >> std::setw(1) >> response;
	std::cin.ignore();

	// if yes program restarts
	if (response == 'y' || response == 'Y') {
		return main();
	}
	// if not then leave program
	else {
		std::cout << "\n You did a great job! Goodbye. ";
		return 0;
	}
}