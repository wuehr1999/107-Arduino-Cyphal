/**
 * This software is distributed under the terms of the MIT License.
 * Copyright (c) 2020 LXRobotics.
 * Author: Bernhard Mayer <bernard@generationmake.de>, Alexander Entinger <alexander.entinger@lxrobotics.com>
 * Contributors: https://github.com/107-systems/107-Arduino-Cyphal/graphs/contributors.
 */

#ifndef ARDUINO_UAVCAN_TYPES_UAVCAN_SI_SAMPLE_MAGNETIC_FIELD_STRENGTH_SCALAR_1_0_HPP_
#define ARDUINO_UAVCAN_TYPES_UAVCAN_SI_SAMPLE_MAGNETIC_FIELD_STRENGTH_SCALAR_1_0_HPP_

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include <libcanard/canard.h>

#include <types/uavcan/si/sample/magnetic_field_strength/Scalar_1_0.h>

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

namespace uavcan {
namespace si {
namespace sample {
namespace magnetic_field_strength {

/**************************************************************************************
 * CLASS DECLARATION
 **************************************************************************************/

template <CanardPortID ID>
class Scalar_1_0
{

public:

  uavcan_si_sample_magnetic_field_strength_Scalar_1_0 data;

  static constexpr CanardPortID       PORT_ID          = ID;
  static constexpr size_t             MAX_PAYLOAD_SIZE = uavcan_si_sample_magnetic_field_strength_Scalar_1_0_SERIALIZATION_BUFFER_SIZE_BYTES_;
  static constexpr CanardTransferKind TRANSFER_KIND    = CanardTransferKindMessage;

  Scalar_1_0()
  {
    uavcan_si_sample_magnetic_field_strength_Scalar_1_0_initialize_(&data);
  }

  Scalar_1_0(Scalar_1_0 const & other)
  {
    memcpy(&data, &other.data, sizeof(data));
  }

  static Scalar_1_0 deserialize(CanardRxTransfer const & transfer)
  {
    Scalar_1_0<ID> b;
    size_t inout_buffer_size_bytes = transfer.payload_size;
    uavcan_si_sample_magnetic_field_strength_Scalar_1_0_deserialize_(&b.data, (uint8_t *)(transfer.payload), &inout_buffer_size_bytes);
    return b;
  }

  size_t serialize(uint8_t * payload) const
  {
    size_t inout_buffer_size_bytes = Scalar_1_0::MAX_PAYLOAD_SIZE;
    return (uavcan_si_sample_magnetic_field_strength_Scalar_1_0_serialize_(&data, payload, &inout_buffer_size_bytes) < NUNAVUT_SUCCESS) ? 0 : inout_buffer_size_bytes;
  }
};

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

} /* magnetic_field_strength */
} /* sample */
} /* si */
} /* uavcan */

#endif /* ARDUINO_UAVCAN_TYPES_UAVCAN_SI_SAMPLE_MAGNETIC_FIELD_STRENGTH_SCALAR_1_0_HPP_ */
