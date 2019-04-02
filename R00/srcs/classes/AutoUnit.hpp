#ifndef AUTO_UNIT_HPP
# define AUTO_UNIT_HPP

# include <cstdlib>
# include <string>
# include "AUnit.hpp"

class AutoUnit : public AUnit
{
	public:
		AutoUnit( int x, int y, const std::string & pattern );
		AutoUnit( const AutoUnit & inst );
		~AutoUnit( void );

		AutoUnit	&operator=( const AutoUnit & inst );

		std::string		get_pattern( void ) const;
		size_t			get_pattern_pos( void ) const;

		virtual void		move( void );

	protected:
		AutoUnit( void );

		std::string _pattern;
		size_t		_pattern_pos;
};

#endif
