/**
 * This software is distributed under the terms of the MIT License.
 * Copyright (c) 2020 LXRobotics.
 * Author: Alexander Entinger <alexander.entinger@lxrobotics.com>
 * Contributors: https://github.com/107-systems/107-Arduino-Cyphal/graphs/contributors.
 */

#ifndef ARDUINO_UAVCAN_TYPES_UAVCAN_NODE_PORT_ID_1_0_HPP_
#define ARDUINO_UAVCAN_TYPES_UAVCAN_NODE_PORT_ID_1_0_HPP_

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include <libcanard/canard.h>

#include <types/uavcan/node/port/ID_1_0.h>

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

namespace uavcan {
namespace node {
namespace port {

/**************************************************************************************
 * CLASS DECLARATION
 **************************************************************************************/

template <CanardPortID ID>
class ID_1_0
{

public:

  uavcan_node_port_ID_1_0 data;

  static constexpr CanardPortID       PORT_ID = ID;
  static constexpr size_t             MAX_PAYLOAD_SIZE = uavcan_node_port_ID_1_0_SERIALIZATION_BUFFER_SIZE_BYTES_;
  static constexpr CanardTransferKind TRANSFER_KIND = CanardTransferKindMessage;

  ID_1_0()
  {
    uavcan_node_port_ID_1_0_initialize_(&data);
  }

  ID_1_0(ID_1_0 const & other)
  {
    memcpy(&data, &other.data, sizeof(data));
  }

  static ID_1_0 deserialize(CanardRxTransfer const & transfer)
  {
    ID_1_0<ID> i;
    size_t inout_buffer_size_bytes = transfer.payload_size;
    uavcan_node_port_ID_1_0_deserialize_(&i.data, (uint8_t *)(transfer.payload), &inout_buffer_size_bytes);
    return i;
  }

  size_t serialize(uint8_t * payload) const
  {
    size_t inout_buffer_size_bytes = ID_1_0<ID>::MAX_PAYLOAD_SIZE;
    return (uavcan_node_port_ID_1_0_serialize_(&data, payload, &inout_buffer_size_bytes) < NUNAVUT_SUCCESS) ? 0 : inout_buffer_size_bytes;
  }
};

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

} /* port */
} /* node */
} /* uavcan */

#endif /* ARDUINO_UAVCAN_TYPES_UAVCAN_NODE_PORT_ID_1_0_HPP_ */
