#include "luiakeyboard.h"

luia_key luia_sdlkey_map(SDL_KeyCode keycode) {
    switch (keycode) {
        case SDLK_UNKNOWN: return LUIA_KEY_UNKNOWN;
        case SDLK_BACKSPACE: return LUIA_KEY_BACKSPACE;
        case SDLK_TAB: return LUIA_KEY_TAB;
        case SDLK_RETURN: return LUIA_KEY_RETURN;
        case SDLK_ESCAPE: return LUIA_KEY_ESCAPE;
        case SDLK_SPACE: return LUIA_KEY_SPACE;
        case SDLK_EXCLAIM: return LUIA_KEY_EXCLAIM;
        case SDLK_QUOTEDBL: return LUIA_KEY_QUOTEDBL;
        case SDLK_HASH: return LUIA_KEY_HASH;
        case SDLK_DOLLAR: return LUIA_KEY_DOLLAR;
        case SDLK_PERCENT: return LUIA_KEY_PERCENT;
        case SDLK_AMPERSAND: return LUIA_KEY_AMPERSAND;
        case SDLK_QUOTE: return LUIA_KEY_QUOTE;
        case SDLK_LEFTPAREN: return LUIA_KEY_LEFTPAREN;
        case SDLK_RIGHTPAREN: return LUIA_KEY_RIGHTPAREN;
        case SDLK_ASTERISK: return LUIA_KEY_ASTERISK;
        case SDLK_PLUS: return LUIA_KEY_PLUS;
        case SDLK_COMMA: return LUIA_KEY_COMMA;
        case SDLK_MINUS: return LUIA_KEY_MINUS;
        case SDLK_PERIOD: return LUIA_KEY_PERIOD;
        case SDLK_SLASH: return LUIA_KEY_SLASH;
        case SDLK_0: return LUIA_KEY_0;
        case SDLK_1: return LUIA_KEY_1;
        case SDLK_2: return LUIA_KEY_2;
        case SDLK_3: return LUIA_KEY_3;
        case SDLK_4: return LUIA_KEY_4;
        case SDLK_5: return LUIA_KEY_5;
        case SDLK_6: return LUIA_KEY_6;
        case SDLK_7: return LUIA_KEY_7;
        case SDLK_8: return LUIA_KEY_8;
        case SDLK_9: return LUIA_KEY_9;
        case SDLK_COLON: return LUIA_KEY_COLON;
        case SDLK_SEMICOLON: return LUIA_KEY_SEMICOLON;
        case SDLK_LESS: return LUIA_KEY_LESS;
        case SDLK_EQUALS: return LUIA_KEY_EQUALS;
        case SDLK_GREATER: return LUIA_KEY_GREATER;
        case SDLK_QUESTION: return LUIA_KEY_QUESTION;
        case SDLK_AT: return LUIA_KEY_AT;
        case SDLK_LEFTBRACKET: return LUIA_KEY_LEFTBRACKET;
        case SDLK_BACKSLASH: return LUIA_KEY_BACKSLASH;
        case SDLK_RIGHTBRACKET: return LUIA_KEY_RIGHTBRACKET;
        case SDLK_CARET: return LUIA_KEY_CARET;
        case SDLK_UNDERSCORE: return LUIA_KEY_UNDERSCORE;
        case SDLK_BACKQUOTE: return LUIA_KEY_BACKQUOTE;
        case SDLK_a: return LUIA_KEY_a;
        case SDLK_b: return LUIA_KEY_b;
        case SDLK_c: return LUIA_KEY_c;
        case SDLK_d: return LUIA_KEY_d;
        case SDLK_e: return LUIA_KEY_e;
        case SDLK_f: return LUIA_KEY_f;
        case SDLK_g: return LUIA_KEY_g;
        case SDLK_h: return LUIA_KEY_h;
        case SDLK_i: return LUIA_KEY_i;
        case SDLK_j: return LUIA_KEY_j;
        case SDLK_k: return LUIA_KEY_k;
        case SDLK_l: return LUIA_KEY_l;
        case SDLK_m: return LUIA_KEY_m;
        case SDLK_n: return LUIA_KEY_n;
        case SDLK_o: return LUIA_KEY_o;
        case SDLK_p: return LUIA_KEY_p;
        case SDLK_q: return LUIA_KEY_q;
        case SDLK_r: return LUIA_KEY_r;
        case SDLK_s: return LUIA_KEY_s;
        case SDLK_t: return LUIA_KEY_t;
        case SDLK_u: return LUIA_KEY_u;
        case SDLK_v: return LUIA_KEY_v;
        case SDLK_w: return LUIA_KEY_w;
        case SDLK_x: return LUIA_KEY_x;
        case SDLK_y: return LUIA_KEY_y;
        case SDLK_z: return LUIA_KEY_z;
        case SDLK_DELETE: return LUIA_KEY_DELETE;
        case SDLK_CAPSLOCK: return LUIA_KEY_CAPSLOCK;
        case SDLK_F1: return LUIA_KEY_F1;
        case SDLK_F2: return LUIA_KEY_F2;
        case SDLK_F3: return LUIA_KEY_F3;
        case SDLK_F4: return LUIA_KEY_F4;
        case SDLK_F5: return LUIA_KEY_F5;
        case SDLK_F6: return LUIA_KEY_F6;
        case SDLK_F7: return LUIA_KEY_F7;
        case SDLK_F8: return LUIA_KEY_F8;
        case SDLK_F9: return LUIA_KEY_F9;
        case SDLK_F10: return LUIA_KEY_F10;
        case SDLK_F11: return LUIA_KEY_F11;
        case SDLK_F12: return LUIA_KEY_F12;
        case SDLK_PRINTSCREEN: return LUIA_KEY_PRINTSCREEN;
        case SDLK_SCROLLLOCK: return LUIA_KEY_SCROLLLOCK;
        case SDLK_PAUSE: return LUIA_KEY_PAUSE;
        case SDLK_INSERT: return LUIA_KEY_INSERT;
        case SDLK_HOME: return LUIA_KEY_HOME;
        case SDLK_PAGEUP: return LUIA_KEY_PAGEUP;
        case SDLK_END: return LUIA_KEY_END;
        case SDLK_PAGEDOWN: return LUIA_KEY_PAGEDOWN;
        case SDLK_RIGHT: return LUIA_KEY_RIGHT;
        case SDLK_LEFT: return LUIA_KEY_LEFT;
        case SDLK_DOWN: return LUIA_KEY_DOWN;
        case SDLK_UP: return LUIA_KEY_UP;
        case SDLK_NUMLOCKCLEAR: return LUIA_KEY_NUMLOCKCLEAR;
        case SDLK_KP_DIVIDE: return LUIA_KEY_KP_DIVIDE;
        case SDLK_KP_MULTIPLY: return LUIA_KEY_KP_MULTIPLY;
        case SDLK_KP_MINUS: return LUIA_KEY_KP_MINUS;
        case SDLK_KP_PLUS: return LUIA_KEY_KP_PLUS;
        case SDLK_KP_ENTER: return LUIA_KEY_KP_ENTER;
        case SDLK_KP_1: return LUIA_KEY_KP_1;
        case SDLK_KP_2: return LUIA_KEY_KP_2;
        case SDLK_KP_3: return LUIA_KEY_KP_3;
        case SDLK_KP_4: return LUIA_KEY_KP_4;
        case SDLK_KP_5: return LUIA_KEY_KP_5;
        case SDLK_KP_6: return LUIA_KEY_KP_6;
        case SDLK_KP_7: return LUIA_KEY_KP_7;
        case SDLK_KP_8: return LUIA_KEY_KP_8;
        case SDLK_KP_9: return LUIA_KEY_KP_9;
        case SDLK_KP_0: return LUIA_KEY_KP_0;
        case SDLK_KP_PERIOD: return LUIA_KEY_KP_PERIOD;
        case SDLK_APPLICATION: return LUIA_KEY_APPLICATION;
        case SDLK_POWER: return LUIA_KEY_POWER;
        case SDLK_KP_EQUALS: return LUIA_KEY_KP_EQUALS;
        case SDLK_F13: return LUIA_KEY_F13;
        case SDLK_F14: return LUIA_KEY_F14;
        case SDLK_F15: return LUIA_KEY_F15;
        case SDLK_F16: return LUIA_KEY_F16;
        case SDLK_F17: return LUIA_KEY_F17;
        case SDLK_F18: return LUIA_KEY_F18;
        case SDLK_F19: return LUIA_KEY_F19;
        case SDLK_F20: return LUIA_KEY_F20;
        case SDLK_F21: return LUIA_KEY_F21;
        case SDLK_F22: return LUIA_KEY_F22;
        case SDLK_F23: return LUIA_KEY_F23;
        case SDLK_F24: return LUIA_KEY_F24;
        case SDLK_EXECUTE: return LUIA_KEY_EXECUTE;
        case SDLK_HELP: return LUIA_KEY_HELP;
        case SDLK_MENU: return LUIA_KEY_MENU;
        case SDLK_SELECT: return LUIA_KEY_SELECT;
        case SDLK_STOP: return LUIA_KEY_STOP;
        case SDLK_AGAIN: return LUIA_KEY_AGAIN;
        case SDLK_UNDO: return LUIA_KEY_UNDO;
        case SDLK_CUT: return LUIA_KEY_CUT;
        case SDLK_COPY: return LUIA_KEY_COPY;
        case SDLK_PASTE: return LUIA_KEY_PASTE;
        case SDLK_FIND: return LUIA_KEY_FIND;
        case SDLK_MUTE: return LUIA_KEY_MUTE;
        case SDLK_VOLUMEUP: return LUIA_KEY_VOLUMEUP;
        case SDLK_VOLUMEDOWN: return LUIA_KEY_VOLUMEDOWN;
        case SDLK_KP_COMMA: return LUIA_KEY_KP_COMMA;
        case SDLK_KP_EQUALSAS400: return LUIA_KEY_KP_EQUALSAS400;
        case SDLK_ALTERASE: return LUIA_KEY_ALTERASE;
        case SDLK_SYSREQ: return LUIA_KEY_SYSREQ;
        case SDLK_CANCEL: return LUIA_KEY_CANCEL;
        case SDLK_CLEAR: return LUIA_KEY_CLEAR;
        case SDLK_PRIOR: return LUIA_KEY_PRIOR;
        case SDLK_RETURN2: return LUIA_KEY_RETURN2;
        case SDLK_SEPARATOR: return LUIA_KEY_SEPARATOR;
        case SDLK_OUT: return LUIA_KEY_OUT;
        case SDLK_OPER: return LUIA_KEY_OPER;
        case SDLK_CLEARAGAIN: return LUIA_KEY_CLEARAGAIN;
        case SDLK_CRSEL: return LUIA_KEY_CRSEL;
        case SDLK_EXSEL: return LUIA_KEY_EXSEL;
        case SDLK_KP_00: return LUIA_KEY_KP_00;
        case SDLK_KP_000: return LUIA_KEY_KP_000;
        case SDLK_THOUSANDSSEPARATOR: return LUIA_KEY_THOUSANDSSEPARATOR;
        case SDLK_DECIMALSEPARATOR: return LUIA_KEY_DECIMALSEPARATOR;
        case SDLK_CURRENCYUNIT: return LUIA_KEY_CURRENCYUNIT;
        case SDLK_CURRENCYSUBUNIT: return LUIA_KEY_CURRENCYSUBUNIT;
        case SDLK_KP_LEFTPAREN: return LUIA_KEY_KP_LEFTPAREN;
        case SDLK_KP_RIGHTPAREN: return LUIA_KEY_KP_RIGHTPAREN;
        case SDLK_KP_LEFTBRACE: return LUIA_KEY_KP_LEFTBRACE;
        case SDLK_KP_RIGHTBRACE: return LUIA_KEY_KP_RIGHTBRACE;
        case SDLK_KP_TAB: return LUIA_KEY_KP_TAB;
        case SDLK_KP_BACKSPACE: return LUIA_KEY_KP_BACKSPACE;
        case SDLK_KP_A: return LUIA_KEY_KP_A;
        case SDLK_KP_B: return LUIA_KEY_KP_B;
        case SDLK_KP_C: return LUIA_KEY_KP_C;
        case SDLK_KP_D: return LUIA_KEY_KP_D;
        case SDLK_KP_E: return LUIA_KEY_KP_E;
        case SDLK_KP_F: return LUIA_KEY_KP_F;
        case SDLK_KP_XOR: return LUIA_KEY_KP_XOR;
        case SDLK_KP_POWER: return LUIA_KEY_KP_POWER;
        case SDLK_KP_PERCENT: return LUIA_KEY_KP_PERCENT;
        case SDLK_KP_LESS: return LUIA_KEY_KP_LESS;
        case SDLK_KP_GREATER: return LUIA_KEY_KP_GREATER;
        case SDLK_KP_AMPERSAND: return LUIA_KEY_KP_AMPERSAND;
        case SDLK_KP_DBLAMPERSAND: return LUIA_KEY_KP_DBLAMPERSAND;
        case SDLK_KP_VERTICALBAR: return LUIA_KEY_KP_VERTICALBAR;
        case SDLK_KP_DBLVERTICALBAR: return LUIA_KEY_KP_DBLVERTICALBAR;
        case SDLK_KP_COLON: return LUIA_KEY_KP_COLON;
        case SDLK_KP_HASH: return LUIA_KEY_KP_HASH;
        case SDLK_KP_SPACE: return LUIA_KEY_KP_SPACE;
        case SDLK_KP_AT: return LUIA_KEY_KP_AT;
        case SDLK_KP_EXCLAM: return LUIA_KEY_KP_EXCLAM;
        case SDLK_KP_MEMSTORE: return LUIA_KEY_KP_MEMSTORE;
        case SDLK_KP_MEMRECALL: return LUIA_KEY_KP_MEMRECALL;
        case SDLK_KP_MEMCLEAR: return LUIA_KEY_KP_MEMCLEAR;
        case SDLK_KP_MEMADD: return LUIA_KEY_KP_MEMADD;
        case SDLK_KP_MEMSUBTRACT: return LUIA_KEY_KP_MEMSUBTRACT;
        case SDLK_KP_MEMMULTIPLY: return LUIA_KEY_KP_MEMMULTIPLY;
        case SDLK_KP_MEMDIVIDE: return LUIA_KEY_KP_MEMDIVIDE;
        case SDLK_KP_PLUSMINUS: return LUIA_KEY_KP_PLUSMINUS;
        case SDLK_KP_CLEAR: return LUIA_KEY_KP_CLEAR;
        case SDLK_KP_CLEARENTRY: return LUIA_KEY_KP_CLEARENTRY;
        case SDLK_KP_BINARY: return LUIA_KEY_KP_BINARY;
        case SDLK_KP_OCTAL: return LUIA_KEY_KP_OCTAL;
        case SDLK_KP_DECIMAL: return LUIA_KEY_KP_DECIMAL;
        case SDLK_KP_HEXADECIMAL: return LUIA_KEY_KP_HEXADECIMAL;
        case SDLK_LCTRL: return LUIA_KEY_LCTRL;
        case SDLK_LSHIFT: return LUIA_KEY_LSHIFT;
        case SDLK_LALT: return LUIA_KEY_LALT;
        case SDLK_LGUI: return LUIA_KEY_LGUI;
        case SDLK_RCTRL: return LUIA_KEY_RCTRL;
        case SDLK_RSHIFT: return LUIA_KEY_RSHIFT;
        case SDLK_RALT: return LUIA_KEY_RALT;
        case SDLK_RGUI: return LUIA_KEY_RGUI;
        case SDLK_MODE: return LUIA_KEY_MODE;
        case SDLK_AUDIONEXT: return LUIA_KEY_AUDIONEXT;
        case SDLK_AUDIOPREV: return LUIA_KEY_AUDIOPREV;
        case SDLK_AUDIOSTOP: return LUIA_KEY_AUDIOSTOP;
        case SDLK_AUDIOPLAY: return LUIA_KEY_AUDIOPLAY;
        case SDLK_AUDIOMUTE: return LUIA_KEY_AUDIOMUTE;
        case SDLK_MEDIASELECT: return LUIA_KEY_MEDIASELECT;
        case SDLK_WWW: return LUIA_KEY_WWW;
        case SDLK_MAIL: return LUIA_KEY_MAIL;
        case SDLK_CALCULATOR: return LUIA_KEY_CALCULATOR;
        case SDLK_COMPUTER: return LUIA_KEY_COMPUTER;
        case SDLK_AC_SEARCH: return LUIA_KEY_AC_SEARCH;
        case SDLK_AC_HOME: return LUIA_KEY_AC_HOME;
        case SDLK_AC_BACK: return LUIA_KEY_AC_BACK;
        case SDLK_AC_FORWARD: return LUIA_KEY_AC_FORWARD;
        case SDLK_AC_STOP: return LUIA_KEY_AC_STOP;
        case SDLK_AC_REFRESH: return LUIA_KEY_AC_REFRESH;
        case SDLK_AC_BOOKMARKS: return LUIA_KEY_AC_BOOKMARKS;
        case SDLK_BRIGHTNESSDOWN: return LUIA_KEY_BRIGHTNESSDOWN;
        case SDLK_BRIGHTNESSUP: return LUIA_KEY_BRIGHTNESSUP;
        case SDLK_DISPLAYSWITCH: return LUIA_KEY_DISPLAYSWITCH;
        case SDLK_KBDILLUMTOGGLE: return LUIA_KEY_KBDILLUMTOGGLE;
        case SDLK_KBDILLUMDOWN: return LUIA_KEY_KBDILLUMDOWN;
        case SDLK_KBDILLUMUP: return LUIA_KEY_KBDILLUMUP;
        case SDLK_EJECT: return LUIA_KEY_EJECT;
        case SDLK_SLEEP: return LUIA_KEY_SLEEP;
        default: return LUIA_KEY_UNKNOWN;
    }
    return LUIA_KEY_UNKNOWN;
}