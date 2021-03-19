#pragma once

#include <cstdint>
#include "Itransmit.h"
#include "usart2registers.hpp"

template<typename TUSARTReg, auto& aTransmitter>

class Usart
{
  public: 
    static void WriteByte(std::uint8_t byte)
  {
    TUSARTReg::DR::Write(byte);
  }
  
  static void InterruptHandler()
  {
    if(TUSARTReg::SR::TXE::DataRegisterEmpty::IsSet() &&  TUSARTReg::CR1::TXEIE::InterruptWhenTXE::IsSet())
    {
      aTransmitter.OnNextByteTransmit();
    }   
    
  }

  static void TransmitEnable()
  {
    TUSARTReg::CR1::TE::Enable::Set();
      
  }
  
  static void InterruptEnable()
  {
    TUSARTReg::CR1::TXEIE::InterruptWhenTXE::Set();      
  }
  
  static void InterruptDisable()
  {
    TUSARTReg::CR1::TXEIE::InterruptInhibited::Set();
      
  }
  
  static void TransmitDisable()
  {
    TUSARTReg::CR1::RE::Disable::Set();
  }
  

};
