#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>



#include "dst_active.h"

#define TIME_NOW "Sun Nov 24 17:10:23 2019"

int main()
{
    struct tm dst_test;
    struct tm dst_start;
    struct tm dst_end;


    time_holder_t start_dst;
    time_holder_t end_dst;
    time_holder_t time_now;


    start_dst.day = 25;
    start_dst.month = 10;
    start_dst.hour = 1;
    start_dst.min = 30;

    time_now.day = 26;
    time_now.month = 3;
    time_now.hour = 2;
    time_now.min = 0;

    end_dst.day = 25;
    end_dst.month = 3;
  //  end_dst.hour = 2;
  //  end_dst.min = 0;


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
    //enable_dst = is_dst_active(&start_dst,&end_dst,&time_now);
   // printf("DST value = %d",enable_dst);

    //day loop
   /* for(k = 0;k < 24;k++){
        time_now.hour = k;
        for(l = 0;l < 60;l++){
            time_now.min = l;
            enable_dst = is_dst_active(&start_dst,&end_dst,&time_now);
            if(enable_dst){
                printf("%02d-%02d %02d:%02d\n\r",time_now.day,time_now.month,time_now.hour,time_now.min);
            }
            enable_dst=false;

        }
    }*/



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
                        printf("%02d-%02d %02d:%02d %02d\n\r",time_now.day,time_now.month,time_now.hour,time_now.min,enable_dst);
                        last_state = enable_dst;
                    }


                }
            }
        }



    }

    return 0;
}
