/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacquet <cjacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 13:27:21 by cjacquet          #+#    #+#             */
/*   Updated: 2019/04/02 13:47:54 by cjacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERTER_HPP
# define CONVERTER_HPP

# include <exception>
# include <iostream>

class Converter
{
    public:
        Converter( void );
        Converter( const Converter & inst );
        ~Converter( void );

        Converter    &operator=( const Converter & inst );
};

#endif