#include <iostream>
#include <string>
#include <ctime>

using namespace std;

enum enActions { Rock = 1, Paper = 2, Scissors = 3 };
enum enResult { Win, Lose, Draw };

int RandomNumber(int From, int To)
{

	int randNum = rand() % (To - From + 1) + From;
	return randNum;
}

int ReadPositiveNumberFromTo(string Message, int From, int To)
{
	int Num;

	do {
		cout << Message << endl;
		cin >> Num;

		if (Num < From || Num > To)
			cout << "Wrong number!\n\n";

	} while (Num < From || Num > To);

	return Num;
}

enResult ResultOfRound(enActions PlayerChoice, enActions ComputerChoice)
{
	if (PlayerChoice == ComputerChoice)
	{
		return enResult::Draw;
	}
	else if (PlayerChoice == enActions::Paper && ComputerChoice == enActions::Rock
		|| PlayerChoice == enActions::Rock && ComputerChoice == enActions::Scissors
		|| PlayerChoice == enActions::Scissors && ComputerChoice == enActions::Paper)
	{
		return enResult::Win;
	}
	else
	{
		return enResult::Lose;
	}
}

void GamePlay(int RoundsNumber, int& Win, int& Lose, int& Draw)
{
	string Actions[3] = { "Rock","Paper","Scissors" };

	for (int i = 1; i <= RoundsNumber; i++)
	{
		cout << "\n-------------------------Round[" << i << "]-------------------------\n";
		enActions PlayerChoice = enActions(ReadPositiveNumberFromTo("Choice your action [ Rock = 1, Paper = 2, Scissors = 3 ]?", 1, 3));
		enActions ComputerChoice = enActions(RandomNumber(1, 3));
		enResult RoundResult = ResultOfRound(PlayerChoice, ComputerChoice);

		cout << "You chose " << Actions[PlayerChoice - 1] << endl;
		cout << "computer choice " << Actions[ComputerChoice - 1] << endl;

		if (RoundResult == enResult::Draw)
		{
			cout << "Draw\n";
			system("color 6F");

			Draw++;
		}
		else if (RoundResult == enResult::Win)
		{
			cout << "You win\n";
			system("color 2F");

			Win++;
		}
		else
		{
			cout << "Computer win\a\n";
			system("color 4F");

			Lose++;
		}
		cout << "----------------------------------------------------------\n";

	}
}

int FinalResult(int RoundsNumber, int Win, int Lose, int Draw)
{
	int PlayAgain;

	cout << "\n\t\t----------------------------------------\n";
	cout << "\t\t\t*** G A M E  O V E R ***\n";
	cout << "\t\t----------------------------------------\n";
	cout << "\t\t\tGame rounds: " << RoundsNumber;
	cout << "\n\t\t\tWin: " << Win << endl;
	cout << "\t\t\tLose: " << Lose << endl;
	cout << "\t\t\tDraw: " << Draw << endl;
	if (Win > Lose)
		cout << "\t\t\tFinal result: You win\n";
	else if (Lose > Win)
		cout << "\t\t\tFinal result: Computer win\n";
	else
		cout << "\t\t\tFinal result: Draw\n";
	cout << "\t\t----------------------------------------\n";

	cout << "\n\t\t\tPlay again? [Yes = 1, No = 0]\n";
	cin >> PlayAgain;

	return PlayAgain;
}

int main()
{
	srand((unsigned)time(NULL));

	int x;

	do {
		int RoundsNumber, Win = 0, Lose = 0, Draw = 0;
		RoundsNumber = ReadPositiveNumberFromTo("How many rounds the game will be?", 1, 10);

		GamePlay(RoundsNumber, Win, Lose, Draw);

		x = FinalResult(RoundsNumber, Win, Lose, Draw);
	} while (x == 1);

	return 0;
}