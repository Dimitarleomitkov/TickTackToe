#include <iostream>

using namespace std;

bool win_check(char *squares, bool player);
void draw_gamespace(char *squares);
void game();

int player1Score = 0;
int player2Score = 0;

int main()
{
    while (player1Score < 3 && player2Score < 3){
        cout << "Player 1 " << player1Score << ":" << player2Score << " Player 2" << endl;
        game();
    }
    if (player1Score == 3)
    {
        cout << "Player 1 is VICTORIOUS!!!" << endl;
    }
    else
    {
        cout << "Player 2 is VICTORIOUS!!!" << endl;
    }
    return 0;
}

void game()
{
    char squares[9];
    bool player_turns = 0;
    char square;

    for (int i = 0; i < 9; ++i)
    {
        squares[i] = '0';
    }

    do
    {
        draw_gamespace(squares);
        if (player_turns == 0)
        {
            square = 'a';
            while (square - '0' >= 10)
            {
                cout << "Player 1's Turn:";
                cin >> square;
                if (squares[square - '0' - 1] == '1' || squares[square - '0' - 1] == '2')
                {
                    square = 'a';
                }
            }
            player_turns = 1;
            squares[square - '0' - 1] = '1';
        }
        else
        {
            square = 'a';
            while (square - '0' >= 10)
            {
                cout << "Player 2's Turn:";
                cin >> square;
                if (squares[square - '0' - 1] == '1' || squares[square - '0' - 1] == '2')
                {
                    square = 'a';
                }
            }
            player_turns = 0;
            squares[square - '0' - 1] = '2';
        }
    }while(!win_check(squares, player_turns));
}

bool win_check(char *squares, bool player)
{
    if (player == 1)
    {
        if ((squares[0] == '1' && squares[1] == '1' && squares[2] == '1') ||
            (squares[3] == '1' && squares[4] == '1' && squares[5] == '1') ||
            (squares[6] == '1' && squares[7] == '1' && squares[8] == '1') ||
            (squares[0] == '1' && squares[3] == '1' && squares[6] == '1') ||
            (squares[1] == '1' && squares[4] == '1' && squares[7] == '1') ||
            (squares[2] == '1' && squares[5] == '1' && squares[8] == '1') ||
            (squares[0] == '1' && squares[4] == '1' && squares[8] == '1') ||
            (squares[2] == '1' && squares[4] == '1' && squares[6] == '1'))
        {
            cout << "Player 1 won!\nCongratulations!\n";
            draw_gamespace(squares);
            ++player1Score;
            return true;
        }
        else
        {
            if (squares[0] != '0' && squares[1] != '0' && squares[2] != '0' &&
                squares[3] != '0' && squares[4] != '0' && squares[5] != '0' &&
                squares[6] != '0' && squares[7] != '0' && squares[8] != '0')
            {
                cout << "DRAW!\n";
                draw_gamespace(squares);
                return true;
            }
            return false;
        }
    }
    else
    {
        if ((squares[0] == '2' && squares[1] == '2' && squares[2] == '2') ||
            (squares[3] == '2' && squares[4] == '2' && squares[5] == '2') ||
            (squares[6] == '2' && squares[7] == '2' && squares[8] == '2') ||
            (squares[0] == '2' && squares[3] == '2' && squares[6] == '2') ||
            (squares[1] == '2' && squares[4] == '2' && squares[7] == '2') ||
            (squares[2] == '2' && squares[5] == '2' && squares[8] == '2') ||
            (squares[0] == '2' && squares[4] == '2' && squares[8] == '2') ||
            (squares[2] == '2' && squares[4] == '2' && squares[6] == '2'))
        {
            cout << "Player 2 won!\nCongratulations!\n";
            draw_gamespace(squares);
            ++player2Score;
            return true;
        }
        else
        {
            if (squares[0] != '0' && squares[1] != '0' && squares[2] != '0' &&
                squares[3] != '0' && squares[4] != '0' && squares[5] != '0' &&
                squares[6] != '0' && squares[7] != '0' && squares[8] != '0')
            {
                cout << "DRAW!\n";
                draw_gamespace(squares);
                return true;
            }
            return false;
        }
    }
}

void draw_gamespace(char *squares)
{
    cout << "Game Space:\tInstructions:" << endl;
    for(int i = 0; i < 6; ++i)
    {
        cout << "_";
    }
    cout << "\t\t";
    for(int i = 0; i < 6; ++i)
    {
        cout << "_";
    }
    cout << endl << "|";

    for(int i = 0; i < 3; ++i)
    {
        if(squares[i] == '0')
        {
            cout << " ";
        }
        else if(squares[i] == '1')
        {
            cout << "X";
        }
        else if(squares[i] == '2')
        {
            cout << "O";
        }
        cout << "|";
    }
    cout << "\t\t|";
    for(int i = 0; i < 3; ++i)
    {
        cout << i + 1 << "|";
    }
    cout << endl << "|";

    for(int i = 0; i < 3; ++i)
    {
        if(squares[i + 3] == '0')
        {
            cout << " ";
        }
        else if(squares[i + 3] == '1')
        {
            cout << "X";
        }
        else if(squares[i + 3] == '2')
        {
            cout << "O";
        }
        cout << "|";
    }
    cout << "\t\t|";
    for(int i = 0; i < 3; ++i)
    {
        cout << i + 4 << "|";
    }
    cout << endl << "|";

    for(int i = 0; i < 3; ++i)
    {
        if(squares[i + 6] == '0')
        {
            cout << " ";
        }
        else if(squares[i + 6] == '1')
        {
            cout << "X";
        }
        else if(squares[i + 6] == '2')
        {
            cout << "O";
        }
        cout << "|";
    }
    cout << "\t\t|";
    for(int i = 0; i < 3; ++i)
    {
        cout << i + 7 << "|";
    }
    cout << endl;
    char symbol = 45;
    for (int i = 0; i < 7; ++i)
    {
        cout << symbol;
    }
    cout << "\t\t";
    for (int i = 0; i < 7; ++i)
    {
        cout << symbol;
    }
    cout << endl;
}
