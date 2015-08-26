//
// Created by Jonathan Rumion on 8/13/15.
//

#include "Tile.h"
#include "util/UTF8Util.h"


Tile::Tile(int symbol, ColorRGB color){

    m_symbol = symbol;
    m_colorRGB = color;

}

bool Tile::operator!=(const Tile& tile2) const {
    if(m_symbol != tile2.m_symbol ||
       m_temperature != tile2.m_temperature ||
       m_soundDensity != tile2.m_soundDensity ||
       m_opacity != tile2.m_opacity ||
       m_hardness != tile2.m_hardness ||
       m_damage != tile2.m_damage ||
       m_colorRGB != tile2.m_colorRGB ||
       m_tileType != tile2.m_tileType)
        return true;
    else
        return false;
}


bool Tile::operator==(const Tile& tile2) const {
    if(m_symbol == tile2.m_symbol &&
       m_temperature == tile2.m_temperature &&
       m_soundDensity == tile2.m_soundDensity &&
       m_opacity == tile2.m_opacity &&
       m_hardness == tile2.m_hardness &&
       m_damage == tile2.m_damage &&
       m_colorRGB == tile2.m_colorRGB &&
       m_tileType == tile2.m_tileType)
        return true;
    else
        return false;
}


std::string Tile::getStringSymbol(){

    return IntToUTF8String(m_symbol);
}


void Tile::setStringSymbol(std::string symbol) {

    m_symbol = UTF8StringToInt(symbol);
}