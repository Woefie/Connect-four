#pragma once
#include "iuser.h"

class Player : public IUser{
  public:
  Player()=default;
  Player(uint8_t);

  const uint32_t GetPlacement()  override;


};