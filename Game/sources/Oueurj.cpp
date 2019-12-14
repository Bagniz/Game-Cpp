//
// Created by netbook on 10/12/2019.
//

#include <iostream>
#include "../headers/Oueurj.h"

Oueurj::Oueurj() : Element(){}

Oueurj::Oueurj(Position &p, Board &b) : Element('j', p, b), teleportations(){}

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
