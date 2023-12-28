#ifndef __HALL_ENCODER_H__
#define __HALL_ENCODER_H__

void HALL_SENSOR_Init(void);
uint16_t getCycleCount(void);
uint16_t getTravelledDistance(void);
#endif // __HALL_ENCODER_H__
