// Copyright 2022 Benjamin Vedder <benjamin@vedder.se>
//
// This file is part of the Refloat VESC package.
//
// Refloat VESC package is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by the
// Free Software Foundation, either version 3 of the License, or (at your
// option) any later version.
//
// Refloat VESC package is distributed in the hope that it will be useful, but
// WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
// or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
// more details.
//
// You should have received a copy of the GNU General Public License along with
// this program. If not, see <http://www.gnu.org/licenses/>.

#ifndef DATATYPES_H_
#define DATATYPES_H_

#include <stdbool.h>
#include <stdint.h>

typedef enum {
    INPUTTILT_NONE = 0,
    INPUTTILT_UART,
    INPUTTILT_PPM
} FLOAT_INPUTTILT_REMOTE_TYPE;

typedef enum {
    LED_TYPE_NONE = 0,
    LED_TYPE_RGB,
    LED_TYPE_RGBW,
    LED_TYPE_EXTERNAL,
} LedType;

typedef enum {
    LED_PIN_B6 = 0,
    LED_PIN_B7
} LedPin;

typedef enum {
    COLOR_BLACK = 0,
    COLOR_WHITE_FULL,
    COLOR_WHITE_RGB,
    COLOR_WHITE_SINGLE,
    COLOR_RED,
    COLOR_FERRARI,
    COLOR_FLAME,
    COLOR_CORAL,
    COLOR_SUNSET,
    COLOR_SUNRISE,
    COLOR_GOLD,
    COLOR_ORANGE,
    COLOR_YELLOW,
    COLOR_BANANA,
    COLOR_LIME,
    COLOR_ACID,
    COLOR_SAGE,
    COLOR_GREEN,
    COLOR_MINT,
    COLOR_TIFFANY,
    COLOR_CYAN,
    COLOR_STEEL,
    COLOR_SKY,
    COLOR_AZURE,
    COLOR_SAPPHIRE,
    COLOR_BLUE,
    COLOR_VIOLET,
    COLOR_AMETHYST,
    COLOR_MAGENTA,
    COLOR_PINK,
    COLOR_FUCHSIA,
    COLOR_LAVENDER,
} LedColor;

typedef enum {
    LED_MODE_SOLID = 0,
    LED_MODE_FADE,
    LED_MODE_PULSE,
    LED_MODE_STROBE,
    LED_MODE_KNIGHT_RIDER
} LedMode;

typedef enum {
    LED_TRANS_FADE = 0,
    LED_TRANS_FADE_OUT_IN,
    LED_TRANS_CIPHER,
    LED_TRANS_MONO_CIPHER,
} LedTransition;

typedef struct {
    LedMode mode;
    float brightness;
    LedColor color1;
    LedColor color2;
    float speed;
} LedBar;

typedef struct {
    float brightness_headlights_off;
    float brightness_headlights_on;
    bool show_sensors_while_running;
    float duty_threshold;
    float red_bar_percentage;
    uint16_t idle_timeout;
} StatusBar;

typedef struct {
    bool on;
    bool headlights_on;

    LedTransition headlights_transition;
    LedTransition direction_transition;

    bool lights_off_when_lifted;
    bool status_on_front_when_lifted;

    LedBar headlights;
    LedBar taillights;
    LedBar front;
    LedBar rear;
    StatusBar status;
    LedBar status_idle;
} CfgLeds;

typedef struct {
    uint8_t count;
    bool reverse;
} CfgLedStrip;

typedef struct {
    LedType type;
    LedPin pin;
    CfgLedStrip status;
    CfgLedStrip front;
    CfgLedStrip rear;
} CfgHwLeds;

typedef struct {
    CfgHwLeds leds;
} CfgHardware;

typedef enum {
    NO_TUNE_B = 0,
    ACCELERATION_BASED = 1,
    ERPM_BASED = 2
} TUNES_MIXING_MODE;

typedef enum {
    ALL_TOGETHER = 0,
    B_THEN_C = 1,
    C_THEN_B = 2
} TRANSITIONS_ORDER_MODE;

typedef struct {
    float kp;
    float kp_b;
    float kp_c;
    float ki;
    float ki_b;
    float ki_c;
    float kp2;
    float kp2_b;
    float kp2_c;
    float mahony_kp;
    float mahony_kp_roll;
    float mahony_kp_yaw;
    float bf_accel_confidence_decay;
    uint16_t hertz;
    float fault_pitch;
    float fault_roll;
    float fault_adc1;
    float fault_adc2;
    bool is_footbeep_enabled;
    uint16_t fault_delay_pitch;
    uint16_t fault_delay_roll;
    uint16_t fault_delay_switch_half;
    uint16_t fault_delay_switch_full;
    uint16_t fault_adc_half_erpm;
    bool fault_is_dual_switch;
    bool fault_moving_fault_disabled;
    bool fault_darkride_enabled;
    bool fault_reversestop_enabled;
    float tiltback_duty_angle;
    float tiltback_duty_speed;
    float tiltback_duty;
    bool is_dutybeep_enabled;
    float surge_angle;
    float surge_duty_start;
    bool is_surgebeep_enabled;
    float tiltback_hv_angle;
    float tiltback_hv_speed;
    float tiltback_hv;
    float tiltback_lv_angle;
    float tiltback_lv_speed;
    float tiltback_lv;
    float tiltback_return_speed;
    float tiltback_constant;
    uint16_t tiltback_constant_erpm;
    float tiltback_variable;
    float tiltback_variable_max;
    uint16_t tiltback_variable_erpm;
    float noseangling_speed;
    FLOAT_INPUTTILT_REMOTE_TYPE inputtilt_remote_type;
    float inputtilt_speed;
    float inputtilt_angle_limit;
    uint8_t inputtilt_smoothing_factor;
    bool inputtilt_invert_throttle;
    float inputtilt_deadband;
    float remote_throttle_current_max;
    float remote_throttle_grace_period;
    float startup_pitch_tolerance;
    float startup_roll_tolerance;
    float startup_speed;
    float startup_click_current;
    bool startup_simplestart_enabled;
    bool startup_pushstart_enabled;
    bool startup_dirtylandings_enabled;
    float brake_current;
    float ki_limit;
    float ki_limit_b;
    float ki_limit_c;
    float booster_angle;
    float booster_angle_b;
    float booster_angle_c;
    float booster_ramp;
    float booster_ramp_b;
    float booster_ramp_c;
    float booster_current;
    float booster_current_b;
    float booster_current_c;
    float torquetilt_start_current;
    float torquetilt_angle_limit;
    float torquetilt_on_speed;
    float torquetilt_off_speed;
    float torquetilt_strength;
    float torquetilt_strength_regen;
    float turntilt_strength;
    float turntilt_angle_limit;
    float turntilt_start_angle;
    uint16_t turntilt_start_erpm;
    float turntilt_speed;
    uint16_t turntilt_erpm_boost;
    uint16_t turntilt_erpm_boost_end;
    uint16_t turntilt_yaw_aggregate;
    float atr_strength_up;
    float atr_strength_down;
    float atr_threshold_up;
    float atr_threshold_down;
    float atr_speed_boost;
    float atr_angle_limit;
    float atr_on_speed;
    float atr_off_speed;
    float atr_response_boost;
    float atr_transition_boost;
    float atr_filter;
    float atr_amps_accel_ratio;
    float atr_amps_decel_ratio;
    float braketilt_strength;
    float braketilt_lingering;
    CfgLeds leds;
    CfgHardware hardware;
    float dark_pitch_offset;
    bool is_beeper_enabled;
    bool disabled;
    float brake_max_amp_change_a;
    float brake_max_amp_change_b;
    float brake_max_amp_change_c;
    float current_out_filter_a;
    float current_out_filter_b;
    float current_out_filter_c;
    TRANSITIONS_ORDER_MODE transitions_order;
    TUNES_MIXING_MODE tunes_mixing_b;
    TUNES_MIXING_MODE tunes_mixing_c;
    float tune_a_transition_speed;
    float tune_b_transition_speed;
    float tune_c_transition_speed;
    bool tune_b_only_for_brakes;
    bool tune_c_only_for_brakes;
    float asym_min_accel_b;
    float asym_max_accel_b;
    uint16_t asym_min_erpm_b;
    uint16_t asym_max_erpm_b;
    float asym_min_accel_c;
    float asym_max_accel_c;
    uint16_t asym_min_erpm_c;
    uint16_t asym_max_erpm_c;
} RefloatConfig;

// DATATYPES_H_
#endif
