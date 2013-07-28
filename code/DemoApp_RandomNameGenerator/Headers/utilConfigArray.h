/*
 * utilConfigArray.h - Configuration Array Manager [header]
 *
 *  Created on: 28 juil. 2013
 *      Author: Emmanuel
 */

// http://stackoverflow.com/questions/7798383/array-of-pointers-to-multiple-types-c

#ifndef UTILCONFIGARRAY_H_
#define UTILCONFIGARRAY_H_

#include <stdlib.h>
#include <stdio.h>

/**
 * \brief	This enum is used to store type information in a struct/array.
 */
typedef enum eArrayElementType {
	aet_str,
	aet_int
} eArrayElementType;

/**
 * \brief	This is an element to be stored in sUtilConfigArray.
 * \fields	_type	type of the stored element
 * 			union	contains either a string or an integer (current state)
 */
typedef struct sConfigArrayElement {
	eArrayElementType _eType;
	union {
		char*	_pStr;
		int*	_pI;
	};
} sConfigArrayElement;

/**
 * \brief	Struct used to store data (with given type) contained in a config file.
 * \fields	_pConfigFile	pointer to config file
 * 			_pArray			the proper array used to store data
 */
typedef struct sUtilConfigArray {
	FILE* 					_pConfigFile;
	sConfigArrayElement*	_pArray;
} sUtilConfigArray;

#endif /* UTILCONFIGARRAY_H_ */
