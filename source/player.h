#ifndef ZPWM_PLAYER_H_
#define ZPWM_PLAYER_H_
class Player
{
private:
  int position_x_;
  int position_y_;
  double velocity_;
  double speed_multiplier_;
public:
  Player(int x,int y);
  ~Player();
  int return_position_x()const;
  int return_position_y()const;
  void move_up();
  void move_right();
  void move_left();
  void move_down();
  bool is_on_route()const;
  

};

#endif