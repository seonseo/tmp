#include <string>
#include "Contact.h"

// Default Constructor
Contact::Contact() 
    : FirstName(""), LastName(""), Nickname(""), PhoneNumber(""), DarkestSecret("") 
{
}

// Copy Constructor
Contact::Contact(const Contact& other) 
    : FirstName(other.FirstName), 
      LastName(other.LastName), 
      Nickname(other.Nickname), 
      PhoneNumber(other.PhoneNumber), 
      DarkestSecret(other.DarkestSecret) 
{
}

// Copy Assignment Operator
Contact& Contact::operator=(const Contact& other) 
{
    if (this != &other) // Check for self-assignment
    {
        FirstName = other.FirstName;
        LastName = other.LastName;
        Nickname = other.Nickname;
        PhoneNumber = other.PhoneNumber;
        DarkestSecret = other.DarkestSecret;
    }
    return *this;
}

// Destructor
Contact::~Contact() 
{
}

// Getters
std::string Contact::getFirstName() const 
{
    return FirstName;
}

std::string Contact::getLastName() const 
{
    return LastName;
}

std::string Contact::getNickname() const 
{
    return Nickname;
}

std::string Contact::getPhoneNumber() const 
{
    return PhoneNumber;
}

std::string Contact::getDarkestSecret() const 
{
    return DarkestSecret;
}

// Setters
void Contact::setFirstName(const std::string& firstName) 
{
    FirstName = firstName;
}

void Contact::setLastName(const std::string& lastName) 
{
    LastName = lastName;
}

void Contact::setNickname(const std::string& nickname) 
{
    Nickname = nickname;
}

void Contact::setPhoneNumber(const std::string& phoneNumber) 
{
    PhoneNumber = phoneNumber;
}

void Contact::setDarkestSecret(const std::string& darkestSecret) 
{
    DarkestSecret = darkestSecret;
}
