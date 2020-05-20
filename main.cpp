/*
 * EVEtomo
 *
 * Copyright (c) 2020 Simon Piorecki
 */

#ifdef WIN32
#include <windows.h>
#endif

int getPrimaryScreenWidth();
int getPrimaryScreenHeight();

int main()
{

    return 0;
}

int getPrimaryScreenWidth()
{
#ifdef WIN32
    return GetSystemMetrics(SM_CXSCREEN);
#endif
}

int getPrimaryScreenHeight()
{
#ifdef WIN32
    return GetSystemMetrics(SM_CYSCREEN);
#endif
}
