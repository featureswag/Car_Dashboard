#ifndef __DISPLAY_H__
#define __DISPLAY_H__

//English Version display
void display_English_BasicInfo(void);
//Chinese Version display
void display_Chinese_BasicInfo(void);

//Module Info display
void display_SpeedInfo(uint16_t current_status);
void display_OilInfo(uint16_t current_status);

//Update program function
void update_SpeedInfo(void);
void update_OilInfo(uint16_t flag);



#endif // __DISPLAY_H__
