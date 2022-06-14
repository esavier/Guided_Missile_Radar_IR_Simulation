

#ifndef __GMS_NYSTROM_STEP_AVX_H__
#define __GMS_NYSTROM_STEP_AVX_H__ 040620220959


/*MIT License
Copyright (c) 2020 Bernard Gingold
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
SOFTWARE.
*/



/*
   Adapted from: http://www.mymathlib.com/diffeq/runge-kutta/runge_kutta_nystrom.html
   Manually vectorized by Bernard Gingold, beniekg@gmail.com
*/



    const unsigned int GMS_NYSTROM_STEP_AVX_MAJOR = 1U;
    const unsigned int GMS_NYSTROM_STEP_AVX_MINOR = 0U;
    const unsigned int GMS_NYSTROM_STEP_AVX_MICRO = 0U;
    const unsigned int GMS_NYSTROM_STEP_AVX_FULLVER =
      1000U*GMS_NYSTROM_STEP_AVX_MAJOR+
      100U*GMS_NYSTROM_STEP_AVX_MINOR+
      10U*GMS_NYSTROM_STEP_AVX_MICRO;
    const char * const GMS_NYSTROM_STEP_AVX_CREATION_DATE = "04-06-2022 09:59 PM +00200 (SAT 04 JUN 2022 GMT+2)";
    const char * const GMS_NYSTROM_STEP_AVX_BUILD_DATE    = __DATE__ ":" __TIME__;
    const char * const GMS_NYSTROM_STEP_AVX_AUTHOR        = "Programmer: Bernard Gingold, contact: beniekg@gmail.com";
    const char * const GMS_NYSTROM_STEP_AVX_DESCRIPTION   = "Vectorized (AVX) Runge-Kutta-Nystrom order 5 step."




#include <immintrin.h>
#include <stdint.h>


////////////////////////////////////////////////////////////////////////////////
//  double Runge_Kutta_Nystrom( double (*f)(double, double), double y0,       //
//                               double x0, double h, int number_of_steps );  //
//                                                                            //
//  Description:                                                              //
//     This routine uses the Runge-Kutta-Nystrom method described above to    //
//     approximate the solution at x = x0 + h * number_of_steps of the initial//
//     value problem y'=f(x,y), y(x0) = y0.                                   //
//                                                                            //
//  Arguments:                                                                //
//     double *f                                                              //
//            Pointer to the function which returns the slope at (x,y) of the //
//            integral curve of the differential equation y' = f(x,y) which   //
//            passes through the point (x0,y0).                               //
//     double y0                                                              //
//            The initial value of y at x = x0.                               //
//     double x0                                                              //
//            The initial value of x.                                         //
//     double h                                                               //
//            The step size.                                                  //
//     int    number_of_steps                                                 //
//            The number of steps. Must be a nonnegative integer.             //
//                                                                            //
//  Return Values:                                                            //
//     The solution of the initial value problem y' = f(x,y), y(x0) = y0 at   //
//     x = x0 + number_of_steps * h.                                          //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////



__m512d
nystrom_step_zmm8r8(__m512d(*)(__m512d,
			       __m512d),
		    __m512d,
		    __m512d,
		    const __m512d,
		    const int32_t) __attribute__((noinline))
			           __attribute__((hot))
				   __attribute__((regcall))
				   __attribute__((aligned(32)));


			
__m512
nystrom_step_zmm16r4(__m512(*)(__m512,
			       __m512),
		    __m512,
		    __m512,
		    const __m512,
		    const int32_t) __attribute__((noinline))
			           __attribute__((hot))
				   __attribute__((regcall))
				   __attribute__((aligned(32)));


__m512d
nystrom_richardson_zmm8r8(__m512d(*)(__m512d,
			             __m512d),
			  __m512d,
			  __m512d,
			  const __m512d,
			  const int32_t,
			  int32_t) __attribute__((noinline))
			           __attribute__((hot))
				   __attribute__((regcall))
				   __attribute__((aligned(32)));


__m512
nystrom_richardson_zmm16r4(__m512d(*)(__m512,
			             __m512),
			  __m512,
			  __m512,
			  const __m512,
			  const int32_t,
			  int32_t) __attribute__((noinline))
			           __attribute__((hot))
				   __attribute__((regcall))
				   __attribute__((aligned(32)));	     


















#endif /*__GMS_NYSTROM_STEP_AVX_H__*/