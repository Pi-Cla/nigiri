#include "nigiri/loader/loader_interface.h"
#include "nigiri/timetable.h"

#include "rust/cxx.h"

#include "nigiri-cxx/main.h"

using Timetable = nigiri::timetable;

struct LoaderConfig;

std::unique_ptr<Timetable> load_timetable(rust::Vec<rust::String> const& paths,
                                          LoaderConfig const&,
                                          rust::Str start_date,
                                          std::uint32_t num_days);

void dump_timetable(Timetable const&, rust::Str path);