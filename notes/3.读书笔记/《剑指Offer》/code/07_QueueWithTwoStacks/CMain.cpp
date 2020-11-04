#include "Queue.h"

int main()
{
    CQueue<int> q;

    q.appendTail(1);
    q.appendTail(2);
    q.appendTail(3);
    q.appendTail(4);
    q.appendTail(5);

    cout << q.deleteHead() << endl;
    cout << q.deleteHead() << endl;
    cout << q.deleteHead() << endl;
    cout << q.deleteHead() << endl;
    cout << q.deleteHead() << endl;
    cout << q.deleteHead() << endl;

    return 0;
}