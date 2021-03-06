#ifndef VRPTW_OR_OPT_H
#define VRPTW_OR_OPT_H

/*

This file is part of VROOM.

Copyright (c) 2015-2018, Julien Coupey.
All rights reserved (see LICENSE).

*/

#include "problems/cvrp/operators/or_opt.h"
#include "structures/vroom/tw_route.h"

namespace vroom {
namespace vrptw {

class OrOpt : public cvrp::OrOpt {
private:
  TWRoute& _tw_s_route;
  TWRoute& _tw_t_route;

  bool _is_normal_valid;
  bool _is_reverse_valid;

  virtual void compute_gain() override;

public:
  OrOpt(const Input& input,
        const utils::SolutionState& sol_state,
        TWRoute& tw_s_route,
        Index s_vehicle,
        Index s_rank,
        TWRoute& tw_t_route,
        Index t_vehicle,
        Index t_rank);

  virtual bool is_valid() override;

  virtual void apply() override;
};

} // namespace vrptw
} // namespace vroom

#endif
