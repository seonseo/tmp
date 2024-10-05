#ifndef CONTACT_H
#define CONTACT_H

#include <string>

class Contact
{
public:
    // Default Constructor
    Contact();
    // Copy Constructor
    Contact(const Contact& other);
    // Copy Assignment Operator
    Contact& operator=(const Contact& other);
    // Destructor
    ~Contact();

    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getNickname() const;
    std::string getPhoneNumber() const;
    std::string getDarkestSecret() const;

    void setFirstName(const std::string& firstName);
    void setLastName(const std::string& lastName);
    void setNickname(const std::string& nickname);
    void setPhoneNumber(const std::string& phoneNumber);
    void setDarkestSecret(const std::string& darkestSecret);
private:
    std::string FirstName;
    std::string LastName;
    std::string Nickname;
    std::string PhoneNumber;
    std::string DarkestSecret;
};

#endif
