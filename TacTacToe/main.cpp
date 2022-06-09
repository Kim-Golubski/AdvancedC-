#include "tic_tac_toe.h"
#include "tic_tac_toe_manager.h"
#include "tic_tac_toe_3.h"
#include "tic_tac_toe_4.h"
#include "tic_tac_toe_data.h"
#include<iostream>
using std::cout; using std::cin;

int main() 
{
	unique_ptr<TicTacToe>game;
	TicTacToeData data;
	TicTacToeManager manage = TicTacToeManager(data);
	string letter;
	char choice = 'y';
	int X = 0;
	int O = 0;
	int Ties = 0;
	int type;
	

	while (choice == 'y')
	{	
		do
		{		
			cout<<"Would you like to play TicTacToe 3 or TicTacToe 4? ";
			cin>>type;
			if (type == 3)
			{
				game = make_unique<TicTacToe3>();
			}
			else if (type == 4)
			{
				game = make_unique<TicTacToe4>();
			}
		}
		while (!(type ==3 || type == 4));
		
		do
		{
			cout<<"Choese X or O: ";
			cin>>letter;
			if (letter == "x")
			{
				letter = "X";
			}
			else if (letter == "o")
			{
				letter = "O";
			}
		} 
		while (!(letter == "X" || letter == "O"));

		game->start_game(letter);
		
		do
		{
			
			cin>>*game;
			cout<<*game;
		}
		while (game->game_over() == false);

		
		cout<<"Game Over! "<<game->get_winner()<<" is the winner! "<<"\n";
		manage.save_game(game);		
		manage.get_winner_total(O, X, Ties);	
		cout<<"Enter Y to play again: ";
		cin>>choice;
	}
	cout<<"Here is your game summary:"<<"\n"<<manage;
		
	return 0;
}
