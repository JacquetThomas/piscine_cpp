#include "Sniper.hpp"

Sniper::Sniper(int x, int y) :
    Enemy(x, y, "v>v>v<v<v")
{
    RandomPattern		patterns[] = {
		{"Y", "v>v>v<v<v"},
		{"T", "vvv>^<v"},
		{"W", ">v>v>v>v>v>v<v<v<v<v"},
		{"¯\\_(*)_/¯", "vvvvv^^^^^^^^^^"},
    };
    RandomPattern		pattern;

	pattern = patterns[rand() % (sizeof(patterns) / sizeof(patterns[0]))];

    _icon = pattern.icon;
    _pattern = pattern.pattern;
    return ;
}

Sniper::Sniper(int x, int y, std::string pattern) : Enemy(x, y, pattern) {
    return ;
}

Sniper::Sniper( const Sniper & inst ) : Enemy( inst )
{
    *this = inst;
    return ;
}

Sniper::~Sniper( void )
{
    return ;
}

Sniper    &    Sniper::operator=( const Sniper & lhs )
{
    Enemy::operator=( lhs );
    return *this;
}
