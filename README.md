# GevrekEventBus

**GevrekEventBus** is a lightweight, type-agnostic Publish-Subscribe (Pub/Sub) Event Bus library written in C. It enables decoupled, event-driven communication between different modules or components within an application.

---

## Roadmap Checklist
| Feature | Status | Scope |
|---|---|---|
| Compile-time event ID generation (`__COUNTER__`) | ✅ Implemented | Core |
| Dynamic channel management | ✅ Implemented | Core |
| Context-aware callbacks (`user_data`) | ✅ Implemented | Core |
| Bus creation and destruction (`Create`, `Destroy`) | ✅ Implemented | Core |
| Event subscription (`Subscribe`) | ✅ Implemented | Core |
| Event publication (`Publish`) | ✅ Implemented | Core |
| Unsubscribe mechanism | ❌ Not implemented | Core |
| Thread-safe synchronization (mutexes) | ❌ Not implemented | Concurrency module |
| Event channel cleanup on zero subscribers | ❌ Not implemented | Core |
| Event filtering / conditional dispatch | ❌ Not implemented | Utility module |
| Custom event payload type safety checks | ❌ Not implemented | Core |
| Wildcard or pattern-based subscriptions | ❌ Not implemented | Advanced module |
| Event queue and deferred dispatch | ❌ Not implemented | Advanced module |
