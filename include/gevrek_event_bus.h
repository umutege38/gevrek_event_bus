#ifndef GEVREK_EVENT_BUS_H
#define GEVREK_EVENT_BUS_H

#define GEVREK_REGISTER_EVENT(name) \
    static const int EVENT_##name = __COUNTER__

typedef void (*GevrekEventCallback)(void*, void*);

typedef struct {
    GevrekEventCallback* callbacks;
    void** user_datas;
    size_t count;
    size_t capacity;
} GevrekEventChannel;

typedef struct {
    GevrekEventChannel* channels;
    size_t count;
} GevrekEventBus;

GevrekEventBus* GevrekEventBusCreate(size_t event_count);

void GevrekEventBusDestroy(GevrekEventBus* bus);

int GevrekEventBusSubscribe(GevrekEventBus* bus, int event_type, GevrekEventCallback callback, void* user_data);

void GevrekEventBusPublish(GevrekEventBus* bus, int event_type, void* event_data);

#endif // GEVREK_EVENT_BUS_H
