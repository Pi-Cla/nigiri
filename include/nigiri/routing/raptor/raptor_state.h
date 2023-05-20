#pragma once

#include <vector>

#include "date/date.h"

#include "cista/containers/flat_matrix.h"

#include "nigiri/routing/raptor/delta_t.h"

namespace nigiri {
struct timetable;
}

namespace nigiri::routing {

struct raptor_state {
  raptor_state() = default;
  raptor_state(raptor_state const&) = delete;
  raptor_state& operator=(raptor_state const&) = delete;
  raptor_state(raptor_state&&) = default;
  raptor_state& operator=(raptor_state&&) = default;
  ~raptor_state() = default;

  void reset(unsigned n_locations, unsigned n_routes);

  void print(timetable const& tt, date::sys_days, delta_t invalid);

  std::vector<delta_t> tmp_;
  std::vector<delta_t> best_;
  cista::raw::flat_matrix<delta_t> round_times_;
  std::vector<bool> station_mark_;
  std::vector<bool> prev_station_mark_;
  std::vector<bool> route_mark_;
};

}  // namespace nigiri::routing