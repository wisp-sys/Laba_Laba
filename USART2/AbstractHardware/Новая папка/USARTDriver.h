#pragma once

#include <array>

template<typename TUsart>
class USARTDriver
{
public:
  void OnNextByteTransmit()
  {
    TUsart::WriteByte(TransmitBuffer[i]);
      i++;
    if (i < size)
    {
      TUsart::DisableTransmit();
      i = 0U;
    }
  }
  void SendMessage(std::uint8_t* message, size_t size)
  {
    
  }

private:
  std::size_t i = 0U;
  std::array<std::uint8_t,255> TransmitBuffer;
   size_t size = 0U;  
};


