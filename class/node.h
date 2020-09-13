#ifndef _NODE_H_
#define _NODE_H_
#define NULL 0
class CNode{
private:
    int Position;
    CNode *Nxt;
public:
    CNode(int _a){
        Position = _a;
        *Nxt = NULL;
    }
    int GetPosition(){
        return Position;
    }
};
#endif