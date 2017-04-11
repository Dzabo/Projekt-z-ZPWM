#include <Windows.h>
#include "res.h"
#include <stdio.h>

CHAR szText[200];
HBITMAP hBitmapMenu;
HBITMAP hBitmapMenuPlayer;
HINSTANCE hInst;

void DrawMenu(HDC x);
void DrawMenuPlayer(HDC x);


INT_PTR CALLBACK DialogProc(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)//Funkcja obs³ugi komunikatów
{
  HWND hwndGameview = GetDlgItem(hwndDlg, IDD_GAMEVIEW);
  HWND hwndMainview = GetDlgItem(hwndDlg, IDD_MAINVIEW);
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
      case IDC_BUTTON_NEW_GAME:
      {
        HWND hwndPlayerWindow = CreateDialog(NULL, MAKEINTRESOURCE(IDD_PLAYERVIEW), hwndMainview, DialogProc);
        ShowWindow(hwndPlayerWindow, SW_SHOW);
        return TRUE;
      }
      case IDC_BUTTON_PLAYER_SINGLE:
      {
        HWND hwndGameWindow = CreateDialog(NULL, MAKEINTRESOURCE(IDD_GAMEVIEW), hwndPlayerview, DialogProc);
        ShowWindow(hwndGameWindow, SW_SHOW);
        return TRUE;

      }
      case IDC_BUTTON_PLAYER_MULTI:
      {
        HWND hwndGameWindow = CreateDialog(NULL, MAKEINTRESOURCE(IDD_GAMEVIEW), hwndPlayerview, DialogProc);
        ShowWindow(hwndGameWindow, SW_SHOW);
        return TRUE;
      }
      case IDC_BUTTON_CONTROL:
      {
        MessageBox(hwndDlg, TEXT("Gracz 1 strza³ki, Gracz 2 wsad"), TEXT("Sterowanie"), MB_OK);
        return TRUE;
      }
      case IDC_BUTTON_GOBACK:
      {
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
    hBitmapMenuPlayer = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BITMAP_MENUPLAYER));
  }
  return TRUE;
  case WM_PAINT:
  {
    HDC hdc = GetDC(hwndDlg);
   /* HDC hdc2 = GetDC(hwndMainview);
    HDC hdc3 = GetDC(hwndPlayerview);*/
    DrawMenu(hdc);
    DrawMenuPlayer(hdc);
    ReleaseDC(hwndDlg, hdc);
    return DefWindowProc(hwndDlg, uMsg, wParam, lParam);
  }
  case WM_CLOSE:
  {
    DestroyWindow(hwndDlg); // zniszczenie okna
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
  HWND hwndMainWindow = CreateDialog(hInstance, MAKEINTRESOURCE(IDD_MAINVIEW), NULL, DialogProc);
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
/*
1252x600
*/
