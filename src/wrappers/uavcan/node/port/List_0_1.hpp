/**
 * This software is distributed under the terms of the MIT License.
 * Copyright (c) 2020 LXRobotics.
 * Author: Alexander Entinger <alexander.entinger@lxrobotics.com>
 * Contributors: https://github.com/107-systems/107-Arduino-Cyphal/graphs/contributors.
 */

#ifndef ARDUINO_UAVCAN_TYPES_UAVCAN_NODE_PORT_LIST_0_1_HPP_
#define ARDUINO_UAVCAN_TYPES_UAVCAN_NODE_PORT_LIST_0_1_HPP_

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include <libcanard/canard.h>

#include <types/uavcan/node/port/List_0_1.h>

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
class List_0_1
{

public:

  uavcan_node_port_List_0_1 data;

  static constexpr CanardPortID       PORT_ID = ID;
  static constexpr size_t             MAX_PAYLOAD_SIZE = uavcan_node_port_List_0_1_SERIALIZATION_BUFFER_SIZE_BYTES_;
  static constexpr CanardTransferKind TRANSFER_KIND = CanardTransferKindMessage;

  List_0_1()
  {
    uavcan_node_port_List_0_1_initialize_(&data);
  }

  List_0_1(List_0_1 const & other)
  {
    memcpy(&data, &other.data, sizeof(data));
  }

  static List_0_1 deserialize(CanardRxTransfer const & transfer)
  {
    List_0_1<ID> i;
    size_t inout_buffer_size_bytes = transfer.payload_size;
    uavcan_node_port_List_0_1_deserialize_(&i.data, (uint8_t *)(transfer.payload), &inout_buffer_size_bytes);
    return i;
  }

  size_t serialize(uint8_t * payload) const
  {
    size_t inout_buffer_size_bytes = List_0_1<ID>::MAX_PAYLOAD_SIZE;
    return (uavcan_node_port_List_0_1_serialize_(&data, payload, &inout_buffer_size_bytes) < NUNAVUT_SUCCESS) ? 0 : inout_buffer_size_bytes;
  }
};

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

} /* port */
} /* node */
} /* uavcan */

#endif /* ARDUINO_UAVCAN_TYPES_UAVCAN_NODE_PORT_LIST_0_1_HPP_ */
