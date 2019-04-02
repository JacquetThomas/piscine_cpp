#include "Enemy.hpp"
#include <iostream>
#include <ncurses.h>

Enemy::Enemy(int x, int y) : AutoUnit(x, y, "v>v<") {
    this->_icon = "V";
    this->_enemy = true;
    return ;
}

Enemy::Enemy(int x, int y, std::string pattern) : AutoUnit(x, y, pattern) {
    this->_icon = "V";
    this->_enemy = true;
    return ;
}

Enemy::Enemy( const Enemy & inst ) : AutoUnit( inst )
{
    this->_icon = "V";
    this->_enemy = inst.is_enemy();
    *this = inst;
    return ;
}

Enemy::~Enemy( void )
{
    return ;
}

void    Enemy::print( WINDOW * win ) const
{
    mvwaddstr(win, _posY, _posX, _icon.c_str());
}

Enemy    &    Enemy::operator=( const Enemy & lhs )
{
    AutoUnit::operator=( lhs );
    _icon = lhs._icon;
    _enemy = lhs._enemy;
    return *this;
}
