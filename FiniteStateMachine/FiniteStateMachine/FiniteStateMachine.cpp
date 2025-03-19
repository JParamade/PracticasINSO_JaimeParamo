#include <iostream>
#include <Windows.h>

#define GetKey(X) (!!(GetAsyncKeyState(0[#X])&0x8000))

class Player;

class State {
public:
    virtual void Enter(Player* _pPlayer) = 0;
    virtual void Toggle(Player* _pPlayer) = 0;
    virtual void Exit(Player* _pPlayer) = 0;
};

class Ducking : public State {
public:
    virtual void Enter(Player* _pPlayer) { printf(""); }
    virtual void Toggle(Player* _pPlayer) { printf(""); }
    virtual void Exit(Player* _pPlayer) { printf(""); }
};

class Standing : public State {
public:
    virtual void Enter(Player* _pPlayer) { printf(""); }
    virtual void Toggle(Player* _pPlayer) { printf(""); }
    virtual void Exit(Player* _pPlayer) { printf(""); }
};

class Jumping : public State {
public:
    virtual void Enter(Player* _pPlayer) { printf(""); }
    virtual void Toggle(Player* _pPlayer) { printf(""); }
    virtual void Exit(Player* _pPlayer) { printf(""); }
};

class Diving : public State {
public:
    virtual void Enter(Player* _pPlayer) { printf(""); }
    virtual void Toggle(Player* _pPlayer) { printf(""); }
    virtual void Exit(Player* _pPlayer) { printf(""); }
};

class Player {
public:
    void SetState(State& _rNewState) {
        pCurrentState->Exit(this);
        pCurrentState = &_rNewState;
        pCurrentState->Enter(this);
    }

private:
    State* pCurrentState;
};

int main()
{

}