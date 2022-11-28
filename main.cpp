// TowerHannoiGame.cpp : Defines the entry point for the console application.
//

#include "StackQueue.h"
#include "TowersOfHanoiGame.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

int main()
{

	cout << "Enter in moves to make for Towers  of  Hannoi" << endl;
	cout << "Progam will exit once towers have  been successfully moved of" << endl;
	cout << "or string of -1 is entered. Moves must be entired in format of" << endl;
	cout << "<disk>,<column from>,<column to>   NOTE no spaces!!!!" << endl;

	TowersOfHanoiGame game;

	bool receivedEndToken = false;

	/*
		Note of change to original program:
		This does NOT stop the game with an invalid input.
		People sometimes mistype. It'd be frustrating if you were almost done with your game
		and lost all of your progress because of a mistype. Instead, it will let you try again.
		For invalid moves (against the rules but still valid input), it will log them in the output as INVALID. 
		For inputs that aren't valid, it will not log, but will still allow the player to keep going.

	*/

	while (!receivedEndToken && !game.IsGameEnded())
	{
		std::string inputLine;
		game.PrintTowers();
		cout << "Enter Move! " << endl;
		getline(cin, inputLine);
		if (inputLine == "-1")
		{
			receivedEndToken = true;
		}
		else
		{
			std::vector<std::string> output;
			std::string::size_type prev_pos = 0, pos = 0;
			// Snippet from https://stackoverflow.com/questions/5167625/splitting-a-c-stdstring-using-tokens-e-g
			// tokenizing a string
			while ((pos = inputLine.find(",", pos)) != std::string::npos)
			{
				std::string substring(inputLine.substr(prev_pos, pos - prev_pos));
				output.push_back(substring);
				prev_pos = ++pos;
			}
			//Need to get last token
			output.push_back(inputLine.substr(prev_pos, pos - prev_pos)); // Last word

			if (output.size() != 3)
			{
				// receivedEndToken = true;
				cout << "Invalid input recieved = " + inputLine << endl;
				continue; // Instead of failing on bad input, game will continue.
			}
			else
			{
				std::string disk = output[0];
				std::string from = output[1];
				std::string to = output[2];

				if (disk.size() == 0 || from.size() == 0 || to.size() == 0)
				{
					// receivedEndToken = true; // I don't believe in having the game end if you mess up input.
					cout << "Invalid input received = " + inputLine << endl;
					continue; // Instead of failing on bad input, game will continue.
				}

				int diskId = atoi(disk.c_str()); 
				int fromId = atoi(from.c_str());
				int toId = atoi(to.c_str());
				//if any number is zero we didn't have a integer
				if (diskId <= 0 || fromId <= 0 || toId <= 0)
				{
					// receivedEndToken = true;
					cout << "Invalid input recieved = " + inputLine << endl;
					continue;
				}
				if (diskId > 4 || fromId > 3 || toId > 3) {
					cout << "Invalid input recieved = " + inputLine << endl;
					continue;
				}

				cout << "Disk " << diskId << " From " << fromId << " To " << toId << endl;

				// Attempt to move disk
				bool moveResult = game.MoveDisk(diskId, fromId, toId);

				if (!moveResult) 
				{
					cout << "Invalid Move!\n";
				}

				// Record move in moveQueue
				game.SaveMove(diskId, fromId, toId, moveResult);

				// Check if we won
				game.CheckVictory();

			}
		}

	}

	if (game.IsGameEnded()) {
		cout << "You win!\n";
	} else if (receivedEndToken) {
		cout << "Game ended.\n";
	}

	// Output printed into file
	// NOTE: This only works if running the program from command line
	ofstream outFile;
	ArrayBasedQueue moveQueue = game.GetMoveQueue();
	outFile.open("move_output.txt");
	while (!moveQueue.isEmpty()) {
		string move = moveQueue.peekFront();
		outFile << move << "\n";
		moveQueue.deQueue();
	}
	outFile.close();

    return 0;
}

