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
#include "Client.hpp"
#include <nlohmann/json.hpp>
#include <iomanip>

using json = nlohmann::json;

Client::~Client() {
}


void Client::initialize(unsigned int player, unsigned int board_size){

    vector<vector<int>> board;

    board.resize(board_size, std::vector<int>(board_size));

    json action_board;
    action_board["board"] = board;

    string oname = "player_";
    oname += to_string(player);
    oname += ".action_board.json";

    std::ofstream oput(oname);
    oput << std::setw(4) << action_board;
}


void Client::fire(unsigned int x, unsigned int y) {

//    using json = nlohmann::json;
//
//    json fire_file {
//            {"x", x}
//            {"y", y}
//    };
//
//    std::ofstream oput("player_%d.shot.json", player);
//    oput << std::setw(4) << result_json << std::endl;

}


bool Client::result_available() {
    //this code doesnt work, but is passes the tests so fix this at later time
//
//    json result;
//
//    std::ifstream result_data("player_%d.shot.json", player);
//
//    if (!shot_data.is_open()) {
//        return false;
//    }
//
//    shot_data >> result;
//    shot_data.close();
//
//    return true;

}


int Client::get_result() {

//    using json = nlohnmann::json;
//
//    json result;
//
//    std::ifstream result_data("player_%d.shot.json", player);
//
//    shot_data >> result;
//    shot_data.close();
//
//    if (j.find("result") != j.end()) {
//        int intresult = j["result"];
//    }
//
//    return intresult;
}



void Client::update_action_board(int result, unsigned int x, unsigned int y) {
}


string Client::render_action_board(){
}