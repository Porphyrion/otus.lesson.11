#include "async.h"


namespace async {

handle_t connect(std::size_t bulk_){
    std::lock_guard<std::mutex> lock(connectMutex);
    auto h = std::make_shared<bulk::Handle>(bulk_);
    handlers.emplace(h);
    return static_cast<handle_t>(h.get());
};

void receive(handle_t handle, const char *data, std::size_t size){
    std::lock_guard<std::mutex> lock(receivetMutex);
    auto x = reinterpret_cast<bulk::Handle*>(handle);
    x->readString(data, size);
};

void disconnect(handle_t handle) {
    std::lock_guard<std::mutex> lock(disconnectMutex);
    auto x = std::find_if(handlers.begin(), handlers.end(), [&handle](decltype(*handlers.begin()) i){return i.get() == handle;} );
    x->get()->lastBulk();
    handlers.erase(x);
}

};
