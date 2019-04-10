/*******************************************************************\

Module: Traces of GOTO Programs

Author: Daniel Kroening

Date: July 2005

\*******************************************************************/

/// \file
/// Traces of GOTO Programs

#ifndef CPROVER_GOTO_SYMEX_BUILD_GOTO_TRACE_H
#define CPROVER_GOTO_SYMEX_BUILD_GOTO_TRACE_H

#include "symex_target_equation.h"
#include "goto_symex_state.h"

/// Build a trace by going through the steps of \p target and stopping at the
/// first failing assertion
/// \param target: SSA form of the program
/// \param propositional_conversion: solver from which to get valuations
/// \param ns: namespace
/// \param [out] goto_trace: trace to which the steps of the trace get appended
void build_goto_trace(
  const symex_target_equationt &target,
  const propositional_conversiont &propositional_conversion,
  const namespacet &ns,
  goto_tracet &goto_trace);

/// Build a trace by going through the steps of \p target and stopping after
/// the given step
/// \param target: SSA form of the program
/// \param last_step_to_keep: iterator pointing to the last step to keep
/// \param propositional_conversion: solver from which to get valuations
/// \param ns: namespace
/// \param [out] goto_trace: trace to which the steps of the trace get appended
void build_goto_trace(
  const symex_target_equationt &target,
  symex_target_equationt::SSA_stepst::const_iterator last_step_to_keep,
  const propositional_conversiont &propositional_conversion,
  const namespacet &ns,
  goto_tracet &goto_trace);

typedef std::function<
  bool(symex_target_equationt::SSA_stepst::const_iterator, const propositional_conversiont &)>
  ssa_step_predicatet;

/// Build a trace by going through the steps of \p target and stopping after
/// the step matching a given condition
/// \param target: SSA form of the program
/// \param stop_after_predicate: function with an SSA step iterator and solver
///   as argument, which should return true for the last step to keep
/// \param propositional_conversion: solver from which to get valuations
/// \param ns: namespace
/// \param [out] goto_trace: trace to which the steps of the trace get appended
void build_goto_trace(
  const symex_target_equationt &target,
  ssa_step_predicatet stop_after_predicate,
  const propositional_conversiont &propositional_conversion,
  const namespacet &ns,
  goto_tracet &goto_trace);

#endif // CPROVER_GOTO_SYMEX_BUILD_GOTO_TRACE_H
