#include "PinHit.h"

//default constructor for PinHit.
//precondition: none.
//Postcondition: a pinhit object used to signify an
//"empty" slot in the vector of pinhits. The value
//of m_pin and m_hits will never be used legitimately.
PinHit::PinHit() {
    m_pin = -1;
    m_hits = -1;
}
//non-default constructor for PinHit.
//Precondition: a pin number and a value for the pin.
//Postcondition: a valid PinHit object.
PinHit::PinHit(int key, int value) {
    m_pin = key;
    m_hits = value;
}
//SetKey.
//public function that sets a private variable.
void PinHit::SetKey(int pin) {
    m_pin = pin;
}
//GetKey
//public function that sets a private variable.
int PinHit::GetKey() const {
    return m_pin;
}
//GetValue
//public function that returns a private variable.
int PinHit::GetValue() const {
    return m_hits;
}
//IncrementHits
//Increments m_hits.
void PinHit::IncrementHits() {
    m_hits++;
}
//CompareTo
//Compares the hits of this pin to another pin.
//precondition: another PinHit object
//postcondition: negative if this is smaller, positive if
//this is bigger, 0 if the same.
int PinHit::CompareTo(const PinHit& other) const {
    return(this->GetValue() - other.GetValue());
}
//overloaded == operator
//returns true if pins are the same, false otherwise.
//Precondition: another PinHit object
//Postcondition: boolean.
bool PinHit::operator==(const PinHit& other) {
    if(this->GetKey() == other.GetKey()){
        return true;
    }
    return false;
}

