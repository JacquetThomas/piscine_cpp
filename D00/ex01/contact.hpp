/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacquet <cjacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 11:19:03 by cjacquet          #+#    #+#             */
/*   Updated: 2019/03/25 18:24:13 by cjacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>
# include <iomanip>

class Contact {

public:
	Contact(void);
	~Contact(void);

	void		fillFields();
	void		setFirstName(std::string first_name);
	std::string	getFirstName();
	void		setLastName(std::string last_name);
	std::string	getLastName();
	void		setNickname(std::string nickname);
	std::string	getNickname();
	void		setLogin(std::string login);
	std::string	getLogin();
	void		setPostalAddress(std::string postal_address);
	std::string	getPostalAddress();
	void		setEmailAddress(std::string email_address);
	std::string	getEmailAddress();
	void		setPhoneNumber(std::string phone_number);
	std::string	getPhoneNumber();
	void		setBirthdayDate(std::string birthday_date);
	std::string	getBirthdayDate();
	void		setFavoriteMeal(std::string favorite_meal);
	std::string	getFavoriteMeal();
	void		setUnderwearColor(std::string underwear_color);
	std::string	getUnderwearColor();
	void		setDarkestSecret(std::string darkest_secret);
	std::string	getDarkestSecret();

private:
	std::string _first_name;
	std::string _last_name;
	std::string _nickname;
	std::string _login;
	std::string _postal_address;
	std::string _email_address;
	std::string _phone_number;
	std::string _birthday_date;
	std::string _favorite_meal;
	std::string _underwear_color;
	std::string _darkest_secret;
};

#endif
