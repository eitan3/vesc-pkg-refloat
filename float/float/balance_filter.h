#ifndef BALANCE_FILTER_h
#define BALANCE_FILTER_h

typedef struct {
	float q0;
	float q1;
	float q2;
	float q3;
	float integralFBx;
	float integralFBy;
	float integralFBz;
	float acc_mag;

	// parameters
	float acc_confidence_decay;
	float kp;
	float ki;
} BalanceFilterData;

void balance_filter_init(BalanceFilterData *data);
void balance_filter_update(float *gyroXYZ, float *accelXYZ, float dt, BalanceFilterData *data);

float balance_filter_get_roll(BalanceFilterData *data);
float balance_filter_get_pitch(BalanceFilterData *data);
float balance_filter_get_yaw(BalanceFilterData *data);

#endif
