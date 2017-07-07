#ifndef _OFFSETS_H_
#define _OFFSETS_H_

#include <assert.h>
#include "SymbolTable.h"


enum SCOPE_SPACE  currscopespace              ();
unsigned          currscopeoffset             ();
void              incurrscopeoffset           ();
void              enterscopespace             ();
void              exitscopespace              ();
void              resetformalargsoffset       ();
void              resetfunctionlocalssoffset  ();
void              restorecurrscopeoffset      (unsigned);

#endif
