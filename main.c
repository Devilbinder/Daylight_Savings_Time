#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>



#include "dst_active.h"

#define SOUTH 0
#define NORTH 1
#define TIME_TEST 0

int main()
{
    time_t now;
    struct tm *timeinfo;
    char strftime_buf[64];


    time_holder_t start_dst;
    time_holder_t end_dst;
    time_holder_t time_now;
    time_holder_t time_offset;



#if SOUTH == 1
    start_dst.day = 25;
    start_dst.month = 10;
    start_dst.hour = 1;
    start_dst.min = 30;

    //single day test
    time_now.day = 26;
    time_now.month = 3;
    time_now.hour = 2;
    time_now.min = 0;

    end_dst.day = 25;
    end_dst.month = 3;

  #elif NORTH == 1
    start_dst.day = 25;
    start_dst.month = 4;
    start_dst.hour = 1;
    start_dst.min = 30;

    //single day test
    time_now.day = 26;
    time_now.month = 3;
    time_now.hour = 2;
    time_now.min = 0;

    end_dst.day = 25;
    end_dst.month = 8;

  #endif

  time_offset.hour = time_now.hour;
  time_offset.min = start_dst.min;


    // north
    // start < now < end //the start date of dst in the north fall inbetween a time range

    //south
    //start > end // the start date of dst in the south is greater than the end date
    //start < now
    //end < now
    //start > now > end

    int i = 1;
    int j = 1;
    int k = 1;
    int l = 1;
    bool enable_dst = false;
    //single day test
    //enable_dst = is_dst_active(&start_dst,&end_dst,&time_now);
   // printf("DST value = %d",enable_dst);


    //year loop
    bool last_state = false;
    for(i = 1;i < 13;i++){
        time_now.month = i;
        //printf("Month %02d %02d %02d\n\r",start_dst.month,time_now.month,end_dst.month);
        for(j = 1;j < 32;j++){
            time_now.day = j;
            for(k = 0;k < 24;k++){
                time_now.hour = k;
                for(l = 0;l < 60;l++){
                    time_now.min = l;
                    enable_dst = is_dst_active(&start_dst,&end_dst,&time_now);

                    if(enable_dst != last_state){
                        //print date and time dst was active  and inactive
                        printf("%02d-%02d %02d:%02d %02d\n\r",time_now.day,time_now.month,time_now.hour,time_now.min,enable_dst);
                        last_state = enable_dst;
                    }


                }
            }
        }
    }

    //implementation
    time(&now);
    timeinfo = localtime(&now);
    char timezone[10] = "UTC-00:00";

    time_now.day = timeinfo->tm_mday;
    time_now.month = timeinfo->tm_mon;
    time_now.hour = timeinfo->tm_hour;
    time_now.min = timeinfo->tm_min;

    enable_dst = is_dst_active(&start_dst,&end_dst,&time_now);

    if(enable_dst){
        timezone[4] += time_offset.hour / 10;
        timezone[5] += time_offset.hour % 10;
        timezone[7] += time_offset.min / 10;
        timezone[8] += time_offset.min % 10;
    }

    // Set timezone to Standard Time
#ifndef __WIN32
    setenv("TZ", timezone, 1);
#endif // __WIN32
    tzset();


    // update 'now' variable with current time
    time(&now);
    timeinfo = localtime(&now);


    strftime(strftime_buf, sizeof(strftime_buf), "%c", &timeinfo);
    //printf("The current date/time: %s xx", strftime_buf);
    printf("The current date/time: %s\n\r", asctime(timeinfo));


    return 0;
}
