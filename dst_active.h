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


#ifndef DST_ACTIVE_H_INCLUDED
#define DST_ACTIVE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


/**@brief Structur containing the time infromation for dst.*/

typedef struct{
    int day;   /**start\end day of dst value 0-31*/
    int month; /**start\end month of dst value 1-12*/
    int hour;  /**start\end hour of dst value 0-23*/
    int min;   /**start\end min of dst value 0-59*/
}time_holder_t;

/**@brief Function that take in UTC time and determines if Daylight Savings Time(DST) time is active.
 *
 *@details The Function takes in the current unmodified UTC time without the year with user defined start and end times of
 * when Daylight Savings Time(DST) is in effect. This function works for both the Northen and Southern hemisphere. Found that
 * the end hour and min of DST is irrelavant when fed UTC.
 *
 *@param[in]  dst_start Pointer to a structure containing the information when DST starts
 *@param[in]  dst_end   Pointer to a structure containing the information when DST end
 *@param[in]  time_now  Pointer to a structure containing the current unmodified UTC time.
 *
 *@retval true   DST is currently active
 *@retval false  DST is currently inactive
 */

bool is_dst_active(time_holder_t *dst_start,
                   time_holder_t *dst_end,
                   time_holder_t *time_now
                   );

#endif // DST_ACTIVE_H_INCLUDED
