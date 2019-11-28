/*MIT License

Copyright (c) 2019 Devilbinder

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.*/


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
                    /**Test if the current day is the day dst should end*/
                    if(dst_start->day == time_now->day ){
                        //printf("DST End Day\n\r");
                       /**Test if the current time in min is before dst should end*/
                        if(start > now){
                            enable_dst =  true;
                        }
                    }else{
                        /**if the day is after dst is active, skip time test*/
                        enable_dst =  true;
                    }
                }
            }else{
                /**if the month is after dst is active, skip month test*/
                enable_dst =  true;
            }

        }

    }else{
         //printf("In the North\n\r");
        if((dst_start->month <= time_now->month) && (time_now->month < dst_end->month)){
            //printf("North DST Enable MON\n\r");
            /**Test if the current month is when dst should end*/
            if(dst_start->month == time_now->month){

            //printf("DST Start MON\n\r");
               /**Test if the current day is greater or equil to when DST should start
               * Allow the code to fall thought if the day is greater
               */
                if(dst_start->day <= time_now->day ){
                   // printf("DST Start Day\n\r");
                   /**Test if the current time in min is before dst should end*/
                   if(dst_start->day == time_now->day ){
                        /**Test if the current time in min is before dst should end*/
                        if(start <= now){
                            enable_dst =  true;
                        }

                   }else{
                        enable_dst =  true;
                   }
                }
            }else{
                /**if the month is after dst is active, skip month test*/
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
                            /**Test if the current time in min is before dst should end*/
                            if(start > now){
                                enable_dst =  true;
                            }

                        }else{
                            /**if the day is after dst is active, skip time test*/
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
