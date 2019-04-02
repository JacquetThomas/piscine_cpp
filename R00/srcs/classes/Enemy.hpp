#ifndef ENEMY_HPP
# define ENEMY_HPP

# include <cstdlib>
# include <string>
# include "AutoUnit.hpp"

class Enemy : public AutoUnit
{
    public:
        Enemy(int x, int y);
        Enemy(int x, int y, std::string pattern);
        Enemy( const Enemy & inst );
        ~Enemy( void );

        Enemy    &operator=( const Enemy & inst );
        void        print ( WINDOW * win ) const;

    protected:
        std::string     _icon;

    private:
        Enemy( void );
};

#endif
