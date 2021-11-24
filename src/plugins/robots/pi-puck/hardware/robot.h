/**
 * @file <argos3/plugins/robots/pi-puck/hardware/robot.h>
 *
 * @author Michael Allwright - <allsey87@gmail.com>
 */

#ifndef ROBOT_H
#define ROBOT_H

namespace argos {
   class CPhysicalSensor;
   class CPhysicalActuator;
   class CCI_Controller;
}

struct iio_context;
struct iio_device;

#include <argos3/core/utility/math/rng.h>
#include <argos3/core/utility/networking/tcp_socket.h>
#include <argos3/core/utility/configuration/argos_configuration.h>


namespace argos {

   class CRobot {

   public:

      static CRobot& GetInstance() {
         static CRobot cRobot;
         return cRobot;
      }

      void Init(TConfigurationNode& t_controller,
                const std::string& str_controller_id,
                const std::string& str_router_addr,
                UInt32 un_ticks_per_sec,
                UInt32 un_length);

      void Execute();

      void Destroy();

      void SetSignal(int n_signal) {
         m_bSignalRaised = true;
         m_strSignal = ::strsignal(n_signal);
      }

      iio_context* GetContext() {
         return m_psContext;
      }

      iio_device* GetActuatorUpdateTrigger() {
         return m_psActuatorUpdateTrigger;
      }

      iio_device* GetSensorUpdateTrigger() {
         return m_psSensorUpdateTrigger;
      }

      UInt32 GetTicksPerSec() {
         return m_unTicksPerSec;
      }

      CTCPSocket& GetSocket() {
         return m_cSocket;
      }

   private:

      CRobot() :
         m_bSignalRaised(false),
         m_unTicksPerSec(0),
         m_unLength(0),
         m_pcController(nullptr),
         m_psContext(nullptr),
         m_psSensorUpdateTrigger(nullptr),
         m_psActuatorUpdateTrigger(nullptr) {}

      virtual ~CRobot() {}

   private:

      /* signal handling variables */
      bool m_bSignalRaised;
      std::string m_strSignal;

      /* target tick length for the controller */
      UInt32 m_unTicksPerSec;

      /* number of ticks to run */
      UInt32 m_unLength;

      /* pointer to the controller */
      CCI_Controller* m_pcController;

      /* connection to the message router */
      CTCPSocket m_cSocket;

      /* the vector of actuators */
      std::vector<CPhysicalActuator*> m_vecActuators;

      /* the vector of sensors */
      std::vector<CPhysicalSensor*> m_vecSensors;

      /* triggers for updating the sensors and actuators */
      iio_context* m_psContext;
      iio_device* m_psSensorUpdateTrigger;
      iio_device* m_psActuatorUpdateTrigger;
   };

}

#endif
