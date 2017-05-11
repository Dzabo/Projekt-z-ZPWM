#ifndef ZPWM_FUNCTIONS_H_
#define ZPWM_FUNCTIONS_H_

#include <Windows.h>
#include "player.h"


#define KEYLEFT 0x25
#define KEYUP 0x26
#define KEYRIGHT 0x27
#define KEYDOWN 0x28
#define KEYA 0x41
#define KEYW 0x57
#define KEYD 0x44
#define KEYS 0x53
#define KEYENTER 0x0D
#define KEYESCAPE 0x1B
#define STARTX 585
#define STARTYMIN 290
#define STARTYMAX 390
#define ENDX 580

HBITMAP hBitmapMenu;
HBITMAP hBitmapMenuPlayer;
HBITMAP hBitmapBoard;
HBITMAP hBitmapControls;
HBITMAP hBitmapPlayer1;
HBITMAP hBitmapPlayer1N;
HBITMAP hBitmapPlayer1E;
HBITMAP hBitmapPlayer1S;
HBITMAP hBitmapPlayer1W;
HBITMAP hBitmapPlayer2;
HBITMAP hBitmapPlayer2N;
HBITMAP hBitmapPlayer2E;
HBITMAP hBitmapPlayer2S;
HBITMAP hBitmapPlayer2W;

bool check1_ = false,
check2_ = false,
check3_ = false,
check4_ = false,
check5_ = false,
check6_ = false,
check7_ = false,
check8_ = false,
check9_ = false,
check10_ = false;




HINSTANCE hInst;
bool is_game_on = false;
bool is_game_active = false;
bool is_controls_window_open = false;
bool is_player_window_open = false;
bool is_multiplayer = false;
bool key_tab[10] = { false }; //0-3 arrows 4-7 wsad 8-9 enter escape to start and pause game
void check_result(Player* player, HWND hwndDlg,int player_id);
Player* player_one;
Player* player_two;

enum direction
{
  north,
  east,
  south,
  west
};

/*void DrawMenu(HDC x);
void DrawMenuPlayer(HDC x);
void DrawGameBoard(HDC x);
void DrawGameControls(HDC x);
void DrawPlayer1(HDC hdc, int x, int y);
void DrawPlayer1N(HDC hdc, int x, int y);
void DrawPlayer1E(HDC hdc, int x, int y);
void DrawPlayer1S(HDC hdc, int x, int y);
void DrawPlayer1W(HDC hdc, int x, int y);
void DrawPlayer2(HDC hdc, int x, int y);
void DrawPlayer2N(HDC hdc, int x, int y);
void DrawPlayer2E(HDC hdc, int x, int y);
void DrawPlayer2S(HDC hdc, int x, int y);
void DrawPlayer2W(HDC hdc, int x, int y);
void DrawPlayers(HDC hdc);*/


//
inline void DrawMenu(HDC x)
{
  HDC hDCBitmap;
  hDCBitmap = CreateCompatibleDC(x);
  SelectObject(hDCBitmap, hBitmapMenu);
  BitBlt(x, 0, 0, 280, 220, hDCBitmap, 0, 0, SRCCOPY); //width, height
  DeleteDC(hDCBitmap);
}

inline void DrawMenuPlayer(HDC x)
{
  HDC hDCBitmap;
  hDCBitmap = CreateCompatibleDC(x);
  SelectObject(hDCBitmap, hBitmapMenuPlayer);
  BitBlt(x, 0, 0, 280, 180, hDCBitmap, 0, 0, SRCCOPY); //width, height
  DeleteDC(hDCBitmap);

}

inline void DrawGameBoard(HDC x)
{
  HDC hDCBitmap;
  hDCBitmap = CreateCompatibleDC(x);
  SelectObject(hDCBitmap, hBitmapBoard);
  BitBlt(x, 0, 0, 1250, 600, hDCBitmap, 0, 0, SRCCOPY); //width, height
  DeleteDC(hDCBitmap);
}

inline void DrawGameControls(HDC x)
{
  HDC hDCBitmap;
  hDCBitmap = CreateCompatibleDC(x);
  SelectObject(hDCBitmap, hBitmapControls);
  BitBlt(x, 0, 0, 288, 162, hDCBitmap, 0, 0, SRCCOPY); //width, height
  DeleteDC(hDCBitmap);
}

inline void DrawPlayer1(HDC hdc, int x, int y)
{
  HDC hDCBitmap;
  hDCBitmap = CreateCompatibleDC(hdc);
  SelectObject(hDCBitmap, hBitmapPlayer1);
  BitBlt(hdc, x, y, 29, 29, hDCBitmap, 0, 0, SRCCOPY); //width, height
  DeleteDC(hDCBitmap);
}

inline void DrawPlayer1N(HDC hdc, int x, int y)
{
  HDC hDCBitmap;
  hDCBitmap = CreateCompatibleDC(hdc);
  SelectObject(hDCBitmap, hBitmapPlayer1N);
  BitBlt(hdc, x, y, 29, 29, hDCBitmap, 0, 0, SRCCOPY); //width, height
  DeleteDC(hDCBitmap);
}

inline void DrawPlayer1E(HDC hdc, int x, int y)
{
  HDC hDCBitmap;
  hDCBitmap = CreateCompatibleDC(hdc);
  SelectObject(hDCBitmap, hBitmapPlayer1E);
  BitBlt(hdc, x, y, 29, 29, hDCBitmap, 0, 0, SRCCOPY); //width, height
  DeleteDC(hDCBitmap);
}

inline void DrawPlayer1S(HDC hdc, int x, int y)
{
  HDC hDCBitmap;
  hDCBitmap = CreateCompatibleDC(hdc);
  SelectObject(hDCBitmap, hBitmapPlayer1S);
  BitBlt(hdc, x, y, 29, 29, hDCBitmap, 0, 0, SRCCOPY); //width, height
  DeleteDC(hDCBitmap);
}

inline void DrawPlayer1W(HDC hdc, int x, int y)
{
  HDC hDCBitmap;
  hDCBitmap = CreateCompatibleDC(hdc);
  SelectObject(hDCBitmap, hBitmapPlayer1W);
  BitBlt(hdc, x, y, 29, 29, hDCBitmap, 0, 0, SRCCOPY); //width, height
  DeleteDC(hDCBitmap);
}

inline void DrawPlayer2(HDC hdc, int x, int y)
{
  HDC hDCBitmap;
  hDCBitmap = CreateCompatibleDC(hdc);
  SelectObject(hDCBitmap, hBitmapPlayer2);
  BitBlt(hdc, x, y, 29, 29, hDCBitmap, 0, 0, SRCCOPY); //width, height
  DeleteDC(hDCBitmap);
}

inline void DrawPlayer2N(HDC hdc, int x, int y)
{
  HDC hDCBitmap;
  hDCBitmap = CreateCompatibleDC(hdc);
  SelectObject(hDCBitmap, hBitmapPlayer2N);
  BitBlt(hdc, x, y, 29, 29, hDCBitmap, 0, 0, SRCCOPY); //width, height
  DeleteDC(hDCBitmap);
}

inline void DrawPlayer2E(HDC hdc, int x, int y)
{
  HDC hDCBitmap;
  hDCBitmap = CreateCompatibleDC(hdc);
  SelectObject(hDCBitmap, hBitmapPlayer2E);
  BitBlt(hdc, x, y, 29, 29, hDCBitmap, 0, 0, SRCCOPY); //width, height
  DeleteDC(hDCBitmap);
}
inline void DrawPlayer2S(HDC hdc, int x, int y)
{
  HDC hDCBitmap;
  hDCBitmap = CreateCompatibleDC(hdc);
  SelectObject(hDCBitmap, hBitmapPlayer2S);
  BitBlt(hdc, x, y, 29, 29, hDCBitmap, 0, 0, SRCCOPY); //width, height
  DeleteDC(hDCBitmap);
}

inline void DrawPlayer2W(HDC hdc, int x, int y)
{
  HDC hDCBitmap;
  hDCBitmap = CreateCompatibleDC(hdc);
  SelectObject(hDCBitmap, hBitmapPlayer2W);
  BitBlt(hdc, x, y, 29, 29, hDCBitmap, 0, 0, SRCCOPY); //width, height
  DeleteDC(hDCBitmap);
}

inline void DrawPlayers(HDC hdc, direction dir_variable1, direction dir_variable2)
{
  if (is_multiplayer == false)
  {
    switch(dir_variable1)
    {
    case north:
      DrawPlayer1N(hdc, player_one->return_position_x(), player_one->return_position_y());
      break;
    case east:
      DrawPlayer1E(hdc, player_one->return_position_x(), player_one->return_position_y());
      break;
    case south:
      DrawPlayer1S(hdc, player_one->return_position_x(), player_one->return_position_y());
      break;
    case west:
      DrawPlayer1W(hdc, player_one->return_position_x(), player_one->return_position_y());
      break;
    }
//    DrawPlayer1(hdc, player_one->return_position_x(), player_one->return_position_y());
  }
  else
  {
    switch (dir_variable1)
    {
    case north:
      DrawPlayer1N(hdc, player_one->return_position_x(), player_one->return_position_y());
      //DrawPlayer2N(hdc, player_two->return_position_x(), player_two->return_position_y());
      break;
    case east:
      DrawPlayer1E(hdc, player_one->return_position_x(), player_one->return_position_y());
      //DrawPlayer2E(hdc, player_two->return_position_x(), player_two->return_position_y());
      break;
    case south:
      DrawPlayer1S(hdc, player_one->return_position_x(), player_one->return_position_y());
      //DrawPlayer2S(hdc, player_two->return_position_x(), player_two->return_position_y());
      break;
    case west:
      DrawPlayer1W(hdc, player_one->return_position_x(), player_one->return_position_y());
      //DrawPlayer2W(hdc, player_two->return_position_x(), player_two->return_position_y());
      break;
    }
    switch (dir_variable2)
    {
    case north:
      //DrawPlayer1N(hdc, player_one->return_position_x(), player_one->return_position_y());
      DrawPlayer2N(hdc, player_two->return_position_x(), player_two->return_position_y());
      break;
    case east:
      //DrawPlayer1E(hdc, player_one->return_position_x(), player_one->return_position_y());
      DrawPlayer2E(hdc, player_two->return_position_x(), player_two->return_position_y());
      break;
    case south:
      //DrawPlayer1S(hdc, player_one->return_position_x(), player_one->return_position_y());
      DrawPlayer2S(hdc, player_two->return_position_x(), player_two->return_position_y());
      break;
    case west:
      //DrawPlayer1W(hdc, player_one->return_position_x(), player_one->return_position_y());
      DrawPlayer2W(hdc, player_two->return_position_x(), player_two->return_position_y());
      break;
    }
//    DrawPlayer1(hdc, player_one->return_position_x(), player_one->return_position_y());
//    DrawPlayer2(hdc, player_two->return_position_x(), player_two->return_position_y());
  }

}
//
inline void check_result(Player* player,HWND hwndDlg,int player_id)
{

  if ((player->return_position_x() > 800) && (player->return_position_y() < 500) && (player->return_position_y() > 350)) { check1_ = true; }
  if ((player->return_position_x() > 1050) && (player->return_position_y() < 350) && (player->return_position_y() > 250) && (check1_ == true)) { check2_ = true; }
  if ((player->return_position_x() < 1050) && (player->return_position_y() < 180) && (player->return_position_y() > 80) && (check2_ == true)) { check3_ = true; }
  if ((player->return_position_x() < 920) && (player->return_position_y() < 200) && (player->return_position_y() > 110) && (check3_ == true)) { check4_ = true; }
  if ((player->return_position_x() < 600) && (player->return_position_y() < 175) && (player->return_position_y() > 50) && (check4_ == true)) { check5_ = true; }
  if ((player->return_position_x() < 400) && (player->return_position_y() < 250) && (player->return_position_y() > 100) && (check5_ == true)) { check6_ = true; }
  if ((player->return_position_x() < 220) && (player->return_position_y() > 150) && (check6_ == true)) { check7_ = true; }
  if ((player->return_position_x() < 220) && (player->return_position_y() > 400) && (check7_ == true)) { check8_ = true; }
  if ((player->return_position_x() > 350) && (player->return_position_y() < 510) && (player->return_position_y() > 390) && (check8_ == true)) { check9_ = true; }
  if ((player->return_position_x() > 580) && (player->return_position_y() < 410) && (player->return_position_y() > 270) && (check9_ == true)) { check10_ = true; }
  if ((check10_ == true)&&(player_id==1))
  {
    is_game_active = false;
    MessageBox(GetDlgItem(hwndDlg, IDD_GAMEVIEW), "Wygra³ zawodnik nr 1", " ", MB_OK);
  }
  else if ((check10_ == true) && (player_id == 2))
  {
    is_game_active = false;
    MessageBox(GetDlgItem(hwndDlg, IDD_GAMEVIEW), "Wygra³ zawodnik nr 1", " ", MB_OK);
  }
}
#endif
