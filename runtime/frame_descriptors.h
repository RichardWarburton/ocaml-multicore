/**************************************************************************/
/*                                                                        */
/*                                 OCaml                                  */
/*                                                                        */
/*      KC Sivaramakrishnan, Indian Institute of Technology, Madras       */
/*                   Tom Kelly, OCaml Labs Consultancy                    */
/*                 Stephen Dolan, University of Cambridge                 */
/*                                                                        */
/*   Copyright 2019 Indian Institute of Technology, Madras                */
/*   Copyright 2021 OCaml Labs Consultancy Ltd                            */
/*   Copyright 2019 University of Cambridge                               */
/*                                                                        */
/*   All rights reserved.  This file is distributed under the terms of    */
/*   the GNU Lesser General Public License version 2.1, with the          */
/*   special exception on linking described in the file LICENSE.          */
/*                                                                        */
/**************************************************************************/

#ifndef CAML_FRAME_DESCRIPTORS_H
#define CAML_FRAME_DESCRIPTORS_H

#include "caml/config.h"
#include "caml/stack.h"

#define Hash_retaddr(addr, mask)                          \
  (((uintnat)(addr) >> 3) & (mask))


/* Allocation lengths are encoded as 0-255, giving sizes 1-256 */
#define Wosize_encoded_alloc_len(n) ((uintnat)(n) + 1)

/* Used to compute offsets in frame tables.
   ty must have power-of-2 size */
#define Align_to(p, ty) \
  (void*)(((uintnat)(p) + sizeof(ty) - 1) & -sizeof(ty))


void caml_init_frame_descriptors(void);
void caml_register_frametable(intnat *table);

/* Find the current table of frame descriptors.
   The resulting structure is only valid until the next GC */
frame_descr* caml_find_frame_descr(caml_frame_descrs fds, uintnat pc);

#endif /* CAML_FRAME_DESCRIPTORS_H */
