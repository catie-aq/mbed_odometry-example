/*
 * Copyright (c) 2023, CATIE
 * SPDX-License-Identifier: Apache-2.0
 */

// ============ THIS FILE IS APPLICATION SPECIFIC ========================

#ifndef ODOMETRY_EXAMPLE_H
#define ODOMETRY_EXAMPLE_H

#include "mbed.h"
#include "odometry/odometry_two_encoders.h"

namespace sixtron {

#define ENC_REVOLUTION 4096
#define MOTOR_REDUCTION 100
#define ENC_WHEEL_RADIUS (0.05f) // in meters
#define ENC_WHEELS_DISTANCE (0.40f) // in meters

class OdometryExample: public OdometryTwoEncoders {

public:
    OdometryExample(float rate_hz):
            OdometryTwoEncoders(rate_hz,
                    (ENC_REVOLUTION * MOTOR_REDUCTION),
                    ENC_WHEEL_RADIUS,
                    ENC_WHEELS_DISTANCE) {};

    ~OdometryExample() = default;

    // Specific for Example, init the fake encoders
    void init() override;

    // Specific for Example, update the fake encoders
    void update() override;

private:
    int64_t _fake_counter_left;
    int64_t _fake_counter_right;
};
}

#endif // ODOMETRY_EXAMPLE_H
