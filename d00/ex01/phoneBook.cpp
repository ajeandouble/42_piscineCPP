#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <regex>

#define CONTACTS_NUMBER	8

class phoneBook
{
	private:
		bool _is_email_valid(const std::string& email)
		{
			const std::regex pattern("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
   			return std::regex_match(email, pattern);
		}

	public:
		std::string firstName;
		std::string lastName;
		std::string email;
		bool	setFirstName()
		{
			std::cout << "Firstname:\t";
			std::getline(std::cin, firstName);
			if (firstName.length() < 1)
			{
				std::cout << "Invalid firstname" << std::endl;
				firstName = "";
				return (false);
			}
			firstName[0] = toupper(firstName[0]);
			for (int i = 1; i < firstName.length(); ++i)
				firstName[i] = tolower(firstName[i]);
			return (true);
		}
		bool	setLastName()
		{
			std::cout << "Lastname:\t";
			std::getline(std::cin, lastName);
			if (lastName.length() < 1)
			{
				std::cout << "Invalid lastname" << std::endl;
				lastName = "";
				return (false);
			}
			lastName[0] = toupper(lastName[0]);
			for (int i = 1; i < lastName.length(); ++i)
				lastName[i] = tolower(lastName[i]);
			return (true);
		}
		bool	setEmail()
		{
			std::cout << "Email:\t";
			std::getline(std::cin, email);
			if (!_is_email_valid(email))
			{
				std::cout << "Invalid email" << std::endl;
				email = "";
				return (false);
			}
			return (true);
		}
		void	printContact()
		{
			std::cout << "Firstname:\t" << firstName << "\tLastname:\t" << lastName << "\tEmail:\t" << email << std::endl;
		}
};

int main(int ac, char **av)
{
	phoneBook	contacts[CONTACTS_NUMBER];
	int			contactsLen = 0;
	std::string command;

	while (43)
	{
		std::getline(std::cin, command);
		if (command == "EXIT" || std::cin.eof())
			exit (0);
		else if (command == "ADD")
		{
			command = "";
			phoneBook newContact;
			std::cout << "Enter contact infos:" << std::endl;
			while (!newContact.setFirstName() && !std::cin.eof())
				newContact.setFirstName();
			if (newContact.firstName.empty())
				exit (EXIT_FAILURE);
			while (!newContact.setLastName() && !std::cin.eof())
				newContact.setLastName();
			if (newContact.lastName.empty())
				exit (EXIT_FAILURE);
			while (!newContact.setEmail() && !std::cin.eof())
				newContact.setEmail();
			if (newContact.email.empty())
				exit (EXIT_FAILURE);
			std::cout << "New contact added to entry #" << contactsLen % 8 << std::endl;
			contacts[contactsLen % CONTACTS_NUMBER] = newContact;
			newContact.printContact();
			++contactsLen;	
	   	}
		else if (command == "SEARCH")
		{
			for (int i = 0; i < contactsLen % CONTACTS_NUMBER; ++i)
			{
				std::cout << '[' << i << "]\t";
				contacts[i].printContact();
			}
		}
		else
		{
			// loop
		}
	}
	return (0);
}
