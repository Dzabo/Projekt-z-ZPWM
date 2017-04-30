#include <Windows.h>
#include "res.h"
#include <stdio.h>


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

CHAR szText[200];
HBITMAP hBitmapMenu;
HBITMAP hBitmapMenuPlayer;
HBITMAP hBitmapBoard;
HBITMAP hBitmapControls;
HINSTANCE hInst;
bool is_game_on = false;
bool is_controls_window_open = false;
bool is_player_window_open = false;
bool key_tab[10] = { false }; //0-3 arrows 4-7 wsad 8-9 enter escape to start and pause game

void DrawMenu(HDC x);
void DrawMenuPlayer(HDC x);
void DrawGameBoard(HDC x);
void DrawGameControls(HDC x);


INT_PTR CALLBACK DialogControl(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
  //HWND hwndGameview = GetDlgItem(hwndDlg, IDD_GAMEVIEW);

  switch (uMsg)
  {

  case WM_COMMAND:
  {

    switch (HIWORD(wParam))
    {

    case BN_CLICKED:
      switch (LOWORD(wParam))
      {

      default:;
      }
    default:;
    }
  }
  return TRUE;
  case WM_INITDIALOG:
  {
    hBitmapControls = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BITMAP_CONTROLS));
  }
  return TRUE;
  case WM_PAINT:
  {
    HDC hdc = GetDC(hwndDlg);
    DrawGameControls(hdc);
    ReleaseDC(hwndDlg, hdc);
    return DefWindowProc(hwndDlg, uMsg, wParam, lParam);
  }
  case WM_CLOSE:
  {
    is_controls_window_open = false;
    EndDialog(hwndDlg, 0);
    DestroyWindow(hwndDlg); 
  }
  return TRUE;
  default:;
  }
  return FALSE;
}

INT_PTR CALLBACK DialogGame(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
  //HWND hwndGameview = GetDlgItem(hwndDlg, IDD_GAMEVIEW);

  switch (uMsg)
  {

  case WM_COMMAND:
  {

    switch (HIWORD(wParam))
    {

    case BN_CLICKED://Zdarzenie klikniêcia 
      switch (LOWORD(wParam))
      {
      case ID_OGRZE_AUTORZY:
        {
        MessageBox(0, "Super ludzie to zrobili", "Autorzy", MB_OK);
        return TRUE;
        }
      case ID_OGRZE_TUTAJ:
        {
        MessageBox(0, "Super informacje o grze", "O grze", MB_OK);
        return TRUE;
        }
      case ID_ROZGRYWKA_ROZPOCZNIJ:
        {
        MessageBox(0, "HEHE JESZCZE NIE TERAZ", " ", MB_OK);
        return TRUE;
        }
      case ID_ROZGRYWKA_ZAKONCZ:
        {
        MessageBox(0, "Najpierw trzeba zacz¹æ hehe", " ", MB_OK);
        return TRUE;
        }
      default:;
      }
    default:;
    }
  }
  return TRUE;
  case WM_KEYDOWN:
  {
    if ((wParam == KEYLEFT) && (key_tab[0] == false))
    {
      MessageBox(nullptr, "Nacisn¹³eœ strza³kê w lewo", "temp", MB_OK);
      key_tab[0] = true;
    }
    if ((wParam == KEYUP) && (key_tab[1] == false))
    {
      MessageBox(nullptr, "Nacisn¹³eœ strza³kê w górê", "temp", MB_OK);
      key_tab[1] = true;
    }
    if ((wParam == KEYRIGHT) && (key_tab[2] == false))
    {
      MessageBox(nullptr, "Nacisn¹³eœ strza³kê w prawo", "temp", MB_OK);
      key_tab[2] = true;
    }
    if ((wParam == KEYDOWN) && (key_tab[3] == false))
    {
      MessageBox(nullptr, "Nacisn¹³eœ strza³kê w dó³", "temp", MB_OK);
      key_tab[3] = true;
    }
    if ((wParam == KEYA) && (key_tab[4] == false))
    {
      MessageBox(nullptr, "Nacisn¹³eœ a", "temp", MB_OK);
      key_tab[4] = true;
    }
    if ((wParam == KEYW) && (key_tab[5] == false))
    {
      MessageBox(nullptr, "Nacisn¹³eœ w", "temp", MB_OK);
      key_tab[5] = true;
    }
    if ((wParam == KEYD) && (key_tab[6] == false))
    {
      MessageBox(nullptr, "Nacisn¹³eœ d", "temp", MB_OK);
      key_tab[6] = true;
    }
    if ((wParam == KEYS) && (key_tab[7] == false))
    {
      MessageBox(nullptr, "Nacisn¹³eœ s", "temp", MB_OK);
      key_tab[7] = true;
    }
    if ((wParam == KEYENTER) && (key_tab[8] == false))
    {
      MessageBox(nullptr, "Nacisn¹³eœ enter, w przysz³oœci uruchomi³byœ grê", "temp", MB_OK);
      key_tab[8] = true;
    }
    if ((wParam == KEYESCAPE) && (key_tab[9] == false))
    {
      MessageBox(nullptr, "Nacisn¹³eœ escape, zatrzyma³byœ grê, gdyby dzia³a³a", "temp", MB_OK);
      key_tab[9] = true;
    }

    return TRUE;
  }
  case WM_KEYUP:
  {
    if ((wParam == KEYLEFT) && (key_tab[0] == true))
    {
      MessageBox(nullptr, "Puœci³eœ strza³kê w lewo", "temp", MB_OK);
      key_tab[0] = false;
    }
    if ((wParam == KEYUP) && (key_tab[1] == true))
    {
      MessageBox(nullptr, "Puœci³eœ strza³kê w górê", "temp", MB_OK);
      key_tab[1] = false;
    }
    if ((wParam == KEYRIGHT) && (key_tab[2] == true))
    {
      MessageBox(nullptr, "Puœci³eœ strza³kê w prawo", "temp", MB_OK);
      key_tab[2] = false;
    }
    if ((wParam == KEYDOWN) && (key_tab[3] == true))
    {
      MessageBox(nullptr, "Puœci³eœ strza³kê w dó³", "temp", MB_OK);
      key_tab[3] = false;
    }
    if ((wParam == KEYA) && (key_tab[4] == true))
    {
      MessageBox(nullptr, "Puœci³eœ a", "temp", MB_OK);
      key_tab[4] = false;
    }
    if ((wParam == KEYW) && (key_tab[5] == true))
    {
      MessageBox(nullptr, "Puœci³eœ w", "temp", MB_OK);
      key_tab[5] = false;
    }
    if ((wParam == KEYD) && (key_tab[6] == true))
    {
      MessageBox(nullptr, "Puœci³eœ d", "temp", MB_OK);
      key_tab[6] = false;
    }
    if ((wParam == KEYS) && (key_tab[7] == true))
    {
      MessageBox(nullptr, "Puœci³eœ s", "temp", MB_OK);
      key_tab[7] = false;
    }
    if ((wParam == KEYENTER) && (key_tab[8] == true))
    {
      MessageBox(nullptr, "Puœci³eœ enter, cokolwiek", "temp", MB_OK);
      key_tab[8] = false;
    }
    if ((wParam == KEYESCAPE) && (key_tab[9] == true))
    {
      MessageBox(nullptr, "Puœci³eœ escape", "temp", MB_OK);
      key_tab[9] = false;
    }
    return TRUE;
  }
  case WM_INITDIALOG:
  {
    hBitmapBoard = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BITMAP_BOARD));
  }
  return TRUE;
  case WM_PAINT:
  {
    HDC hdc = GetDC(hwndDlg);
    DrawGameBoard(hdc);
    ReleaseDC(hwndDlg, hdc);
    return DefWindowProc(hwndDlg, uMsg, wParam, lParam);
  }
  case WM_CLOSE:
  {
    is_game_on = false;
    EndDialog(hwndDlg, 0);
    DestroyWindow(hwndDlg); // zniszczenie okna
  }
  return TRUE;
  default:;
  }
  return FALSE;
}

INT_PTR CALLBACK DialogPlayer(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
  HWND hwndPlayerview = GetDlgItem(hwndDlg, IDD_PLAYERVIEW);

  switch (uMsg)
  {

  case WM_COMMAND:
  {

    switch (HIWORD(wParam))
    {

    case BN_CLICKED:
      switch (LOWORD(wParam))
      {
      case IDC_BUTTON_PLAYER_SINGLE:
      {
        if (is_game_on == false)
        {
          HWND hwndGameWindow = CreateDialog(NULL, MAKEINTRESOURCE(IDD_GAMEVIEW), hwndPlayerview, DialogGame);
          ShowWindow(hwndGameWindow, SW_SHOW);
          MessageBox(hwndGameWindow, "Enter rozpoczyna grê", " ", MB_OK);
          is_game_on = true;
        }
        return TRUE;
      }

      case IDC_BUTTON_PLAYER_MULTI:
      {
        if (is_game_on == false)
        {
          HWND hwndGameWindow = CreateDialog(NULL, MAKEINTRESOURCE(IDD_GAMEVIEW), hwndPlayerview, DialogGame);
          ShowWindow(hwndGameWindow, SW_SHOW);
          is_game_on = true;
        }
        return TRUE;
      }
      case IDC_BUTTON_GOBACK:
        is_player_window_open = false;
      {
        EndDialog(hwndDlg, 0);
        DestroyWindow(hwndDlg); 
        return TRUE;
      }
      default:;
      }
    default:;
    }
  }
  return TRUE;
  case WM_INITDIALOG:
  {
    hBitmapMenuPlayer = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BITMAP_MENUPLAYER));
  }
  return TRUE;
  case WM_PAINT:
  {
    HDC hdc = GetDC(hwndDlg);
    DrawMenuPlayer(hdc);
    ReleaseDC(hwndDlg, hdc);
    return DefWindowProc(hwndDlg, uMsg, wParam, lParam);
  }
  case WM_CLOSE:
  {
    is_player_window_open = false;
    EndDialog(hwndDlg, 0);
    DestroyWindow(hwndDlg); 
  }
  return TRUE;
  default:;
  }
  return FALSE;
}

INT_PTR CALLBACK DialogMain(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)//Funkcja obs³ugi komunikatów
{
  HWND hwndMainview = GetDlgItem(hwndDlg, IDD_MAINVIEW);
  
  switch (uMsg)
  {

  case WM_COMMAND:
  {

    switch (HIWORD(wParam))
    {

    case BN_CLICKED:
      switch (LOWORD(wParam))
      {
      case IDC_BUTTON_NEW_GAME:
      {
        if(is_player_window_open==false){
          HWND hwndPlayerWindow = CreateDialog(NULL, MAKEINTRESOURCE(IDD_PLAYERVIEW), NULL, DialogPlayer);
          ShowWindow(hwndPlayerWindow, SW_SHOW);
          is_player_window_open = true;
        }
        return TRUE;
      }
      case IDC_BUTTON_CONTROL:
      {
        if (is_controls_window_open == false) 
        {
          HWND hwndControlWindow = CreateDialog(NULL, MAKEINTRESOURCE(IDD_CONTROLVIEW), NULL, DialogControl);
          ShowWindow(hwndControlWindow, SW_SHOW);
          is_controls_window_open = true;
        }
        return TRUE;
      }
      case IDC_BUTTON_END_GAME:
      {
        DestroyWindow(hwndMainview); 
        PostQuitMessage(0);
        return TRUE;
      }
      default:;
      }
    default:;
    }
  }
    return TRUE;
  case WM_INITDIALOG:
  {
    hBitmapMenu = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BITMAP_MENU));
  }
  return TRUE;
  case WM_PAINT:
  {
    HDC hdc = GetDC(hwndDlg);
    DrawMenu(hdc);
    ReleaseDC(hwndDlg, hdc);
    return DefWindowProc(hwndDlg, uMsg, wParam, lParam);
  }
  case WM_CLOSE:
  {
    DestroyWindow(hwndMainview); 
    PostQuitMessage(0); 
  }
  return TRUE;
  default:;
  }
  return FALSE;
}


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow)
{


  hInst = hInstance;
  HWND hwndMainWindow = CreateDialog(hInstance, MAKEINTRESOURCE(IDD_MAINVIEW), NULL, DialogMain);
  ShowWindow(hwndMainWindow, iCmdShow);



  MSG msg = {};
  while (GetMessage(&msg, nullptr, 0, 0))
  {
    TranslateMessage(&msg);
    DispatchMessage(&msg);

  }

}

void DrawMenu(HDC x)
{
  HDC hDCBitmap;
  hDCBitmap = CreateCompatibleDC(x);
  SelectObject(hDCBitmap, hBitmapMenu);
  BitBlt(x, 0, 0, 280, 220, hDCBitmap, 0, 0, SRCCOPY); //width, height
  DeleteDC(hDCBitmap);
}

void DrawMenuPlayer(HDC x)
{
  HDC hDCBitmap;
  hDCBitmap = CreateCompatibleDC(x);
  SelectObject(hDCBitmap, hBitmapMenuPlayer);
  BitBlt(x, 0, 0, 280, 180, hDCBitmap, 0, 0, SRCCOPY); //width, height
  DeleteDC(hDCBitmap);
  
}

void DrawGameBoard(HDC x)
{
  HDC hDCBitmap;
  hDCBitmap = CreateCompatibleDC(x);
  SelectObject(hDCBitmap, hBitmapBoard);
  BitBlt(x, 0, 0, 1250, 600, hDCBitmap, 0, 0, SRCCOPY); //width, height
  DeleteDC(hDCBitmap);  
}

void DrawGameControls(HDC x)
{
  HDC hDCBitmap;
  hDCBitmap = CreateCompatibleDC(x);
  SelectObject(hDCBitmap, hBitmapControls);
  BitBlt(x, 0, 0, 288, 162, hDCBitmap, 0, 0, SRCCOPY); //width, height
  DeleteDC(hDCBitmap);
}
