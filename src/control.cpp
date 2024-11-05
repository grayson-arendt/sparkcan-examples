#include "SparkMax.hpp"
#include <iostream>

/*
This has been tested with the SPARK MAX connected to a NEO Brushless Motor V1.1.
*/

int main()
{
    try
    {
        // Initialize SparkMax object with CAN interface and CAN ID
        SparkMax motor("can0", 18);

        motor.SetIdleMode(IdleMode::kCoast);
        motor.SetMotorType(MotorType::kBrushless);
        motor.SetInverted(true);
        motor.BurnFlash();
   
        // Loop for 10 seconds
        auto start = std::chrono::high_resolution_clock::now();
        while (std::chrono::duration_cast<std::chrono::seconds>(
                   std::chrono::high_resolution_clock::now() - start)
                   .count() < 10)
        {
            SparkMax::Heartbeat();
            motor.SetDutyCycle(0.1);
            
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return -1;
    }

    return 0;
}
