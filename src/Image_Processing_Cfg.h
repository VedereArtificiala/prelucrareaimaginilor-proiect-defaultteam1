#pragma once
//Preprocessing guard to ensure that Image_Processing_CFG header is included only inside Image_Processing.h

#ifndef _IMAGE_PROCESSING_H
#error "Image_Processing_Cfg.h can only be included in source.h"
#endif

//====================================================================================================
//Header Includes
//====================================================================================================



//====================================================================================================
//Macros and Defines
//====================================================================================================

/* ERROR CODES */
#define ERROR_NO_ERROR		 0
#define ERROR_MISSING_FILE	 1
#define ERROR_OPENING_FILE	 nullptr;
//...///
const unsigned int MODE_ARITMETIC = 1;
const unsigned int MODE_GAUSS = 2;
const unsigned short filterWidth_1 = 3;
const unsigned short filterHeight_1 = 3;

const unsigned short filterWidth_2 = 9;
const unsigned short filterHeight_2 = 9;

//====================================================================================================
//Data types 
//====================================================================================================



//====================================================================================================
//Function prototypes 
//====================================================================================================



//====================================================================================================
//Global variables
//====================================================================================================
