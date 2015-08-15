//
// Created by Jonathan Rumion on 8/12/15.
//

#ifndef AGORIAL_ClientConfigParser_H
#define AGORIAL_ClientConfigParser_H

#include <string>
#include <boost/program_options.hpp>

class ClientConfigParser {

public:

    static ClientConfigParser* I();

    bool loadCommandLine(int argc, char * argv[]);
    bool parse();

    std::string getHomePath(){return m_homePath;}

    std::string getConfigPath(){return m_configPath;}
    std::string getLoginServerHost(){return m_login_server_host;}
    int getLoginServerPort(){return m_login_server_port;}

    std::string getFontPath(){return m_fontPath;}
    std::string getDataPath(){return m_dataPath;}
    std::string getCertPath(){return m_certPath;}

    int getConnectionThreads(){return m_connectionThreads;}


    std::string getScreenSize(){return m_screenSize;}
    int getScreenX(){return m_screenX;}
    int getScreenY(){return m_screenY;}

    bool saveConfig(std::string savePath="");

private:

    ClientConfigParser();

    ClientConfigParser(ClientConfigParser const&){};             // copy constructor is private
    void operator=(ClientConfigParser const&){};  // assignment operator is private
    static ClientConfigParser* m_pInstance;

    boost::program_options::variables_map m_varMap;

    boost::program_options::options_description * m_description;
    boost::program_options::options_description * m_config;
    boost::program_options::options_description * m_config_file_options;

    std::string m_homePath;

    std::string m_configPath;
    std::string m_login_server_host;
    int m_login_server_port;

    std::string m_screenSize;
    int m_screenX;
    int m_screenY;

    int m_connectionThreads;

    std::string m_fontPath;
    std::string m_dataPath;
    std::string m_certPath;


    bool m_commandLineLoaded;

};


#endif //AGORIAL_ClientConfigParser_H
