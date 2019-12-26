//
// Created by bagniz on 12/21/19.
//

#include <iostream>
#include <sys/param.h>
#include <cstdio>
#include <termio.h>
#include <unistd.h>

using namespace std;

char clickedChar()
{
    struct termios oldSettings, newSettings;
    tcgetattr( fileno( stdin ), &oldSettings );
    newSettings = oldSettings;
    newSettings.c_lflag &= (~ICANON & ~ECHO);
    tcsetattr( fileno( stdin ), TCSANOW, &newSettings );
    fd_set set;
    FD_ZERO( &set );
    FD_SET( fileno( stdin ), &set );
    int res = select( fileno( stdin )+1, &set, nullptr, nullptr, nullptr);
    if( res > 0 )
    {
        char c;
        read( fileno( stdin ), &c, 1);
        tcsetattr( fileno( stdin ), TCSANOW, &oldSettings );
        return c; // Return the clicked char
    }
    else if( res < 0 )
    {
        perror( "select error" );
    }
    else
    {
        printf( "Select timeout\n" );
    }
    tcsetattr( fileno( stdin ), TCSANOW, &oldSettings );
    return '\0';
}
