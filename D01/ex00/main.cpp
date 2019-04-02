/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacquet <cjacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 10:08:51 by cjacquet          #+#    #+#             */
/*   Updated: 2019/03/26 10:58:32 by cjacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pony.hpp"

void    ponyOnTheStack() {
    Pony    stack;

    stack.setName("Stacky");
    stack.setColor("Brown");
    stack.printInfo();
}

void    ponyOnTheHeap() {
    Pony*   heap = new Pony("Heapy");

    heap->setColor("white");
    heap->printInfo();
    delete heap;
}

int     main(void) {
    std::cout << "--- Go on the stack ---" << std::endl;
    ponyOnTheStack();
    std::cout << "--- Go on the heap ---" << std::endl;
    ponyOnTheHeap();
    return (0);
}