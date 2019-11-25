# **Daylight Savings Time**

**Under Testing**

The Function takes in the current unmodified UTC time without the year with user defined start and end times of
when Daylight Savings Time(DST) is in effect. This function works for both the Northen and Southern hemisphere.

param[in]  dst_start Pointer to a structure containing the information when DST starts

param[in]  dst_end   Pointer to a structure containing the information when DST end

param[in]  time_now  Pointer to a structure containing the current unmodified UTC time.

retval true   DST is currently active

retval false  DST is currently inactive

