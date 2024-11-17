#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <mariadb/conncpp.hpp>
#include <chrono>
#include <thread>

#define HEADER_H

using namespace std;
using namespace sql;
//using namespace std::this_thread; 
//using namespace std::chrono;

struct Chambres {
    string nom;
    string prenom;
    int numero;
    bool reserv;
    bool occupy;
};

void getData(const unique_ptr<Connection>& conn);
void AfficherDonnees(const unique_ptr<Connection>& conn);
void getMenu(const unique_ptr<Connection>& conn);
void doReserv(const unique_ptr<Connection>& conn);
void undoReserv(const unique_ptr<Connection>& conn);
void confirmReserv(const unique_ptr<Connection>& conn);
void ModifyReserv(const unique_ptr<Connection>& conn);
void occup(const unique_ptr<Connection>& conn);
void out(const unique_ptr<Connection>& conn);
void leaveMenu(const unique_ptr<Connection>& conn);
void getData(const unique_ptr<Connection>& conn);