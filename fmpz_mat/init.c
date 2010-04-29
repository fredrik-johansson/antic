/*============================================================================

    This file is part of FLINT.

    FLINT is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    FLINT is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with FLINT; if not, write to the Free Software
    Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301 USA

===============================================================================*/
/****************************************************************************

   Copyright (C) 2010 William Hart
   
*****************************************************************************/

#include <stdlib.h>
#include <mpir.h>
#include "flint.h"
#include "fmpz.h"
#include "fmpz_mat.h"

void fmpz_mat_init(fmpz_mat_t mat, ulong rows, ulong cols)
{
   ulong i;

   if ((rows) && (cols)) // allocate space for r*c small entries
   {
      mat->entries = (fmpz *) calloc(rows*cols, sizeof(fmpz));
      mat->rows = (fmpz **) malloc(rows*sizeof(fmpz *)); // initialise rows
		
      for (i = 0; i < rows; i++)
      mat->rows[i] = mat->entries + i*cols;
   } else mat->entries = NULL;
   
   mat->r = rows;
   mat->c = cols;
}
