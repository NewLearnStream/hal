/**
*********************************************************************************************************
* Copyright (C) 2023-2026 by xiongqulin - All Rights Reserved.                                              *
*                                                                                                       *
* This file is part of the project.                                                                     *
*                                                                                                       *
* This file can not be copied and/or distributed without the express permission of the project owner.   *
*********************************************************************************************************/

/**
*********************************************************************************************************
* @file   : usart.hpp
* @author : xiongqulin
* @date   : 18 Jan 2023
* @brief  :
*
*********************************************************************************************************
*/

#pragma once

#include <cstdint>
#include "infrastructure/component/common/callback.hpp"

class Uart {
protected:
    ContextCallback<uint8_t *, uint16_t> _receive_data_callback;
    ContextCallback<> _receive_idle_callback;

public:
    void attach_data_callback(ContextCallback<uint8_t *, uint16_t>::Func fun, void *context)
    {
        _receive_data_callback.attach(fun, context);
    }

    void attach_idle_callback(ContextCallback<>::Func fun, void *context)
    {
        _receive_idle_callback.attach(fun, context);
    }

    virtual bool write(uint8_t *buf, uint32_t len) = 0;

    virtual bool read_start(uint8_t *buf, uint32_t len) = 0;
};