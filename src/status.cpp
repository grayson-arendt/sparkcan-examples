#include <chrono>
#include <iomanip>
#include <iostream>

#include "SparkMax.hpp"

/*
This has been tested with the SPARK MAX while connected to a NEO V1.1.
*/

int main()
{
  try {
    // Initialize SparkMax object with CAN interface and CAN ID
    SparkMax motor("can0", 1);

    // Loop for 10 seconds
    auto start = std::chrono::high_resolution_clock::now();
    while (std::chrono::duration_cast<std::chrono::seconds>(
        std::chrono::high_resolution_clock::now() - start).count() < 10)
    {
      // Enable and run motor
      motor.Heartbeat();
      motor.SetDutyCycle(0.5);

      // Display motor status
      std::cout << std::fixed << std::setprecision(2);
      std::cout << "\r";
      std::cout << "Duty Cycle: " << motor.GetDutyCycle() << " ";
      std::cout << "Velocity: " << motor.GetVelocity() << " RPM, ";
      std::cout << "Position: " << motor.GetPosition() << " ticks";
      std::cout.flush();
    }
    std::cout << std::endl;
  } catch (const std::exception & e) {
    std::cerr << "Error: " << e.what() << std::endl;
    return -1;
  }
  return 0;
}
