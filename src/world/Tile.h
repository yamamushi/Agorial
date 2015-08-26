//
// Created by Jonathan Rumion on 8/13/15.
//
//  The Tile Class is one of the most important containers in the entire World management engine.
//  Each tile must maintain a state, free of pointers, that is to be indexed
//


#ifndef AGORIAL_TILE_H
#define AGORIAL_TILE_H

#include <string>
#include "types/ColorTypes.h"

enum class TileType {

    AetherTile,

};

class Tile {

public:

    Tile(int symbol=0, ColorRGB color=ColorRGB{0,0,0});
    bool operator!=(const Tile& tile2) const;
    bool operator==(const Tile& tile2) const;

    std::string getStringSymbol();
    void setStringSymbol(std::string symbol);

    int getSymbol(){return m_symbol;}
    void setSymbol(int symbol){m_symbol = symbol;} // !!Needs bounds checking!!
    ColorRGB getColorRGB(){return m_colorRGB;}
    TileType getTileType(){return m_tileType;}

protected:

    int m_symbol; // Symbol is stored as an Int not a String
    float m_temperature;
    float m_soundDensity;
    int m_opacity;
    int m_hardness;
    float m_damage;

    ColorRGB m_colorRGB;
    TileType m_tileType;

};


class AetherTile : public Tile {

public:

    AetherTile(int symbol=0, ColorRGB color=ColorRGB{0,0,0}) { m_tileType = TileType::AetherTile; };

private:

};

#endif //AGORIAL_TILE_H
