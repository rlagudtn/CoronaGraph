#include "State.h"

State::State():probablity(0),name("") {
}
State::~State(){}

State::State(double probablity,string name):probablity(probablity),name(name) {
}

Suspected::Suspected():State(PSI,"�񰨿���"){}



Infected::Infected():State(PIR,"������") {}

Removed::Removed():State(PRI,"ȸ�� �� ���"){}