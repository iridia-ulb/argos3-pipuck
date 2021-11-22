/**
 * @file <argos3/plugins/robots/pi-puck/hardware/pipuck_differential_drive_default_sensor.cpp>
 *
 * @author Michael Allwright - <allsey87@gmail.com>
 */

#include "pipuck_differential_drive_default_sensor.h"

#include <argos3/core/utility/logging/argos_log.h>
#include <argos3/plugins/robots/pi-puck/hardware/robot.h>

#include <iio.h>

#include <cmath>
#include <cerrno>

namespace argos {

   /****************************************/
   /****************************************/

   CPiPuckDifferentialDriveDefaultSensor::CPiPuckDifferentialDriveDefaultSensor() :
      m_psDevice(nullptr),
      m_psBuffer(nullptr),
      m_psLeft(nullptr),
      m_psRight(nullptr),
      m_fVelocityLeft(0.0f),
      m_fVelocityRight(0.0f) {}

   /****************************************/
   /****************************************/

   CPiPuckDifferentialDriveDefaultSensor::~CPiPuckDifferentialDriveDefaultSensor() {
      /* destroy buffer */
      if(m_psBuffer != nullptr) {
         ::iio_buffer_destroy(m_psBuffer);
      }
      /* unset trigger */
      if(m_psDevice != nullptr) {
         ::iio_device_set_trigger(m_psDevice, nullptr);         
      }
      /* disable channels */
      if(m_psLeft != nullptr) {
         ::iio_channel_disable(m_psLeft);
      }
      if(m_psRight != nullptr) {
         ::iio_channel_disable(m_psRight);
      }
   }
   
   /****************************************/
   /****************************************/
   
   void CPiPuckDifferentialDriveDefaultSensor::Init(TConfigurationNode& t_tree) {
      try {
         CCI_PiPuckDifferentialDriveSensor::Init(t_tree);
         /* Get context and trigger */
         iio_context* psContext = CRobot::GetInstance().GetContext();
         iio_device* psUpdateTrigger = CRobot::GetInstance().GetSensorUpdateTrigger();
         /* get a pointer to the device */
         m_psDevice = ::iio_context_find_device(psContext, "epuck-encoders");
         if(m_psDevice == nullptr) {
            THROW_ARGOSEXCEPTION("Could not find IIO device \"epuck-encoders\"");
         }
         /* get the channels */
         m_psLeft = ::iio_device_find_channel(m_psDevice, "angl0", false);
         if(m_psLeft == nullptr) {
            THROW_ARGOSEXCEPTION("Could not find IIO channel \"angl0\" for device "
                                 "\"epuck-encoders\"");
         }
         m_psRight = ::iio_device_find_channel(m_psDevice, "angl1", false);
         if(m_psRight == nullptr) {
            THROW_ARGOSEXCEPTION("Could not find IIO channel \"angl1\" for device "
                                 "\"epuck-encoders\"");
         }
         /* enable channels */
         ::iio_channel_enable(m_psLeft);
         ::iio_channel_enable(m_psRight);
         /* set trigger */
         ::iio_device_set_trigger(m_psDevice, psUpdateTrigger);
         /* create buffer */
         m_psBuffer = ::iio_device_create_buffer(m_psDevice, 1, false);
         if(m_psBuffer == nullptr) {
            THROW_ARGOSEXCEPTION("Could not create IIO buffer: " << ::strerror(errno));
         }
      }
      catch(CARGoSException& ex) {
         THROW_ARGOSEXCEPTION_NESTED("Initialization error in the Pi-Puck differential drive sensor.", ex);
      }
   }
  
   /****************************************/
   /****************************************/
   
   void CPiPuckDifferentialDriveDefaultSensor::Update() {
      SInt16 nLeftVelocityRaw, nRightVelocityRaw;
      /* fetch samples from the driver */
      ::iio_buffer_refill(m_psBuffer);
      ::iio_channel_read(m_psLeft, m_psBuffer, &nLeftVelocityRaw, 2);
      ::iio_channel_read(m_psRight, m_psBuffer, &nRightVelocityRaw, 2);
      /* convert samples to meters per second */
      m_fVelocityLeft = ConvertToMetersPerSecond(nLeftVelocityRaw);
      m_fVelocityRight = ConvertToMetersPerSecond(nRightVelocityRaw);
   }

   /****************************************/
   /****************************************/
   
   void CPiPuckDifferentialDriveDefaultSensor::Reset() {
      m_fVelocityLeft = Real(0);
      m_fVelocityRight = Real(0);
   }
   
   /****************************************/
   /****************************************/
   
   Real CPiPuckDifferentialDriveDefaultSensor::GetLeftVelocity() {
      return m_fVelocityLeft;
   }

   /****************************************/
   /****************************************/

   Real CPiPuckDifferentialDriveDefaultSensor::GetRightVelocity() {
      return -m_fVelocityRight;
   }

   /****************************************/
   /****************************************/

   REGISTER_SENSOR(CPiPuckDifferentialDriveDefaultSensor,
                   "pipuck_differential_drive", "default",
                   "Michael Allwright [allsey87@gmail.com]",
                   "1.0",
                   "The pipuck differential drive sensor.",
                   "This sensor monitors the differential drive of the Pi-Puck.",
                   "Usable"
   );

   /****************************************/
   /****************************************/

}
 
