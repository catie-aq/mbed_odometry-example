/*
 * Copyright (c) 2023, CATIE
 * SPDX-License-Identifier: Apache-2.0
 */

// ============ THIS FILE IS APPLICATION SPECIFIC ========================

#include "odometry_example.h"

namespace sixtron {

void OdometryExample::init()
{

    _fake_counter_left = 0;
    _fake_counter_right = 0;
}

void OdometryExample::update()
{

    // update the simulated sensors
    _fake_counter_left += ENC_REVOLUTION / 5;
    _fake_counter_right += 2 * ENC_REVOLUTION;

    // update odometry
    compute(_fake_counter_left, _fake_counter_right);
}
}
