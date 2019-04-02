/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacquet <cjacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 15:19:31 by cjacquet          #+#    #+#             */
/*   Updated: 2019/03/27 21:50:44 by cjacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed {

    public:
        Fixed(void);
        Fixed(Fixed const & fixed);
        Fixed(int const number);
        Fixed(float const number);
        ~Fixed(void);

        Fixed & operator=(Fixed const & rhs);
        Fixed   operator+(Fixed const & rhs);
        Fixed & operator++(void);
        Fixed & operator++(int);
        Fixed   operator-(Fixed const & rhs);
        Fixed & operator--(void);
        Fixed & operator--(int);
        Fixed   operator*(Fixed const & rhs);
        Fixed   operator/(Fixed const & rhs);
        bool    operator>(Fixed const & rhs) const;
        bool    operator<(Fixed const & rhs) const;
        bool    operator>=(Fixed const & rhs) const;
        bool    operator<=(Fixed const & rhs) const;
        bool    operator==(Fixed const & rhs) const;
        bool    operator!=(Fixed const & rhs) const;

        static Fixed &         min(Fixed &a, Fixed &b);
        static Fixed const &   min(Fixed const &a, Fixed const &b);
        static Fixed &         max(Fixed &a, Fixed &b);
        static Fixed const &   max(Fixed const &a, Fixed const &b);

        int     getRawBits(void) const;
        void    setRawBits(int const raw);
        int     toInt(void) const;
        float   toFloat(void) const;

    private:
        int _number;
        static int const     frac = 8;

};


std::ostream &  operator<<(std::ostream & o, Fixed const & rhs);

#endif