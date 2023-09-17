#ifndef BALANCE_FILTER_h
#define BALANCE_FILTER_h

typedef struct {
	float q0;
	float q1;
	float q2;
	float q3;
	float acc_mag;

	// parameters
	float acc_confidence_decay;
	float kp;
} BalanceFilterData;

void balance_filter_init(BalanceFilterData *data);
void balance_filter_update(float *gyro_xyz, float *accel_xyz, float dt, BalanceFilterData *data);

float balance_filter_get_roll(BalanceFilterData *data);
float balance_filter_get_pitch(BalanceFilterData *data);
float balance_filter_get_yaw(BalanceFilterData *data);

#endif
