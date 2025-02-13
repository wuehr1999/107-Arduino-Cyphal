/**
 * This software is distributed under the terms of the MIT License.
 * Copyright (c) 2020 LXRobotics.
 * Author: Alexander Entinger <alexander.entinger@lxrobotics.com>
 * Contributors: https://github.com/107-systems/107-Arduino-Cyphal/graphs/contributors.
 */


/**************************************************************************************
 * INCLUDES
 **************************************************************************************/

#include "RegisterList.h"

#include <algorithm>

#include "util/ListResponse.h"
#include "util/AccessRequest.hpp"
#include "util/AccessResponse.hpp"

/**************************************************************************************
 * CTOR/DTOR
 **************************************************************************************/

RegisterList::RegisterList()
: _reg_last{"", Register::TypeTag::Empty, false, false}
{
  _on_access_request_handler_map[Register::TypeTag::Empty] =
  [](uavcan::_register::Access_1_0::Request<> const & req, RegisterBase * reg_base_ptr)
  {
    uavcan::_register::Access_1_0::Response<> r;

    uavcan_register_Value_1_0_select_empty_(&r.data.value);
    r.data.timestamp.microsecond = 0;
    r.data._mutable = false;
    r.data.persistent = false;

    return r;
  };

  _on_access_request_handler_map[Register::TypeTag::String] =
  [](uavcan::_register::Access_1_0::Request<> const & req, RegisterBase * reg_base_ptr)
  {
    RegisterString * reg_ptr = reinterpret_cast<RegisterString *>(reg_base_ptr);
    if(uavcan_register_Value_1_0_is_empty_(&req.data.value))
      reg_ptr->onReadRequest();
    if(uavcan_register_Value_1_0_is_string_(&req.data.value) && reg_ptr->isMutable())
    {
      /* Limitation makes no sense for 'std::string' */
      reg_ptr->set(AccessRequest::toRegisterValue<std::string>(req.data.value));
      reg_ptr->onWriteRequest();
    }
    return AccessResponse::create(*reg_ptr);
  };

  _on_access_request_handler_map[Register::TypeTag::Bit] =
  [](uavcan::_register::Access_1_0::Request<> const & req, RegisterBase * reg_base_ptr)
  {
    RegisterBit * reg_ptr = reinterpret_cast<RegisterBit *>(reg_base_ptr);
    if(uavcan_register_Value_1_0_is_empty_(&req.data.value))
      reg_ptr->onReadRequest();
    if(uavcan_register_Value_1_0_is_bit_(&req.data.value) && reg_ptr->isMutable())
    {
      /* Limitation makes no sense for 'bool' */
      reg_ptr->set(AccessRequest::toRegisterValue<bool>(req.data.value));
      reg_ptr->onWriteRequest();
    }
    return AccessResponse::create(*reg_ptr);
  };

  _on_access_request_handler_map[Register::TypeTag::Integer8] =
  [](uavcan::_register::Access_1_0::Request<> const & req, RegisterBase * reg_base_ptr)
  {
    RegisterInteger8 * reg_ptr = reinterpret_cast<RegisterInteger8 *>(reg_base_ptr);
    if(uavcan_register_Value_1_0_is_empty_(&req.data.value))
      reg_ptr->onReadRequest();
    if(uavcan_register_Value_1_0_is_integer8_(&req.data.value) && reg_ptr->isMutable())
    {
      int8_t const reg_val = AccessRequest::toRegisterValue<int8_t>(req.data.value);
      int8_t const limited_reg_val = reg_ptr->limitValue(reg_val);
      reg_ptr->set(limited_reg_val);
      reg_ptr->onWriteRequest();
    }
    return AccessResponse::create(*reg_ptr);
  };

  _on_access_request_handler_map[Register::TypeTag::Integer16] =
  [](uavcan::_register::Access_1_0::Request<> const & req, RegisterBase * reg_base_ptr)
  {
    RegisterInteger16 * reg_ptr = reinterpret_cast<RegisterInteger16 *>(reg_base_ptr);
    if(uavcan_register_Value_1_0_is_empty_(&req.data.value))
      reg_ptr->onReadRequest();
    if(uavcan_register_Value_1_0_is_integer16_(&req.data.value) && reg_ptr->isMutable())
    {
      int16_t const reg_val = AccessRequest::toRegisterValue<int16_t>(req.data.value);
      int16_t const limited_reg_val = reg_ptr->limitValue(reg_val);
      reg_ptr->set(limited_reg_val);
      reg_ptr->onWriteRequest();
    }
    return AccessResponse::create(*reg_ptr);
  };

  _on_access_request_handler_map[Register::TypeTag::Integer32] =
  [](uavcan::_register::Access_1_0::Request<> const & req, RegisterBase * reg_base_ptr)
  {
    RegisterInteger32 * reg_ptr = reinterpret_cast<RegisterInteger32 *>(reg_base_ptr);
    if(uavcan_register_Value_1_0_is_empty_(&req.data.value))
      reg_ptr->onReadRequest();
    if(uavcan_register_Value_1_0_is_integer32_(&req.data.value) && reg_ptr->isMutable())
    {
      int32_t const reg_val = AccessRequest::toRegisterValue<int32_t>(req.data.value);
      int32_t const limited_reg_val = reg_ptr->limitValue(reg_val);
      reg_ptr->set(limited_reg_val);
      reg_ptr->onWriteRequest();
    }
    return AccessResponse::create(*reg_ptr);
  };

  _on_access_request_handler_map[Register::TypeTag::Integer64] =
  [](uavcan::_register::Access_1_0::Request<> const & req, RegisterBase * reg_base_ptr)
  {
    RegisterInteger64 * reg_ptr = reinterpret_cast<RegisterInteger64 *>(reg_base_ptr);
    if(uavcan_register_Value_1_0_is_empty_(&req.data.value))
      reg_ptr->onReadRequest();
    if(uavcan_register_Value_1_0_is_integer64_(&req.data.value) && reg_ptr->isMutable())
    {
      int64_t const reg_val = AccessRequest::toRegisterValue<int64_t>(req.data.value);
      int64_t const limited_reg_val = reg_ptr->limitValue(reg_val);
      reg_ptr->set(limited_reg_val);
      reg_ptr->onWriteRequest();
    }
    return AccessResponse::create(*reg_ptr);
  };

  _on_access_request_handler_map[Register::TypeTag::Natural8] =
  [](uavcan::_register::Access_1_0::Request<> const & req, RegisterBase * reg_base_ptr)
  {
    RegisterNatural8 * reg_ptr = reinterpret_cast<RegisterNatural8 *>(reg_base_ptr);
    if(uavcan_register_Value_1_0_is_empty_(&req.data.value))
      reg_ptr->onReadRequest();
    if(uavcan_register_Value_1_0_is_natural8_(&req.data.value) && reg_ptr->isMutable())
    {
      uint8_t const reg_val = AccessRequest::toRegisterValue<uint8_t>(req.data.value);
      uint8_t const limited_reg_val = reg_ptr->limitValue(reg_val);
      reg_ptr->set(limited_reg_val);
      reg_ptr->onWriteRequest();
    }
    return AccessResponse::create(*reg_ptr);
  };

  _on_access_request_handler_map[Register::TypeTag::Natural16] =
  [](uavcan::_register::Access_1_0::Request<> const & req, RegisterBase * reg_base_ptr)
  {
    RegisterNatural16 * reg_ptr = reinterpret_cast<RegisterNatural16 *>(reg_base_ptr);
    if(uavcan_register_Value_1_0_is_empty_(&req.data.value))
      reg_ptr->onReadRequest();
    if(uavcan_register_Value_1_0_is_natural16_(&req.data.value) && reg_ptr->isMutable())
    {
      uint16_t const reg_val = AccessRequest::toRegisterValue<uint16_t>(req.data.value);
      uint16_t const limited_reg_val = reg_ptr->limitValue(reg_val);
      reg_ptr->set(limited_reg_val);
      reg_ptr->onWriteRequest();
    }
    return AccessResponse::create(*reg_ptr);
  };

  _on_access_request_handler_map[Register::TypeTag::Natural32] =
  [](uavcan::_register::Access_1_0::Request<> const & req, RegisterBase * reg_base_ptr)
  {
    RegisterNatural32 * reg_ptr = reinterpret_cast<RegisterNatural32 *>(reg_base_ptr);
    if(uavcan_register_Value_1_0_is_empty_(&req.data.value))
      reg_ptr->onReadRequest();
    if(uavcan_register_Value_1_0_is_natural32_(&req.data.value) && reg_ptr->isMutable())
    {
      uint32_t const reg_val = AccessRequest::toRegisterValue<uint32_t>(req.data.value);
      uint32_t const limited_reg_val = reg_ptr->limitValue(reg_val);
      reg_ptr->set(limited_reg_val);
      reg_ptr->onWriteRequest();
    }
    return AccessResponse::create(*reg_ptr);
  };

  _on_access_request_handler_map[Register::TypeTag::Natural64] =
  [](uavcan::_register::Access_1_0::Request<> const & req, RegisterBase * reg_base_ptr)
  {
    RegisterNatural64 * reg_ptr = reinterpret_cast<RegisterNatural64 *>(reg_base_ptr);
    if(uavcan_register_Value_1_0_is_empty_(&req.data.value))
      reg_ptr->onReadRequest();
    if(uavcan_register_Value_1_0_is_natural64_(&req.data.value) && reg_ptr->isMutable())
    {
      uint64_t const reg_val = AccessRequest::toRegisterValue<uint64_t>(req.data.value);
      uint64_t const limited_reg_val = reg_ptr->limitValue(reg_val);
      reg_ptr->set(limited_reg_val);
      reg_ptr->onWriteRequest();
    }
    return AccessResponse::create(*reg_ptr);
  };

  _on_access_request_handler_map[Register::TypeTag::Real32] =
  [](uavcan::_register::Access_1_0::Request<> const & req, RegisterBase * reg_base_ptr)
  {
    RegisterReal32 * reg_ptr = reinterpret_cast<RegisterReal32 *>(reg_base_ptr);
    if(uavcan_register_Value_1_0_is_empty_(&req.data.value))
      reg_ptr->onReadRequest();
    if(uavcan_register_Value_1_0_is_real32_(&req.data.value) && reg_ptr->isMutable())
    {
      float const reg_val = AccessRequest::toRegisterValue<float>(req.data.value);
      float const limited_reg_val = reg_ptr->limitValue(reg_val);
      reg_ptr->set(limited_reg_val);
      reg_ptr->onWriteRequest();
    }
    return AccessResponse::create(*reg_ptr);
  };

  _on_access_request_handler_map[Register::TypeTag::Real64] =
  [](uavcan::_register::Access_1_0::Request<> const & req, RegisterBase * reg_base_ptr)
  {
    RegisterReal64 * reg_ptr = reinterpret_cast<RegisterReal64 *>(reg_base_ptr);
    if(uavcan_register_Value_1_0_is_empty_(&req.data.value))
      reg_ptr->onReadRequest();
    if(uavcan_register_Value_1_0_is_real64_(&req.data.value) && reg_ptr->isMutable())
    {
      double const reg_val = AccessRequest::toRegisterValue<double>(req.data.value);
      double const limited_reg_val = reg_ptr->limitValue(reg_val);
      reg_ptr->set(limited_reg_val);
      reg_ptr->onWriteRequest();
    }
    return AccessResponse::create(*reg_ptr);
  };
}

/**************************************************************************************
 * PUBLIC MEMBER FUNCTIONS
 **************************************************************************************/

void RegisterList::subscribe(Node & node_hdl)
{
  node_hdl.subscribe<uavcan::_register::List_1_0::Request<>>
    ([this](CanardRxTransfer const & transfer, Node & node_hdl) { this->onList_1_0_Request_Received(transfer, node_hdl); });
  node_hdl.subscribe<uavcan::_register::Access_1_0::Request<>>
    ([this](CanardRxTransfer const & transfer, Node & node_hdl) { this->onAccess_1_0_Request_Received(transfer, node_hdl); });
}

/**************************************************************************************
 * PRIVATE MEMBER FUNCTIONS
 **************************************************************************************/

void RegisterList::onList_1_0_Request_Received(CanardRxTransfer const & transfer, Node & node_hdl)
{
  uavcan::_register::List_1_0::Request<>  const req = uavcan::_register::List_1_0::Request<>::deserialize(transfer);
  uavcan::_register::List_1_0::Response<> const rsp =
    (req.data.index < _reg_list.size()) ? ListResponse::create(_reg_list[req.data.index]->name()) : ListResponse::create(_reg_last.name());
  node_hdl.respond(rsp, transfer.metadata.remote_node_id, transfer.metadata.transfer_id);
}

void RegisterList::onAccess_1_0_Request_Received(CanardRxTransfer const & transfer, Node & node_hdl)
{
  uavcan::_register::Access_1_0::Request<> const req = uavcan::_register::Access_1_0::Request<>::deserialize(transfer);

  /* Initialise with an empty response in case we
   * can't find a matching register.
   */
  uavcan::_register::Access_1_0::Response<> rsp = []()
  {
    uavcan::_register::Access_1_0::Response<> r;

    uavcan_register_Value_1_0_select_empty_(&r.data.value);
    r.data.timestamp.microsecond = 0;
    r.data._mutable = false;
    r.data.persistent = false;

    return r;
  } ();

  /* Find a register with the same register name within
   * the register list.
   */
  auto iter = std::find_if(std::begin(_reg_list),
                           std::end  (_reg_list),
                           [req](RegisterBase * reg_ptr)
                           {
                             if (reg_ptr->name().name.count != req.data.name.name.count)
                               return false;

                             return (strncmp(reinterpret_cast<const char *>(reg_ptr->name().name.elements),
                                     reinterpret_cast<const char *>(req.data.name.name.elements),
                                     reg_ptr->name().name.count) == 0);
                           });

  if (iter != std::end(_reg_list))
  {
    /* Store in separate variable for better clarity. */
    RegisterBase * reg_base_ptr = *iter;
    /* Determine the actual type of the register. */
    Register::TypeTag const type_tag = reg_base_ptr->type_tag();
    /* Call the approbriate callback handler. */
    if (_on_access_request_handler_map.count(type_tag) > 0)
      rsp = _on_access_request_handler_map.at(type_tag)(req, reg_base_ptr);
  }

  /* Send the actual response. */
  node_hdl.respond(rsp, transfer.metadata.remote_node_id, transfer.metadata.transfer_id);
}
