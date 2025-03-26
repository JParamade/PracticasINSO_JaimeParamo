#include "FiniteStateMachine.h"
#include <iostream>

void Ducking::Enter(Player* _pPlayer) { 
    printf("You are now \033[1;32mDucking\033[0m!\n\n"); 
}

void Ducking::HandleInput(Player* _pPlayer, PlayerInput _eInput) {
    if (_eInput == PlayerInput::PressA) _pPlayer->SetState(Standing::GetInstance());
}

void Ducking::Exit(Player* _pPlayer) { 
    printf("You stopped \033[1;31mDucking\033[0m!\n"); 
}

State& Ducking::GetInstance() {
    static Ducking oInstance;
    return oInstance;
}

void Standing::Enter(Player* _pPlayer) {
    printf("You are now \033[1;32mStanding\033[0m!\n\n");
}

void Standing::HandleInput(Player* _pPlayer, PlayerInput _eInput) {
    if (_eInput == PlayerInput::PressA) _pPlayer->SetState(Ducking::GetInstance());
    else _pPlayer->SetState(Jumping::GetInstance());
}

void Standing::Exit(Player* _pPlayer) {
    printf("You stopped \033[1;31mStanding\033[0m!\n");
}

State& Standing::GetInstance() {
    static Standing oInstance;
    return oInstance;
}

void Jumping::Enter(Player* _pPlayer) {
    printf("You are now \033[1;32mJumping\033[0m!\n\n");
}

void Jumping::HandleInput(Player* _pPlayer, PlayerInput _eInput) {
    if (_eInput == PlayerInput::PressA) _pPlayer->SetState(Diving::GetInstance());
}

void Jumping::Exit(Player* _pPlayer) {
    printf("You stopped \033[1;31mJumping\033[0m!\n");
}

State& Jumping::GetInstance() {
    static Jumping oInstance;
    return oInstance;
}

void Diving::Enter(Player* _pPlayer) {
    printf("You are now \033[1;32mDiving\033[0m!\n\n");
}

void Diving::HandleInput(Player* _pPlayer, PlayerInput _eInput) {
    
}

void Diving::Exit(Player* _pPlayer) {
    printf("You stopped \033[1;31mDiving\033[0m!\n");
}

State& Diving::GetInstance() {
    static Diving oInstance;
    return oInstance;
}

Player::Player() { 
    pCurrentState = &Standing::GetInstance(); 
}

State* Player::GetCurrentState() const { 
    return pCurrentState; 
}

void Player::HandleInput(PlayerInput _eInput) { 
    pCurrentState->HandleInput(this, _eInput); 
}

void Player::SetState(State& _rNewState) {
    pCurrentState->Exit(this);
    pCurrentState = &_rNewState;
    pCurrentState->Enter(this);
}