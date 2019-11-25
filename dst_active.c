

#include "dst_active.h"



bool is_dst_active(time_holder_t *dst_start,
                   time_holder_t *dst_end,
                   time_holder_t *time_now
                   )
{

    bool enable_dst = false;

    int start = (dst_start->hour*60) + dst_start->min;
    int end = (dst_end->hour*60) + dst_end->min;
    int now = (time_now->hour*60) + time_now->min;
    //printf("TM 3\n\r");


    /** Test if the DST if for Northen and Southern hemisphere */
    if(dst_start->month > dst_end->month){
       // printf("In the South\n\r");
       /** Handle DST for Southern hemisphere.
        * DST calculations work a bit diffrent since summer months cross the year mark.
       */

        /**Test if the current time is after dst should end*/
        if(dst_end->month <= time_now->month){
          // printf("South DST Disable MON 3\n\r");
            enable_dst = false;
        }
        /**Test if the current time is after dst should should
        * Override the value in the priviose if block
        */

        if(dst_start->month <= time_now->month){

            /**Test if the current month is when DST should start */
            if(dst_start->month == time_now->month){
               //printf("DST Start MON\n\r");
               /**Test if the current day is greater or equil to when DST should start
               * Allow the code to fall thought if the day is greater
               */
                if(dst_start->day <= time_now->day ){
                   // printf("DST Start Day\n\r");
                   if(dst_start->day == time_now->day ){
                       /**Test if the current hour is greater or equil to when DST should start
                        * Allow the code to fall thought if the hour is greater
                        */
                        if(start <= now){
                            enable_dst =  true;
                        }

                   }else{
                        enable_dst =  true;
                   }
                }
            }else{
                /**DST is active if if(dst_start->month <= time_now->month) is true*/
               // printf("South DST Enable MON 1\n\r");
                enable_dst =  true;
            }
        }


        /**Test if the current time is in the start of the year before dst should end */
        if(dst_end->month >= time_now->month){
           // printf("South DST Enable MON 2\n\r");
           /**Test if the current month is when dst should end*/
            if(dst_end->month == time_now->month){
               //printf("DST End MON\n\r");
               /**Test if the current day is before dst should end*/
                if(dst_end->day >= time_now->day ){
                    if(dst_start->day == time_now->day ){
                        //printf("DST End Day\n\r");
                       /**Test if the current hour is before dst should end*/
                        if(start > now){
                            enable_dst =  true;
                        }
                    }else{
                        enable_dst =  true;
                    }
                }
            }else{
                enable_dst =  true;
            }

        }

    }else{
         //printf("In the North\n\r");
        if((dst_start->month <= time_now->month) && (time_now->month < dst_end->month)){
            //printf("North DST Enable MON\n\r");

            if(dst_start->month == time_now->month){

            //printf("DST Start MON\n\r");
               /**Test if the current day is greater or equil to when DST should start
               * Allow the code to fall thought if the day is greater
               */
                if(dst_start->day <= time_now->day ){
                   // printf("DST Start Day\n\r");
                   if(dst_start->day == time_now->day ){
                       /**Test if the current hour is greater or equil to when DST should start
                        * Allow the code to fall thought if the hour is greater
                        */
                        if(start <= now){
                            enable_dst =  true;
                        }

                   }else{
                        enable_dst =  true;
                   }
                }
            }else{
                enable_dst =  true;
            }
        }else{
            /**Test if the current time is in the start of the year before dst should end */
            if(dst_end->month == time_now->month){
               // printf("South DST Enable MON 2\n\r");
               /**Test if the current month is when dst should end*/
                if(dst_end->month == time_now->month){
                   //printf("DST End MON\n\r");
                   /**Test if the current day is before dst should end*/
                    if(dst_end->day >= time_now->day){
                        //printf("DST End Day\n\r");
                        if(dst_end->day == time_now->day){
                            /**Test if the current hour is before dst should end*/
                            if(start > now){
                                enable_dst =  true;
                            }

                        }else{
                            enable_dst =  true;
                        }

                    }
                }else{
                    enable_dst =  false;
                }

            }
        }
    }
    //printf("\n\r");


    return enable_dst;
}
