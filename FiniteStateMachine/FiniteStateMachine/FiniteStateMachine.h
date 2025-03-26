#pragma once

enum class PlayerInput {
    PressA,
    PressB
};

class Player;

class State {
public:
    virtual void Enter(Player* _pPlayer) = 0;
    virtual void HandleInput(Player* _pPlayer, PlayerInput _eInput) = 0;
    virtual void Exit(Player* _pPlayer) = 0;
};

class Ducking : public State {
public:
    virtual void Enter(Player* _pPlayer);
    virtual void HandleInput(Player* _pPlayer, PlayerInput _eInput);
    virtual void Exit(Player* _pPlayer);

    static State& GetInstance();
};

class Standing : public State {
public:
    virtual void Enter(Player* _pPlayer);
    virtual void HandleInput(Player* _pPlayer, PlayerInput _eInput);
    virtual void Exit(Player* _pPlayer);

    static State& GetInstance();
};

class Jumping : public State {
public:
    virtual void Enter(Player* _pPlayer);
    virtual void HandleInput(Player* _pPlayer, PlayerInput _eInput);
    virtual void Exit(Player* _pPlayer);

    static State& GetInstance();
};

class Diving : public State {
public:
    virtual void Enter(Player* _pPlayer);
    virtual void HandleInput(Player* _pPlayer, PlayerInput _eInput);
    virtual void Exit(Player* _pPlayer);

    static State& GetInstance();
};

class Player {
public:
    Player();
    State* GetCurrentState() const;

    void HandleInput(PlayerInput _eInput);

    void SetState(State& _rNewState);

private:
    State* pCurrentState;
};