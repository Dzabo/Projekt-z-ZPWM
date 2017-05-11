#include "player.h"



Player::Player(int x, int y, int id)
{
  position_x_ = x;
  position_y_ = y;
  id_ = id;
  velocity_ = 8;
  speed_multiplier_ = 0.4;
  check1_, check2_, check3_, check4_, check5_, check6_, check7_, check8_, check9_, check10_, check_final_ = false;
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
  if (is_on_route() == true)
  {
    position_y_ = position_y_ - velocity_;
  }
  else
  {
    position_y_ = position_y_ - (speed_multiplier_ * velocity_);
  }
}

void Player::move_right()
{
  if (is_on_route() == true)
  {
    position_x_ = position_x_ + velocity_;
  }
  else
  {
    position_x_ = position_x_ + (speed_multiplier_ * velocity_);
  }
}

void Player::move_left()
{
  if (is_on_route() == true)
  {
    position_x_ = position_x_ - velocity_;
  }
  else
  {
    position_x_ = position_x_ - (speed_multiplier_ * velocity_);
  }
}

void Player::move_down()
{
  if (is_on_route() == true)
  {
    position_y_ = position_y_ + velocity_;
  }
  else
  {
    position_y_ = position_y_ + (speed_multiplier_ * velocity_);
  }
}

bool Player::is_on_route()
{
  if (position_x_ < 15)position_x_ += 15;
  if (position_x_ > 1235)position_x_ -= 15;
  if (position_y_ < 15)position_y_ += 15;
  if (position_y_ > 585)position_y_ -= 15;
  if (position_x_ < 80 || position_x_>1205 || position_y_ < 31 || position_y_ >550 ||
    (position_x_ > 227 && position_x_ < 356 && position_y_>249 && position_y_ < 385) ||
    (position_y_ > 438 && position_x_ > 521 && position_x_ < 744) ||
    (position_y_ > 211 && position_y_ < 275 && position_x_>246 && position_x_ < 671) ||
    (position_y_ > 493 && position_x_ > 439) || (position_y_ > 391 && position_x_ > 1064) ||
    (position_y_ < 105 && position_x_>343 && position_x_ < 490) ||
    (position_y_ < 117 && position_x_> 764 && position_x_ < 896) || (position_x_ > 1120 && position_y_ > 334) ||
    (position_y_ > 263 && position_y_ < 290 && position_x_>713 && position_x_ < 993) ||
    (position_y_ > 255 && position_y_ < 328 && position_x_>221 && position_x_ < 451) ||
    (position_y_ < 348 && position_y_>266 && position_x_ > 841 && position_x_ < 915) ||
    (position_y_ > 208 && position_y_ < 241 && position_x_ < 1034 && position_x_>987) ||
    (position_x_ < 243 && position_x_>218 && position_y_ > 184 && position_y_ < 429))
  {
    return false;
  }
  return true;
}

/*bool Player::check_result()
{
  if ((position_x_ > 800) && (position_y_ < 500) && (position_y_ > 350)) { check1_ = true; }
  if ((position_x_ > 1050) && (position_y_ < 350) && (position_y_ > 250) && (check1_ == true)) { check2_ = true; }
  if ((position_x_ < 1050) && (position_y_ < 180) && (position_y_ > 80) && (check2_ == true)) { check3_ = true; }
  if ((position_x_ < 920) && (position_y_ < 200) && (position_y_ > 110) && (check3_ == true)) { check4_ = true; }
  if ((position_x_ < 600) && (position_y_ < 175) && (position_y_ > 50) && (check4_ == true)) { check5_ = true; }
  if ((position_x_ < 400) && (position_y_ < 250) && (position_y_ > 100) && (check5_ == true)) { check6_ = true; }
  if ((position_x_ < 220) && (position_y_ > 150) && (check6_ == true)) { check7_ = true; }
  if ((position_x_ < 220) && (position_y_ > 400) && (check7_ == true)) { check8_ = true; }
  if ((position_x_ > 350) && (position_y_ < 510) && (position_y_ > 390) && (check8_ == true)) { check9_ = true; }
  if ((position_x_  > 600) && (position_y_ < 410) && (position_y_ > 270) && (check9_ == true)) { check10_ = true; }
  //if ((check10_ == true) && (id_ == 1))
  //{
  //  is_game_on = false;
  //  MessageBox(GetDlgItem(hwndDlg, IDD_GAMEVIEW), "Wygra³ zawodnik nr 1", " ", MB_OK);
  //}
  //else if ((check10_ == true) && (player_id == 2))
  //{
  //  is_game_on = false;
  //  MessageBox(GetDlgItem(hwndDlg, IDD_GAMEVIEW), "Wygra³ zawodnik nr 1", " ", MB_OK);
  //}
  return false;
}*/
