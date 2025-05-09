/***************************************************************************
****************************************************************************
*   File: D:\owncloud\LEnsE\Concours\Maquettes\Maquette_Filtre_Numerique\IIR_butter_band_pass_400_500.c
*   Created by dsPIC FD Lite Version 1.0.0 Build 1 at 19:57:36 Jul 01 2024
*   C Code Generator - Version 4.0  
****************************************************************************
*  Code Fragment to implement filter
*
*  The functions defined in 'qed_filt.c' must be compiled and linked in.
*    This can be accomplished by either #include "qed_filt.c"
*    or by separately compiling and linking 'qed_filt.c'
*
*** following is actual code fragment
*  extern BiquadSections IIR_IIR_butter_ba;
*
*  init_biquad_float (&IIR_IIR_butter_ba);  // initialize filter structure 
*
*  IIR_IIR_butter_ba.filter ( x, y, n, &IIR_IIR_butter_ba);  // x is an array of input samples
*                                            // y is an array of output samples
*                                            // n is number of samples to process
*                                            // &IIR_IIR_butter_ba is a pointer to the
*                                            //    filter structure
*****************************************************************************
*  This is a complete program which can be compiled and run to test the filter.
*  To change this to a subroutine only, just add in this program or add globally
*     in "qed_cgen.h" the line with the definition of DEFINE_SUBROUTINE as follows
*  #define DEFINE_SUBROUTINE
*****************************************************************************
****************************************************************************/

/* qed_cgen.h contains definitions of filter structures and function prototypes */
#include "qed_cgen.h"

/* filter functions are in files 'qed_filt.c'  */

float IIR_butter_ba_num[  9] = {
   9.643554687500e-003F,  /* b[  1, 0] */
   0.000000000000e+000F,  /* b[  1, 1] */
  -9.643554687500e-003F,  /* b[  1, 2] */
   7.019042968750e-003F,  /* b[  2, 0] */
   0.000000000000e+000F,  /* b[  2, 1] */
  -7.019042968750e-003F,  /* b[  2, 2] */
   1.345825195313e-002F,  /* b[  3, 0] */
   0.000000000000e+000F,  /* b[  3, 1] */
  -1.345825195313e-002F}; /* b[  3, 2] */

float IIR_butter_ba_den[  9] = {
   5.000000000000e-001F,  /* a[  1, 0] */
  -9.710083007813e-001F,  /* a[  1, 1] */
   4.806823730469e-001F,  /* a[  1, 2] */
   5.000000000000e-001F,  /* a[  2, 0] */
  -9.766845703125e-001F,  /* a[  2, 1] */
   4.890747070313e-001F,  /* a[  2, 2] */
   5.000000000000e-001F,  /* a[  3, 0] */
  -9.837341308594e-001F,  /* a[  3, 1] */
   4.913940429688e-001F}; /* a[  3, 2] */

float IIR_butter_ba_m1[3];
float IIR_butter_ba_m2[3];

float IIR_butter_ba_gain = 1.000061035156e+000F; /* initial gain for cascade realization */
                          /* also applies to parallel realization */
float IIR_butter_ba_pars = 1.000000000000e+000F; /* scale value for parallel sections */

BiquadSections IIR_IIR_butter_ba = {

     3,     /* number of sections                     */
     0,     /* realization method                     */
            /*   0  Cascaded second order sections    */
            /*   1  Parallel second order sections    */
     1,     /* quantization: 0 off, 1 on              */
     1,     /* quantization type                      */
            /*   0  Floating point                    */
            /*   1  Fixed point fractional            */
     0,     /* realization type for cascaded sections only              */
            /*   0  Fixed point    - Transposed Canonic biquad sections */
            /*   1  Fixed point    - Canonic biquad sections            */
            /*   2  Floating point - 4 multiplies                       */
            /*   3  Floating point - 5 multiplies                       */
            /*   4  Floating point - recursive normal                   */
     0,     /* realization type for parallel sections only              */
            /*   0  Fixed point    - Transposed Canonic biquad sections */
            /*   1  Floating point - Transposed Canonic biquad sections */
   &IIR_butter_ba_gain,    /* pointer to gain for cascade/parallel realizations */
   &IIR_butter_ba_pars,    /* pointer to scale value for parallel sections      */
   IIR_butter_ba_num,      /* pointer to numerator coefficients                 */
   IIR_butter_ba_den,      /* pointer to denominator coefficients               */
   IIR_butter_ba_m1,       /* pointer to delay line 1                           */
   IIR_butter_ba_m2,       /* pointer to delay line 2                           */
   cas_blkfloat_fm1}; /* ptr to filter routine */

/* call the following function first and normally only once */
/* init_biquad_float (&IIR_IIR_butter_ba)  */
/*   where &IIR_IIR_butter_ba is a pointer to the BiquadSections */
/*   structure defining the filter */


/* call the following function to filter n samples */
/* IIR_IIR_butter_ba.filter (pIn, pOut, int n, &IIR_IIR_butter_ba); */

/*   where pIn  is a pointer to an array or buffer of samples to be filtered */
/*         pOut is a pointer to the array of filtered samples output by the filter */
/*         n    is the number of samples to filter */
/*         &IIR_IIR_butter_ba is a pointer to the structure defining the filter */


#ifndef DEFINE_SUBROUTINE

/* The following main program can be used to test the filter.         */
/*   input is in file 'in' and the filtered samples are in file 'out' */
/*   The input and output files are ascii floating point values       */
/*    e.g 1.0342 with 1 sample per line                               */
/* The input files can be created in DSPworks and exported as         */
/*   ascii floating point or any other system capable of creating     */
/*   ascii files with floating point values.                          */
/* The filtered output file can be imported into DSPworks as an ascii */
/*    floating point file and an FFT can be run to validate           */
/*    the frequency response.                                         */

#include "qed_filt.c"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>


#define INSZ1  1000
#define OUTSZ1 1000

static    float x[INSZ1], y[OUTSZ1];


int main(int argc, char *argv[])

{
  int i, in_count, file_status, error;

  FILE *fin;              /* input file of samples */
  FILE *fout;             /* output file of filtered samples */ 

  fprintf (stderr," ***** start filter test *****\n");

  fprintf (stderr," this program accepts 0,1 or 2 command line arguments\n");
  fprintf (stderr," the first  argument is the filename of the input file\n");
  fprintf (stderr," the second argument is the filename of the output file\n");
  fprintf (stderr," if there are 0 arguments, input and output is respectively\n");
  fprintf (stderr,"     stdin and stdout\n");
  fprintf (stderr," if only one argument is specified, then output is stdout\n");
  fprintf (stderr," if input is stdin rather than a file, then fscanf expects input\n");
  fprintf (stderr,"     from the console which may be piped in or entered directly\n");

  fin  = stdin;
  fout = stdout;
  error = 0;

  if (argc == 1) {
	    fprintf(stderr," ***** waiting for input *****\n");
  }
  if (argc >= 2) {
      fin = fopen (argv[1], "r");
      if (fin == NULL) {
          fprintf(stderr,"\n error - Cannot open file %s for input\n", argv[1]);
          error = 1;
      }
  }
  if (argc >= 3) {
      fout = fopen (argv[2], "w");
      if (fout == NULL) {
          fprintf(stderr,"\n error - Cannot open file %s for output\n", argv[2]);
          error = 1;
      }
  }
  if (error) {
      fprintf(stderr," ***** end filter test *****\n");
      return(0);
  }
  
  

  init_biquad_float (&IIR_IIR_butter_ba);


  do {

      /* get input samples */ 
      for (in_count = 0; in_count < INSZ1; in_count++) { 
          file_status = fscanf(fin,"%f",&x[in_count]); 
          if (file_status != 1) 
              break; 
      }

      /* filter samples */ 

      if (in_count == 0) break;

      IIR_IIR_butter_ba.filter( x, y, in_count, &IIR_IIR_butter_ba);

      for (i = 0; i < in_count; i++)
          fprintf (fout,"%f\n",y[i]);

  } while (file_status == 1);

  fclose (fin); 
  fclose (fout);

  fprintf(stderr," ***** end filter test *****\n");
  return(1);

}
 
#endif 
