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

HINSTANCE hInst;
bool is_game_on = false;
bool is_controls_window_open = false;
bool is_player_window_open = false;
bool is_multiplayer = false;
bool key_tab[10] = { false }; //0-3 arrows 4-7 wsad 8-9 enter escape to start and pause game
Player* player_one;
Player* player_two;

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

inline void DrawPlayers(HDC hdc)
{
  if (is_multiplayer == false)
  {
    DrawPlayer1(hdc, player_one->return_position_x(), player_one->return_position_y());
  }
  else
  {
    DrawPlayer1(hdc, player_one->return_position_x(), player_one->return_position_y());
    DrawPlayer2(hdc, player_two->return_position_x(), player_two->return_position_y());
  }

}
//
#endif
