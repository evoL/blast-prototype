#ifndef EVENTLISTENER_H
#define EVENTLISTENER_H

class EventListener { 

public:
	EventListener();
	virtual void execute()=0;
};


#endif