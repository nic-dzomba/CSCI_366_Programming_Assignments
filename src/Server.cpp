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
//    std::ifstream in_file(file, std::ios::binary | std::ios::ate);
//    int file_size = in_file.tellg();
//    return file_size;
}


//public arrays to use for now
char p1array[BOARD_SIZE][BOARD_SIZE];
char p2array[BOARD_SIZE][BOARD_SIZE];


void Server::initialize(unsigned int board_size,
                        string p1_setup_board,
                        string p2_setup_board){

//    std::ifstream p1file(p1_setup_board);
//    std::ifstream p2file(p2_setup_board);
//
//    if (!p1file.is_open()) {
//        throw "player 2 board not found";
//    }
//
//    if (!p2file.is_open()) {
//        throw "player 2 board not found";
//    }
//    std::string str;
//
//    int counter = 0;
//
//    while(std::getline(p1file, str)) {
//        std::cout << str << "\n";
//
//        if (str.length() == board_size) {
//            for (int i = 0; i < sizeof(str); i++)
//                p1array[counter][i] = str[i];
//            counter += 1;
//        } else {
//            throw  "Player 1 Board has an incorrect line";
//        }
//    }
//
//    if (counter != board_size + 1) {
//        throw "Player 1 Board has incorrect length";
//    }
//
//    counter = 0;
//
//    while(std::getline(p2file, str)) {
//        std::cout << str << "\n"
//
//        if (str.length() == board_size) {
//            for (int i = 0; i < sizeof(str); i++)
//                p2array[counter][i] = str[i];
//            counter += 1;
//        } else {
//            throw  "Player 2 Board has an incorrect line";
//        }
//    }
//
//    if (counter != board_size + 1) {
//        throw "Player 2 Board has incorrect length";
//    }

}


int Server::evaluate_shot(unsigned int player, unsigned int x, unsigned int y) {

//    if ((player < 1) || (player > 2)) {
//        throw "player number out of bounds";
//    }
//
//    if ((x > board_size) || (y > board_size)) {
//        return OUT_OF_BOUNDS;
//    }
//
//    if (player == 1) {
//        if (p2array[x][y] == "_") {
//            return MISS;
//        } else {
//            return HIT;
//        }
//    }
//
//    if (player == 2) {
//        if (p1array[x][y] == "_") {
//            return MISS;
//        } else {
//            return HIT;
//        }
//    }

}


int Server::process_shot(unsigned int player) {
//    if ((player < 1) || (player > 2)) {
//        throw "player number out of bounds";
//    }
//
//    using json = nlohmann::json;
//    json j;
//    std::ifstream shot_data("player_%d.shot.json", player);
//
//    if (!shot_data.is_open()) {
//        return NO_SHOT_FILE;
//    }
//
//    shot_data >> j;
//    shot_data.close();
//
//    if (j.find("x") != j.end()) {
//        int x = j["x"];
//    }
//
//    if (j.find("y") != j.end()) {
//        int y = j["y"];
//    }
//
//    int result = evaluate_shot(player, x, y);
//
//    json result_json = {
//            {"result", result}
//    };
//
//    std::ofstream oput("player_%d.result.json", player);
//    oput << std::setw(4) << result_json << std::endl;
//
//    return SHOT_FILE_PROCESSED;
}