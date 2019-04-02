/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacquet <cjacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 11:51:47 by cjacquet          #+#    #+#             */
/*   Updated: 2019/03/26 09:49:35 by cjacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"

Contact::Contact(void) {}

Contact::~Contact(void) {}

void    Contact::fillFields(void){
    std::string response;

    std::cout << "first name : ";
  	std::cin.ignore();
	std::getline(std::cin, response);
	setFirstName(response);
	std::cout << "last name : ";
    std::getline(std::cin, response);
	setLastName(response);
	std::cout << "nickname : ";
	std::getline(std::cin, response);
	setNickname(response);
	std::cout << "login : ";
	std::getline(std::cin, response);
	setLogin(response);
	std::cout << "postal address : ";
	std::getline(std::cin, response);
	setPostalAddress(response);
	std::cout << "email address : ";
	std::getline(std::cin, response);
	setEmailAddress(response);
	std::cout << "phone number : ";
	std::getline(std::cin, response);
	setPhoneNumber(response);
	std::cout << "birthday date : ";
	std::getline(std::cin, response);
	setBirthdayDate(response);
	std::cout << "favorite meal : ";
	std::getline(std::cin, response);
	setFavoriteMeal(response);
	std::cout << "underwear color : ";
	std::getline(std::cin, response);
	setUnderwearColor(response);
	std::cout << "darkest secret : ";
	std::getline(std::cin, response);
	setDarkestSecret(response);
}

void	Contact::setFirstName(std::string first_name) {
	this->_first_name = first_name;
}

std::string	Contact::getFirstName(void) {
	return (this->_first_name);
}

void Contact::setLastName(std::string last_name) {
	this->_last_name = last_name;
}

std::string Contact::getLastName() {
	return (this->_last_name);
}

void Contact::setNickname(std::string nickname) {
	this->_nickname = nickname;
}

std::string Contact::getNickname() {
	return (this->_nickname);
}

void Contact::setLogin(std::string login) {
	this->_login = login;
}

std::string Contact::getLogin() {
	return (this->_login);
}

void Contact::setPostalAddress(std::string postal_address) {
	this->_postal_address = postal_address;
}

std::string Contact::getPostalAddress(){
	return(this->_postal_address);
}

void Contact::setEmailAddress(std::string email_address) {
	this->_email_address = email_address;
}

std::string Contact::getEmailAddress() {
	return (this->_email_address);
}

void Contact::setPhoneNumber(std::string phone_number) {
	this->_phone_number = phone_number;
}

std::string Contact::getPhoneNumber() {
	return (this->_phone_number);
}

void Contact::setBirthdayDate(std::string birthday_date) {
	this->_birthday_date = birthday_date;
}

std::string Contact::getBirthdayDate() {
	return (this->_birthday_date);
}

void Contact::setFavoriteMeal(std::string favorite_meal) {
	this->_favorite_meal = favorite_meal;
}

std::string Contact::getFavoriteMeal(){
	return (this->_favorite_meal);
}

void Contact::setUnderwearColor(std::string underwear_color) {
	this->_underwear_color = underwear_color;
}

std::string Contact::getUnderwearColor() {
	return (this->_underwear_color);
}

void Contact::setDarkestSecret(std::string darkest_secret) {
	this->_darkest_secret = darkest_secret;
}

std::string Contact::getDarkestSecret() {
	return (this->_darkest_secret);
}