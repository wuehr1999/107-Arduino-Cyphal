/**
 * This software is distributed under the terms of the MIT License.
 * Copyright (c) 2020 LXRobotics.
 * Author: Alexander Entinger <alexander.entinger@lxrobotics.com>
 * Contributors: https://github.com/107-systems/107-Arduino-Cyphal/graphs/contributors.
 */

#ifndef ARDUINO_UAVCAN_TYPES_UAVCAN_REGISTER_VALUE_1_0_HPP_
#define ARDUINO_UAVCAN_TYPES_UAVCAN_REGISTER_VALUE_1_0_HPP_

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include <libcanard/canard.h>

#include <types/uavcan/register/Value_1_0.h>

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

namespace uavcan {
namespace _register {

/**************************************************************************************
 * CLASS DECLARATION
 **************************************************************************************/

template <CanardPortID ID>
class Value_1_0
{

public:

  uavcan_register_Value_1_0 data;

  static constexpr CanardPortID       PORT_ID          = ID;
  static constexpr size_t             MAX_PAYLOAD_SIZE = uavcan_register_Value_1_0_SERIALIZATION_BUFFER_SIZE_BYTES_;
  static constexpr CanardTransferKind TRANSFER_KIND    = CanardTransferKindMessage;

  Value_1_0()
  {
    uavcan_register_Value_1_0_initialize_(&data);
  }

  Value_1_0(Value_1_0 const & other)
  {
    memcpy(&data, &other.data, sizeof(data));
  }

  static Value_1_0 deserialize(CanardRxTransfer const & transfer)
  {
    Value_1_0<ID> b;
    size_t inout_buffer_size_bytes = transfer.payload_size;
    uavcan_register_Value_1_0_deserialize_(&b.data, (uint8_t *)(transfer.payload), &inout_buffer_size_bytes);
    return b;
  }

  size_t serialize(uint8_t * payload) const
  {
    size_t inout_buffer_size_bytes = Value_1_0::MAX_PAYLOAD_SIZE;
    return (uavcan_register_Value_1_0_serialize_(&data, payload, &inout_buffer_size_bytes) < NUNAVUT_SUCCESS) ? 0 : inout_buffer_size_bytes;
  }
};

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

} /* _register */
} /* uavcan */

#endif /* ARDUINO_UAVCAN_TYPES_UAVCAN_REGISTER_VALUE_1_0_HPP_ */
