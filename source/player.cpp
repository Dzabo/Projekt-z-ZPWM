#include "player.h"



Player::Player(int x, int y)
{
  position_x_ = x;
  position_y_ = y;
}


Player::~Player()
{
}

int Player::return_position_x()const
{
  return position_x_;
}

int Player::return_position_y()const
{
  return position_y_;
}

void Player::move_up()
{
 position_y_=position_y_-5;
}

void Player::move_right()
{
  position_x_=position_x_+5;
}

void Player::move_left()
{
  position_x_ = position_x_ - 5;
}

void Player::move_down()
{
  position_y_ = position_y_ + 5;
}
