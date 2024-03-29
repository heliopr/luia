#ifndef LUIA_KEYBOARD_H
#define LUIA_KEYBOARD_H

#include <stdint.h>
#include <SDL2/SDL.h>

typedef enum luia_key {
    LUIA_KEY_UNKNOWN = 0,
    LUIA_KEY_BACKSPACE,
    LUIA_KEY_TAB,
    LUIA_KEY_RETURN,
    LUIA_KEY_ESCAPE,
    LUIA_KEY_SPACE,
    LUIA_KEY_EXCLAIM,
    LUIA_KEY_QUOTEDBL,
    LUIA_KEY_HASH,
    LUIA_KEY_DOLLAR,
    LUIA_KEY_PERCENT,
    LUIA_KEY_AMPERSAND,
    LUIA_KEY_QUOTE,
    LUIA_KEY_LEFTPAREN,
    LUIA_KEY_RIGHTPAREN,
    LUIA_KEY_ASTERISK,
    LUIA_KEY_PLUS,
    LUIA_KEY_COMMA,
    LUIA_KEY_MINUS,
    LUIA_KEY_PERIOD,
    LUIA_KEY_SLASH,
    LUIA_KEY_0,
    LUIA_KEY_1,
    LUIA_KEY_2,
    LUIA_KEY_3,
    LUIA_KEY_4,
    LUIA_KEY_5,
    LUIA_KEY_6,
    LUIA_KEY_7,
    LUIA_KEY_8,
    LUIA_KEY_9,
    LUIA_KEY_COLON,
    LUIA_KEY_SEMICOLON,
    LUIA_KEY_LESS,
    LUIA_KEY_EQUALS,
    LUIA_KEY_GREATER,
    LUIA_KEY_QUESTION,
    LUIA_KEY_AT,
    LUIA_KEY_LEFTBRACKET,
    LUIA_KEY_BACKSLASH,
    LUIA_KEY_RIGHTBRACKET,
    LUIA_KEY_CARET,
    LUIA_KEY_UNDERSCORE,
    LUIA_KEY_BACKQUOTE,
    LUIA_KEY_a,
    LUIA_KEY_b,
    LUIA_KEY_c,
    LUIA_KEY_d,
    LUIA_KEY_e,
    LUIA_KEY_f,
    LUIA_KEY_g,
    LUIA_KEY_h,
    LUIA_KEY_i,
    LUIA_KEY_j,
    LUIA_KEY_k,
    LUIA_KEY_l,
    LUIA_KEY_m,
    LUIA_KEY_n,
    LUIA_KEY_o,
    LUIA_KEY_p,
    LUIA_KEY_q,
    LUIA_KEY_r,
    LUIA_KEY_s,
    LUIA_KEY_t,
    LUIA_KEY_u,
    LUIA_KEY_v,
    LUIA_KEY_w,
    LUIA_KEY_x,
    LUIA_KEY_y,
    LUIA_KEY_z,
    LUIA_KEY_DELETE,
    LUIA_KEY_CAPSLOCK,
    LUIA_KEY_F1,
    LUIA_KEY_F2,
    LUIA_KEY_F3,
    LUIA_KEY_F4,
    LUIA_KEY_F5,
    LUIA_KEY_F6,
    LUIA_KEY_F7,
    LUIA_KEY_F8,
    LUIA_KEY_F9,
    LUIA_KEY_F10,
    LUIA_KEY_F11,
    LUIA_KEY_F12,
    LUIA_KEY_PRINTSCREEN,
    LUIA_KEY_SCROLLLOCK,
    LUIA_KEY_PAUSE,
    LUIA_KEY_INSERT,
    LUIA_KEY_HOME,
    LUIA_KEY_PAGEUP,
    LUIA_KEY_END,
    LUIA_KEY_PAGEDOWN,
    LUIA_KEY_RIGHT,
    LUIA_KEY_LEFT,
    LUIA_KEY_DOWN,
    LUIA_KEY_UP,
    LUIA_KEY_NUMLOCKCLEAR,
    LUIA_KEY_KP_DIVIDE,
    LUIA_KEY_KP_MULTIPLY,
    LUIA_KEY_KP_MINUS,
    LUIA_KEY_KP_PLUS,
    LUIA_KEY_KP_ENTER,
    LUIA_KEY_KP_1,
    LUIA_KEY_KP_2,
    LUIA_KEY_KP_3,
    LUIA_KEY_KP_4,
    LUIA_KEY_KP_5,
    LUIA_KEY_KP_6,
    LUIA_KEY_KP_7,
    LUIA_KEY_KP_8,
    LUIA_KEY_KP_9,
    LUIA_KEY_KP_0,
    LUIA_KEY_KP_PERIOD,
    LUIA_KEY_APPLICATION,
    LUIA_KEY_POWER,
    LUIA_KEY_KP_EQUALS,
    LUIA_KEY_F13,
    LUIA_KEY_F14,
    LUIA_KEY_F15,
    LUIA_KEY_F16,
    LUIA_KEY_F17,
    LUIA_KEY_F18,
    LUIA_KEY_F19,
    LUIA_KEY_F20,
    LUIA_KEY_F21,
    LUIA_KEY_F22,
    LUIA_KEY_F23,
    LUIA_KEY_F24,
    LUIA_KEY_EXECUTE,
    LUIA_KEY_HELP,
    LUIA_KEY_MENU,
    LUIA_KEY_SELECT,
    LUIA_KEY_STOP,
    LUIA_KEY_AGAIN,
    LUIA_KEY_UNDO,
    LUIA_KEY_CUT,
    LUIA_KEY_COPY,
    LUIA_KEY_PASTE,
    LUIA_KEY_FIND,
    LUIA_KEY_MUTE,
    LUIA_KEY_VOLUMEUP,
    LUIA_KEY_VOLUMEDOWN,
    LUIA_KEY_KP_COMMA,
    LUIA_KEY_KP_EQUALSAS400,
    LUIA_KEY_ALTERASE,
    LUIA_KEY_SYSREQ,
    LUIA_KEY_CANCEL,
    LUIA_KEY_CLEAR,
    LUIA_KEY_PRIOR,
    LUIA_KEY_RETURN2,
    LUIA_KEY_SEPARATOR,
    LUIA_KEY_OUT,
    LUIA_KEY_OPER,
    LUIA_KEY_CLEARAGAIN,
    LUIA_KEY_CRSEL,
    LUIA_KEY_EXSEL,
    LUIA_KEY_KP_00,
    LUIA_KEY_KP_000,
    LUIA_KEY_THOUSANDSSEPARATOR,
    LUIA_KEY_DECIMALSEPARATOR,
    LUIA_KEY_CURRENCYUNIT,
    LUIA_KEY_CURRENCYSUBUNIT,
    LUIA_KEY_KP_LEFTPAREN,
    LUIA_KEY_KP_RIGHTPAREN,
    LUIA_KEY_KP_LEFTBRACE,
    LUIA_KEY_KP_RIGHTBRACE,
    LUIA_KEY_KP_TAB,
    LUIA_KEY_KP_BACKSPACE,
    LUIA_KEY_KP_A,
    LUIA_KEY_KP_B,
    LUIA_KEY_KP_C,
    LUIA_KEY_KP_D,
    LUIA_KEY_KP_E,
    LUIA_KEY_KP_F,
    LUIA_KEY_KP_XOR,
    LUIA_KEY_KP_POWER,
    LUIA_KEY_KP_PERCENT,
    LUIA_KEY_KP_LESS,
    LUIA_KEY_KP_GREATER,
    LUIA_KEY_KP_AMPERSAND,
    LUIA_KEY_KP_DBLAMPERSAND,
    LUIA_KEY_KP_VERTICALBAR,
    LUIA_KEY_KP_DBLVERTICALBAR,
    LUIA_KEY_KP_COLON,
    LUIA_KEY_KP_HASH,
    LUIA_KEY_KP_SPACE,
    LUIA_KEY_KP_AT,
    LUIA_KEY_KP_EXCLAM,
    LUIA_KEY_KP_MEMSTORE,
    LUIA_KEY_KP_MEMRECALL,
    LUIA_KEY_KP_MEMCLEAR,
    LUIA_KEY_KP_MEMADD,
    LUIA_KEY_KP_MEMSUBTRACT,
    LUIA_KEY_KP_MEMMULTIPLY,
    LUIA_KEY_KP_MEMDIVIDE,
    LUIA_KEY_KP_PLUSMINUS,
    LUIA_KEY_KP_CLEAR,
    LUIA_KEY_KP_CLEARENTRY,
    LUIA_KEY_KP_BINARY,
    LUIA_KEY_KP_OCTAL,
    LUIA_KEY_KP_DECIMAL,
    LUIA_KEY_KP_HEXADECIMAL,
    LUIA_KEY_LCTRL,
    LUIA_KEY_LSHIFT,
    LUIA_KEY_LALT,
    LUIA_KEY_LGUI,
    LUIA_KEY_RCTRL,
    LUIA_KEY_RSHIFT,
    LUIA_KEY_RALT,
    LUIA_KEY_RGUI,
    LUIA_KEY_MODE,
    LUIA_KEY_AUDIONEXT,
    LUIA_KEY_AUDIOPREV,
    LUIA_KEY_AUDIOSTOP,
    LUIA_KEY_AUDIOPLAY,
    LUIA_KEY_AUDIOMUTE,
    LUIA_KEY_MEDIASELECT,
    LUIA_KEY_WWW,
    LUIA_KEY_MAIL,
    LUIA_KEY_CALCULATOR,
    LUIA_KEY_COMPUTER,
    LUIA_KEY_AC_SEARCH,
    LUIA_KEY_AC_HOME,
    LUIA_KEY_AC_BACK,
    LUIA_KEY_AC_FORWARD,
    LUIA_KEY_AC_STOP,
    LUIA_KEY_AC_REFRESH,
    LUIA_KEY_AC_BOOKMARKS,
    LUIA_KEY_BRIGHTNESSDOWN,
    LUIA_KEY_BRIGHTNESSUP,
    LUIA_KEY_DISPLAYSWITCH,
    LUIA_KEY_KBDILLUMTOGGLE,
    LUIA_KEY_KBDILLUMDOWN,
    LUIA_KEY_KBDILLUMUP,
    LUIA_KEY_EJECT,
    LUIA_KEY_SLEEP,
} luia_key;

luia_key luia_sdlkey_map(SDL_KeyCode keycode);


#endif