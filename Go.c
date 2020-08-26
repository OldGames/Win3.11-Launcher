/*
 * Old-Games.Org Win3.11 Launcher
 * Based on template from https://github.com/yeokm1/programming-win31/tree/master/disk-files/CHAP01
 */

#include <windows.h>

#define TARGET_PROGRAM "calc.exe                                                                         "

long FAR PASCAL _export WndProc (HWND, UINT, UINT, LONG) ;

int PASCAL WinMain (HANDLE hInstance, HANDLE hPrevInstance,
                    LPSTR lpszCmdParam, int nCmdShow)
{
    static char szAppName[] = "Old-Games.org Win3.11 Launcher" ;
    HWND        hwnd ;
    MSG         msg ;
    WNDCLASS    wndclass ;

    if (!hPrevInstance)
    {
        wndclass.style         = CS_HREDRAW | CS_VREDRAW;
        wndclass.lpfnWndProc   = WndProc;
        wndclass.cbClsExtra    = 0;
        wndclass.cbWndExtra    = 0;
        wndclass.hInstance     = hInstance;
        wndclass.hIcon         = LoadIcon (NULL, IDI_APPLICATION);
        wndclass.hCursor       = LoadCursor (NULL, IDC_ARROW);
        wndclass.hbrBackground = GetStockObject (BLACK_BRUSH);
        wndclass.lpszMenuName  = NULL;
        wndclass.lpszClassName = szAppName;

        RegisterClass (&wndclass) ;
    }

    hwnd = CreateWindow (szAppName,             // window class name
                         "Old-Games.org",       // window caption
                         WS_OVERLAPPEDWINDOW,   // window style
                         CW_USEDEFAULT,         // initial x position
                         CW_USEDEFAULT,         // initial y position
                         490,                   // initial x size
                         295,                   // initial y size
                         NULL,                  // parent window handle
                         NULL,                  // window menu handle
                         hInstance,             // program instance handle
                         NULL) ;                // creation parameters  

    ShowWindow (hwnd, nCmdShow) ;
    UpdateWindow (hwnd) ;

    while (GetMessage (&msg, NULL, 0, 0))
    {
        TranslateMessage (&msg) ;
        DispatchMessage (&msg) ;
    }
    return msg.wParam ;
}

void PrintMultiLine(RECT* p_rect, HDC hdc, LPCSTR lpchText)
{
   int height;
   height = DrawText (hdc, lpchText, -1, p_rect, DT_SINGLELINE | DT_CENTER);
   OffsetRect(p_rect, 0, height);
}

long FAR PASCAL _export WndProc (HWND hwnd, UINT message, UINT wParam,
                                                          LONG lParam)
{
    HDC         hdc;
    PAINTSTRUCT ps;
    RECT        rect;
    HFONT       hFont;
    COLORREF rgbBackground;
    COLORREF rgbText;
     

    switch (message)
    {
        case WM_PAINT:
            rgbBackground   = RGB(0x0c, 0x0c, 0x0c);
            rgbText         = RGB(0xcc, 0xcc, 0xcc);
            
            hdc             = BeginPaint (hwnd, &ps);
                
            hFont = CreateFont (13, 0, 0, 0, FW_DONTCARE, FALSE, FALSE, FALSE, ANSI_CHARSET, 
                                OUT_TT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, 
                                DEFAULT_PITCH | FF_DONTCARE, "Courier New");
            SetBkColor(hdc, rgbBackground);
            SetTextColor(hdc, rgbText);
            SelectObject(hdc, hFont);
            GetClientRect(hwnd, &rect) ;
            OffsetRect(&rect, 0, 1);

            PrintMultiLine(&rect, hdc, " ############################################################################## ");
            PrintMultiLine(&rect, hdc, " #                                                                            # ");
            PrintMultiLine(&rect, hdc, " #             #                                                              # ");
            PrintMultiLine(&rect, hdc, " #             ######   #     #        #      #   #####   #  ###              # ");
            PrintMultiLine(&rect, hdc, " #                   #  ##    #        #      #  #     #  # #   #             # ");
            PrintMultiLine(&rect, hdc, " #                   #  # #  #          #     #  #     #  ##    #             # ");
            PrintMultiLine(&rect, hdc, " #                   #  #  # #          #     #  #     #  #     #             # ");
            PrintMultiLine(&rect, hdc, " #                   #  #   #            #    #  #     #  #     #             # ");
            PrintMultiLine(&rect, hdc, " #                   #  #    #           #    #   #   #   #     #             # ");
            PrintMultiLine(&rect, hdc, " #             ######   #     #        #######     ###    # ####              # ");
            PrintMultiLine(&rect, hdc, " #                                                                            # ");
            PrintMultiLine(&rect, hdc, " #                                                                            # ");
            PrintMultiLine(&rect, hdc, " #                     ######   #####    #     #  ######                      # ");
            PrintMultiLine(&rect, hdc, " #                           #       #   #     #        #                     # ");
            PrintMultiLine(&rect, hdc, " #                           #       #    #    #        #                     # ");
            PrintMultiLine(&rect, hdc, " #                           #       #    #    #        #                     # ");
            PrintMultiLine(&rect, hdc, " #                           #       #     #   #  #     #                     # ");
            PrintMultiLine(&rect, hdc, " #                           #       #     #   #  #     #                     # ");
            PrintMultiLine(&rect, hdc, " #                           #  #######  ######   #     #                     # ");
            PrintMultiLine(&rect, hdc, " #                                                                            # ");
            PrintMultiLine(&rect, hdc, " #                                                                            # ");
            PrintMultiLine(&rect, hdc, " ########################### http://www.old-games.org ######################### ");
            PrintMultiLine(&rect, hdc, "                                                                                ");
            
            EndPaint(hwnd, &ps) ;
            return 0;

        case WM_KEYDOWN:
            PostMessage(hwnd, WM_CLOSE, 0, 0);
            return 0;

        case WM_DESTROY:   
            WinExec(TARGET_PROGRAM, SW_SHOWNORMAL);
            PostQuitMessage(0);
            return 0;
    }

    return DefWindowProc (hwnd, message, wParam, lParam);
}
