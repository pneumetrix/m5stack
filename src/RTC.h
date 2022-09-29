#ifndef __RTC_H__
#define __RTC_H__

//#include <Wire.h>
#include "mgos_i2c.h"
typedef struct
{
  uint8_t Hours;
  uint8_t Minutes;
  uint8_t Seconds;
}RTC_TimeTypeDef;


typedef struct
{
  uint8_t WeekDay;
  uint8_t Month;
  uint8_t Date;
  uint16_t Year;
}RTC_DateTypeDef;

#define RTC_ADDR 0X51

class RTC { 
public:
  RTC();

  void begin(void);
  void GetBm8563Time(void);

  void SetTime(RTC_TimeTypeDef* RTC_TimeStruct);
  void SetDate(RTC_DateTypeDef* RTC_DateStruct);

  void GetTime(RTC_TimeTypeDef* RTC_TimeStruct);
  void GetDate(RTC_DateTypeDef* RTC_DateStruct); 

  int SetAlarmIRQ(int afterSeconds);
  int SetAlarmIRQ( const RTC_TimeTypeDef &RTC_TimeStruct);
  int SetAlarmIRQ( const RTC_DateTypeDef &RTC_DateStruct, const RTC_TimeTypeDef &RTC_TimeStruct);
  
  void clearIRQ();
  void disableIRQ();

public:
  uint8_t Second;
  uint8_t Minute;
  uint8_t Hour;
  uint8_t Week;
  uint8_t Day;
  uint8_t Month;
  uint8_t Year;
  uint8_t DateString[9];
  uint8_t TimeString[9];

  uint8_t asc[14];

  
private:
  void Bcd2asc(void);
  void DataMask();
  void Str2Time(void);
  void WriteReg(uint8_t reg, uint8_t data);
  uint8_t ReadReg(uint8_t reg);
  uint8_t Bcd2ToByte(uint8_t Value);
  uint8_t ByteToBcd2(uint8_t Value);
   
private:
  /*Define an array to store the read time data */
  uint8_t trdata[7]; 
  /*Define an array to store the converted asc code time data*/
  //uint8_t asc[14]; 

};

#endif
