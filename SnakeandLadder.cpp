#include <bits/stdc++.h>
using namespace std;
#define pb push_back
using vi = vector<int>;
class Player
{
public:
    string name;
    int position;
    int moves;
    Player(string PlayerName)
    {
        name = PlayerName;
        position = 0;
        moves = 0;
    }
    int rollDice()
    {
        static std::random_device rd;
        static std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(1, 6);
        return dis(gen);
    }
    void move(int spaces)
    {
        position += spaces;
        moves++;
    }
};
class Board
{
public:
    int size;
    vi playerPositions, snakePositions, ladderPositions;
    Board(int sz)
    {
        size = sz;
    }
    void movePlayer(Player &p, int roll)
    {
        int newpos = p.position + roll;
        if (newpos > size)
        {
            return;
        }
        for (int i = 0; i < ladderPositions.size(); i += 2)
        {
            if (ladderPositions[i] == newpos)
            {
                newpos = ladderPositions[i + 1];
                break;
            }
        }
        for (int i = 0; i < snakePositions.size(); i += 2)
        {
            if (newpos == snakePositions[i])
            {
                newpos = snakePositions[i + 1];
                break;
            }
        }
        p.position = newpos;
    }
    bool checkWinner(Player &p)
    {
        if (p.position == size)
        {
            cout << "CONGRATULATIONS\n";
            cout << "Player " << p.name << " has won the Game \n";
            return 1;
        }
        return 0;
    }
};

int main()
{
    vector<string> playerNames = {"Maurya", "Ajit", "Akash"};
    vector<vector<int>> snakes = {{17, 7, 54, 32}};
    vector<vector<int>> ladders = {{1, 5, 8, 9, 13, 37}};
   
    return 0;
}