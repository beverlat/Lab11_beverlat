#include "StackQueue.h"

#ifndef GAME_H
#define GAME_H
class TowersOfHanoiGame
{
public:
    TowersOfHanoiGame(void);
    // virtual ~TowersOfHanoiGame();
    void PrintTowers();
    bool IsGameEnded();
    bool MoveDisk(int, int, int);
    bool CheckVictory();
    void SaveMove(int, int, int, bool);
    ArrayBasedQueue GetMoveQueue();

private:
	bool m_GameEnded;
	ArrayBasedStack towers[3];
	ArrayBasedQueue moveQueue;
};
#endif