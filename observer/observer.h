#ifndef OBSERVER_H
#define OBSERVER_H

typedef struct __observer {
	void (*destroy)(struct __observer *);
	void* impl;
	void (*notify)(struct __observer*, void *);
	void (*notifyImpl)(void*, int, void*);
} Observer;

Observer * observer_new(void*, void (*)(void*, int, void*));

#endif 