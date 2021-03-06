/**
 * @file <argos3/plugins/robots/pi-puck/hardware/pipuck_system_default_sensor.h>
 *
 * @author Michael Allwright <allsey87@gmail.com>
 */

#ifndef PIPUCK_SYSTEM_DEFAULT_SENSOR_H
#define PIPUCK_SYSTEM_DEFAULT_SENSOR_H

namespace argos {
   class CPiPuckSystemDefaultSensor;
}

#include <argos3/plugins/robots/pi-puck/hardware/sensor.h>
#include <argos3/plugins/robots/pi-puck/control_interface/ci_pipuck_system_sensor.h>

#include <chrono>

namespace argos {

   class CPiPuckSystemDefaultSensor : public CPhysicalSensor,
                                      public CCI_PiPuckSystemSensor {

   public:

      /**
       * @brief Constructor.
       */
      CPiPuckSystemDefaultSensor() {}

      /**
       * @brief Destructor.
       */
      virtual ~CPiPuckSystemDefaultSensor() {}

      virtual void Init(TConfigurationNode& t_tree) override;

      virtual void Reset() override;

      virtual void Update() override;

   private:

      std::chrono::steady_clock::time_point m_tpInit;

   };
}

#endif
