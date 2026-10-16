#include <gevrek_event_bus.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

GevrekEventBus* GevrekEventBusCreate(size_t event_count) {
    GevrekEventBus* bus = calloc(1, sizeof(GevrekEventBus));
    if (!bus) return NULL;

    bus->channels = calloc(event_count, sizeof(GevrekEventChannel));
    if (!bus->channels && event_count != 0) {
        free(bus);
        return NULL;
    }

    bus->count = event_count;
    return bus;
}

void GevrekEventBusDestroy(GevrekEventBus* bus) {
    if (!bus) return;

    for (size_t i = 0; i < bus->count; ++i) {
        free(bus->channels[i].callbacks);
        free(bus->channels[i].user_datas);
    }

    free(bus->channels);
    free(bus);
}

int GevrekEventBusSubscribe(GevrekEventBus* bus, int event_type, GevrekEventCallback callback, void* user_data) {
    if (!bus || event_type < 0 ||
        (size_t)event_type >= bus->count || !callback)
        return 0;

    GevrekEventChannel* ch = &bus->channels[event_type];

    if (ch->count == ch->capacity) {
        size_t cap = ch->capacity ? ch->capacity * 2 : 4;

        GevrekEventCallback* callbacks =
            malloc(cap * sizeof(*callbacks));
        void** datas = malloc(cap * sizeof(*datas));

        if (!callbacks || !datas) {
            free(callbacks);
            free(datas);
            return 0;
        }

        memcpy(callbacks, ch->callbacks,
            ch->count * sizeof(*callbacks));
        memcpy(datas, ch->user_datas,
            ch->count * sizeof(*datas));

        free(ch->callbacks);
        free(ch->user_datas);

        ch->callbacks = callbacks;
        ch->user_datas = datas;
        ch->capacity = cap;
    }

    ch->callbacks[ch->count] = callback;
    ch->user_datas[ch->count] = user_data;
    ch->count++;
    return 1;
}

void GevrekEventBusPublish(GevrekEventBus* bus, int event_type, void* event_data) 
{    
    if (!bus || event_type < 0 ||
        (size_t)event_type >= bus->count)
        return;

    GevrekEventChannel* ch = &bus->channels[event_type];

    for (size_t i = 0; i < ch->count; ++i)
        ch->callbacks[i](event_data, ch->user_datas[i]);
}
