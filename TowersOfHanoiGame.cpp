#include "TowersOfHanoiGame.h"
#include <string>
#include <iostream>

TowersOfHanoiGame::TowersOfHanoiGame() : m_GameEnded(false)
{
	towers[0] = ArrayBasedStack();
	towers[1] = ArrayBasedStack();
	towers[2] = ArrayBasedStack();
	towers[0].push(4);
	towers[0].push(3);
	towers[0].push(2);
	towers[0].push(1);
}

/*
	Getter for m_GameEnded bool.
*/
bool TowersOfHanoiGame::IsGameEnded() { return m_GameEnded; }

/*
	Prints the current state of the towers.
*/
void TowersOfHanoiGame::PrintTowers()
{
	for (int i = 1; i <= 3; i++) 
	{
		std::cout << "Tower " << i << ": " + towers[i-1].toString() + "\n";
	}
}

/*
	Moves a disk in format <disk> <tower from which to pull> <tower to place disk on>
	Returns true if it successfully moves the disk, and false if it does not.
	Will also record the move via 
*/
bool TowersOfHanoiGame::MoveDisk(int disk, int fromTower, int toTower) 
{
	// We want to the user to have 1,2,3 but indeces start at 0. We need to convert.
	--fromTower;
	--toTower;

	// If the tower we're pulling from has no disks, we can't move one from it.
	if (towers[fromTower].isEmpty() || fromTower == toTower) return false;
	
	int topFrom = towers[fromTower].peek();

	// We should only peek if the tower is not empty
	int topTo = 100; // Set to arbitrarily large number above any disk values
	if (!towers[toTower].isEmpty()) 
		topTo = towers[toTower].peek();
	// Check if the user is moving the disk they want to 
	// and that it is not bigger than the top disk on the tower
	if (disk != topFrom || disk > topTo) return false;
	towers[toTower].push(topFrom);
	towers[fromTower].pop();

	return true;
}

/*
	Checks if the game meets the victory condition.
	Returns true if it does, false if not
*/
bool TowersOfHanoiGame::CheckVictory() 
{
	// If the third tower meets the requirements, set the game to end.
	if (towers[2].toString() == "4 3 2 1") 
		m_GameEnded = true;
	
	return m_GameEnded;
}

/*
	Saves a move to the moveQueue. 
*/
void TowersOfHanoiGame::SaveMove(int disk, int from, int to, bool isValid) 
{
	std::string move = std::to_string(disk) + ","+ std::to_string(from) + "," + std::to_string(to);
	// If the move didn't work, we add a marker indicating that to the file output.
	if (!isValid)
		move.append(" <- INVALID");

	bool success = moveQueue.enQueue(move);
	if (!success) 
		throw "Move limit exceeded.";

}

/*
	MoveQueue getter.
*/
ArrayBasedQueue TowersOfHanoiGame::GetMoveQueue() {
	return std::move(moveQueue);
}