//cpp
#include "tic_tac_toe_data.h"

void TicTacToeData::save_games(const std::vector<std::unique_ptr<TicTacToe>>&games)
{
    std::ofstream out_file;
    out_file.open(file_name);

    if(out_file.is_open())
    {
        for(auto& game: games)
        {
            for(auto& move: game->get_pegs())
            {
                out_file<<move;
            }
            out_file<<" "<<game->get_winner()<<"\n";
        }
    }
    out_file.close();
}

std::vector<std::unique_ptr<TicTacToe>> TicTacToeData::get_games()
{
    vector<std::unique_ptr<TicTacToe>> boards;
    std::ifstream in_file;
    in_file.open(file_name);
    string line;

    if(in_file.is_open())
    {
        while (std::getline(in_file, line))
        {
            vector<string> pegs;
            for(size_t i =0; i< (line.size() -1); ++i)
            {
                string game(1, line[i]);
                pegs.push_back(game);
            }
        
            string winner{line.back()};

            std::unique_ptr<TicTacToe> board;

            if (pegs.size() == 9)
            {
                board = std::make_unique<TicTacToe3>(pegs, winner);
            }
            else if (pegs.size() == 16)
            {
                board = std::make_unique<TicTacToe4>(pegs, winner);
            }
            boards.push_back(std::move(board));
        }

    }

    in_file.close();

    return boards;

}