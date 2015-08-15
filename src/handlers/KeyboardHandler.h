//
// Created by Jonathan Rumion on 8/12/15.
//

#ifndef AGORIAL_KEYBOARDHANDLER_H
#define AGORIAL_KEYBOARDHANDLER_H

#include <libtcod/libtcod.hpp>

class KeyboardHandler {

public:

    enum KEYPRESS_TYPES{

        KALT_f = -110,
        KALT_m = -75

    };

    KeyboardHandler(TCOD_key_t keyboard);

    void handleKeyboard();

private:

    TCOD_key_t keyboard_;

};


#endif //AGORIAL_KEYBOARDHANDLER_H
