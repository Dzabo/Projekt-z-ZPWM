#ifndef ZPWM_PLAYER_H_
#define ZPWM_PLAYER_H_
class Player
{
private:
  int position_x_=-10;
  int position_y_=-10;
  int id_;
  double velocity_;
  double speed_multiplier_;
  bool check1_, check2_, check3_, check4_, check5_, check6_, check7_, check8_, check9_, check10_,check_final_;
public:
  Player(int x,int y,int id);
  ~Player();
  int return_position_x()const;
  int return_position_y()const;
  void move_up();
  void move_right();
  void move_left();
  void move_down();
  bool is_on_route();
  bool check_result();
  

};

#endif