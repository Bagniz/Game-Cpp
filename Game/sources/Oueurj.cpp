//
// Created by netbook on 10/12/2019.
//

#include <iostream>
#include "../headers/Oueurj.h"

Oueurj::Oueurj() : Element(){}

Oueurj::Oueurj(char s, Position &p, Board &b) : Element(s, p, b), teleportations(){}

void Oueurj::teleport()
{

}

void Oueurj::move()
{

}

Oueurj::~Oueurj()
{
    cout << "Oueurj deleted" << endl;
}
