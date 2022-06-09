//cpp
#include "tic_tac_toe_manager.h"

std::ostream& operator<<(std::ostream& out, const TicTacToeManager& manager)
{
    for (auto& element:manager.games)
    {
        out<<*element<<"\n";
    }
    out<<"O wins: "<<manager.o_win<<"\n";
    out<<"X wins: "<<manager.x_win<<"\n";
    out<<"Ties: "<<manager.ties<<"\n";
    return out;
}

TicTacToeManager::TicTacToeManager(TicTacToeData& d) : data{d}
{
    games = data.get_games();

    for (auto& game:games)
    {
        update_winner_count(game->get_winner());
    }
}

void TicTacToeManager::save_game(unique_ptr<TicTacToe> &b)
{
    update_winner_count(b->get_winner());
    games.push_back(std::move(b));
}
void TicTacToeManager::get_winner_total(int& o, int& x, int& t)
{   
    o = o_win;
    x = x_win;
    t = ties;
}


void TicTacToeManager::update_winner_count(string winner)
{
    if (winner == "X")
    {
        x_win +=1;
    }
    else if (winner == "O")
    {
        o_win +=1;
    }
    else if (winner == "C")
    {
        ties +=1;
    }
}

TicTacToeManager::~TicTacToeManager()
{
    data.save_games(games);
    cout<<"\nYour game history has been saved.";
}