#include <time.h>
#include <iostream>

std::string timeToTimestamp(time_t time)
{
    struct tm *p = localtime(&time);
    char buf[100];
    size_t len = strftime(buf, sizeof buf - 1, "%FT%T%z", p);
    if (len > 1)
    {
        char minute[] = {buf[len - 2], buf[len - 1], '\0'};
        sprintf(buf + len - 2, ":%s", minute);
    }
    return buf;
}