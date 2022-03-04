#ifndef OBSERVER_H
	#define OBSERVER_H
	typedef struct __observer {
		void (*destroy)(struct __observer *);
		void* impl;
		void (*notify)(struct __observer*, int, void *);
		void (*notifyImpl)(void*, int, void*);
	} Observer;

	Observer * observerNew(void*, void (*)(void*, int, void*));

#endif