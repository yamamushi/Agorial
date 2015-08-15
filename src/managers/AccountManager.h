//
// Created by Jonathan Rumion on 8/13/15.
//

#ifndef AGORIAL_ACCOUNTMANAGER_H
#define AGORIAL_ACCOUNTMANAGER_H

#include <string>

class AccountManager {

public:

    static AccountManager* I();

    void checkLogin(std::string user, std::string passMD5){};
    void validate(std::string user, std::string token){};

private:

    AccountManager();
    ~AccountManager(){};

    AccountManager(AccountManager const&){};             // copy constructor is private
    void operator=(AccountManager const&){};  // assignment operator is private
    static AccountManager* m_pInstance;

};


#endif //AGORIAL_ACCOUNTMANAGER_H
