//
// Created by Jonathan Rumion on 8/12/15.
//

#include "ClientConfigParser.h"
#include "util/Constants.h"
#include "util/IsNumber.h"
#include "handlers/FilesystemHandler.h"

#include <boost/filesystem.hpp>
#include <boost/progress.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/ini_parser.hpp>

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>

ClientConfigParser* ClientConfigParser::m_pInstance = NULL;

ClientConfigParser* ClientConfigParser::I()
{
    if (!m_pInstance)   // Only allow one instance of class to be generated.
        m_pInstance = new ClientConfigParser;

    return m_pInstance;
}


ClientConfigParser::ClientConfigParser() {

    m_commandLineLoaded = false;
    m_homePath = getenv("HOME");

    m_description = new boost::program_options::options_description("Default options");

    m_dataPath = m_homePath + "/.agorial/data/";

    m_description->add_options()
            ("config,c", boost::program_options::value<std::string>(&m_configPath)->default_value(
                    m_homePath + "/.agorial/agorial.conf"), "Configuration file path")
            ("help,h", "display this help text")
            ("version,v", "display version number");

    m_config = new boost::program_options::options_description("Config File Options");

    m_config->add_options()
            ("network.login_server_host",
             boost::program_options::value<std::string>(&m_login_server_host)->default_value("localhost"),
             "Login Server Hostname")
            ("network.login_server_port", boost::program_options::value<int>(&m_login_server_port)->default_value(4200),
             "Login Server Port")
            ("network.cert_path",
             boost::program_options::value<std::string>(&m_certPath)->default_value(m_homePath + "/.agorial/certs/"),
             "Certificate Path")
            ("network.connection_threads",
             boost::program_options::value<int>(&m_connectionThreads)->default_value(2),
             "Number of Client Connection Threads")
            ("gui.screen_size", boost::program_options::value<std::string>(&m_screenSize)->default_value("80:40"),
             "Screen Size x:y")
            ("gui.font_path",
             boost::program_options::value<std::string>(&m_fontPath)->default_value(m_homePath + "/.agorial/fonts/"),
             "Screen Size x:y")
            ;

    m_config_file_options = new boost::program_options::options_description();
    m_config_file_options->add(*m_config);

}


bool ClientConfigParser::parse(){

    if(!m_commandLineLoaded){

        std::cerr << "Cannot Start Parser, Command Line Not Loaded" << std::endl;
        return false;
    }

    std::ifstream ifs(m_configPath.c_str());
    if(!ifs)
    {
        std::cout << clientversiontext << std::endl;
        std::cout << std::endl;
        std::cout << *m_description << std::endl;
        std::cout << *m_config << std::endl;
        std::cout << std::endl;
        std::cout << "Error: could not open config file \"" << m_configPath << "\"" << std::endl;
        exit(0);
    }
    else
    {
        store(parse_config_file(ifs, *m_config_file_options), m_varMap);
        notify(m_varMap);
    }


    char c=':';
    std::vector<std::string> v;
    std::string::size_type i = 0;
    std::string::size_type j = m_screenSize.find(c);

    while (j != std::string::npos) {
        v.push_back(m_screenSize.substr(i, j-i));
        i = ++j;
        j = m_screenSize.find(c, j);

        if (j == std::string::npos)
            v.push_back(m_screenSize.substr(i, m_screenSize.length()));
    }

    for(auto screenSizeVar : v){

        if(!IsNumber(screenSizeVar)){

            std::cerr << "Variable " + screenSizeVar + " is not a valid Screen Size" << std::endl;
            return false;

        }
    }
    m_screenX = std::stoi(v.at(0));
    m_screenY = std::stoi(v.at(1));

    return true;
}


bool ClientConfigParser::loadCommandLine(int argc, char * argv[]) {

    try {

        boost::program_options::store(boost::program_options::parse_command_line(argc, argv, *m_description), m_varMap);
        boost::program_options::notify(m_varMap);

        if (m_varMap.count("help")) {
            std::cout << *m_description << std::endl;
            std::cout << *m_config << std::endl;
            exit(0);
        }
        if (m_varMap.count("version")) {
            std::cout << clientversiontext << std::endl;
            exit(0);
        }
    }

    catch(std::exception& e) {
        std::cerr << "error: " << e.what() << "\n";
        return false;
    }
    catch(...) {
        std::cerr << "Exception of unknown type!\n";
        return false;
    }

    m_commandLineLoaded = true;
    return true;

}



bool ClientConfigParser::saveConfig(std::string savePath) {

    if (savePath.empty()) {

        savePath = m_configPath;

    }

    boost::property_tree::ptree outputTree;

    boost::property_tree::ptree graphicsSettings;
    graphicsSettings.put("screen_size", m_screenSize);
    graphicsSettings.put("font_path", m_fontPath);

    boost::property_tree::ptree networkSettings;
    networkSettings.put("login_server_host", m_login_server_host);
    networkSettings.put("login_server_port", std::to_string(m_login_server_port));
    networkSettings.put("cert_path", m_certPath);


    outputTree.push_front(boost::property_tree::ptree::value_type("gui", graphicsSettings));
    outputTree.push_front(boost::property_tree::ptree::value_type("network", networkSettings));

    boost::property_tree::write_ini( savePath, outputTree );

    return true;
}
