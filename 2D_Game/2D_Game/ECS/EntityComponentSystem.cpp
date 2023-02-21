//
//  EntityComponentSystem.cpp
//  2D_Game
//
//  Created by Joshua Patino on 2/8/23.
//

#include "EntityComponentSystem.hpp"


void Entity::addGroup(Group mGroup) {
    groupBitset[mGroup] = true;
    manager.addToGroup(this, mGroup); 
}

