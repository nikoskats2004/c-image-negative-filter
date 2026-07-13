/*
  ------------------------------------------------------------
  STATIC ANSI C IMAGE PROCESSING TEMPLATE
  by D.K. Iakovidis
  ------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define INPUT_FILENAME		"image268x324.raw"		
#define OUTPUT_FILENAME		"image268x324out.raw"	
#define ROWS				324						
#define COLUMNS				268						
#define GREYLEVELS			256						
#define OUTPUT_ROWS			ROWS				
#define OUTPUT_COLUMNS		COLUMNS					

int main(void)
{
	unsigned char	inputImage  [ROWS][COLUMNS],					
					outputImage [OUTPUT_ROWS][OUTPUT_COLUMNS];

	FILE	*inputFile,											
			*outputFile;

	int	i = 0,
		j = 0;

/*
  ------------------------------------------------------------
  LOAD IMAGE
  ------------------------------------------------------------
*/
	if ( ((inputFile = fopen(INPUT_FILENAME,"rb")) != NULL))
	{
		for  (i = 0; i < ROWS; i++)
		{
			for  (j = 0; j < COLUMNS; j++)
			{
				fscanf(inputFile, "%c", &inputImage[i][j]);
			}
		}
	} 
	else
	{
		printf("Error loading image.");
	}
	fclose(inputFile);


/*
  ------------------------------------------------------------
  PUT IMAGE PROCESSING & ANALYSIS CODE HERE
  ------------------------------------------------------------
*/

/*  Example: Copy input image to output image */

	for (i = 0; i < ROWS; i++)
	{
		for (j = 0; j < COLUMNS; j++)
		{	
		  
		  outputImage[i][j] = 255 - inputImage[i][j];
 	}
}

/*
  ------------------------------------------------------------
  SAVE IMAGE
  ------------------------------------------------------------
*/
	if ( ((outputFile = fopen(OUTPUT_FILENAME,"wb")) != NULL))
	{
		for  (i = 0; i < OUTPUT_ROWS; i++)
		{
			for  (j = 0; j < OUTPUT_COLUMNS; j++)
			{
				fprintf(outputFile, "%c", outputImage[i][j]);
			}
		}
	} 
	else
	{
		printf("Error saving image.");
	}
	fclose(outputFile);

    return 0;
}
