#include <Windows.h>
#include "res.h"
#include <stdio.h>

CHAR szText[200];
HBITMAP hBitmapMenu;
HBITMAP hBitmapMenuPlayer;
HBITMAP hBitmapBoard;
HBITMAP hBitmapControls;
HINSTANCE hInst;
bool is_game_on = false;

void DrawMenu(HDC x);
void DrawMenuPlayer(HDC x);
void DrawGameBoard(HDC x);
void DrawGameControls(HDC x);

INT_PTR CALLBACK DialogControl(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)//Funkcja obs³ugi komunikatów
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
    EndDialog(hwndDlg, 0);
    DestroyWindow(hwndDlg); // zniszczenie okna
  }
  return TRUE;
  default:;
  }
  return FALSE;
}

INT_PTR CALLBACK DialogGame(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)//Funkcja obs³ugi komunikatów
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
      
      default:;
      }
    default:;
    }
  }
  return TRUE;
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

INT_PTR CALLBACK DialogPlayer(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)//Funkcja obs³ugi komunikatów
{
  HWND hwndPlayerview = GetDlgItem(hwndDlg, IDD_PLAYERVIEW);

  switch (uMsg)
  {

  case WM_COMMAND:
  {

    switch (HIWORD(wParam))
    {

    case BN_CLICKED://Zdarzenie klikniêcia 
      switch (LOWORD(wParam))
      {
      case IDC_BUTTON_PLAYER_SINGLE:
      {
        if (is_game_on == false)
        {
          HWND hwndGameWindow = CreateDialog(NULL, MAKEINTRESOURCE(IDD_GAMEVIEW), hwndPlayerview, DialogGame);
          ShowWindow(hwndGameWindow, SW_SHOW);
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
      {
        EndDialog(hwndDlg, 0);
        DestroyWindow(hwndDlg); // zniszczenie okna
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
    EndDialog(hwndDlg, 0);
    DestroyWindow(hwndDlg); // zniszczenie okna
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

    case BN_CLICKED://Zdarzenie klikniêcia 
      switch (LOWORD(wParam))
      {
      case IDC_BUTTON_NEW_GAME:
      {
        HWND hwndPlayerWindow = CreateDialog(NULL, MAKEINTRESOURCE(IDD_PLAYERVIEW), NULL, DialogPlayer);
        ShowWindow(hwndPlayerWindow, SW_SHOW);
        return TRUE;
      }
      case IDC_BUTTON_CONTROL:
      {
        HWND hwndControlWindow = CreateDialog(NULL, MAKEINTRESOURCE(IDD_CONTROLVIEW), NULL, DialogControl);
        ShowWindow(hwndControlWindow, SW_SHOW);
        return TRUE;
      }
      case IDC_BUTTON_END_GAME:
      {
        DestroyWindow(hwndMainview); // zniszczenie okna
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
    DestroyWindow(hwndMainview); // zniszczenie okna
    PostQuitMessage(0); //Komunikat polecenia zakoñczenia aplikacji
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
  while (GetMessage(&msg, NULL, 0, 0))
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
  BitBlt(x, 0, 0, 280, 220, hDCBitmap, 0, 0, SRCCOPY); //szerokosc,wysokosc
  DeleteDC(hDCBitmap);
}

void DrawMenuPlayer(HDC x)
{
  HDC hDCBitmap;
  hDCBitmap = CreateCompatibleDC(x);
  SelectObject(hDCBitmap, hBitmapMenuPlayer);
  BitBlt(x, 0, 0, 280, 180, hDCBitmap, 0, 0, SRCCOPY); //szerokosc,wysokosc
  DeleteDC(hDCBitmap);
  
}

void DrawGameBoard(HDC x)
{
  HDC hDCBitmap;
  hDCBitmap = CreateCompatibleDC(x);
  SelectObject(hDCBitmap, hBitmapBoard);
  BitBlt(x, 0, 0, 1250, 600, hDCBitmap, 0, 0, SRCCOPY); //szerokosc,wysokosc
  DeleteDC(hDCBitmap);  
}

void DrawGameControls(HDC x)
{
  HDC hDCBitmap;
  hDCBitmap = CreateCompatibleDC(x);
  SelectObject(hDCBitmap, hBitmapControls);
  BitBlt(x, 0, 0, 288, 162, hDCBitmap, 0, 0, SRCCOPY); //szerokosc,wysokosc
  DeleteDC(hDCBitmap);
}
