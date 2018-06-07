/*******************************************************************\

Module:

Author: Michael Tautschnig

\*******************************************************************/

#ifndef CPROVER_CPP_CPROVER_LIBRARY_H
#define CPROVER_CPP_CPROVER_LIBRARY_H

#include <set>

#include <util/irep.h>

class message_handlert;
class symbol_tablet;

void add_cprover_cpp_library(
  const std::set<irep_idt> &functions,
  symbol_tablet &,
  message_handlert &);

#endif // CPROVER_CPP_CPROVER_LIBRARY_H
