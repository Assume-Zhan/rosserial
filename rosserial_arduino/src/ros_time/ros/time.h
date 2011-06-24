/* 
 * Software License Agreement (BSD License)
 *
 * Copyright (c) 2011, Willow Garage, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 *  * Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *  * Redistributions in binary form must reproduce the above
 *    copyright notice, this list of conditions and the following
 *    disclaimer in the documentation and/or other materials provided
 *    with the distribution.
 *  * Neither the name of Willow Garage, Inc. nor the names of its
 *    contributors may be used to endorse or promote prducts derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

/* 
 * Author: Michael Ferguson
 */

#ifndef ros_time_h_included
#define ros_time_h_included

#include <ros.h>
//#include <ros/duration.h>
#include <math.h>

#define ROS_TIME_IN_USE

namespace ros
{
  void normalizeSecNSec(unsigned long& sec, unsigned long& nsec);

  class Time
  {
    public:
      unsigned long sec, nsec; 

      Time() : sec(0), nsec(0) {}
      Time(unsigned long _sec, unsigned long _nsec) : sec(_sec), nsec(_nsec)
      {
        normalizeSecNSec(sec, nsec);  
      } 
        
      float toSec() const { return (float)sec + 1e-9*(float)nsec; };
      void fromSec(float t) { sec = (unsigned long) floor(t); nsec = (unsigned long) round((t-sec) * 1e9); } ;  
      unsigned long toNsec() { return (unsigned long)sec*1000000000ull + (unsigned long)nsec; };
      void fromNSec(long t);

      static Time now();
  };

}

#endif