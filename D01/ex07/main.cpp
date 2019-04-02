/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacquet <cjacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 12:12:35 by cjacquet          #+#    #+#             */
/*   Updated: 2019/03/29 15:50:53 by cjacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

int main(int argc, char **argv) {
    std::string str;
    std::string buff;
    std::string replacefile;
    std::string search;
    std::string replace;
    std::string::size_type found_at;

     if (argc != 4) {
        std::cout << "Usage : [Filemane] [search] [replace]" << std::endl;
        return (1);
    }

    replacefile = argv[1];
    search = argv[2];
    replace = argv[3];

    if (replacefile.empty() || search.empty() || replace.empty()) {
        std::cout << "Usage : [Filemane] [search] [replace]" << std::endl;
        std::cout << "No \"\" or space charactere allowed" << std::endl; 
        return (1);
    }

    std::ifstream   ifs(replacefile);
    if (ifs.fail()) {
    std::cout << "Error at opening file : [" << replacefile << "]" << std::endl;
        return (1);
    }
    std::ofstream   ofs(replacefile.append(".replace"));  
    while (std::getline(ifs, buff)) {
        str.append(buff);
        str.append("\n");
    }

    found_at = str.find(search);
    while (std::string::npos != found_at) {
        str.replace(found_at, search.length(), replace);
		found_at = str.find(search, found_at + replace.length());
    }
    ofs << str << std::endl;
    return (0);
}