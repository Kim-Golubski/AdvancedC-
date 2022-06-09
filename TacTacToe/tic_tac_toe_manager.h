//h
#ifndef TIC_TAC_TOE_MANAGER
#define TIC_TAC_TOE_MANAGER

#include "tic_tac_toe.h"
#include "tic_tac_toe_data.h"

#include<vector>
#include<iostream>

#include<memory>
using std::unique_ptr; using std::make_unique;


class TicTacToeManager
{

friend std::ostream& operator<<(std::ostream& out, const TicTacToeManager& manager);

public:
TicTacToeManager() = default;
TicTacToeManager(TicTacToeData& data);

void save_game(unique_ptr<TicTacToe> &b);
void get_winner_total(int& o, int& x, int& t);
~TicTacToeManager();

private:

vector<unique_ptr<TicTacToe>>games;
int x_win =0;
int o_win=0;
int ties=0;
TicTacToeData data;

void update_winner_count(string winner);

};




#endif