/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjacquet <cjacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 11:12:41 by cjacquet          #+#    #+#             */
/*   Updated: 2019/03/26 09:27:26 by cjacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "contact.hpp"

# define MAX_CONTACTS 8
# define WIDTH 10

class Phonebook {

public:
    Phonebook(void);
    ~Phonebook(void);

    void        addContact(void);
    void        search(void);
    void        setContactIdx(int idx);
    int         getContactIdx(void);
    Contact     getContact(int idx);

private:
    Contact contact_list[MAX_CONTACTS];
    int     contact_idx;

    void        printContacts(int idx);
    void        printContact(int idx);
    std::string toFit(std::string str);
};

#endif
