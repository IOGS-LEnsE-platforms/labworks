#include <stdio.h>

#include "IIR_Filter.h"
#include "IIR_Filter.h"

#define NUM_SAMPLES 300
#define NUM_BLOCKS 10
#define NUM_SAMPLES_PER_BLOCK (NUM_SAMPLES-1)/NUM_BLOCKS+1

int main (int argc, char * argv[])
{
   FILE *pOutFile;
   int  inSamples[NUM_SAMPLES_PER_BLOCK], outSamples[NUM_SAMPLES_PER_BLOCK];
   int  numBlocks, i, j;


   pOutFile = fopen("IIR_Filter_impresponse.dat", "wt");
   if( pOutFile == NULL )
		abort();

   IIRTransposeFilterInit( &IIR_FilterFilter );

   inSamples[0] = 0x7FFF;
   BlockIIRTransposeFilter( &IIR_FilterFilter, &inSamples[0], &outSamples[0], 1 );

   fprintf( pOutFile, "%g\n", outSamples[0]/32768. );

   for( i=0; i < NUM_SAMPLES_PER_BLOCK; i++ )
		inSamples[i] = 0;

   for( i=0; i < NUM_BLOCKS; i++ )
   {
		BlockIIRTransposeFilter(&IIR_FilterFilter,inSamples,outSamples,NUM_SAMPLES_PER_BLOCK);
		for( j=0; j < NUM_SAMPLES_PER_BLOCK; j++ )
			 fprintf( pOutFile, "%g\n", outSamples[j]/32768. );
   }

   fclose(pOutFile);
   return 0;
}

