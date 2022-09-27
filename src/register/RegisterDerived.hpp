/**
 * This software is distributed under the terms of the MIT License.
 * Copyright (c) 2020 LXRobotics.
 * Author: Alexander Entinger <alexander.entinger@lxrobotics.com>
 * Contributors: https://github.com/107-systems/107-Arduino-Cyphal/graphs/contributors.
 */

#ifndef REGISTER_DERIVED_HPP_
#define REGISTER_DERIVED_HPP_

/**************************************************************************************
 * INCLUDES
 **************************************************************************************/

#include "RegisterBase.h"
#include "types/Access.h"
#include "types/Persistent.h"

/**************************************************************************************
 * CLASS DECLARATION
 **************************************************************************************/

template <typename T>
class RegisterDerived : public RegisterBase
{
public:
  typedef std::function<void(T const &)> OnWriteRequestFunc;

  RegisterDerived(char const * name,
                  Register::Access const access,
                  Register::Persistent const is_persistent,
                  T const & initial_val,
                  OnWriteRequestFunc on_write_func);

  inline T get() const { return _val; }
  void set(uavcan_register_Value_1_0 const & val);


private:
  T _val;
  OnWriteRequestFunc _on_write_func;

  inline void onWriteFunc() const { if (_on_write_func) _on_write_func(_val); }
};

/**************************************************************************************
 * TYPEDEF
 **************************************************************************************/

typedef RegisterDerived<std::string> RegisterString;
typedef RegisterDerived<bool>        RegisterBit;
typedef RegisterDerived<int8_t>      RegisterInteger8;
typedef RegisterDerived<int16_t>     RegisterInteger16;
typedef RegisterDerived<int32_t>     RegisterInteger32;
typedef RegisterDerived<int64_t>     RegisterInteger64;
typedef RegisterDerived<uint8_t>     RegisterNatural8;
typedef RegisterDerived<uint16_t>    RegisterNatural16;
typedef RegisterDerived<uint32_t>    RegisterNatural32;
typedef RegisterDerived<uint64_t>    RegisterNatural64;
typedef RegisterDerived<float>       RegisterReal32;
typedef RegisterDerived<double>      RegisterReal64;

/**************************************************************************************
 * TEMPLATE IMPLEMENTATION
 **************************************************************************************/

#include "RegisterDerived.ipp"

#endif /* REGISTER_DERIVED_HPP_ */
