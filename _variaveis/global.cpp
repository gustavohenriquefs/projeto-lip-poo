#ifndef VARIAVEIS_G_H
#define VARIAVEIS_G_H

#ifdef _WIN32
    #define CLEAR_COMMAND "cls"
    #define RELOAD_FILE "serve.bat"
#else
    #define CLEAR_COMMAND "clear"
    #define RELOAD_FILE "serve.sh"
#endif

#define nl '\n'

const int ERRO_PADRAO = 9999;

#endif