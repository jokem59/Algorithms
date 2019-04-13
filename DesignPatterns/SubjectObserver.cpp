#include <iostream>
#include <vector>
#include <string>

class ObserverInterface
{
public:
	virtual ~ObserverInterface() {}
	virtual void update(int message) = 0;
    virtual std::string getName() = 0;
};

class SubjectInterface
{
public:
	virtual ~SubjectInterface();
	virtual void subscribe(ObserverInterface *);
	virtual void unsubscribe (ObserverInterface *);
	virtual void notify(int message);
private:
	std::vector<ObserverInterface *> mObservers;
};

SubjectInterface::~SubjectInterface()
{}

void SubjectInterface::subscribe(ObserverInterface *observer)
{
	mObservers.push_back(observer);
}

void SubjectInterface::unsubscribe(ObserverInterface *observer)
{
	int count = mObservers.size();
	int i;

	for (i = 0; i < count; i++) {
        if (mObservers[i]->getName() == observer->getName()) {
            mObservers.erase(mObservers.begin() + i);
            break;
        }

	}
}

void SubjectInterface::notify(int msg)
{
	int count = mObservers.size();

	for (int i = 0; i < count; i++)
		(mObservers[i])->update(msg);
}

class MySubject : public SubjectInterface
{
public:
	enum Message {ADD, REMOVE};
};

class MyObserver : public ObserverInterface
{
public:
	explicit MyObserver(const std::string &str) : name(str) {}
	void update(int message)
	{
		std::cout << name << " Got message " << message << std::endl;
	}
    std::string getName() {
        return name;
    }

private:
	std::string name;
};

int main()
{
	MyObserver observerA("observerA");
	MyObserver observerB("observerB");
	MyObserver observerC("observerC");

	MySubject subject;
	subject.subscribe(&observerA);
	subject.subscribe(&observerB);
	subject.unsubscribe(&observerB);
	subject.subscribe(&observerC);

	subject.notify(MySubject::ADD);
	subject.notify(MySubject::REMOVE);

	return 0;
}
