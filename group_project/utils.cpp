/// @file utils.cpp
/// @author Adam T Koehler, PhD
/// @date May 27, 2025
/// @brief Utility functions for use in the group project.

#include <unistd.h>
#include <iostream>

const useconds_t SLEEP_USEC = 35000;
const bool ANIMATE = true;
const bool CLEAR_SCREEN = true;
const bool IN_COLOR = true;

/// @brief Sleep for animation based on project animation setting value.
void pause(float scale=1)
{
    if (ANIMATE)
    {
        usleep(static_cast<unsigned int>(SLEEP_USEC * scale));
    }
}

/// @brief Clear the console screen or output two newlines based on
///        the project setting for clearing the screen.
void clearScreen()
{
    if (CLEAR_SCREEN)
    {
        printf("\033[H\033[2J");
        fflush(stdout);
    }
    else
    {
        printf("\n\n");
        fflush(stdout);
    }
}


/////////////////////////////////////////
///  SETTING BACKGROUND TO COLORS     ///
///  https://i.sstatic.net/9UVnC.png  ///
/////////////////////////////////////////

/// @brief reset the background color to default
void resetColors()
{
    if (IN_COLOR)
    {
        printf("\033[0m");
        fflush(stdout);
    }
}

/// @brief set printout background color to green
void setBlackBackground()
{
    if (IN_COLOR)
    {
        printf("\033[40m");
        fflush(stdout);
    }
}

/// @brief set printout background color to green
void setBlueBackground()
{
    if (IN_COLOR)
    {
        printf("\033[44m");
        fflush(stdout);
    }
}

/// @brief set printout background color to green
void setGreenBackground()
{
    if (IN_COLOR)
    {
        printf("\033[42m");
        fflush(stdout);
    }
}

/// @brief set printout background color to green
void setRedBackground()
{
    if (IN_COLOR)
    {
        printf("\033[41m");
        fflush(stdout);
    }
}

/// @brief set printout background color to green
void setWhiteBackground()
{
    if (IN_COLOR)
    {
        printf("\033[47m");
        fflush(stdout);
    }
}

