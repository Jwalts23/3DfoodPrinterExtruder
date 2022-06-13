
class IrSensor {       // The class
  public:             // Access specifier
    int myNum;        // Attribute (int variable)
    char myString;  // Attribute (string variable)

    IrSensor(void);
    void Init(void);
    float CalcDistance(void);
};