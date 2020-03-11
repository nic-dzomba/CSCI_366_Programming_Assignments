//    Battleship game assignment for MSU CSCI 366
//    Copyright (C) 2020    Mike P. Wittie
//
//    This program is free software: you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation, either version 3 of the License, or
//    (at your option) any later version.
//
//    This program is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.
//
//    You should have received a copy of the GNU General Public License
//    along with this program.  If not, see <https://www.gnu.org/licenses/>.


#include "common.hpp"
#include "Server.hpp"


/**
 * Calculate the length of a file (helper function)
 *
 * @param file - the file whose length we want to query
 * @return length of the file in bytes
 */

//code found from https://codeyarns.com/2018/02/02/how-to-find-size-of-file-in-c/
int get_file_length(ifstream *file){
    std::ifstream in_file(file, std::ios::binary | std::ios::ate);
    int file_size = in_file.tellg();
    return file_size;
}


void Server::initialize(unsigned int board_size,
                        string p1_setup_board,
                        string p2_setup_board){

    std::ifstream p1file(p1_setup_board);
    std::ifstream p2file(p2_setup_board);

    int counter = 0;
    while(std::getline(p1file, str)) {
        std::cout << str << "\n"

        if (str.length() == board_size) {
            counter += 1
        } else {
            throw  "Player 1 Board has an incorrect line"
        }
    }

    if (counter != board_size + 1) {
        throw "Player 1 Board has incorrect length"
    }

    counter = 0;

    while(std::getline(p2file, str)) {
        std::cout << str << "\n"

        if (str.length() == board_size) {
            counter += 1
        } else {
            throw  "Player 2 Board has an incorrect line"
        }
    }

    if (counter != board_size + 1) {
        throw "Player 2 Board has incorrect length"
    }

    



}


int Server::evaluate_shot(unsigned int player, unsigned int x, unsigned int y) {
}


int Server::process_shot(unsigned int player) {
   return NO_SHOT_FILE;
}