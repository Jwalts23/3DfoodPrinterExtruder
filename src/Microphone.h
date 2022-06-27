#include <Arduino.h>

class Microphone {       // The class
  public:             // Access specifier
    int myNum;        // Attribute (int variable)
    int volPin = 10; // Attribute (string variable)

    Microphone(void);
    void Init(void);
    float CalcVolume(void);
};