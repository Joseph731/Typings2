#include <iostream>
#include "type.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

enum Difficulty
{
	easy = 1,
	normal = 2,
	expert = 3,
	master = 4
};

void printDifficulty(Difficulty difficulty);


int main() {

	Type water("Water", { "Fire", "Ground", "Rock" }, { "Water", "Grass", "Dragon" });
	Type flying("Flying", { "Fighting", "Bug", "Grass" }, { "Rock", "Electric", "Steel" });
	Type normaler("Normal", {}, { "Rock", "Steel" }, "Ghost");
	Type grass("Grass", { "Ground", "Rock", "Water" }, { "Flying", "Poison", "Bug", "Steel", "Fire", "Grass", "Dragon" });
	Type bug("Bug", { "Grass", "Psychic", "Dark" }, { "Fighting", "Flying", "Poison", "Ghost", "Steel", "Fire", "Fairy"});
	Type electric("Electric", { "Flying", "Water" }, { "Grass", "Electric", "Dragon" }, "Ground");
	Type psychic("Psychic", { "Fighting", "Poison" }, { "Steel", "Psychic" }, "Dark");
	Type fighting("Fighting", { "Normal", "Rock", "Steel", "Ice", "Dark" }, { "Flying", "Poison", "Bug", "Psychic", "Fairy"}, "Ghost");
	Type poison("Poison", { "Grass" }, { "Rock", "Ground", "Poison", "Ghost" }, "Steel");
	Type fire("Fire", { "Grass", "Ice", "Bug", "Steel" }, { "Fire", "Dragon", "Water", "Rock" });
	Type rock("Rock", { "Flying", "Bug", "Fire", "Ice" }, { "Ground", "Steel", "Fighting" });
	
	/* initialize random seed: */
	srand(static_cast<int>(time(NULL)));


	std::string playAgainInput{};
	while (playAgainInput != "n" && playAgainInput != "no") {

		std::vector<Type> types{ water, flying, normaler, grass, bug, electric, psychic, fighting, poison, fire, rock };

		std::cout << "Welcome to Pokemon Type Master!\n\nENTER YOUR DIFFICULTY:\tEasy: 1  Normal: 2  Expert: 3  MASTER: 4\n";
		Difficulty difficulty{normal};
		
		std::string difficultyInput{};
		while (difficultyInput != "1" && difficultyInput != "2" && difficultyInput != "3" && difficultyInput != "4") {
			std::cin >> difficultyInput;
			if (difficultyInput != "1" && difficultyInput != "2" && difficultyInput != "3" && difficultyInput != "4")
				std::cout << "Input a valid difficulty number.\n";
		}
		difficulty = static_cast<Difficulty>(std::stoi(difficultyInput));
		short lives{};
		switch (difficulty) {
		case easy:
			lives = 20;
			std::cout << "You have entered Easy mode. Starting Lives: " << lives << "\n\n";
			break;
		case normal:
			lives = 10;
			std::cout << "You have entered Normal mode. Starting Lives: " << lives << "\n\n";
			break;
		case expert:
			lives = 5;
			std::cout << "You have entered Expert mode. Starting Lives: " << lives << "\n\n";
			break;
		case master:
			lives = 1;
			std::cout << "You have entered MASTER mode. Starting Lives: " << lives << "\n\n";
			break;

		default:
			difficulty = normal;
			lives = 10;
			std::cout << "You have entered normal mode. Starting Lives: " << lives << "\n\n";
		}

		std::cout << "Answer by entering \"y\" or \"n\" on the keyboard.\n";

		bool gameover{ 0 };
		int score{ 0 };
		while (types.size() > 0 && !gameover) {

			int randomNum{ rand() % static_cast<int>(types.size()) };

			if (types.at(randomNum).getNoEffect() != "") {
				int randomNum2 { static_cast<int>(rand() % 4 + 1) };
				bool yesSolution{ randomNum2 > 1 };
				std::string middleText{};
				if (yesSolution) {
					middleText = types.at(randomNum).getNoEffect();
					types.at(randomNum).setNoEffectToEmpty();
				}
				else
					middleText = types.at(randomNum).getRandomNonNoEffectType();

				std::string input{};
				while (input != "y" && input != "n") {
					std::cout << "Does " << types.at(randomNum).getName() << " have no effect on " << middleText << "? ";
					std::cin >> input;
					if (input != "y" && input != "n")
						std::cout << "Try again. (y/n)\n";
				}
				if (yesSolution) {
					if (input == "y") {
						std::cout << "Correct!\n";
						score += 50;
					}
					else {
						std::cout << "Wrong!\nLives Remaining: " << --lives << '\n';
					}
				}
				else {
					if (input == "n") {
						std::cout << "Correct!\n";
						score += 50;
					}
					else {
						std::cout << "Wrong!\nLives Remaining: " << --lives << '\n';
					}
				}

			}
			else {
				bool superEffectiveQuestion{ static_cast<bool>(rand() % 2) };
				if (superEffectiveQuestion && !types.at(randomNum).superEffectiveSizeIsMoreThanZero()
					|| !superEffectiveQuestion && !types.at(randomNum).notEffectiveSizeIsMoreThanZero()) {
					superEffectiveQuestion = !superEffectiveQuestion;
				}

				bool yesSolution{ static_cast<bool>(rand() % 2) };
				if (!yesSolution && superEffectiveQuestion && !types.at(randomNum).fakeSuperEffectiveSizeIsMoreThanZero()
					|| !yesSolution && !superEffectiveQuestion && !types.at(randomNum).fakeNotEffectiveSizeIsMoreThanZero()) {
					yesSolution = true;
				}

				std::string middleText{};
				std::string againstTypeName{};
				if (superEffectiveQuestion)
				{
					middleText = " super effective";
					if (yesSolution)
					{
						againstTypeName = types.at(randomNum).getAndEraseRandomSuperEffective();

					}
					else
					{
						againstTypeName = types.at(randomNum).getAndEraseRandomFakeSuperEffective();
					}
				}
				else {
					middleText = " not very effective";
					if (yesSolution)
						againstTypeName = types.at(randomNum).getAndEraseRandomNotEffective();
					else
						againstTypeName = types.at(randomNum).getAndEraseRandomFakeNotEffective();
				}

				std::string input{};
				while (input != "y" && input != "n") {
					std::cout << "Is " << types.at(randomNum).getName() << middleText << " against " << againstTypeName << "? ";
					std::cin >> input;
					if (input != "y" && input != "n")
						std::cout << "Try again. (y/n)\n";
				}
				if (yesSolution) {
					if (input == "y") {
						std::cout << "Correct!\n";
						score += 100;
					}
					else {
						std::cout << "Wrong!\nLives Remaining: " << --lives << '\n';
					}
				}
				else {
					if (input == "n") {
						std::cout << "Correct!\n";
						score += 50;
					}
					else {
						std::cout << "Wrong!\nLives Remaining: " << --lives << '\n';
					}
				}

				if (!types.at(randomNum).superEffectiveSizeIsMoreThanZero() && !types.at(randomNum).notEffectiveSizeIsMoreThanZero()) {
					types.erase(types.begin() + randomNum);
				}
			}

			if (lives < 1)
				gameover = true;
		}

		if (gameover) {
			std::cout << "\nGAMEOVER\n";
			printDifficulty(difficulty);
			std::cout << "Score: " << score << "\n\n";
		}
		else {
			std::cout << "Finished!\n\n";
			printDifficulty(difficulty);
			std::cout << "Score: " << score << '\n';
			if (difficulty == 4) {
				std::cout << "You did it! You are a Pokemon Master!!!\n\n";
			}
			else
				std::cout << "You are a winner! Congratulations!\n\n";
		}

		
		std::cout << "Play again? (y/n) ";
		std::cin >> playAgainInput;
		if (playAgainInput != "n" && playAgainInput != "no")
			std::cout << "\n\n\n";
	}
	return 0;
}

void printDifficulty(Difficulty difficulty) {
	switch (difficulty) {
	case easy:
		std::cout << "Easy Mode\n";
		break;
	case normal:
		std::cout << "Normal Mode\n";
		break;
	case expert:
		std::cout << "Expert Mode\n";
		break;
	case master:
		std::cout << "MASTER Mode\n";
		break;
	}
}
