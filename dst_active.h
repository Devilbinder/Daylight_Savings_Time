#ifndef DST_ACTIVE_H_INCLUDED
#define DST_ACTIVE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct{
    int day;
    int month;
    int hour;
    int min;
}time_holder_t;

/**@brief Function that take in UTC time and determines if Daylight Savings Time(DST) time is active.
 *
 *@details The Function takes in the current unmodified UTC time without the year with user defined start and end times of
 * when Daylight Savings Time(DST) is in effect. This function works for both the Northen and Southern hemisphere.
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
