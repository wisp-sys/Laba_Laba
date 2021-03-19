#pragma once
#include "usart.h"
#include "usart2registers.hpp"
#include "USARTDriver.h"

class Usart2;

inline USARTDriver <Usart2> usartDriver;
class Usart2: public Usart < USART2, usartDriver>
{
};