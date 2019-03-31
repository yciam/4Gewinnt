//
// Created by Raphael Straub on 15.09.18.
//

#ifndef IVGEWINNT_DEBUG_HPP
#define IVGEWINNT_DEBUG_HPP

#include <string>
#include <iostream>

#define _S(s)                      std::string(s)
#define _T(s)                      std::to_string(s)

#define DEBUG_ESCAPE               _S("\033[")
#define DEBUG_SINGLE_C(c)          (DEBUG_ESCAPE+_T(c)+"m")



#define DEBUG_RESET                DEBUG_SINGLE_C( 0)

#define DEBUG_NORMALIZE            DEBUG_SINGLE_C(22)
#define DEBUG_NORMALIZE_2          DEBUG_SINGLE_C(23)
#define DEBUG_NO_UNDERLINE         DEBUG_SINGLE_C(24)
#define DEBUG_NO_OVERLINED         DEBUG_SINGLE_C(55)

#define DEBUG_BOLD                 DEBUG_SINGLE_C( 1)
#define DEBUG_FAINT                DEBUG_SINGLE_C( 2)
#define DEBUG_ITALIC               DEBUG_SINGLE_C( 3)
#define DEBUG_UNDERLINE            DEBUG_SINGLE_C( 4)
#define DEBUG_OVERLINED            DEBUG_SINGLE_C(53)
#define DEBUG_SLOW_BLINK           DEBUG_SINGLE_C( 5)
#define DEBUG_REVERSE              DEBUG_SINGLE_C( 7)
#define DEBUG_STRIKE               DEBUG_SINGLE_C( 9)

#define DEBUG_8BIT_FOREGROUND(c)   "\033[38;5;" + (c) + "m"
#define DEBUG_DEFAULT_FOREGROUND   DEBUG_SINGLE_C(39)

#define DEBUG_FG_BLACK             DEBUG_SINGLE_C(30)
#define DEBUG_FG_RED               DEBUG_SINGLE_C(31)
#define DEBUG_FG_GREEN             DEBUG_SINGLE_C(32)
#define DEBUG_FG_YELLOW            DEBUG_SINGLE_C(33)
#define DEBUG_FG_BLUE              DEBUG_SINGLE_C(34)
#define DEBUG_FG_MAGENTA           DEBUG_SINGLE_C(35)
#define DEBUG_FG_CYAN              DEBUG_SINGLE_C(36)
#define DEBUG_FG_WHITE             DEBUG_SINGLE_C(37)

#define DEBUG_8BIT_BACKGROUND(c)   "\033[48;5;" + (c) + "m"
#define DEBUG_DEFAULT_BACKGROUND   DEBUG_SINGLE_C(49)

#define DEBUG_BG_BLACK             DEBUG_SINGLE_C(40)
#define DEBUG_BG_RED               DEBUG_SINGLE_C(41)
#define DEBUG_BG_GREEN             DEBUG_SINGLE_C(42)
#define DEBUG_BG_YELLOW            DEBUG_SINGLE_C(43)
#define DEBUG_BG_BLUE              DEBUG_SINGLE_C(44)
#define DEBUG_BG_MAGENTA           DEBUG_SINGLE_C(45)
#define DEBUG_BG_CYAN              DEBUG_SINGLE_C(46)
#define DEBUG_BG_WHITE             DEBUG_SINGLE_C(47)


#ifndef YELLOWDEBUG
    #define YELLOWDEBUG 0
#endif
#ifndef PROJECT_NAME
#define PROJECT_NAME "undefined"
#endif
#ifndef PROJECT_VERSION
#define PROJECT_VERSION 0
#endif

#if YELLOWDEBUG >= 0
#define DEB_WAR(str) {\
        std::cout << DEBUG_RESET << DEBUG_FG_BLACK << \
        DEBUG_BG_YELLOW << "[WAR] " << str << " @" << __LINE__ << "~" << \
        __FILE__ << std::endl << DEBUG_RESET;}
#define DEB_ERR(str) {\
        std::cout << DEBUG_RESET << DEBUG_BG_RED << \
        DEBUG_FG_BLACK << std::endl << "[ERR] " << str << " @" << __LINE__ << "~" << \
        __FILE__ << std::endl << std::endl << DEBUG_RESET;}
#else
#define DEB_WAR(str);
  #define DEB_ERR(str);
#endif
#if YELLOWDEBUG > 0
#define DEB_MSG_1(str) {\
        std::cout << DEBUG_RESET << DEBUG_BG_WHITE << \
        DEBUG_FG_BLACK << "[DL1] " << str << " @" << __LINE__ << "~" << \
        __FILE__ << std::endl << DEBUG_RESET;}
#else
#define P_DEB_MSG(str);
#define P_MAC_MSG(mac,str);
#define DEB_MSG_1(str);
#endif

#if YELLOWDEBUG > 1
#define DEB_MSG_2(str) {\
        std::cout << DEBUG_RESET << DEBUG_BG_CYAN << \
        DEBUG_FG_BLACK << "[DL2] " << str << " @" << __LINE__ << "~" << \
        __FILE__ << std::endl << DEBUG_RESET;}
#else
#define DEB_MSG_2(str);
#endif

#if YELLOWDEBUG > 2
#define DEB_MSG_3(str) {\
        std::cout << DEBUG_RESET << DEBUG_BG_BLUE << \
        DEBUG_FG_BLACK << "[DL3] " << str << " @" << __LINE__ << "~" << \
        __FILE__ << std::endl << DEBUG_RESET;}
#else
#define DEB_MSG_3(str);
#endif


#endif //MINIGAME_COLLECTION_DEBUG_HPP
