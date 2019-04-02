/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacquet <cjacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 12:31:58 by cjacquet          #+#    #+#             */
/*   Updated: 2019/04/02 12:36:51 by cjacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char **argv) {
    
    
    if (argc != 2) {
        std::cout << "Usage : ./convert [literal value to convert]" << std::endl;
        return (1);
    }
 //   std::cout << "argument : " << argv[1] << std::endl;


    return (0);
}