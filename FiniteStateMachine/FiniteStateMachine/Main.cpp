#include "FiniteStateMachine.h"
#include <Windows.h>
#include <iostream>

#define GetKey(X) (!!(GetAsyncKeyState(X)&0x0001))

int main() {
    Player oMyPlayer;

    if (oMyPlayer.GetCurrentState() == &Ducking::GetInstance()) printf("You are \033[1;32mDucking\033[0m!\n\n");
    else if (oMyPlayer.GetCurrentState() == &Standing::GetInstance()) printf("You are \033[1;32mStanding\033[0m!\n\n");
    else if (oMyPlayer.GetCurrentState() == &Jumping::GetInstance()) printf("You are \033[1;32mJumping\033[0m!\n\n");
    else if (oMyPlayer.GetCurrentState() == &Diving::GetInstance()) printf("You are \033[1;32mDiving\033[0m!\n\n");

    while (!GetKey(VK_ESCAPE)) {
        if (GetKey(0x41)) oMyPlayer.HandleInput(PlayerInput::PressA);
        else if (GetKey(0x42)) oMyPlayer.HandleInput(PlayerInput::PressB);

        Sleep(50);
    }

    return 0;
}