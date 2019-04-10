/*******************************************************************\

Module:

Author: Daniel Kroening, kroening@kroening.com

\*******************************************************************/

#include "boolbv.h"

#include <util/std_types.h>

#include "boolbv_type.h"

#include <solvers/floatbv/float_utils.h>

bvt boolbvt::convert_abs(const abs_exprt &expr)
{
  const std::size_t width = boolbv_width(expr.type());

  if(width==0)
    return conversion_failed(expr);

  const bvt &op_bv=convert_bv(expr.op());

  if(expr.op().type()!=expr.type())
    return conversion_failed(expr);

  const bvtypet bvtype = get_bvtype(expr.type());

  if(bvtype==bvtypet::IS_FIXED ||
     bvtype==bvtypet::IS_SIGNED ||
     bvtype==bvtypet::IS_UNSIGNED)
  {
    return bv_utils.absolute_value(op_bv);
  }
  else if(bvtype==bvtypet::IS_FLOAT)
  {
    float_utilst float_utils(propositional, to_floatbv_type(expr.type()));
    return float_utils.abs(op_bv);
  }

  return conversion_failed(expr);
}
