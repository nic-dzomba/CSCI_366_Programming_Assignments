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
#include <fstream>
#include <iomanip>
#include <cereal/archives/json.hpp>


/**
 * Calculate the length of a file (helper function)
 *
 * @param file - the file whose length we want to query
 * @return length of the file in bytes
 */

//code found from https://codeyarns.com/2018/02/02/how-to-find-size-of-file-in-c/
int get_file_length(ifstream *file){
    file->seekg(0, std::ios::end);
    int file_size = file->tellg();
    return file_size;
}


//public arrays to use for now
char p1array[BOARD_SIZE][BOARD_SIZE];
char p2array[BOARD_SIZE][BOARD_SIZE];


class json;

void Server::initialize(unsigned int board_size,
                        string p1_setup_board,
                        string p2_setup_board){

    Server::board_size = board_size;

    std::ifstream p1file(p1_setup_board);
    std::ifstream p2file(p2_setup_board);

    if (!p1file.is_open()) {
        throw "player 2 board not found";
    }

    if (!p2file.is_open()) {
        throw "player 2 board not found";
    }
    std::string str;

    int counter = 0;

    while(std::getline(p1file, str)) {
        std::cout << str << "\n";

        if (str.length() == board_size) {
            for (int i = 0; i < sizeof(str); i++)
                p1array[counter][i] = str[i];
            counter += 1;
        } else {
            throw  "Player 1 Board has an incorrect line";
        }
    }

    if (counter != board_size ) {
        throw "Player 1 Board has incorrect length";
    }

    counter = 0;

    while(std::getline(p2file, str)) {
        if (str.length() == board_size) {
            for (int i = 0; i < sizeof(str); i++)
                p2array[counter][i] = str[i];
            counter += 1;
        } else {
            throw  "Player 2 Board has an incorrect line";
        }
    }

    if (counter != board_size ) {
        throw "Player 2 Board has incorrect length";
    }

}


int Server::evaluate_shot(unsigned int player, unsigned int x, unsigned int y) {

    if ((player < 1) || (player > 2)) {
        throw "player number out of bounds";
    }

    if ((x > (BOARD_SIZE - 1)) || (y > (BOARD_SIZE - 1))) {
        return OUT_OF_BOUNDS;
    }

    if (player == 1) {
        if (p2array[x][y] == '_') {
            return MISS;
        } else {
            return HIT;
        }
    }

    if (player == 2) {
        if (p1array[x][y] == '_') {
            return MISS;
        } else {
            return HIT;
        }
    }

}


int Server::process_shot(unsigned int player) {

    if ((player < 1) || (player > 2)) {
        throw "player number out of bounds";
    }

    char buffer [50];
    sprintf(buffer, "player_%d.fire.json", player);
    std::ifstream inp(buffer);

    std::string str2;


    int counter = 0;

    int x;
    int y;
    while(std::getline(inp, str2)) {
        if (counter == 1) {
            int x = str2.at(9);
            counter += 1;
        } else if (counter == 2) {
            int y = str2.at(9);
            counter += 1;
        } else {
            counter += 1;
        }
    }

    printf("x: %d, y: %d\n", x, y);



    int result = evaluate_shot(player, x, y);


    return SHOT_FILE_PROCESSED;
}