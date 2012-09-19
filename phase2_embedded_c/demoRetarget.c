/*******************************************************************************
*
* demoRetarget.c
*
* TODO comment this
*
* Rob Laswick
* Sept 17 2012
*
* Copyright (C) 2012 www.laswick.net
*
* This program is free software.  It comes without any warranty, to the extent
* permitted by applicable law.  You can redistribute it and/or modify it under
* the terms of the WTF Public License (WTFPL), Version 2, as published by
* Sam Hocevar.  See http://sam.zoy.org/wtfpl/COPYING for more details.
* Canada Day 2012
*
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>

#include "kinetis.h"

#include "hardware.h"
#include "globalDefs.h"
#include "util.h"

int main(void)
{
    uart_install();

    int fd = open("uart3", 0, 0);

    if (fd == -1)
        assert(0);

    //ioctl(fd, IO_IOCTL_UART_BAUD_SET, 115200);

    //printf("The start of something good...\r\n"); /* StdOut is uart3 */

    char str[] = "laswick";

    for (;;)
        write(fd, str, strlen(str));

    int i;
    volatile uartPort_t *uart = UART3_REG_PTR;
    for (i = 0; str[i]; i++) {
        delay();
        uart->d = str[i];
    }

    close(fd);

    return 0;
}