/**
 * This software is distributed under the terms of the MIT License.
 * Copyright (c) 2020 LXRobotics.
 * Author: Alexander Entinger <alexander.entinger@lxrobotics.com>
 * Contributors: https://github.com/107-systems/107-Arduino-Cyphal/graphs/contributors.
 */

#ifndef ARDUINO_UAVCAN_TYPES_UAVCAN_PNP_CLUSTER_APPENDENTRIES_1_0_HPP_
#define ARDUINO_UAVCAN_TYPES_UAVCAN_PNP_CLUSTER_APPENDENTRIES_1_0_HPP_

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include <libcanard/canard.h>

#include <types/uavcan/pnp/cluster/AppendEntries_1_0.h>

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

namespace uavcan {
namespace pnp {
namespace cluster {
namespace AppendEntries_1_0 {

/**************************************************************************************
 * CLASS DECLARATION
 **************************************************************************************/

template <CanardPortID ID = uavcan_pnp_cluster_AppendEntries_1_0_FIXED_PORT_ID_>
class Request
{

public:

  uavcan_pnp_cluster_AppendEntries_Request_1_0 data;

  static constexpr CanardPortID       PORT_ID          = ID;
  static constexpr size_t             MAX_PAYLOAD_SIZE = uavcan_pnp_cluster_AppendEntries_Request_1_0_SERIALIZATION_BUFFER_SIZE_BYTES_;
  static constexpr CanardTransferKind TRANSFER_KIND    = CanardTransferKindMessage;

  Request()
  {
    uavcan_pnp_cluster_AppendEntries_Request_1_0_initialize_(&data);
  }

  Request(Request const & other)
  {
    memcpy(&data, &other.data, sizeof(data));
  }

  static Request deserialize(CanardRxTransfer const & transfer)
  {
    Request<ID> i;
    size_t inout_buffer_size_bytes = transfer.payload_size;
    uavcan_pnp_cluster_AppendEntries_Request_1_0_deserialize_(&i.data, (uint8_t *)(transfer.payload), &inout_buffer_size_bytes);
    return i;
  }

  size_t serialize(uint8_t * payload) const
  {
    size_t inout_buffer_size_bytes = Request<ID>::MAX_PAYLOAD_SIZE;
    return (uavcan_pnp_cluster_AppendEntries_Request_1_0_serialize_(&data, payload, &inout_buffer_size_bytes) < NUNAVUT_SUCCESS) ? 0 : inout_buffer_size_bytes;
  }
};

template <CanardPortID ID = uavcan_pnp_cluster_AppendEntries_1_0_FIXED_PORT_ID_>
class Response
{

public:

  uavcan_pnp_cluster_AppendEntries_Response_1_0 data;

  static constexpr CanardPortID       PORT_ID          = ID;
  static constexpr size_t             MAX_PAYLOAD_SIZE = uavcan_pnp_cluster_AppendEntries_Response_1_0_SERIALIZATION_BUFFER_SIZE_BYTES_;
  static constexpr CanardTransferKind TRANSFER_KIND    = CanardTransferKindMessage;

  Response()
  {
    uavcan_pnp_cluster_AppendEntries_Response_1_0_initialize_(&data);
  }

  Response(Response const & other)
  {
    memcpy(&data, &other.data, sizeof(data));
  }

  static Response deserialize(CanardRxTransfer const & transfer)
  {
    Response<ID> i;
    size_t inout_buffer_size_bytes = transfer.payload_size;
    uavcan_pnp_cluster_AppendEntries_Response_1_0_deserialize_(&i.data, (uint8_t *)(transfer.payload), &inout_buffer_size_bytes);
    return i;
  }

  size_t serialize(uint8_t * payload) const
  {
    size_t inout_buffer_size_bytes = Response<ID>::MAX_PAYLOAD_SIZE;
    return (uavcan_pnp_cluster_AppendEntries_Response_1_0_serialize_(&data, payload, &inout_buffer_size_bytes) < NUNAVUT_SUCCESS) ? 0 : inout_buffer_size_bytes;
  }
};

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

} /* AppendEntries_1_0 */
} /* cluster */
} /* pnp */
} /* uavcan */

#endif /* ARDUINO_UAVCAN_TYPES_UAVCAN_PNP_CLUSTER_APPENDENTRIES_1_0_HPP_ */
