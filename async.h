#pragma once

#include <cstddef>
#include <set>
#include <memory>
#include "bulk.h"

namespace async {

using handle_t = void *;

std::set<std::shared_ptr<bulk::Handle>> handlers{};
int id = 0;

handle_t connect(std::size_t bulk);
void receive(handle_t handle, const char *data, std::size_t size);
void disconnect(handle_t handle);

}
