/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacquet <cjacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 11:12:41 by cjacquet          #+#    #+#             */
/*   Updated: 2019/03/26 09:49:42 by cjacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

Phonebook::Phonebook(void) {
    this->contact_idx = 0;
}

Phonebook::~Phonebook(void) {}

void    Phonebook::setContactIdx(int idx) {
    this->contact_idx = idx;
}

int     Phonebook::getContactIdx(void) {
    return (this->contact_idx);
}

void    Phonebook::addContact(void) {
    if (this->contact_idx >= MAX_CONTACTS) {
        std::cout << "Sorry bro, no more space available" << std::endl;
        return ;
    }
    this->contact_list[this->contact_idx].fillFields();
    this->contact_idx += 1;

    std::cout << "Contact succesfully added !" << std::endl;
}

/**
 * You should check value of idx before call this method 
 */
Contact Phonebook::getContact(int idx) {
        return (contact_list[idx]);
}

std::string Phonebook::toFit(std::string str) {
    if (str.size() > 10) {
        str.resize(WIDTH - 1);
        str.append(".");
    }
    return (str);
}

void    Phonebook::printContacts(int idx) {
    Contact tmp;
    std::string firstname;
    std::string lastname;
    std::string nickname;

    tmp = this->getContact(idx);
    firstname = tmp.getFirstName();
    lastname = tmp.getLastName();
    nickname = tmp.getNickname();
    std::cout << std::setfill (' ');
    std::cout << std::setw(WIDTH) << idx << "|";
    std::cout << std::setw(WIDTH) << toFit(firstname) << "|";
    std::cout << std::setw(WIDTH) << toFit(lastname) << "|";
    std::cout << std::setw(WIDTH) << toFit(nickname) << std::endl;
}

void Phonebook::printContact(int idx) {
    Contact tmp;

    tmp = this->getContact(idx);
    std::cout << tmp.getFirstName() << std::endl;
    std::cout << tmp.getLastName() << std::endl;
    std::cout << tmp.getNickname() << std::endl;
    std::cout << tmp.getLogin() << std::endl;
    std::cout << tmp.getPostalAddress() << std::endl;
    std::cout << tmp.getEmailAddress() << std::endl;
    std::cout << tmp.getPhoneNumber() << std::endl;
    std::cout << tmp.getBirthdayDate() << std::endl;
    std::cout << tmp.getFavoriteMeal() << std::endl;
    std::cout << tmp.getUnderwearColor() << std::endl;
    std::cout << tmp.getDarkestSecret() << std::endl;
}

void    Phonebook::search(void) {
    int         index;

    if (this->contact_idx > 0) {
        std::cout << "     index|first name| last name|  nickname" << std::endl;
        for (int i = 0; i < this->contact_idx; i++) {
            printContacts(i);
        }
        std::cout << "index : ";
        std::cin >> index;
        if (!std::cin.fail() && index <= contact_idx && index >= 0)
            printContact(index);
        else {
            std::cout << "Nothing appropriate" << std::endl;
        }
    }
    else {
        std::cout << "Nothing to show" << std::endl;
    }
    std::cin.clear();
    std::cin.sync();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}