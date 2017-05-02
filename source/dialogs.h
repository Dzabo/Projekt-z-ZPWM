#ifndef ZPWM_DIALOGS_H_
#define ZPWM_DIALOGS_H_

inline INT_PTR CALLBACK DialogControl(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
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

inline INT_PTR CALLBACK DialogGame(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
  //HWND hwndGameview = GetDlgItem(hwndDlg, IDD_GAMEVIEW);

  switch (uMsg)
  {

  case WM_COMMAND:
  {

    switch (HIWORD(wParam))
    {

    case BN_CLICKED://Zdarzenie klikniecia 
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
        MessageBox(0, "Najpierw trzeba zacz1a hehe", " ", MB_OK);
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
      key_tab[0] = true;
      //while (key_tab[0] == true)
      //{
      DrawGameBoard(GetDC(hwndDlg));
      player_one->move_left();
      DrawPlayers(GetDC(hwndDlg));
      //}
    }
    if ((wParam == KEYUP) && (key_tab[1] == false))
    {
      key_tab[1] = true;
      //while (key_tab[1] == true)
      //{
      DrawGameBoard(GetDC(hwndDlg));
      player_one->move_up();
      DrawPlayers(GetDC(hwndDlg));
      //}
    }
    if ((wParam == KEYRIGHT) && (key_tab[2] == false))
    {
      key_tab[2] = true;
      //while (key_tab[2] == true)
      //{
      DrawGameBoard(GetDC(hwndDlg));
      player_one->move_right();
      DrawPlayers(GetDC(hwndDlg));
      //}
    }
    if ((wParam == KEYDOWN) && (key_tab[3] == false))
    {
      key_tab[3] = true;
      //while (key_tab[3] == true)
      //{
      DrawGameBoard(GetDC(hwndDlg));
      player_one->move_down();
      DrawPlayers(GetDC(hwndDlg));
      //}
    }
    if ((wParam == KEYA) && (key_tab[4] == false) && (is_multiplayer == true))
    {
      key_tab[4] = true;
      DrawGameBoard(GetDC(hwndDlg));
      player_two->move_left();
      DrawPlayers(GetDC(hwndDlg));
    }
    if ((wParam == KEYW) && (key_tab[5] == false) && (is_multiplayer == true))
    {
      key_tab[5] = true;
      DrawGameBoard(GetDC(hwndDlg));
      player_two->move_up();
      DrawPlayers(GetDC(hwndDlg));
    }
    if ((wParam == KEYD) && (key_tab[6] == false) && (is_multiplayer == true))
    {
      key_tab[6] = true;
      DrawGameBoard(GetDC(hwndDlg));
      player_two->move_right();
      DrawPlayers(GetDC(hwndDlg));
    }
    if ((wParam == KEYS) && (key_tab[7] == false) && (is_multiplayer == true))
    {
      key_tab[7] = true;
      DrawGameBoard(GetDC(hwndDlg));
      player_two->move_down();
      DrawPlayers(GetDC(hwndDlg));
    }
    if ((wParam == KEYENTER) && (key_tab[8] == false))
    {
      player_one = new Player(STARTX, (STARTYMIN + 10));
      player_two = new Player(STARTX, (STARTYMAX - 10));
      DrawPlayers(GetDC(hwndDlg));
      key_tab[8] = true;
    }
    if ((wParam == KEYESCAPE) && (key_tab[9] == false))
    {
      MessageBox(nullptr, "Nacisnales escape, zatrzymalbys gre, gdyby dzialala", "temp", MB_OK);
      key_tab[9] = true;
    }

    return TRUE;
  }
  case WM_KEYUP:
  {
    if ((wParam == KEYLEFT) && (key_tab[0] == true))
    {
      key_tab[0] = false;
    }
    if ((wParam == KEYUP) && (key_tab[1] == true))
    {
      key_tab[1] = false;
    }
    if ((wParam == KEYRIGHT) && (key_tab[2] == true))
    {
      key_tab[2] = false;
    }
    if ((wParam == KEYDOWN) && (key_tab[3] == true))
    {
      key_tab[3] = false;
    }
    if ((wParam == KEYA) && (key_tab[4] == true))
    {
      key_tab[4] = false;
    }
    if ((wParam == KEYW) && (key_tab[5] == true))
    {
      key_tab[5] = false;
    }
    if ((wParam == KEYD) && (key_tab[6] == true))
    {
      key_tab[6] = false;
    }
    if ((wParam == KEYS) && (key_tab[7] == true))
    {
      key_tab[7] = false;
    }
    if ((wParam == KEYENTER) && (key_tab[8] == true))
    {
      key_tab[8] = false;
    }
    if ((wParam == KEYESCAPE) && (key_tab[9] == true))
    {
      MessageBox(nullptr, "Pusciles escape", "temp", MB_OK);
      key_tab[9] = false;
    }
    return TRUE;
  }
  case WM_INITDIALOG:
  {
    hBitmapBoard = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BITMAP_BOARD));
    hBitmapPlayer1 = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_PLAYER1));
    hBitmapPlayer1N = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_PLAYER1_N));
    hBitmapPlayer1E = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_PLAYER1_E));
    hBitmapPlayer1S = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_PLAYER1_S));
    hBitmapPlayer1W = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_PLAYER1_W));
    hBitmapPlayer2 = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_PLAYER2));
    hBitmapPlayer2N = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_PLAYER2_N));
    hBitmapPlayer2E = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_PLAYER2_E));
    hBitmapPlayer2S = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_PLAYER2_S));
    hBitmapPlayer2W = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_PLAYER2_W));
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

inline  INT_PTR CALLBACK DialogPlayer(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
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
          MessageBox(hwndGameWindow, "Enter rozpoczyna gre", " ", MB_OK);
          is_game_on = true;
          is_multiplayer = false;
        }
        return TRUE;
      }

      case IDC_BUTTON_PLAYER_MULTI:
      {
        if (is_game_on == false)
        {
          HWND hwndGameWindow = CreateDialog(NULL, MAKEINTRESOURCE(IDD_GAMEVIEW), hwndPlayerview, DialogGame);
          ShowWindow(hwndGameWindow, SW_SHOW);
          MessageBox(hwndGameWindow, "Enter rozpoczyna gre", " ", MB_OK);
          is_game_on = true;
          is_multiplayer = true;
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

inline INT_PTR CALLBACK DialogMain(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)//Funkcja obs3ugi komunikatów
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
        if (is_player_window_open == false) {
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

#endif