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
class Game
{
public:
    Board board;
    vector<Player> players;
    vector<vector<int>> snakes;
    vector<vector<int>> ladders;
    Game(int boardSize, vector<string> playerNames, vector<vector<int>> s, vector<vector<int>> l) : board(boardSize)
    {
        for (int i = 0; i < playerNames.size(); i++)
        {
            players.pb(Player(playerNames[i]));
        }
        snakes = s;
        ladders = l;
        initializeBoard();
    }
    void initializeBoard()
    {
        for (int i = 0; i < snakes.size(); i++)
        {
            board.snakePositions.pb(snakes[i][0]);
            board.snakePositions.pb(snakes[i][1]);
        }
        for (int i = 0; i < snakes.size(); i++)
        {
            board.ladderPositions.pb(ladders[i][0]);
            board.ladderPositions.pb(ladders[i][1]);
        }
    }
    void play()
    {
        while (1)
        {
            for (int i = 0; i < players.size(); i++)
            {
                int roll = players[i].rollDice();
                cout << players[i].name << " rolled a " << roll << "\n";
                board.movePlayer(players[i], roll);
                cout << players[i].name << " is now on square " << players[i].position << "\n";
                if (board.checkWinner(players[i]))
                {
                    return;
                }
            }
        }
    }
};
int main()
{
    vector<string> playerNames = {"Maurya", "Ajit", "Akash"};
    vector<vector<int>> snakes = {{17, 7, 54, 32}};
    vector<vector<int>> ladders = {{1, 5, 8, 9, 13, 37}};
    Game game(100, playerNames, snakes, ladders);
    game.play();
    return 0;
}