#ifndef LINESENSOR_H
#define LINESENSOR_H

#define APDS9960_I2C_ADDR 0x39
#define ALSGAIN 0b11

template<typename WireClass>
class LineSensor {
  public:
    void setup() {
      Wire.begin();
      writeByte(0x80, 0b111);
      writeByte(0x8F, ALSGAIN);
      writeByte(0x9F, 0);
   }

    uint16_t getR() {
      getStatus();
      return readHighLow(0x96);
    }
    uint16_t getG() {
      getStatus();
      return readHighLow(0x98);
    }
    uint16_t getB() {
      getStatus();
      return readHighLow(0x9A);
    }
    uint16_t getC() {
      getStatus();
      return readHighLow(0x94);
    }
    uint8_t getProximity() {
      getStatus();
      return readByte(0x9c);
    }

  private:
    WireClass Wire;
    void writeByte(uint8_t addr, uint8_t value) {
      Wire.beginTransmission(APDS9960_I2C_ADDR);
      Wire.write(addr);
      Wire.write(value);
      Wire.endTransmission();
    }

    uint8_t readByte(uint8_t addr) {
      Wire.beginTransmission(APDS9960_I2C_ADDR);
      Wire.write(addr);
      Wire.endTransmission();
      Wire.requestFrom(APDS9960_I2C_ADDR, 1);
      uint8_t val;
      while (Wire.available()) {
        val = Wire.read();
      }
      return val;
    }

    uint16_t readHighLow(uint8_t addr) {
      return uint16_t(readByte(addr + 1)) << 8 | readByte(addr);
    }

    uint8_t getStatus() {
      return readByte(0x93);
    }

};

#endif
