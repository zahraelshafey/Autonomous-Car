 /*
 * SERVO_config.h
 *
 *  Author: zahra ahmed elshafey
 */ 
#ifndef SERVO_CONFIG_H_
#define SERVO_CONFIG_H_

/* values are Timer1 ticks (1 tick = 4us) */
#define SERVO_MIN_DUTY      250    /* 1.0ms = -90 deg */
#define SERVO_MAX_DUTY      500    /* 2.0ms = +90 deg */
#define SERVO_CENTER_DUTY   375    /* 1.5ms =   0 deg */

#define SERVO_MIN_ANGLE     -90
#define SERVO_MAX_ANGLE      90

#endif /* SERVO_CONFIG_H_ */