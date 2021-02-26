/*******************************************************************************************
*
*   raylib [core] example - Basic window
*
*   Welcome to raylib!
*
*   To test examples, just press F6 and execute raylib_compile_execute script
*   Note that compiled executable is placed in the same folder as .c file
*
*   You can find all basic examples on C:\raylib\raylib\examples folder or
*   raylib official webpage: www.raylib.com
*
*   Enjoy using raylib. :)
*
*   This example has been created using raylib 1.0 (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   Copyright (c) 2014 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include "raylib.h"
#include <iostream>


unsigned int ElfHash(unsigned char* data)
{
    unsigned int hash = 0;
    unsigned int x = 0;

    for (unsigned char* i = data; *i != '\0'; ++i)
    {
        hash = (hash << 4) + *i;
        if ((x = hash & 0xF0000000L) != 0)
        {
            hash ^= (x >> 24);
            hash &= ~x;
        }
    }

    return (hash & 0x7FFFFFFF);
}


unsigned int MyHash(unsigned char* data)
{
    //Hash is given a value
    unsigned int hash = 0;
    unsigned int x = 0;

    //Iterates through the data and checks if its the end of the string
    for (unsigned char* i = data; *i != '\0'; ++i)
    {
        //Sets hash to hash shifted by 4
        hash = (hash << 4) + *i;

        //Checking if hash is null and setting X
        if ((x = hash & 0xF0000000L) != 0)
        {
            //Sets hash bit shifted to X by 24
            hash = (x >> 24);
            //X bit shifted into hash
            hash &= x;
            //Sets hash to be divided by 7
            hash = hash / 7;


        }
    }

    //Returns hash
    return (hash & 0x7FFFFFFF);
}

int main(int argc, char* argv[])
{
    // Initialization
    //--------------------------------------------------------------------------------------
    int screenWidth = 800;
    int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    SetTargetFPS(60);
    //--------------------------------------------------------------------------------------

    int checkSum = 0;
    unsigned char* input = new unsigned char[0];
    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {

        // Update
        //----------------------------------------------------------------------------------

        std::cin >> input;
        checkSum = MyHash(input);

        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(GetColor(checkSum));

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------   
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}