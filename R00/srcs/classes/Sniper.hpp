#ifndef SNIPER_HPP
# define SNIPER_HPP

# include <cstdlib>
# include <string>
# include "Enemy.hpp"

struct RandomPattern
{
    std::string		icon;
    std::string		pattern;
};

class Sniper : public Enemy
{
    public:
        Sniper(int x, int y);
        Sniper(int x, int y, std::string pattern);
        Sniper( const Sniper & inst );
        ~Sniper( void );

        Sniper    &operator=( const Sniper & inst );

    private:
        Sniper( void );
};

#endif
