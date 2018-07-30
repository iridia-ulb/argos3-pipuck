/**
 * @file <argos3/plugins/robots/builderbot/control_interface/ci_builderbot_lift_system_sensor.h>
 *
 * @author Michael Allwright - <allsey87@gmail.com>
 */

#ifndef CCI_BUILDERBOT_LIFT_SYSTEM_SENSOR_H
#define CCI_BUILDERBOT_LIFT_SYSTEM_SENSOR_H

namespace argos {
   class CCI_BuilderBotLiftSystemSensor;
}

#include <argos3/core/control_interface/ci_sensor.h>

namespace argos {

   class CCI_BuilderBotLiftSystemSensor : public CCI_Sensor {

   public:

      CCI_BuilderBotLiftSystemSensor() :
         m_unState(0),
         m_fPosition(140.0f),
         m_arrLimitSwitches({false, false}) {}

      virtual ~CCI_BuilderBotLiftSystemSensor() {}

      UInt8 GetState() const {
         return m_unState;
      }

      Real GetPosition() const {
         return m_fPosition;
      }

      const std::array<UInt8, 2>& GetLimitSwitches() const {
         return m_arrLimitSwitches;
      }

#ifdef ARGOS_WITH_LUA
      virtual void CreateLuaState(lua_State* pt_lua_state);

      virtual void ReadingsToLuaState(lua_State* pt_lua_state);
#endif

   protected:

      UInt8 m_unState;
      Real m_fPosition;
      std::array<UInt8, 2> m_arrLimitSwitches;

      static const std::array<const std::string, 5> m_arrStateStrings = {
         "inactive", "position_control", "speed_control",
         "calibration_search_top", "calibration_search_bottom" 
      };

   };

}

#endif
