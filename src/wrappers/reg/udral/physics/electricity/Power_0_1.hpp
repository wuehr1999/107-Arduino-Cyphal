/**
 * This software is distributed under the terms of the MIT License.
 * Copyright (c) 2020 LXRobotics.
 * Author: Alexander Entinger <alexander.entinger@lxrobotics.com>
 * Contributors: https://github.com/107-systems/107-Arduino-Cyphal/graphs/contributors.
 */

#ifndef ARDUINO_UAVCAN_TYPES_REG_DRONE_PHYSICS_ELECTRICITY_POWER_0_1_H_
#define ARDUINO_UAVCAN_TYPES_REG_DRONE_PHYSICS_ELECTRICITY_POWER_0_1_H_

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include <libcanard/canard.h>

#include <types/reg/udral/physics/electricity/Power_0_1.h>

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

namespace reg {
namespace udral {
namespace physics {
namespace electricity {

/**************************************************************************************
 * CLASS DECLARATION
 **************************************************************************************/

template <CanardPortID ID>
class Power_0_1
{

public:

  reg_udral_physics_electricity_Power_0_1 data;

  static constexpr CanardPortID       PORT_ID          = ID;
  static constexpr size_t             MAX_PAYLOAD_SIZE = reg_udral_physics_electricity_Power_0_1_SERIALIZATION_BUFFER_SIZE_BYTES_;
  static constexpr CanardTransferKind TRANSFER_KIND    = CanardTransferKindMessage;


  Power_0_1()
  {
    reg_udral_physics_electricity_Power_0_1_initialize_(&data);
  }

  Power_0_1(Power_0_1 const & other)
  {
    memcpy(&data, &other.data, sizeof(data));
  }

  static Power_0_1 deserialize(CanardRxTransfer const & transfer)
  {
    Power_0_1 b;
    size_t inout_buffer_size_bytes = transfer.payload_size;
    reg_udral_physics_electricity_Power_0_1_deserialize_(&b.data, (uint8_t *)(transfer.payload), &inout_buffer_size_bytes);
    return b;
  }

  size_t serialize(uint8_t * payload) const
  {
    size_t inout_buffer_size_bytes = Power_0_1::MAX_PAYLOAD_SIZE;
    return (reg_udral_physics_electricity_Power_0_1_serialize_(&data, payload, &inout_buffer_size_bytes) < NUNAVUT_SUCCESS) ? 0 : inout_buffer_size_bytes;
  }
};

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

} /* reg */
} /* udral */
} /* physics */
} /* electricity */

#endif /* ARDUINO_UAVCAN_TYPES_REG_DRONE_PHYSICS_ELECTRICITY_POWER_0_1_H_ */
