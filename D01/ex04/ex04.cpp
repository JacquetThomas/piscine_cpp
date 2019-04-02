/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex04.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacquet <cjacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 14:45:06 by cjacquet          #+#    #+#             */
/*   Updated: 2019/03/26 15:08:02 by cjacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(void) {
    std::string     str = "HI THIS IS BRAIN";
    std::string*    strPtr = &str;
    std::string&    strRef = str;

    std::cout << "str : " << str << std::endl;
    std::cout << "pointer : " << *strPtr << std::endl;
    std::cout << "reference : " << strRef << std::endl;
    return (0);
}