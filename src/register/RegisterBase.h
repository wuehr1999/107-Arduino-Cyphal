/**
 * This software is distributed under the terms of the MIT License.
 * Copyright (c) 2020 LXRobotics.
 * Author: Alexander Entinger <alexander.entinger@lxrobotics.com>
 * Contributors: https://github.com/107-systems/107-Arduino-Cyphal/graphs/contributors.
 */

#ifndef REGISTER_BASE_H_
#define REGISTER_BASE_H_

/**************************************************************************************
 * INCLUDES
 **************************************************************************************/

#include "../Types.h"
#include "types/TypeTag.hpp"

/**************************************************************************************
 * CLASS DECLARATION
 **************************************************************************************/

class RegisterBase
{
public:
  RegisterBase(char const * name,
               Register::TypeTag const type_tag,
               bool const is_mutable,
               bool const is_persistent);


  inline uavcan_register_Name_1_0 const & name() const { return _name; }
  inline Register::TypeTag type_tag() const { return _type_tag; }
  inline bool isMutable() const { return _is_mutable; }
  inline bool isPersistent() const { return _is_persistent; }
  inline uavcan_time_SynchronizedTimestamp_1_0 timestamp() const { return _timestamp; }


protected:
  inline void setTimestamp(uint64_t const microsecond) { _timestamp.microsecond = microsecond; }


private:
  uavcan_register_Name_1_0 _name;
  Register::TypeTag const _type_tag;
  bool const _is_mutable;
  bool const _is_persistent;
  uavcan_time_SynchronizedTimestamp_1_0 _timestamp;
};

#endif /* REGISTER_BASE_H_ */
