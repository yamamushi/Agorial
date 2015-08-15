//
// Created by Jonathan Rumion on 8/13/15.
//

#include "AccountManager.h"

#include <string>

AccountManager* AccountManager::m_pInstance = NULL;


AccountManager* AccountManager::I()
{
    if (!m_pInstance)   // Only allow one instance of class to be generated.
        m_pInstance = new AccountManager;

    return m_pInstance;
}

AccountManager::AccountManager() {


}