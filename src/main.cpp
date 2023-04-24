/*
 * Copyright (c) 2023, CATIE
 * SPDX-License-Identifier: Apache-2.0
 */
#include "mbed.h"
#include "odometry_example.h"

// Define the odometry rate
#define ODOM_RATE 100ms

static DigitalOut led1(LED1);

#define ODOM_FLAG 0x01
Ticker OdomUpdateTicker;
EventFlags OdomFlag;

void OdomFlagUpdate()
{
    OdomFlag.set(ODOM_FLAG);
}

int main()
{
    // First, convert the rate of the loop in hertz [float]
    auto f_secs = std::chrono::duration_cast<std::chrono::duration<float>>(ODOM_RATE);
    float hz_odom = 1.0f / f_secs.count();

    // Create a fake/simulated odometry (see odometry_example.h for more infos)
    sixtron::OdometryExample my_simulated_odometry(hz_odom);
    my_simulated_odometry.init();

    // Setup ticker to update odometry flag at exactly the defined rate
    OdomUpdateTicker.attach(&OdomFlagUpdate, ODOM_RATE);

    while (true) {
        // Wait for Odom tick
        OdomFlag.wait_any(ODOM_FLAG);
        led1 = !led1;

        // Update odometry
        my_simulated_odometry.update();

        // Print odometry values
        printf("Odometry: X=%3.3f, Y=%3.3f, Theta=%3.3frad\n",
                my_simulated_odometry.getX(),
                my_simulated_odometry.getY(),
                my_simulated_odometry.getTheta());
    }
}
