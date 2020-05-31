#include "State.h"

State::State():probablity(0),name("") {
}
State::~State(){}

State::State(double probablity,string name):probablity(probablity),name(name) {
}

Suspected::Suspected():State(PSI,"ºñ°¨¿°ÀÚ"){}



Infected::Infected():State(PIR,"°¨¿°ÀÚ") {}

Removed::Removed():State(PRI,"È¸º¹ ¹× »ç¸Á"){}