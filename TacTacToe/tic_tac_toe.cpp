//cpp
#include "tic_tac_toe.h"

std::istream& operator>>(std::istream& in, TicTacToe& game)
{
    int position;
    if (game.pegs.size() == 9)
    {
        do
        {
            cout<<"Choose 1-9 for your board position: ";
            in>>position;
        } while (!(position >= 1 && position <= 9));
        game.mark_board(position);
        return in;
    }
    else if (game.pegs.size() == 16)
    {
        do
        {
            cout<<"Choose 1-16 for your board position: ";
            in>>position;
        } while (!(position >=1 && position <=16));        
        game.mark_board(position);
        return in;
    }
    
}
std::ostream& operator<<(std::ostream& out, const TicTacToe& game)
{
    if (game.pegs.size() == 9)
    {
        out<<game.pegs[0]<<"|"<<game.pegs[1]<<"|"<<game.pegs[2]<<"\n";
        out<<game.pegs[3]<<"|"<<game.pegs[4]<<"|"<<game.pegs[5]<<"\n";
        out<<game.pegs[6]<<"|"<<game.pegs[7]<<"|"<<game.pegs[8]<<"\n";
        return out;
    }
    else if (game.pegs.size() == 16)
    {
        out<<game.pegs[0]<<"|"<<game.pegs[1]<<"|"<<game.pegs[2]<<"|"<<game.pegs[3]<<"\n";
        out<<game.pegs[4]<<"|"<<game.pegs[5]<<"|"<<game.pegs[6]<<"|"<<game.pegs[7]<<"\n";
        out<<game.pegs[8]<<"|"<<game.pegs[9]<<"|"<<game.pegs[10]<<"|"<<game.pegs[11]<<"\n";
        out<<game.pegs[12]<<"|"<<game.pegs[13]<<"|"<<game.pegs[14]<<"|"<<game.pegs[15]<<"\n";
        return out;
    }
    
}

bool TicTacToe::game_over()
{
    if (check_column_win() == true)
    {
        set_winner();
        return true;
    }
    if (check_row_win() == true)
    {
        set_winner();
        return true;
    }
    if (check_diagonal_win() == true)
    {
        set_winner();
        return true;
    }
    if (check_board_full() == true)
    {
        winner = "C";
        return true;
    }  
    return false;
}
void TicTacToe::start_game(string first_player)
{
    first_player == "X" || first_player =="O";
    player = first_player;
    clear_board();

}
void TicTacToe::mark_board(int position)
{
    pegs[position-1] = player;
    if (game_over() == false)
    {
        set_next_player();
    }
    
}
string TicTacToe::get_player()const
{
    return player;
}
string TicTacToe::get_winner()
{
    return winner;
}
vector<string> TicTacToe::get_pegs()const
{
    return pegs;
}


void TicTacToe::set_next_player()
{
    if (player == "O")
    {
        player = "X";
    }
    else (player = "O");
}
bool TicTacToe::check_board_full()
{
    for (string n : pegs)
    {
        if (n == " ")
        {
            return false;
        }  
    }
    return true; 
}
void TicTacToe::clear_board()
{
    for (string& n : pegs)
        {
            n = " ";
        }
}
bool  TicTacToe::check_column_win()
{
    
    return false;    
}
bool TicTacToe::check_row_win()
{
    return false;
}
bool TicTacToe::check_diagonal_win()
{
    return false;
}
void TicTacToe::set_winner()
{
    if (player == "X")
    {
        winner = "X";
    }
    else (winner = "O");    
}